/***************************************************************************
 * Copyright (c) 1999-2009, Broadcom Corporation.
 *
 *  Name: bcm_70012_regs.h
 *
 *  Description: BCM70012 registers
 *
 ********************************************************************
 * This header is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 2.1 of the License.
 *
 * This header is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with this header.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef MACFILE_H__
#define MACFILE_H__

/* 
                                                           
 */
#if !defined(GET_FIELD) && !defined(SET_FIELD)
#define BRCM_ALIGN(c, r, f)   c##_##r##_##f##_ALIGN
#define BRCM_BITS(c, r, f)    c##_##r##_##f##_BITS
#define BRCM_MASK(c, r, f)    c##_##r##_##f##_MASK
#define BRCM_SHIFT(c, r, f)   c##_##r##_##f##_SHIFT

#define GET_FIELD(m, c, r, f) \
	((((m) & BRCM_MASK(c, r, f)) >> BRCM_SHIFT(c, r, f)) << BRCM_ALIGN(c, r, f))

#define SET_FIELD(m, c, r, f, d) \
	((m) = (((m) & ~BRCM_MASK(c, r, f)) | ((((d) >> BRCM_ALIGN(c, r, f)) << \
	 BRCM_SHIFT(c, r, f)) & BRCM_MASK(c, r, f))) \
	)

#define SET_TYPE_FIELD(m, c, r, f, d) SET_FIELD(m, c, r, f, c##_##d)
#define SET_NAME_FIELD(m, c, r, f, d) SET_FIELD(m, c, r, f, c##_##r##_##f##_##d)
#define SET_VALUE_FIELD(m, c, r, f, d) SET_FIELD(m, c, r, f, d)

#endif /*           */

/*                                                                           
              
                                                                           */
/*                                                                           
                                   
                                                                           */
#define AES_RGR_BRIDGE_RESET_CTRL_DEASSERT                 0
#define AES_RGR_BRIDGE_RESET_CTRL_ASSERT                   1

/*                                                                           
                                   
                                                                           */
#define CCE_RGR_BRIDGE_RESET_CTRL_DEASSERT                 0
#define CCE_RGR_BRIDGE_RESET_CTRL_ASSERT                   1

/*                                                                           
                                   
                                                                           */
#define DBU_RGR_BRIDGE_RESET_CTRL_DEASSERT                 0
#define DBU_RGR_BRIDGE_RESET_CTRL_ASSERT                   1

/*                                                                           
                                   
                                                                           */
#define DCI_RGR_BRIDGE_RESET_CTRL_DEASSERT                 0
#define DCI_RGR_BRIDGE_RESET_CTRL_ASSERT                   1

/*                                                                           
                                      
                                                                           */
#define GISB_ARBITER_DEASSERT_ASSERT_DEASSERT              0
#define GISB_ARBITER_DEASSERT_ASSERT_ASSERT                1

/*                                                                           
                                  
                                                                           */
#define GISB_ARBITER_UNMASK_MASK_UNMASK                    0
#define GISB_ARBITER_UNMASK_MASK_MASK                      1

/*                                                                           
                                     
                                                                           */
#define GISB_ARBITER_DISABLE_ENABLE_DISABLE                0
#define GISB_ARBITER_DISABLE_ENABLE_ENABLE                 1

/*                                                                           
                                  
                                                                           */
#define I2C_GR_BRIDGE_RESET_CTRL_DEASSERT                  0
#define I2C_GR_BRIDGE_RESET_CTRL_ASSERT                    1

/*                                                                           
                                   
                                                                           */
#define MISC_GR_BRIDGE_RESET_CTRL_DEASSERT                 0
#define MISC_GR_BRIDGE_RESET_CTRL_ASSERT                   1

/*                                                                           
                                  
                                                                           */
#define OTP_GR_BRIDGE_RESET_CTRL_DEASSERT                  0
#define OTP_GR_BRIDGE_RESET_CTRL_ASSERT                    1

/*                                                                           
                            
                                                                           */
