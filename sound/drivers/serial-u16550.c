/*
 *   serial.c
 *   Copyright (c) by Jaroslav Kysela <perex@perex.cz>,
 *                    Isaku Yamahata <yamahata@private.email.ne.jp>,
 *		      George Hansper <ghansper@apana.org.au>,
 *		      Hannu Savolainen
 *
 *   This code is based on the code from ALSA 0.5.9, but heavily rewritten.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 * Sat Mar 31 17:27:57 PST 2001 tim.mann@compaq.com 
 *      Added support for the Midiator MS-124T and for the MS-124W in
 *      Single Addressed (S/A) or Multiple Burst (M/B) mode, with
 *      power derived either parasitically from the serial port or
 *      from a separate power supply.
 *
 *      More documentation can be found in serial-u16550.txt.
 */

#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <sound/core.h>
#include <sound/rawmidi.h>
#include <sound/initval.h>

#include <linux/serial_reg.h>
#include <linux/jiffies.h>

#include <asm/io.h>

MODULE_DESCRIPTION("MIDI serial u16550");
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("{{ALSA, MIDI serial u16550}}");

#define SNDRV_SERIAL_SOUNDCANVAS 0 /*                                        */
#define SNDRV_SERIAL_MS124T 1      /*                  */
#define SNDRV_SERIAL_MS124W_SA 2   /*                              */
#define SNDRV_SERIAL_MS124W_MB 3   /*                              */
#define SNDRV_SERIAL_GENERIC 4     /*                   */
#define SNDRV_SERIAL_MAX_ADAPTOR SNDRV_SERIAL_GENERIC
static char *adaptor_names[] = {
	"Soundcanvas",
        "MS-124T",
	"MS-124W S/A",
	"MS-124W M/B",
	"Generic"
};

#define SNDRV_SERIAL_NORMALBUFF 0 /*                                  */
#define SNDRV_SERIAL_DROPBUFF   1 /*                                */

static int index[SNDRV_CARDS] = SNDRV_DEFAULT_IDX;	/*             */
static char *id[SNDRV_CARDS] = SNDRV_DEFAULT_STR;	/*                  */
static bool enable[SNDRV_CARDS] = SNDRV_DEFAULT_ENABLE; /*                  */
static long port[SNDRV_CARDS] = SNDRV_DEFAULT_PORT; /*                         */
static int irq[SNDRV_CARDS] = SNDRV_DEFAULT_IRQ; 	/*                       */
static int speed[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS - 1)] = 38400}; /*                               */
static int base[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS - 1)] = 115200}; /*           */
static int outs[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS - 1)] = 1};	 /*         */
static int ins[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS - 1)] = 1};	/*         */
static int adaptor[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS - 1)] = SNDRV_SERIAL_SOUNDCANVAS};
static bool droponfull[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS -1)] = SNDRV_SERIAL_NORMALBUFF };

module_param_array(index, int, NULL, 0444);
MODULE_PARM_DESC(index, "Index value for Serial MIDI.");
module_param_array(id, charp, NULL, 0444);
MODULE_PARM_DESC(id, "ID string for Serial MIDI.");
module_param_array(enable, bool, NULL, 0444);
MODULE_PARM_DESC(enable, "Enable UART16550A chip.");
module_param_array(port, long, NULL, 0444);
MODULE_PARM_DESC(port, "Port # for UART16550A chip.");
module_param_array(irq, int, NULL, 0444);
MODULE_PARM_DESC(irq, "IRQ # for UART16550A chip.");
module_param_array(speed, int, NULL, 0444);
MODULE_PARM_DESC(speed, "Speed in bauds.");
module_param_array(base, int, NULL, 0444);
MODULE_PARM_DESC(base, "Base for divisor in bauds.");
module_param_array(outs, int, NULL, 0444);
MODULE_PARM_DESC(outs, "Number of MIDI outputs.");
module_param_array(ins, int, NULL, 0444);
MODULE_PARM_DESC(ins, "Number of MIDI inputs.");
module_param_array(droponfull, bool, NULL, 0444);
MODULE_PARM_DESC(droponfull, "Flag to enable drop-on-full buffer mode");

module_param_array(adaptor, int, NULL, 0444);
MODULE_PARM_DESC(adaptor, "Type of adaptor.");

/*                                        */  /*                                       */

