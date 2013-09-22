#ifndef _ASM_ARCH_PXA27X_UDC_H
#define _ASM_ARCH_PXA27X_UDC_H

#ifdef _ASM_ARCH_PXA25X_UDC_H
#error You cannot include both PXA25x and PXA27x UDC support
#endif

#define UDCCR           __REG(0x40600000) /*                      */
#define UDCCR_OEN	(1 << 31)	/*                  */
#define UDCCR_AALTHNP	(1 << 30)	/*                                    
                              */
#define UDCCR_AHNP	(1 << 29)	/*                                   
                */
#define UDCCR_BHNP	(1 << 28)	/*                                   
               */
#define UDCCR_DWRE	(1 << 16)	/*                              */
#define UDCCR_ACN	(0x03 << 11)	/*                                 */
#define UDCCR_ACN_S	11
#define UDCCR_AIN	(0x07 << 8)	/*                             */
#define UDCCR_AIN_S	8
#define UDCCR_AAISN	(0x07 << 5)	/*                               
                       */
#define UDCCR_AAISN_S	5
#define UDCCR_SMAC	(1 << 4)	/*                                 
                      */
#define UDCCR_EMCE	(1 << 3)	/*                              
              */
#define UDCCR_UDR	(1 << 2)	/*            */
#define UDCCR_UDA	(1 << 1)	/*            */
#define UDCCR_UDE	(1 << 0)	/*            */

#define UDCICR0         __REG(0x40600004) /*                                 */
#define UDCICR1         __REG(0x40600008) /*                                 */
#define UDCICR_FIFOERR	(1 << 1)	/*                             */
#define UDCICR_PKTCOMPL (1 << 0)	/*                                  */

#define UDC_INT_FIFOERROR  (0x2)
#define UDC_INT_PACKETCMP  (0x1)

#define UDCICR_INT(n,intr) (((intr) & 0x03) << (((n) & 0x0F) * 2))
#define UDCICR1_IECC	(1 << 31)	/*                              */
#define UDCICR1_IESOF	(1 << 30)	/*                        */
#define UDCICR1_IERU	(1 << 29)	/*                */
#define UDCICR1_IESU	(1 << 28)	/*                 */
#define UDCICR1_IERS	(1 << 27)	/*               */

#define UDCISR0         __REG(0x4060000C) /*                                 */
#define UDCISR1         __REG(0x40600010) /*                                 */
#define UDCISR_INT(n,intr) (((intr) & 0x03) << (((n) & 0x0F) * 2))
#define UDCISR1_IRCC	(1 << 31)	/*                               */
#define UDCISR1_IRSOF	(1 << 30)	/*                         */
#define UDCISR1_IRRU	(1 << 29)	/*                 */
#define UDCISR1_IRSU	(1 << 28)	/*                  */
#define UDCISR1_IRRS	(1 << 27)	/*                */

#define UDCFNR          __REG(0x40600014) /*                           */
#define UDCOTGICR	__REG(0x40600018) /*                                 */
#define UDCOTGICR_IESF	(1 << 24)	/*                               */
#define UDCOTGICR_IEXR	(1 << 17)	/*                            
                                     */
#define UDCOTGICR_IEXF	(1 << 16)	/*                            
                                      */
#define UDCOTGICR_IEVV40R (1 << 9)	/*                                
                         */
#define UDCOTGICR_IEVV40F (1 << 8)	/*                                 
                         */
#define UDCOTGICR_IEVV44R (1 << 7)	/*                                
                         */
#define UDCOTGICR_IEVV44F (1 << 6)	/*                                 
                         */
#define UDCOTGICR_IESVR	(1 << 5)	/*                              
                         */
#define UDCOTGICR_IESVF	(1 << 4)	/*                               
                         */
#define UDCOTGICR_IESDR	(1 << 3)	/*                               
                              */
#define UDCOTGICR_IESDF	(1 << 2)	/*                                
                              */
#define UDCOTGICR_IEIDR	(1 << 1)	/*                          
                         */
#define UDCOTGICR_IEIDF	(1 << 0)	/*                           
                         */

#define UP2OCR		  __REG(0x40600020)  /*                                    */
#define UP3OCR		  __REG(0x40600024)  /*                                    */

#define UP2OCR_CPVEN	(1 << 0)	/*                         */
#define UP2OCR_CPVPE	(1 << 1)	/*                               */
#define UP2OCR_DPPDE	(1 << 2)	/*                                             */
#define UP2OCR_DMPDE	(1 << 3)	/*                                             */
#define UP2OCR_DPPUE	(1 << 4)	/*                                           */
#define UP2OCR_DMPUE	(1 << 5)	/*                                           */
#define UP2OCR_DPPUBE	(1 << 6)	/*                                                  */
#define UP2OCR_DMPUBE	(1 << 7)	/*                                                  */
#define UP2OCR_EXSP		(1 << 8)	/*                                    */
#define UP2OCR_EXSUS	(1 << 9)	/*                                   */
#define UP2OCR_IDON		(1 << 10)	/*                    */
#define UP2OCR_HXS		(1 << 16)	/*                                       */
#define UP2OCR_HXOE		(1 << 17)	/*                                       */
#define UP2OCR_SEOS(x)		((x & 7) << 24)	/*                            */

