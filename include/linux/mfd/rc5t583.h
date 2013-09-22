/*
 * Core driver interface to access RICOH_RC5T583 power management chip.
 *
 * Copyright (c) 2011-2012, NVIDIA CORPORATION.  All rights reserved.
 * Author: Laxman dewangan <ldewangan@nvidia.com>
 *
 * Based on code
 *      Copyright (C) 2011 RICOH COMPANY,LTD
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __LINUX_MFD_RC5T583_H
#define __LINUX_MFD_RC5T583_H

#include <linux/mutex.h>
#include <linux/types.h>
#include <linux/regmap.h>

#define RC5T583_MAX_REGS		0xF8

/*                                   */
#define MAX_MAIN_INTERRUPT		5
#define RC5T583_MAX_GPEDGE_REG		2
#define RC5T583_MAX_INTERRUPT_MASK_REGS	9

/*                           */
#define RC5T583_INT_EN_SYS1	0x19
#define RC5T583_INT_EN_SYS2	0x1D
#define RC5T583_INT_EN_DCDC	0x41
#define RC5T583_INT_EN_RTC	0xED
#define RC5T583_INT_EN_ADC1	0x90
#define RC5T583_INT_EN_ADC2	0x91
#define RC5T583_INT_EN_ADC3	0x92

/*                                                   */
#define RC5T583_INTC_INTPOL	0xAD
#define RC5T583_INTC_INTEN	0xAE
#define RC5T583_INTC_INTMON	0xAF

#define RC5T583_INT_MON_GRP	0xAF
#define RC5T583_INT_MON_SYS1	0x1B
#define RC5T583_INT_MON_SYS2	0x1F
#define RC5T583_INT_MON_DCDC	0x43
#define RC5T583_INT_MON_RTC	0xEE

/*                              */
#define RC5T583_INT_IR_SYS1	0x1A
#define RC5T583_INT_IR_SYS2	0x1E
#define RC5T583_INT_IR_DCDC	0x42
#define RC5T583_INT_IR_RTC	0xEE
#define RC5T583_INT_IR_ADCL	0x94
#define RC5T583_INT_IR_ADCH	0x95
#define RC5T583_INT_IR_ADCEND	0x96
#define RC5T583_INT_IR_GPIOR	0xA9
#define RC5T583_INT_IR_GPIOF	0xAA

/*                          */
#define RC5T583_SLPSEQ1		0x21
#define RC5T583_SLPSEQ2		0x22
#define RC5T583_SLPSEQ3		0x23
#define RC5T583_SLPSEQ4		0x24
#define RC5T583_SLPSEQ5		0x25
#define RC5T583_SLPSEQ6		0x26
#define RC5T583_SLPSEQ7		0x27
#define RC5T583_SLPSEQ8		0x28
#define RC5T583_SLPSEQ9		0x29
#define RC5T583_SLPSEQ10	0x2A
#define RC5T583_SLPSEQ11	0x2B

/*                     */
#define RC5T583_REG_DC0CTL	0x30
#define RC5T583_REG_DC0DAC	0x31
#define RC5T583_REG_DC0LATCTL	0x32
#define RC5T583_REG_SR0CTL	0x33

#define RC5T583_REG_DC1CTL	0x34
#define RC5T583_REG_DC1DAC	0x35
#define RC5T583_REG_DC1LATCTL	0x36
#define RC5T583_REG_SR1CTL	0x37

#define RC5T583_REG_DC2CTL	0x38
#define RC5T583_REG_DC2DAC	0x39
#define RC5T583_REG_DC2LATCTL	0x3A
#define RC5T583_REG_SR2CTL	0x3B

#define RC5T583_REG_DC3CTL	0x3C
#define RC5T583_REG_DC3DAC	0x3D
#define RC5T583_REG_DC3LATCTL	0x3E
#define RC5T583_REG_SR3CTL	0x3F


#define RC5T583_REG_LDOEN1	0x50
#define RC5T583_REG_LDOEN2	0x51
#define RC5T583_REG_LDODIS1	0x52
#define RC5T583_REG_LDODIS2	0x53