#define SNDRV_SERIAL_MAX_OUTS	16		/*                */
#define SNDRV_SERIAL_MAX_INS	16		/*                */

#define TX_BUFF_SIZE		(1<<15)		/*             */
#define TX_BUFF_MASK		(TX_BUFF_SIZE - 1)

#define SERIAL_MODE_NOT_OPENED 		(0)
#define SERIAL_MODE_INPUT_OPEN		(1 << 0)
#define SERIAL_MODE_OUTPUT_OPEN		(1 << 1)
#define SERIAL_MODE_INPUT_TRIGGERED	(1 << 2)
#define SERIAL_MODE_OUTPUT_TRIGGERED	(1 << 3)

struct snd_uart16550 {
	struct snd_card *card;
	struct snd_rawmidi *rmidi;
	struct snd_rawmidi_substream *midi_output[SNDRV_SERIAL_MAX_OUTS];
	struct snd_rawmidi_substream *midi_input[SNDRV_SERIAL_MAX_INS];

	int filemode;		/*                     */

	spinlock_t open_lock;

	int irq;

	unsigned long base;
	struct resource *res_base;

	unsigned int speed;
	unsigned int speed_base;
	unsigned char divisor;

	unsigned char old_divisor_lsb;
	unsigned char old_divisor_msb;
	unsigned char old_line_ctrl_reg;

	/*                                   */
	short int fifo_limit;	/*                   */
        short int fifo_count;	/*                   */

	/*                 */
	int adaptor;

	/*        */
	int prev_in;
	unsigned char rstatus;

	/*         */
	int prev_out;
	unsigned char prev_status[SNDRV_SERIAL_MAX_OUTS];

	/*                                               */
	unsigned char tx_buff[TX_BUFF_SIZE];
	int buff_in_count;
        int buff_in;
        int buff_out;
        int drop_on_full;

	/*            */
	unsigned int timer_running:1;
	struct timer_list buffer_timer;

};

static struct platform_device *devices[SNDRV_CARDS];

static inline void snd_uart16550_add_timer(struct snd_uart16550 *uart)
{
	if (!uart->timer_running) {
		/*                                 */
		uart->buffer_timer.expires = jiffies + (HZ+255)/256;
		uart->timer_running = 1;
		add_timer(&uart->buffer_timer);
	}
}

static inline void snd_uart16550_del_timer(struct snd_uart16550 *uart)
{
	if (uart->timer_running) {
		del_timer(&uart->buffer_timer);
		uart->timer_running = 0;
	}
}

/*                                                  */
static inline void snd_uart16550_buffer_output(struct snd_uart16550 *uart)
{
	unsigned short buff_out = uart->buff_out;
	if (uart->buff_in_count > 0) {
		outb(uart->tx_buff[buff_out], uart->base + UART_TX);
		uart->fifo_count++;
		buff_out++;
		buff_out &= TX_BUFF_MASK;
		uart->buff_out = buff_out;
		uart->buff_in_count--;
	}
}

/*                                                    
                                    
                                          
 */
static void snd_uart16550_io_loop(struct snd_uart16550 * uart)
{
	unsigned char c, status;
	int substream;

	/*                        */
	substream = uart->prev_in;

	/*           */
	while ((status = inb(uart->base + UART_LSR)) & UART_LSR_DR) {
		/*                          */
		c = inb(uart->base + UART_RX);

		/*                                */
		if (c & 0x80)
			uart->rstatus = c;

		/*                      */
		if (uart->adaptor == SNDRV_SERIAL_GENERIC) {
			if (uart->rstatus == 0xf5) {
				if (c <= SNDRV_SERIAL_MAX_INS && c > 0)
					substream = c - 1;
				if (c != 0xf5)
					/*                                
                               */
					uart->rstatus = 0;
			} else if ((uart->filemode & SERIAL_MODE_INPUT_OPEN)
				   && uart->midi_input[substream])
				snd_rawmidi_receive(uart->midi_input[substream],
						    &c, 1);
		} else if ((uart->filemode & SERIAL_MODE_INPUT_OPEN) &&
			   uart->midi_input[substream])
			snd_rawmidi_receive(uart->midi_input[substream], &c, 1);

		if (status & UART_LSR_OE)
			snd_printk(KERN_WARNING
				   "%s: Overrun on device at 0x%lx\n",
			       uart->rmidi->name, uart->base);
	}

	/*                          */
	uart->prev_in = substream;

	/*                                                         
                            */
	/*                    */
	if (status & UART_LSR_THRE)
		uart->fifo_count = 0;
	if (uart->adaptor == SNDRV_SERIAL_MS124W_SA
	   || uart->adaptor == SNDRV_SERIAL_GENERIC) {
		/*                                                 */
		status = inb(uart->base + UART_MSR);
		while (uart->fifo_count == 0 && (status & UART_MSR_CTS) &&
		       uart->buff_in_count > 0) {
		       snd_uart16550_buffer_output(uart);
		       status = inb(uart->base + UART_MSR);
		}
	} else {
		/*            */
		while (uart->fifo_count < uart->fifo_limit /*                */
		       && uart->buff_in_count > 0)	/*                */
			snd_uart16550_buffer_output(uart);
	}
	if (uart->irq < 0 && uart->buff_in_count > 0)
		snd_uart16550_add_timer(uart);
}

