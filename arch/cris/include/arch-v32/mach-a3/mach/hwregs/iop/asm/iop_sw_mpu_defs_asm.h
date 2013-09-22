#ifndef __iop_sw_mpu_defs_asm_h
#define __iop_sw_mpu_defs_asm_h

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

/*                                                     */
#define reg_iop_sw_mpu_rw_sw_cfg_owner___cfg___lsb 0
#define reg_iop_sw_mpu_rw_sw_cfg_owner___cfg___width 2
#define reg_iop_sw_mpu_rw_sw_cfg_owner_offset 0

/*                                                */
#define reg_iop_sw_mpu_r_spu_trace_offset 4

/*                                                    */
#define reg_iop_sw_mpu_r_spu_fsm_trace_offset 8

/*                                                */
#define reg_iop_sw_mpu_rw_mc_ctrl___keep_owner___lsb 0
#define reg_iop_sw_mpu_rw_mc_ctrl___keep_owner___width 1
#define reg_iop_sw_mpu_rw_mc_ctrl___keep_owner___bit 0
#define reg_iop_sw_mpu_rw_mc_ctrl___cmd___lsb 1
#define reg_iop_sw_mpu_rw_mc_ctrl___cmd___width 2
#define reg_iop_sw_mpu_rw_mc_ctrl___size___lsb 3
#define reg_iop_sw_mpu_rw_mc_ctrl___size___width 3
#define reg_iop_sw_mpu_rw_mc_ctrl___wr_spu_mem___lsb 6
#define reg_iop_sw_mpu_rw_mc_ctrl___wr_spu_mem___width 1
#define reg_iop_sw_mpu_rw_mc_ctrl___wr_spu_mem___bit 6
#define reg_iop_sw_mpu_rw_mc_ctrl_offset 12

/*                                                */
#define reg_iop_sw_mpu_rw_mc_data___val___lsb 0
#define reg_iop_sw_mpu_rw_mc_data___val___width 32
#define reg_iop_sw_mpu_rw_mc_data_offset 16

/*                                                */
#define reg_iop_sw_mpu_rw_mc_addr_offset 20

/*                                                */
#define reg_iop_sw_mpu_rs_mc_data_offset 24

/*                                              */
#define reg_iop_sw_mpu_r_mc_data_offset 28

/*                                              */
#define reg_iop_sw_mpu_r_mc_stat___busy_cpu___lsb 0
#define reg_iop_sw_mpu_r_mc_stat___busy_cpu___width 1
#define reg_iop_sw_mpu_r_mc_stat___busy_cpu___bit 0
#define reg_iop_sw_mpu_r_mc_stat___busy_mpu___lsb 1
#define reg_iop_sw_mpu_r_mc_stat___busy_mpu___width 1
#define reg_iop_sw_mpu_r_mc_stat___busy_mpu___bit 1
#define reg_iop_sw_mpu_r_mc_stat___busy_spu___lsb 2
#define reg_iop_sw_mpu_r_mc_stat___busy_spu___width 1
#define reg_iop_sw_mpu_r_mc_stat___busy_spu___bit 2
#define reg_iop_sw_mpu_r_mc_stat___owned_by_cpu___lsb 3
#define reg_iop_sw_mpu_r_mc_stat___owned_by_cpu___width 1
#define reg_iop_sw_mpu_r_mc_stat___owned_by_cpu___bit 3
#define reg_iop_sw_mpu_r_mc_stat___owned_by_mpu___lsb 4
#define reg_iop_sw_mpu_r_mc_stat___owned_by_mpu___width 1
#define reg_iop_sw_mpu_r_mc_stat___owned_by_mpu___bit 4
#define reg_iop_sw_mpu_r_mc_stat___owned_by_spu___lsb 5
#define reg_iop_sw_mpu_r_mc_stat___owned_by_spu___width 1
#define reg_iop_sw_mpu_r_mc_stat___owned_by_spu___bit 5
#define reg_iop_sw_mpu_r_mc_stat_offset 32

/*                                                     */
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte0___lsb 0
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte0___width 8
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte1___lsb 8
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte1___width 8
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte2___lsb 16
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte2___width 8
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte3___lsb 24
#define reg_iop_sw_mpu_rw_bus_clr_mask___byte3___width 8
#define reg_iop_sw_mpu_rw_bus_clr_mask_offset 36

/*                                                     */
#define reg_iop_sw_mpu_rw_bus_set_mask___byte0___lsb 0
#define reg_iop_sw_mpu_rw_bus_set_mask___byte0___width 8
#define reg_iop_sw_mpu_rw_bus_set_mask___byte1___lsb 8
#define reg_iop_sw_mpu_rw_bus_set_mask___byte1___width 8
#define reg_iop_sw_mpu_rw_bus_set_mask___byte2___lsb 16
#define reg_iop_sw_mpu_rw_bus_set_mask___byte2___width 8
#define reg_iop_sw_mpu_rw_bus_set_mask___byte3___lsb 24
#define reg_iop_sw_mpu_rw_bus_set_mask___byte3___width 8
#define reg_iop_sw_mpu_rw_bus_set_mask_offset 40

/*                                                        */
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte0___lsb 0
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte0___width 1
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte0___bit 0
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte1___lsb 1
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte1___width 1
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte1___bit 1
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte2___lsb 2
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte2___width 1
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte2___bit 2
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte3___lsb 3
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte3___width 1
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask___byte3___bit 3
#define reg_iop_sw_mpu_rw_bus_oe_clr_mask_offset 44

/*                                                        */
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte0___lsb 0
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte0___width 1
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte0___bit 0
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte1___lsb 1
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte1___width 1
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte1___bit 1
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte2___lsb 2
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte2___width 1
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte2___bit 2
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte3___lsb 3
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte3___width 1
#define reg_iop_sw_mpu_rw_bus_oe_set_mask___byte3___bit 3
#define reg_iop_sw_mpu_rw_bus_oe_set_mask_offset 48

