/*
 * linux/drivers/video/platinumfb-hw.c -- Frame buffer device for the
 * Platinum on-board video in PowerMac 7200s (and some clones based
 * on the same motherboard.)
 *
 *  Created 09 Feb 1998 by Jon Howell <jonh@cs.dartmouth.edu>
 *
 * Copyright (C) 1998 Jon Howell
 *
 *  based on drivers/macintosh/platinum.c: Console support
 * 	for PowerMac "platinum" display adaptor.
 *  Copyright (C) 1996 Paul Mackerras and Mark Abene.
 *
 *  based on skeletonfb.c:
 *  Created 28 Dec 1997 by Geert Uytterhoeven
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file COPYING in the main directory of this archive
 * for more details.
 */

/*
                                                             
 */
struct cmap_regs {
	unsigned char addr;
	char pad1[15];
	unsigned char d1;
	char pad2[15];
	unsigned char d2;
	char pad3[15];
	unsigned char lut;
	char pad4[15];
};

/*
                                                                  
 */
struct preg {			/*                 */
	unsigned r;			/*                         */
	char pad[12];
};

struct platinum_regs {
	struct preg reg[128];
};

/*
                                                           
  
                                                                  
                                                                  
                                                  
                                                    
                                                                  
              
                                                        
 */
struct platinum_regvals {
	int	fb_offset;
	int	pitch[3];
	unsigned regs[26];
	unsigned char offset[3];
	unsigned char mode[3];
	unsigned char dacula_ctrl[3];
	unsigned char clock_params[2][2];
};

#define DIV2	0x20
#define DIV4	0x40
#define DIV8	0x60
#define DIV16	0x80

/*                      */
static struct platinum_regvals platinum_reg_init_20 = {
	0x5c00,
	{ 1312, 2592, 2592 },
	{ 0xffc, 4, 0, 0, 0, 0, 0x428, 0,
	  0, 0xb3, 0xd3, 0x12, 0x1a5, 0x23, 0x28, 0x2d,
	  0x5e, 0x19e, 0x1a4, 0x854, 0x852, 4, 9, 0x50,
	  0x850, 0x851 }, { 0x58, 0x5d, 0x5d },
	{ 0, 0xff, 0xff }, { 0x51, 0x55, 0x55 },
	{{ 45, 3 }, { 66, 7 }}
};

/*                     */
static struct platinum_regvals platinum_reg_init_19 = {
	0x5c00,
	{ 1312, 2592, 2592 },
	{ 0xffc, 4, 0, 0, 0, 0, 0x428, 0,
	  0, 0xb2, 0xd2, 0x12, 0x1a3, 0x23, 0x28, 0x2d,
	  0x5c, 0x19c, 0x1a2, 0x7d0, 0x7ce, 4, 9, 0x4c,
	  0x7cc, 0x7cd }, { 0x56, 0x5b, 0x5b },
	{ 0, 0xff, 0xff }, { 0x51, 0x55, 0x55 },
	{{ 42, 3 }, { 44, 5 }}
};

/*                     */
static struct platinum_regvals platinum_reg_init_18 = {
	0x11b0,
	{ 1184, 2336, 4640 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x38f, 0,
	  0, 0x294, 0x16c, 0x20, 0x2d7, 0x3f, 0x49, 0x53,
	  0x82, 0x2c2, 0x2d6, 0x726, 0x724, 4, 9, 0x52,
	  0x71e, 0x722 }, { 0x74, 0x7c, 0x81 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 26, 0 + DIV2 }, { 42, 6 }}
};

/*                     */
static struct platinum_regvals platinum_reg_init_17 = {
	0x10b0,
	{ 1056, 2080, 4128 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x254, 0x14b, 0x18, 0x295, 0x2f, 0x32, 0x3b,
	  0x80, 0x280, 0x296, 0x648, 0x646, 4, 9, 0x40,
	  0x640, 0x644 }, { 0x72, 0x7a, 0x7f },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 54, 3 + DIV2 }, { 67, 12 }}
};

/*                     */
static struct platinum_regvals platinum_reg_init_16 = {
	0x10b0,
	{ 1056, 2080, 4128 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x250, 0x147, 0x17, 0x28f, 0x2f, 0x35, 0x47,
	  0x82, 0x282, 0x28e, 0x640, 0x63e, 4, 9, 0x3c,
	  0x63c, 0x63d }, { 0x74, 0x7c, 0x81 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 20, 0 + DIV2 }, { 11, 2 }}
};