/*                             
                              
                                                                            
                       
                                                                 
                                             
                    
                     
                                                                             
                                                                     
                                                                              
                                                                                
                                               
                                                                          
                 
  
  
                                                                       
                                                                    
 */
static irqreturn_t snd_uart16550_interrupt(int irq, void *dev_id)
{
	struct snd_uart16550 *uart;

	uart = dev_id;
	spin_lock(&uart->open_lock);
	if (uart->filemode == SERIAL_MODE_NOT_OPENED) {
		spin_unlock(&uart->open_lock);
		return IRQ_NONE;
	}
	/*                                                           */
	inb(uart->base + UART_IIR);
	snd_uart16550_io_loop(uart);
	spin_unlock(&uart->open_lock);
	return IRQ_HANDLED;
}

/*                                                                   */
static void snd_uart16550_buffer_timer(unsigned long data)
{
	unsigned long flags;
	struct snd_uart16550 *uart;

	uart = (struct snd_uart16550 *)data;
	spin_lock_irqsave(&uart->open_lock, flags);
	snd_uart16550_del_timer(uart);
	snd_uart16550_io_loop(uart);
	spin_unlock_irqrestore(&uart->open_lock, flags);
}

/*
                                                     
                     
                                      
 */
static int __devinit snd_uart16550_detect(struct snd_uart16550 *uart)
{
	unsigned long io_base = uart->base;
	int ok;
	unsigned char c;

	/*                                                  */
	if (io_base == 0 || io_base == SNDRV_AUTO_PORT) {
		return -ENODEV;	/*                */
	}

	uart->res_base = request_region(io_base, 8, "Serial MIDI");
	if (uart->res_base == NULL) {
		snd_printk(KERN_ERR "u16550: can't grab port 0x%lx\n", io_base);
		return -EBUSY;
	}

	/*                                                             */
	ok = 1;
	/*                                               */
	outb(UART_LCR_WLEN8, io_base + UART_LCR); /*                       */
	c = inb(io_base + UART_IER);
	/*                                                 */
	if ((c & 0xf0) != 0)
		ok = 0;		/*        */

	outb(0xaa, io_base + UART_SCR);
	/*                                           */
	c = inb(io_base + UART_SCR);
	/*                           */
	if (c != 0xaa)
		ok = 0;		/*        */

	outb(0x55, io_base + UART_SCR);
	/*                                           */
	c = inb(io_base + UART_SCR);
	/*                           */
	if (c != 0x55)
		ok = 0;		/*        */

	return ok;
}

