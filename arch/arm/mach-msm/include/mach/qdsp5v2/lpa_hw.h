/* Copyright (c) 2009, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __MACH_QDSP5_V2_LPA_HW_H__
#define __MACH_QDSP5_V2_LPA_HW_H__

#define LPA_MAX_BUF_SIZE 0x30000

/*                             */
enum {
	LPA_OBUF_CONTROL	= 0x00000000,
	LPA_OBUF_CODEC		= 0x00000004,
	LPA_OBUF_HLB_MIN_ADDR	= 0x00000008,
	LPA_OBUF_HLB_MAX_ADDR	= 0x0000000C,
	LPA_OBUF_HLB_WPTR	= 0x00000010,
	LPA_OBUF_HLB_VOLUME_CONTROL = 0x00000014,
	LPA_OBUF_LLB_MIN_ADDR	= 0x00000018,
	LPA_OBUF_LLB_MAX_ADDR	= 0x0000001C,
	LPA_OBUF_SB_MIN_ADDR	= 0x00000020,
	LPA_OBUF_SB_MAX_ADDR	= 0x00000024,
	LPA_OBUF_INTR_ENABLE	= 0x00000028,
	LPA_OBUF_INTR_STATUS	= 0x0000002C,
	LPA_OBUF_WMARK_ASSIGN	= 0x00000030,
	LPA_OBUF_WMARK_0_LLB	= 0x00000034,
	LPA_OBUF_WMARK_1_LLB	= 0x00000038,
	LPA_OBUF_WMARK_2_LLB	= 0x0000003C,
	LPA_OBUF_WMARK_3_LLB	= 0x00000040,
	LPA_OBUF_WMARK_HLB	= 0x00000044,
	LPA_OBUF_WMARK_SB	= 0x00000048,
	LPA_OBUF_RDPTR_LLB	= 0x0000004C,
	LPA_OBUF_RDPTR_HLB	= 0x00000050,
	LPA_OBUF_WRPTR_SB	= 0x00000054,
	LPA_OBUF_UTC_CONFIG	= 0x00000058,
	LPA_OBUF_UTC_INTR_LOW	= 0x0000005C,
	LPA_OBUF_UTC_INTR_HIGH	= 0x00000060,
	LPA_OBUF_UTC_LOW	= 0x00000064,
	LPA_OBUF_UTC_HIGH	= 0x00000068,
	LPA_OBUF_MISR		= 0x0000006C,
	LPA_OBUF_STATUS		= 0x00000070,
	LPA_OBUF_ACK		= 0x00000074,
	LPA_OBUF_MEMORY_CONTROL	= 0x00000078,
	LPA_OBUF_MEMORY_STATUS	= 0x0000007C,
	LPA_OBUF_MEMORY_TIME_CONTROL	= 0x00000080,
	LPA_OBUF_ACC_LV			= 0x00000084,
	LPA_OBUF_ACC_HV			= 0x0000008c,
	LPA_OBUF_RESETS			= 0x00000090,
	LPA_OBUF_TESTBUS		= 0x00000094,
};

/*                       */
#define LPA_OBUF_CODEC_RESERVED31_22_BMSK        0xffc00000
#define LPA_OBUF_CODEC_RESERVED31_22_SHFT        0x16
#define LPA_OBUF_CODEC_LOAD_BMSK                 0x200000
#define LPA_OBUF_CODEC_LOAD_SHFT                 0x15
#define LPA_OBUF_CODEC_CODEC_INTF_EN_BMSK        0x100000
#define LPA_OBUF_CODEC_CODEC_INTF_EN_SHFT        0x14
#define LPA_OBUF_CODEC_SAMP_BMSK                 0xf0000
#define LPA_OBUF_CODEC_SAMP_SHFT                 0x10
#define LPA_OBUF_CODEC_BITS_PER_CHAN_BMSK        0xc000
#define LPA_OBUF_CODEC_BITS_PER_CHAN_SHFT        0xe
#define LPA_OBUF_CODEC_RESERVED_13_7_BMSK        0x3f80
#define LPA_OBUF_CODEC_RESERVED_13_7_SHFT        0x7
#define LPA_OBUF_CODEC_INTF_BMSK                 0x70
#define LPA_OBUF_CODEC_INTF_SHFT                 0x4
#define LPA_OBUF_CODEC_NUM_CHAN_BMSK             0xf
#define LPA_OBUF_CODEC_NUM_CHAN_SHFT             0

