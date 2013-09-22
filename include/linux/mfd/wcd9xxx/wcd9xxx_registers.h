#ifndef WCD9XXX_CODEC_DIGITAL_H

#define WCD9XXX_CODEC_DIGITAL_H

#define WCD9XXX_A_CHIP_CTL			(0x00)
#define WCD9XXX_A_CHIP_CTL__POR			(0x00000000)
#define WCD9XXX_A_CHIP_STATUS			(0x01)
#define WCD9XXX_A_CHIP_STATUS__POR		(0x00000000)
#define WCD9XXX_A_CHIP_ID_BYTE_0		(0x04)
#define WCD9XXX_A_CHIP_ID_BYTE_0__POR		(0x00000000)
#define WCD9XXX_A_CHIP_ID_BYTE_1		(0x05)
#define WCD9XXX_A_CHIP_ID_BYTE_1__POR		(0x00000000)
#define WCD9XXX_A_CHIP_ID_BYTE_2		(0x06)
#define WCD9XXX_A_CHIP_ID_BYTE_2__POR		(0x00000000)
#define WCD9XXX_A_CHIP_ID_BYTE_3		(0x07)
#define WCD9XXX_A_CHIP_ID_BYTE_3__POR		(0x00000001)
#define WCD9XXX_A_CHIP_VERSION			(0x08)
#define WCD9XXX_A_CHIP_VERSION__POR		(0x00000020)
#define WCD9XXX_A_SB_VERSION			(0x09)
#define WCD9XXX_A_SB_VERSION__POR		(0x00000010)
#define WCD9XXX_A_SLAVE_ID_1			(0x0C)
#define WCD9XXX_A_SLAVE_ID_1__POR		(0x00000077)
#define WCD9XXX_A_SLAVE_ID_2			(0x0D)
#define WCD9XXX_A_SLAVE_ID_2__POR		(0x00000066)
#define WCD9XXX_A_SLAVE_ID_3			(0x0E)
#define WCD9XXX_A_SLAVE_ID_3__POR		(0x00000055)
#define WCD9XXX_A_CDC_CTL			(0x80)
#define WCD9XXX_A_CDC_CTL__POR			(0x00000000)
#define WCD9XXX_A_LEAKAGE_CTL			(0x88)
#define WCD9XXX_A_LEAKAGE_CTL__POR		(0x00000004)
#define WCD9XXX_A_INTR_MODE			(0x90)
#define WCD9XXX_A_INTR_MASK0			(0x94)
#define WCD9XXX_A_INTR_STATUS0			(0x98)
#define WCD9XXX_A_INTR_CLEAR0			(0x9C)
#define WCD9XXX_A_INTR_LEVEL0			(0xA0)
#define WCD9XXX_A_INTR_LEVEL1			(0xA1)
#define WCD9XXX_A_INTR_LEVEL2			(0xA2)
#define WCD9XXX_A_RX_HPH_CNP_EN			(0x1AB)
#define WCD9XXX_A_RX_HPH_CNP_EN__POR		(0x80)
#define WCD9XXX_A_RX_HPH_CNP_EN			(0x1AB)
#define WCD9XXX_A_RX_HPH_CNP_EN__POR		(0x80)
#define WCD9XXX_A_BIAS_CENTRAL_BG_CTL		(0x101)
#define WCD9XXX_A_BIAS_CENTRAL_BG_CTL__POR	(0x50)
#define WCD9XXX_A_CLK_BUFF_EN1			(0x108)
#define WCD9XXX_A_CLK_BUFF_EN1__POR		(0x04)
#define WCD9XXX_A_CLK_BUFF_EN2			(0x109)
#define WCD9XXX_A_CLK_BUFF_EN2__POR		(0x02)
#define WCD9XXX_A_RX_COM_BIAS			(0x1A2)
#define WCD9XXX_A_RX_COM_BIAS__POR		(0x00)
#define WCD9XXX_A_RC_OSC_FREQ			(0x1FA)
#define WCD9XXX_A_RC_OSC_FREQ__POR		(0x46)
#define WCD9XXX_A_BIAS_OSC_BG_CTL		(0x105)
#define WCD9XXX_A_BIAS_OSC_BG_CTL__POR		(0x16)
#define WCD9XXX_A_RC_OSC_TEST			(0x1FB)
#define WCD9XXX_A_RC_OSC_TEST__POR		(0x0A)
#define WCD9XXX_A_CDC_CLK_MCLK_CTL		(0x311)
#define WCD9XXX_A_CDC_CLK_MCLK_CTL__POR		(0x00)