#define UDCCSN(x)	__REG2(0x40600100, (x) << 2)
#define UDCCSR0         __REG(0x40600100) /*                                          */
#define UDCCSR0_SA	(1 << 7)	/*              */
#define UDCCSR0_RNE	(1 << 6)	/*                        */
#define UDCCSR0_FST	(1 << 5)	/*             */
#define UDCCSR0_SST	(1 << 4)	/*            */
#define UDCCSR0_DME	(1 << 3)	/*            */
#define UDCCSR0_FTF	(1 << 2)	/*                     */
#define UDCCSR0_IPR	(1 << 1)	/*                 */
#define UDCCSR0_OPC	(1 << 0)	/*                     */

#define UDCCSRA         __REG(0x40600104) /*                                          */
#define UDCCSRB         __REG(0x40600108) /*                                          */
#define UDCCSRC         __REG(0x4060010C) /*                                          */
#define UDCCSRD         __REG(0x40600110) /*                                          */
#define UDCCSRE         __REG(0x40600114) /*                                          */
#define UDCCSRF         __REG(0x40600118) /*                                          */
#define UDCCSRG         __REG(0x4060011C) /*                                          */
#define UDCCSRH         __REG(0x40600120) /*                                          */
#define UDCCSRI         __REG(0x40600124) /*                                          */
#define UDCCSRJ         __REG(0x40600128) /*                                          */
#define UDCCSRK         __REG(0x4060012C) /*                                          */
#define UDCCSRL         __REG(0x40600130) /*                                          */
#define UDCCSRM         __REG(0x40600134) /*                                          */
#define UDCCSRN         __REG(0x40600138) /*                                          */
#define UDCCSRP         __REG(0x4060013C) /*                                          */
#define UDCCSRQ         __REG(0x40600140) /*                                          */
#define UDCCSRR         __REG(0x40600144) /*                                          */
#define UDCCSRS         __REG(0x40600148) /*                                          */
#define UDCCSRT         __REG(0x4060014C) /*                                          */
#define UDCCSRU         __REG(0x40600150) /*                                          */
#define UDCCSRV         __REG(0x40600154) /*                                          */
#define UDCCSRW         __REG(0x40600158) /*                                          */
#define UDCCSRX         __REG(0x4060015C) /*                                          */

#define UDCCSR_DPE	(1 << 9)	/*                   */
#define UDCCSR_FEF	(1 << 8)	/*                     */
#define UDCCSR_SP	(1 << 7)	/*                             */
#define UDCCSR_BNE	(1 << 6)	/*                                 */
#define UDCCSR_BNF	(1 << 6)	/*                                 */
#define UDCCSR_FST	(1 << 5)	/*             */
#define UDCCSR_SST	(1 << 4)	/*            */
#define UDCCSR_DME	(1 << 3)	/*            */
#define UDCCSR_TRN	(1 << 2)	/*           */
#define UDCCSR_PC	(1 << 1)	/*                 */
#define UDCCSR_FS	(1 << 0)	/*                    */

#define UDCBCN(x)	__REG2(0x40600200, (x)<<2)
#define UDCBCR0         __REG(0x40600200) /*                           */
#define UDCBCRA         __REG(0x40600204) /*                           */
#define UDCBCRB         __REG(0x40600208) /*                           */
#define UDCBCRC         __REG(0x4060020C) /*                           */
#define UDCBCRD         __REG(0x40600210) /*                           */
#define UDCBCRE         __REG(0x40600214) /*                           */
#define UDCBCRF         __REG(0x40600218) /*                           */
#define UDCBCRG         __REG(0x4060021C) /*                           */
#define UDCBCRH         __REG(0x40600220) /*                           */
#define UDCBCRI         __REG(0x40600224) /*                           */
#define UDCBCRJ         __REG(0x40600228) /*                           */
#define UDCBCRK         __REG(0x4060022C) /*                           */
#define UDCBCRL         __REG(0x40600230) /*                           */
#define UDCBCRM         __REG(0x40600234) /*                           */
#define UDCBCRN         __REG(0x40600238) /*                           */
#define UDCBCRP         __REG(0x4060023C) /*                           */
#define UDCBCRQ         __REG(0x40600240) /*                           */
#define UDCBCRR         __REG(0x40600244) /*                           */
#define UDCBCRS         __REG(0x40600248) /*                           */
#define UDCBCRT         __REG(0x4060024C) /*                           */
#define UDCBCRU         __REG(0x40600250) /*                           */
#define UDCBCRV         __REG(0x40600254) /*                           */
#define UDCBCRW         __REG(0x40600258) /*                           */
#define UDCBCRX         __REG(0x4060025C) /*                           */

