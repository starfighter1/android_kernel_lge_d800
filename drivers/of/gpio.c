/*
 * OF helpers for the GPIO API
 *
 * Copyright (c) 2007-2008  MontaVista Software, Inc.
 *
 * Author: Anton Vorontsov <avorontsov@ru.mvista.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/device.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/slab.h>

/* 
                                                                               
                                     
                                                        
                            
                                     
  
                                                                              
                                                                              
                         
 */
int of_get_named_gpio_flags(struct device_node *np, const char *propname,
                           int index, enum of_gpio_flags *flags)
{
	int ret;
	struct gpio_chip *gc;
	struct of_phandle_args gpiospec;

	ret = of_parse_phandle_with_args(np, propname, "#gpio-cells", index,
					 &gpiospec);
	if (ret) {
		pr_debug("%s: can't parse gpios property\n", __func__);
		goto err0;
	}

	gc = of_node_to_gpiochip(gpiospec.np);
	if (!gc) {
		pr_debug("%s: gpio controller %s isn't registered\n",
			 np->full_name, gpiospec.np->full_name);
		ret = -EPROBE_DEFER;
		goto err1;
	}

	if (gpiospec.args_count != gc->of_gpio_n_cells) {
		pr_debug("%s: wrong #gpio-cells for %s\n",
			 np->full_name, gpiospec.np->full_name);
		ret = -EINVAL;
		goto err1;
	}

	/*                                                            */
	if (flags)
		*flags = 0;

	ret = gc->of_xlate(gc, &gpiospec, flags);
	if (ret < 0)
		goto err1;

	ret += gc->base;
err1:
	of_node_put(gpiospec.np);
err0:
	pr_debug("%s exited with status %d\n", __func__, ret);
	return ret;
}
EXPORT_SYMBOL(of_get_named_gpio_flags);

/* 
                                                 
                                       
                                                        
  
                                                                
  
                                                               
  
             
                     
             
                       
  
                                                                    
                     
 */
unsigned int of_gpio_named_count(struct device_node *np, const char* propname)
{
	unsigned int cnt = 0;

	do {
		int ret;

		ret = of_parse_phandle_with_args(np, propname, "#gpio-cells",
						 cnt, NULL);
		/*                                         */
		if (ret < 0 && ret != -EEXIST)
			break;
	} while (++cnt);

	return cnt;
}
EXPORT_SYMBOL(of_gpio_named_count);

/* 
                                                                          
                                           
                                     
                                                         
                                     
  
                                                                        
                                                                         
                                                            
 */
int of_gpio_simple_xlate(struct gpio_chip *gc,
			 const struct of_phandle_args *gpiospec, u32 *flags)
{
	/*
                                                                    
                                                                     
                                                                     
                         
  */
	if (gc->of_gpio_n_cells < 2) {
		WARN_ON(1);
		return -EINVAL;
	}

	if (WARN_ON(gpiospec->args_count < gc->of_gpio_n_cells))
		return -EINVAL;

	if (gpiospec->args[0] >= gc->ngpio)
		return -EINVAL;

	if (flags)
		*flags = gpiospec->args[1];

	return gpiospec->args[0];
}
EXPORT_SYMBOL(of_gpio_simple_xlate);

/* 
                                                          
                                     
                                                             
  
                                                                
  
                                 
                         
                       
                                    
  
                                       
                                     
  
                                                              
                                                               
                                      
 */
int of_mm_gpiochip_add(struct device_node *np,
		       struct of_mm_gpio_chip *mm_gc)
{
	int ret = -ENOMEM;
	struct gpio_chip *gc = &mm_gc->gc;

	gc->label = kstrdup(np->full_name, GFP_KERNEL);
	if (!gc->label)
		goto err0;

	mm_gc->regs = of_iomap(np, 0);
	if (!mm_gc->regs)
		goto err1;

	gc->base = -1;

	if (mm_gc->save_regs)
		mm_gc->save_regs(mm_gc);

	mm_gc->gc.of_node = np;

	ret = gpiochip_add(gc);
	if (ret)
		goto err2;

	return 0;
err2:
	iounmap(mm_gc->regs);
err1:
	kfree(gc->label);
err0:
	pr_err("%s: GPIO chip registration failed with status %d\n",
	       np->full_name, ret);
	return ret;
}
EXPORT_SYMBOL(of_mm_gpiochip_add);

void of_gpiochip_add(struct gpio_chip *chip)
{
	if ((!chip->of_node) && (chip->dev))
		chip->of_node = chip->dev->of_node;

	if (!chip->of_node)
		return;

	if (!chip->of_xlate) {
		chip->of_gpio_n_cells = 2;
		chip->of_xlate = of_gpio_simple_xlate;
	}

	of_node_get(chip->of_node);
}

void of_gpiochip_remove(struct gpio_chip *chip)
{
	if (chip->of_node)
		of_node_put(chip->of_node);
}

/*                                                          */
static int of_gpiochip_is_match(struct gpio_chip *chip, const void *data)
{
	return chip->of_node == data;
}

struct gpio_chip *of_node_to_gpiochip(struct device_node *np)
{
	return gpiochip_find(np, of_gpiochip_is_match);
}
