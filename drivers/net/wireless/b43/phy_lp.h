#ifndef LINUX_B43_PHY_LP_H_
#define LINUX_B43_PHY_LP_H_

/*                            */


/*                             */
#define B43_LPPHY_B_VERSION			B43_PHY_CCK(0x00) /*               */
#define B43_LPPHY_B_BBCONFIG			B43_PHY_CCK(0x01) /*                */
#define B43_LPPHY_B_RX_STAT0			B43_PHY_CCK(0x04) /*                  */
#define B43_LPPHY_B_RX_STAT1			B43_PHY_CCK(0x05) /*                  */
#define B43_LPPHY_B_CRS_THRESH			B43_PHY_CCK(0x06) /*                  */
#define B43_LPPHY_B_TXERROR			B43_PHY_CCK(0x07) /*               */
#define B43_LPPHY_B_CHANNEL			B43_PHY_CCK(0x08) /*               */
#define B43_LPPHY_B_WORKAROUND			B43_PHY_CCK(0x09) /*                  */
#define B43_LPPHY_B_TEST			B43_PHY_CCK(0x0A) /*            */
#define B43_LPPHY_B_FOURWIRE_ADDR		B43_PHY_CCK(0x0B) /*                        */
#define B43_LPPHY_B_FOURWIRE_DATA_HI		B43_PHY_CCK(0x0C) /*                        */
#define B43_LPPHY_B_FOURWIRE_DATA_LO		B43_PHY_CCK(0x0D) /*                        */
#define B43_LPPHY_B_BIST_STAT			B43_PHY_CCK(0x0E) /*                   */
#define B43_LPPHY_PA_RAMP_TX_TO			B43_PHY_CCK(0x10) /*                    */
#define B43_LPPHY_RF_SYNTH_DC_TIMER		B43_PHY_CCK(0x11) /*                   */
#define B43_LPPHY_PA_RAMP_TX_TIME_IN		B43_PHY_CCK(0x12) /*                    */
#define B43_LPPHY_RX_FILTER_TIME_IN		B43_PHY_CCK(0x13) /*                   */
#define B43_LPPHY_PLL_COEFF_S			B43_PHY_CCK(0x18) /*                    */
#define B43_LPPHY_PLL_OUT			B43_PHY_CCK(0x19) /*         */
#define B43_LPPHY_RSSI_THRES			B43_PHY_CCK(0x20) /*                */
#define B43_LPPHY_IQ_THRES_HH			B43_PHY_CCK(0x21) /*                 */
#define B43_LPPHY_IQ_THRES_H			B43_PHY_CCK(0x22) /*                */
#define B43_LPPHY_IQ_THRES_L			B43_PHY_CCK(0x23) /*                */
#define B43_LPPHY_IQ_THRES_LL			B43_PHY_CCK(0x24) /*                 */
#define B43_LPPHY_AGC_GAIN			B43_PHY_CCK(0x25) /*          */
#define B43_LPPHY_LNA_GAIN_RANGE		B43_PHY_CCK(0x26) /*                */
#define B43_LPPHY_JSSI				B43_PHY_CCK(0x27) /*      */
#define B43_LPPHY_TSSI_CTL			B43_PHY_CCK(0x28) /*              */
#define B43_LPPHY_TSSI				B43_PHY_CCK(0x29) /*      */
#define B43_LPPHY_TR_LOSS			B43_PHY_CCK(0x2A) /*         */
#define B43_LPPHY_LO_LEAKAGE			B43_PHY_CCK(0x2B) /*            */
#define B43_LPPHY_LO_RSSIACC			B43_PHY_CCK(0x2C) /*            */
#define B43_LPPHY_LO_IQ_MAG_ACC			B43_PHY_CCK(0x2D) /*               */
#define B43_LPPHY_TX_DCOFFSET1			B43_PHY_CCK(0x2E) /*              */
#define B43_LPPHY_TX_DCOFFSET2			B43_PHY_CCK(0x2F) /*              */
#define B43_LPPHY_SYNCPEAKCNT			B43_PHY_CCK(0x30) /*             */
#define B43_LPPHY_SYNCFREQ			B43_PHY_CCK(0x31) /*          */
#define B43_LPPHY_SYNCDIVERSITYCTL		B43_PHY_CCK(0x32) /*                      */
#define B43_LPPHY_PEAKENERGYL			B43_PHY_CCK(0x33) /*             */
#define B43_LPPHY_PEAKENERGYH			B43_PHY_CCK(0x34) /*             */
#define B43_LPPHY_SYNCCTL			B43_PHY_CCK(0x35) /*             */
#define B43_LPPHY_DSSSSTEP			B43_PHY_CCK(0x38) /*          */
#define B43_LPPHY_DSSSWARMUP			B43_PHY_CCK(0x39) /*            */
#define B43_LPPHY_DSSSSIGPOW			B43_PHY_CCK(0x3D) /*            */
#define B43_LPPHY_SFDDETECTBLOCKTIME		B43_PHY_CCK(0x40) /*                    */
#define B43_LPPHY_SFDTO				B43_PHY_CCK(0x41) /*            */
#define B43_LPPHY_SFDCTL			B43_PHY_CCK(0x42) /*            */
#define B43_LPPHY_RXDBG				B43_PHY_CCK(0x43) /*         */
#define B43_LPPHY_RX_DELAYCOMP			B43_PHY_CCK(0x44) /*              */
#define B43_LPPHY_CRSDROPOUTTO			B43_PHY_CCK(0x45) /*                   */
#define B43_LPPHY_PSEUDOSHORTTO			B43_PHY_CCK(0x46) /*                    */
#define B43_LPPHY_PR3931			B43_PHY_CCK(0x47) /*        */
#define B43_LPPHY_DSSSCOEFF1			B43_PHY_CCK(0x48) /*            */
#define B43_LPPHY_DSSSCOEFF2			B43_PHY_CCK(0x49) /*            */
#define B43_LPPHY_CCKCOEFF1			B43_PHY_CCK(0x4A) /*           */
#define B43_LPPHY_CCKCOEFF2			B43_PHY_CCK(0x4B) /*           */
#define B43_LPPHY_TRCORR			B43_PHY_CCK(0x4C) /*        */
#define B43_LPPHY_ANGLESCALE			B43_PHY_CCK(0x4D) /*            */
#define B43_LPPHY_OPTIONALMODES2		B43_PHY_CCK(0x4F) /*                */
#define B43_LPPHY_CCKLMSSTEPSIZE		B43_PHY_CCK(0x50) /*                */
#define B43_LPPHY_DFEBYPASS			B43_PHY_CCK(0x51) /*           */
#define B43_LPPHY_CCKSTARTDELAYLONG		B43_PHY_CCK(0x52) /*                   */
#define B43_LPPHY_CCKSTARTDELAYSHORT		B43_PHY_CCK(0x53) /*                    */
#define B43_LPPHY_PPROCCHDELAY			B43_PHY_CCK(0x54) /*              */
#define B43_LPPHY_PPROCONOFF			B43_PHY_CCK(0x55) /*            */
#define B43_LPPHY_LNAGAINTWOBIT10		B43_PHY_CCK(0x5B) /*                 */
#define B43_LPPHY_LNAGAINTWOBIT32		B43_PHY_CCK(0x5C) /*                 */
#define B43_LPPHY_OPTIONALMODES			B43_PHY_CCK(0x5D) /*               */
#define B43_LPPHY_B_RX_STAT2			B43_PHY_CCK(0x5E) /*                  */
#define B43_LPPHY_B_RX_STAT3			B43_PHY_CCK(0x5F) /*                  */
#define B43_LPPHY_PWDNDACDELAY			B43_PHY_CCK(0x63) /*              */
#define B43_LPPHY_FINEDIGIGAIN_CTL		B43_PHY_CCK(0x67) /*                      */
#define B43_LPPHY_LG2GAINTBLLNA8		B43_PHY_CCK(0x68) /*                */
#define B43_LPPHY_LG2GAINTBLLNA28		B43_PHY_CCK(0x69) /*                 */
#define B43_LPPHY_GAINTBLLNATRSW		B43_PHY_CCK(0x6A) /*                */
#define B43_LPPHY_PEAKENERGY			B43_PHY_CCK(0x6B) /*            */
#define B43_LPPHY_LG2INITGAIN			B43_PHY_CCK(0x6C) /*             */
#define B43_LPPHY_BLANKCOUNTLNAPGA		B43_PHY_CCK(0x6D) /*                  */
#define B43_LPPHY_LNAGAINTWOBIT54		B43_PHY_CCK(0x6E) /*                 */
#define B43_LPPHY_LNAGAINTWOBIT76		B43_PHY_CCK(0x6F) /*                 */
#define B43_LPPHY_JSSICTL			B43_PHY_CCK(0x70) /*             */
#define B43_LPPHY_LG2GAINTBLLNA44		B43_PHY_CCK(0x71) /*                 */
#define B43_LPPHY_LG2GAINTBLLNA62		B43_PHY_CCK(0x72) /*                 */

