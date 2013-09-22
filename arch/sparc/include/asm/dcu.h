#ifndef _SPARC64_DCU_H
#define _SPARC64_DCU_H

#include <linux/const.h>

/*                                                 */
#define DCU_CP	_AC(0x0002000000000000,UL) /*                           */
#define DCU_CV	_AC(0x0001000000000000,UL) /*                           */
#define DCU_ME	_AC(0x0000800000000000,UL) /*                         */
#define DCU_RE	_AC(0x0000400000000000,UL) /*                    */
#define DCU_PE	_AC(0x0000200000000000,UL) /*                */
#define DCU_HPE	_AC(0x0000100000000000,UL) /*                    */
#define DCU_SPE	_AC(0x0000080000000000,UL) /*                    */
#define DCU_SL	_AC(0x0000040000000000,UL) /*                           */
#define DCU_WE	_AC(0x0000020000000000,UL) /*                */
#define DCU_PM	_AC(0x000001fe00000000,UL) /*                         */
#define DCU_VM	_AC(0x00000001fe000000,UL) /*                         */
#define DCU_PR	_AC(0x0000000001000000,UL) /*                           */
#define DCU_PW	_AC(0x0000000000800000,UL) /*                           */
#define DCU_VR	_AC(0x0000000000400000,UL) /*                           */
#define DCU_VW	_AC(0x0000000000200000,UL) /*                           */
#define DCU_DM	_AC(0x0000000000000008,UL) /*              */
#define DCU_IM	_AC(0x0000000000000004,UL) /*              */
#define DCU_DC	_AC(0x0000000000000002,UL) /*                    */
#define DCU_IC	_AC(0x0000000000000001,UL) /*                          */

#endif /*                */
