#ifndef __ser_defs_h
#define __ser_defs_h

/*
                                  
                                                  
                                                                   
                                             
  
                                                                                                
                                                                    
                                 
  
                              
 */
/*                    */
#ifndef REG_RD
#define REG_RD( scope, inst, reg ) \
  REG_READ( reg_##scope##_##reg, \
            (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_WR
#define REG_WR( scope, inst, reg, val ) \
  REG_WRITE( reg_##scope##_##reg, \
             (inst) + REG_WR_ADDR_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_VECT
#define REG_RD_VECT( scope, inst, reg, index ) \
  REG_READ( reg_##scope##_##reg, \
            (inst) + REG_RD_ADDR_##scope##_##reg + \
	    (index) * STRIDE_##scope##_##reg )
#endif

#ifndef REG_WR_VECT
#define REG_WR_VECT( scope, inst, reg, index, val ) \
  REG_WRITE( reg_##scope##_##reg, \
             (inst) + REG_WR_ADDR_##scope##_##reg + \
	     (index) * STRIDE_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_INT
#define REG_RD_INT( scope, inst, reg ) \
  REG_READ( int, (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_WR_INT
#define REG_WR_INT( scope, inst, reg, val ) \
  REG_WRITE( int, (inst) + REG_WR_ADDR_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_INT_VECT
#define REG_RD_INT_VECT( scope, inst, reg, index ) \
  REG_READ( int, (inst) + REG_RD_ADDR_##scope##_##reg + \
	    (index) * STRIDE_##scope##_##reg )
#endif

#ifndef REG_WR_INT_VECT
#define REG_WR_INT_VECT( scope, inst, reg, index, val ) \
  REG_WRITE( int, (inst) + REG_WR_ADDR_##scope##_##reg + \
	     (index) * STRIDE_##scope##_##reg, (val) )
#endif

#ifndef REG_TYPE_CONV
#define REG_TYPE_CONV( type, orgtype, val ) \
  ( { union { orgtype o; type n; } r; r.o = val; r.n; } )
#endif

#ifndef reg_page_size
#define reg_page_size 8192
#endif

#ifndef REG_ADDR
#define REG_ADDR( scope, inst, reg ) \
  ( (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_ADDR_VECT
#define REG_ADDR_VECT( scope, inst, reg, index ) \
  ( (inst) + REG_RD_ADDR_##scope##_##reg + \
    (index) * STRIDE_##scope##_##reg )
#endif

/*                               */

/*                                         */
typedef struct {
  unsigned int base_freq : 3;
  unsigned int en        : 1;
  unsigned int par       : 2;
  unsigned int par_en    : 1;
  unsigned int data_bits : 1;
  unsigned int stop_bits : 1;
  unsigned int stop      : 1;
  unsigned int rts_delay : 3;
  unsigned int rts_setup : 1;
  unsigned int auto_rts  : 1;
  unsigned int txd       : 1;
  unsigned int auto_cts  : 1;
  unsigned int dummy1    : 15;
} reg_ser_rw_tr_ctrl;
#define REG_RD_ADDR_ser_rw_tr_ctrl 0
#define REG_WR_ADDR_ser_rw_tr_ctrl 0

/*                                           */
typedef struct {
  unsigned int en : 1;
  unsigned int dummy1 : 31;
} reg_ser_rw_tr_dma_en;
#define REG_RD_ADDR_ser_rw_tr_dma_en 4
#define REG_WR_ADDR_ser_rw_tr_dma_en 4

/*                                          */
typedef struct {
  unsigned int base_freq   : 3;
  unsigned int en          : 1;
  unsigned int par         : 2;
  unsigned int par_en      : 1;
  unsigned int data_bits   : 1;
  unsigned int dma_mode    : 1;
  unsigned int dma_err     : 1;
  unsigned int sampling    : 1;
  unsigned int timeout     : 3;
  unsigned int auto_eop    : 1;
  unsigned int half_duplex : 1;
  unsigned int rts_n       : 1;
  unsigned int loopback    : 1;
  unsigned int dummy1      : 14;
} reg_ser_rw_rec_ctrl;
#define REG_RD_ADDR_ser_rw_rec_ctrl 8
#define REG_WR_ADDR_ser_rw_rec_ctrl 8

/*                                             */
typedef struct {
  unsigned int div : 16;
  unsigned int dummy1 : 16;
} reg_ser_rw_tr_baud_div;
#define REG_RD_ADDR_ser_rw_tr_baud_div 12
#define REG_WR_ADDR_ser_rw_tr_baud_div 12

/*                                              */
typedef struct {
  unsigned int div : 16;
  unsigned int dummy1 : 16;
} reg_ser_rw_rec_baud_div;
#define REG_RD_ADDR_ser_rw_rec_baud_div 16
#define REG_WR_ADDR_ser_rw_rec_baud_div 16

/*                                      */
typedef struct {
  unsigned int chr       : 8;
  unsigned int automatic : 1;
  unsigned int dummy1    : 23;
} reg_ser_rw_xoff;
#define REG_RD_ADDR_ser_rw_xoff 20
#define REG_WR_ADDR_ser_rw_xoff 20

/*                                          */
typedef struct {
  unsigned int clr : 1;
  unsigned int dummy1 : 31;
} reg_ser_rw_xoff_clr;
#define REG_RD_ADDR_ser_rw_xoff_clr 24
#define REG_WR_ADDR_ser_rw_xoff_clr 24

/*                                      */
typedef struct {
  unsigned int data : 8;
  unsigned int dummy1 : 24;
} reg_ser_rw_dout;
#define REG_RD_ADDR_ser_rw_dout 28
#define REG_WR_ADDR_ser_rw_dout 28

/*                                          */
typedef struct {
  unsigned int data        : 8;
  unsigned int dummy1      : 8;
  unsigned int dav         : 1;
  unsigned int framing_err : 1;
  unsigned int par_err     : 1;
  unsigned int orun        : 1;
  unsigned int rec_err     : 1;
  unsigned int rxd         : 1;
  unsigned int tr_idle     : 1;
  unsigned int tr_empty    : 1;
  unsigned int tr_rdy      : 1;
  unsigned int cts_n       : 1;
  unsigned int xoff_detect : 1;
  unsigned int rts_n       : 1;
  unsigned int txd         : 1;
  unsigned int dummy2      : 3;
} reg_ser_rs_stat_din;
#define REG_RD_ADDR_ser_rs_stat_din 32

/*                                        */
typedef struct {
  unsigned int data        : 8;
  unsigned int dummy1      : 8;
  unsigned int dav         : 1;
  unsigned int framing_err : 1;
  unsigned int par_err     : 1;
  unsigned int orun        : 1;
  unsigned int rec_err     : 1;
  unsigned int rxd         : 1;
  unsigned int tr_idle     : 1;
  unsigned int tr_empty    : 1;
  unsigned int tr_rdy      : 1;
  unsigned int cts_n       : 1;
  unsigned int xoff_detect : 1;
  unsigned int rts_n       : 1;
  unsigned int txd         : 1;
  unsigned int dummy2      : 3;
} reg_ser_r_stat_din;
#define REG_RD_ADDR_ser_r_stat_din 36

/*                                         */
typedef struct {
  unsigned int set : 1;
  unsigned int dummy1 : 31;
} reg_ser_rw_rec_eop;
#define REG_RD_ADDR_ser_rw_rec_eop 40
#define REG_WR_ADDR_ser_rw_rec_eop 40

/*                                           */
typedef struct {
  unsigned int tr_rdy   : 1;
  unsigned int tr_empty : 1;
  unsigned int tr_idle  : 1;
  unsigned int dav      : 1;
  unsigned int dummy1   : 28;
} reg_ser_rw_intr_mask;
#define REG_RD_ADDR_ser_rw_intr_mask 44
#define REG_WR_ADDR_ser_rw_intr_mask 44

/*                                          */
typedef struct {
  unsigned int tr_rdy   : 1;
  unsigned int tr_empty : 1;
  unsigned int tr_idle  : 1;
  unsigned int dav      : 1;
  unsigned int dummy1   : 28;
} reg_ser_rw_ack_intr;
#define REG_RD_ADDR_ser_rw_ack_intr 48
#define REG_WR_ADDR_ser_rw_ack_intr 48

/*                                    */
typedef struct {
  unsigned int tr_rdy   : 1;
  unsigned int tr_empty : 1;
  unsigned int tr_idle  : 1;
  unsigned int dav      : 1;
  unsigned int dummy1   : 28;
} reg_ser_r_intr;
#define REG_RD_ADDR_ser_r_intr 52

/*                                           */
typedef struct {
  unsigned int tr_rdy   : 1;
  unsigned int tr_empty : 1;
  unsigned int tr_idle  : 1;
  unsigned int dav      : 1;
  unsigned int dummy1   : 28;
} reg_ser_r_masked_intr;
#define REG_RD_ADDR_ser_r_masked_intr 56


/*           */
enum {
  regk_ser_active                          = 0x00000000,
  regk_ser_bits1                           = 0x00000000,
  regk_ser_bits2                           = 0x00000001,
  regk_ser_bits7                           = 0x00000001,
  regk_ser_bits8                           = 0x00000000,
  regk_ser_del0_5                          = 0x00000000,
  regk_ser_del1                            = 0x00000001,
  regk_ser_del1_5                          = 0x00000002,
  regk_ser_del2                            = 0x00000003,
  regk_ser_del2_5                          = 0x00000004,
  regk_ser_del3                            = 0x00000005,
  regk_ser_del3_5                          = 0x00000006,
  regk_ser_del4                            = 0x00000007,
  regk_ser_even                            = 0x00000000,
  regk_ser_ext                             = 0x00000001,
  regk_ser_f100                            = 0x00000007,
  regk_ser_f29_493                         = 0x00000004,
  regk_ser_f32                             = 0x00000005,
  regk_ser_f32_768                         = 0x00000006,
  regk_ser_ignore                          = 0x00000001,
  regk_ser_inactive                        = 0x00000001,
  regk_ser_majority                        = 0x00000001,
  regk_ser_mark                            = 0x00000002,
  regk_ser_middle                          = 0x00000000,
  regk_ser_no                              = 0x00000000,
  regk_ser_odd                             = 0x00000001,
  regk_ser_off                             = 0x00000000,
  regk_ser_rw_intr_mask_default            = 0x00000000,
  regk_ser_rw_rec_baud_div_default         = 0x00000000,
  regk_ser_rw_rec_ctrl_default             = 0x00010000,
  regk_ser_rw_tr_baud_div_default          = 0x00000000,
  regk_ser_rw_tr_ctrl_default              = 0x00008000,
  regk_ser_rw_tr_dma_en_default            = 0x00000000,
  regk_ser_rw_xoff_default                 = 0x00000000,
  regk_ser_space                           = 0x00000003,
  regk_ser_stop                            = 0x00000000,
  regk_ser_yes                             = 0x00000001
};
#endif /*              */
