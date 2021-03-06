/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2002, 2004, 2007 by Ralf Baechle
 * Copyright (C) 2007  Maciej W. Rozycki
 */
#ifndef _ASM_WAR_H
#define _ASM_WAR_H

#include <war.h>

/*
                                                                
  
                                                                   
                                                                
                                                              
                
                                                                   
        
  
                                                                   
                                                                
                                                              
                     
  
                                                                   
                                              
                                                              
                
 */
#ifdef CONFIG_CPU_R4000_WORKAROUNDS
#define R4000_WAR 1
#else
#define R4000_WAR 0
#endif

/*
                                                                
  
                                                                   
                                                                
                                                               
                                                                    
 */
#ifdef CONFIG_CPU_R4400_WORKAROUNDS
#define R4400_WAR 1
#else
#define R4400_WAR 0
#endif

/*
                                                   
  
                                                       
                                                              
                
  
                                                              
                                                              
                
                                                                   
        
                                                                 
                                                              
 */
#ifdef CONFIG_CPU_DADDI_WORKAROUNDS
#define DADDI_WAR 1
#else
#define DADDI_WAR 0
#endif

/*
                                                                          
                                                                            
                                                                           
                  
 */
#ifndef R4600_V1_INDEX_ICACHEOP_WAR
#error Check setting of R4600_V1_INDEX_ICACHEOP_WAR for your platform
#endif

/*
                                                                     
  
                                                                           
                                                               
                                                                       
                                                                         
                                                                        
                                                                  
                                                                          
                                                                
                    
  
                                  
                                   
                                   
                                   
                                                                      
  
                                  
                                   
                                   
                                   
                                   
                                                                      
 */
#ifndef R4600_V1_HIT_CACHEOP_WAR
#error Check setting of R4600_V1_HIT_CACHEOP_WAR for your platform
#endif


/*
                                                                
  
                                                               
                                                                           
                                                                              
                                                                            
                                                                              
                                                                        
                   
 */
#ifndef R4600_V2_HIT_CACHEOP_WAR
#error Check setting of R4600_V2_HIT_CACHEOP_WAR for your platform
#endif

/*
                                                                        
                                                                    
                         
  
                                                                       
                                                                
                                   
 */
#ifndef R5432_CP0_INTERRUPT_WAR
#error Check setting of R5432_CP0_INTERRUPT_WAR for your platform
#endif

/*
                                                                        
  
                                                               
  
                                                                        
                                                                         
                                                                       
                            
 */
#ifndef BCM1250_M3_WAR
#error Check setting of BCM1250_M3_WAR for your platform
#endif

/*
                                                                          
 */
#ifndef SIBYTE_1956_WAR
#error Check setting of SIBYTE_1956_WAR for your platform
#endif

/*
                                                 
  
                                                                     
                                                                   
                                                                      
  
                                                              
  
           
                                                
 */
#ifndef MIPS4K_ICACHE_REFILL_WAR
#error Check setting of MIPS4K_ICACHE_REFILL_WAR for your platform
#endif

/*
                                                             
              
  
                                                                    
                                                                      
                                                                      
                                                     
  
                                                                     
  
           
                                                     
                                                   
 */
#ifndef MIPS_CACHE_SYNC_WAR
#error Check setting of MIPS_CACHE_SYNC_WAR for your platform
#endif

/*
                                                                      
                                                               
                                
  
                                                           
 */
#ifndef TX49XX_ICACHE_INDEX_INV_WAR
#error Check setting of TX49XX_ICACHE_INDEX_INV_WAR for your platform
#endif

/*
                                                                        
                                           
 */
#ifndef RM9000_CDEX_SMP_WAR
#error Check setting of RM9000_CDEX_SMP_WAR for your platform
#endif

/*
                                                                          
                                                                       
                                                                     
              
 */
#ifndef ICACHE_REFILLS_WORKAROUND_WAR
#error Check setting of ICACHE_REFILLS_WORKAROUND_WAR for your platform
#endif

/*
                                                                           
                                                                       
 */
#ifndef R10000_LLSC_WAR
#error Check setting of R10000_LLSC_WAR for your platform
#endif

/*
                                                              
 */
#ifndef MIPS34K_MISSED_ITLB_WAR
#error Check setting of MIPS34K_MISSED_ITLB_WAR for your platform
#endif

#endif /*            */