/*                              */
#define B43_LPPHY_VERSION			B43_PHY_OFDM(0x00) /*         */
#define B43_LPPHY_BBCONFIG			B43_PHY_OFDM(0x01) /*          */
#define B43_LPPHY_RX_STAT0			B43_PHY_OFDM(0x04) /*            */
#define B43_LPPHY_RX_STAT1			B43_PHY_OFDM(0x05) /*            */
#define B43_LPPHY_TX_ERROR			B43_PHY_OFDM(0x07) /*          */
#define B43_LPPHY_CHANNEL			B43_PHY_OFDM(0x08) /*         */
#define B43_LPPHY_WORKAROUND			B43_PHY_OFDM(0x09) /*            */
#define B43_LPPHY_FOURWIRE_ADDR			B43_PHY_OFDM(0x0B) /*                  */
#define B43_LPPHY_FOURWIREDATAHI		B43_PHY_OFDM(0x0C) /*                */
#define B43_LPPHY_FOURWIREDATALO		B43_PHY_OFDM(0x0D) /*                */
#define B43_LPPHY_BISTSTAT0			B43_PHY_OFDM(0x0E) /*             */
#define B43_LPPHY_BISTSTAT1			B43_PHY_OFDM(0x0F) /*             */
#define B43_LPPHY_CRSGAIN_CTL			B43_PHY_OFDM(0x10) /*                 */
#define B43_LPPHY_OFDMPWR_THRESH0		B43_PHY_OFDM(0x11) /*                   */
#define B43_LPPHY_OFDMPWR_THRESH1		B43_PHY_OFDM(0x12) /*                   */
#define B43_LPPHY_OFDMPWR_THRESH2		B43_PHY_OFDM(0x13) /*                   */
#define B43_LPPHY_DSSSPWR_THRESH0		B43_PHY_OFDM(0x14) /*                   */
#define B43_LPPHY_DSSSPWR_THRESH1		B43_PHY_OFDM(0x15) /*                   */
#define B43_LPPHY_MINPWR_LEVEL			B43_PHY_OFDM(0x16) /*                */
#define B43_LPPHY_OFDMSYNCTHRESH0		B43_PHY_OFDM(0x17) /*                 */
#define B43_LPPHY_OFDMSYNCTHRESH1		B43_PHY_OFDM(0x18) /*                 */
#define B43_LPPHY_FINEFREQEST			B43_PHY_OFDM(0x19) /*             */
#define B43_LPPHY_IDLEAFTERPKTRXTO		B43_PHY_OFDM(0x1A) /*                       */
#define B43_LPPHY_LTRN_CTL			B43_PHY_OFDM(0x1B) /*              */
#define B43_LPPHY_DCOFFSETTRANSIENT		B43_PHY_OFDM(0x1C) /*                   */
#define B43_LPPHY_PREAMBLEINTO			B43_PHY_OFDM(0x1D) /*                   */
#define B43_LPPHY_PREAMBLECONFIRMTO		B43_PHY_OFDM(0x1E) /*                        */
#define B43_LPPHY_CLIPTHRESH			B43_PHY_OFDM(0x1F) /*            */
#define B43_LPPHY_CLIPCTRTHRESH			B43_PHY_OFDM(0x20) /*               */
#define B43_LPPHY_OFDMSYNCTIMER_CTL		B43_PHY_OFDM(0x21) /*                       */
#define B43_LPPHY_WAITFORPHYSELTO		B43_PHY_OFDM(0x22) /*                      */
#define B43_LPPHY_HIGAINDB			B43_PHY_OFDM(0x23) /*          */
#define B43_LPPHY_LOWGAINDB			B43_PHY_OFDM(0x24) /*           */
#define B43_LPPHY_VERYLOWGAINDB			B43_PHY_OFDM(0x25) /*               */
#define B43_LPPHY_GAINMISMATCH			B43_PHY_OFDM(0x26) /*              */
#define B43_LPPHY_GAINDIRECTMISMATCH		B43_PHY_OFDM(0x27) /*                    */
#define B43_LPPHY_PWR_THRESH0			B43_PHY_OFDM(0x28) /*               */
#define B43_LPPHY_PWR_THRESH1			B43_PHY_OFDM(0x29) /*               */
#define B43_LPPHY_DETECTOR_DELAY_ADJUST		B43_PHY_OFDM(0x2A) /*                       */
#define B43_LPPHY_REDUCED_DETECTOR_DELAY	B43_PHY_OFDM(0x2B) /*                        */
#define B43_LPPHY_DATA_TO			B43_PHY_OFDM(0x2C) /*              */
#define B43_LPPHY_CORRELATOR_DIS_DELAY		B43_PHY_OFDM(0x2D) /*                      */
#define B43_LPPHY_DIVERSITY_GAINBACK		B43_PHY_OFDM(0x2E) /*                    */
#define B43_LPPHY_DSSS_CONFIRM_CNT		B43_PHY_OFDM(0x2F) /*                  */
#define B43_LPPHY_DC_BLANK_INT			B43_PHY_OFDM(0x30) /*                   */
#define B43_LPPHY_GAIN_MISMATCH_LIMIT		B43_PHY_OFDM(0x31) /*                     */
#define B43_LPPHY_CRS_ED_THRESH			B43_PHY_OFDM(0x32) /*               */
#define B43_LPPHY_PHASE_SHIFT_CTL		B43_PHY_OFDM(0x33) /*                     */
#define B43_LPPHY_INPUT_PWRDB			B43_PHY_OFDM(0x34) /*               */
#define B43_LPPHY_OFDM_SYNC_CTL			B43_PHY_OFDM(0x35) /*                   */
#define B43_LPPHY_AFE_ADC_CTL_0			B43_PHY_OFDM(0x36) /*                   */
#define B43_LPPHY_AFE_ADC_CTL_1			B43_PHY_OFDM(0x37) /*                   */
#define B43_LPPHY_AFE_ADC_CTL_2			B43_PHY_OFDM(0x38) /*                   */
#define B43_LPPHY_AFE_DAC_CTL			B43_PHY_OFDM(0x39) /*                 */
#define B43_LPPHY_AFE_CTL			B43_PHY_OFDM(0x3A) /*             */
#define B43_LPPHY_AFE_CTL_OVR			B43_PHY_OFDM(0x3B) /*                 */
#define B43_LPPHY_AFE_CTL_OVRVAL		B43_PHY_OFDM(0x3C) /*                    */
#define B43_LPPHY_AFE_RSSI_CTL_0		B43_PHY_OFDM(0x3D) /*                    */
#define B43_LPPHY_AFE_RSSI_CTL_1		B43_PHY_OFDM(0x3E) /*                    */
#define B43_LPPHY_AFE_RSSI_SEL			B43_PHY_OFDM(0x3F) /*              */
#define B43_LPPHY_RADAR_THRESH			B43_PHY_OFDM(0x40) /*              */
#define B43_LPPHY_RADAR_BLANK_INT		B43_PHY_OFDM(0x41) /*                      */
#define B43_LPPHY_RADAR_MIN_FM_INT		B43_PHY_OFDM(0x42) /*                       */
#define B43_LPPHY_RADAR_GAIN_TO			B43_PHY_OFDM(0x43) /*                    */
#define B43_LPPHY_RADAR_PULSE_TO		B43_PHY_OFDM(0x44) /*                     */
#define B43_LPPHY_RADAR_DETECT_FM_CTL		B43_PHY_OFDM(0x45) /*                         */
#define B43_LPPHY_RADAR_DETECT_EN		B43_PHY_OFDM(0x46) /*                 */
#define B43_LPPHY_RADAR_RD_DATA_REG		B43_PHY_OFDM(0x47) /*                   */
#define B43_LPPHY_LP_PHY_CTL			B43_PHY_OFDM(0x48) /*                */
#define B43_LPPHY_CLASSIFIER_CTL		B43_PHY_OFDM(0x49) /*                    */
#define B43_LPPHY_RESET_CTL			B43_PHY_OFDM(0x4A) /*               */
#define B43_LPPHY_CLKEN_CTL			B43_PHY_OFDM(0x4B) /*               */
#define B43_LPPHY_RF_OVERRIDE_0			B43_PHY_OFDM(0x4C) /*               */
#define B43_LPPHY_RF_OVERRIDE_VAL_0		B43_PHY_OFDM(0x4D) /*                   */
#define B43_LPPHY_TR_LOOKUP_1			B43_PHY_OFDM(0x4E) /*             */
#define B43_LPPHY_TR_LOOKUP_2			B43_PHY_OFDM(0x4F) /*             */
#define B43_LPPHY_RSSISELLOOKUP1		B43_PHY_OFDM(0x50) /*                */
#define B43_LPPHY_IQLO_CAL_CMD			B43_PHY_OFDM(0x51) /*              */
#define B43_LPPHY_IQLO_CAL_CMD_N_NUM		B43_PHY_OFDM(0x52) /*                    */
#define B43_LPPHY_IQLO_CAL_CMD_G_CTL		B43_PHY_OFDM(0x53) /*                        */
#define B43_LPPHY_MACINT_DBG_REGISTER		B43_PHY_OFDM(0x54) /*                       */
#define B43_LPPHY_TABLE_ADDR			B43_PHY_OFDM(0x55) /*               */
#define B43_LPPHY_TABLEDATALO			B43_PHY_OFDM(0x56) /*             */
#define B43_LPPHY_TABLEDATAHI			B43_PHY_OFDM(0x57) /*             */
#define B43_LPPHY_PHY_CRS_ENABLE_ADDR		B43_PHY_OFDM(0x58) /*                        */
#define B43_LPPHY_IDLETIME_CTL			B43_PHY_OFDM(0x59) /*                  */
#define B43_LPPHY_IDLETIME_CRS_ON_LO		B43_PHY_OFDM(0x5A) /*                    */
#define B43_LPPHY_IDLETIME_CRS_ON_HI		B43_PHY_OFDM(0x5B) /*                    */
#define B43_LPPHY_IDLETIME_MEAS_TIME_LO		B43_PHY_OFDM(0x5C) /*                       */
#define B43_LPPHY_IDLETIME_MEAS_TIME_HI		B43_PHY_OFDM(0x5D) /*                       */
#define B43_LPPHY_RESET_LEN_OFDM_TX_ADDR	B43_PHY_OFDM(0x5E) /*                           */
#define B43_LPPHY_RESET_LEN_OFDM_RX_ADDR	B43_PHY_OFDM(0x5F) /*                           */
#define B43_LPPHY_REG_CRS_ENABLE		B43_PHY_OFDM(0x60) /*                */
#define B43_LPPHY_PLCP_TMT_STR0_CTR_MIN		B43_PHY_OFDM(0x61) /*                       */
#define B43_LPPHY_PKT_FSM_RESET_LEN_VAL		B43_PHY_OFDM(0x62) /*                         */
#define B43_LPPHY_READSYM2RESET_CTL		B43_PHY_OFDM(0x63) /*                       */
#define B43_LPPHY_DC_FILTER_DELAY1		B43_PHY_OFDM(0x64) /*                  */
#define B43_LPPHY_PACKET_RX_ACTIVE_TO		B43_PHY_OFDM(0x65) /*                          */
#define B43_LPPHY_ED_TOVAL			B43_PHY_OFDM(0x66) /*                 */
#define B43_LPPHY_HOLD_CRS_ON_VAL		B43_PHY_OFDM(0x67) /*                   */
#define B43_LPPHY_OFDM_TX_PHY_CRS_DELAY_VAL	B43_PHY_OFDM(0x69) /*                             */
#define B43_LPPHY_CCK_TX_PHY_CRS_DELAY_VAL	B43_PHY_OFDM(0x6A) /*                            */
#define B43_LPPHY_ED_ON_CONFIRM_TIMER_VAL	B43_PHY_OFDM(0x6B) /*                           */
#define B43_LPPHY_ED_OFFSET_CONFIRM_TIMER_VAL	B43_PHY_OFDM(0x6C) /*                               */
#define B43_LPPHY_PHY_CRS_OFFSET_TIMER_VAL	B43_PHY_OFDM(0x6D) /*                            */
#define B43_LPPHY_ADC_COMPENSATION_CTL		B43_PHY_OFDM(0x70) /*                          */
#define B43_LPPHY_LOG2_RBPSK_ADDR		B43_PHY_OFDM(0x71) /*                    */
#define B43_LPPHY_LOG2_RQPSK_ADDR		B43_PHY_OFDM(0x72) /*                    */
#define B43_LPPHY_LOG2_R16QAM_ADDR		B43_PHY_OFDM(0x73) /*                     */
#define B43_LPPHY_LOG2_R64QAM_ADDR		B43_PHY_OFDM(0x74) /*                     */
#define B43_LPPHY_OFFSET_BPSK_ADDR		B43_PHY_OFDM(0x75) /*                     */
#define B43_LPPHY_OFFSET_QPSK_ADDR		B43_PHY_OFDM(0x76) /*                     */
#define B43_LPPHY_OFFSET_16QAM_ADDR		B43_PHY_OFDM(0x77) /*                      */
#define B43_LPPHY_OFFSET_64QAM_ADDR		B43_PHY_OFDM(0x78) /*                      */
#define B43_LPPHY_ALPHA1			B43_PHY_OFDM(0x79) /*        */
#define B43_LPPHY_ALPHA2			B43_PHY_OFDM(0x7A) /*        */
#define B43_LPPHY_BETA1				B43_PHY_OFDM(0x7B) /*       */
#define B43_LPPHY_BETA2				B43_PHY_OFDM(0x7C) /*       */
#define B43_LPPHY_LOOP_NUM_ADDR			B43_PHY_OFDM(0x7D) /*                  */
#define B43_LPPHY_STR_COLLMAX_SMPL_ADDR		B43_PHY_OFDM(0x7E) /*                            */
#define B43_LPPHY_MAX_SMPL_COARSE_FINE_ADDR	B43_PHY_OFDM(0x7F) /*                                */
#define B43_LPPHY_MAX_SMPL_COARSE_STR0CTR_ADDR	B43_PHY_OFDM(0x80) /*                                   */
#define B43_LPPHY_IQ_ENABLE_WAIT_TIME_ADDR	B43_PHY_OFDM(0x81) /*                             */
#define B43_LPPHY_IQ_NUM_SMPLS_ADDR		B43_PHY_OFDM(0x82) /*                        */
#define B43_LPPHY_IQ_ACC_HI_ADDR		B43_PHY_OFDM(0x83) /*                   */
#define B43_LPPHY_IQ_ACC_LO_ADDR		B43_PHY_OFDM(0x84) /*                   */
#define B43_LPPHY_IQ_I_PWR_ACC_HI_ADDR		B43_PHY_OFDM(0x85) /*                         */
#define B43_LPPHY_IQ_I_PWR_ACC_LO_ADDR		B43_PHY_OFDM(0x86) /*                         */
#define B43_LPPHY_IQ_Q_PWR_ACC_HI_ADDR		B43_PHY_OFDM(0x87) /*                         */
#define B43_LPPHY_IQ_Q_PWR_ACC_LO_ADDR		B43_PHY_OFDM(0x88) /*                         */
#define B43_LPPHY_MAXNUMSTEPS			B43_PHY_OFDM(0x89) /*             */
#define B43_LPPHY_ROTORPHASE_ADDR		B43_PHY_OFDM(0x8A) /*                    */
#define B43_LPPHY_ADVANCEDRETARDROTOR_ADDR	B43_PHY_OFDM(0x8B) /*                             */
#define B43_LPPHY_RSSIADCDELAY_CTL_ADDR		B43_PHY_OFDM(0x8D) /*                              */
#define B43_LPPHY_TSSISTAT_ADDR			B43_PHY_OFDM(0x8E) /*                    */
#define B43_LPPHY_TEMPSENSESTAT_ADDR		B43_PHY_OFDM(0x8F) /*                         */
#define B43_LPPHY_TEMPSENSE_CTL_ADDR		B43_PHY_OFDM(0x90) /*                           */
#define B43_LPPHY_WRSSISTAT_ADDR		B43_PHY_OFDM(0x91) /*                     */
#define B43_LPPHY_MUFACTORADDR			B43_PHY_OFDM(0x92) /*              */
#define B43_LPPHY_SCRAMSTATE_ADDR		B43_PHY_OFDM(0x93) /*                    */
#define B43_LPPHY_TXHOLDOFFADDR			B43_PHY_OFDM(0x94) /*               */
#define B43_LPPHY_PKTGAINVAL_ADDR		B43_PHY_OFDM(0x95) /*                    */
#define B43_LPPHY_COARSEESTIM_ADDR		B43_PHY_OFDM(0x96) /*                     */
#define B43_LPPHY_STATE_TRANSITION_ADDR		B43_PHY_OFDM(0x97) /*                          */
#define B43_LPPHY_TRN_OFFSET_ADDR		B43_PHY_OFDM(0x98) /*                    */
#define B43_LPPHY_NUM_ROTOR_ADDR		B43_PHY_OFDM(0x99) /*                   */
#define B43_LPPHY_VITERBI_OFFSET_ADDR		B43_PHY_OFDM(0x9A) /*                        */
#define B43_LPPHY_SMPL_COLLECT_WAIT_ADDR	B43_PHY_OFDM(0x9B) /*                             */
#define B43_LPPHY_A_PHY_CTL_ADDR		B43_PHY_OFDM(0x9C) /*                       */
#define B43_LPPHY_NUM_PASS_THROUGH_ADDR		B43_PHY_OFDM(0x9D) /*                          */
#define B43_LPPHY_RX_COMP_COEFF_S		B43_PHY_OFDM(0x9E) /*                        */
#define B43_LPPHY_CPAROTATEVAL			B43_PHY_OFDM(0x9F) /*                */
#define B43_LPPHY_SMPL_PLAY_COUNT		B43_PHY_OFDM(0xA0) /*                   */
#define B43_LPPHY_SMPL_PLAY_BUFFER_CTL		B43_PHY_OFDM(0xA1) /*                            */
#define B43_LPPHY_FOURWIRE_CTL			B43_PHY_OFDM(0xA2) /*                  */
#define B43_LPPHY_CPA_TAILCOUNT_VAL		B43_PHY_OFDM(0xA3) /*                     */
#define B43_LPPHY_TX_PWR_CTL_CMD		B43_PHY_OFDM(0xA4) /*                      */
#define  B43_LPPHY_TX_PWR_CTL_CMD_MODE		0xE000 /*                            */
#define   B43_LPPHY_TX_PWR_CTL_CMD_MODE_OFF	0x0000 /*                         */
#define   B43_LPPHY_TX_PWR_CTL_CMD_MODE_SW	0x8000 /*                              */
#define   B43_LPPHY_TX_PWR_CTL_CMD_MODE_HW	0xE000 /*                              */
#define B43_LPPHY_TX_PWR_CTL_NNUM		B43_PHY_OFDM(0xA5) /*                       */
#define B43_LPPHY_TX_PWR_CTL_IDLETSSI		B43_PHY_OFDM(0xA6) /*                           */
#define B43_LPPHY_TX_PWR_CTL_TARGETPWR		B43_PHY_OFDM(0xA7) /*                              */
#define B43_LPPHY_TX_PWR_CTL_DELTAPWR_LIMIT	B43_PHY_OFDM(0xA8) /*                                   */
#define B43_LPPHY_TX_PWR_CTL_BASEINDEX		B43_PHY_OFDM(0xA9) /*                            */
#define B43_LPPHY_TX_PWR_CTL_PWR_INDEX		B43_PHY_OFDM(0xAA) /*                              */
#define B43_LPPHY_TX_PWR_CTL_STAT		B43_PHY_OFDM(0xAB) /*                         */
#define B43_LPPHY_LP_RF_SIGNAL_LUT		B43_PHY_OFDM(0xAC) /*                  */
#define B43_LPPHY_RX_RADIO_CTL_FILTER_STATE	B43_PHY_OFDM(0xAD) /*                               */
#define B43_LPPHY_RX_RADIO_CTL			B43_PHY_OFDM(0xAE) /*                  */
#define B43_LPPHY_NRSSI_STAT_ADDR		B43_PHY_OFDM(0xAF) /*                      */
#define B43_LPPHY_RF_OVERRIDE_2			B43_PHY_OFDM(0xB0) /*               */
#define B43_LPPHY_RF_OVERRIDE_2_VAL		B43_PHY_OFDM(0xB1) /*                   */
#define B43_LPPHY_PS_CTL_OVERRIDE_VAL0		B43_PHY_OFDM(0xB2) /*                          */
#define B43_LPPHY_PS_CTL_OVERRIDE_VAL1		B43_PHY_OFDM(0xB3) /*                          */
#define B43_LPPHY_PS_CTL_OVERRIDE_VAL2		B43_PHY_OFDM(0xB4) /*                          */
#define B43_LPPHY_TX_GAIN_CTL_OVERRIDE_VAL	B43_PHY_OFDM(0xB5) /*                              */
#define B43_LPPHY_RX_GAIN_CTL_OVERRIDE_VAL	B43_PHY_OFDM(0xB6) /*                              */
#define B43_LPPHY_AFE_DDFS			B43_PHY_OFDM(0xB7) /*          */
#define B43_LPPHY_AFE_DDFS_POINTER_INIT		B43_PHY_OFDM(0xB8) /*                       */
#define B43_LPPHY_AFE_DDFS_INCR_INIT		B43_PHY_OFDM(0xB9) /*                    */
#define B43_LPPHY_MRCNOISEREDUCTION		B43_PHY_OFDM(0xBA) /*                   */
#define B43_LPPHY_TR_LOOKUP_3			B43_PHY_OFDM(0xBB) /*             */
#define B43_LPPHY_TR_LOOKUP_4			B43_PHY_OFDM(0xBC) /*             */
#define B43_LPPHY_RADAR_FIFO_STAT		B43_PHY_OFDM(0xBD) /*                   */
#define B43_LPPHY_GPIO_OUTEN			B43_PHY_OFDM(0xBE) /*                 */
#define B43_LPPHY_GPIO_SELECT			B43_PHY_OFDM(0xBF) /*             */
#define B43_LPPHY_GPIO_OUT			B43_PHY_OFDM(0xC0) /*          */
#define B43_LPPHY_4C3				B43_PHY_OFDM(0xC3) /*                              */
#define B43_LPPHY_4C4				B43_PHY_OFDM(0xC4) /*                              */
#define B43_LPPHY_4C5				B43_PHY_OFDM(0xC5) /*                              */
#define B43_LPPHY_TR_LOOKUP_5			B43_PHY_OFDM(0xC7) /*             */
#define B43_LPPHY_TR_LOOKUP_6			B43_PHY_OFDM(0xC8) /*             */
#define B43_LPPHY_TR_LOOKUP_7			B43_PHY_OFDM(0xC9) /*             */
#define B43_LPPHY_TR_LOOKUP_8			B43_PHY_OFDM(0xCA) /*             */
#define B43_LPPHY_RF_PWR_OVERRIDE		B43_PHY_OFDM(0xD3) /*                   */