#define PCIE_CFG_DEVICE_VENDOR_ID      0x00000000 /*                           */
#define PCIE_CFG_STATUS_COMMAND        0x00000004 /*                         */
#define PCIE_CFG_PCI_CLASSCODE_AND_REVISION_ID 0x00000008 /*                                        */
#define PCIE_CFG_BIST_HEADER_TYPE_LATENCY_TIMER_CACHE_LINE_SIZE 0x0000000c /*                                                         */
#define PCIE_CFG_BASE_ADDRESS_1        0x00000010 /*                         */
#define PCIE_CFG_BASE_ADDRESS_2        0x00000014 /*                         */
#define PCIE_CFG_BASE_ADDRESS_3        0x00000018 /*                         */
#define PCIE_CFG_BASE_ADDRESS_4        0x0000001c /*                         */
#define PCIE_CFG_CARDBUS_CIS_POINTER   0x00000028 /*                              */
#define PCIE_CFG_SUBSYSTEM_DEVICE_VENDOR_ID 0x0000002c /*                                     */
#define PCIE_CFG_EXPANSION_ROM_BASE_ADDRESS 0x00000030 /*                                     */
#define PCIE_CFG_CAPABILITIES_POINTER  0x00000034 /*                               */
#define PCIE_CFG_INTERRUPT             0x0000003c /*                    */
#define PCIE_CFG_VPD_CAPABILITIES      0x00000040 /*                           */
#define PCIE_CFG_VPD_DATA              0x00000044 /*                   */
#define PCIE_CFG_POWER_MANAGEMENT_CAPABILITY 0x00000048 /*                                      */
#define PCIE_CFG_POWER_MANAGEMENT_CONTROL_STATUS 0x0000004c /*                                          */
#define PCIE_CFG_MSI_CAPABILITY_HEADER 0x00000050 /*                                */
#define PCIE_CFG_MSI_LOWER_ADDRESS     0x00000054 /*                            */
#define PCIE_CFG_MSI_UPPER_ADDRESS_REGISTER 0x00000058 /*                                     */
#define PCIE_CFG_MSI_DATA              0x0000005c /*                   */
#define PCIE_CFG_BROADCOM_VENDOR_SPECIFIC_CAPABILITY_HEADER 0x00000060 /*                                                     */
#define PCIE_CFG_RESET_COUNTERS_INITIAL_VALUES 0x00000064 /*                                        */
#define PCIE_CFG_MISCELLANEOUS_HOST_CONTROL 0x00000068 /*                                     */
#define PCIE_CFG_SPARE                 0x0000006c /*                */
#define PCIE_CFG_PCI_STATE             0x00000070 /*                    */
#define PCIE_CFG_CLOCK_CONTROL         0x00000074 /*                        */
#define PCIE_CFG_REGISTER_BASE         0x00000078 /*                        */
#define PCIE_CFG_MEMORY_BASE           0x0000007c /*                      */
#define PCIE_CFG_REGISTER_DATA         0x00000080 /*                        */
#define PCIE_CFG_MEMORY_DATA           0x00000084 /*                      */
#define PCIE_CFG_EXPANSION_ROM_BAR_SIZE 0x00000088 /*                                 */
#define PCIE_CFG_EXPANSION_ROM_ADDRESS 0x0000008c /*                                */
#define PCIE_CFG_EXPANSION_ROM_DATA    0x00000090 /*                             */
#define PCIE_CFG_VPD_INTERFACE         0x00000094 /*                        */
#define PCIE_CFG_UNDI_RECEIVE_BD_STANDARD_PRODUCER_RING_PRODUCER_INDEX_MAILBOX_UPPER 0x00000098 /*                                                                              */
#define PCIE_CFG_UNDI_RECEIVE_BD_STANDARD_PRODUCER_RING_PRODUCER_INDEX_MAILBOX_LOWER 0x0000009c /*                                                                              */
#define PCIE_CFG_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX_UPPER 0x000000a0 /*                                                        */
#define PCIE_CFG_UNDI_RECEIVE_RETURN_RING_CONSUMER_INDEX_LOWER 0x000000a4 /*                                                        */
#define PCIE_CFG_UNDI_SEND_BD_PRODUCER_INDEX_MAILBOX_UPPER 0x000000a8 /*                                                    */
#define PCIE_CFG_UNDI_SEND_BD_PRODUCER_INDEX_MAILBOX_LOWER 0x000000ac /*                                                    */
#define PCIE_CFG_INT_MAILBOX_UPPER     0x000000b0 /*                            */
#define PCIE_CFG_INT_MAILBOX_LOWER     0x000000b4 /*                            */
#define PCIE_CFG_PRODUCT_ID_AND_ASIC_REVISION 0x000000bc /*                                       */
#define PCIE_CFG_FUNCTION_EVENT        0x000000c0 /*                         */
#define PCIE_CFG_FUNCTION_EVENT_MASK   0x000000c4 /*                              */
#define PCIE_CFG_FUNCTION_PRESENT      0x000000c8 /*                           */
#define PCIE_CFG_PCIE_CAPABILITIES     0x000000cc /*                            */
#define PCIE_CFG_DEVICE_CAPABILITIES   0x000000d0 /*                              */
#define PCIE_CFG_DEVICE_STATUS_CONTROL 0x000000d4 /*                                */
#define PCIE_CFG_LINK_CAPABILITY       0x000000d8 /*                          */
#define PCIE_CFG_LINK_STATUS_CONTROL   0x000000dc /*                              */
#define PCIE_CFG_DEVICE_CAPABILITIES_2 0x000000f0 /*                                */
#define PCIE_CFG_DEVICE_STATUS_CONTROL_2 0x000000f4 /*                                  */
#define PCIE_CFG_LINK_CAPABILITIES_2   0x000000f8 /*                              */
#define PCIE_CFG_LINK_STATUS_CONTROL_2 0x000000fc /*                                */
#define PCIE_CFG_ADVANCED_ERROR_REPORTING_ENHANCED_CAPABILITY_HEADER 0x00000100 /*                                                              */
#define PCIE_CFG_UNCORRECTABLE_ERROR_STATUS 0x00000104 /*                                     */
#define PCIE_CFG_UNCORRECTABLE_ERROR_MASK 0x00000108 /*                                   */
#define PCIE_CFG_UNCORRECTABLE_ERROR_SEVERITY 0x0000010c /*                                       */
#define PCIE_CFG_CORRECTABLE_ERROR_STATUS 0x00000110 /*                                   */
#define PCIE_CFG_CORRECTABLE_ERROR_MASK 0x00000114 /*                                 */
#define PCIE_CFG_ADVANCED_ERROR_CAPABILITIES_AND_CONTROL 0x00000118 /*                                                  */
#define PCIE_CFG_HEADER_LOG_1          0x0000011c /*                       */
#define PCIE_CFG_HEADER_LOG_2          0x00000120 /*                       */
#define PCIE_CFG_HEADER_LOG_3          0x00000124 /*                       */
#define PCIE_CFG_HEADER_LOG_4          0x00000128 /*                       */
#define PCIE_CFG_VIRTUAL_CHANNEL_ENHANCED_CAPABILITY_HEADER 0x0000013c /*                                                     */
#define PCIE_CFG_PORT_VC_CAPABILITY    0x00000140 /*                             */
#define PCIE_CFG_PORT_VC_CAPABILITY_2  0x00000144 /*                               */
#define PCIE_CFG_PORT_VC_STATUS_CONTROL 0x00000148 /*                                 */
#define PCIE_CFG_VC_RESOURCE_CAPABILITY 0x0000014c /*                                 */
#define PCIE_CFG_VC_RESOURCE_CONTROL   0x00000150 /*                              */
#define PCIE_CFG_VC_RESOURCE_STATUS    0x00000154 /*                             */
#define PCIE_CFG_DEVICE_SERIAL_NO_ENHANCED_CAPABILITY_HEADER 0x00000160 /*                                                      */
#define PCIE_CFG_DEVICE_SERIAL_NO_LOWER_DW 0x00000164 /*                                    */
#define PCIE_CFG_DEVICE_SERIAL_NO_UPPER_DW 0x00000168 /*                                    */
#define PCIE_CFG_POWER_BUDGETING_ENHANCED_CAPABILITY_HEADER 0x0000016c /*                                                     */
#define PCIE_CFG_POWER_BUDGETING_DATA_SELECT 0x00000170 /*                                      */
#define PCIE_CFG_POWER_BUDGETING_DATA  0x00000174 /*                               */
#define PCIE_CFG_POWER_BUDGETING_CAPABILITY 0x00000178 /*                                     */
#define PCIE_CFG_FIRMWARE_POWER_BUDGETING_2_1 0x0000017c /*                                       */
#define PCIE_CFG_FIRMWARE_POWER_BUDGETING_4_3 0x00000180 /*                                       */
#define PCIE_CFG_FIRMWARE_POWER_BUDGETING_6_5 0x00000184 /*                                       */
#define PCIE_CFG_FIRMWARE_POWER_BUDGETING_8_7 0x00000188 /*                                       */
#define PCIE_CFG_PCIE_1_1_ADVISORY_NON_FATAL_ERROR_MASKING 0x0000018c /*                                                    */