/*                                             */
#define reg_iop_sw_mpu_r_bus_in_offset 52

/*                                                     */
#define reg_iop_sw_mpu_rw_gio_clr_mask___val___lsb 0
#define reg_iop_sw_mpu_rw_gio_clr_mask___val___width 32
#define reg_iop_sw_mpu_rw_gio_clr_mask_offset 56

/*                                                     */
#define reg_iop_sw_mpu_rw_gio_set_mask___val___lsb 0
#define reg_iop_sw_mpu_rw_gio_set_mask___val___width 32
#define reg_iop_sw_mpu_rw_gio_set_mask_offset 60

/*                                                        */
#define reg_iop_sw_mpu_rw_gio_oe_clr_mask___val___lsb 0
#define reg_iop_sw_mpu_rw_gio_oe_clr_mask___val___width 32
#define reg_iop_sw_mpu_rw_gio_oe_clr_mask_offset 64

/*                                                        */
#define reg_iop_sw_mpu_rw_gio_oe_set_mask___val___lsb 0
#define reg_iop_sw_mpu_rw_gio_oe_set_mask___val___width 32
#define reg_iop_sw_mpu_rw_gio_oe_set_mask_offset 68

/*                                             */
#define reg_iop_sw_mpu_r_gio_in_offset 72

/*                                                 */
#define reg_iop_sw_mpu_rw_cpu_intr___intr0___lsb 0
#define reg_iop_sw_mpu_rw_cpu_intr___intr0___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr0___bit 0
#define reg_iop_sw_mpu_rw_cpu_intr___intr1___lsb 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr1___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr1___bit 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr2___lsb 2
#define reg_iop_sw_mpu_rw_cpu_intr___intr2___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr2___bit 2
#define reg_iop_sw_mpu_rw_cpu_intr___intr3___lsb 3
#define reg_iop_sw_mpu_rw_cpu_intr___intr3___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr3___bit 3
#define reg_iop_sw_mpu_rw_cpu_intr___intr4___lsb 4
#define reg_iop_sw_mpu_rw_cpu_intr___intr4___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr4___bit 4
#define reg_iop_sw_mpu_rw_cpu_intr___intr5___lsb 5
#define reg_iop_sw_mpu_rw_cpu_intr___intr5___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr5___bit 5
#define reg_iop_sw_mpu_rw_cpu_intr___intr6___lsb 6
#define reg_iop_sw_mpu_rw_cpu_intr___intr6___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr6___bit 6
#define reg_iop_sw_mpu_rw_cpu_intr___intr7___lsb 7
#define reg_iop_sw_mpu_rw_cpu_intr___intr7___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr7___bit 7
#define reg_iop_sw_mpu_rw_cpu_intr___intr8___lsb 8
#define reg_iop_sw_mpu_rw_cpu_intr___intr8___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr8___bit 8
#define reg_iop_sw_mpu_rw_cpu_intr___intr9___lsb 9
#define reg_iop_sw_mpu_rw_cpu_intr___intr9___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr9___bit 9
#define reg_iop_sw_mpu_rw_cpu_intr___intr10___lsb 10
#define reg_iop_sw_mpu_rw_cpu_intr___intr10___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr10___bit 10
#define reg_iop_sw_mpu_rw_cpu_intr___intr11___lsb 11
#define reg_iop_sw_mpu_rw_cpu_intr___intr11___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr11___bit 11
#define reg_iop_sw_mpu_rw_cpu_intr___intr12___lsb 12
#define reg_iop_sw_mpu_rw_cpu_intr___intr12___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr12___bit 12
#define reg_iop_sw_mpu_rw_cpu_intr___intr13___lsb 13
#define reg_iop_sw_mpu_rw_cpu_intr___intr13___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr13___bit 13
#define reg_iop_sw_mpu_rw_cpu_intr___intr14___lsb 14
#define reg_iop_sw_mpu_rw_cpu_intr___intr14___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr14___bit 14
#define reg_iop_sw_mpu_rw_cpu_intr___intr15___lsb 15
#define reg_iop_sw_mpu_rw_cpu_intr___intr15___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr15___bit 15
#define reg_iop_sw_mpu_rw_cpu_intr___intr16___lsb 16
#define reg_iop_sw_mpu_rw_cpu_intr___intr16___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr16___bit 16
#define reg_iop_sw_mpu_rw_cpu_intr___intr17___lsb 17
#define reg_iop_sw_mpu_rw_cpu_intr___intr17___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr17___bit 17
#define reg_iop_sw_mpu_rw_cpu_intr___intr18___lsb 18
#define reg_iop_sw_mpu_rw_cpu_intr___intr18___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr18___bit 18
#define reg_iop_sw_mpu_rw_cpu_intr___intr19___lsb 19
#define reg_iop_sw_mpu_rw_cpu_intr___intr19___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr19___bit 19
#define reg_iop_sw_mpu_rw_cpu_intr___intr20___lsb 20
#define reg_iop_sw_mpu_rw_cpu_intr___intr20___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr20___bit 20
#define reg_iop_sw_mpu_rw_cpu_intr___intr21___lsb 21
#define reg_iop_sw_mpu_rw_cpu_intr___intr21___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr21___bit 21
#define reg_iop_sw_mpu_rw_cpu_intr___intr22___lsb 22
#define reg_iop_sw_mpu_rw_cpu_intr___intr22___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr22___bit 22
#define reg_iop_sw_mpu_rw_cpu_intr___intr23___lsb 23
#define reg_iop_sw_mpu_rw_cpu_intr___intr23___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr23___bit 23
#define reg_iop_sw_mpu_rw_cpu_intr___intr24___lsb 24
#define reg_iop_sw_mpu_rw_cpu_intr___intr24___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr24___bit 24
#define reg_iop_sw_mpu_rw_cpu_intr___intr25___lsb 25
#define reg_iop_sw_mpu_rw_cpu_intr___intr25___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr25___bit 25
#define reg_iop_sw_mpu_rw_cpu_intr___intr26___lsb 26
#define reg_iop_sw_mpu_rw_cpu_intr___intr26___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr26___bit 26
#define reg_iop_sw_mpu_rw_cpu_intr___intr27___lsb 27
#define reg_iop_sw_mpu_rw_cpu_intr___intr27___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr27___bit 27
#define reg_iop_sw_mpu_rw_cpu_intr___intr28___lsb 28
#define reg_iop_sw_mpu_rw_cpu_intr___intr28___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr28___bit 28
#define reg_iop_sw_mpu_rw_cpu_intr___intr29___lsb 29
#define reg_iop_sw_mpu_rw_cpu_intr___intr29___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr29___bit 29
#define reg_iop_sw_mpu_rw_cpu_intr___intr30___lsb 30
#define reg_iop_sw_mpu_rw_cpu_intr___intr30___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr30___bit 30
#define reg_iop_sw_mpu_rw_cpu_intr___intr31___lsb 31
#define reg_iop_sw_mpu_rw_cpu_intr___intr31___width 1
#define reg_iop_sw_mpu_rw_cpu_intr___intr31___bit 31
#define reg_iop_sw_mpu_rw_cpu_intr_offset 76