/*                     */
static struct platinum_regvals platinum_reg_init_15 = {
	0x10b0,
	{ 1056, 2080, 4128 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x254, 0x14b, 0x22, 0x297, 0x43, 0x49, 0x5b,
	  0x86, 0x286, 0x296, 0x64c, 0x64a, 0xa, 0xf, 0x44,
	  0x644, 0x646 }, { 0x78, 0x80, 0x85 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 19, 0 + DIV2 }, { 110, 21 }}
};

/*                     */
static struct platinum_regvals platinum_reg_init_14 = {
	0x10b0,
	{ 1056, 2080, 4128 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x25a, 0x14f, 0x22, 0x29f, 0x43, 0x49, 0x5b,
	  0x8e, 0x28e, 0x29e, 0x64c, 0x64a, 0xa, 0xf, 0x44,
	  0x644, 0x646 }, { 0x80, 0x88, 0x8d },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 71, 6 + DIV2 }, { 118, 13 + DIV2 }}
};

/*                    */
static struct platinum_regvals platinum_reg_init_13 = {
	0x70,
	{ 864, 1680, 3344 },	/*                                                     
                                                    
     */
	{ 0xff0, 4, 0, 0, 0, 0, 0x299, 0,
	  0, 0x21e, 0x120, 0x10, 0x23f, 0x1f, 0x25, 0x37,
	  0x8a, 0x22a, 0x23e, 0x536, 0x534, 4, 9, 0x52,
	  0x532, 0x533 }, { 0x7c, 0x84, 0x89 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 30, 0 + DIV4 }, { 56, 7 + DIV2 }}
};

/*                    */
static struct platinum_regvals platinum_reg_init_12 = {
	0x1010,
	{ 832, 1632, 3232 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x1ce, 0x108, 0x14, 0x20f, 0x27, 0x30, 0x39,
	  0x72, 0x202, 0x20e, 0x4e2, 0x4e0, 4, 9, 0x2e,
	  0x4de, 0x4df }, { 0x64, 0x6c, 0x71 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 122, 7 + DIV4 }, { 62, 9 + DIV2 }}
};

/*                    */
static struct platinum_regvals platinum_reg_init_11 = {
	0x1010,
	{ 832, 1632, 3232 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x1ca, 0x104, 0x1e, 0x207, 0x3b, 0x44, 0x4d,
	  0x56, 0x1e6, 0x206, 0x534, 0x532, 0xa, 0xe, 0x38,
	  0x4e8, 0x4ec }, { 0x48, 0x50, 0x55 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 26, 0 + DIV4 }, { 42, 6 + DIV2 }}
};

/*                    */
static struct platinum_regvals platinum_reg_init_10 = {
	0x1010,
	{ 832, 1632, 3232 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x1ce, 0x108, 0x20, 0x20f, 0x3f, 0x45, 0x5d,
	  0x66, 0x1f6, 0x20e, 0x4e8, 0x4e6, 6, 0xa, 0x34,
	  0x4e4, 0x4e5 }, { 0x58, 0x60, 0x65 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 54, 3 + DIV4 }, { 95, 1 + DIV8 }}
};

/*                                                             */
static struct platinum_regvals platinum_reg_init_9 = {
	0x1010,
	{ 832, 1632, 3232 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x1ce, 0x108, 0x20, 0x20f, 0x3f, 0x45, 0x5d,
	  0x66, 0x1f6, 0x20e, 0x4e8, 0x4e6, 6, 0xa, 0x34,
	  0x4e4, 0x4e5 }, { 0x58, 0x60, 0x65 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 54, 3 + DIV4 }, { 88, 1 + DIV8 }}
};

/*                                  */
static struct platinum_regvals platinum_reg_init_8 = {
	0x1010,
	{ 800, 1568, 3104 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0xc8, 0xec, 0x11, 0x1d7, 0x22, 0x25, 0x36,
	  0x47, 0x1c7, 0x1d6, 0x271, 0x270, 4, 9, 0x27,
	  0x267, 0x26b }, { 0x39, 0x41, 0x46 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 31, 0 + DIV16 }, { 74, 9 + DIV8 }}
};

/*                            */
static struct platinum_regvals platinum_reg_init_7 = {
	0xb10,
	{ 672, 1312, 2592 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x176, 0xd0, 0x14, 0x19f, 0x27, 0x2d, 0x3f,
	  0x4a, 0x18a, 0x19e, 0x72c, 0x72a, 4, 9, 0x58,
	  0x724, 0x72a }, { 0x3c, 0x44, 0x49 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 30, 0 + DIV4 }, { 56, 7 + DIV2 }}
};

