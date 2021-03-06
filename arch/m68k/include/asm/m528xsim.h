/*                                                                          */

/*
 *	m528xsim.h -- ColdFire 5280/5282 System Integration Module support.
 *
 *	(C) Copyright 2003, Greg Ungerer (gerg@snapgear.com)
 */

/*                                                                          */
#ifndef	m528xsim_h
#define	m528xsim_h
/*                                                                          */

#define	CPU_NAME		"COLDFIRE(m528x)"
#define	CPU_INSTR_PER_JIFFY	3
#define	MCF_BUSCLK		MCF_CLK

#include <asm/m52xxacr.h>

/*
                                                   
 */
#define	MCFICM_INTC0		(MCF_IPSBAR + 0x0c00)	/*                           */
#define	MCFICM_INTC1		(MCF_IPSBAR + 0x0d00)	/*                           */

#define	MCFINTC_IPRH		0x00		/*                         */
#define	MCFINTC_IPRL		0x04		/*                        */
#define	MCFINTC_IMRH		0x08		/*                      */
#define	MCFINTC_IMRL		0x0c		/*                     */
#define	MCFINTC_INTFRCH		0x10		/*                       */
#define	MCFINTC_INTFRCL		0x14		/*                      */
#define	MCFINTC_IRLR		0x18		/* */
#define	MCFINTC_IACKL		0x19		/* */
#define	MCFINTC_ICR0		0x40		/*                   */

#define	MCFINT_VECBASE		64		/*                    */
#define	MCFINT_UART0		13		/*                            */
#define	MCFINT_UART1		14		/*                            */
#define	MCFINT_UART2		15		/*                            */
#define	MCFINT_QSPI		18		/*                           */
#define	MCFINT_FECRX0		23		/*                          */
#define	MCFINT_FECTX0		27		/*                          */
#define	MCFINT_FECENTC0		29		/*                          */
#define	MCFINT_PIT1		55		/*                           */

#define	MCF_IRQ_UART0	        (MCFINT_VECBASE + MCFINT_UART0)
#define	MCF_IRQ_UART1	        (MCFINT_VECBASE + MCFINT_UART1)
#define	MCF_IRQ_UART2	        (MCFINT_VECBASE + MCFINT_UART2)

#define	MCF_IRQ_FECRX0		(MCFINT_VECBASE + MCFINT_FECRX0)
#define	MCF_IRQ_FECTX0		(MCFINT_VECBASE + MCFINT_FECTX0)
#define	MCF_IRQ_FECENTC0	(MCFINT_VECBASE + MCFINT_FECENTC0)

#define	MCF_IRQ_QSPI		(MCFINT_VECBASE + MCFINT_QSPI)

/*
                                 
 */
#define	MCFSIM_DCR		(MCF_IPSBAR + 0x00000044) /*         */
#define	MCFSIM_DACR0		(MCF_IPSBAR + 0x00000048) /*                */
#define	MCFSIM_DMR0		(MCF_IPSBAR + 0x0000004c) /*                */
#define	MCFSIM_DACR1		(MCF_IPSBAR + 0x00000050) /*                */
#define	MCFSIM_DMR1		(MCF_IPSBAR + 0x00000054) /*                */

/*
                           
 */
#define	MCFDMA_BASE0		(MCF_IPSBAR + 0x00000100)
#define	MCFDMA_BASE1		(MCF_IPSBAR + 0x00000140)
#define	MCFDMA_BASE2		(MCF_IPSBAR + 0x00000180)
#define	MCFDMA_BASE3		(MCF_IPSBAR + 0x000001C0)

/*
               
 */
#define	MCFUART_BASE0		(MCF_IPSBAR + 0x00000200)
#define	MCFUART_BASE1		(MCF_IPSBAR + 0x00000240)
#define	MCFUART_BASE2		(MCF_IPSBAR + 0x00000280)

/*
                       
 */
#define	MCFFEC_BASE0		(MCF_IPSBAR + 0x00001000)
#define	MCFFEC_SIZE0		0x800

/*
               
 */
#define	MCFQSPI_IOBASE		(MCF_IPSBAR + 0x340)
#define	MCFQSPI_SIZE		0x40

#define	MCFQSPI_CS0		147
#define	MCFQSPI_CS1		148
#define	MCFQSPI_CS2		149
#define	MCFQSPI_CS3		150

/*
                  
 */