/*                                               */
#define reg_iop_sw_mpu_r_cpu_intr___intr0___lsb 0
#define reg_iop_sw_mpu_r_cpu_intr___intr0___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr0___bit 0
#define reg_iop_sw_mpu_r_cpu_intr___intr1___lsb 1
#define reg_iop_sw_mpu_r_cpu_intr___intr1___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr1___bit 1
#define reg_iop_sw_mpu_r_cpu_intr___intr2___lsb 2
#define reg_iop_sw_mpu_r_cpu_intr___intr2___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr2___bit 2
#define reg_iop_sw_mpu_r_cpu_intr___intr3___lsb 3
#define reg_iop_sw_mpu_r_cpu_intr___intr3___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr3___bit 3
#define reg_iop_sw_mpu_r_cpu_intr___intr4___lsb 4
#define reg_iop_sw_mpu_r_cpu_intr___intr4___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr4___bit 4
#define reg_iop_sw_mpu_r_cpu_intr___intr5___lsb 5
#define reg_iop_sw_mpu_r_cpu_intr___intr5___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr5___bit 5
#define reg_iop_sw_mpu_r_cpu_intr___intr6___lsb 6
#define reg_iop_sw_mpu_r_cpu_intr___intr6___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr6___bit 6
#define reg_iop_sw_mpu_r_cpu_intr___intr7___lsb 7
#define reg_iop_sw_mpu_r_cpu_intr___intr7___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr7___bit 7
#define reg_iop_sw_mpu_r_cpu_intr___intr8___lsb 8
#define reg_iop_sw_mpu_r_cpu_intr___intr8___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr8___bit 8
#define reg_iop_sw_mpu_r_cpu_intr___intr9___lsb 9
#define reg_iop_sw_mpu_r_cpu_intr___intr9___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr9___bit 9
#define reg_iop_sw_mpu_r_cpu_intr___intr10___lsb 10
#define reg_iop_sw_mpu_r_cpu_intr___intr10___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr10___bit 10
#define reg_iop_sw_mpu_r_cpu_intr___intr11___lsb 11
#define reg_iop_sw_mpu_r_cpu_intr___intr11___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr11___bit 11
#define reg_iop_sw_mpu_r_cpu_intr___intr12___lsb 12
#define reg_iop_sw_mpu_r_cpu_intr___intr12___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr12___bit 12
#define reg_iop_sw_mpu_r_cpu_intr___intr13___lsb 13
#define reg_iop_sw_mpu_r_cpu_intr___intr13___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr13___bit 13
#define reg_iop_sw_mpu_r_cpu_intr___intr14___lsb 14
#define reg_iop_sw_mpu_r_cpu_intr___intr14___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr14___bit 14
#define reg_iop_sw_mpu_r_cpu_intr___intr15___lsb 15
#define reg_iop_sw_mpu_r_cpu_intr___intr15___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr15___bit 15
#define reg_iop_sw_mpu_r_cpu_intr___intr16___lsb 16
#define reg_iop_sw_mpu_r_cpu_intr___intr16___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr16___bit 16
#define reg_iop_sw_mpu_r_cpu_intr___intr17___lsb 17
#define reg_iop_sw_mpu_r_cpu_intr___intr17___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr17___bit 17
#define reg_iop_sw_mpu_r_cpu_intr___intr18___lsb 18
#define reg_iop_sw_mpu_r_cpu_intr___intr18___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr18___bit 18
#define reg_iop_sw_mpu_r_cpu_intr___intr19___lsb 19
#define reg_iop_sw_mpu_r_cpu_intr___intr19___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr19___bit 19
#define reg_iop_sw_mpu_r_cpu_intr___intr20___lsb 20
#define reg_iop_sw_mpu_r_cpu_intr___intr20___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr20___bit 20
#define reg_iop_sw_mpu_r_cpu_intr___intr21___lsb 21
#define reg_iop_sw_mpu_r_cpu_intr___intr21___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr21___bit 21
#define reg_iop_sw_mpu_r_cpu_intr___intr22___lsb 22
#define reg_iop_sw_mpu_r_cpu_intr___intr22___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr22___bit 22
#define reg_iop_sw_mpu_r_cpu_intr___intr23___lsb 23
#define reg_iop_sw_mpu_r_cpu_intr___intr23___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr23___bit 23
#define reg_iop_sw_mpu_r_cpu_intr___intr24___lsb 24
#define reg_iop_sw_mpu_r_cpu_intr___intr24___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr24___bit 24
#define reg_iop_sw_mpu_r_cpu_intr___intr25___lsb 25
#define reg_iop_sw_mpu_r_cpu_intr___intr25___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr25___bit 25
#define reg_iop_sw_mpu_r_cpu_intr___intr26___lsb 26
#define reg_iop_sw_mpu_r_cpu_intr___intr26___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr26___bit 26
#define reg_iop_sw_mpu_r_cpu_intr___intr27___lsb 27
#define reg_iop_sw_mpu_r_cpu_intr___intr27___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr27___bit 27
#define reg_iop_sw_mpu_r_cpu_intr___intr28___lsb 28
#define reg_iop_sw_mpu_r_cpu_intr___intr28___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr28___bit 28
#define reg_iop_sw_mpu_r_cpu_intr___intr29___lsb 29
#define reg_iop_sw_mpu_r_cpu_intr___intr29___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr29___bit 29
#define reg_iop_sw_mpu_r_cpu_intr___intr30___lsb 30
#define reg_iop_sw_mpu_r_cpu_intr___intr30___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr30___bit 30
#define reg_iop_sw_mpu_r_cpu_intr___intr31___lsb 31
#define reg_iop_sw_mpu_r_cpu_intr___intr31___width 1
#define reg_iop_sw_mpu_r_cpu_intr___intr31___bit 31
#define reg_iop_sw_mpu_r_cpu_intr_offset 80