static void snd_uart16550_do_open(struct snd_uart16550 * uart)
{
	char byte;

	/*                            */
	uart->buff_in_count = 0;
	uart->buff_in = 0;
	uart->buff_out = 0;
	uart->fifo_limit = 1;
	uart->fifo_count = 0;
	uart->timer_running = 0;

	outb(UART_FCR_ENABLE_FIFO	/*                              */
	     | UART_FCR_CLEAR_RCVR	/*                     */
	     | UART_FCR_CLEAR_XMIT	/*                        */
	     | UART_FCR_TRIGGER_4	/*                             */
	/*                                                
                                                
  */
	     ,uart->base + UART_FCR);	/*                       */

	if ((inb(uart->base + UART_IIR) & 0xf0) == 0xc0)
		uart->fifo_limit = 16;
	if (uart->divisor != 0) {
		uart->old_line_ctrl_reg = inb(uart->base + UART_LCR);
		outb(UART_LCR_DLAB	/*                          */
		     ,uart->base + UART_LCR);	/*                       */
		uart->old_divisor_lsb = inb(uart->base + UART_DLL);
		uart->old_divisor_msb = inb(uart->base + UART_DLM);

		outb(uart->divisor
		     ,uart->base + UART_DLL);	/*                   */
		outb(0
		     ,uart->base + UART_DLM);	/*                    */
		/*                                   */
	}
	/*                                         */
	outb(UART_LCR_WLEN8	/*             */
	     | 0		/*            */
	     | 0		/*            */
	     | 0		/*          */
	     ,uart->base + UART_LCR);	/*                       */

	switch (uart->adaptor) {
	default:
		outb(UART_MCR_RTS	/*                                 */
		     | UART_MCR_DTR	/*                                     */
		     | UART_MCR_OUT2	/*                                         
                                                      
     */
		     ,uart->base + UART_MCR);	/*                        */
		break;
	case SNDRV_SERIAL_MS124W_SA:
	case SNDRV_SERIAL_MS124W_MB:
		/*                                                
                             */ 
		outb(UART_MCR_RTS | (0&UART_MCR_DTR) | UART_MCR_OUT2,
		     uart->base + UART_MCR);
		break;
	case SNDRV_SERIAL_MS124T:
		/*                                                       
                                      */
		outb(UART_MCR_RTS | UART_MCR_DTR | UART_MCR_OUT2,
		     uart->base + UART_MCR);
		break;
	}

	if (uart->irq < 0) {
		byte = (0 & UART_IER_RDI)	/*                                 */
		    |(0 & UART_IER_THRI)	/*                                                      */
		    ;
	} else if (uart->adaptor == SNDRV_SERIAL_MS124W_SA) {
		byte = UART_IER_RDI	/*                                */
		    | UART_IER_MSI	/*                               */
		    ;
	} else if (uart->adaptor == SNDRV_SERIAL_GENERIC) {
		byte = UART_IER_RDI	/*                                */
		    | UART_IER_MSI	/*                               */
		    | UART_IER_THRI	/*                                                     */
		    ;
	} else {
		byte = UART_IER_RDI	/*                                */
		    | UART_IER_THRI	/*                                                     */
		    ;
	}
	outb(byte, uart->base + UART_IER);	/*                           */

	inb(uart->base + UART_LSR);	/*                                           */
	inb(uart->base + UART_IIR);	/*                                           */
	inb(uart->base + UART_RX);	/*                                          */
}

static void snd_uart16550_do_close(struct snd_uart16550 * uart)
{
	if (uart->irq < 0)
		snd_uart16550_del_timer(uart);

	/*                                                                        
                                           
  */

	outb((0 & UART_IER_RDI)		/*                                 */
	     |(0 & UART_IER_THRI)	/*                                                      */
	     ,uart->base + UART_IER);	/*                           */

	switch (uart->adaptor) {
	default:
		outb((0 & UART_MCR_RTS)		/*                                  */
		     |(0 & UART_MCR_DTR)	/*                                     */
		     |(0 & UART_MCR_OUT2)	/*                 */
		     ,uart->base + UART_MCR);	/*                        */
	  break;
	case SNDRV_SERIAL_MS124W_SA:
	case SNDRV_SERIAL_MS124W_MB:
		/*                                                
                                               */ 
		outb(UART_MCR_RTS | (0&UART_MCR_DTR) | (0&UART_MCR_OUT2),
		     uart->base + UART_MCR);
		break;
	case SNDRV_SERIAL_MS124T:
		/*                                                       
                                                        */
		outb(UART_MCR_RTS | UART_MCR_DTR | (0&UART_MCR_OUT2),
		     uart->base + UART_MCR);
		break;
	}

	inb(uart->base + UART_IIR);	/*                                  */

	/*                     */
	if (uart->divisor != 0) {
		outb(UART_LCR_DLAB		/*                          */
		     ,uart->base + UART_LCR);	/*                       */
		outb(uart->old_divisor_lsb
		     ,uart->base + UART_DLL);	/*                   */
		outb(uart->old_divisor_msb
		     ,uart->base + UART_DLM);	/*                    */
		/*                                                      */
		outb(uart->old_line_ctrl_reg
		     ,uart->base + UART_LCR);	/*                       */
	}
}