#define MCFGPIO_PORTA		(MCF_IPSBAR + 0x00100000)
#define MCFGPIO_PORTB		(MCF_IPSBAR + 0x00100001)
#define MCFGPIO_PORTC		(MCF_IPSBAR + 0x00100002)
#define MCFGPIO_PORTD		(MCF_IPSBAR + 0x00100003)
#define MCFGPIO_PORTE		(MCF_IPSBAR + 0x00100004)
#define MCFGPIO_PORTF		(MCF_IPSBAR + 0x00100005)
#define MCFGPIO_PORTG		(MCF_IPSBAR + 0x00100006)
#define MCFGPIO_PORTH		(MCF_IPSBAR + 0x00100007)
#define MCFGPIO_PORTJ		(MCF_IPSBAR + 0x00100008)
#define MCFGPIO_PORTDD		(MCF_IPSBAR + 0x00100009)
#define MCFGPIO_PORTEH		(MCF_IPSBAR + 0x0010000A)
#define MCFGPIO_PORTEL		(MCF_IPSBAR + 0x0010000B)
#define MCFGPIO_PORTAS		(MCF_IPSBAR + 0x0010000C)
#define MCFGPIO_PORTQS		(MCF_IPSBAR + 0x0010000D)
#define MCFGPIO_PORTSD		(MCF_IPSBAR + 0x0010000E)
#define MCFGPIO_PORTTC		(MCF_IPSBAR + 0x0010000F)
#define MCFGPIO_PORTTD		(MCF_IPSBAR + 0x00100010)
#define MCFGPIO_PORTUA		(MCF_IPSBAR + 0x00100011)

#define MCFGPIO_DDRA		(MCF_IPSBAR + 0x00100014)
#define MCFGPIO_DDRB		(MCF_IPSBAR + 0x00100015)
#define MCFGPIO_DDRC		(MCF_IPSBAR + 0x00100016)
#define MCFGPIO_DDRD		(MCF_IPSBAR + 0x00100017)
#define MCFGPIO_DDRE		(MCF_IPSBAR + 0x00100018)
#define MCFGPIO_DDRF		(MCF_IPSBAR + 0x00100019)
#define MCFGPIO_DDRG		(MCF_IPSBAR + 0x0010001A)
#define MCFGPIO_DDRH		(MCF_IPSBAR + 0x0010001B)
#define MCFGPIO_DDRJ		(MCF_IPSBAR + 0x0010001C)
#define MCFGPIO_DDRDD		(MCF_IPSBAR + 0x0010001D)
#define MCFGPIO_DDREH		(MCF_IPSBAR + 0x0010001E)
#define MCFGPIO_DDREL		(MCF_IPSBAR + 0x0010001F)
#define MCFGPIO_DDRAS		(MCF_IPSBAR + 0x00100020)
#define MCFGPIO_DDRQS		(MCF_IPSBAR + 0x00100021)
#define MCFGPIO_DDRSD		(MCF_IPSBAR + 0x00100022)
#define MCFGPIO_DDRTC		(MCF_IPSBAR + 0x00100023)
#define MCFGPIO_DDRTD		(MCF_IPSBAR + 0x00100024)
#define MCFGPIO_DDRUA		(MCF_IPSBAR + 0x00100025)

#define MCFGPIO_PORTAP		(MCF_IPSBAR + 0x00100028)
#define MCFGPIO_PORTBP		(MCF_IPSBAR + 0x00100029)
#define MCFGPIO_PORTCP		(MCF_IPSBAR + 0x0010002A)
#define MCFGPIO_PORTDP		(MCF_IPSBAR + 0x0010002B)
#define MCFGPIO_PORTEP		(MCF_IPSBAR + 0x0010002C)
#define MCFGPIO_PORTFP		(MCF_IPSBAR + 0x0010002D)
#define MCFGPIO_PORTGP		(MCF_IPSBAR + 0x0010002E)
#define MCFGPIO_PORTHP		(MCF_IPSBAR + 0x0010002F)
#define MCFGPIO_PORTJP		(MCF_IPSBAR + 0x00100030)
#define MCFGPIO_PORTDDP		(MCF_IPSBAR + 0x00100031)
#define MCFGPIO_PORTEHP		(MCF_IPSBAR + 0x00100032)
#define MCFGPIO_PORTELP		(MCF_IPSBAR + 0x00100033)
#define MCFGPIO_PORTASP		(MCF_IPSBAR + 0x00100034)
#define MCFGPIO_PORTQSP		(MCF_IPSBAR + 0x00100035)
#define MCFGPIO_PORTSDP		(MCF_IPSBAR + 0x00100036)
#define MCFGPIO_PORTTCP		(MCF_IPSBAR + 0x00100037)
#define MCFGPIO_PORTTDP		(MCF_IPSBAR + 0x00100038)
#define MCFGPIO_PORTUAP		(MCF_IPSBAR + 0x00100039)