/*                                                       */
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr0___lsb 0
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr0___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr0___bit 0
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp0___lsb 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp0___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp0___bit 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___timer_grp0___lsb 2
#define reg_iop_sw_mpu_rw_intr_grp0_mask___timer_grp0___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___timer_grp0___bit 2
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_out___lsb 3
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_out___bit 3
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr1___lsb 4
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr1___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr1___bit 4
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp1___lsb 5
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp1___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp1___bit 5
#define reg_iop_sw_mpu_rw_intr_grp0_mask___timer_grp1___lsb 6
#define reg_iop_sw_mpu_rw_intr_grp0_mask___timer_grp1___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___timer_grp1___bit 6
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_in___lsb 7
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_in___bit 7
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr2___lsb 8
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr2___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr2___bit 8
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp2___lsb 9
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp2___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp2___bit 9
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_out_extra___lsb 10
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_out_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_out_extra___bit 10
#define reg_iop_sw_mpu_rw_intr_grp0_mask___dmc_out___lsb 11
#define reg_iop_sw_mpu_rw_intr_grp0_mask___dmc_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___dmc_out___bit 11
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr3___lsb 12
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr3___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___spu_intr3___bit 12
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp3___lsb 13
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp3___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___trigger_grp3___bit 13
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_in_extra___lsb 14
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_in_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___fifo_in_extra___bit 14
#define reg_iop_sw_mpu_rw_intr_grp0_mask___dmc_in___lsb 15
#define reg_iop_sw_mpu_rw_intr_grp0_mask___dmc_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp0_mask___dmc_in___bit 15
#define reg_iop_sw_mpu_rw_intr_grp0_mask_offset 84

/*                                                      */
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr0___lsb 0
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr0___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr0___bit 0
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr1___lsb 4
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr1___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr1___bit 4
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr2___lsb 8
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr2___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr2___bit 8
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr3___lsb 12
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr3___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp0___spu_intr3___bit 12
#define reg_iop_sw_mpu_rw_ack_intr_grp0_offset 88

/*                                                */
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr0___lsb 0
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr0___width 1
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr0___bit 0
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp0___lsb 1
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp0___width 1
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp0___bit 1
#define reg_iop_sw_mpu_r_intr_grp0___timer_grp0___lsb 2
#define reg_iop_sw_mpu_r_intr_grp0___timer_grp0___width 1
#define reg_iop_sw_mpu_r_intr_grp0___timer_grp0___bit 2
#define reg_iop_sw_mpu_r_intr_grp0___fifo_out___lsb 3
#define reg_iop_sw_mpu_r_intr_grp0___fifo_out___width 1
#define reg_iop_sw_mpu_r_intr_grp0___fifo_out___bit 3
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr1___lsb 4
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr1___width 1
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr1___bit 4
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp1___lsb 5
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp1___width 1
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp1___bit 5
#define reg_iop_sw_mpu_r_intr_grp0___timer_grp1___lsb 6
#define reg_iop_sw_mpu_r_intr_grp0___timer_grp1___width 1
#define reg_iop_sw_mpu_r_intr_grp0___timer_grp1___bit 6
#define reg_iop_sw_mpu_r_intr_grp0___fifo_in___lsb 7
#define reg_iop_sw_mpu_r_intr_grp0___fifo_in___width 1
#define reg_iop_sw_mpu_r_intr_grp0___fifo_in___bit 7
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr2___lsb 8
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr2___width 1
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr2___bit 8
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp2___lsb 9
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp2___width 1
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp2___bit 9
#define reg_iop_sw_mpu_r_intr_grp0___fifo_out_extra___lsb 10
#define reg_iop_sw_mpu_r_intr_grp0___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp0___fifo_out_extra___bit 10
#define reg_iop_sw_mpu_r_intr_grp0___dmc_out___lsb 11
#define reg_iop_sw_mpu_r_intr_grp0___dmc_out___width 1
#define reg_iop_sw_mpu_r_intr_grp0___dmc_out___bit 11
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr3___lsb 12
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr3___width 1
#define reg_iop_sw_mpu_r_intr_grp0___spu_intr3___bit 12
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp3___lsb 13
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp3___width 1
#define reg_iop_sw_mpu_r_intr_grp0___trigger_grp3___bit 13
#define reg_iop_sw_mpu_r_intr_grp0___fifo_in_extra___lsb 14
#define reg_iop_sw_mpu_r_intr_grp0___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp0___fifo_in_extra___bit 14
#define reg_iop_sw_mpu_r_intr_grp0___dmc_in___lsb 15
#define reg_iop_sw_mpu_r_intr_grp0___dmc_in___width 1
#define reg_iop_sw_mpu_r_intr_grp0___dmc_in___bit 15
#define reg_iop_sw_mpu_r_intr_grp0_offset 92