/*                                                                           
                           
                                                                           */
#define PCIE_TL_TL_CONTROL             0x00000400 /*                     */
#define PCIE_TL_TRANSACTION_CONFIGURATION 0x00000404 /*                                    */


/*                                                                           
                            
                                                                           */
#define PCIE_DLL_DATA_LINK_CONTROL     0x00000500 /*                            */
#define PCIE_DLL_DATA_LINK_STATUS      0x00000504 /*                           */


/*                                                                           
                        
                                                                           */
#define INTR_INTR_STATUS               0x00000700 /*                           */
#define INTR_INTR_SET                  0x00000704 /*                        */
#define INTR_INTR_CLR_REG              0x00000708 /*                          */
#define INTR_INTR_MSK_STS_REG          0x0000070c /*                                */
#define INTR_INTR_MSK_SET_REG          0x00000710 /*                             */
#define INTR_INTR_MSK_CLR_REG          0x00000714 /*                               */
#define INTR_EOI_CTRL                  0x00000720 /*                                   */


/*                                                                           
                          
                                                                           */
#define MISC1_TX_FIRST_DESC_L_ADDR_LIST0 0x00000c00 /*                                                        */
#define MISC1_TX_FIRST_DESC_U_ADDR_LIST0 0x00000c04 /*                                                        */
#define MISC1_TX_FIRST_DESC_L_ADDR_LIST1 0x00000c08 /*                                                        */
#define MISC1_TX_FIRST_DESC_U_ADDR_LIST1 0x00000c0c /*                                                        */
#define MISC1_TX_SW_DESC_LIST_CTRL_STS 0x00000c10 /*                                                    */
#define MISC1_TX_DMA_ERROR_STATUS      0x00000c18 /*                            */
#define MISC1_TX_DMA_LIST0_CUR_DESC_L_ADDR 0x00000c1c /*                                               */
#define MISC1_TX_DMA_LIST0_CUR_DESC_U_ADDR 0x00000c20 /*                                               */
#define MISC1_TX_DMA_LIST0_CUR_BYTE_CNT_REM 0x00000c24 /*                                               */
#define MISC1_TX_DMA_LIST1_CUR_DESC_L_ADDR 0x00000c28 /*                                               */
#define MISC1_TX_DMA_LIST1_CUR_DESC_U_ADDR 0x00000c2c /*                                               */
#define MISC1_TX_DMA_LIST1_CUR_BYTE_CNT_REM 0x00000c30 /*                                               */
#define MISC1_Y_RX_FIRST_DESC_L_ADDR_LIST0 0x00000c34 /*                                                      */
#define MISC1_Y_RX_FIRST_DESC_U_ADDR_LIST0 0x00000c38 /*                                                      */
#define MISC1_Y_RX_FIRST_DESC_L_ADDR_LIST1 0x00000c3c /*                                                      */
#define MISC1_Y_RX_FIRST_DESC_U_ADDR_LIST1 0x00000c40 /*                                                      */
#define MISC1_Y_RX_SW_DESC_LIST_CTRL_STS 0x00000c44 /*                                                  */
#define MISC1_Y_RX_ERROR_STATUS        0x00000c4c /*                          */
#define MISC1_Y_RX_LIST0_CUR_DESC_L_ADDR 0x00000c50 /*                                             */
#define MISC1_Y_RX_LIST0_CUR_DESC_U_ADDR 0x00000c54 /*                                             */
#define MISC1_Y_RX_LIST0_CUR_BYTE_CNT  0x00000c58 /*                                          */
#define MISC1_Y_RX_LIST1_CUR_DESC_L_ADDR 0x00000c5c /*                                             */
#define MISC1_Y_RX_LIST1_CUR_DESC_U_ADDR 0x00000c60 /*                                             */
#define MISC1_Y_RX_LIST1_CUR_BYTE_CNT  0x00000c64 /*                                          */
#define MISC1_UV_RX_FIRST_DESC_L_ADDR_LIST0 0x00000c68 /*                                                       */
#define MISC1_UV_RX_FIRST_DESC_U_ADDR_LIST0 0x00000c6c /*                                                       */
#define MISC1_UV_RX_FIRST_DESC_L_ADDR_LIST1 0x00000c70 /*                                                       */
#define MISC1_UV_RX_FIRST_DESC_U_ADDR_LIST1 0x00000c74 /*                                                       */
#define MISC1_UV_RX_SW_DESC_LIST_CTRL_STS 0x00000c78 /*                                                   */
#define MISC1_UV_RX_ERROR_STATUS       0x00000c7c /*                           */
#define MISC1_UV_RX_LIST0_CUR_DESC_L_ADDR 0x00000c80 /*                                              */
#define MISC1_UV_RX_LIST0_CUR_DESC_U_ADDR 0x00000c84 /*                                              */
#define MISC1_UV_RX_LIST0_CUR_BYTE_CNT 0x00000c88 /*                                           */
#define MISC1_UV_RX_LIST1_CUR_DESC_L_ADDR 0x00000c8c /*                                              */
#define MISC1_UV_RX_LIST1_CUR_DESC_U_ADDR 0x00000c90 /*                                              */
#define MISC1_UV_RX_LIST1_CUR_BYTE_CNT 0x00000c94 /*                                           */
#define MISC1_DMA_DEBUG_OPTIONS_REG    0x00000c98 /*                            */
#define MISC1_READ_CHANNEL_ERROR_STATUS 0x00000c9c /*                           */
#define MISC1_PCIE_DMA_CTRL            0x00000ca0 /*                           */


