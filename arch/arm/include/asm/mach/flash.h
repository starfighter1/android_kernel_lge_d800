/*
 *  arch/arm/include/asm/mach/flash.h
 *
 *  Copyright (C) 2003 Russell King, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef ASMARM_MACH_FLASH_H
#define ASMARM_MACH_FLASH_H

struct mtd_partition;
struct mtd_info;

enum sw_version {
	VERSION_1 = 0,
	VERSION_2,
};

/*
                                        
                                                       
                                
                                               
                                                      
                                               
                                                  
                                                                            
                                                                  
                                                            
                                               
 */
struct flash_platform_data {
	const char	*map_name;
	const char	*name;
	unsigned int	width;
	unsigned int    interleave;
	int		(*init)(void);
	void		(*exit)(void);
	void		(*set_vpp)(int on);
	void		(*mmcontrol)(struct mtd_info *mtd, int sync_read);
	struct mtd_partition *parts;
	unsigned int	nr_parts;
	enum sw_version	version;
};

#endif
