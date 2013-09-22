#ifndef QDSP5AUDPLAYCMDI_H
#define QDSP5AUDPLAYCMDI_H

/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

       Q D S P 5  A U D I O   P L A Y  T A S K   C O M M A N D S

GENERAL DESCRIPTION
  Command Interface for AUDPLAYTASK on QDSP5

REFERENCES
  None

EXTERNALIZED FUNCTIONS

  audplay_cmd_dec_data_avail
    Send buffer to AUDPLAY task
	
  
Copyright (c) 1992-2009, The Linux Foundation. All rights reserved.

This software is licensed under the terms of the GNU General Public
License version 2, as published by the Free Software Foundation, and
may be copied, distributed, and modified under those terms.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*                                                                           

                                           

                                                                    
                                                              

                                                                                                                  
  
                                                                           */

#define AUDPLAY_CMD_BITSTREAM_DATA_AVAIL		0x0000
#define AUDPLAY_CMD_BITSTREAM_DATA_AVAIL_LEN	\
	sizeof(audplay_cmd_bitstream_data_avail)

/*                                                                 
*/
typedef struct {
  /*          */
  unsigned int cmd_id;        

  /*                                            */
  unsigned int decoder_id;        

  /*                                            */
  unsigned int buf_ptr;    

  /*                                                                        
                             
   */
  unsigned int buf_size;
          
  /*                                                                    
            
  */
  unsigned int partition_number;    

} __attribute__((packed)) audplay_cmd_bitstream_data_avail;

#define AUDPLAY_CMD_HPCM_BUF_CFG 0x0003
#define AUDPLAY_CMD_HPCM_BUF_CFG_LEN \
  sizeof(struct audplay_cmd_hpcm_buf_cfg)

struct audplay_cmd_hpcm_buf_cfg {
  unsigned int cmd_id;
  unsigned int hostpcm_config;
  unsigned int feedback_frequency;
  unsigned int byte_swap;
  unsigned int max_buffers;
  unsigned int partition_number;
} __attribute__((packed));

#define AUDPLAY_CMD_BUFFER_REFRESH 0x0004
#define AUDPLAY_CMD_BUFFER_REFRESH_LEN \
  sizeof(struct audplay_cmd_buffer_update)

struct audplay_cmd_buffer_refresh {
  unsigned int cmd_id;
  unsigned int num_buffers;
  unsigned int buf_read_count;
  unsigned int buf0_address;
  unsigned int buf0_length;
  unsigned int buf1_address;
  unsigned int buf1_length;
} __attribute__((packed));

#define AUDPLAY_CMD_BITSTREAM_DATA_AVAIL_NT2            0x0005
#define AUDPLAY_CMD_BITSTREAM_DATA_AVAIL_NT2_LEN    \
	sizeof(audplay_cmd_bitstream_data_avail_nt2)

/*                                                                 
           */
struct audplay_cmd_bitstream_data_avail_nt2 {
  /*          */
  unsigned int cmd_id;

  /*                                            */
  unsigned int decoder_id;

  /*                                            */
  unsigned int buf_ptr;

  /*                                                                        
                            
   */
  unsigned int buf_size;

  /*                                                                    
           
   */
  unsigned int partition_number;

 /*                         */
  unsigned int dspBitstreamWritePtr;

} __attribute__((packed));

#endif /*                   */
