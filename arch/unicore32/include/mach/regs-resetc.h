/*
                                          
 */
/*
                          
 */
#define RESETC_SWRR	(PKUNITY_RESETC_BASE + 0x0000)
/*
                        
 */
#define RESETC_RSSR	(PKUNITY_RESETC_BASE + 0x0004)

/*
                     
 */
#define RESETC_SWRR_SRB		FIELD(1, 1, 0)

/*
                 
 */
#define RESETC_RSSR_HWR		FIELD(1, 1, 0)
/*
                 
 */
#define RESETC_RSSR_SWR		FIELD(1, 1, 1)
/*
                 
 */
#define RESETC_RSSR_WDR		FIELD(1, 1, 2)
/*
                   
 */
#define RESETC_RSSR_SMR		FIELD(1, 1, 3)