/*                                                                           
                          
                                                                           */
#define MISC2_GLOBAL_CTRL              0x00000d00 /*                         */
#define MISC2_INTERNAL_STATUS          0x00000d04 /*                          */
#define MISC2_INTERNAL_STATUS_MUX_CTRL 0x00000d08 /*                            */
#define MISC2_DEBUG_FIFO_LENGTH        0x00000d0c /*                   */


/*                                                                           
                          
                                                                           */
#define MISC3_RESET_CTRL               0x00000e00 /*                        */
#define MISC3_BIST_CTRL                0x00000e04 /*                       */
#define MISC3_BIST_STATUS              0x00000e08 /*                      */
#define MISC3_RX_CHECKSUM              0x00000e0c /*                  */
#define MISC3_TX_CHECKSUM              0x00000e10 /*                   */
#define MISC3_ECO_CTRL_CORE            0x00000e14 /*                                 */
#define MISC3_CSI_TEST_CTRL            0x00000e18 /*                           */
#define MISC3_HD_DVI_TEST_CTRL         0x00000e1c /*                              */


/*                                                                           
                               
                                                                           */
#define MISC_PERST_ECO_CTRL_PERST      0x00000e80 /*                                 */
#define MISC_PERST_DECODER_CTRL        0x00000e84 /*                          */
#define MISC_PERST_CCE_STATUS          0x00000e88 /*                           */
#define MISC_PERST_PCIE_DEBUG          0x00000e8c /*                             */
#define MISC_PERST_PCIE_DEBUG_STATUS   0x00000e90 /*                            */
#define MISC_PERST_VREG_CTRL           0x00000e94 /*                                    */
#define MISC_PERST_MEM_CTRL            0x00000e98 /*                         */
#define MISC_PERST_CLOCK_CTRL          0x00000e9c /*                        */


/*                                                                           
                                 
                                                                           */
#define GISB_ARBITER_REVISION          0x00000f00 /*                       */
#define GISB_ARBITER_SCRATCH           0x00000f04 /*                               */
#define GISB_ARBITER_REQ_MASK          0x00000f08 /*                                           */
#define GISB_ARBITER_TIMER             0x00000f0c /*                                   */


/*                                                                           
                       
                                                                           */