#define MCFGPIO_SETA		(MCF_IPSBAR + 0x00100028)
#define MCFGPIO_SETB		(MCF_IPSBAR + 0x00100029)
#define MCFGPIO_SETC		(MCF_IPSBAR + 0x0010002A)
#define MCFGPIO_SETD		(MCF_IPSBAR + 0x0010002B)
#define MCFGPIO_SETE		(MCF_IPSBAR + 0x0010002C)
#define MCFGPIO_SETF		(MCF_IPSBAR + 0x0010002D)
#define MCFGPIO_SETG		(MCF_IPSBAR + 0x0010002E)
#define MCFGPIO_SETH		(MCF_IPSBAR + 0x0010002F)
#define MCFGPIO_SETJ		(MCF_IPSBAR + 0x00100030)
#define MCFGPIO_SETDD		(MCF_IPSBAR + 0x00100031)
#define MCFGPIO_SETEH		(MCF_IPSBAR + 0x00100032)
#define MCFGPIO_SETEL		(MCF_IPSBAR + 0x00100033)
#define MCFGPIO_SETAS		(MCF_IPSBAR + 0x00100034)
#define MCFGPIO_SETQS		(MCF_IPSBAR + 0x00100035)
#define MCFGPIO_SETSD		(MCF_IPSBAR + 0x00100036)
#define MCFGPIO_SETTC		(MCF_IPSBAR + 0x00100037)
#define MCFGPIO_SETTD		(MCF_IPSBAR + 0x00100038)
#define MCFGPIO_SETUA		(MCF_IPSBAR + 0x00100039)

#define MCFGPIO_CLRA		(MCF_IPSBAR + 0x0010003C)
#define MCFGPIO_CLRB		(MCF_IPSBAR + 0x0010003D)
#define MCFGPIO_CLRC		(MCF_IPSBAR + 0x0010003E)
#define MCFGPIO_CLRD		(MCF_IPSBAR + 0x0010003F)
#define MCFGPIO_CLRE		(MCF_IPSBAR + 0x00100040)
#define MCFGPIO_CLRF		(MCF_IPSBAR + 0x00100041)
#define MCFGPIO_CLRG		(MCF_IPSBAR + 0x00100042)
#define MCFGPIO_CLRH		(MCF_IPSBAR + 0x00100043)
#define MCFGPIO_CLRJ		(MCF_IPSBAR + 0x00100044)
#define MCFGPIO_CLRDD		(MCF_IPSBAR + 0x00100045)
#define MCFGPIO_CLREH		(MCF_IPSBAR + 0x00100046)
#define MCFGPIO_CLREL		(MCF_IPSBAR + 0x00100047)
#define MCFGPIO_CLRAS		(MCF_IPSBAR + 0x00100048)
#define MCFGPIO_CLRQS		(MCF_IPSBAR + 0x00100049)
#define MCFGPIO_CLRSD		(MCF_IPSBAR + 0x0010004A)
#define MCFGPIO_CLRTC		(MCF_IPSBAR + 0x0010004B)
#define MCFGPIO_CLRTD		(MCF_IPSBAR + 0x0010004C)
#define MCFGPIO_CLRUA		(MCF_IPSBAR + 0x0010004D)

#define MCFGPIO_PBCDPAR		(MCF_IPSBAR + 0x00100050)
#define MCFGPIO_PFPAR		(MCF_IPSBAR + 0x00100051)
#define MCFGPIO_PEPAR		(MCF_IPSBAR + 0x00100052)
#define MCFGPIO_PJPAR		(MCF_IPSBAR + 0x00100054)
#define MCFGPIO_PSDPAR		(MCF_IPSBAR + 0x00100055)
#define MCFGPIO_PASPAR		(MCF_IPSBAR + 0x00100056)
#define MCFGPIO_PEHLPAR		(MCF_IPSBAR + 0x00100058)
#define MCFGPIO_PQSPAR		(MCF_IPSBAR + 0x00100059)
#define MCFGPIO_PTCPAR		(MCF_IPSBAR + 0x0010005A)
#define MCFGPIO_PTDPAR		(MCF_IPSBAR + 0x0010005B)
#define MCFGPIO_PUAPAR		(MCF_IPSBAR + 0x0010005C)

/*
                            
 */
#define	MCFPIT_BASE1		(MCF_IPSBAR + 0x00150000)
#define	MCFPIT_BASE2		(MCF_IPSBAR + 0x00160000)
#define	MCFPIT_BASE3		(MCF_IPSBAR + 0x00170000)
#define	MCFPIT_BASE4		(MCF_IPSBAR + 0x00180000)

/*
                       
 */