/*                         */
#define LPA_OBUF_CONTROL_RESERVED31_9_BMSK       0xfffffe00
#define LPA_OBUF_CONTROL_RESERVED31_9_SHFT       0x9
#define LPA_OBUF_CONTROL_TEST_EN_BMSK            0x100
#define LPA_OBUF_CONTROL_TEST_EN_SHFT            0x8
#define LPA_OBUF_CONTROL_LLB_CLR_CMD_BMSK        0x80
#define LPA_OBUF_CONTROL_LLB_CLR_CMD_SHFT        0x7
#define LPA_OBUF_CONTROL_SB_SAT_EN_BMSK          0x40
#define LPA_OBUF_CONTROL_SB_SAT_EN_SHFT          0x6
#define LPA_OBUF_CONTROL_LLB_SAT_EN_BMSK         0x20
#define LPA_OBUF_CONTROL_LLB_SAT_EN_SHFT         0x5
#define LPA_OBUF_CONTROL_RESERVED4_BMSK          0x10
#define LPA_OBUF_CONTROL_RESERVED4_SHFT          0x4
#define LPA_OBUF_CONTROL_LLB_ACC_EN_BMSK         0x8
#define LPA_OBUF_CONTROL_LLB_ACC_EN_SHFT         0x3
#define LPA_OBUF_CONTROL_HLB_EN_BMSK             0x4
#define LPA_OBUF_CONTROL_HLB_EN_SHFT             0x2
#define LPA_OBUF_CONTROL_LLB_EN_BMSK             0x2
#define LPA_OBUF_CONTROL_LLB_EN_SHFT             0x1
#define LPA_OBUF_CONTROL_SB_EN_BMSK              0x1
#define LPA_OBUF_CONTROL_SB_EN_SHFT              0

/*                       */
#define LPA_OBUF_RESETS_MISR_RESET 0x1
#define LPA_OBUF_RESETS_OVERALL_RESET 0x2

/*                        */
#define LPA_OBUF_STATUS_RESET_DONE 0x80000
#define LPA_OBUF_STATUS_LLB_CLR_BMSK 0x40000
#define LPA_OBUF_STATUS_LLB_CLR_SHFT 0x12

/*                              */
#define LPA_OBUF_HLB_MIN_ADDR_LOAD_BMSK 0x40000
#define LPA_OBUF_HLB_MIN_ADDR_SEG_BMSK 0x3e000

/*                              */
#define LPA_OBUF_HLB_MAX_ADDR_SEG_BMSK 0x3fff8

/*                              */
#define LPA_OBUF_LLB_MIN_ADDR_LOAD_BMSK 0x40000
#define LPA_OBUF_LLB_MIN_ADDR_SEG_BMSK 0x3e000

/*                              */
#define LPA_OBUF_LLB_MAX_ADDR_SEG_BMSK 0x3ff8
#define LPA_OBUF_LLB_MAX_ADDR_SEG_SHFT 0x3

/*                             */
#define LPA_OBUF_SB_MIN_ADDR_LOAD_BMSK 0x4000
#define LPA_OBUF_SB_MIN_ADDR_SEG_BMSK 0x3e00

/*                             */
#define LPA_OBUF_SB_MAX_ADDR_SEG_BMSK 0x3ff8

/*                                */
#define LPA_OBUF_MEM_CTL_PWRUP_BMSK 0xfff
#define LPA_OBUF_MEM_CTL_PWRUP_SHFT 0x0

/*                             */
#define LPA_OBUF_INTR_EN_BMSK 0x3

/*                              */
#define LPA_OBUF_WMARK_ASSIGN_BMSK 0xF
#define LPA_OBUF_WMARK_ASSIGN_DONE 0xF

/*                             */
#define LPA_OBUF_WMARK_n_LLB_ADDR(n)  (0x00000034 + 0x4 * (n))
#define LPA_OBUF_LLB_WMARK_CTRL_BMSK 0xc0000
#define LPA_OBUF_LLB_WMARK_CTRL_SHFT 0x12
#define LPA_OBUF_LLB_WMARK_MAP_BMSK  0xf00000
#define LPA_OBUF_LLB_WMARK_MAP_SHFT  0x14