/*                                                       */
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr0___lsb 0
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr0___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr0___bit 0
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp0___lsb 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp0___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp0___bit 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___timer_grp0___lsb 2
#define reg_iop_sw_mpu_r_masked_intr_grp0___timer_grp0___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___timer_grp0___bit 2
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_out___lsb 3
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_out___bit 3
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr1___lsb 4
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr1___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr1___bit 4
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp1___lsb 5
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp1___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp1___bit 5
#define reg_iop_sw_mpu_r_masked_intr_grp0___timer_grp1___lsb 6
#define reg_iop_sw_mpu_r_masked_intr_grp0___timer_grp1___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___timer_grp1___bit 6
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_in___lsb 7
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_in___bit 7
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr2___lsb 8
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr2___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr2___bit 8
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp2___lsb 9
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp2___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp2___bit 9
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_out_extra___lsb 10
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_out_extra___bit 10
#define reg_iop_sw_mpu_r_masked_intr_grp0___dmc_out___lsb 11
#define reg_iop_sw_mpu_r_masked_intr_grp0___dmc_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___dmc_out___bit 11
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr3___lsb 12
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr3___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___spu_intr3___bit 12
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp3___lsb 13
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp3___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___trigger_grp3___bit 13
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_in_extra___lsb 14
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___fifo_in_extra___bit 14
#define reg_iop_sw_mpu_r_masked_intr_grp0___dmc_in___lsb 15
#define reg_iop_sw_mpu_r_masked_intr_grp0___dmc_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp0___dmc_in___bit 15
#define reg_iop_sw_mpu_r_masked_intr_grp0_offset 96

/*                                                       */
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr4___lsb 0
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr4___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr4___bit 0
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp4___lsb 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp4___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp4___bit 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_out_extra___lsb 2
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_out_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_out_extra___bit 2
#define reg_iop_sw_mpu_rw_intr_grp1_mask___dmc_out___lsb 3
#define reg_iop_sw_mpu_rw_intr_grp1_mask___dmc_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___dmc_out___bit 3
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr5___lsb 4
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr5___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr5___bit 4
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp5___lsb 5
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp5___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp5___bit 5
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_in_extra___lsb 6
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_in_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_in_extra___bit 6
#define reg_iop_sw_mpu_rw_intr_grp1_mask___dmc_in___lsb 7
#define reg_iop_sw_mpu_rw_intr_grp1_mask___dmc_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___dmc_in___bit 7
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr6___lsb 8
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr6___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr6___bit 8
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp6___lsb 9
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp6___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp6___bit 9
#define reg_iop_sw_mpu_rw_intr_grp1_mask___timer_grp0___lsb 10
#define reg_iop_sw_mpu_rw_intr_grp1_mask___timer_grp0___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___timer_grp0___bit 10
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_out___lsb 11
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_out___bit 11
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr7___lsb 12
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr7___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___spu_intr7___bit 12
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp7___lsb 13
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp7___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___trigger_grp7___bit 13
#define reg_iop_sw_mpu_rw_intr_grp1_mask___timer_grp1___lsb 14
#define reg_iop_sw_mpu_rw_intr_grp1_mask___timer_grp1___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___timer_grp1___bit 14
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_in___lsb 15
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp1_mask___fifo_in___bit 15
#define reg_iop_sw_mpu_rw_intr_grp1_mask_offset 100

/*                                                      */
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr4___lsb 0
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr4___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr4___bit 0
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr5___lsb 4
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr5___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr5___bit 4
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr6___lsb 8
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr6___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr6___bit 8
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr7___lsb 12
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr7___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp1___spu_intr7___bit 12
#define reg_iop_sw_mpu_rw_ack_intr_grp1_offset 104

/*                                                */
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr4___lsb 0
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr4___width 1
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr4___bit 0
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp4___lsb 1
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp4___width 1
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp4___bit 1
#define reg_iop_sw_mpu_r_intr_grp1___fifo_out_extra___lsb 2
#define reg_iop_sw_mpu_r_intr_grp1___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp1___fifo_out_extra___bit 2
#define reg_iop_sw_mpu_r_intr_grp1___dmc_out___lsb 3
#define reg_iop_sw_mpu_r_intr_grp1___dmc_out___width 1
#define reg_iop_sw_mpu_r_intr_grp1___dmc_out___bit 3
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr5___lsb 4
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr5___width 1
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr5___bit 4
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp5___lsb 5
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp5___width 1
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp5___bit 5
#define reg_iop_sw_mpu_r_intr_grp1___fifo_in_extra___lsb 6
#define reg_iop_sw_mpu_r_intr_grp1___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp1___fifo_in_extra___bit 6
#define reg_iop_sw_mpu_r_intr_grp1___dmc_in___lsb 7
#define reg_iop_sw_mpu_r_intr_grp1___dmc_in___width 1
#define reg_iop_sw_mpu_r_intr_grp1___dmc_in___bit 7
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr6___lsb 8
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr6___width 1
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr6___bit 8
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp6___lsb 9
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp6___width 1
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp6___bit 9
#define reg_iop_sw_mpu_r_intr_grp1___timer_grp0___lsb 10
#define reg_iop_sw_mpu_r_intr_grp1___timer_grp0___width 1
#define reg_iop_sw_mpu_r_intr_grp1___timer_grp0___bit 10
#define reg_iop_sw_mpu_r_intr_grp1___fifo_out___lsb 11
#define reg_iop_sw_mpu_r_intr_grp1___fifo_out___width 1
#define reg_iop_sw_mpu_r_intr_grp1___fifo_out___bit 11
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr7___lsb 12
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr7___width 1
#define reg_iop_sw_mpu_r_intr_grp1___spu_intr7___bit 12
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp7___lsb 13
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp7___width 1
#define reg_iop_sw_mpu_r_intr_grp1___trigger_grp7___bit 13
#define reg_iop_sw_mpu_r_intr_grp1___timer_grp1___lsb 14
#define reg_iop_sw_mpu_r_intr_grp1___timer_grp1___width 1
#define reg_iop_sw_mpu_r_intr_grp1___timer_grp1___bit 14
#define reg_iop_sw_mpu_r_intr_grp1___fifo_in___lsb 15
#define reg_iop_sw_mpu_r_intr_grp1___fifo_in___width 1
#define reg_iop_sw_mpu_r_intr_grp1___fifo_in___bit 15
#define reg_iop_sw_mpu_r_intr_grp1_offset 108

