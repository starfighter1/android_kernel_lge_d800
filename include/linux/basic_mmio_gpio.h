/*
 * Basic memory-mapped GPIO controllers.
 *
 * Copyright 2008 MontaVista Software, Inc.
 * Copyright 2008,2010 Anton Vorontsov <cbouatmailru@gmail.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

#ifndef __BASIC_MMIO_GPIO_H
#define __BASIC_MMIO_GPIO_H

#include <linux/gpio.h>
#include <linux/types.h>
#include <linux/compiler.h>
#include <linux/spinlock_types.h>

struct bgpio_pdata {
	int base;
	int ngpio;
};

struct device;

struct bgpio_chip {
	struct gpio_chip gc;

	unsigned long (*read_reg)(void __iomem *reg);
	void (*write_reg)(void __iomem *reg, unsigned long data);

	void __iomem *reg_dat;
	void __iomem *reg_set;
	void __iomem *reg_clr;
	void __iomem *reg_dir;

	/*                                               */
	int bits;

	/*
                                                                 
                                                                  
  */
	unsigned long (*pin2mask)(struct bgpio_chip *bgc, unsigned int pin);

	/*
                                                               
                                                     
  */
	spinlock_t lock;

	/*                                                  */
	unsigned long data;

	/*                                                             */
	unsigned long dir;
};

static inline struct bgpio_chip *to_bgpio_chip(struct gpio_chip *gc)
{
	return container_of(gc, struct bgpio_chip, gc);
}

int bgpio_remove(struct bgpio_chip *bgc);
int bgpio_init(struct bgpio_chip *bgc, struct device *dev,
	       unsigned long sz, void __iomem *dat, void __iomem *set,
	       void __iomem *clr, void __iomem *dirout, void __iomem *dirin,
	       bool big_endian);

#endif /*                     */