/*                                   */
#define B43_LP_RADIO(radio_reg)			(radio_reg)
#define B43_LP_NORTH(radio_reg)			B43_LP_RADIO(radio_reg)
#define B43_LP_SOUTH(radio_reg)			B43_LP_RADIO((radio_reg) | 0x4000)


/*                                         */
#define B2062_N_COMM1				B43_LP_NORTH(0x000) /*                   */
#define B2062_N_COMM2				B43_LP_NORTH(0x002) /*                   */
#define B2062_N_COMM3				B43_LP_NORTH(0x003) /*                   */
#define B2062_N_COMM4				B43_LP_NORTH(0x004) /*                   */
#define B2062_N_COMM5				B43_LP_NORTH(0x005) /*                   */
#define B2062_N_COMM6				B43_LP_NORTH(0x006) /*                   */
#define B2062_N_COMM7				B43_LP_NORTH(0x007) /*                   */
#define B2062_N_COMM8				B43_LP_NORTH(0x008) /*                   */
#define B2062_N_COMM9				B43_LP_NORTH(0x009) /*                   */
#define B2062_N_COMM10				B43_LP_NORTH(0x00A) /*                   */
#define B2062_N_COMM11				B43_LP_NORTH(0x00B) /*                   */
#define B2062_N_COMM12				B43_LP_NORTH(0x00C) /*                   */
#define B2062_N_COMM13				B43_LP_NORTH(0x00D) /*                   */
#define B2062_N_COMM14				B43_LP_NORTH(0x00E) /*                   */
#define B2062_N_COMM15				B43_LP_NORTH(0x00F) /*                   */
#define B2062_N_PDN_CTL0			B43_LP_NORTH(0x010) /*                       */
#define B2062_N_PDN_CTL1			B43_LP_NORTH(0x011) /*                       */
#define B2062_N_PDN_CTL2			B43_LP_NORTH(0x012) /*                       */
#define B2062_N_PDN_CTL3			B43_LP_NORTH(0x013) /*                       */
#define B2062_N_PDN_CTL4			B43_LP_NORTH(0x014) /*                       */
#define B2062_N_GEN_CTL0			B43_LP_NORTH(0x015) /*                       */
#define B2062_N_IQ_CALIB			B43_LP_NORTH(0x016) /*                        */
#define B2062_N_LGENC				B43_LP_NORTH(0x017) /*               */
#define B2062_N_LGENA_LPF			B43_LP_NORTH(0x018) /*                   */
#define B2062_N_LGENA_BIAS0			B43_LP_NORTH(0x019) /*                      */
#define B2062_N_LGNEA_BIAS1			B43_LP_NORTH(0x01A) /*                      */
#define B2062_N_LGENA_CTL0			B43_LP_NORTH(0x01B) /*                         */
#define B2062_N_LGENA_CTL1			B43_LP_NORTH(0x01C) /*                         */
#define B2062_N_LGENA_CTL2			B43_LP_NORTH(0x01D) /*                         */
#define B2062_N_LGENA_TUNE0			B43_LP_NORTH(0x01E) /*                      */
#define B2062_N_LGENA_TUNE1			B43_LP_NORTH(0x01F) /*                      */
#define B2062_N_LGENA_TUNE2			B43_LP_NORTH(0x020) /*                      */
#define B2062_N_LGENA_TUNE3			B43_LP_NORTH(0x021) /*                      */
#define B2062_N_LGENA_CTL3			B43_LP_NORTH(0x022) /*                         */
#define B2062_N_LGENA_CTL4			B43_LP_NORTH(0x023) /*                         */
#define B2062_N_LGENA_CTL5			B43_LP_NORTH(0x024) /*                         */
#define B2062_N_LGENA_CTL6			B43_LP_NORTH(0x025) /*                         */
#define B2062_N_LGENA_CTL7			B43_LP_NORTH(0x026) /*                         */
#define B2062_N_RXA_CTL0			B43_LP_NORTH(0x027) /*                       */
#define B2062_N_RXA_CTL1			B43_LP_NORTH(0x028) /*                       */
#define B2062_N_RXA_CTL2			B43_LP_NORTH(0x029) /*                       */
#define B2062_N_RXA_CTL3			B43_LP_NORTH(0x02A) /*                       */
#define B2062_N_RXA_CTL4			B43_LP_NORTH(0x02B) /*                       */
#define B2062_N_RXA_CTL5			B43_LP_NORTH(0x02C) /*                       */
#define B2062_N_RXA_CTL6			B43_LP_NORTH(0x02D) /*                       */
#define B2062_N_RXA_CTL7			B43_LP_NORTH(0x02E) /*                       */
#define B2062_N_RXBB_CTL0			B43_LP_NORTH(0x02F) /*                        */
#define B2062_N_RXBB_CTL1			B43_LP_NORTH(0x030) /*                        */
#define B2062_N_RXBB_CTL2			B43_LP_NORTH(0x031) /*                        */
#define B2062_N_RXBB_GAIN0			B43_LP_NORTH(0x032) /*                     */
#define B2062_N_RXBB_GAIN1			B43_LP_NORTH(0x033) /*                     */
#define B2062_N_RXBB_GAIN2			B43_LP_NORTH(0x034) /*                     */
#define B2062_N_RXBB_GAIN3			B43_LP_NORTH(0x035) /*                     */
#define B2062_N_RXBB_RSSI0			B43_LP_NORTH(0x036) /*                     */
#define B2062_N_RXBB_RSSI1			B43_LP_NORTH(0x037) /*                     */
#define B2062_N_RXBB_CALIB0			B43_LP_NORTH(0x038) /*                           */
#define B2062_N_RXBB_CALIB1			B43_LP_NORTH(0x039) /*                           */
#define B2062_N_RXBB_CALIB2			B43_LP_NORTH(0x03A) /*                           */
#define B2062_N_RXBB_BIAS0			B43_LP_NORTH(0x03B) /*                     */
#define B2062_N_RXBB_BIAS1			B43_LP_NORTH(0x03C) /*                     */
#define B2062_N_RXBB_BIAS2			B43_LP_NORTH(0x03D) /*                     */
#define B2062_N_RXBB_BIAS3			B43_LP_NORTH(0x03E) /*                     */
#define B2062_N_RXBB_BIAS4			B43_LP_NORTH(0x03F) /*                     */
#define B2062_N_RXBB_BIAS5			B43_LP_NORTH(0x040) /*                     */
#define B2062_N_RXBB_RSSI2			B43_LP_NORTH(0x041) /*                     */
#define B2062_N_RXBB_RSSI3			B43_LP_NORTH(0x042) /*                     */
#define B2062_N_RXBB_RSSI4			B43_LP_NORTH(0x043) /*                     */
#define B2062_N_RXBB_RSSI5			B43_LP_NORTH(0x044) /*                     */
#define B2062_N_TX_CTL0				B43_LP_NORTH(0x045) /*                      */
#define B2062_N_TX_CTL1				B43_LP_NORTH(0x046) /*                      */
#define B2062_N_TX_CTL2				B43_LP_NORTH(0x047) /*                      */
#define B2062_N_TX_CTL3				B43_LP_NORTH(0x048) /*                      */
#define B2062_N_TX_CTL4				B43_LP_NORTH(0x049) /*                      */
#define B2062_N_TX_CTL5				B43_LP_NORTH(0x04A) /*                      */
#define B2062_N_TX_CTL6				B43_LP_NORTH(0x04B) /*                      */
#define B2062_N_TX_CTL7				B43_LP_NORTH(0x04C) /*                      */
#define B2062_N_TX_CTL8				B43_LP_NORTH(0x04D) /*                      */
#define B2062_N_TX_CTL9				B43_LP_NORTH(0x04E) /*                      */
#define B2062_N_TX_CTL_A			B43_LP_NORTH(0x04F) /*                      */
#define B2062_N_TX_GC2G				B43_LP_NORTH(0x050) /*                 */
#define B2062_N_TX_GC5G				B43_LP_NORTH(0x051) /*                 */
#define B2062_N_TX_TUNE				B43_LP_NORTH(0x052) /*                 */
#define B2062_N_TX_PAD				B43_LP_NORTH(0x053) /*                */
#define B2062_N_TX_PGA				B43_LP_NORTH(0x054) /*                */
#define B2062_N_TX_PADAUX			B43_LP_NORTH(0x055) /*                   */
#define B2062_N_TX_PGAAUX			B43_LP_NORTH(0x056) /*                   */
#define B2062_N_TSSI_CTL0			B43_LP_NORTH(0x057) /*                        */
#define B2062_N_TSSI_CTL1			B43_LP_NORTH(0x058) /*                        */
#define B2062_N_TSSI_CTL2			B43_LP_NORTH(0x059) /*                        */
#define B2062_N_IQ_CALIB_CTL0			B43_LP_NORTH(0x05A) /*                                  */
#define B2062_N_IQ_CALIB_CTL1			B43_LP_NORTH(0x05B) /*                                  */
#define B2062_N_IQ_CALIB_CTL2			B43_LP_NORTH(0x05C) /*                                  */
#define B2062_N_CALIB_TS			B43_LP_NORTH(0x05D) /*                        */
#define B2062_N_CALIB_CTL0			B43_LP_NORTH(0x05E) /*                               */
#define B2062_N_CALIB_CTL1			B43_LP_NORTH(0x05F) /*                               */
#define B2062_N_CALIB_CTL2			B43_LP_NORTH(0x060) /*                               */
#define B2062_N_CALIB_CTL3			B43_LP_NORTH(0x061) /*                               */
#define B2062_N_CALIB_CTL4			B43_LP_NORTH(0x062) /*                               */
#define B2062_N_CALIB_DBG0			B43_LP_NORTH(0x063) /*                             */
#define B2062_N_CALIB_DBG1			B43_LP_NORTH(0x064) /*                             */
#define B2062_N_CALIB_DBG2			B43_LP_NORTH(0x065) /*                             */
#define B2062_N_CALIB_DBG3			B43_LP_NORTH(0x066) /*                             */
#define B2062_N_PSENSE_CTL0			B43_LP_NORTH(0x069) /*                          */
#define B2062_N_PSENSE_CTL1			B43_LP_NORTH(0x06A) /*                          */
#define B2062_N_PSENSE_CTL2			B43_LP_NORTH(0x06B) /*                          */
#define B2062_N_TEST_BUF0			B43_LP_NORTH(0x06C) /*                   */

