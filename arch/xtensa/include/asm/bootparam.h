/*
 * include/asm-xtensa/bootparam.h
 *
 * Definition of the Linux/Xtensa boot parameter structure
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2001 - 2005  Tensilica Inc.
 *
 * (Concept borrowed from the 68K port)
 */

#ifndef _XTENSA_BOOTPARAM_H
#define _XTENSA_BOOTPARAM_H

#define BP_VERSION 0x0001

#define BP_TAG_COMMAND_LINE	0x1001	/*                                   */
#define BP_TAG_INITRD		0x1002	/*                                    */
#define BP_TAG_MEMORY		0x1003	/*                                   */
#define BP_TAG_SERIAL_BAUSRATE	0x1004	/*                               */
#define BP_TAG_SERIAL_PORT	0x1005	/*                                  */

#define BP_TAG_FIRST		0x7B0B  /*                                 */
#define BP_TAG_LAST 		0x7E0B	/*          */

#ifndef __ASSEMBLY__

/*                                    */

typedef struct bp_tag {
  unsigned short id;		/*        */
  unsigned short size;		/*                                            */
  unsigned long data[0];	/*      */
} bp_tag_t;

typedef struct meminfo {
  unsigned long type;
  unsigned long start;
  unsigned long end;
} meminfo_t;

#define SYSMEM_BANKS_MAX 5

#define MEMORY_TYPE_CONVENTIONAL	0x1000
#define MEMORY_TYPE_NONE		0x2000

typedef struct sysmem_info {
  int nr_banks;
  meminfo_t bank[SYSMEM_BANKS_MAX];
} sysmem_info_t;

extern sysmem_info_t sysmem;

#endif
#endif