#define OTP_CONFIG_INFO                0x00001400 /*                            */
#define OTP_CMD                        0x00001404 /*                      */
#define OTP_STATUS                     0x00001408 /*                     */
#define OTP_CONTENT_MISC               0x0000140c /*                                  */
#define OTP_CONTENT_AES_0              0x00001410 /*                              */
#define OTP_CONTENT_AES_1              0x00001414 /*                              */
#define OTP_CONTENT_AES_2              0x00001418 /*                              */
#define OTP_CONTENT_AES_3              0x0000141c /*                              */
#define OTP_CONTENT_SHA_0              0x00001420 /*                              */
#define OTP_CONTENT_SHA_1              0x00001424 /*                              */
#define OTP_CONTENT_SHA_2              0x00001428 /*                              */
#define OTP_CONTENT_SHA_3              0x0000142c /*                              */
#define OTP_CONTENT_SHA_4              0x00001430 /*                              */
#define OTP_CONTENT_SHA_5              0x00001434 /*                              */
#define OTP_CONTENT_SHA_6              0x00001438 /*                              */
#define OTP_CONTENT_SHA_7              0x0000143c /*                              */
#define OTP_CONTENT_CHECKSUM           0x00001440 /*                              */
#define OTP_PROG_CTRL                  0x00001444 /*                              */
#define OTP_PROG_STATUS                0x00001448 /*                             */
#define OTP_PROG_PULSE                 0x0000144c /*                              */
#define OTP_VERIFY_PULSE               0x00001450 /*                             */
#define OTP_PROG_MASK                  0x00001454 /*                       */
#define OTP_DATA_INPUT                 0x00001458 /*                     */
#define OTP_DATA_OUTPUT                0x0000145c /*                      */


/*                                                                           
                       
                                                                           */
#define AES_CONFIG_INFO                0x00001800 /*                                        */
#define AES_CMD                        0x00001804 /*                      */
#define AES_STATUS                     0x00001808 /*                     */
#define AES_EEPROM_CONFIG              0x0000180c /*                                   */
#define AES_EEPROM_DATA_0              0x00001810 /*                            */
#define AES_EEPROM_DATA_1              0x00001814 /*                            */
#define AES_EEPROM_DATA_2              0x00001818 /*                            */
#define AES_EEPROM_DATA_3              0x0000181c /*                            */


/*                                                                           
                       
                                                                           */
#define DCI_CMD                        0x00001c00 /*                      */
#define DCI_STATUS                     0x00001c04 /*                     */
#define DCI_DRAM_BASE_ADDR             0x00001c08 /*                            */
#define DCI_FIRMWARE_ADDR              0x00001c0c /*                           */
#define DCI_FIRMWARE_DATA              0x00001c10 /*                        */
#define DCI_SIGNATURE_DATA_0           0x00001c14 /*                           */
#define DCI_SIGNATURE_DATA_1           0x00001c18 /*                           */
#define DCI_SIGNATURE_DATA_2           0x00001c1c /*                           */
#define DCI_SIGNATURE_DATA_3           0x00001c20 /*                           */
#define DCI_SIGNATURE_DATA_4           0x00001c24 /*                           */
#define DCI_SIGNATURE_DATA_5           0x00001c28 /*                           */
#define DCI_SIGNATURE_DATA_6           0x00001c2c /*                           */
#define DCI_SIGNATURE_DATA_7           0x00001c30 /*                           */


/*                                                                           
                        
                                                                           */
/*                                                                           
                      
                                                                           */
/*                                          */
#define INTR_INTR_STATUS_reserved0_MASK                            0xfc000000
#define INTR_INTR_STATUS_reserved0_ALIGN                           0
#define INTR_INTR_STATUS_reserved0_BITS                            6
#define INTR_INTR_STATUS_reserved0_SHIFT                           26

/*                                                 */
#define INTR_INTR_STATUS_PCIE_TGT_CA_ATTN_MASK                     0x02000000
#define INTR_INTR_STATUS_PCIE_TGT_CA_ATTN_ALIGN                    0
#define INTR_INTR_STATUS_PCIE_TGT_CA_ATTN_BITS                     1
#define INTR_INTR_STATUS_PCIE_TGT_CA_ATTN_SHIFT                    25

/*                                                 */
#define INTR_INTR_STATUS_PCIE_TGT_UR_ATTN_MASK                     0x01000000
#define INTR_INTR_STATUS_PCIE_TGT_UR_ATTN_ALIGN                    0
#define INTR_INTR_STATUS_PCIE_TGT_UR_ATTN_BITS                     1
#define INTR_INTR_STATUS_PCIE_TGT_UR_ATTN_SHIFT                    24

/*                                          */
#define INTR_INTR_STATUS_reserved1_MASK                            0x00ffc000
#define INTR_INTR_STATUS_reserved1_ALIGN                           0
#define INTR_INTR_STATUS_reserved1_BITS                            10
#define INTR_INTR_STATUS_reserved1_SHIFT                           14

/*                                                      */
#define INTR_INTR_STATUS_L1_UV_RX_DMA_ERR_INTR_MASK                0x00002000
#define INTR_INTR_STATUS_L1_UV_RX_DMA_ERR_INTR_ALIGN               0
#define INTR_INTR_STATUS_L1_UV_RX_DMA_ERR_INTR_BITS                1
#define INTR_INTR_STATUS_L1_UV_RX_DMA_ERR_INTR_SHIFT               13

/*                                                       */
#define INTR_INTR_STATUS_L1_UV_RX_DMA_DONE_INTR_MASK               0x00001000
#define INTR_INTR_STATUS_L1_UV_RX_DMA_DONE_INTR_ALIGN              0
#define INTR_INTR_STATUS_L1_UV_RX_DMA_DONE_INTR_BITS               1
#define INTR_INTR_STATUS_L1_UV_RX_DMA_DONE_INTR_SHIFT              12

/*                                                     */
#define INTR_INTR_STATUS_L1_Y_RX_DMA_ERR_INTR_MASK                 0x00000800
#define INTR_INTR_STATUS_L1_Y_RX_DMA_ERR_INTR_ALIGN                0
#define INTR_INTR_STATUS_L1_Y_RX_DMA_ERR_INTR_BITS                 1
#define INTR_INTR_STATUS_L1_Y_RX_DMA_ERR_INTR_SHIFT                11