/*                          */
#define LPA_OBUF_SB_WMARK_CTRL_BMSK 0xc0000
#define LPA_OBUF_SB_WMARK_CTRL_SHFT 0x12
#define LPA_OBUF_SB_WMARK_MAP_BMSK  0xf00000
#define LPA_OBUF_SB_WMARK_MAP_SHFT  0x14

/*                           */
#define LPA_OBUF_HLB_WMARK_CTRL_BMSK 0xc0000
#define LPA_OBUF_HLB_WMARK_CTRL_SHFT 0x12
#define LPA_OBUF_HLB_WMARK_MAP_BMSK  0xf00000
#define LPA_OBUF_HLB_WMARK_MAP_SHFT  0x14

/*                            */
#define LPA_OBUF_UTC_CONFIG_MAP_BMSK 0xf0
#define LPA_OBUF_UTC_CONFIG_MAP_SHFT 0x4
#define LPA_OBUF_UTC_CONFIG_EN_BMSK  0x1
#define LPA_OBUF_UTC_CONFIG_EN_SHFT  0
#define LPA_OBUF_UTC_CONFIG_NO_INTR 0xF

/*                     */
#define LPA_OBUF_ACK_RESET_DONE_BMSK   0x80000
#define LPA_OBUF_ACK_RESET_DONE_SHFT   0x13
enum {
	LPA_SAMPLE_RATE_8KHZ		= 0x0000,
	LPA_SAMPLE_RATE_11P025KHZ	= 0x0001,
	LPA_SAMPLE_RATE_16KHZ		= 0x0002,
	LPA_SAMPLE_RATE_22P05KHZ	= 0x0003,
	LPA_SAMPLE_RATE_32KHZ		= 0x0004,
	LPA_SAMPLE_RATE_44P1KHZ		= 0x0005,
	LPA_SAMPLE_RATE_48KHZ		= 0x0006,
	LPA_SAMPLE_RATE_64KHZ		= 0x0007,
	LPA_SAMPLE_RATE_96KHZ		= 0x0008,
};

enum {
	LPA_BITS_PER_CHAN_16BITS	= 0x0000,
	LPA_BITS_PER_CHAN_24BITS	= 0x0001,
	LPA_BITS_PER_CHAN_32BITS	= 0x0002,
	LPA_BITS_PER_CHAN_RESERVED	= 0x0003,
};

enum {
	LPA_INTF_WB_CODEC		= 0x0000,
	LPA_INTF_SDAC			= 0x0001,
	LPA_INTF_MI2S			= 0x0002,
	LPA_INTF_RESERVED		= 0x0003,
};

enum {
	LPA_BUF_ID_HLB,   /*            */
	LPA_BUF_ID_LLB,   /*            */
	LPA_BUF_ID_SB,    /*           */
	LPA_BUF_ID_UTC,
};

/*                                                    
                                            
 */
enum {
	LPA_NUM_CHAN_MONO		= 0x0000,
	LPA_NUM_CHAN_STEREO		= 0x0001,
	LPA_NUM_CHAN_5P1		= 0x0002,
	LPA_NUM_CHAN_7P1		= 0x0003,
	LPA_NUM_CHAN_4_CHANNEL		= 0x0004,
};

enum {
	LPA_WMARK_CTL_DISABLED = 0x0,
	LPA_WMARK_CTL_NON_BLOCK = 0x1,
	LPA_WMARK_CTL_ZERO_INSERT = 0x2,
	LPA_WMARK_CTL_RESERVED = 0x3
};

struct lpa_mem_bank_select {
  u32    b0:1;       /*                         */
  u32    b1:1;       /*                         */
  u32    b2:1;       /*                         */
  u32    b3:1;       /*                         */
  u32    b4:1;       /*                         */
  u32    b5:1;       /*                         */
  u32    b6:1;       /*                         */
  u32    b7:1;       /*                         */
  u32    b8:1;       /*                         */
  u32    b9:1;       /*                         */
  u32    b10:1;      /*                          */
  u32    llb:1;      /*                          */
};

#endif