#define WCD9XXX_A_CDC_MBHC_EN_CTL		(0x3C0)
#define WCD9XXX_A_CDC_MBHC_EN_CTL__POR		(0x00)
#define WCD9XXX_A_CDC_MBHC_FIR_B1_CFG		(0x3C1)
#define WCD9XXX_A_CDC_MBHC_FIR_B1_CFG__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_FIR_B2_CFG		(0x3C2)
#define WCD9XXX_A_CDC_MBHC_FIR_B2_CFG__POR	(0x06)
#define WCD9XXX_A_CDC_MBHC_TIMER_B1_CTL		(0x3C3)
#define WCD9XXX_A_CDC_MBHC_TIMER_B1_CTL__POR	(0x03)
#define WCD9XXX_A_CDC_MBHC_TIMER_B2_CTL		(0x3C4)
#define WCD9XXX_A_CDC_MBHC_TIMER_B2_CTL__POR	(0x09)
#define WCD9XXX_A_CDC_MBHC_TIMER_B3_CTL		(0x3C5)
#define WCD9XXX_A_CDC_MBHC_TIMER_B3_CTL__POR	(0x1E)
#define WCD9XXX_A_CDC_MBHC_TIMER_B4_CTL		(0x3C6)
#define WCD9XXX_A_CDC_MBHC_TIMER_B4_CTL__POR	(0x45)
#define WCD9XXX_A_CDC_MBHC_TIMER_B5_CTL		(0x3C7)
#define WCD9XXX_A_CDC_MBHC_TIMER_B5_CTL__POR	(0x04)
#define WCD9XXX_A_CDC_MBHC_TIMER_B6_CTL		(0x3C8)
#define WCD9XXX_A_CDC_MBHC_TIMER_B6_CTL__POR	(0x78)
#define WCD9XXX_A_CDC_MBHC_B1_STATUS		(0x3C9)
#define WCD9XXX_A_CDC_MBHC_B1_STATUS__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_B2_STATUS		(0x3CA)
#define WCD9XXX_A_CDC_MBHC_B2_STATUS__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_B3_STATUS		(0x3CB)
#define WCD9XXX_A_CDC_MBHC_B3_STATUS__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_B4_STATUS		(0x3CC)
#define WCD9XXX_A_CDC_MBHC_B4_STATUS__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_B5_STATUS		(0x3CD)
#define WCD9XXX_A_CDC_MBHC_B5_STATUS__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_B1_CTL		(0x3CE)
#define WCD9XXX_A_CDC_MBHC_B1_CTL__POR		(0xC0)
#define WCD9XXX_A_CDC_MBHC_B2_CTL		(0x3CF)
#define WCD9XXX_A_CDC_MBHC_B2_CTL__POR		(0x5D)
#define WCD9XXX_A_CDC_MBHC_VOLT_B1_CTL		(0x3D0)
#define WCD9XXX_A_CDC_MBHC_VOLT_B1_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_VOLT_B2_CTL		(0x3D1)
#define WCD9XXX_A_CDC_MBHC_VOLT_B2_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_VOLT_B3_CTL		(0x3D2)
#define WCD9XXX_A_CDC_MBHC_VOLT_B3_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_VOLT_B4_CTL		(0x3D3)
#define WCD9XXX_A_CDC_MBHC_VOLT_B4_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_VOLT_B5_CTL		(0x3D4)
#define WCD9XXX_A_CDC_MBHC_VOLT_B5_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_VOLT_B6_CTL		(0x3D5)
#define WCD9XXX_A_CDC_MBHC_VOLT_B6_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_VOLT_B7_CTL		(0x3D6)
#define WCD9XXX_A_CDC_MBHC_VOLT_B7_CTL__POR	(0xFF)
#define WCD9XXX_A_CDC_MBHC_VOLT_B8_CTL		(0x3D7)
#define WCD9XXX_A_CDC_MBHC_VOLT_B8_CTL__POR	(0x07)
#define WCD9XXX_A_CDC_MBHC_VOLT_B9_CTL		(0x3D8)
#define WCD9XXX_A_CDC_MBHC_VOLT_B9_CTL__POR	(0xFF)
#define WCD9XXX_A_CDC_MBHC_VOLT_B10_CTL		(0x3D9)
#define WCD9XXX_A_CDC_MBHC_VOLT_B10_CTL__POR	(0x7F)
#define WCD9XXX_A_CDC_MBHC_VOLT_B11_CTL		(0x3DA)
#define WCD9XXX_A_CDC_MBHC_VOLT_B11_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_VOLT_B12_CTL		(0x3DB)
#define WCD9XXX_A_CDC_MBHC_VOLT_B12_CTL__POR	(0x80)
#define WCD9XXX_A_CDC_MBHC_CLK_CTL		(0x3DC)
#define WCD9XXX_A_CDC_MBHC_CLK_CTL__POR		(0x00)
#define WCD9XXX_A_CDC_MBHC_INT_CTL		(0x3DD)
#define WCD9XXX_A_CDC_MBHC_INT_CTL__POR		(0x00)
#define WCD9XXX_A_CDC_MBHC_DEBUG_CTL		(0x3DE)
#define WCD9XXX_A_CDC_MBHC_DEBUG_CTL__POR	(0x00)
#define WCD9XXX_A_CDC_MBHC_SPARE		(0x3DF)
#define WCD9XXX_A_CDC_MBHC_SPARE__POR		(0x00)
#define WCD9XXX_A_MBHC_SCALING_MUX_1		(0x14E)
#define WCD9XXX_A_MBHC_SCALING_MUX_1__POR	(0x00)
#define WCD9XXX_A_RX_HPH_OCP_CTL		(0x1AA)
#define WCD9XXX_A_RX_HPH_OCP_CTL__POR		(0x68)
#define WCD9XXX_A_MICB_1_CTL			(0x12B)
#define WCD9XXX_A_MICB_1_CTL__POR		(0x16)
#define WCD9XXX_A_MICB_1_INT_RBIAS		(0x12C)
#define WCD9XXX_A_MICB_1_INT_RBIAS__POR		(0x24)
#define WCD9XXX_A_MICB_1_MBHC			(0x12D)
#define WCD9XXX_A_MICB_1_MBHC__POR		(0x01)
#define WCD9XXX_A_MICB_CFILT_2_CTL		(0x12E)
#define WCD9XXX_A_MICB_CFILT_2_CTL__POR		(0x40)
#define WCD9XXX_A_MICB_CFILT_2_VAL		(0x12F)
#define WCD9XXX_A_MICB_CFILT_2_VAL__POR		(0x80)
#define WCD9XXX_A_MICB_CFILT_2_PRECHRG		(0x130)
#define WCD9XXX_A_MICB_CFILT_2_PRECHRG__POR	(0x38)
#define WCD9XXX_A_MICB_2_CTL			(0x131)
#define WCD9XXX_A_MICB_2_CTL__POR		(0x16)
#define WCD9XXX_A_MICB_2_INT_RBIAS		(0x132)
#define WCD9XXX_A_MICB_2_INT_RBIAS__POR		(0x24)
#define WCD9XXX_A_MICB_2_MBHC			(0x133)
#define WCD9XXX_A_MICB_2_MBHC__POR		(0x02)
#define WCD9XXX_A_MICB_CFILT_3_CTL		(0x134)
#define WCD9XXX_A_MICB_CFILT_3_CTL__POR		(0x40)
#define WCD9XXX_A_MICB_CFILT_3_VAL		(0x135)
#define WCD9XXX_A_MICB_CFILT_3_VAL__POR		(0x80)
#define WCD9XXX_A_MICB_CFILT_3_PRECHRG		(0x136)
#define WCD9XXX_A_MICB_CFILT_3_PRECHRG__POR	(0x38)
#define WCD9XXX_A_MICB_3_CTL			(0x137)
#define WCD9XXX_A_MICB_3_CTL__POR		(0x16)
#define WCD9XXX_A_MICB_3_INT_RBIAS		(0x138)
#define WCD9XXX_A_MICB_3_INT_RBIAS__POR		(0x24)
#define WCD9XXX_A_MICB_3_MBHC			(0x139)
#define WCD9XXX_A_MICB_3_MBHC__POR		(0x00)
#define WCD9XXX_A_MICB_4_CTL			(0x13D)
#define WCD9XXX_A_MICB_4_CTL__POR		(0x16)
#define WCD9XXX_A_MICB_4_INT_RBIAS		(0x13E)
#define WCD9XXX_A_MICB_4_INT_RBIAS__POR		(0x24)
#define WCD9XXX_A_MICB_4_MBHC			(0x13F)
#define WCD9XXX_A_MICB_4_MBHC__POR		(0x01)
#define WCD9XXX_A_MICB_CFILT_1_VAL		(0x129)
#define WCD9XXX_A_MICB_CFILT_1_VAL__POR		(0x80)
#define WCD9XXX_A_RX_HPH_L_STATUS		(0x1B3)
#define WCD9XXX_A_RX_HPH_L_STATUS__POR		(0x00)
#define WCD9XXX_A_MBHC_HPH			(0x1FE)
#define WCD9XXX_A_MBHC_HPH__POR			(0x44)
#define WCD9XXX_A_RX_HPH_CNP_WG_TIME		(0x1AD)
#define WCD9XXX_A_RX_HPH_CNP_WG_TIME__POR	(0x2A)
#define WCD9XXX_A_RX_HPH_R_DAC_CTL		(0x1B7)
#define WCD9XXX_A_RX_HPH_R_DAC_CTL__POR		(0x00)
#define WCD9XXX_A_RX_HPH_L_DAC_CTL		(0x1B1)
#define WCD9XXX_A_RX_HPH_L_DAC_CTL__POR		(0x00)
#define WCD9XXX_A_TX_7_MBHC_EN			(0x171)
#define WCD9XXX_A_TX_7_MBHC_EN__POR		(0x0C)
#define WCD9XXX_A_PIN_CTL_OE0			(0x010)
#define WCD9XXX_A_PIN_CTL_OE0__POR		(0x00)
#define WCD9XXX_A_PIN_CTL_OE1			(0x011)
#define WCD9XXX_A_PIN_CTL_OE1__POR		(0x00)
#define WCD9XXX_A_MICB_CFILT_1_CTL		(0x128)
#define WCD9XXX_A_LDO_H_MODE_1			(0x110)
#define WCD9XXX_A_LDO_H_MODE_1__POR		(0x65)
#define WCD9XXX_A_MICB_CFILT_1_CTL__POR		(0x40)
#define WCD9XXX_A_TX_7_MBHC_TEST_CTL		(0x174)
#define WCD9XXX_A_TX_7_MBHC_TEST_CTL__POR	(0x38)
#define WCD9XXX_A_MBHC_SCALING_MUX_2		(0x14F)
#define WCD9XXX_A_MBHC_SCALING_MUX_2__POR	(0x80)
#define WCD9XXX_A_TX_COM_BIAS			(0x14C)
#define WCD9XXX_A_TX_COM_BIAS__POR		(0xF0)

