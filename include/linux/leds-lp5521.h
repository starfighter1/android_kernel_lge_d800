/*
 * LP5521 LED chip driver.
 *
 * Copyright (C) 2010 Nokia Corporation
 *
 * Contact: Samu Onkalo <samu.p.onkalo@nokia.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef __LINUX_LP5521_H
#define __LINUX_LP5521_H

/*                                        */

struct lp5521_led_config {
	char		*name;
	u8		chan_nr;
	u8		led_current; /*                                   */
	u8		max_current;
};

struct lp5521_led_pattern {
	const u8 *r;
	const u8 *g;
	const u8 *b;
	u8 size_r;
	u8 size_g;
	u8 size_b;
};

struct lp5521_engine {
	int		id;
	u8		mode;
	u8		prog_page;
	u8		engine_mask;
};

struct lp5521_led {
	int			id;
	u8			chan_nr;
	u8			led_current;
	u8			max_current;
	struct led_classdev	cdev;
	struct work_struct	brightness_work;
	u8			brightness;
};

#define LP5521_CLOCK_AUTO	0
#define LP5521_CLOCK_INT	1
#define LP5521_CLOCK_EXT	2

/*                         */
#define LP5521_PWM_HF			0x40	/*                           */
#define LP5521_PWRSAVE_EN		0x20	/*                     */
#define LP5521_CP_MODE_OFF		0	/*                      */
#define LP5521_CP_MODE_BYPASS		8	/*                          */
#define LP5521_CP_MODE_1X5		0x10	/*                        */
#define LP5521_CP_MODE_AUTO		0x18	/*                          */
#define LP5521_R_TO_BATT		4	/*                         */
#define LP5521_CLK_SRC_EXT		0	/*                          */
#define LP5521_CLK_INT			1	/*                */
#define LP5521_CLK_AUTO			2	/*                           */

struct lp5521_platform_data {
	struct lp5521_led_config *led_config;
	u8	num_channels;
	u8	clock_mode;
	void	(*release_resources)(void);
	void	(*enable)(bool state);
	const char *label;
	u8	update_config;
	struct lp5521_led_pattern *patterns;
	int num_patterns;
};

#define LP5521_MAX_LEDS			3	/*                        */
#define LP5521_MAX_ENGINES		3	/*                           */

struct lp5521_chip {
	struct lp5521_platform_data *pdata;
	struct mutex		lock; /*                   */
	struct i2c_client	*client;
	struct lp5521_engine	engines[LP5521_MAX_ENGINES];
	struct lp5521_led	leds[LP5521_MAX_LEDS];
	u8			num_channels;
	u8			num_leds;
	int id_pattern_play;
	u8 current_index;
    unsigned int rgb_led_en;
};

#define LP5521_INFO_PRINT   	(1)


