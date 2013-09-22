#ifndef __iop_dmc_out_defs_asm_h
#define __iop_dmc_out_defs_asm_h

/*
                                  
                                                         
                                                                          
                                             
  
                                                                                                                            
                                                                               
                                 
  
                              
 */

#ifndef REG_FIELD
#define REG_FIELD( scope, reg, field, value ) \
  REG_FIELD_X_( value, reg_##scope##_##reg##___##field##___lsb )
#define REG_FIELD_X_( value, shift ) ((value) << shift)
#endif

#ifndef REG_STATE
#define REG_STATE( scope, reg, field, symbolic_value ) \
  REG_STATE_X_( regk_##scope##_##symbolic_value, reg_##scope##_##reg##___##field##___lsb )
#define REG_STATE_X_( k, shift ) (k << shift)
#endif

#ifndef REG_MASK
#define REG_MASK( scope, reg, field ) \
  REG_MASK_X_( reg_##scope##_##reg##___##field##___width, reg_##scope##_##reg##___##field##___lsb )
#define REG_MASK_X_( width, lsb ) (((1 << width)-1) << lsb)
#endif

#ifndef REG_LSB
#define REG_LSB( scope, reg, field ) reg_##scope##_##reg##___##field##___lsb
#endif

#ifndef REG_BIT
#define REG_BIT( scope, reg, field ) reg_##scope##_##reg##___##field##___bit
#endif

#ifndef REG_ADDR
#define REG_ADDR( scope, inst, reg ) REG_ADDR_X_(inst, reg_##scope##_##reg##_offset)
#define REG_ADDR_X_( inst, offs ) ((inst) + offs)
#endif

#ifndef REG_ADDR_VECT
#define REG_ADDR_VECT( scope, inst, reg, index ) \
         REG_ADDR_VECT_X_(inst, reg_##scope##_##reg##_offset, index, \
			 STRIDE_##scope##_##reg )
#define REG_ADDR_VECT_X_( inst, offs, index, stride ) \
                          ((inst) + offs + (index) * stride)
#endif

/*                                             */
#define reg_iop_dmc_out_rw_cfg___trf_lim___lsb 0
#define reg_iop_dmc_out_rw_cfg___trf_lim___width 16
#define reg_iop_dmc_out_rw_cfg___last_at_trf_lim___lsb 16
#define reg_iop_dmc_out_rw_cfg___last_at_trf_lim___width 1
#define reg_iop_dmc_out_rw_cfg___last_at_trf_lim___bit 16
#define reg_iop_dmc_out_rw_cfg___dth_intr___lsb 17
#define reg_iop_dmc_out_rw_cfg___dth_intr___width 3
#define reg_iop_dmc_out_rw_cfg_offset 0

/*                                              */
#define reg_iop_dmc_out_rw_ctrl___dif_en___lsb 0
#define reg_iop_dmc_out_rw_ctrl___dif_en___width 1
#define reg_iop_dmc_out_rw_ctrl___dif_en___bit 0
#define reg_iop_dmc_out_rw_ctrl___dif_dis___lsb 1
#define reg_iop_dmc_out_rw_ctrl___dif_dis___width 1
#define reg_iop_dmc_out_rw_ctrl___dif_dis___bit 1
#define reg_iop_dmc_out_rw_ctrl_offset 4

/*                                            */
#define reg_iop_dmc_out_r_stat___dif_en___lsb 0
#define reg_iop_dmc_out_r_stat___dif_en___width 1
#define reg_iop_dmc_out_r_stat___dif_en___bit 0
#define reg_iop_dmc_out_r_stat_offset 8

/*                                                    */
#define reg_iop_dmc_out_rw_stream_cmd___cmd___lsb 0
#define reg_iop_dmc_out_rw_stream_cmd___cmd___width 10
#define reg_iop_dmc_out_rw_stream_cmd___n___lsb 16
#define reg_iop_dmc_out_rw_stream_cmd___n___width 8
#define reg_iop_dmc_out_rw_stream_cmd_offset 12

/*                                                     */
#define reg_iop_dmc_out_rs_stream_data_offset 16

/*                                                   */
#define reg_iop_dmc_out_r_stream_data_offset 20

/*                                                   */
#define reg_iop_dmc_out_r_stream_stat___dth___lsb 0
#define reg_iop_dmc_out_r_stream_stat___dth___width 7
#define reg_iop_dmc_out_r_stream_stat___dv___lsb 16
#define reg_iop_dmc_out_r_stream_stat___dv___width 1
#define reg_iop_dmc_out_r_stream_stat___dv___bit 16
#define reg_iop_dmc_out_r_stream_stat___all_avail___lsb 17
#define reg_iop_dmc_out_r_stream_stat___all_avail___width 1
#define reg_iop_dmc_out_r_stream_stat___all_avail___bit 17
#define reg_iop_dmc_out_r_stream_stat___last___lsb 18
#define reg_iop_dmc_out_r_stream_stat___last___width 1
#define reg_iop_dmc_out_r_stream_stat___last___bit 18
#define reg_iop_dmc_out_r_stream_stat___size___lsb 19
#define reg_iop_dmc_out_r_stream_stat___size___width 3
#define reg_iop_dmc_out_r_stream_stat___data_md_valid___lsb 22
#define reg_iop_dmc_out_r_stream_stat___data_md_valid___width 1
#define reg_iop_dmc_out_r_stream_stat___data_md_valid___bit 22
#define reg_iop_dmc_out_r_stream_stat___ctxt_md_valid___lsb 23
#define reg_iop_dmc_out_r_stream_stat___ctxt_md_valid___width 1
#define reg_iop_dmc_out_r_stream_stat___ctxt_md_valid___bit 23
#define reg_iop_dmc_out_r_stream_stat___group_md_valid___lsb 24
#define reg_iop_dmc_out_r_stream_stat___group_md_valid___width 1
#define reg_iop_dmc_out_r_stream_stat___group_md_valid___bit 24
#define reg_iop_dmc_out_r_stream_stat___stream_busy___lsb 25
#define reg_iop_dmc_out_r_stream_stat___stream_busy___width 1
#define reg_iop_dmc_out_r_stream_stat___stream_busy___bit 25
#define reg_iop_dmc_out_r_stream_stat___cmd_rdy___lsb 26
#define reg_iop_dmc_out_r_stream_stat___cmd_rdy___width 1
#define reg_iop_dmc_out_r_stream_stat___cmd_rdy___bit 26
#define reg_iop_dmc_out_r_stream_stat___cmd_rq___lsb 27
#define reg_iop_dmc_out_r_stream_stat___cmd_rq___width 1
#define reg_iop_dmc_out_r_stream_stat___cmd_rq___bit 27
#define reg_iop_dmc_out_r_stream_stat_offset 24

/*                                                  */
#define reg_iop_dmc_out_r_data_descr___ctrl___lsb 0
#define reg_iop_dmc_out_r_data_descr___ctrl___width 8
#define reg_iop_dmc_out_r_data_descr___stat___lsb 8
#define reg_iop_dmc_out_r_data_descr___stat___width 8
#define reg_iop_dmc_out_r_data_descr___md___lsb 16
#define reg_iop_dmc_out_r_data_descr___md___width 16
#define reg_iop_dmc_out_r_data_descr_offset 28

/*                                                  */
#define reg_iop_dmc_out_r_ctxt_descr___ctrl___lsb 0
#define reg_iop_dmc_out_r_ctxt_descr___ctrl___width 8
#define reg_iop_dmc_out_r_ctxt_descr___stat___lsb 8
#define reg_iop_dmc_out_r_ctxt_descr___stat___width 8
#define reg_iop_dmc_out_r_ctxt_descr___md0___lsb 16
#define reg_iop_dmc_out_r_ctxt_descr___md0___width 16
#define reg_iop_dmc_out_r_ctxt_descr_offset 32

/*                                                      */
#define reg_iop_dmc_out_r_ctxt_descr_md1_offset 36

/*                                                      */
#define reg_iop_dmc_out_r_ctxt_descr_md2_offset 40

/*                                                   */
#define reg_iop_dmc_out_r_group_descr___ctrl___lsb 0
#define reg_iop_dmc_out_r_group_descr___ctrl___width 8
#define reg_iop_dmc_out_r_group_descr___stat___lsb 8
#define reg_iop_dmc_out_r_group_descr___stat___width 8
#define reg_iop_dmc_out_r_group_descr___md___lsb 16
#define reg_iop_dmc_out_r_group_descr___md___width 16
#define reg_iop_dmc_out_r_group_descr_offset 52

/*                                                    */
#define reg_iop_dmc_out_rw_data_descr___md___lsb 16
#define reg_iop_dmc_out_rw_data_descr___md___width 16
#define reg_iop_dmc_out_rw_data_descr_offset 56

/*                                                    */
#define reg_iop_dmc_out_rw_ctxt_descr___md0___lsb 16
#define reg_iop_dmc_out_rw_ctxt_descr___md0___width 16
#define reg_iop_dmc_out_rw_ctxt_descr_offset 60

/*                                                        */
#define reg_iop_dmc_out_rw_ctxt_descr_md1_offset 64

/*                                                        */
#define reg_iop_dmc_out_rw_ctxt_descr_md2_offset 68

/*                                                     */
#define reg_iop_dmc_out_rw_group_descr___md___lsb 16
#define reg_iop_dmc_out_rw_group_descr___md___width 16
#define reg_iop_dmc_out_rw_group_descr_offset 80

/*                                                   */
#define reg_iop_dmc_out_rw_intr_mask___data_md___lsb 0
#define reg_iop_dmc_out_rw_intr_mask___data_md___width 1
#define reg_iop_dmc_out_rw_intr_mask___data_md___bit 0
#define reg_iop_dmc_out_rw_intr_mask___ctxt_md___lsb 1
#define reg_iop_dmc_out_rw_intr_mask___ctxt_md___width 1
#define reg_iop_dmc_out_rw_intr_mask___ctxt_md___bit 1
#define reg_iop_dmc_out_rw_intr_mask___group_md___lsb 2
#define reg_iop_dmc_out_rw_intr_mask___group_md___width 1
#define reg_iop_dmc_out_rw_intr_mask___group_md___bit 2
#define reg_iop_dmc_out_rw_intr_mask___cmd_rdy___lsb 3
#define reg_iop_dmc_out_rw_intr_mask___cmd_rdy___width 1
#define reg_iop_dmc_out_rw_intr_mask___cmd_rdy___bit 3
#define reg_iop_dmc_out_rw_intr_mask___dth___lsb 4
#define reg_iop_dmc_out_rw_intr_mask___dth___width 1
#define reg_iop_dmc_out_rw_intr_mask___dth___bit 4
#define reg_iop_dmc_out_rw_intr_mask___dv___lsb 5
#define reg_iop_dmc_out_rw_intr_mask___dv___width 1
#define reg_iop_dmc_out_rw_intr_mask___dv___bit 5
#define reg_iop_dmc_out_rw_intr_mask___last_data___lsb 6
#define reg_iop_dmc_out_rw_intr_mask___last_data___width 1
#define reg_iop_dmc_out_rw_intr_mask___last_data___bit 6
#define reg_iop_dmc_out_rw_intr_mask___trf_lim___lsb 7
#define reg_iop_dmc_out_rw_intr_mask___trf_lim___width 1
#define reg_iop_dmc_out_rw_intr_mask___trf_lim___bit 7
#define reg_iop_dmc_out_rw_intr_mask___cmd_rq___lsb 8
#define reg_iop_dmc_out_rw_intr_mask___cmd_rq___width 1
#define reg_iop_dmc_out_rw_intr_mask___cmd_rq___bit 8
#define reg_iop_dmc_out_rw_intr_mask_offset 84

/*                                                  */
#define reg_iop_dmc_out_rw_ack_intr___data_md___lsb 0
#define reg_iop_dmc_out_rw_ack_intr___data_md___width 1
#define reg_iop_dmc_out_rw_ack_intr___data_md___bit 0
#define reg_iop_dmc_out_rw_ack_intr___ctxt_md___lsb 1
#define reg_iop_dmc_out_rw_ack_intr___ctxt_md___width 1
#define reg_iop_dmc_out_rw_ack_intr___ctxt_md___bit 1
#define reg_iop_dmc_out_rw_ack_intr___group_md___lsb 2
#define reg_iop_dmc_out_rw_ack_intr___group_md___width 1
#define reg_iop_dmc_out_rw_ack_intr___group_md___bit 2
#define reg_iop_dmc_out_rw_ack_intr___cmd_rdy___lsb 3
#define reg_iop_dmc_out_rw_ack_intr___cmd_rdy___width 1
#define reg_iop_dmc_out_rw_ack_intr___cmd_rdy___bit 3
#define reg_iop_dmc_out_rw_ack_intr___dth___lsb 4
#define reg_iop_dmc_out_rw_ack_intr___dth___width 1
#define reg_iop_dmc_out_rw_ack_intr___dth___bit 4
#define reg_iop_dmc_out_rw_ack_intr___dv___lsb 5
#define reg_iop_dmc_out_rw_ack_intr___dv___width 1
#define reg_iop_dmc_out_rw_ack_intr___dv___bit 5
#define reg_iop_dmc_out_rw_ack_intr___last_data___lsb 6
#define reg_iop_dmc_out_rw_ack_intr___last_data___width 1
#define reg_iop_dmc_out_rw_ack_intr___last_data___bit 6
#define reg_iop_dmc_out_rw_ack_intr___trf_lim___lsb 7
#define reg_iop_dmc_out_rw_ack_intr___trf_lim___width 1
#define reg_iop_dmc_out_rw_ack_intr___trf_lim___bit 7
#define reg_iop_dmc_out_rw_ack_intr___cmd_rq___lsb 8
#define reg_iop_dmc_out_rw_ack_intr___cmd_rq___width 1
#define reg_iop_dmc_out_rw_ack_intr___cmd_rq___bit 8
#define reg_iop_dmc_out_rw_ack_intr_offset 88

/*                                            */
#define reg_iop_dmc_out_r_intr___data_md___lsb 0
#define reg_iop_dmc_out_r_intr___data_md___width 1
#define reg_iop_dmc_out_r_intr___data_md___bit 0
#define reg_iop_dmc_out_r_intr___ctxt_md___lsb 1
#define reg_iop_dmc_out_r_intr___ctxt_md___width 1
#define reg_iop_dmc_out_r_intr___ctxt_md___bit 1
#define reg_iop_dmc_out_r_intr___group_md___lsb 2
#define reg_iop_dmc_out_r_intr___group_md___width 1
#define reg_iop_dmc_out_r_intr___group_md___bit 2
#define reg_iop_dmc_out_r_intr___cmd_rdy___lsb 3
#define reg_iop_dmc_out_r_intr___cmd_rdy___width 1
#define reg_iop_dmc_out_r_intr___cmd_rdy___bit 3
#define reg_iop_dmc_out_r_intr___dth___lsb 4
#define reg_iop_dmc_out_r_intr___dth___width 1
#define reg_iop_dmc_out_r_intr___dth___bit 4
#define reg_iop_dmc_out_r_intr___dv___lsb 5
#define reg_iop_dmc_out_r_intr___dv___width 1
#define reg_iop_dmc_out_r_intr___dv___bit 5
#define reg_iop_dmc_out_r_intr___last_data___lsb 6
#define reg_iop_dmc_out_r_intr___last_data___width 1
#define reg_iop_dmc_out_r_intr___last_data___bit 6
#define reg_iop_dmc_out_r_intr___trf_lim___lsb 7
#define reg_iop_dmc_out_r_intr___trf_lim___width 1
#define reg_iop_dmc_out_r_intr___trf_lim___bit 7
#define reg_iop_dmc_out_r_intr___cmd_rq___lsb 8
#define reg_iop_dmc_out_r_intr___cmd_rq___width 1
#define reg_iop_dmc_out_r_intr___cmd_rq___bit 8
#define reg_iop_dmc_out_r_intr_offset 92

/*                                                   */
#define reg_iop_dmc_out_r_masked_intr___data_md___lsb 0
#define reg_iop_dmc_out_r_masked_intr___data_md___width 1
#define reg_iop_dmc_out_r_masked_intr___data_md___bit 0
#define reg_iop_dmc_out_r_masked_intr___ctxt_md___lsb 1
#define reg_iop_dmc_out_r_masked_intr___ctxt_md___width 1
#define reg_iop_dmc_out_r_masked_intr___ctxt_md___bit 1
#define reg_iop_dmc_out_r_masked_intr___group_md___lsb 2
#define reg_iop_dmc_out_r_masked_intr___group_md___width 1
#define reg_iop_dmc_out_r_masked_intr___group_md___bit 2
#define reg_iop_dmc_out_r_masked_intr___cmd_rdy___lsb 3
#define reg_iop_dmc_out_r_masked_intr___cmd_rdy___width 1
#define reg_iop_dmc_out_r_masked_intr___cmd_rdy___bit 3
#define reg_iop_dmc_out_r_masked_intr___dth___lsb 4
#define reg_iop_dmc_out_r_masked_intr___dth___width 1
#define reg_iop_dmc_out_r_masked_intr___dth___bit 4
#define reg_iop_dmc_out_r_masked_intr___dv___lsb 5
#define reg_iop_dmc_out_r_masked_intr___dv___width 1
#define reg_iop_dmc_out_r_masked_intr___dv___bit 5
#define reg_iop_dmc_out_r_masked_intr___last_data___lsb 6
#define reg_iop_dmc_out_r_masked_intr___last_data___width 1
#define reg_iop_dmc_out_r_masked_intr___last_data___bit 6
#define reg_iop_dmc_out_r_masked_intr___trf_lim___lsb 7
#define reg_iop_dmc_out_r_masked_intr___trf_lim___width 1
#define reg_iop_dmc_out_r_masked_intr___trf_lim___bit 7
#define reg_iop_dmc_out_r_masked_intr___cmd_rq___lsb 8
#define reg_iop_dmc_out_r_masked_intr___cmd_rq___width 1
#define reg_iop_dmc_out_r_masked_intr___cmd_rq___bit 8
#define reg_iop_dmc_out_r_masked_intr_offset 96


/*           */
#define regk_iop_dmc_out_ack_pkt                  0x00000100
#define regk_iop_dmc_out_array                    0x00000008
#define regk_iop_dmc_out_burst                    0x00000020
#define regk_iop_dmc_out_copy_next                0x00000010
#define regk_iop_dmc_out_copy_up                  0x00000020
#define regk_iop_dmc_out_dis_c                    0x00000010
#define regk_iop_dmc_out_dis_g                    0x00000020
#define regk_iop_dmc_out_lim1                     0x00000000
#define regk_iop_dmc_out_lim16                    0x00000004
#define regk_iop_dmc_out_lim2                     0x00000001
#define regk_iop_dmc_out_lim32                    0x00000005
#define regk_iop_dmc_out_lim4                     0x00000002
#define regk_iop_dmc_out_lim64                    0x00000006
#define regk_iop_dmc_out_lim8                     0x00000003
#define regk_iop_dmc_out_load_c                   0x00000200
#define regk_iop_dmc_out_load_c_n                 0x00000280
#define regk_iop_dmc_out_load_c_next              0x00000240
#define regk_iop_dmc_out_load_d                   0x00000140
#define regk_iop_dmc_out_load_g                   0x00000300
#define regk_iop_dmc_out_load_g_down              0x000003c0
#define regk_iop_dmc_out_load_g_next              0x00000340
#define regk_iop_dmc_out_load_g_up                0x00000380
#define regk_iop_dmc_out_next_en                  0x00000010
#define regk_iop_dmc_out_next_pkt                 0x00000010
#define regk_iop_dmc_out_no                       0x00000000
#define regk_iop_dmc_out_restore                  0x00000020
#define regk_iop_dmc_out_rw_cfg_default           0x00000000
#define regk_iop_dmc_out_rw_ctxt_descr_default    0x00000000
#define regk_iop_dmc_out_rw_ctxt_descr_md1_default  0x00000000
#define regk_iop_dmc_out_rw_ctxt_descr_md2_default  0x00000000
#define regk_iop_dmc_out_rw_data_descr_default    0x00000000
#define regk_iop_dmc_out_rw_group_descr_default   0x00000000
#define regk_iop_dmc_out_rw_intr_mask_default     0x00000000
#define regk_iop_dmc_out_save_down                0x00000020
#define regk_iop_dmc_out_save_up                  0x00000020
#define regk_iop_dmc_out_set_reg                  0x00000050
#define regk_iop_dmc_out_set_w_size1              0x00000190
#define regk_iop_dmc_out_set_w_size2              0x000001a0
#define regk_iop_dmc_out_set_w_size4              0x000001c0
#define regk_iop_dmc_out_store_c                  0x00000002
#define regk_iop_dmc_out_store_descr              0x00000000
#define regk_iop_dmc_out_store_g                  0x00000004
#define regk_iop_dmc_out_store_md                 0x00000001
#define regk_iop_dmc_out_update_down              0x00000020
#define regk_iop_dmc_out_yes                      0x00000001
#endif /*                          */
