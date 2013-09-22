/*
                                                  
 */

#ifndef __ASM_ARCH_EP93XX_REGS_H
#define __ASM_ARCH_EP93XX_REGS_H

/*
                           
  
                   
                                       
                            
                            
 */

#define EP93XX_AHB_PHYS_BASE		0x80000000
#define EP93XX_AHB_VIRT_BASE		0xfef00000
#define EP93XX_AHB_SIZE			0x00100000

#define EP93XX_AHB_PHYS(x)		(EP93XX_AHB_PHYS_BASE + (x))
#define EP93XX_AHB_IOMEM(x)		IOMEM(EP93XX_AHB_VIRT_BASE + (x))

#define EP93XX_APB_PHYS_BASE		0x80800000
#define EP93XX_APB_VIRT_BASE		0xfed00000
#define EP93XX_APB_SIZE			0x00200000

#define EP93XX_APB_PHYS(x)		(EP93XX_APB_PHYS_BASE + (x))
#define EP93XX_APB_IOMEM(x)		IOMEM(EP93XX_APB_VIRT_BASE + (x))

/*           */
#define EP93XX_UART1_PHYS_BASE		EP93XX_APB_PHYS(0x000c0000)
#define EP93XX_UART1_BASE		EP93XX_APB_IOMEM(0x000c0000)

#define EP93XX_UART2_PHYS_BASE		EP93XX_APB_PHYS(0x000d0000)
#define EP93XX_UART2_BASE		EP93XX_APB_IOMEM(0x000d0000)

#define EP93XX_UART3_PHYS_BASE		EP93XX_APB_PHYS(0x000e0000)
#define EP93XX_UART3_BASE		EP93XX_APB_IOMEM(0x000e0000)

#endif