#define WCD9XXX_A_MBHC_INSERT_DETECT		(0x14A) /*                 */
#define WCD9XXX_A_MBHC_INSERT_DETECT__POR	(0x00)
#define WCD9XXX_A_MBHC_INSERT_DET_STATUS	(0x14B) /*                 */
#define WCD9XXX_A_MBHC_INSERT_DET_STATUS__POR	(0x00)
#define WCD9XXX_A_MAD_ANA_CTRL			(0x150)
#define WCD9XXX_A_MAD_ANA_CTRL__POR		(0xF1)


#define WCD9XXX_A_CDC_CLK_OTHR_CTL			(0x30C)
#define WCD9XXX_A_CDC_CLK_OTHR_CTL__POR				(0x00)

/*                                  */
#define WCD9XXX_A_BUCK_MODE_1			(0x181)
#define WCD9XXX_A_BUCK_MODE_1__POR				(0x21)
#define WCD9XXX_A_BUCK_MODE_2			(0x182)
#define WCD9XXX_A_BUCK_MODE_2__POR				(0xFF)
#define WCD9XXX_A_BUCK_MODE_3			(0x183)
#define WCD9XXX_A_BUCK_MODE_3__POR				(0xCC)
#define WCD9XXX_A_BUCK_MODE_4			(0x184)
#define WCD9XXX_A_BUCK_MODE_4__POR				(0x3A)
#define WCD9XXX_A_BUCK_MODE_5			(0x185)
#define WCD9XXX_A_BUCK_MODE_5__POR				(0x00)
#define WCD9XXX_A_BUCK_CTRL_VCL_1			(0x186)
#define WCD9XXX_A_BUCK_CTRL_VCL_1__POR				(0x48)
#define WCD9XXX_A_BUCK_CTRL_VCL_2			(0x187)
#define WCD9XXX_A_BUCK_CTRL_VCL_2__POR				(0xA3)
#define WCD9XXX_A_BUCK_CTRL_VCL_3			(0x188)
#define WCD9XXX_A_BUCK_CTRL_VCL_3__POR				(0x82)
#define WCD9XXX_A_BUCK_CTRL_CCL_1			(0x189)
#define WCD9XXX_A_BUCK_CTRL_CCL_1__POR				(0xAB)
#define WCD9XXX_A_BUCK_CTRL_CCL_2			(0x18A)
#define WCD9XXX_A_BUCK_CTRL_CCL_2__POR				(0xDC)
#define WCD9XXX_A_BUCK_CTRL_CCL_3			(0x18B)
#define WCD9XXX_A_BUCK_CTRL_CCL_3__POR				(0x6A)
#define WCD9XXX_A_BUCK_CTRL_CCL_4			(0x18C)
#define WCD9XXX_A_BUCK_CTRL_CCL_4__POR				(0x58)
#define WCD9XXX_A_BUCK_CTRL_PWM_DRVR_1			(0x18D)
#define WCD9XXX_A_BUCK_CTRL_PWM_DRVR_1__POR				(0x50)
#define WCD9XXX_A_BUCK_CTRL_PWM_DRVR_2			(0x18E)
#define WCD9XXX_A_BUCK_CTRL_PWM_DRVR_2__POR				(0x64)
#define WCD9XXX_A_BUCK_CTRL_PWM_DRVR_3			(0x18F)
#define WCD9XXX_A_BUCK_CTRL_PWM_DRVR_3__POR				(0x77)
#define WCD9XXX_A_BUCK_TMUX_A_D			(0x190)
#define WCD9XXX_A_BUCK_TMUX_A_D__POR				(0x00)
#define WCD9XXX_A_NCP_EN			(0x192)
#define WCD9XXX_A_NCP_EN__POR				(0xFE)
#define WCD9XXX_A_NCP_STATIC			(0x194)
#define WCD9XXX_A_NCP_STATIC__POR				(0x28)
#define WCD9XXX_A_NCP_BUCKREF			(0x191)
#define WCD9XXX_A_NCP_BUCKREF__POR				(0x00)
#define WCD9XXX_A_CDC_CLSH_B1_CTL			(0x320)
#define WCD9XXX_A_CDC_CLSH_B1_CTL__POR				(0xE4)
#define WCD9XXX_A_CDC_CLSH_B2_CTL			(0x321)
#define WCD9XXX_A_CDC_CLSH_B2_CTL__POR				(0x00)
#define WCD9XXX_A_CDC_CLSH_B3_CTL			(0x322)
#define WCD9XXX_A_CDC_CLSH_B3_CTL__POR				(0x00)
#define WCD9XXX_A_CDC_CLSH_BUCK_NCP_VARS			(0x323)
#define WCD9XXX_A_CDC_CLSH_BUCK_NCP_VARS__POR			(0x00)
#define WCD9XXX_A_CDC_CLSH_IDLE_HPH_THSD			(0x324)
#define WCD9XXX_A_CDC_CLSH_IDLE_HPH_THSD__POR			(0x12)
#define WCD9XXX_A_CDC_CLSH_IDLE_EAR_THSD			(0x325)
#define WCD9XXX_A_CDC_CLSH_IDLE_EAR_THSD__POR			(0x0C)
#define WCD9XXX_A_CDC_CLSH_FCLKONLY_HPH_THSD			(0x326)
#define WCD9XXX_A_CDC_CLSH_FCLKONLY_HPH_THSD__POR		(0x18)
#define WCD9XXX_A_CDC_CLSH_FCLKONLY_EAR_THSD			(0x327)
#define WCD9XXX_A_CDC_CLSH_FCLKONLY_EAR_THSD__POR		(0x23)
#define WCD9XXX_A_CDC_CLSH_K_ADDR			(0x328)
#define WCD9XXX_A_CDC_CLSH_K_ADDR__POR				(0x00)
#define WCD9XXX_A_CDC_CLSH_K_DATA			(0x329)
#define WCD9XXX_A_CDC_CLSH_K_DATA__POR				(0xA4)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_HPH_L			(0x32A)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_HPH_L__POR				(0xD7)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_HPH_U			(0x32B)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_HPH_U__POR				(0x05)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_EAR_L			(0x32C)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_EAR_L__POR				(0x60)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_EAR_U			(0x32D)
#define WCD9XXX_A_CDC_CLSH_I_PA_FACT_EAR_U__POR				(0x09)
#define WCD9XXX_A_CDC_CLSH_V_PA_HD_EAR			(0x32E)
#define WCD9XXX_A_CDC_CLSH_V_PA_HD_EAR__POR				(0x00)
#define WCD9XXX_A_CDC_CLSH_V_PA_HD_HPH			(0x32F)
#define WCD9XXX_A_CDC_CLSH_V_PA_HD_HPH__POR				(0x00)
#define WCD9XXX_A_CDC_CLSH_V_PA_MIN_EAR			(0x330)
#define WCD9XXX_A_CDC_CLSH_V_PA_MIN_EAR__POR				(0x00)
#define WCD9XXX_A_CDC_CLSH_V_PA_MIN_HPH			(0x331)
#define WCD9XXX_A_CDC_CLSH_V_PA_MIN_HPH__POR				(0x00)


#endif