/*                                                       */
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr4___lsb 0
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr4___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr4___bit 0
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp4___lsb 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp4___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp4___bit 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_out_extra___lsb 2
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_out_extra___bit 2
#define reg_iop_sw_mpu_r_masked_intr_grp1___dmc_out___lsb 3
#define reg_iop_sw_mpu_r_masked_intr_grp1___dmc_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___dmc_out___bit 3
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr5___lsb 4
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr5___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr5___bit 4
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp5___lsb 5
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp5___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp5___bit 5
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_in_extra___lsb 6
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_in_extra___bit 6
#define reg_iop_sw_mpu_r_masked_intr_grp1___dmc_in___lsb 7
#define reg_iop_sw_mpu_r_masked_intr_grp1___dmc_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___dmc_in___bit 7
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr6___lsb 8
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr6___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr6___bit 8
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp6___lsb 9
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp6___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp6___bit 9
#define reg_iop_sw_mpu_r_masked_intr_grp1___timer_grp0___lsb 10
#define reg_iop_sw_mpu_r_masked_intr_grp1___timer_grp0___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___timer_grp0___bit 10
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_out___lsb 11
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_out___bit 11
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr7___lsb 12
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr7___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___spu_intr7___bit 12
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp7___lsb 13
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp7___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___trigger_grp7___bit 13
#define reg_iop_sw_mpu_r_masked_intr_grp1___timer_grp1___lsb 14
#define reg_iop_sw_mpu_r_masked_intr_grp1___timer_grp1___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___timer_grp1___bit 14
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_in___lsb 15
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp1___fifo_in___bit 15
#define reg_iop_sw_mpu_r_masked_intr_grp1_offset 112

/*                                                       */
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr8___lsb 0
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr8___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr8___bit 0
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp0___lsb 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp0___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp0___bit 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___timer_grp0___lsb 2
#define reg_iop_sw_mpu_rw_intr_grp2_mask___timer_grp0___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___timer_grp0___bit 2
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_out___lsb 3
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_out___bit 3
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr9___lsb 4
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr9___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr9___bit 4
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp1___lsb 5
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp1___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp1___bit 5
#define reg_iop_sw_mpu_rw_intr_grp2_mask___timer_grp1___lsb 6
#define reg_iop_sw_mpu_rw_intr_grp2_mask___timer_grp1___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___timer_grp1___bit 6
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_in___lsb 7
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_in___bit 7
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr10___lsb 8
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr10___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr10___bit 8
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp2___lsb 9
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp2___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp2___bit 9
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_out_extra___lsb 10
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_out_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_out_extra___bit 10
#define reg_iop_sw_mpu_rw_intr_grp2_mask___dmc_out___lsb 11
#define reg_iop_sw_mpu_rw_intr_grp2_mask___dmc_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___dmc_out___bit 11
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr11___lsb 12
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr11___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___spu_intr11___bit 12
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp3___lsb 13
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp3___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___trigger_grp3___bit 13
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_in_extra___lsb 14
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_in_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___fifo_in_extra___bit 14
#define reg_iop_sw_mpu_rw_intr_grp2_mask___dmc_in___lsb 15
#define reg_iop_sw_mpu_rw_intr_grp2_mask___dmc_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp2_mask___dmc_in___bit 15
#define reg_iop_sw_mpu_rw_intr_grp2_mask_offset 116

/*                                                      */
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr8___lsb 0
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr8___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr8___bit 0
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr9___lsb 4
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr9___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr9___bit 4
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr10___lsb 8
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr10___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr10___bit 8
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr11___lsb 12
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr11___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp2___spu_intr11___bit 12
#define reg_iop_sw_mpu_rw_ack_intr_grp2_offset 120