/*                                         */
#define B2062_S_COMM1				B43_LP_SOUTH(0x000) /*                   */
#define B2062_S_RADIO_ID_CODE			B43_LP_SOUTH(0x001) /*                       */
#define B2062_S_COMM2				B43_LP_SOUTH(0x002) /*                   */
#define B2062_S_COMM3				B43_LP_SOUTH(0x003) /*                   */
#define B2062_S_COMM4				B43_LP_SOUTH(0x004) /*                   */
#define B2062_S_COMM5				B43_LP_SOUTH(0x005) /*                   */
#define B2062_S_COMM6				B43_LP_SOUTH(0x006) /*                   */
#define B2062_S_COMM7				B43_LP_SOUTH(0x007) /*                   */
#define B2062_S_COMM8				B43_LP_SOUTH(0x008) /*                   */
#define B2062_S_COMM9				B43_LP_SOUTH(0x009) /*                   */
#define B2062_S_COMM10				B43_LP_SOUTH(0x00A) /*                   */
#define B2062_S_COMM11				B43_LP_SOUTH(0x00B) /*                   */
#define B2062_S_COMM12				B43_LP_SOUTH(0x00C) /*                   */
#define B2062_S_COMM13				B43_LP_SOUTH(0x00D) /*                   */
#define B2062_S_COMM14				B43_LP_SOUTH(0x00E) /*                   */
#define B2062_S_COMM15				B43_LP_SOUTH(0x00F) /*                   */
#define B2062_S_PDS_CTL0			B43_LP_SOUTH(0x010) /*                       */
#define B2062_S_PDS_CTL1			B43_LP_SOUTH(0x011) /*                       */
#define B2062_S_PDS_CTL2			B43_LP_SOUTH(0x012) /*                       */
#define B2062_S_PDS_CTL3			B43_LP_SOUTH(0x013) /*                       */
#define B2062_S_BG_CTL0				B43_LP_SOUTH(0x014) /*                      */
#define B2062_S_BG_CTL1				B43_LP_SOUTH(0x015) /*                      */
#define B2062_S_BG_CTL2				B43_LP_SOUTH(0x016) /*                      */
#define B2062_S_LGENG_CTL0			B43_LP_SOUTH(0x017) /*                          */
#define B2062_S_LGENG_CTL1			B43_LP_SOUTH(0x018) /*                          */
#define B2062_S_LGENG_CTL2			B43_LP_SOUTH(0x019) /*                          */
#define B2062_S_LGENG_CTL3			B43_LP_SOUTH(0x01A) /*                          */
#define B2062_S_LGENG_CTL4			B43_LP_SOUTH(0x01B) /*                          */
#define B2062_S_LGENG_CTL5			B43_LP_SOUTH(0x01C) /*                          */
#define B2062_S_LGENG_CTL6			B43_LP_SOUTH(0x01D) /*                          */
#define B2062_S_LGENG_CTL7			B43_LP_SOUTH(0x01E) /*                          */
#define B2062_S_LGENG_CTL8			B43_LP_SOUTH(0x01F) /*                          */
#define B2062_S_LGENG_CTL9			B43_LP_SOUTH(0x020) /*                          */
#define B2062_S_LGENG_CTL10			B43_LP_SOUTH(0x021) /*                          */
#define B2062_S_LGENG_CTL11			B43_LP_SOUTH(0x022) /*                          */
#define B2062_S_REFPLL_CTL0			B43_LP_SOUTH(0x023) /*                           */
#define B2062_S_REFPLL_CTL1			B43_LP_SOUTH(0x024) /*                           */
#define B2062_S_REFPLL_CTL2			B43_LP_SOUTH(0x025) /*                           */
#define B2062_S_REFPLL_CTL3			B43_LP_SOUTH(0x026) /*                           */
#define B2062_S_REFPLL_CTL4			B43_LP_SOUTH(0x027) /*                           */
#define B2062_S_REFPLL_CTL5			B43_LP_SOUTH(0x028) /*                           */
#define B2062_S_REFPLL_CTL6			B43_LP_SOUTH(0x029) /*                           */
#define B2062_S_REFPLL_CTL7			B43_LP_SOUTH(0x02A) /*                           */
#define B2062_S_REFPLL_CTL8			B43_LP_SOUTH(0x02B) /*                           */
#define B2062_S_REFPLL_CTL9			B43_LP_SOUTH(0x02C) /*                           */
#define B2062_S_REFPLL_CTL10			B43_LP_SOUTH(0x02D) /*                           */
#define B2062_S_REFPLL_CTL11			B43_LP_SOUTH(0x02E) /*                           */
#define B2062_S_REFPLL_CTL12			B43_LP_SOUTH(0x02F) /*                           */
#define B2062_S_REFPLL_CTL13			B43_LP_SOUTH(0x030) /*                           */
#define B2062_S_REFPLL_CTL14			B43_LP_SOUTH(0x031) /*                           */
#define B2062_S_REFPLL_CTL15			B43_LP_SOUTH(0x032) /*                           */
#define B2062_S_REFPLL_CTL16			B43_LP_SOUTH(0x033) /*                           */
#define B2062_S_RFPLL_CTL0			B43_LP_SOUTH(0x034) /*                          */
#define B2062_S_RFPLL_CTL1			B43_LP_SOUTH(0x035) /*                          */
#define B2062_S_RFPLL_CTL2			B43_LP_SOUTH(0x036) /*                          */
#define B2062_S_RFPLL_CTL3			B43_LP_SOUTH(0x037) /*                          */
#define B2062_S_RFPLL_CTL4			B43_LP_SOUTH(0x038) /*                          */
#define B2062_S_RFPLL_CTL5			B43_LP_SOUTH(0x039) /*                          */
#define B2062_S_RFPLL_CTL6			B43_LP_SOUTH(0x03A) /*                          */
#define B2062_S_RFPLL_CTL7			B43_LP_SOUTH(0x03B) /*                          */
#define B2062_S_RFPLL_CTL8			B43_LP_SOUTH(0x03C) /*                          */
#define B2062_S_RFPLL_CTL9			B43_LP_SOUTH(0x03D) /*                          */
#define B2062_S_RFPLL_CTL10			B43_LP_SOUTH(0x03E) /*                          */
#define B2062_S_RFPLL_CTL11			B43_LP_SOUTH(0x03F) /*                          */
#define B2062_S_RFPLL_CTL12			B43_LP_SOUTH(0x040) /*                          */
#define B2062_S_RFPLL_CTL13			B43_LP_SOUTH(0x041) /*                          */
#define B2062_S_RFPLL_CTL14			B43_LP_SOUTH(0x042) /*                          */
#define B2062_S_RFPLL_CTL15			B43_LP_SOUTH(0x043) /*                          */
#define B2062_S_RFPLL_CTL16			B43_LP_SOUTH(0x044) /*                          */
#define B2062_S_RFPLL_CTL17			B43_LP_SOUTH(0x045) /*                          */
#define B2062_S_RFPLL_CTL18			B43_LP_SOUTH(0x046) /*                          */
#define B2062_S_RFPLL_CTL19			B43_LP_SOUTH(0x047) /*                          */
#define B2062_S_RFPLL_CTL20			B43_LP_SOUTH(0x048) /*                          */
#define B2062_S_RFPLL_CTL21			B43_LP_SOUTH(0x049) /*                          */
#define B2062_S_RFPLL_CTL22			B43_LP_SOUTH(0x04A) /*                          */
#define B2062_S_RFPLL_CTL23			B43_LP_SOUTH(0x04B) /*                          */
#define B2062_S_RFPLL_CTL24			B43_LP_SOUTH(0x04C) /*                          */
#define B2062_S_RFPLL_CTL25			B43_LP_SOUTH(0x04D) /*                          */
#define B2062_S_RFPLL_CTL26			B43_LP_SOUTH(0x04E) /*                          */
#define B2062_S_RFPLL_CTL27			B43_LP_SOUTH(0x04F) /*                          */
#define B2062_S_RFPLL_CTL28			B43_LP_SOUTH(0x050) /*                          */
#define B2062_S_RFPLL_CTL29			B43_LP_SOUTH(0x051) /*                          */
#define B2062_S_RFPLL_CTL30			B43_LP_SOUTH(0x052) /*                          */
#define B2062_S_RFPLL_CTL31			B43_LP_SOUTH(0x053) /*                          */
#define B2062_S_RFPLL_CTL32			B43_LP_SOUTH(0x054) /*                          */
#define B2062_S_RFPLL_CTL33			B43_LP_SOUTH(0x055) /*                          */
#define B2062_S_RFPLL_CTL34			B43_LP_SOUTH(0x056) /*                          */
#define B2062_S_RXG_CNT0			B43_LP_SOUTH(0x057) /*                        */
#define B2062_S_RXG_CNT1			B43_LP_SOUTH(0x058) /*                        */
#define B2062_S_RXG_CNT2			B43_LP_SOUTH(0x059) /*                        */
#define B2062_S_RXG_CNT3			B43_LP_SOUTH(0x05A) /*                        */
#define B2062_S_RXG_CNT4			B43_LP_SOUTH(0x05B) /*                        */
#define B2062_S_RXG_CNT5			B43_LP_SOUTH(0x05C) /*                        */
#define B2062_S_RXG_CNT6			B43_LP_SOUTH(0x05D) /*                        */
#define B2062_S_RXG_CNT7			B43_LP_SOUTH(0x05E) /*                        */
#define B2062_S_RXG_CNT8			B43_LP_SOUTH(0x05F) /*                        */
#define B2062_S_RXG_CNT9			B43_LP_SOUTH(0x060) /*                        */
#define B2062_S_RXG_CNT10			B43_LP_SOUTH(0x061) /*                        */
#define B2062_S_RXG_CNT11			B43_LP_SOUTH(0x062) /*                        */
#define B2062_S_RXG_CNT12			B43_LP_SOUTH(0x063) /*                        */
#define B2062_S_RXG_CNT13			B43_LP_SOUTH(0x064) /*                        */
#define B2062_S_RXG_CNT14			B43_LP_SOUTH(0x065) /*                        */
#define B2062_S_RXG_CNT15			B43_LP_SOUTH(0x066) /*                        */
#define B2062_S_RXG_CNT16			B43_LP_SOUTH(0x067) /*                        */
#define B2062_S_RXG_CNT17			B43_LP_SOUTH(0x068) /*                        */