static int snd_uart16550_input_open(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_uart16550 *uart = substream->rmidi->private_data;

	spin_lock_irqsave(&uart->open_lock, flags);
	if (uart->filemode == SERIAL_MODE_NOT_OPENED)
		snd_uart16550_do_open(uart);
	uart->filemode |= SERIAL_MODE_INPUT_OPEN;
	uart->midi_input[substream->number] = substream;
	spin_unlock_irqrestore(&uart->open_lock, flags);
	return 0;
}

static int snd_uart16550_input_close(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_uart16550 *uart = substream->rmidi->private_data;

	spin_lock_irqsave(&uart->open_lock, flags);
	uart->filemode &= ~SERIAL_MODE_INPUT_OPEN;
	uart->midi_input[substream->number] = NULL;
	if (uart->filemode == SERIAL_MODE_NOT_OPENED)
		snd_uart16550_do_close(uart);
	spin_unlock_irqrestore(&uart->open_lock, flags);
	return 0;
}

static void snd_uart16550_input_trigger(struct snd_rawmidi_substream *substream,
					int up)
{
	unsigned long flags;
	struct snd_uart16550 *uart = substream->rmidi->private_data;

	spin_lock_irqsave(&uart->open_lock, flags);
	if (up)
		uart->filemode |= SERIAL_MODE_INPUT_TRIGGERED;
	else
		uart->filemode &= ~SERIAL_MODE_INPUT_TRIGGERED;
	spin_unlock_irqrestore(&uart->open_lock, flags);
}

static int snd_uart16550_output_open(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_uart16550 *uart = substream->rmidi->private_data;

	spin_lock_irqsave(&uart->open_lock, flags);
	if (uart->filemode == SERIAL_MODE_NOT_OPENED)
		snd_uart16550_do_open(uart);
	uart->filemode |= SERIAL_MODE_OUTPUT_OPEN;
	uart->midi_output[substream->number] = substream;
	spin_unlock_irqrestore(&uart->open_lock, flags);
	return 0;
};

static int snd_uart16550_output_close(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	struct snd_uart16550 *uart = substream->rmidi->private_data;

	spin_lock_irqsave(&uart->open_lock, flags);
	uart->filemode &= ~SERIAL_MODE_OUTPUT_OPEN;
	uart->midi_output[substream->number] = NULL;
	if (uart->filemode == SERIAL_MODE_NOT_OPENED)
		snd_uart16550_do_close(uart);
	spin_unlock_irqrestore(&uart->open_lock, flags);
	return 0;
};

static inline int snd_uart16550_buffer_can_write(struct snd_uart16550 *uart,
						 int Num)
{
	if (uart->buff_in_count + Num < TX_BUFF_SIZE)
		return 1;
	else
		return 0;
}

static inline int snd_uart16550_write_buffer(struct snd_uart16550 *uart,
					     unsigned char byte)
{
	unsigned short buff_in = uart->buff_in;
	if (uart->buff_in_count < TX_BUFF_SIZE) {
		uart->tx_buff[buff_in] = byte;
		buff_in++;
		buff_in &= TX_BUFF_MASK;
		uart->buff_in = buff_in;
		uart->buff_in_count++;
		if (uart->irq < 0) /*              */
			snd_uart16550_add_timer(uart);
		return 1;
	} else
		return 0;
}

static int snd_uart16550_output_byte(struct snd_uart16550 *uart,
				     struct snd_rawmidi_substream *substream,
				     unsigned char midi_byte)
{
	if (uart->buff_in_count == 0                    /*               */
	    && ((uart->adaptor != SNDRV_SERIAL_MS124W_SA &&
	    uart->adaptor != SNDRV_SERIAL_GENERIC) ||
		(uart->fifo_count == 0                  /*             */
		 && (inb(uart->base + UART_MSR) & UART_MSR_CTS)))) { /*      */

	        /*                                            */
		if ((inb(uart->base + UART_LSR) & UART_LSR_THRE) != 0) {
		        /*                                                  */
		        uart->fifo_count = 1;
			outb(midi_byte, uart->base + UART_TX);
		} else {
		        if (uart->fifo_count < uart->fifo_limit) {
			        uart->fifo_count++;
				outb(midi_byte, uart->base + UART_TX);
			} else {
			        /*                              
                          */
				snd_uart16550_write_buffer(uart, midi_byte);
			}
		}
	} else {
		if (!snd_uart16550_write_buffer(uart, midi_byte)) {
			snd_printk(KERN_WARNING
				   "%s: Buffer overrun on device at 0x%lx\n",
				   uart->rmidi->name, uart->base);
			return 0;
		}
	}

	return 1;
}

