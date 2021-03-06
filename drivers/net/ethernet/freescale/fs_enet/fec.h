#ifndef FS_ENET_FEC_H
#define FS_ENET_FEC_H

/*                                                                  */
#define FEC_CRC_POLY   0x04C11DB7

#define FEC_MAX_MULTICAST_ADDRS	64

/*                        
*/
#define FEC_ENET_HBERR	0x80000000U	/*                          */
#define FEC_ENET_BABR	0x40000000U	/*                          */
#define FEC_ENET_BABT	0x20000000U	/*                          */
#define FEC_ENET_GRA	0x10000000U	/*                          */
#define FEC_ENET_TXF	0x08000000U	/*                          */
#define FEC_ENET_TXB	0x04000000U	/*                          */
#define FEC_ENET_RXF	0x02000000U	/*                          */
#define FEC_ENET_RXB	0x01000000U	/*                          */
#define FEC_ENET_MII	0x00800000U	/*                          */
#define FEC_ENET_EBERR	0x00400000U	/*                          */

#define FEC_ECNTRL_PINMUX	0x00000004
#define FEC_ECNTRL_ETHER_EN	0x00000002
#define FEC_ECNTRL_RESET	0x00000001

/*                                                      */
#define FEC_RCNTRL_RMII_MODE	(0x00000100 | \
				 FEC_RCNTRL_MII_MODE | FEC_RCNTRL_FCE)
#define FEC_RCNTRL_FCE		0x00000020
#define FEC_RCNTRL_BC_REJ	0x00000010
#define FEC_RCNTRL_PROM		0x00000008
#define FEC_RCNTRL_MII_MODE	0x00000004
#define FEC_RCNTRL_DRT		0x00000002
#define FEC_RCNTRL_LOOP		0x00000001

#define FEC_TCNTRL_FDEN		0x00000004
#define FEC_TCNTRL_HBC		0x00000002
#define FEC_TCNTRL_GTS		0x00000001

/*
                                                          
 */
#define FEC_RESET_DELAY		50
#endif