/*                   */
static struct platinum_regvals platinum_reg_init_6 = {
	0x1010,
	{ 672, 1312, 2592 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x209, 0,
	  0, 0x18e, 0xd8, 0x10, 0x1af, 0x1f, 0x25, 0x37,
	  0x4a, 0x18a, 0x1ae, 0x41a, 0x418, 4, 9, 0x52,
	  0x412, 0x416 }, { 0x3c, 0x44, 0x49 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 99, 4 + DIV8 }, { 42, 5 + DIV4 }}
};

/*                   */
static struct platinum_regvals platinum_reg_init_5 = {
	0x1010,
	{ 672, 1312, 2592 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x15e, 0xc8, 0x18, 0x18f, 0x2f, 0x35, 0x3e,
	  0x42, 0x182, 0x18e, 0x41a, 0x418, 2, 7, 0x44,
	  0x404, 0x408 }, { 0x34, 0x3c, 0x41 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 26, 0 + DIV8 }, { 14, 2 + DIV4 }}
};

/*                                   */
static struct platinum_regvals platinum_reg_init_4 = {
	0x1010,
	{ 672, 1312, 2592 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0xa5, 0xc3, 0xe, 0x185, 0x1c, 0x1f, 0x30,
	  0x37, 0x177, 0x184, 0x20d, 0x20c, 5, 0xb, 0x23,
	  0x203, 0x206 }, { 0x29, 0x31, 0x36 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 94, 5 + DIV16 }, { 48, 7 + DIV8 }}
};

/*                                  */
static struct platinum_regvals platinum_reg_init_3 = {
	0x1010,
	{ 672, 1312, 2592 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0xc8, 0xec, 0x11, 0x1d7, 0x22, 0x25, 0x36,
	  0x67, 0x1a7, 0x1d6, 0x271, 0x270, 4, 9, 0x57,
	  0x237, 0x26b }, { 0x59, 0x61, 0x66 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 31, 0 + DIV16 }, { 74, 9 + DIV8 }}
};

/*                   */
static struct platinum_regvals platinum_reg_init_2 = {
	0x1010,
	{ 544, 1056, 2080 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0x25c, 0x140, 0x10, 0x27f, 0x1f, 0x2b, 0x4f,
	  0x68, 0x268, 0x27e, 0x32e, 0x32c, 4, 9, 0x2a,
	  0x32a, 0x32b }, { 0x5a, 0x62, 0x67 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 33, 2 + DIV8 }, { 79, 9 + DIV8 }}
};

/*                                   */
static struct platinum_regvals platinum_reg_init_1 = {
	0x1010,
	{ 544, 1056, 2080 },
	{ 0xff0, 4, 0, 0, 0, 0, 0x320, 0,
	  0, 0xa5, 0xc3, 0xe, 0x185, 0x1c, 0x1f, 0x30,
	  0x57, 0x157, 0x184, 0x20d, 0x20c, 5, 0xb, 0x53,
	  0x1d3, 0x206 }, { 0x49, 0x51, 0x56 },
	{ 2, 0, 0xff }, { 0x11, 0x15, 0x19 },
	{{ 94, 5 + DIV16 }, { 48, 7 + DIV8 }}
};

static struct platinum_regvals *platinum_reg_init[VMODE_MAX] = {
	&platinum_reg_init_1,
	&platinum_reg_init_2,
	&platinum_reg_init_3,
	&platinum_reg_init_4,
	&platinum_reg_init_5,
	&platinum_reg_init_6,
	&platinum_reg_init_7,
	&platinum_reg_init_8,
	&platinum_reg_init_9,
	&platinum_reg_init_10,
	&platinum_reg_init_11,
	&platinum_reg_init_12,
	&platinum_reg_init_13,
	&platinum_reg_init_14,
	&platinum_reg_init_15,
	&platinum_reg_init_16,
	&platinum_reg_init_17,
	&platinum_reg_init_18,
	&platinum_reg_init_19,
	&platinum_reg_init_20
};

struct vmode_attr {
	int hres;
	int vres;
	int vfreq;
	int interlaced;
};

struct vmode_attr vmode_attrs[VMODE_MAX] = {
	{512, 384, 60, 1},
	{512, 384, 60},
	{640, 480, 50, 1},
	{640, 480, 60, 1},
	{640, 480, 60},
	{640, 480, 67},
	{640, 870, 75},
	{768, 576, 50, 1},
	{800, 600, 56},
	{800, 600, 60},
	{800, 600, 72},
	{800, 600, 75},
	{832, 624, 75},
	{1024, 768, 60},
	{1024, 768, 72},
	{1024, 768, 75},
	{1024, 768, 75},
	{1152, 870, 75},
	{1280, 960, 75},
	{1280, 1024, 75}
};