#define MCFEPORT_EPPAR		(MCF_IPSBAR + 0x00130000)
#define MCFEPORT_EPDDR		(MCF_IPSBAR + 0x00130002)
#define MCFEPORT_EPIER		(MCF_IPSBAR + 0x00130003)
#define MCFEPORT_EPDR		(MCF_IPSBAR + 0x00130004)
#define MCFEPORT_EPPDR		(MCF_IPSBAR + 0x00130005)
#define MCFEPORT_EPFR		(MCF_IPSBAR + 0x00130006)

/*
                        
 */
#define MCFQADC_PORTQA		(MCF_IPSBAR + 0x00190006)
#define MCFQADC_PORTQB		(MCF_IPSBAR + 0x00190007)
#define MCFQADC_DDRQA		(MCF_IPSBAR + 0x00190008)
#define MCFQADC_DDRQB		(MCF_IPSBAR + 0x00190009)

/*
                                    
 */
#define MCFGPTA_GPTPORT		(MCF_IPSBAR + 0x001A001D)
#define MCFGPTA_GPTDDR		(MCF_IPSBAR + 0x001A001E)
#define MCFGPTB_GPTPORT		(MCF_IPSBAR + 0x001B001D)
#define MCFGPTB_GPTDDR		(MCF_IPSBAR + 0x001B001E)
/*
  
                                       
  
 */
#define MCFGPIO_PODR		MCFGPIO_PORTA	/*                  */
#define MCFGPIO_PDDR		MCFGPIO_DDRA	/*                     */
#define MCFGPIO_PPDR		MCFGPIO_PORTAP	/*               */
#define MCFGPIO_SETR		MCFGPIO_SETA	/*            */
#define MCFGPIO_CLRR		MCFGPIO_CLRA	/*            */

#define MCFGPIO_IRQ_MAX		8
#define MCFGPIO_IRQ_VECBASE	MCFINT_VECBASE
#define MCFGPIO_PIN_MAX		180


/*
                            
                                                                  
 */
/*                                 */
#define MCF5282_GPIO_PASPAR     (volatile u16 *) (MCF_IPSBAR + 0x00100056)

/*                                         */
#define MCF5282_GPIO_PUAPAR	0x10005C

/*                                      */ 
#define MCF5282_INTC0_IMRL      (volatile u32 *) (MCF_IPSBAR + 0x0C0C)
/*                              */
#define MCF5282_INTC0_ICR17     (volatile u8 *) (MCF_IPSBAR + 0x0C51)


/*
                                            
 */
#define	MCF_RCR			(MCF_IPSBAR + 0x110000)
#define	MCF_RSR			(MCF_IPSBAR + 0x110001)

#define	MCF_RCR_SWRESET		0x80		/*                    */
#define	MCF_RCR_FRCSTOUT	0x40		/*                      */

/*                                                                    
 
                       
 
                                                                    */
/*                                          */
#define MCF5282_I2C_I2ADR       (volatile u8 *) (MCF_IPSBAR + 0x0300) //         
#define MCF5282_I2C_I2FDR       (volatile u8 *) (MCF_IPSBAR + 0x0304) //             
#define MCF5282_I2C_I2CR        (volatile u8 *) (MCF_IPSBAR + 0x0308) //        
#define MCF5282_I2C_I2SR        (volatile u8 *) (MCF_IPSBAR + 0x030C) //       
#define MCF5282_I2C_I2DR        (volatile u8 *) (MCF_IPSBAR + 0x0310) //         

/*                                  */
#define MCF5282_I2C_I2ADR_ADDR(x)                       (((x)&0x7F)<<0x01)

#define MCF5282_I2C_I2FDR_IC(x)                         (((x)&0x3F))

#define MCF5282_I2C_I2CR_IEN    (0x80)	//           
#define MCF5282_I2C_I2CR_IIEN   (0x40)  //                 
#define MCF5282_I2C_I2CR_MSTA   (0x20)  //                  
#define MCF5282_I2C_I2CR_MTX    (0x10)  //                      
#define MCF5282_I2C_I2CR_TXAK   (0x08)  //                            
#define MCF5282_I2C_I2CR_RSTA   (0x04)  //             

#define MCF5282_I2C_I2SR_ICF    (0x80)  //                  
#define MCF5282_I2C_I2SR_IAAS   (0x40)  //                         
#define MCF5282_I2C_I2SR_IBB    (0x20)  //             
#define MCF5282_I2C_I2SR_IAL    (0x10)  //                  
#define MCF5282_I2C_I2SR_SRW    (0x04)  //                 
#define MCF5282_I2C_I2SR_IIF    (0x02)  //              
#define MCF5282_I2C_I2SR_RXAK   (0x01)  //                     


#endif	/*            */