/*                                                      */
#define INTR_INTR_STATUS_L1_Y_RX_DMA_DONE_INTR_MASK                0x00000400
#define INTR_INTR_STATUS_L1_Y_RX_DMA_DONE_INTR_ALIGN               0
#define INTR_INTR_STATUS_L1_Y_RX_DMA_DONE_INTR_BITS                1
#define INTR_INTR_STATUS_L1_Y_RX_DMA_DONE_INTR_SHIFT               10

/*                                                   */
#define INTR_INTR_STATUS_L1_TX_DMA_ERR_INTR_MASK                   0x00000200
#define INTR_INTR_STATUS_L1_TX_DMA_ERR_INTR_ALIGN                  0
#define INTR_INTR_STATUS_L1_TX_DMA_ERR_INTR_BITS                   1
#define INTR_INTR_STATUS_L1_TX_DMA_ERR_INTR_SHIFT                  9

/*                                                    */
#define INTR_INTR_STATUS_L1_TX_DMA_DONE_INTR_MASK                  0x00000100
#define INTR_INTR_STATUS_L1_TX_DMA_DONE_INTR_ALIGN                 0
#define INTR_INTR_STATUS_L1_TX_DMA_DONE_INTR_BITS                  1
#define INTR_INTR_STATUS_L1_TX_DMA_DONE_INTR_SHIFT                 8

/*                                          */
#define INTR_INTR_STATUS_reserved2_MASK                            0x000000c0
#define INTR_INTR_STATUS_reserved2_ALIGN                           0
#define INTR_INTR_STATUS_reserved2_BITS                            2
#define INTR_INTR_STATUS_reserved2_SHIFT                           6

/*                                                      */
#define INTR_INTR_STATUS_L0_UV_RX_DMA_ERR_INTR_MASK                0x00000020
#define INTR_INTR_STATUS_L0_UV_RX_DMA_ERR_INTR_ALIGN               0
#define INTR_INTR_STATUS_L0_UV_RX_DMA_ERR_INTR_BITS                1
#define INTR_INTR_STATUS_L0_UV_RX_DMA_ERR_INTR_SHIFT               5

/*                                                       */
#define INTR_INTR_STATUS_L0_UV_RX_DMA_DONE_INTR_MASK               0x00000010
#define INTR_INTR_STATUS_L0_UV_RX_DMA_DONE_INTR_ALIGN              0
#define INTR_INTR_STATUS_L0_UV_RX_DMA_DONE_INTR_BITS               1
#define INTR_INTR_STATUS_L0_UV_RX_DMA_DONE_INTR_SHIFT              4

/*                                                     */
#define INTR_INTR_STATUS_L0_Y_RX_DMA_ERR_INTR_MASK                 0x00000008
#define INTR_INTR_STATUS_L0_Y_RX_DMA_ERR_INTR_ALIGN                0
#define INTR_INTR_STATUS_L0_Y_RX_DMA_ERR_INTR_BITS                 1
#define INTR_INTR_STATUS_L0_Y_RX_DMA_ERR_INTR_SHIFT                3

/*                                                      */
#define INTR_INTR_STATUS_L0_Y_RX_DMA_DONE_INTR_MASK                0x00000004
#define INTR_INTR_STATUS_L0_Y_RX_DMA_DONE_INTR_ALIGN               0
#define INTR_INTR_STATUS_L0_Y_RX_DMA_DONE_INTR_BITS                1
#define INTR_INTR_STATUS_L0_Y_RX_DMA_DONE_INTR_SHIFT               2

/*                                                   */
#define INTR_INTR_STATUS_L0_TX_DMA_ERR_INTR_MASK                   0x00000002
#define INTR_INTR_STATUS_L0_TX_DMA_ERR_INTR_ALIGN                  0
#define INTR_INTR_STATUS_L0_TX_DMA_ERR_INTR_BITS                   1
#define INTR_INTR_STATUS_L0_TX_DMA_ERR_INTR_SHIFT                  1

/*                                                    */
#define INTR_INTR_STATUS_L0_TX_DMA_DONE_INTR_MASK                  0x00000001
#define INTR_INTR_STATUS_L0_TX_DMA_DONE_INTR_ALIGN                 0
#define INTR_INTR_STATUS_L0_TX_DMA_DONE_INTR_BITS                  1
#define INTR_INTR_STATUS_L0_TX_DMA_DONE_INTR_SHIFT                 0


/*                                                                           
                                    
                                                                           */
/*                                                        */
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_reserved0_MASK              0xfffffff0
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_reserved0_ALIGN             0
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_reserved0_BITS              28
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_reserved0_SHIFT             4

/*                                                                */
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DMA_DATA_SERV_PTR_MASK      0x00000008
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DMA_DATA_SERV_PTR_ALIGN     0
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DMA_DATA_SERV_PTR_BITS      1
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DMA_DATA_SERV_PTR_SHIFT     3

/*                                                            */
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DESC_SERV_PTR_MASK          0x00000004
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DESC_SERV_PTR_ALIGN         0
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DESC_SERV_PTR_BITS          1
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_DESC_SERV_PTR_SHIFT         2

/*                                                                   */
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_HALT_ON_ERROR_MASK   0x00000002
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_HALT_ON_ERROR_ALIGN  0
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_HALT_ON_ERROR_BITS   1
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_HALT_ON_ERROR_SHIFT  1

