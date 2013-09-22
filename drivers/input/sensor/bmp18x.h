/*  Copyright (c) 2010  Christoph Mair <christoph.mair@gmail.com>
    Copyright (c) 2011  Bosch Sensortec GmbH
    Copyright (c) 2011  Unixphere AB

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#ifndef _BMP18X_H
#define _BMP18X_H

#define BMP18X_NAME "bmp18x"

/* 
                                                                               
                                                                
                                                                           
                                              
                                                                               
                     
                                             
                                                
 */
struct bmp18x_platform_data {
	u8	chip_id;
	u8	default_oversampling;
	u32	temp_measurement_period;
	int	(*init_hw)(struct bmp18x_platform_data *pdata);
	int	(*deinit_hw)(struct bmp18x_platform_data *pdata);
#ifdef CONFIG_OF
	struct regulator *vdd_ana;
	struct regulator *vdd_i2c;
#endif
};

struct bmp18x_bus_ops {
	int	(*read_block)(void *client, u8 reg, int len, char *buf);
	int	(*read_byte)(void *client, u8 reg);
	int	(*write_byte)(void *client, u8 reg, u8 value);
};

struct bmp18x_data_bus {
	const struct bmp18x_bus_ops	*bops;
	void	*client;
};

int bmp18x_probe(struct device *dev, struct bmp18x_data_bus *data_bus);
int bmp18x_remove(struct device *dev);
#ifdef CONFIG_PM
int bmp18x_enable(struct device *dev);
int bmp18x_disable(struct device *dev);
#endif

#endif