/*                                                */
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr8___lsb 0
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr8___width 1
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr8___bit 0
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp0___lsb 1
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp0___width 1
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp0___bit 1
#define reg_iop_sw_mpu_r_intr_grp2___timer_grp0___lsb 2
#define reg_iop_sw_mpu_r_intr_grp2___timer_grp0___width 1
#define reg_iop_sw_mpu_r_intr_grp2___timer_grp0___bit 2
#define reg_iop_sw_mpu_r_intr_grp2___fifo_out___lsb 3
#define reg_iop_sw_mpu_r_intr_grp2___fifo_out___width 1
#define reg_iop_sw_mpu_r_intr_grp2___fifo_out___bit 3
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr9___lsb 4
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr9___width 1
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr9___bit 4
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp1___lsb 5
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp1___width 1
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp1___bit 5
#define reg_iop_sw_mpu_r_intr_grp2___timer_grp1___lsb 6
#define reg_iop_sw_mpu_r_intr_grp2___timer_grp1___width 1
#define reg_iop_sw_mpu_r_intr_grp2___timer_grp1___bit 6
#define reg_iop_sw_mpu_r_intr_grp2___fifo_in___lsb 7
#define reg_iop_sw_mpu_r_intr_grp2___fifo_in___width 1
#define reg_iop_sw_mpu_r_intr_grp2___fifo_in___bit 7
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr10___lsb 8
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr10___width 1
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr10___bit 8
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp2___lsb 9
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp2___width 1
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp2___bit 9
#define reg_iop_sw_mpu_r_intr_grp2___fifo_out_extra___lsb 10
#define reg_iop_sw_mpu_r_intr_grp2___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp2___fifo_out_extra___bit 10
#define reg_iop_sw_mpu_r_intr_grp2___dmc_out___lsb 11
#define reg_iop_sw_mpu_r_intr_grp2___dmc_out___width 1
#define reg_iop_sw_mpu_r_intr_grp2___dmc_out___bit 11
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr11___lsb 12
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr11___width 1
#define reg_iop_sw_mpu_r_intr_grp2___spu_intr11___bit 12
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp3___lsb 13
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp3___width 1
#define reg_iop_sw_mpu_r_intr_grp2___trigger_grp3___bit 13
#define reg_iop_sw_mpu_r_intr_grp2___fifo_in_extra___lsb 14
#define reg_iop_sw_mpu_r_intr_grp2___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp2___fifo_in_extra___bit 14
#define reg_iop_sw_mpu_r_intr_grp2___dmc_in___lsb 15
#define reg_iop_sw_mpu_r_intr_grp2___dmc_in___width 1
#define reg_iop_sw_mpu_r_intr_grp2___dmc_in___bit 15
#define reg_iop_sw_mpu_r_intr_grp2_offset 124

/*                                                       */
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr8___lsb 0
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr8___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr8___bit 0
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp0___lsb 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp0___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp0___bit 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___timer_grp0___lsb 2
#define reg_iop_sw_mpu_r_masked_intr_grp2___timer_grp0___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___timer_grp0___bit 2
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_out___lsb 3
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_out___bit 3
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr9___lsb 4
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr9___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr9___bit 4
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp1___lsb 5
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp1___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp1___bit 5
#define reg_iop_sw_mpu_r_masked_intr_grp2___timer_grp1___lsb 6
#define reg_iop_sw_mpu_r_masked_intr_grp2___timer_grp1___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___timer_grp1___bit 6
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_in___lsb 7
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_in___bit 7
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr10___lsb 8
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr10___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr10___bit 8
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp2___lsb 9
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp2___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp2___bit 9
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_out_extra___lsb 10
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_out_extra___bit 10
#define reg_iop_sw_mpu_r_masked_intr_grp2___dmc_out___lsb 11
#define reg_iop_sw_mpu_r_masked_intr_grp2___dmc_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___dmc_out___bit 11
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr11___lsb 12
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr11___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___spu_intr11___bit 12
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp3___lsb 13
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp3___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___trigger_grp3___bit 13
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_in_extra___lsb 14
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___fifo_in_extra___bit 14
#define reg_iop_sw_mpu_r_masked_intr_grp2___dmc_in___lsb 15
#define reg_iop_sw_mpu_r_masked_intr_grp2___dmc_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp2___dmc_in___bit 15
#define reg_iop_sw_mpu_r_masked_intr_grp2_offset 128

/*                                                       */
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr12___lsb 0
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr12___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr12___bit 0
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp4___lsb 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp4___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp4___bit 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_out_extra___lsb 2
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_out_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_out_extra___bit 2
#define reg_iop_sw_mpu_rw_intr_grp3_mask___dmc_out___lsb 3
#define reg_iop_sw_mpu_rw_intr_grp3_mask___dmc_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___dmc_out___bit 3
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr13___lsb 4
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr13___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr13___bit 4
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp5___lsb 5
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp5___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp5___bit 5
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_in_extra___lsb 6
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_in_extra___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_in_extra___bit 6
#define reg_iop_sw_mpu_rw_intr_grp3_mask___dmc_in___lsb 7
#define reg_iop_sw_mpu_rw_intr_grp3_mask___dmc_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___dmc_in___bit 7
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr14___lsb 8
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr14___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr14___bit 8
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp6___lsb 9
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp6___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp6___bit 9
#define reg_iop_sw_mpu_rw_intr_grp3_mask___timer_grp0___lsb 10
#define reg_iop_sw_mpu_rw_intr_grp3_mask___timer_grp0___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___timer_grp0___bit 10
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_out___lsb 11
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_out___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_out___bit 11
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr15___lsb 12
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr15___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___spu_intr15___bit 12
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp7___lsb 13
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp7___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___trigger_grp7___bit 13
#define reg_iop_sw_mpu_rw_intr_grp3_mask___timer_grp1___lsb 14
#define reg_iop_sw_mpu_rw_intr_grp3_mask___timer_grp1___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___timer_grp1___bit 14
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_in___lsb 15
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_in___width 1
#define reg_iop_sw_mpu_rw_intr_grp3_mask___fifo_in___bit 15
#define reg_iop_sw_mpu_rw_intr_grp3_mask_offset 132

/*                                                      */
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr12___lsb 0
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr12___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr12___bit 0
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr13___lsb 4
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr13___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr13___bit 4
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr14___lsb 8
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr14___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr14___bit 8
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr15___lsb 12
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr15___width 1
#define reg_iop_sw_mpu_rw_ack_intr_grp3___spu_intr15___bit 12
#define reg_iop_sw_mpu_rw_ack_intr_grp3_offset 136