#if defined(LP5521_INFO_PRINT)
#define LP5521_INFO_MSG(fmt, args...) \
		printk(KERN_INFO "[LP5521] " fmt, ##args);
#else
#define LP5521_INFO_MSG(fmt, args...)     {};
#endif

#ifdef CONFIG_LEDS_LP5521
/*                                   */
static const u8 mode1_red[] = {0xE0, 0x0C, 0x40, 0x00, 0x0C, 0x2F, 0x06, 0x28, 0x05, 0x2D, 0x06, 0x2A, 0x06, 0x25, 0x03, 0xDC, 0x02, 0xFA, 0x48, 0x00, 0x03, 0x54, 0x44, 0x01, 0x23, 0x06, 0x31, 0x84, 0x06, 0xA8, 0x0C, 0xAF};
static const u8 mode1_green[] = {0xE0, 0x80, 0x40, 0x00, 0x52, 0x00, 0x0B, 0x15, 0x05, 0x2D, 0x03, 0x48, 0x03, 0x4B, 0x09, 0x1B, 0x02, 0x63, 0x19, 0x89, 0x03, 0xCA, 0x04, 0xC1, 0x05, 0xB2, 0x06, 0xA6, 0x12, 0x8D, 0x52, 0x00};
static const u8 mode1_blue[] = {0xE0, 0x80, 0x40, 0x00, 0x12, 0xFE, 0x40, 0xC0, 0x0A, 0x18, 0x06, 0xA6, 0x06, 0xAA, 0x03, 0xCF, 0x04, 0xB6, 0x52, 0x00};

/*                                 */
static const u8 mode2_red[]={0x40, 0xff, 0x4d, 0x00, 0x0a, 0xff, 0x0a, 0xfe, 0xc0, 0x00};
static const u8 mode2_green[]={0x40, 0xff, 0x4d, 0x00, 0x0a, 0xff, 0x0a, 0xfe, 0xc0, 0x00};
static const u8 mode2_blue[]={0x40, 0xff, 0x4d, 0x00, 0x0a, 0xff, 0x0a, 0xfe, 0xc0, 0x00};

/*                              */
static const u8 mode3_red[] = {0x40, 0x1a, 0x42, 0x18, 0x12, 0x65, 0x12, 0x65, 0x66, 0x00, 0x12, 0xe5, 0x12, 0xe5, 0x42, 0x98};

/*                             */
static const u8 mode4_green[]={0x40, 0xff};

/*                                         */
static const u8 mode5_red[]={0x40, 0x19, 0x27, 0x19, 0xe0, 0x04, 0x0c, 0x65, 0xe0, 0x04, 0x0c, 0x65, 0xe0, 0x04, 0x0c, 0xe5, 0xe0, 0x04, 0x0c, 0xe5, 0xe0, 0x04, 0x29, 0x98, 0xe0, 0x04, 0x5a, 0x00};
static const u8 mode5_green[]={0x40, 0x0c, 0x43, 0x0b, 0xe0, 0x80, 0x19, 0x30, 0xe0, 0x80, 0x19, 0x30, 0xe0, 0x80, 0x19, 0xb0, 0xe0, 0x80, 0x19, 0xb0, 0xe0, 0x80, 0x43, 0x8b, 0xe0, 0x80, 0x5a, 0x00};

/*                          */
static const u8 mode6_red[] = {0xE0, 0x0C, 0x40, 0x00, 0x0C, 0x2F, 0x06, 0x28, 0x05, 0x2D, 0x06, 0x2A, 0x06, 0x25, 0x03, 0xDC, 0x02, 0xFA, 0x48, 0x00, 0x03, 0x54, 0x44, 0x01, 0x23, 0x06, 0x31, 0x84, 0x06, 0xA8, 0x0C, 0xAF};
static const u8 mode6_green[] = {0xE0, 0x80, 0x40, 0x00, 0x52, 0x00, 0x0B, 0x15, 0x05, 0x2D, 0x03, 0x48, 0x03, 0x4B, 0x09, 0x1B, 0x02, 0x63, 0x19, 0x89, 0x03, 0xCA, 0x04, 0xC1, 0x05, 0xB2, 0x06, 0xA6, 0x12, 0x8D, 0x52, 0x00};
static const u8 mode6_blue[] = {0xE0, 0x80, 0x40, 0x00, 0x12, 0xFE, 0x40, 0xC0, 0x0A, 0x18, 0x06, 0xA6, 0x06, 0xAA, 0x03, 0xCF, 0x04, 0xB6, 0x52, 0x00};


#if defined(CONFIG_MACH_APQ8064_GK_KR) || defined(CONFIG_MACH_APQ8064_GKATT) || defined(CONFIG_MACH_APQ8064_GV_KR) || defined(CONFIG_MACH_MSM8974_VU3_KR) || defined(CONFIG_MACH_MSM8974_Z_KR)
/*                            */
static const u8 mode7_red[]={};
static const u8 mode7_green[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xd4, 0x02, 0xd4, 0x02, 0xd4, 0x48, 0x00, 0x40, 0xff, 0x02, 0xd4, 0x02, 0xd4, 0x02, 0xd4, 0x25, 0xfe};
static const u8 mode7_blue[]={};

/*                                       */
static const u8 mode8_red[]={0x40, 0x00, 0x10, 0xFE, 0x40, 0xFF, 0x4F, 0x00, 0x05, 0xE5, 0xE0, 0x0C, 0x05, 0xE5, 0xE0, 0x0C, 0x40, 0xFF, 0x4F, 0x00, 0x04, 0xFF, 0xE0, 0x0C, 0x04, 0xFE, 0xE0, 0x0C, 0x1A, 0xFE};
static const u8 mode8_green[]={0x40, 0x00, 0x10, 0xFE, 0x40, 0x66, 0x4F, 0x00, 0x0B, 0xA8, 0xE0, 0x80, 0x0B, 0xA8, 0xE0, 0x80, 0x40, 0x66, 0x4F, 0x00, 0x09, 0xB2, 0xE0, 0x80, 0x09, 0xB2, 0xE0, 0x80, 0x1A, 0xFE};
static const u8 mode8_blue[]={0x40, 0x00, 0x10, 0xFE, 0x40, 0x73, 0x4F, 0x00, 0x08, 0xBC, 0xE0, 0x80, 0x0F, 0x9E, 0xE0, 0x80, 0x40, 0x73, 0x4F, 0x00, 0x05, 0xD5, 0xE0, 0x80, 0x10, 0x9C, 0xE0, 0x80, 0x1A, 0xFE};

/*                                                        */
#if 1 /*                           */
static const u8 mode4_green_50[]={0x40, 0x00, 0x3f, 0x19, 0x23, 0x33, 0x24, 0x32, 0x66, 0x00, 0x24, 0xb2, 0x23, 0xb3, 0x3f, 0x99, 0x7f, 0x00, 0xa2, 0x98};
#else /*                            */
static const u8 mode4_green_50[]={0x40, 0x00, 0x3f, 0x19, 0x23, 0x33, 0x24, 0x32, 0x66, 0x00, 0x24, 0xb2, 0x23, 0xb3, 0x3f, 0x99, 0x7f, 0x00, 0xa5, 0x18};
#endif

/*                                                         */
static const u8 mode3_red_50[]={0x40, 0x0d, 0x44, 0x0c, 0x23, 0x33, 0x24, 0x32, 0x66, 0x00, 0x24, 0xb2, 0x23, 0xb3, 0x44, 0x8c};

/*                                   */
static const u8 mode9_red[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xff, 0xe2, 0x00, 0x02, 0xfe, 0xe2, 0x00, 0x48, 0x00, 0x40, 0xff, 0x02, 0xff, 0xe2, 0x00, 0x02, 0xfe, 0xe2, 0x00, 0x25, 0xfe};
static const u8 mode9_green[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0x66, 0x06, 0xb2, 0xe2, 0x00, 0x06, 0xb2, 0xe2, 0x00, 0x48, 0x00, 0x40, 0x66, 0x06, 0xb2, 0xe2, 0x00, 0x06, 0xb2, 0xe2, 0x00, 0x25, 0xfe};
static const u8 mode9_blue[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0x73, 0x04, 0xd5, 0xe0, 0x06, 0x0b, 0x9c, 0xe0, 0x06, 0x48, 0x00, 0x40, 0x73, 0x04, 0xd5, 0xe0, 0x06, 0x0b, 0x9c, 0xe0, 0x06, 0x25, 0xfe};

/*                                   */
static const u8 mode10_red[]={};
static const u8 mode10_green[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xd4, 0x02, 0xd4, 0x02, 0xd4, 0x48, 0x00, 0x40, 0xff, 0x02, 0xd4, 0x02, 0xd4, 0x02, 0xd4, 0x25, 0xfe};
static const u8 mode10_blue[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xd4, 0x02, 0xd4, 0x02, 0xd4, 0x48, 0x00, 0x40, 0xff, 0x02, 0xd4, 0x02, 0xd4, 0x02, 0xd4, 0x25, 0xfe};

/*                                     */
static const u8 mode11_red[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xff, 0xe1, 0x00, 0x02, 0xfe, 0xe1, 0x00, 0x48, 0x00, 0x40, 0xff, 0x02, 0xff, 0xe1, 0x00, 0x02, 0xfe, 0xe1, 0x00, 0x25, 0xfe};
static const u8 mode11_green[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0x66, 0x06, 0xb2, 0xe0, 0x02, 0x06, 0xb2, 0xe0, 0x02, 0x48, 0x00, 0x40, 0x66, 0x06, 0xb2, 0xe0, 0x02, 0x06, 0xb2, 0xe0, 0x02, 0x25, 0xfe};
static const u8 mode11_blue[]={};


/*                                     */
static const u8 mode12_red[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xff, 0xe1, 0x00, 0x02, 0xfe, 0xe1, 0x00, 0x48, 0x00, 0x40, 0xff, 0x02, 0xff, 0xe1, 0x00, 0x02, 0xfe, 0xe1, 0x00, 0x25, 0xfe};
static const u8 mode12_green[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xe6, 0x02, 0xff, 0x3d, 0x00, 0xe0, 0x02, 0x02, 0xff, 0xe0, 0x02, 0x48, 0x00, 0x40, 0xe6, 0x02, 0xff, 0x3d, 0x00, 0xe0, 0x02, 0x02, 0xff, 0xe0, 0x02, 0x25, 0xfe};
static const u8 mode12_blue[]={};

#if  defined(CONFIG_MACH_MSM8974_VU3_KR) || defined(CONFIG_MACH_MSM8974_Z_KR)
/*                                         */
static const u8 mode5_red_rev_a[]={0x40, 0x19, 0x27, 0x19, 0xe0, 0x08, 0x0c, 0x65, 0xe0, 0x08, 0x0c, 0x65, 0xe0, 0x08, 0x0c, 0xe5, 0xe0, 0x08, 0x0c, 0xe5, 0xe0, 0x08, 0x29, 0x98, 0xe0, 0x08, 0x5a, 0x00};
static const u8 mode5_green_rev_a[]={0x40, 0x0c, 0x43, 0x0b, 0xe0, 0x80, 0x19, 0x30, 0xe0, 0x80, 0x19, 0x30, 0xe0, 0x80, 0x19, 0xb0, 0xe0, 0x80, 0x19, 0xb0, 0xe0, 0x80, 0x43, 0x8b, 0xe0, 0x80, 0x5a, 0x00};

/*                                   */
static const u8 mode9_red_rev_a[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xff, 0xe1, 0x00, 0x02, 0xfe, 0xe1, 0x00, 0x48, 0x00, 0x40, 0xff, 0x02, 0xff, 0xe1, 0x00, 0x02, 0xfe, 0xe1, 0x00, 0x25, 0xfe};
static const u8 mode9_green_rev_a[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0x66, 0x06, 0xb2, 0xe1, 0x00, 0x06, 0xb2, 0xe1, 0x00, 0x48, 0x00, 0x40, 0x66, 0x06, 0xb2, 0xe1, 0x00, 0x06, 0xb2, 0xe1, 0x00, 0x25, 0xfe};
static const u8 mode9_blue_rev_a[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0x73, 0x04, 0xd5, 0xe0, 0x0a, 0x0b, 0x9c, 0xe0, 0x0a, 0x48, 0x00, 0x40, 0x73, 0x04, 0xd5, 0xe0, 0x0a, 0x0b, 0x9c, 0xe0, 0x0a, 0x25, 0xfe};

/*                                     */
static const u8 mode11_red_rev_a[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xff, 0xe2, 0x00, 0x02, 0xfe, 0xe2, 0x00, 0x48, 0x00, 0x40, 0xff, 0x02, 0xff, 0xe2, 0x00, 0x02, 0xfe, 0xe2, 0x00, 0x25, 0xfe};
static const u8 mode11_green_rev_a[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0x66, 0x06, 0xb2, 0xe0, 0x02, 0x06, 0xb2, 0xe0, 0x02, 0x48, 0x00, 0x40, 0x66, 0x06, 0xb2, 0xe0, 0x02, 0x06, 0xb2, 0xe0, 0x02, 0x25, 0xfe};
static const u8 mode11_blue_rev_a[]={};

/*                                     */
static const u8 mode12_red_rev_a[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xff, 0x02, 0xff, 0xe2, 0x00, 0x02, 0xfe, 0xe2, 0x00, 0x48, 0x00, 0x40, 0xff, 0x02, 0xff, 0xe2, 0x00, 0x02, 0xfe, 0xe2, 0x00, 0x25, 0xfe};
static const u8 mode12_green_rev_a[]={0x40, 0x00, 0x10, 0xfe, 0x40, 0xe6, 0x02, 0xff, 0x3d, 0x00, 0xe0, 0x02, 0x02, 0xff, 0xe0, 0x02, 0x48, 0x00, 0x40, 0xe6, 0x02, 0xff, 0x3d, 0x00, 0xe0, 0x02, 0x02, 0xff, 0xe0, 0x02, 0x25, 0xfe};
static const u8 mode12_blue_rev_a[]={};
#endif

#elif defined(CONFIG_MACH_APQ8064_GVDCM)

/*                            */
static const u8 mode7_red[]={0x40, 0x00, 0x10, 0xFE, 0x40, 0x5D, 0xE2, 0x00, 0x07, 0xAD, 0xE2, 0x00, 0x07, 0xAE, 0xE2, 0x00, 0x48, 0x00, 0x40, 0x5D, 0xE2, 0x00, 0x07, 0xAD, 0xE2, 0x00, 0x07, 0xAE, 0xE2, 0x00, 0x25, 0xFE};
static const u8 mode7_green[]={0x40, 0x00, 0x10, 0xFE, 0x40, 0xCD, 0xE2, 0x00, 0x03, 0xE6, 0xE2, 0x00, 0x03, 0xE5, 0xE2, 0x00, 0x48, 0x00, 0x40, 0xCD, 0xE2, 0x00, 0x03, 0xE6, 0xE2, 0x00, 0x03, 0xE5, 0xE2, 0x00, 0x25, 0xFE};
static const u8 mode7_blue[]={0x40, 0x00, 0x10, 0xFE, 0x40, 0xE6, 0xE0, 0x06, 0x03, 0xF2, 0xE0, 0x06, 0x03, 0xF2, 0xE0, 0x06, 0x48, 0x00, 0x40, 0xE6, 0xE0, 0x06, 0x03, 0xF2, 0xE0, 0x06, 0x03, 0xF2, 0xE0, 0x06, 0x25, 0xFE};
//                           
static const  u8 mode8_blue[]={0x40, 0x33, 0x04, 0x65, 0x04, 0x65, 0x04, 0xE5, 0x04, 0xE5, 0x00, 0x00};
//                        
static const u8 mode9_blue[]={0x40, 0x00, 0x08, 0x7E, 0x08, 0x7F, 0x08, 0xFE, 0x08, 0xFF, 0x00, 0x00};
#endif

#if defined(CONFIG_MACH_APQ8064_GK_KR) || defined(CONFIG_MACH_APQ8064_GKATT) || defined(CONFIG_MACH_APQ8064_GV_KR) || defined(CONFIG_MACH_MSM8974_VU3_KR) || defined(CONFIG_MACH_MSM8974_Z_KR)

static const u8 current_index_mapped_value[256] = {
	7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,   //   
	7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  8,  8,  8,  8,   //   
	8,  8,  8,  9,  9,  9,  9,  9,  9, 10, 10, 10, 10, 10, 10,   //   
	11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 13, 13, 13, 13,  //   
	14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 19,  //   
	18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 22, 22, 23, 23, 24,  //   
	24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31,  //    
	31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38,  //    
	39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 45, 46, 47, 48,  //    
	49, 50, 51, 52, 52, 53, 54, 55, 56, 57, 58, 59, 60, 60, 61,  //    
	61, 62, 62, 63, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,  //    
	73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,  //    
	88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,100,101,102,  //    
	103,104,105,106,107,108,109,111,112,113,114,115,116,117,118, //    
	119,121,123,124,126,127,128,129,130,131,132,133,134,135,136, //    
	138,140,142,143,144,146,148,150,151,152,154,155,157,158,159, //    
	160,161,162,163,164,165,166,167,168,169,170,172,174,176,178, //    
	180
};
#elif defined(CONFIG_MACH_APQ8064_GVDCM)
static const u8 current_index_mapped_value[256] = {
	7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,   //   
	7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,   //   
	7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,   //   
	7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,   //   
	7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,   //   
	7,  7,  7,  7,  7,255,255,255,255,255,255,255,255,255,255,   //   
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,   //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,   //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,   //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,   //    
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,   //    
	255
};

#else
/*                     */
static const u8 current_index_mapped_value[256] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,  //   
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,  //   
	30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,  //   
	45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,    //   
	60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,  //   
	75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,  //   
	90, 91, 92, 93, 94, 95, 96, 97, 98, 99,100,101,102,103,104,  //    
	105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,  //    
	120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,  //    
	135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,  //    
	150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,  //    
	165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,  //    
	180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,   //    
	195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,   //    
	210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,   //    
	225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,   //    
	240,241,242,243,244,245,246,247,248,249,220,251,252,253,254,   //    
	255
};
#endif


#endif /*                    */

#endif /*                  */
