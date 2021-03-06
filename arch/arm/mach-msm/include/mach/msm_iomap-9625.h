/*
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ASM_ARCH_MSM_IOMAP_MSM9625_H
#define __ASM_ARCH_MSM_IOMAP_MSM9625_H

/*                                               
                                                                
  
                                                             
                                                          
           
  
 */

#define MSM9625_SHARED_RAM_PHYS	0x00000000

#define MSM9625_QGIC_DIST_PHYS	0xF9000000
#define MSM9625_QGIC_DIST_SIZE	SZ_4K

#define MSM9625_TMR_PHYS	0xF9021000
#define MSM9625_TMR_SIZE	SZ_4K

#define MSM9625_TLMM_PHYS	0xFD510000
#define MSM9625_TLMM_SIZE	SZ_16K

#define MSM9625_MPM2_PSHOLD_PHYS	0xFC4AB000
#define MSM9625_MPM2_PSHOLD_SIZE	SZ_4K

#ifdef CONFIG_DEBUG_MSM9625_UART
#define MSM_DEBUG_UART_BASE	IOMEM(0xFA71F000)
#define MSM_DEBUG_UART_PHYS	0xF991F000
#endif

#endif