#define RC5T583_REG_LDO0DAC	0x54
#define RC5T583_REG_LDO1DAC	0x55
#define RC5T583_REG_LDO2DAC	0x56
#define RC5T583_REG_LDO3DAC	0x57
#define RC5T583_REG_LDO4DAC	0x58
#define RC5T583_REG_LDO5DAC	0x59
#define RC5T583_REG_LDO6DAC	0x5A
#define RC5T583_REG_LDO7DAC	0x5B
#define RC5T583_REG_LDO8DAC	0x5C
#define RC5T583_REG_LDO9DAC	0x5D

#define RC5T583_REG_DC0DAC_DS	0x60
#define RC5T583_REG_DC1DAC_DS	0x61
#define RC5T583_REG_DC2DAC_DS	0x62
#define RC5T583_REG_DC3DAC_DS	0x63

#define RC5T583_REG_LDO0DAC_DS	0x64
#define RC5T583_REG_LDO1DAC_DS	0x65
#define RC5T583_REG_LDO2DAC_DS	0x66
#define RC5T583_REG_LDO3DAC_DS	0x67
#define RC5T583_REG_LDO4DAC_DS	0x68
#define RC5T583_REG_LDO5DAC_DS	0x69
#define RC5T583_REG_LDO6DAC_DS	0x6A
#define RC5T583_REG_LDO7DAC_DS	0x6B
#define RC5T583_REG_LDO8DAC_DS	0x6C
#define RC5T583_REG_LDO9DAC_DS	0x6D

/*                            */
#define RC5T583_GPIO_IOSEL	0xA0
#define RC5T583_GPIO_PDEN	0xA1
#define RC5T583_GPIO_IOOUT	0xA2
#define RC5T583_GPIO_PGSEL	0xA3
#define RC5T583_GPIO_GPINV	0xA4
#define RC5T583_GPIO_GPDEB	0xA5
#define RC5T583_GPIO_GPEDGE1	0xA6
#define RC5T583_GPIO_GPEDGE2	0xA7
#define RC5T583_GPIO_EN_INT	0xA8
#define RC5T583_GPIO_MON_IOIN	0xAB
#define RC5T583_GPIO_GPOFUNC	0xAC

/*                               */
enum {
	RC5T583_IRQ_ONKEY,
	RC5T583_IRQ_ACOK,
	RC5T583_IRQ_LIDOPEN,
	RC5T583_IRQ_PREOT,
	RC5T583_IRQ_CLKSTP,
	RC5T583_IRQ_ONKEY_OFF,
	RC5T583_IRQ_WD,
	RC5T583_IRQ_EN_PWRREQ1,
	RC5T583_IRQ_EN_PWRREQ2,
	RC5T583_IRQ_PRE_VINDET,

	RC5T583_IRQ_DC0LIM,
	RC5T583_IRQ_DC1LIM,
	RC5T583_IRQ_DC2LIM,
	RC5T583_IRQ_DC3LIM,

	RC5T583_IRQ_CTC,
	RC5T583_IRQ_YALE,
	RC5T583_IRQ_DALE,
	RC5T583_IRQ_WALE,

	RC5T583_IRQ_AIN1L,
	RC5T583_IRQ_AIN2L,
	RC5T583_IRQ_AIN3L,
	RC5T583_IRQ_VBATL,
	RC5T583_IRQ_VIN3L,
	RC5T583_IRQ_VIN8L,
	RC5T583_IRQ_AIN1H,
	RC5T583_IRQ_AIN2H,
	RC5T583_IRQ_AIN3H,
	RC5T583_IRQ_VBATH,
	RC5T583_IRQ_VIN3H,
	RC5T583_IRQ_VIN8H,
	RC5T583_IRQ_ADCEND,