/*                                                              */
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_RUN_STOP_MASK        0x00000001
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_RUN_STOP_ALIGN       0
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_RUN_STOP_BITS        1
#define MISC1_TX_SW_DESC_LIST_CTRL_STS_TX_DMA_RUN_STOP_SHIFT       0


/*                                                                           
                               
                                                                           */
/*                                                   */
#define MISC1_TX_DMA_ERROR_STATUS_reserved0_MASK                   0xfffffc00
#define MISC1_TX_DMA_ERROR_STATUS_reserved0_ALIGN                  0
#define MISC1_TX_DMA_ERROR_STATUS_reserved0_BITS                   22
#define MISC1_TX_DMA_ERROR_STATUS_reserved0_SHIFT                  10

/*                                                                    */
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DESC_TX_ABORT_ERRORS_MASK  0x00000200
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DESC_TX_ABORT_ERRORS_ALIGN 0
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DESC_TX_ABORT_ERRORS_BITS  1
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DESC_TX_ABORT_ERRORS_SHIFT 9

/*                                                   */
#define MISC1_TX_DMA_ERROR_STATUS_reserved1_MASK                   0x00000100
#define MISC1_TX_DMA_ERROR_STATUS_reserved1_ALIGN                  0
#define MISC1_TX_DMA_ERROR_STATUS_reserved1_BITS                   1
#define MISC1_TX_DMA_ERROR_STATUS_reserved1_SHIFT                  8

/*                                                                    */
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DESC_TX_ABORT_ERRORS_MASK  0x00000080
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DESC_TX_ABORT_ERRORS_ALIGN 0
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DESC_TX_ABORT_ERRORS_BITS  1
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DESC_TX_ABORT_ERRORS_SHIFT 7

/*                                                   */
#define MISC1_TX_DMA_ERROR_STATUS_reserved2_MASK                   0x00000040
#define MISC1_TX_DMA_ERROR_STATUS_reserved2_ALIGN                  0
#define MISC1_TX_DMA_ERROR_STATUS_reserved2_BITS                   1
#define MISC1_TX_DMA_ERROR_STATUS_reserved2_SHIFT                  6

/*                                                                        */
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DMA_DATA_TX_ABORT_ERRORS_MASK 0x00000020
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DMA_DATA_TX_ABORT_ERRORS_ALIGN 0
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DMA_DATA_TX_ABORT_ERRORS_BITS 1
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_DMA_DATA_TX_ABORT_ERRORS_SHIFT 5

/*                                                                */
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_FIFO_FULL_ERRORS_MASK      0x00000010
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_FIFO_FULL_ERRORS_ALIGN     0
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_FIFO_FULL_ERRORS_BITS      1
#define MISC1_TX_DMA_ERROR_STATUS_TX_L1_FIFO_FULL_ERRORS_SHIFT     4

/*                                                   */
#define MISC1_TX_DMA_ERROR_STATUS_reserved3_MASK                   0x00000008
#define MISC1_TX_DMA_ERROR_STATUS_reserved3_ALIGN                  0
#define MISC1_TX_DMA_ERROR_STATUS_reserved3_BITS                   1
#define MISC1_TX_DMA_ERROR_STATUS_reserved3_SHIFT                  3

/*                                                                        */
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DMA_DATA_TX_ABORT_ERRORS_MASK 0x00000004
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DMA_DATA_TX_ABORT_ERRORS_ALIGN 0
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DMA_DATA_TX_ABORT_ERRORS_BITS 1
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_DMA_DATA_TX_ABORT_ERRORS_SHIFT 2

/*                                                                */
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_FIFO_FULL_ERRORS_MASK      0x00000002
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_FIFO_FULL_ERRORS_ALIGN     0
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_FIFO_FULL_ERRORS_BITS      1
#define MISC1_TX_DMA_ERROR_STATUS_TX_L0_FIFO_FULL_ERRORS_SHIFT     1

/*                                                   */
#define MISC1_TX_DMA_ERROR_STATUS_reserved4_MASK                   0x00000001
#define MISC1_TX_DMA_ERROR_STATUS_reserved4_ALIGN                  0
#define MISC1_TX_DMA_ERROR_STATUS_reserved4_BITS                   1
#define MISC1_TX_DMA_ERROR_STATUS_reserved4_SHIFT                  0


/*                                                                           
                             
                                                                           */
/*                                                 */
#define MISC1_Y_RX_ERROR_STATUS_reserved0_MASK                     0xffffc000
#define MISC1_Y_RX_ERROR_STATUS_reserved0_ALIGN                    0
#define MISC1_Y_RX_ERROR_STATUS_reserved0_BITS                     18
#define MISC1_Y_RX_ERROR_STATUS_reserved0_SHIFT                    14

/*                                                            */
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_MASK          0x00002000
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_ALIGN         0
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_BITS          1
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_SHIFT         13

/*                                                           */
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_MASK           0x00001000
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_ALIGN          0
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_BITS           1
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_SHIFT          12

/*                                                            */
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_MASK          0x00000800
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_ALIGN         0
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_BITS          1
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_SHIFT         11

/*                                                           */
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_MASK           0x00000400
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_ALIGN          0
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_BITS           1
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_SHIFT          10

/*                                                                  */
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_MASK    0x00000200
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_ALIGN   0
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_BITS    1
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_SHIFT   9