/*                                   */
#define B2063_RADIO_ID_CODE			B43_LP_RADIO(0x001) /*               */
#define B2063_COMM1				B43_LP_RADIO(0x000) /*           */
#define B2063_COMM2				B43_LP_RADIO(0x002) /*           */
#define B2063_COMM3				B43_LP_RADIO(0x003) /*           */
#define B2063_COMM4				B43_LP_RADIO(0x004) /*           */
#define B2063_COMM5				B43_LP_RADIO(0x005) /*           */
#define B2063_COMM6				B43_LP_RADIO(0x006) /*           */
#define B2063_COMM7				B43_LP_RADIO(0x007) /*           */
#define B2063_COMM8				B43_LP_RADIO(0x008) /*           */
#define B2063_COMM9				B43_LP_RADIO(0x009) /*           */
#define B2063_COMM10				B43_LP_RADIO(0x00A) /*           */
#define B2063_COMM11				B43_LP_RADIO(0x00B) /*           */
#define B2063_COMM12				B43_LP_RADIO(0x00C) /*           */
#define B2063_COMM13				B43_LP_RADIO(0x00D) /*           */
#define B2063_COMM14				B43_LP_RADIO(0x00E) /*           */
#define B2063_COMM15				B43_LP_RADIO(0x00F) /*           */
#define B2063_COMM16				B43_LP_RADIO(0x010) /*           */
#define B2063_COMM17				B43_LP_RADIO(0x011) /*           */
#define B2063_COMM18				B43_LP_RADIO(0x012) /*           */
#define B2063_COMM19				B43_LP_RADIO(0x013) /*           */
#define B2063_COMM20				B43_LP_RADIO(0x014) /*           */
#define B2063_COMM21				B43_LP_RADIO(0x015) /*           */
#define B2063_COMM22				B43_LP_RADIO(0x016) /*           */
#define B2063_COMM23				B43_LP_RADIO(0x017) /*           */
#define B2063_COMM24				B43_LP_RADIO(0x018) /*           */
#define B2063_PWR_SWITCH_CTL			B43_LP_RADIO(0x019) /*                      */
#define B2063_PLL_SP1				B43_LP_RADIO(0x01A) /*          */
#define B2063_PLL_SP2				B43_LP_RADIO(0x01B) /*          */
#define B2063_LOGEN_SP1				B43_LP_RADIO(0x01C) /*            */
#define B2063_LOGEN_SP2				B43_LP_RADIO(0x01D) /*            */
#define B2063_LOGEN_SP3				B43_LP_RADIO(0x01E) /*            */
#define B2063_LOGEN_SP4				B43_LP_RADIO(0x01F) /*            */
#define B2063_LOGEN_SP5				B43_LP_RADIO(0x020) /*            */
#define B2063_G_RX_SP1				B43_LP_RADIO(0x021) /*           */
#define B2063_G_RX_SP2				B43_LP_RADIO(0x022) /*           */
#define B2063_G_RX_SP3				B43_LP_RADIO(0x023) /*           */
#define B2063_G_RX_SP4				B43_LP_RADIO(0x024) /*           */
#define B2063_G_RX_SP5				B43_LP_RADIO(0x025) /*           */
#define B2063_G_RX_SP6				B43_LP_RADIO(0x026) /*           */
#define B2063_G_RX_SP7				B43_LP_RADIO(0x027) /*           */
#define B2063_G_RX_SP8				B43_LP_RADIO(0x028) /*           */
#define B2063_G_RX_SP9				B43_LP_RADIO(0x029) /*           */
#define B2063_G_RX_SP10				B43_LP_RADIO(0x02A) /*            */
#define B2063_G_RX_SP11				B43_LP_RADIO(0x02B) /*            */
#define B2063_A_RX_SP1				B43_LP_RADIO(0x02C) /*           */
#define B2063_A_RX_SP2				B43_LP_RADIO(0x02D) /*           */
#define B2063_A_RX_SP3				B43_LP_RADIO(0x02E) /*           */
#define B2063_A_RX_SP4				B43_LP_RADIO(0x02F) /*           */
#define B2063_A_RX_SP5				B43_LP_RADIO(0x030) /*           */
#define B2063_A_RX_SP6				B43_LP_RADIO(0x031) /*           */
#define B2063_A_RX_SP7				B43_LP_RADIO(0x032) /*           */
#define B2063_RX_BB_SP1				B43_LP_RADIO(0x033) /*            */
#define B2063_RX_BB_SP2				B43_LP_RADIO(0x034) /*            */
#define B2063_RX_BB_SP3				B43_LP_RADIO(0x035) /*            */
#define B2063_RX_BB_SP4				B43_LP_RADIO(0x036) /*            */
#define B2063_RX_BB_SP5				B43_LP_RADIO(0x037) /*            */
#define B2063_RX_BB_SP6				B43_LP_RADIO(0x038) /*            */
#define B2063_RX_BB_SP7				B43_LP_RADIO(0x039) /*            */
#define B2063_RX_BB_SP8				B43_LP_RADIO(0x03A) /*            */
#define B2063_TX_RF_SP1				B43_LP_RADIO(0x03B) /*            */
#define B2063_TX_RF_SP2				B43_LP_RADIO(0x03C) /*            */
#define B2063_TX_RF_SP3				B43_LP_RADIO(0x03D) /*            */
#define B2063_TX_RF_SP4				B43_LP_RADIO(0x03E) /*            */
#define B2063_TX_RF_SP5				B43_LP_RADIO(0x03F) /*            */
#define B2063_TX_RF_SP6				B43_LP_RADIO(0x040) /*            */
#define B2063_TX_RF_SP7				B43_LP_RADIO(0x041) /*            */
#define B2063_TX_RF_SP8				B43_LP_RADIO(0x042) /*            */
#define B2063_TX_RF_SP9				B43_LP_RADIO(0x043) /*            */
#define B2063_TX_RF_SP10			B43_LP_RADIO(0x044) /*             */
#define B2063_TX_RF_SP11			B43_LP_RADIO(0x045) /*             */
#define B2063_TX_RF_SP12			B43_LP_RADIO(0x046) /*             */
#define B2063_TX_RF_SP13			B43_LP_RADIO(0x047) /*             */
#define B2063_TX_RF_SP14			B43_LP_RADIO(0x048) /*             */
#define B2063_TX_RF_SP15			B43_LP_RADIO(0x049) /*             */
#define B2063_TX_RF_SP16			B43_LP_RADIO(0x04A) /*             */
#define B2063_TX_RF_SP17			B43_LP_RADIO(0x04B) /*             */
#define B2063_PA_SP1				B43_LP_RADIO(0x04C) /*         */
#define B2063_PA_SP2				B43_LP_RADIO(0x04D) /*         */
#define B2063_PA_SP3				B43_LP_RADIO(0x04E) /*         */
#define B2063_PA_SP4				B43_LP_RADIO(0x04F) /*         */
#define B2063_PA_SP5				B43_LP_RADIO(0x050) /*         */
#define B2063_PA_SP6				B43_LP_RADIO(0x051) /*         */
#define B2063_PA_SP7				B43_LP_RADIO(0x052) /*         */
#define B2063_TX_BB_SP1				B43_LP_RADIO(0x053) /*            */
#define B2063_TX_BB_SP2				B43_LP_RADIO(0x054) /*            */
#define B2063_TX_BB_SP3				B43_LP_RADIO(0x055) /*            */
#define B2063_REG_SP1				B43_LP_RADIO(0x056) /*          */
#define B2063_BANDGAP_CTL1			B43_LP_RADIO(0x057) /*                   */
#define B2063_BANDGAP_CTL2			B43_LP_RADIO(0x058) /*                   */
#define B2063_LPO_CTL1				B43_LP_RADIO(0x059) /*               */
#define B2063_RC_CALIB_CTL1			B43_LP_RADIO(0x05A) /*                          */
#define B2063_RC_CALIB_CTL2			B43_LP_RADIO(0x05B) /*                          */
#define B2063_RC_CALIB_CTL3			B43_LP_RADIO(0x05C) /*                          */
#define B2063_RC_CALIB_CTL4			B43_LP_RADIO(0x05D) /*                          */
#define B2063_RC_CALIB_CTL5			B43_LP_RADIO(0x05E) /*                          */
#define B2063_RC_CALIB_CTL6			B43_LP_RADIO(0x05F) /*                          */
#define B2063_RC_CALIB_CTL7			B43_LP_RADIO(0x060) /*                          */
#define B2063_RC_CALIB_CTL8			B43_LP_RADIO(0x061) /*                          */
#define B2063_RC_CALIB_CTL9			B43_LP_RADIO(0x062) /*                          */
#define B2063_RC_CALIB_CTL10			B43_LP_RADIO(0x063) /*                           */
#define B2063_PLL_JTAG_CALNRST			B43_LP_RADIO(0x064) /*                  */
#define B2063_PLL_JTAG_IN_PLL1			B43_LP_RADIO(0x065) /*                   */
#define B2063_PLL_JTAG_IN_PLL2			B43_LP_RADIO(0x066) /*                   */
#define B2063_PLL_JTAG_PLL_CP1			B43_LP_RADIO(0x067) /*                   */
#define B2063_PLL_JTAG_PLL_CP2			B43_LP_RADIO(0x068) /*                   */
#define B2063_PLL_JTAG_PLL_CP3			B43_LP_RADIO(0x069) /*                   */
#define B2063_PLL_JTAG_PLL_CP4			B43_LP_RADIO(0x06A) /*                   */
#define B2063_PLL_JTAG_PLL_CTL1			B43_LP_RADIO(0x06B) /*                        */
#define B2063_PLL_JTAG_PLL_LF1			B43_LP_RADIO(0x06C) /*                   */
#define B2063_PLL_JTAG_PLL_LF2			B43_LP_RADIO(0x06D) /*                   */
#define B2063_PLL_JTAG_PLL_LF3			B43_LP_RADIO(0x06E) /*                   */
#define B2063_PLL_JTAG_PLL_LF4			B43_LP_RADIO(0x06F) /*                   */
#define B2063_PLL_JTAG_PLL_SG1			B43_LP_RADIO(0x070) /*                   */
#define B2063_PLL_JTAG_PLL_SG2			B43_LP_RADIO(0x071) /*                   */
#define B2063_PLL_JTAG_PLL_SG3			B43_LP_RADIO(0x072) /*                   */
#define B2063_PLL_JTAG_PLL_SG4			B43_LP_RADIO(0x073) /*                   */
#define B2063_PLL_JTAG_PLL_SG5			B43_LP_RADIO(0x074) /*                   */
#define B2063_PLL_JTAG_PLL_VCO1			B43_LP_RADIO(0x075) /*                    */
#define B2063_PLL_JTAG_PLL_VCO2			B43_LP_RADIO(0x076) /*                    */
#define B2063_PLL_JTAG_PLL_VCO_CALIB1		B43_LP_RADIO(0x077) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB2		B43_LP_RADIO(0x078) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB3		B43_LP_RADIO(0x079) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB4		B43_LP_RADIO(0x07A) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB5		B43_LP_RADIO(0x07B) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB6		B43_LP_RADIO(0x07C) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB7		B43_LP_RADIO(0x07D) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB8		B43_LP_RADIO(0x07E) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB9		B43_LP_RADIO(0x07F) /*                                */
#define B2063_PLL_JTAG_PLL_VCO_CALIB10		B43_LP_RADIO(0x080) /*                                 */
#define B2063_PLL_JTAG_PLL_XTAL_12		B43_LP_RADIO(0x081) /*                       */
#define B2063_PLL_JTAG_PLL_XTAL3		B43_LP_RADIO(0x082) /*                     */
#define B2063_LOGEN_ACL1			B43_LP_RADIO(0x083) /*             */
#define B2063_LOGEN_ACL2			B43_LP_RADIO(0x084) /*             */
#define B2063_LOGEN_ACL3			B43_LP_RADIO(0x085) /*             */
#define B2063_LOGEN_ACL4			B43_LP_RADIO(0x086) /*             */
#define B2063_LOGEN_ACL5			B43_LP_RADIO(0x087) /*             */
#define B2063_LO_CALIB_INPUTS			B43_LP_RADIO(0x088) /*                       */
#define B2063_LO_CALIB_CTL1			B43_LP_RADIO(0x089) /*                          */
#define B2063_LO_CALIB_CTL2			B43_LP_RADIO(0x08A) /*                          */
#define B2063_LO_CALIB_CTL3			B43_LP_RADIO(0x08B) /*                          */
#define B2063_LO_CALIB_WAITCNT			B43_LP_RADIO(0x08C) /*                        */
#define B2063_LO_CALIB_OVR1			B43_LP_RADIO(0x08D) /*                      */
#define B2063_LO_CALIB_OVR2			B43_LP_RADIO(0x08E) /*                      */
#define B2063_LO_CALIB_OVAL1			B43_LP_RADIO(0x08F) /*                       */
#define B2063_LO_CALIB_OVAL2			B43_LP_RADIO(0x090) /*                       */
#define B2063_LO_CALIB_OVAL3			B43_LP_RADIO(0x091) /*                       */
#define B2063_LO_CALIB_OVAL4			B43_LP_RADIO(0x092) /*                       */
#define B2063_LO_CALIB_OVAL5			B43_LP_RADIO(0x093) /*                       */
#define B2063_LO_CALIB_OVAL6			B43_LP_RADIO(0x094) /*                       */
#define B2063_LO_CALIB_OVAL7			B43_LP_RADIO(0x095) /*                       */
#define B2063_LO_CALIB_CALVLD1			B43_LP_RADIO(0x096) /*                         */
#define B2063_LO_CALIB_CALVLD2			B43_LP_RADIO(0x097) /*                         */
#define B2063_LO_CALIB_CVAL1			B43_LP_RADIO(0x098) /*                       */
#define B2063_LO_CALIB_CVAL2			B43_LP_RADIO(0x099) /*                       */
#define B2063_LO_CALIB_CVAL3			B43_LP_RADIO(0x09A) /*                       */
#define B2063_LO_CALIB_CVAL4			B43_LP_RADIO(0x09B) /*                       */
#define B2063_LO_CALIB_CVAL5			B43_LP_RADIO(0x09C) /*                       */
#define B2063_LO_CALIB_CVAL6			B43_LP_RADIO(0x09D) /*                       */
#define B2063_LO_CALIB_CVAL7			B43_LP_RADIO(0x09E) /*                       */
#define B2063_LOGEN_CALIB_EN			B43_LP_RADIO(0x09F) /*                      */
#define B2063_LOGEN_PEAKDET1			B43_LP_RADIO(0x0A0) /*                 */
#define B2063_LOGEN_RCCR1			B43_LP_RADIO(0x0A1) /*              */
#define B2063_LOGEN_VCOBUF1			B43_LP_RADIO(0x0A2) /*                */
#define B2063_LOGEN_MIXER1			B43_LP_RADIO(0x0A3) /*               */
#define B2063_LOGEN_MIXER2			B43_LP_RADIO(0x0A4) /*               */
#define B2063_LOGEN_BUF1			B43_LP_RADIO(0x0A5) /*             */
#define B2063_LOGEN_BUF2			B43_LP_RADIO(0x0A6) /*             */
#define B2063_LOGEN_DIV1			B43_LP_RADIO(0x0A7) /*             */
#define B2063_LOGEN_DIV2			B43_LP_RADIO(0x0A8) /*             */
#define B2063_LOGEN_DIV3			B43_LP_RADIO(0x0A9) /*             */
#define B2063_LOGEN_CBUFRX1			B43_LP_RADIO(0x0AA) /*                */
#define B2063_LOGEN_CBUFRX2			B43_LP_RADIO(0x0AB) /*                */
#define B2063_LOGEN_CBUFTX1			B43_LP_RADIO(0x0AC) /*                */
#define B2063_LOGEN_CBUFTX2			B43_LP_RADIO(0x0AD) /*                */
#define B2063_LOGEN_IDAC1			B43_LP_RADIO(0x0AE) /*              */
#define B2063_LOGEN_SPARE1			B43_LP_RADIO(0x0AF) /*               */
#define B2063_LOGEN_SPARE2			B43_LP_RADIO(0x0B0) /*               */
#define B2063_LOGEN_SPARE3			B43_LP_RADIO(0x0B1) /*               */
#define B2063_G_RX_1ST1				B43_LP_RADIO(0x0B2) /*            */
#define B2063_G_RX_1ST2				B43_LP_RADIO(0x0B3) /*            */
#define B2063_G_RX_1ST3				B43_LP_RADIO(0x0B4) /*            */
#define B2063_G_RX_2ND1				B43_LP_RADIO(0x0B5) /*            */
#define B2063_G_RX_2ND2				B43_LP_RADIO(0x0B6) /*            */
#define B2063_G_RX_2ND3				B43_LP_RADIO(0x0B7) /*            */
#define B2063_G_RX_2ND4				B43_LP_RADIO(0x0B8) /*            */
#define B2063_G_RX_2ND5				B43_LP_RADIO(0x0B9) /*            */
#define B2063_G_RX_2ND6				B43_LP_RADIO(0x0BA) /*            */
#define B2063_G_RX_2ND7				B43_LP_RADIO(0x0BB) /*            */
#define B2063_G_RX_2ND8				B43_LP_RADIO(0x0BC) /*            */
#define B2063_G_RX_PS1				B43_LP_RADIO(0x0BD) /*           */
#define B2063_G_RX_PS2				B43_LP_RADIO(0x0BE) /*           */
#define B2063_G_RX_PS3				B43_LP_RADIO(0x0BF) /*           */
#define B2063_G_RX_PS4				B43_LP_RADIO(0x0C0) /*           */
#define B2063_G_RX_PS5				B43_LP_RADIO(0x0C1) /*           */
#define B2063_G_RX_MIX1				B43_LP_RADIO(0x0C2) /*            */
#define B2063_G_RX_MIX2				B43_LP_RADIO(0x0C3) /*            */
#define B2063_G_RX_MIX3				B43_LP_RADIO(0x0C4) /*            */
#define B2063_G_RX_MIX4				B43_LP_RADIO(0x0C5) /*            */
#define B2063_G_RX_MIX5				B43_LP_RADIO(0x0C6) /*            */
#define B2063_G_RX_MIX6				B43_LP_RADIO(0x0C7) /*            */
#define B2063_G_RX_MIX7				B43_LP_RADIO(0x0C8) /*            */
#define B2063_G_RX_MIX8				B43_LP_RADIO(0x0C9) /*            */
#define B2063_G_RX_PDET1			B43_LP_RADIO(0x0CA) /*             */
#define B2063_G_RX_SPARES1			B43_LP_RADIO(0x0CB) /*               */
#define B2063_G_RX_SPARES2			B43_LP_RADIO(0x0CC) /*               */
#define B2063_G_RX_SPARES3			B43_LP_RADIO(0x0CD) /*               */
#define B2063_A_RX_1ST1				B43_LP_RADIO(0x0CE) /*            */
#define B2063_A_RX_1ST2				B43_LP_RADIO(0x0CF) /*            */
#define B2063_A_RX_1ST3				B43_LP_RADIO(0x0D0) /*            */
#define B2063_A_RX_1ST4				B43_LP_RADIO(0x0D1) /*            */
#define B2063_A_RX_1ST5				B43_LP_RADIO(0x0D2) /*            */
#define B2063_A_RX_2ND1				B43_LP_RADIO(0x0D3) /*            */
#define B2063_A_RX_2ND2				B43_LP_RADIO(0x0D4) /*            */
#define B2063_A_RX_2ND3				B43_LP_RADIO(0x0D5) /*            */
#define B2063_A_RX_2ND4				B43_LP_RADIO(0x0D6) /*            */
#define B2063_A_RX_2ND5				B43_LP_RADIO(0x0D7) /*            */
#define B2063_A_RX_2ND6				B43_LP_RADIO(0x0D8) /*            */
#define B2063_A_RX_2ND7				B43_LP_RADIO(0x0D9) /*            */
#define B2063_A_RX_PS1				B43_LP_RADIO(0x0DA) /*           */
#define B2063_A_RX_PS2				B43_LP_RADIO(0x0DB) /*           */
#define B2063_A_RX_PS3				B43_LP_RADIO(0x0DC) /*           */
#define B2063_A_RX_PS4				B43_LP_RADIO(0x0DD) /*           */
#define B2063_A_RX_PS5				B43_LP_RADIO(0x0DE) /*           */
#define B2063_A_RX_PS6				B43_LP_RADIO(0x0DF) /*           */
#define B2063_A_RX_MIX1				B43_LP_RADIO(0x0E0) /*            */
#define B2063_A_RX_MIX2				B43_LP_RADIO(0x0E1) /*            */
#define B2063_A_RX_MIX3				B43_LP_RADIO(0x0E2) /*            */
#define B2063_A_RX_MIX4				B43_LP_RADIO(0x0E3) /*            */
#define B2063_A_RX_MIX5				B43_LP_RADIO(0x0E4) /*            */
#define B2063_A_RX_MIX6				B43_LP_RADIO(0x0E5) /*            */
#define B2063_A_RX_MIX7				B43_LP_RADIO(0x0E6) /*            */
#define B2063_A_RX_MIX8				B43_LP_RADIO(0x0E7) /*            */
#define B2063_A_RX_PWRDET1			B43_LP_RADIO(0x0E8) /*               */
#define B2063_A_RX_SPARE1			B43_LP_RADIO(0x0E9) /*              */
#define B2063_A_RX_SPARE2			B43_LP_RADIO(0x0EA) /*              */
#define B2063_A_RX_SPARE3			B43_LP_RADIO(0x0EB) /*              */
#define B2063_RX_TIA_CTL1			B43_LP_RADIO(0x0EC) /*                  */
#define B2063_RX_TIA_CTL2			B43_LP_RADIO(0x0ED) /*                  */
#define B2063_RX_TIA_CTL3			B43_LP_RADIO(0x0EE) /*                  */
#define B2063_RX_TIA_CTL4			B43_LP_RADIO(0x0EF) /*                  */
#define B2063_RX_TIA_CTL5			B43_LP_RADIO(0x0F0) /*                  */
#define B2063_RX_TIA_CTL6			B43_LP_RADIO(0x0F1) /*                  */
#define B2063_RX_BB_CTL1			B43_LP_RADIO(0x0F2) /*                 */
#define B2063_RX_BB_CTL2			B43_LP_RADIO(0x0F3) /*                 */
#define B2063_RX_BB_CTL3			B43_LP_RADIO(0x0F4) /*                 */
#define B2063_RX_BB_CTL4			B43_LP_RADIO(0x0F5) /*                 */
#define B2063_RX_BB_CTL5			B43_LP_RADIO(0x0F6) /*                 */
#define B2063_RX_BB_CTL6			B43_LP_RADIO(0x0F7) /*                 */
#define B2063_RX_BB_CTL7			B43_LP_RADIO(0x0F8) /*                 */
#define B2063_RX_BB_CTL8			B43_LP_RADIO(0x0F9) /*                 */
#define B2063_RX_BB_CTL9			B43_LP_RADIO(0x0FA) /*                 */
#define B2063_TX_RF_CTL1			B43_LP_RADIO(0x0FB) /*                 */
#define B2063_TX_RF_IDAC_LO_RF_I		B43_LP_RADIO(0x0FC) /*                    */
#define B2063_TX_RF_IDAC_LO_RF_Q		B43_LP_RADIO(0x0FD) /*                    */
#define B2063_TX_RF_IDAC_LO_BB_I		B43_LP_RADIO(0x0FE) /*                    */
#define B2063_TX_RF_IDAC_LO_BB_Q		B43_LP_RADIO(0x0FF) /*                    */
#define B2063_TX_RF_CTL2			B43_LP_RADIO(0x100) /*                 */
#define B2063_TX_RF_CTL3			B43_LP_RADIO(0x101) /*                 */
#define B2063_TX_RF_CTL4			B43_LP_RADIO(0x102) /*                 */
#define B2063_TX_RF_CTL5			B43_LP_RADIO(0x103) /*                 */
#define B2063_TX_RF_CTL6			B43_LP_RADIO(0x104) /*                 */
#define B2063_TX_RF_CTL7			B43_LP_RADIO(0x105) /*                 */
#define B2063_TX_RF_CTL8			B43_LP_RADIO(0x106) /*                 */
#define B2063_TX_RF_CTL9			B43_LP_RADIO(0x107) /*                 */
#define B2063_TX_RF_CTL10			B43_LP_RADIO(0x108) /*                  */
#define B2063_TX_RF_CTL14			B43_LP_RADIO(0x109) /*                  */
#define B2063_TX_RF_CTL15			B43_LP_RADIO(0x10A) /*                  */
#define B2063_PA_CTL1				B43_LP_RADIO(0x10B) /*              */
#define B2063_PA_CTL2				B43_LP_RADIO(0x10C) /*              */
#define B2063_PA_CTL3				B43_LP_RADIO(0x10D) /*              */
#define B2063_PA_CTL4				B43_LP_RADIO(0x10E) /*              */
#define B2063_PA_CTL5				B43_LP_RADIO(0x10F) /*              */
#define B2063_PA_CTL6				B43_LP_RADIO(0x110) /*              */
#define B2063_PA_CTL7				B43_LP_RADIO(0x111) /*              */
#define B2063_PA_CTL8				B43_LP_RADIO(0x112) /*              */
#define B2063_PA_CTL9				B43_LP_RADIO(0x113) /*              */
#define B2063_PA_CTL10				B43_LP_RADIO(0x114) /*               */
#define B2063_PA_CTL11				B43_LP_RADIO(0x115) /*               */
#define B2063_PA_CTL12				B43_LP_RADIO(0x116) /*               */
#define B2063_PA_CTL13				B43_LP_RADIO(0x117) /*               */
#define B2063_TX_BB_CTL1			B43_LP_RADIO(0x118) /*                 */
#define B2063_TX_BB_CTL2			B43_LP_RADIO(0x119) /*                 */
#define B2063_TX_BB_CTL3			B43_LP_RADIO(0x11A) /*                 */
#define B2063_TX_BB_CTL4			B43_LP_RADIO(0x11B) /*                 */
#define B2063_GPIO_CTL1				B43_LP_RADIO(0x11C) /*                */
#define B2063_VREG_CTL1				B43_LP_RADIO(0x11D) /*                */
#define B2063_AMUX_CTL1				B43_LP_RADIO(0x11E) /*                */
#define B2063_IQ_CALIB_GVAR			B43_LP_RADIO(0x11F) /*                     */
#define B2063_IQ_CALIB_CTL1			B43_LP_RADIO(0x120) /*                          */
#define B2063_IQ_CALIB_CTL2			B43_LP_RADIO(0x121) /*                          */
#define B2063_TEMPSENSE_CTL1			B43_LP_RADIO(0x122) /*                     */
#define B2063_TEMPSENSE_CTL2			B43_LP_RADIO(0x123) /*                     */
#define B2063_TX_RX_LOOPBACK1			B43_LP_RADIO(0x124) /*                  */
#define B2063_TX_RX_LOOPBACK2			B43_LP_RADIO(0x125) /*                  */
#define B2063_EXT_TSSI_CTL1			B43_LP_RADIO(0x126) /*                    */
#define B2063_EXT_TSSI_CTL2			B43_LP_RADIO(0x127) /*                    */
#define B2063_AFE_CTL				B43_LP_RADIO(0x128) /*             */



