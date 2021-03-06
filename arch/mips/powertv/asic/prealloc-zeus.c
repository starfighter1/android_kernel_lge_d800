/*
 * Memory pre-allocations for Zeus boxes.
 *
 * Copyright (C) 2005-2009 Scientific-Atlanta, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Author:       Ken Eppinett
 *               David Schleef <ds@schleef.org>
 */

#include <linux/init.h>
#include <linux/ioport.h>
#include <asm/mach-powertv/asic.h>
#include "prealloc.h"

/*
                        
 */
struct resource dvr_zeus_resources[] __initdata =
{
	/*
                
  */
	/*                         */
	PREALLOC_NORMAL("ST231aImage", 0x20000000, 0x20200000-1,
		IORESOURCE_MEM)
	/*                           */
	PREALLOC_NORMAL("ST231aMonitor", 0x20200000, 0x20202000-1,
		IORESOURCE_MEM)
	/*                                                   */
	PREALLOC_NORMAL("MediaMemory1", 0x20202000, 0x22000000-1,
		IORESOURCE_MEM)

	/*
                
  */
	/*                         */
	PREALLOC_NORMAL("ST231bImage", 0x30000000, 0x30200000-1,
		IORESOURCE_MEM)
	/*                           */
	PREALLOC_NORMAL("ST231bMonitor", 0x30200000, 0x30202000-1,
		IORESOURCE_MEM)
	/*                                                   */
	PREALLOC_NORMAL("MediaMemory2", 0x30202000, 0x32000000-1,
		IORESOURCE_MEM)

	/*
                   
  */
	/*                                 */
	PREALLOC_NORMAL("DSP_Image_Buff", 0x00000000, 0x00100000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))
	/*                             */
	PREALLOC_NORMAL("ADSC_CPU_PCM_Buff", 0x00000000, 0x0000A000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))
	/*                         */
	PREALLOC_NORMAL("ADSC_AUX_Buff", 0x00000000, 0x00004000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))
	/*                          */
	PREALLOC_NORMAL("ADSC_Main_Buff", 0x00000000, 0x00004000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                       
   
                                                                       
                                                                      
                                                                 
                                                                   
                                                             
  */
	/*       */
	PREALLOC_NORMAL("AVMEMPartition0", 0x00000000, 0x00c00000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                    
  */
	/*      */
	PREALLOC_DOCSIS("Docsis", 0x40100000, 0x40800000-1, IORESOURCE_MEM)

	/*
                  
  */
	/*                               */
	PREALLOC_NORMAL("GraphicsHeap", 0x46900000, 0x47700000-1,
		IORESOURCE_MEM)

	/*
                         
  */
	/*        */
	PREALLOC_NORMAL("MulticomSHM", 0x47900000, 0x47920000-1,
		IORESOURCE_MEM)

	/*
                   
  */
	/*        */
	PREALLOC_NORMAL("BMM_Buffer", 0x00000000, 0x00280000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                                 
  */
	/*      */
	PREALLOC_NORMAL("DisplayBins0", 0x00000000, 0x00001000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                                 
  */
	/*      */
	PREALLOC_NORMAL("DisplayBins1", 0x00000000, 0x00001000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
        
  */
	/*                                           */
	PREALLOC_NORMAL("ITFS", 0x00000000, 0x0018E000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
        
  */
	/*                                                */
	PREALLOC_NORMAL("AvfsDmaMem", 0x00000000, 0x007c2000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))
	/*      */
	PREALLOC_NORMAL("AvfsFileSys", 0x00000000, 0x00001000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
        
  */
	/*                                           */
	PREALLOC_PMEM("DiagPersistentMemory", 0x00000000, 0x10000-1,
	     (IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
             
  */
	/*                                                            */
	PREALLOC_NORMAL("SmartCardInfo", 0x00000000, 0x2800-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
              
   
                                                                     
                                        
  */
	PREALLOC_TFTP("TFTPBuffer", 0x00000000, MEBIBYTE(80)-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                            
  */

	/*
                          
  */
	{
		.flags  = 0,
	},
};

/*
                                 
 */
struct resource non_dvr_zeus_resources[] __initdata =
{
	/*
                
  */
	/*                         */
	PREALLOC_NORMAL("ST231aImage", 0x20000000, 0x20200000-1,
		IORESOURCE_MEM)
	/*                           */
	PREALLOC_NORMAL("ST231aMonitor", 0x20200000, 0x20202000-1,
		IORESOURCE_MEM)
	/*                                                   */
	PREALLOC_NORMAL("MediaMemory1", 0x20202000, 0x22000000-1,
		IORESOURCE_MEM)

	/*
                   
  */
	/*                                 */
	PREALLOC_NORMAL("DSP_Image_Buff", 0x00000000, 0x00100000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))
	/*                             */
	PREALLOC_NORMAL("ADSC_CPU_PCM_Buff", 0x00000000, 0x0000A000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))
	/*                         */
	PREALLOC_NORMAL("ADSC_AUX_Buff", 0x00000000, 0x00004000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))
	/*                          */
	PREALLOC_NORMAL("ADSC_Main_Buff", 0x00000000, 0x00004000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                       
  */
	/*      */
	PREALLOC_NORMAL("AVMEMPartition0", 0x00000000, 0x00600000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                    
  */
	/*      */
	PREALLOC_DOCSIS("Docsis", 0x40100000, 0x40800000-1, IORESOURCE_MEM)

	/*
                  
  */
	/*                               */
	PREALLOC_NORMAL("GraphicsHeap", 0x46900000, 0x47700000-1,
		IORESOURCE_MEM)

	/*
                         
  */
	/*        */
	PREALLOC_NORMAL("MulticomSHM", 0x47900000, 0x47920000-1,
		IORESOURCE_MEM)

	/*
                   
  */
	/*        */
	PREALLOC_NORMAL("BMM_Buffer", 0x00000000, 0x00280000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                                 
  */
	/*      */
	PREALLOC_NORMAL("DisplayBins0", 0x00000000, 0x00001000-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                           
  */
	/*                       */
	PREALLOC_NORMAL("AvfsDmaMem", 0x00000000, 0x002c4c00-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
        
  */
	/*                                           */
	PREALLOC_PMEM("DiagPersistentMemory", 0x00000000, 0x10000-1,
	     (IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
             
  */
	/*                                                            */
	PREALLOC_NORMAL("SmartCardInfo", 0x00000000, 0x2800-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
              
  */
	/*       */
	PREALLOC_NORMAL("NandFlash", NAND_FLASH_BASE, NAND_FLASH_BASE+0x400-1,
		IORESOURCE_MEM)

	/*
              
   
                                                                     
                                        
  */
	PREALLOC_TFTP("TFTPBuffer", 0x00000000, MEBIBYTE(80)-1,
		(IORESOURCE_MEM|IORESOURCE_PTV_RES_LOEXT))

	/*
                            
  */

	/*
                          
  */
	{
		.flags  = 0,
	},
};