	RC5T583_IRQ_GPIO0,
	RC5T583_IRQ_GPIO1,
	RC5T583_IRQ_GPIO2,
	RC5T583_IRQ_GPIO3,
	RC5T583_IRQ_GPIO4,
	RC5T583_IRQ_GPIO5,
	RC5T583_IRQ_GPIO6,
	RC5T583_IRQ_GPIO7,

	/*                      */
	RC5T583_MAX_IRQS,
};

/*                           */
enum {
	RC5T583_GPIO0,
	RC5T583_GPIO1,
	RC5T583_GPIO2,
	RC5T583_GPIO3,
	RC5T583_GPIO4,
	RC5T583_GPIO5,
	RC5T583_GPIO6,
	RC5T583_GPIO7,

	/*                      */
	RC5T583_MAX_GPIO,
};

enum {
	RC5T583_DS_NONE,
	RC5T583_DS_DC0,
	RC5T583_DS_DC1,
	RC5T583_DS_DC2,
	RC5T583_DS_DC3,
	RC5T583_DS_LDO0,
	RC5T583_DS_LDO1,
	RC5T583_DS_LDO2,
	RC5T583_DS_LDO3,
	RC5T583_DS_LDO4,
	RC5T583_DS_LDO5,
	RC5T583_DS_LDO6,
	RC5T583_DS_LDO7,
	RC5T583_DS_LDO8,
	RC5T583_DS_LDO9,
	RC5T583_DS_PSO0,
	RC5T583_DS_PSO1,
	RC5T583_DS_PSO2,
	RC5T583_DS_PSO3,
	RC5T583_DS_PSO4,
	RC5T583_DS_PSO5,
	RC5T583_DS_PSO6,
	RC5T583_DS_PSO7,

	/*                      */
	RC5T583_DS_MAX,
};

/*
                                                                   
                                                                  
                         
 */
enum {
	RC5T583_EXT_PWRREQ1_CONTROL = 0x1,
	RC5T583_EXT_PWRREQ2_CONTROL = 0x2,
};

struct rc5t583 {
	struct device	*dev;
	struct regmap	*regmap;
	int		chip_irq;
	int		irq_base;
	struct mutex	irq_lock;
	unsigned long	group_irq_en[MAX_MAIN_INTERRUPT];

	/*                                 */
	uint8_t		intc_inten_reg;

	/*                                      */
	uint8_t		irq_en_reg[RC5T583_MAX_INTERRUPT_MASK_REGS];

	/*               */
	uint8_t		gpedge_reg[RC5T583_MAX_GPEDGE_REG];
};

/*
                                                              
                                                              
                                                                              
                                                                      
 */

struct rc5t583_platform_data {
	int		irq_base;
	bool		enable_shutdown;
};

static inline int rc5t583_write(struct device *dev, uint8_t reg, uint8_t val)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev);
	return regmap_write(rc5t583->regmap, reg, val);
}

static inline int rc5t583_read(struct device *dev, uint8_t reg, uint8_t *val)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev);
	unsigned int ival;
	int ret;
	ret = regmap_read(rc5t583->regmap, reg, &ival);
	if (!ret)
		*val = (uint8_t)ival;
	return ret;
}

static inline int rc5t583_set_bits(struct device *dev, unsigned int reg,
			unsigned int bit_mask)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev);
	return regmap_update_bits(rc5t583->regmap, reg, bit_mask, bit_mask);
}

static inline int rc5t583_clear_bits(struct device *dev, unsigned int reg,
			unsigned int bit_mask)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev);
	return regmap_update_bits(rc5t583->regmap, reg, bit_mask, 0);
}

static inline int rc5t583_update(struct device *dev, unsigned int reg,
		unsigned int val, unsigned int mask)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(dev);
	return regmap_update_bits(rc5t583->regmap, reg, mask, val);
}

int rc5t583_ext_power_req_config(struct device *dev, int deepsleep_id,
	int ext_pwr_req, int deepsleep_slot_nr);
int rc5t583_irq_init(struct rc5t583 *rc5t583, int irq, int irq_base);
int rc5t583_irq_exit(struct rc5t583 *rc5t583);

#endif