enum b43_lpphy_txpctl_mode {
	B43_LPPHY_TXPCTL_UNKNOWN = 0,
	B43_LPPHY_TXPCTL_OFF,	/*                         */
	B43_LPPHY_TXPCTL_SW,	/*                                     */
	B43_LPPHY_TXPCTL_HW,	/*                                     */
};

struct b43_phy_lp {
	/*                                */
	enum b43_lpphy_txpctl_mode txpctl_mode;

	/*                                */
	u8 tx_isolation_med_band;
	/*                             */
	u8 tx_isolation_low_band;
	/*                              */
	u8 tx_isolation_hi_band;

	/*                                */
	u16 max_tx_pwr_med_band;
	/*                             */
	u16 max_tx_pwr_low_band;
	/*                              */
	u16 max_tx_pwr_hi_band;

	/*                                */
	/*                                     */
	u16 tx_max_rate[15];
	u16 tx_max_ratel[15];
	u16 tx_max_rateh[15];

	/*                       */
	s16 txpa[3], txpal[3], txpah[3];

	/*                      */
	u8 rx_pwr_offset;

	/*                     */
	u16 tssi_tx_count;
	/*            */
	u16 tssi_idx; /*                      */
	/*          */
	u16 tssi_npt; /*                      */

	/*                     */
	u16 tgt_tx_freq; /*                      */

	/*                               */
	s8 tx_pwr_idx_over; /*                      */

	/*         */
	u8 rssi_vf;
	/*         */
	u8 rssi_vc;
	/*         */
	u8 rssi_gs;

	/*        */
	u8 rc_cap;
	/*         */
	u8 bx_arch;

	/*                          */
	u8 full_calib_chan;

	/*                              */
	bool tx_iqloc_best_coeffs_valid;
	u8 tx_iqloc_best_coeffs[11];

	/*                                        */
	u16 dig_flt_state[9];

	bool crs_usr_disable, crs_sys_disable;

	unsigned int pdiv;

	/*                             */
	u8 channel;

	/*                                   */
	int antenna;

	/*                                 */
	int tx_tone_freq;
};

enum tssi_mux_mode {
	TSSI_MUX_PREPA,
	TSSI_MUX_POSTPA,
	TSSI_MUX_EXT,
};

struct b43_phy_operations;
extern const struct b43_phy_operations b43_phyops_lp;

#endif /*                     */