#define UDCDN(x)	__REG2(0x40600300, (x)<<2)
#define PHYS_UDCDN(x)	(0x40600300 + ((x)<<2))
#define PUDCDN(x)	(volatile u32 *)(io_p2v(PHYS_UDCDN((x))))
#define UDCDR0          __REG(0x40600300) /*                     */
#define UDCDRA          __REG(0x40600304) /*                     */
#define UDCDRB          __REG(0x40600308) /*                     */
#define UDCDRC          __REG(0x4060030C) /*                     */
#define UDCDRD          __REG(0x40600310) /*                     */
#define UDCDRE          __REG(0x40600314) /*                     */
#define UDCDRF          __REG(0x40600318) /*                     */
#define UDCDRG          __REG(0x4060031C) /*                     */
#define UDCDRH          __REG(0x40600320) /*                     */
#define UDCDRI          __REG(0x40600324) /*                     */
#define UDCDRJ          __REG(0x40600328) /*                     */
#define UDCDRK          __REG(0x4060032C) /*                     */
#define UDCDRL          __REG(0x40600330) /*                     */
#define UDCDRM          __REG(0x40600334) /*                     */
#define UDCDRN          __REG(0x40600338) /*                     */
#define UDCDRP          __REG(0x4060033C) /*                     */
#define UDCDRQ          __REG(0x40600340) /*                     */
#define UDCDRR          __REG(0x40600344) /*                     */
#define UDCDRS          __REG(0x40600348) /*                     */
#define UDCDRT          __REG(0x4060034C) /*                     */
#define UDCDRU          __REG(0x40600350) /*                     */
#define UDCDRV          __REG(0x40600354) /*                     */
#define UDCDRW          __REG(0x40600358) /*                     */
#define UDCDRX          __REG(0x4060035C) /*                     */

#define UDCCN(x)       __REG2(0x40600400, (x)<<2)
#define UDCCRA          __REG(0x40600404) /*                            */
#define UDCCRB          __REG(0x40600408) /*                            */
#define UDCCRC          __REG(0x4060040C) /*                            */
#define UDCCRD          __REG(0x40600410) /*                            */
#define UDCCRE          __REG(0x40600414) /*                            */
#define UDCCRF          __REG(0x40600418) /*                            */
#define UDCCRG          __REG(0x4060041C) /*                            */
#define UDCCRH          __REG(0x40600420) /*                            */
#define UDCCRI          __REG(0x40600424) /*                            */
#define UDCCRJ          __REG(0x40600428) /*                            */
#define UDCCRK          __REG(0x4060042C) /*                            */
#define UDCCRL          __REG(0x40600430) /*                            */
#define UDCCRM          __REG(0x40600434) /*                            */
#define UDCCRN          __REG(0x40600438) /*                            */
#define UDCCRP          __REG(0x4060043C) /*                            */
#define UDCCRQ          __REG(0x40600440) /*                            */
#define UDCCRR          __REG(0x40600444) /*                            */
#define UDCCRS          __REG(0x40600448) /*                            */
#define UDCCRT          __REG(0x4060044C) /*                            */
#define UDCCRU          __REG(0x40600450) /*                            */
#define UDCCRV          __REG(0x40600454) /*                            */
#define UDCCRW          __REG(0x40600458) /*                            */
#define UDCCRX          __REG(0x4060045C) /*                            */

#define UDCCONR_CN	(0x03 << 25)	/*                      */
#define UDCCONR_CN_S	(25)
#define UDCCONR_IN	(0x07 << 22)	/*                  */
#define UDCCONR_IN_S	(22)
#define UDCCONR_AISN	(0x07 << 19)	/*                            */
#define UDCCONR_AISN_S	(19)
#define UDCCONR_EN	(0x0f << 15)	/*                 */
#define UDCCONR_EN_S	(15)
#define UDCCONR_ET	(0x03 << 13)	/*                */
#define UDCCONR_ET_S	(13)
#define UDCCONR_ET_INT	(0x03 << 13)	/*             */
#define UDCCONR_ET_BULK	(0x02 << 13)	/*        */
#define UDCCONR_ET_ISO	(0x01 << 13)	/*               */
#define UDCCONR_ET_NU	(0x00 << 13)	/*            */
#define UDCCONR_ED	(1 << 12)	/*                    */
#define UDCCONR_MPS	(0x3ff << 2)	/*                     */
#define UDCCONR_MPS_S	(2)
#define UDCCONR_DE	(1 << 1)	/*                         */
#define UDCCONR_EE	(1 << 0)	/*                 */


#define UDC_INT_FIFOERROR  (0x2)
#define UDC_INT_PACKETCMP  (0x1)

#define UDC_FNR_MASK     (0x7ff)

#define UDCCSR_WR_MASK   (UDCCSR_DME|UDCCSR_FST)
#define UDC_BCR_MASK    (0x3ff)

#endif
