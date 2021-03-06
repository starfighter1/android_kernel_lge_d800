/*
 * vs6624 - ST VS6624 CMOS image sensor registers
 *
 * Copyright (c) 2011 Analog Devices Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _VS6624_REGS_H_
#define _VS6624_REGS_H_

/*                             */
#define VS6624_MICRO_EN               0xC003 /*                                */
#define VS6624_DIO_EN                 0xC044 /*                    */
/*                   */
#define VS6624_DEV_ID_MSB             0x0001 /*               */
#define VS6624_DEV_ID_LSB             0x0002 /*               */
#define VS6624_FW_VSN_MAJOR           0x0004 /*                        */
#define VS6624_FW_VSN_MINOR           0x0006 /*                        */
#define VS6624_PATCH_VSN_MAJOR        0x0008 /*                     */
#define VS6624_PATCH_VSN_MINOR        0x000A /*                     */
/*                                */
#define VS6624_USER_CMD               0x0180 /*                                        */
/*                               */
#define VS6624_STATE                  0x0202 /*                                   */
/*                  */
#define VS6624_METER_ON               0x0280 /*                                  */
/*            */
#define VS6624_ACTIVE_PIPE_SETUP      0x0302 /*                                               */
#define VS6624_SENSOR_MODE            0x0308 /*                                  */
/*                  */
#define VS6624_IMAGE_SIZE0            0x0380 /*                           */
#define VS6624_MAN_HSIZE0_MSB         0x0383 /*                                  */
#define VS6624_MAN_HSIZE0_LSB         0x0384 /*                                  */
#define VS6624_MAN_VSIZE0_MSB         0x0387 /*                                  */
#define VS6624_MAN_VSIZE0_LSB         0x0388 /*                                  */
#define VS6624_ZOOM_HSTEP0_MSB        0x038B /*                         */
#define VS6624_ZOOM_HSTEP0_LSB        0x038C /*                         */
#define VS6624_ZOOM_VSTEP0_MSB        0x038F /*                         */
#define VS6624_ZOOM_VSTEP0_LSB        0x0390 /*                         */
#define VS6624_ZOOM_CTRL0             0x0392 /*                               */
#define VS6624_PAN_HSTEP0_MSB         0x0395 /*                        */
#define VS6624_PAN_HSTEP0_LSB         0x0396 /*                        */
#define VS6624_PAN_VSTEP0_MSB         0x0399 /*                        */
#define VS6624_PAN_VSTEP0_LSB         0x039A /*                        */
#define VS6624_PAN_CTRL0              0x039C /*                       */
#define VS6624_CROP_CTRL0             0x039E /*                      */
#define VS6624_CROP_HSTART0_MSB       0x03A1 /*                                      */
#define VS6624_CROP_HSTART0_LSB       0x03A2 /*                                      */
#define VS6624_CROP_HSIZE0_MSB        0x03A5 /*                             */
#define VS6624_CROP_HSIZE0_LSB        0x03A6 /*                             */
#define VS6624_CROP_VSTART0_MSB       0x03A9 /*                                      */
#define VS6624_CROP_VSTART0_LSB       0x03AA /*                                      */
#define VS6624_CROP_VSIZE0_MSB        0x03AD /*                             */
#define VS6624_CROP_VSIZE0_LSB        0x03AE /*                             */
#define VS6624_IMG_FMT0               0x03B0 /*                                     */
#define VS6624_BAYER_OUT_ALIGN0       0x03B2 /*                            */
#define VS6624_CONTRAST0              0x03B4 /*                             */
#define VS6624_SATURATION0            0x03B6 /*                               */
#define VS6624_GAMMA0                 0x03B8 /*                */
#define VS6624_HMIRROR0               0x03BA /*                                   */
#define VS6624_VFLIP0                 0x03BC /*                                 */
#define VS6624_CHANNEL_ID0            0x03BE /*                            */
/*                  */
#define VS6624_IMAGE_SIZE1            0x0400 /*                           */
#define VS6624_MAN_HSIZE1_MSB         0x0403 /*                                  */
#define VS6624_MAN_HSIZE1_LSB         0x0404 /*                                  */
#define VS6624_MAN_VSIZE1_MSB         0x0407 /*                                  */
#define VS6624_MAN_VSIZE1_LSB         0x0408 /*                                  */
#define VS6624_ZOOM_HSTEP1_MSB        0x040B /*                         */
#define VS6624_ZOOM_HSTEP1_LSB        0x040C /*                         */
#define VS6624_ZOOM_VSTEP1_MSB        0x040F /*                         */
#define VS6624_ZOOM_VSTEP1_LSB        0x0410 /*                         */
#define VS6624_ZOOM_CTRL1             0x0412 /*                               */
#define VS6624_PAN_HSTEP1_MSB         0x0415 /*                        */
#define VS6624_PAN_HSTEP1_LSB         0x0416 /*                        */
#define VS6624_PAN_VSTEP1_MSB         0x0419 /*                        */
#define VS6624_PAN_VSTEP1_LSB         0x041A /*                        */
#define VS6624_PAN_CTRL1              0x041C /*                       */
#define VS6624_CROP_CTRL1             0x041E /*                      */
#define VS6624_CROP_HSTART1_MSB       0x0421 /*                                      */
#define VS6624_CROP_HSTART1_LSB       0x0422 /*                                      */
#define VS6624_CROP_HSIZE1_MSB        0x0425 /*                             */
#define VS6624_CROP_HSIZE1_LSB        0x0426 /*                             */
#define VS6624_CROP_VSTART1_MSB       0x0429 /*                                      */
#define VS6624_CROP_VSTART1_LSB       0x042A /*                                      */
#define VS6624_CROP_VSIZE1_MSB        0x042D /*                             */
#define VS6624_CROP_VSIZE1_LSB        0x042E /*                             */
#define VS6624_IMG_FMT1               0x0430 /*                                     */
#define VS6624_BAYER_OUT_ALIGN1       0x0432 /*                            */
#define VS6624_CONTRAST1              0x0434 /*                             */
#define VS6624_SATURATION1            0x0436 /*                               */
#define VS6624_GAMMA1                 0x0438 /*                */
#define VS6624_HMIRROR1               0x043A /*                                   */
#define VS6624_VFLIP1                 0x043C /*                                 */
#define VS6624_CHANNEL_ID1            0x043E /*                            */
/*                   */
#define VS6624_VIEW_LIVE_EN           0x0480 /*                       */
#define VS6624_INIT_PIPE_SETUP        0x0482 /*                                */
/*                  */
#define VS6624_CUR_PIPE_SETUP         0x0500 /*                                            */
/*                  */
#define VS6624_TIME_TO_POWER_DOWN     0x0580 /*                                            */
/*                                    */
#define VS6624_EXT_CLK_FREQ_NUM_MSB   0x0605 /*                                        */
#define VS6624_EXT_CLK_FREQ_NUM_LSB   0x0606 /*                                        */
#define VS6624_EXT_CLK_FREQ_DEN       0x0608 /*                                      */
/*                      */
#define VS6624_SYS_CLK_MODE           0x0880 /*                                */
/*                                       */
#define VS6624_LIGHT_FREQ             0x0C80 /*                                         */
#define VS6624_FLICKER_COMPAT         0x0C82 /*                                 */
/*                           */
#define VS6624_FR_NUM_MSB             0x0D81 /*                                  */
#define VS6624_FR_NUM_LSB             0x0D82 /*                                  */
#define VS6624_FR_DEN                 0x0D84 /*                                */
/*                              */
#define VS6624_DISABLE_FR_DAMPER      0x0E80 /*                         */
#define VS6624_MIN_DAMPER_OUT_MSB     0x0E8C /*                        */
#define VS6624_MIN_DAMPER_OUT_LSB     0x0E8A /*                        */
/*                   */
#define VS6624_EXPO_MODE              0x1180 /*               */
#define VS6624_EXPO_METER             0x1182 /*                                         */
#define VS6624_EXPO_TIME_NUM          0x1184 /*                         */
#define VS6624_EXPO_TIME_DEN          0x1186 /*                           */
#define VS6624_EXPO_TIME_MSB          0x1189 /*                                       */
#define VS6624_EXPO_TIME_LSB          0x118A /*                                       */
#define VS6624_EXPO_COMPENSATION      0x1190 /*                       */
#define VS6624_DIRECT_COARSE_MSB      0x1195 /*                                              */
#define VS6624_DIRECT_COARSE_LSB      0x1196 /*                                              */
#define VS6624_DIRECT_FINE_MSB        0x1199 /*                                             */
#define VS6624_DIRECT_FINE_LSB        0x119A /*                                             */
#define VS6624_DIRECT_ANAL_GAIN_MSB   0x119D /*                                 */
#define VS6624_DIRECT_ANAL_GAIN_LSB   0x119E /*                                 */
#define VS6624_DIRECT_DIGI_GAIN_MSB   0x11A1 /*                                  */
#define VS6624_DIRECT_DIGI_GAIN_LSB   0x11A2 /*                                  */
#define VS6624_FLASH_COARSE_MSB       0x11A5 /*                                                 */
#define VS6624_FLASH_COARSE_LSB       0x11A6 /*                                                 */
#define VS6624_FLASH_FINE_MSB         0x11A9 /*                                                */
#define VS6624_FLASH_FINE_LSB         0x11AA /*                                                */
#define VS6624_FLASH_ANAL_GAIN_MSB    0x11AD /*                                    */
#define VS6624_FLASH_ANAL_GAIN_LSB    0x11AE /*                                    */
#define VS6624_FLASH_DIGI_GAIN_MSB    0x11B1 /*                                     */
#define VS6624_FLASH_DIGI_GAIN_LSB    0x11B2 /*                                     */
#define VS6624_FREEZE_AE              0x11B4 /*                      */
#define VS6624_MAX_INT_TIME_MSB       0x11B7 /*                                   */
#define VS6624_MAX_INT_TIME_LSB       0x11B8 /*                                   */
#define VS6624_FLASH_AG_THR_MSB       0x11BB /*                                               */
#define VS6624_FLASH_AG_THR_LSB       0x11BC /*                                               */
#define VS6624_ANTI_FLICKER_MODE      0x11C0 /*                   */
/*                       */
#define VS6624_WB_MODE                0x1480 /*                        */
#define VS6624_MAN_RG                 0x1482 /*                                   */
#define VS6624_MAN_GG                 0x1484 /*                                     */
#define VS6624_MAN_BG                 0x1486 /*                                    */
#define VS6624_FLASH_RG_MSB           0x148B /*                            */
#define VS6624_FLASH_RG_LSB           0x148C /*                            */
#define VS6624_FLASH_GG_MSB           0x148F /*                              */
#define VS6624_FLASH_GG_LSB           0x1490 /*                              */
#define VS6624_FLASH_BG_MSB           0x1493 /*                             */
#define VS6624_FLASH_BG_LSB           0x1494 /*                             */
/*              */
#define VS6624_BC_OFFSET              0x1990 /*                         */
/*                 */
#define VS6624_STABLE_WB              0x1900 /*                      */
#define VS6624_STABLE_EXPO            0x1902 /*                 */
#define VS6624_STABLE                 0x1906 /*               */
/*               */
#define VS6624_FLASH_MODE             0x1A80 /*            */
#define VS6624_FLASH_OFF_LINE_MSB     0x1A83 /*                                  */
#define VS6624_FLASH_OFF_LINE_LSB     0x1A84 /*                                  */
/*              */
#define VS6624_FLASH_RECOM            0x1B00 /*                          */
#define VS6624_FLASH_GRAB_COMPLETE    0x1B02 /*                                  */
/*                        */
#define VS6624_SCYTHE_FILTER          0x1D80 /*                                  */
/*                      */
#define VS6624_JACK_FILTER            0x1E00 /*                                */
/*                  */
#define VS6624_ANTI_ALIAS_FILTER      0x1E80 /*                            */
/*                      */
#define VS6624_CM_DISABLE             0x1F00 /*                             */
#define VS6624_CM_LOW_THR_MSB         0x1F03 /*                                */
#define VS6624_CM_LOW_THR_LSB         0x1F04 /*                                */
#define VS6624_CM_HIGH_THR_MSB        0x1F07 /*                                 */
#define VS6624_CM_HIGH_THR_LSB        0x1F08 /*                                 */
#define VS6624_CM_MIN_OUT_MSB         0x1F0B /*                                    */
#define VS6624_CM_MIN_OUT_LSB         0x1F0C /*                                    */
/*                 */
#define VS6624_PEAK_GAIN              0x2000 /*                       */
#define VS6624_PEAK_G_DISABLE         0x2002 /*                           */
#define VS6624_PEAK_LOW_THR_G_MSB     0x2005 /*                                         */
#define VS6624_PEAK_LOW_THR_G_LSB     0x2006 /*                                         */
#define VS6624_PEAK_HIGH_THR_G_MSB    0x2009 /*                                          */
#define VS6624_PEAK_HIGH_THR_G_LSB    0x200A /*                                          */
#define VS6624_PEAK_MIN_OUT_G_MSB     0x200D /*                                    */
#define VS6624_PEAK_MIN_OUT_G_LSB     0x200E /*                                    */
#define VS6624_PEAK_LOW_THR           0x2010 /*                         */
#define VS6624_PEAK_C_DISABLE         0x2012 /*                        */
#define VS6624_PEAK_HIGH_THR          0x2014 /*                     */
#define VS6624_PEAK_LOW_THR_C_MSB     0x2017 /*                                           */
#define VS6624_PEAK_LOW_THR_C_LSB     0x2018 /*                                           */
#define VS6624_PEAK_HIGH_THR_C_MSB    0x201B /*                                            */
#define VS6624_PEAK_HIGH_THR_C_LSB    0x201C /*                                            */
#define VS6624_PEAK_MIN_OUT_C_MSB     0x201F /*                                      */
#define VS6624_PEAK_MIN_OUT_C_LSB     0x2020 /*                                      */
/*                                         */
#define VS6624_RYM0_MAN_CTRL          0x2180 /*                                 */
#define VS6624_RYM0_W00_MSB           0x2183 /*                                  */
#define VS6624_RYM0_W00_LSB           0x2184 /*                                  */
#define VS6624_RYM0_W01_MSB           0x2187 /*                                  */
#define VS6624_RYM0_W01_LSB           0x2188 /*                                  */
#define VS6624_RYM0_W02_MSB           0x218C /*                                  */
#define VS6624_RYM0_W02_LSB           0x218D /*                                  */
#define VS6624_RYM0_W10_MSB           0x2190 /*                                  */
#define VS6624_RYM0_W10_LSB           0x218F /*                                  */
#define VS6624_RYM0_W11_MSB           0x2193 /*                                  */
#define VS6624_RYM0_W11_LSB           0x2194 /*                                  */
#define VS6624_RYM0_W12_MSB           0x2197 /*                                  */
#define VS6624_RYM0_W12_LSB           0x2198 /*                                  */
#define VS6624_RYM0_W20_MSB           0x219B /*                                  */
#define VS6624_RYM0_W20_LSB           0x219C /*                                  */
#define VS6624_RYM0_W21_MSB           0x21A0 /*                                  */
#define VS6624_RYM0_W21_LSB           0x219F /*                                  */
#define VS6624_RYM0_W22_MSB           0x21A3 /*                                  */
#define VS6624_RYM0_W22_LSB           0x21A4 /*                                  */
#define VS6624_RYM0_YINY_MSB          0x21A7 /*            */
#define VS6624_RYM0_YINY_LSB          0x21A8 /*            */
#define VS6624_RYM0_YINCB_MSB         0x21AB /*             */
#define VS6624_RYM0_YINCB_LSB         0x21AC /*             */
#define VS6624_RYM0_YINCR_MSB         0x21B0 /*             */
#define VS6624_RYM0_YINCR_LSB         0x21AF /*             */
/*                                         */
#define VS6624_RYM1_MAN_CTRL          0x2200 /*                                 */
#define VS6624_RYM1_W00_MSB           0x2203 /*                                  */
#define VS6624_RYM1_W00_LSB           0x2204 /*                                  */
#define VS6624_RYM1_W01_MSB           0x2207 /*                                  */
#define VS6624_RYM1_W01_LSB           0x2208 /*                                  */
#define VS6624_RYM1_W02_MSB           0x220C /*                                  */
#define VS6624_RYM1_W02_LSB           0x220D /*                                  */
#define VS6624_RYM1_W10_MSB           0x2210 /*                                  */
#define VS6624_RYM1_W10_LSB           0x220F /*                                  */
#define VS6624_RYM1_W11_MSB           0x2213 /*                                  */
#define VS6624_RYM1_W11_LSB           0x2214 /*                                  */
#define VS6624_RYM1_W12_MSB           0x2217 /*                                  */
#define VS6624_RYM1_W12_LSB           0x2218 /*                                  */
#define VS6624_RYM1_W20_MSB           0x221B /*                                  */
#define VS6624_RYM1_W20_LSB           0x221C /*                                  */
#define VS6624_RYM1_W21_MSB           0x2220 /*                                  */
#define VS6624_RYM1_W21_LSB           0x221F /*                                  */
#define VS6624_RYM1_W22_MSB           0x2223 /*                                  */
#define VS6624_RYM1_W22_LSB           0x2224 /*                                  */
#define VS6624_RYM1_YINY_MSB          0x2227 /*            */
#define VS6624_RYM1_YINY_LSB          0x2228 /*            */
#define VS6624_RYM1_YINCB_MSB         0x222B /*             */
#define VS6624_RYM1_YINCB_LSB         0x222C /*             */
#define VS6624_RYM1_YINCR_MSB         0x2220 /*             */
#define VS6624_RYM1_YINCR_LSB         0x222F /*             */
/*                             */
#define VS6624_GAMMA_MAN_CTRL0        0x2280 /*                           */
#define VS6624_GAMMA_PEAK_R0          0x2282 /*                                */
#define VS6624_GAMMA_PEAK_G0          0x2284 /*                                  */
#define VS6624_GAMMA_PEAK_B0          0x2286 /*                                 */
#define VS6624_GAMMA_UNPEAK_R0        0x2288 /*                                  */
#define VS6624_GAMMA_UNPEAK_G0        0x228A /*                                    */
#define VS6624_GAMMA_UNPEAK_B0        0x228C /*                                   */
/*                             */
#define VS6624_GAMMA_MAN_CTRL1        0x2300 /*                           */
#define VS6624_GAMMA_PEAK_R1          0x2302 /*                                */
#define VS6624_GAMMA_PEAK_G1          0x2304 /*                                  */
#define VS6624_GAMMA_PEAK_B1          0x2306 /*                                 */
#define VS6624_GAMMA_UNPEAK_R1        0x2308 /*                                  */
#define VS6624_GAMMA_UNPEAK_G1        0x230A /*                                    */
#define VS6624_GAMMA_UNPEAK_B1        0x230C /*                                   */
/*               */
#define VS6624_F2B_DISABLE            0x2480 /*                       */
#define VS6624_F2B_BLACK_VAL_MSB      0x2483 /*                 */
#define VS6624_F2B_BLACK_VAL_LSB      0x2484 /*                 */
#define VS6624_F2B_LOW_THR_MSB        0x2487 /*                                */
#define VS6624_F2B_LOW_THR_LSB        0x2488 /*                                */
#define VS6624_F2B_HIGH_THR_MSB       0x248B /*                                 */
#define VS6624_F2B_HIGH_THR_LSB       0x248C /*                                 */
#define VS6624_F2B_MIN_OUT_MSB        0x248F /*                           */
#define VS6624_F2B_MIN_OUT_LSB        0x2490 /*                           */
/*                          */
#define VS6624_CODE_CK_EN             0x2580 /*                   */
#define VS6624_BLANK_FMT              0x2582 /*              */
#define VS6624_SYNC_CODE_SETUP        0x2584 /*                 */
#define VS6624_HSYNC_SETUP            0x2586 /*              */
#define VS6624_VSYNC_SETUP            0x2588 /*              */
#define VS6624_PCLK_SETUP             0x258A /*            */
#define VS6624_PCLK_EN                0x258C /*             */
#define VS6624_OPF_SP_SETUP           0x258E /*                           */
#define VS6624_BLANK_DATA_MSB         0x2590 /*                */
#define VS6624_BLANK_DATA_LSB         0x2592 /*                */
#define VS6624_RGB_SETUP              0x2594 /*           */
#define VS6624_YUV_SETUP              0x2596 /*           */
#define VS6624_VSYNC_RIS_COARSE_H     0x2598 /*                           */
#define VS6624_VSYNC_RIS_COARSE_L     0x259A /*                          */
#define VS6624_VSYNC_RIS_FINE_H       0x259C /*                         */
#define VS6624_VSYNC_RIS_FINE_L       0x259E /*                        */
#define VS6624_VSYNC_FALL_COARSE_H    0x25A0 /*                            */
#define VS6624_VSYNC_FALL_COARSE_L    0x25A2 /*                           */
#define VS6624_VSYNC_FALL_FINE_H      0x25A4 /*                          */
#define VS6624_VSYNC_FALL_FINE_L      0x25A6 /*                         */
#define VS6624_HSYNC_RIS_H            0x25A8 /*                    */
#define VS6624_HSYNC_RIS_L            0x25AA /*                   */
#define VS6624_HSYNC_FALL_H           0x25AC /*                     */
#define VS6624_HSYNC_FALL_L           0x25AE /*                    */
#define VS6624_OUT_IF                 0x25B0 /*                  */
#define VS6624_CCP_EXT_DATA           0x25B2 /*                */
/*               */
#define VS6624_NORA_DISABLE           0x2600 /*                   */
#define VS6624_NORA_USAGE             0x2602 /*       */
#define VS6624_NORA_SPLIT_KN          0x2604 /*          */
#define VS6624_NORA_SPLIT_NI          0x2606 /*          */
#define VS6624_NORA_TIGHT_G           0x2608 /*             */
#define VS6624_NORA_DISABLE_NP        0x260A /*                        */
#define VS6624_NORA_LOW_THR_MSB       0x260D /*                                */
#define VS6624_NORA_LOW_THR_LSB       0x260E /*                                */
#define VS6624_NORA_HIGH_THR_MSB      0x2611 /*                                 */
#define VS6624_NORA_HIGH_THR_LSB      0x2612 /*                                 */
#define VS6624_NORA_MIN_OUT_MSB       0x2615 /*                           */
#define VS6624_NORA_MIN_OUT_LSB       0x2616 /*                           */

#endif
