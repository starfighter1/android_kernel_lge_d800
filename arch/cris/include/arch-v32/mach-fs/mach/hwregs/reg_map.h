#ifndef __reg_map_h
#define __reg_map_h

/*
                                  
                                            
                                                                       
                                              
                                           
                                                                        
                                              
                                           
                                                                         
                                              
   
                                                                                                                                                                                                                          
                                                                   
                                 
  
                              
 */
typedef enum {
  regi_ata                                 = 0xb0032000,
  regi_bif_core                            = 0xb0014000,
  regi_bif_dma                             = 0xb0016000,
  regi_bif_slave                           = 0xb0018000,
  regi_config                              = 0xb003c000,
  regi_dma0                                = 0xb0000000,
  regi_dma1                                = 0xb0002000,
  regi_dma2                                = 0xb0004000,
  regi_dma3                                = 0xb0006000,
  regi_dma4                                = 0xb0008000,
  regi_dma5                                = 0xb000a000,
  regi_dma6                                = 0xb000c000,
  regi_dma7                                = 0xb000e000,
  regi_dma8                                = 0xb0010000,
  regi_dma9                                = 0xb0012000,
  regi_eth0                                = 0xb0034000,
  regi_eth1                                = 0xb0036000,
  regi_gio                                 = 0xb001a000,
  regi_iop                                 = 0xb0020000,
  regi_iop_version                         = 0xb0020000,
  regi_iop_fifo_in0_extra                  = 0xb0020040,
  regi_iop_fifo_in1_extra                  = 0xb0020080,
  regi_iop_fifo_out0_extra                 = 0xb00200c0,
  regi_iop_fifo_out1_extra                 = 0xb0020100,
  regi_iop_trigger_grp0                    = 0xb0020140,
  regi_iop_trigger_grp1                    = 0xb0020180,
  regi_iop_trigger_grp2                    = 0xb00201c0,
  regi_iop_trigger_grp3                    = 0xb0020200,
  regi_iop_trigger_grp4                    = 0xb0020240,
  regi_iop_trigger_grp5                    = 0xb0020280,
  regi_iop_trigger_grp6                    = 0xb00202c0,
  regi_iop_trigger_grp7                    = 0xb0020300,
  regi_iop_crc_par0                        = 0xb0020380,
  regi_iop_crc_par1                        = 0xb0020400,
  regi_iop_dmc_in0                         = 0xb0020480,
  regi_iop_dmc_in1                         = 0xb0020500,
  regi_iop_dmc_out0                        = 0xb0020580,
  regi_iop_dmc_out1                        = 0xb0020600,
  regi_iop_fifo_in0                        = 0xb0020680,
  regi_iop_fifo_in1                        = 0xb0020700,
  regi_iop_fifo_out0                       = 0xb0020780,
  regi_iop_fifo_out1                       = 0xb0020800,
  regi_iop_scrc_in0                        = 0xb0020880,
  regi_iop_scrc_in1                        = 0xb0020900,
  regi_iop_scrc_out0                       = 0xb0020980,
  regi_iop_scrc_out1                       = 0xb0020a00,
  regi_iop_timer_grp0                      = 0xb0020a80,
  regi_iop_timer_grp1                      = 0xb0020b00,
  regi_iop_timer_grp2                      = 0xb0020b80,
  regi_iop_timer_grp3                      = 0xb0020c00,
  regi_iop_sap_in                          = 0xb0020d00,
  regi_iop_sap_out                         = 0xb0020e00,
  regi_iop_spu0                            = 0xb0020f00,
  regi_iop_spu1                            = 0xb0021000,
  regi_iop_sw_cfg                          = 0xb0021100,
  regi_iop_sw_cpu                          = 0xb0021200,
  regi_iop_sw_mpu                          = 0xb0021300,
  regi_iop_sw_spu0                         = 0xb0021400,
  regi_iop_sw_spu1                         = 0xb0021500,
  regi_iop_mpu                             = 0xb0021600,
  regi_irq                                 = 0xb001c000,
  regi_irq2                                = 0xb005c000,
  regi_marb                                = 0xb003e000,
  regi_marb_bp0                            = 0xb003e240,
  regi_marb_bp1                            = 0xb003e280,
  regi_marb_bp2                            = 0xb003e2c0,
  regi_marb_bp3                            = 0xb003e300,
  regi_pinmux                              = 0xb0038000,
  regi_ser0                                = 0xb0026000,
  regi_ser1                                = 0xb0028000,
  regi_ser2                                = 0xb002a000,
  regi_ser3                                = 0xb002c000,
  regi_sser0                               = 0xb0022000,
  regi_sser1                               = 0xb0024000,
  regi_strcop                              = 0xb0030000,
  regi_strmux                              = 0xb003a000,
  regi_timer                               = 0xb001e000,
  regi_timer0                              = 0xb001e000,
  regi_timer2                              = 0xb005e000,
  regi_trace                               = 0xb0040000,
} reg_scope_instances;
#endif /*             */