static void snd_uart16550_output_write(struct snd_rawmidi_substream *substream)
{
	unsigned long flags;
	unsigned char midi_byte, addr_byte;
	struct snd_uart16550 *uart = substream->rmidi->private_data;
	char first;
	static unsigned long lasttime = 0;
	
	/*                                                            
                                                             
                                     
  */

	spin_lock_irqsave(&uart->open_lock, flags);

	if (uart->irq < 0)	/*         */
		snd_uart16550_io_loop(uart);

	if (uart->adaptor == SNDRV_SERIAL_MS124W_MB) {
		while (1) {
			/*              */
			/*                                         */
			if (uart->buff_in_count > TX_BUFF_SIZE - 2)
				break;
			if (snd_rawmidi_transmit(substream, &midi_byte, 1) != 1)
				break;
#ifdef SNDRV_SERIAL_MS124W_MB_NOCOMBO
			/*                                      */
			addr_byte = (1 << (substream->number + 4)) | 0x08;
#else
			/*                                          */
			addr_byte = (substream->number << 4) | 0x08;
			/*                */
			if (addr_byte == 0x08)
				addr_byte = 0xf8;
#endif
			snd_uart16550_output_byte(uart, substream, addr_byte);
			/*                */
			snd_uart16550_output_byte(uart, substream, midi_byte);
		}
	} else {
		first = 0;
		while (snd_rawmidi_transmit_peek(substream, &midi_byte, 1) == 1) {
			/*                                          
                                  */
			if (first == 0 &&
			    (uart->adaptor == SNDRV_SERIAL_SOUNDCANVAS ||
			     uart->adaptor == SNDRV_SERIAL_GENERIC) &&
			    (uart->prev_out != substream->number ||
			     time_after(jiffies, lasttime + 3*HZ))) {

				if (snd_uart16550_buffer_can_write(uart, 3)) {
					/*                                   */
					/*                                 
                                    
                                          
             
      */
					uart->prev_out = substream->number;
					/*             */
					snd_uart16550_output_byte(uart, substream,
								  0xf5);
					/*      */
					snd_uart16550_output_byte(uart, substream,
								  uart->prev_out + 1);
					/*                             
                                      */
					if (midi_byte < 0x80 &&
					    uart->adaptor == SNDRV_SERIAL_SOUNDCANVAS)
						snd_uart16550_output_byte(uart, substream, uart->prev_status[uart->prev_out]);
				} else if (!uart->drop_on_full)
					break;

			}

			/*                */
			if (!snd_uart16550_output_byte(uart, substream, midi_byte) &&
			    !uart->drop_on_full )
				break;

			if (midi_byte >= 0x80 && midi_byte < 0xf0)
				uart->prev_status[uart->prev_out] = midi_byte;
			first = 1;

			snd_rawmidi_transmit_ack( substream, 1 );
		}
		lasttime = jiffies;
	}
	spin_unlock_irqrestore(&uart->open_lock, flags);
}

static void snd_uart16550_output_trigger(struct snd_rawmidi_substream *substream,
					 int up)
{
	unsigned long flags;
	struct snd_uart16550 *uart = substream->rmidi->private_data;

	spin_lock_irqsave(&uart->open_lock, flags);
	if (up)
		uart->filemode |= SERIAL_MODE_OUTPUT_TRIGGERED;
	else
		uart->filemode &= ~SERIAL_MODE_OUTPUT_TRIGGERED;
	spin_unlock_irqrestore(&uart->open_lock, flags);
	if (up)
		snd_uart16550_output_write(substream);
}

static struct snd_rawmidi_ops snd_uart16550_output =
{
	.open =		snd_uart16550_output_open,
	.close =	snd_uart16550_output_close,
	.trigger =	snd_uart16550_output_trigger,
};

static struct snd_rawmidi_ops snd_uart16550_input =
{
	.open =		snd_uart16550_input_open,
	.close =	snd_uart16550_input_close,
	.trigger =	snd_uart16550_input_trigger,
};