/*                                                 */
#define MISC1_Y_RX_ERROR_STATUS_reserved1_MASK                     0x00000100
#define MISC1_Y_RX_ERROR_STATUS_reserved1_ALIGN                    0
#define MISC1_Y_RX_ERROR_STATUS_reserved1_BITS                     1
#define MISC1_Y_RX_ERROR_STATUS_reserved1_SHIFT                    8

/*                                                                  */
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_MASK    0x00000080
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_ALIGN   0
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_BITS    1
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_SHIFT   7

/*                                                 */
#define MISC1_Y_RX_ERROR_STATUS_reserved2_MASK                     0x00000060
#define MISC1_Y_RX_ERROR_STATUS_reserved2_ALIGN                    0
#define MISC1_Y_RX_ERROR_STATUS_reserved2_BITS                     2
#define MISC1_Y_RX_ERROR_STATUS_reserved2_SHIFT                    5

/*                                                              */
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_MASK        0x00000010
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_ALIGN       0
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_BITS        1
#define MISC1_Y_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_SHIFT       4

/*                                                 */
#define MISC1_Y_RX_ERROR_STATUS_reserved3_MASK                     0x0000000c
#define MISC1_Y_RX_ERROR_STATUS_reserved3_ALIGN                    0
#define MISC1_Y_RX_ERROR_STATUS_reserved3_BITS                     2
#define MISC1_Y_RX_ERROR_STATUS_reserved3_SHIFT                    2

/*                                                              */
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_MASK        0x00000002
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_ALIGN       0
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_BITS        1
#define MISC1_Y_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_SHIFT       1

/*                                                 */
#define MISC1_Y_RX_ERROR_STATUS_reserved4_MASK                     0x00000001
#define MISC1_Y_RX_ERROR_STATUS_reserved4_ALIGN                    0
#define MISC1_Y_RX_ERROR_STATUS_reserved4_BITS                     1
#define MISC1_Y_RX_ERROR_STATUS_reserved4_SHIFT                    0


/*                                                                           
                              
                                                                           */
/*                                                  */
#define MISC1_UV_RX_ERROR_STATUS_reserved0_MASK                    0xffffc000
#define MISC1_UV_RX_ERROR_STATUS_reserved0_ALIGN                   0
#define MISC1_UV_RX_ERROR_STATUS_reserved0_BITS                    18
#define MISC1_UV_RX_ERROR_STATUS_reserved0_SHIFT                   14

/*                                                             */
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_MASK         0x00002000
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_ALIGN        0
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_BITS         1
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_UNDERRUN_ERROR_SHIFT        13

/*                                                            */
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_MASK          0x00001000
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_ALIGN         0
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_BITS          1
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_OVERRUN_ERROR_SHIFT         12

/*                                                             */
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_MASK         0x00000800
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_ALIGN        0
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_BITS         1
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_UNDERRUN_ERROR_SHIFT        11

/*                                                            */
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_MASK          0x00000400
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_ALIGN         0
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_BITS          1
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_OVERRUN_ERROR_SHIFT         10

/*                                                                   */
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_MASK   0x00000200
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_ALIGN  0
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_BITS   1
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_DESC_TX_ABORT_ERRORS_SHIFT  9

/*                                                  */
#define MISC1_UV_RX_ERROR_STATUS_reserved1_MASK                    0x00000100
#define MISC1_UV_RX_ERROR_STATUS_reserved1_ALIGN                   0
#define MISC1_UV_RX_ERROR_STATUS_reserved1_BITS                    1
#define MISC1_UV_RX_ERROR_STATUS_reserved1_SHIFT                   8

/*                                                                   */
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_MASK   0x00000080
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_ALIGN  0
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_BITS   1
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_DESC_TX_ABORT_ERRORS_SHIFT  7

/*                                                  */
#define MISC1_UV_RX_ERROR_STATUS_reserved2_MASK                    0x00000060
#define MISC1_UV_RX_ERROR_STATUS_reserved2_ALIGN                   0
#define MISC1_UV_RX_ERROR_STATUS_reserved2_BITS                    2
#define MISC1_UV_RX_ERROR_STATUS_reserved2_SHIFT                   5

/*                                                               */
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_MASK       0x00000010
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_ALIGN      0
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_BITS       1
#define MISC1_UV_RX_ERROR_STATUS_RX_L1_FIFO_FULL_ERRORS_SHIFT      4

/*                                                  */
#define MISC1_UV_RX_ERROR_STATUS_reserved3_MASK                    0x0000000c
#define MISC1_UV_RX_ERROR_STATUS_reserved3_ALIGN                   0
#define MISC1_UV_RX_ERROR_STATUS_reserved3_BITS                    2
#define MISC1_UV_RX_ERROR_STATUS_reserved3_SHIFT                   2

/*                                                               */
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_MASK       0x00000002
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_ALIGN      0
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_BITS       1
#define MISC1_UV_RX_ERROR_STATUS_RX_L0_FIFO_FULL_ERRORS_SHIFT      1

/*                                                  */
#define MISC1_UV_RX_ERROR_STATUS_reserved4_MASK                    0x00000001
#define MISC1_UV_RX_ERROR_STATUS_reserved4_ALIGN                   0
#define MISC1_UV_RX_ERROR_STATUS_reserved4_BITS                    1
#define MISC1_UV_RX_ERROR_STATUS_reserved4_SHIFT                   0

/*                                                                           
                        
                                                                           */
#endif /*                     */

/*             */

