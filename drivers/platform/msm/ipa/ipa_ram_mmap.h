/* Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _IPA_RAM_MMAP_H_
#define _IPA_RAM_MMAP_H_

/*
                                                                             
              
 */

#define IPA_RAM_NAT_OFST    0
#define IPA_RAM_NAT_SIZE    0
#define IPA_RAM_HDR_OFST    (IPA_RAM_NAT_OFST + IPA_RAM_NAT_SIZE)
#define IPA_RAM_HDR_SIZE    1280
#define IPA_RAM_V4_FLT_OFST (IPA_RAM_HDR_OFST + IPA_RAM_HDR_SIZE)
#define IPA_RAM_V4_FLT_SIZE 1408
#define IPA_RAM_V4_RT_OFST  (IPA_RAM_V4_FLT_OFST + IPA_RAM_V4_FLT_SIZE)
#define IPA_RAM_V4_RT_SIZE  2176
#define IPA_RAM_V6_FLT_OFST (IPA_RAM_V4_RT_OFST + IPA_RAM_V4_RT_SIZE)
#define IPA_RAM_V6_FLT_SIZE 1280
#define IPA_RAM_V6_RT_OFST  (IPA_RAM_V6_FLT_OFST + IPA_RAM_V6_FLT_SIZE)
#define IPA_RAM_V6_RT_SIZE  512
#define IPA_RAM_END_OFST    (IPA_RAM_V6_RT_OFST + IPA_RAM_V6_RT_SIZE)
#define IPA_RAM_V6_RT_SIZE_DDR 16384

#endif /*                  */