static int snd_uart16550_free(struct snd_uart16550 *uart)
{
	if (uart->irq >= 0)
		free_irq(uart->irq, uart);
	release_and_free_resource(uart->res_base);
	kfree(uart);
	return 0;
};

static int snd_uart16550_dev_free(struct snd_device *device)
{
	struct snd_uart16550 *uart = device->device_data;
	return snd_uart16550_free(uart);
}

static int __devinit snd_uart16550_create(struct snd_card *card,
				       unsigned long iobase,
				       int irq,
				       unsigned int speed,
				       unsigned int base,
				       int adaptor,
				       int droponfull,
				       struct snd_uart16550 **ruart)
{
	static struct snd_device_ops ops = {
		.dev_free =	snd_uart16550_dev_free,
	};
	struct snd_uart16550 *uart;
	int err;


	if ((uart = kzalloc(sizeof(*uart), GFP_KERNEL)) == NULL)
		return -ENOMEM;
	uart->adaptor = adaptor;
	uart->card = card;
	spin_lock_init(&uart->open_lock);
	uart->irq = -1;
	uart->base = iobase;
	uart->drop_on_full = droponfull;

	if ((err = snd_uart16550_detect(uart)) <= 0) {
		printk(KERN_ERR "no UART detected at 0x%lx\n", iobase);
		snd_uart16550_free(uart);
		return -ENODEV;
	}

	if (irq >= 0 && irq != SNDRV_AUTO_IRQ) {
		if (request_irq(irq, snd_uart16550_interrupt,
				0, "Serial MIDI", uart)) {
			snd_printk(KERN_WARNING
				   "irq %d busy. Using Polling.\n", irq);
		} else {
			uart->irq = irq;
		}
	}
	uart->divisor = base / speed;
	uart->speed = base / (unsigned int)uart->divisor;
	uart->speed_base = base;
	uart->prev_out = -1;
	uart->prev_in = 0;
	uart->rstatus = 0;
	memset(uart->prev_status, 0x80, sizeof(unsigned char) * SNDRV_SERIAL_MAX_OUTS);
	init_timer(&uart->buffer_timer);
	uart->buffer_timer.function = snd_uart16550_buffer_timer;
	uart->buffer_timer.data = (unsigned long)uart;
	uart->timer_running = 0;

	/*                 */
	if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, uart, &ops)) < 0) {
		snd_uart16550_free(uart);
		return err;
	}

	switch (uart->adaptor) {
	case SNDRV_SERIAL_MS124W_SA:
	case SNDRV_SERIAL_MS124W_MB:
		/*                                                
                             */ 
		outb(UART_MCR_RTS | (0&UART_MCR_DTR), uart->base + UART_MCR);
		break;
	case SNDRV_SERIAL_MS124T:
		/*                                                       
                                 */
		outb(UART_MCR_RTS | UART_MCR_DTR, uart->base + UART_MCR);
		break;
	default:
		break;
	}

	if (ruart)
		*ruart = uart;

	return 0;
}

static void __devinit snd_uart16550_substreams(struct snd_rawmidi_str *stream)
{
	struct snd_rawmidi_substream *substream;

	list_for_each_entry(substream, &stream->substreams, list) {
		sprintf(substream->name, "Serial MIDI %d", substream->number + 1);
	}
}

static int __devinit snd_uart16550_rmidi(struct snd_uart16550 *uart, int device,
				      int outs, int ins,
				      struct snd_rawmidi **rmidi)
{
	struct snd_rawmidi *rrawmidi;
	int err;

	err = snd_rawmidi_new(uart->card, "UART Serial MIDI", device,
			      outs, ins, &rrawmidi);
	if (err < 0)
		return err;
	snd_rawmidi_set_ops(rrawmidi, SNDRV_RAWMIDI_STREAM_INPUT,
			    &snd_uart16550_input);
	snd_rawmidi_set_ops(rrawmidi, SNDRV_RAWMIDI_STREAM_OUTPUT,
			    &snd_uart16550_output);
	strcpy(rrawmidi->name, "Serial MIDI");
	snd_uart16550_substreams(&rrawmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT]);
	snd_uart16550_substreams(&rrawmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT]);
	rrawmidi->info_flags = SNDRV_RAWMIDI_INFO_OUTPUT |
			       SNDRV_RAWMIDI_INFO_INPUT |
			       SNDRV_RAWMIDI_INFO_DUPLEX;
	rrawmidi->private_data = uart;
	if (rmidi)
		*rmidi = rrawmidi;
	return 0;
}