/*                                                */
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr12___lsb 0
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr12___width 1
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr12___bit 0
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp4___lsb 1
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp4___width 1
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp4___bit 1
#define reg_iop_sw_mpu_r_intr_grp3___fifo_out_extra___lsb 2
#define reg_iop_sw_mpu_r_intr_grp3___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp3___fifo_out_extra___bit 2
#define reg_iop_sw_mpu_r_intr_grp3___dmc_out___lsb 3
#define reg_iop_sw_mpu_r_intr_grp3___dmc_out___width 1
#define reg_iop_sw_mpu_r_intr_grp3___dmc_out___bit 3
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr13___lsb 4
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr13___width 1
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr13___bit 4
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp5___lsb 5
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp5___width 1
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp5___bit 5
#define reg_iop_sw_mpu_r_intr_grp3___fifo_in_extra___lsb 6
#define reg_iop_sw_mpu_r_intr_grp3___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_intr_grp3___fifo_in_extra___bit 6
#define reg_iop_sw_mpu_r_intr_grp3___dmc_in___lsb 7
#define reg_iop_sw_mpu_r_intr_grp3___dmc_in___width 1
#define reg_iop_sw_mpu_r_intr_grp3___dmc_in___bit 7
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr14___lsb 8
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr14___width 1
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr14___bit 8
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp6___lsb 9
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp6___width 1
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp6___bit 9
#define reg_iop_sw_mpu_r_intr_grp3___timer_grp0___lsb 10
#define reg_iop_sw_mpu_r_intr_grp3___timer_grp0___width 1
#define reg_iop_sw_mpu_r_intr_grp3___timer_grp0___bit 10
#define reg_iop_sw_mpu_r_intr_grp3___fifo_out___lsb 11
#define reg_iop_sw_mpu_r_intr_grp3___fifo_out___width 1
#define reg_iop_sw_mpu_r_intr_grp3___fifo_out___bit 11
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr15___lsb 12
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr15___width 1
#define reg_iop_sw_mpu_r_intr_grp3___spu_intr15___bit 12
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp7___lsb 13
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp7___width 1
#define reg_iop_sw_mpu_r_intr_grp3___trigger_grp7___bit 13
#define reg_iop_sw_mpu_r_intr_grp3___timer_grp1___lsb 14
#define reg_iop_sw_mpu_r_intr_grp3___timer_grp1___width 1
#define reg_iop_sw_mpu_r_intr_grp3___timer_grp1___bit 14
#define reg_iop_sw_mpu_r_intr_grp3___fifo_in___lsb 15
#define reg_iop_sw_mpu_r_intr_grp3___fifo_in___width 1
#define reg_iop_sw_mpu_r_intr_grp3___fifo_in___bit 15
#define reg_iop_sw_mpu_r_intr_grp3_offset 140

/*                                                       */
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr12___lsb 0
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr12___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr12___bit 0
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp4___lsb 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp4___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp4___bit 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_out_extra___lsb 2
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_out_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_out_extra___bit 2
#define reg_iop_sw_mpu_r_masked_intr_grp3___dmc_out___lsb 3
#define reg_iop_sw_mpu_r_masked_intr_grp3___dmc_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___dmc_out___bit 3
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr13___lsb 4
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr13___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr13___bit 4
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp5___lsb 5
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp5___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp5___bit 5
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_in_extra___lsb 6
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_in_extra___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_in_extra___bit 6
#define reg_iop_sw_mpu_r_masked_intr_grp3___dmc_in___lsb 7
#define reg_iop_sw_mpu_r_masked_intr_grp3___dmc_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___dmc_in___bit 7
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr14___lsb 8
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr14___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr14___bit 8
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp6___lsb 9
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp6___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp6___bit 9
#define reg_iop_sw_mpu_r_masked_intr_grp3___timer_grp0___lsb 10
#define reg_iop_sw_mpu_r_masked_intr_grp3___timer_grp0___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___timer_grp0___bit 10
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_out___lsb 11
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_out___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_out___bit 11
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr15___lsb 12
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr15___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___spu_intr15___bit 12
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp7___lsb 13
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp7___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___trigger_grp7___bit 13
#define reg_iop_sw_mpu_r_masked_intr_grp3___timer_grp1___lsb 14
#define reg_iop_sw_mpu_r_masked_intr_grp3___timer_grp1___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___timer_grp1___bit 14
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_in___lsb 15
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_in___width 1
#define reg_iop_sw_mpu_r_masked_intr_grp3___fifo_in___bit 15
#define reg_iop_sw_mpu_r_masked_intr_grp3_offset 144


/*           */
#define regk_iop_sw_mpu_copy                      0x00000000
#define regk_iop_sw_mpu_cpu                       0x00000000
#define regk_iop_sw_mpu_mpu                       0x00000001
#define regk_iop_sw_mpu_no                        0x00000000
#define regk_iop_sw_mpu_nop                       0x00000000
#define regk_iop_sw_mpu_rd                        0x00000002
#define regk_iop_sw_mpu_reg_copy                  0x00000001
#define regk_iop_sw_mpu_rw_bus_clr_mask_default   0x00000000
#define regk_iop_sw_mpu_rw_bus_oe_clr_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_bus_oe_set_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_bus_set_mask_default   0x00000000
#define regk_iop_sw_mpu_rw_gio_clr_mask_default   0x00000000
#define regk_iop_sw_mpu_rw_gio_oe_clr_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_gio_oe_set_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_gio_set_mask_default   0x00000000
#define regk_iop_sw_mpu_rw_intr_grp0_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_intr_grp1_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_intr_grp2_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_intr_grp3_mask_default  0x00000000
#define regk_iop_sw_mpu_rw_sw_cfg_owner_default   0x00000000
#define regk_iop_sw_mpu_set                       0x00000001
#define regk_iop_sw_mpu_spu                       0x00000002
#define regk_iop_sw_mpu_wr                        0x00000003
#define regk_iop_sw_mpu_yes                       0x00000001
#endif /*                         */