static int __devinit snd_serial_probe(struct platform_device *devptr)
{
	struct snd_card *card;
	struct snd_uart16550 *uart;
	int err;
	int dev = devptr->id;

	switch (adaptor[dev]) {
	case SNDRV_SERIAL_SOUNDCANVAS:
		ins[dev] = 1;
		break;
	case SNDRV_SERIAL_MS124T:
	case SNDRV_SERIAL_MS124W_SA:
		outs[dev] = 1;
		ins[dev] = 1;
		break;
	case SNDRV_SERIAL_MS124W_MB:
		outs[dev] = 16;
		ins[dev] = 1;
		break;
	case SNDRV_SERIAL_GENERIC:
		break;
	default:
		snd_printk(KERN_ERR
			   "Adaptor type is out of range 0-%d (%d)\n",
			   SNDRV_SERIAL_MAX_ADAPTOR, adaptor[dev]);
		return -ENODEV;
	}

	if (outs[dev] < 1 || outs[dev] > SNDRV_SERIAL_MAX_OUTS) {
		snd_printk(KERN_ERR
			   "Count of outputs is out of range 1-%d (%d)\n",
			   SNDRV_SERIAL_MAX_OUTS, outs[dev]);
		return -ENODEV;
	}

	if (ins[dev] < 1 || ins[dev] > SNDRV_SERIAL_MAX_INS) {
		snd_printk(KERN_ERR
			   "Count of inputs is out of range 1-%d (%d)\n",
			   SNDRV_SERIAL_MAX_INS, ins[dev]);
		return -ENODEV;
	}

	err  = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
	if (err < 0)
		return err;

	strcpy(card->driver, "Serial");
	strcpy(card->shortname, "Serial MIDI (UART16550A)");

	if ((err = snd_uart16550_create(card,
					port[dev],
					irq[dev],
					speed[dev],
					base[dev],
					adaptor[dev],
					droponfull[dev],
					&uart)) < 0)
		goto _err;

	err = snd_uart16550_rmidi(uart, 0, outs[dev], ins[dev], &uart->rmidi);
	if (err < 0)
		goto _err;

	sprintf(card->longname, "%s [%s] at %#lx, irq %d",
		card->shortname,
		adaptor_names[uart->adaptor],
		uart->base,
		uart->irq);

	snd_card_set_dev(card, &devptr->dev);

	if ((err = snd_card_register(card)) < 0)
		goto _err;

	platform_set_drvdata(devptr, card);
	return 0;

 _err:
	snd_card_free(card);
	return err;
}

static int __devexit snd_serial_remove(struct platform_device *devptr)
{
	snd_card_free(platform_get_drvdata(devptr));
	platform_set_drvdata(devptr, NULL);
	return 0;
}

#define SND_SERIAL_DRIVER	"snd_serial_u16550"

static struct platform_driver snd_serial_driver = {
	.probe		= snd_serial_probe,
	.remove		= __devexit_p( snd_serial_remove),
	.driver		= {
		.name	= SND_SERIAL_DRIVER
	},
};

static void snd_serial_unregister_all(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(devices); ++i)
		platform_device_unregister(devices[i]);
	platform_driver_unregister(&snd_serial_driver);
}

static int __init alsa_card_serial_init(void)
{
	int i, cards, err;

	if ((err = platform_driver_register(&snd_serial_driver)) < 0)
		return err;

	cards = 0;
	for (i = 0; i < SNDRV_CARDS; i++) {
		struct platform_device *device;
		if (! enable[i])
			continue;
		device = platform_device_register_simple(SND_SERIAL_DRIVER,
							 i, NULL, 0);
		if (IS_ERR(device))
			continue;
		if (!platform_get_drvdata(device)) {
			platform_device_unregister(device);
			continue;
		}
		devices[i] = device;
		cards++;
	}
	if (! cards) {
#ifdef MODULE
		printk(KERN_ERR "serial midi soundcard not found or device busy\n");
#endif
		snd_serial_unregister_all();
		return -ENODEV;
	}
	return 0;
}

static void __exit alsa_card_serial_exit(void)
{
	snd_serial_unregister_all();
}

module_init(alsa_card_serial_init)
module_exit(alsa_card_serial_exit)
