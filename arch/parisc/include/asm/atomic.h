/* Copyright (C) 2000 Philipp Rumpf <prumpf@tux.org>
 * Copyright (C) 2006 Kyle McMartin <kyle@parisc-linux.org>
 */

#ifndef _ASM_PARISC_ATOMIC_H_
#define _ASM_PARISC_ATOMIC_H_

#include <linux/types.h>
#include <asm/cmpxchg.h>

/*
                                                           
                          
  
                                                          
                                               
 */

#ifdef CONFIG_SMP
#include <asm/spinlock.h>
#include <asm/cache.h>		/*                       */

/*                                             
                                                    
                                                                   
 */
#  define ATOMIC_HASH_SIZE 4
#  define ATOMIC_HASH(a) (&(__atomic_hash[ (((unsigned long) (a))/L1_CACHE_BYTES) & (ATOMIC_HASH_SIZE-1) ]))

extern arch_spinlock_t __atomic_hash[ATOMIC_HASH_SIZE] __lock_aligned;

/*                                                             
                          */
#define _atomic_spin_lock_irqsave(l,f) do {	\
	arch_spinlock_t *s = ATOMIC_HASH(l);		\
	local_irq_save(f);			\
	arch_spin_lock(s);			\
} while(0)

#define _atomic_spin_unlock_irqrestore(l,f) do {	\
	arch_spinlock_t *s = ATOMIC_HASH(l);			\
	arch_spin_unlock(s);				\
	local_irq_restore(f);				\
} while(0)


#else
#  define _atomic_spin_lock_irqsave(l,f) do { local_irq_save(f); } while (0)
#  define _atomic_spin_unlock_irqrestore(l,f) do { local_irq_restore(f); } while (0)
#endif

/*
                                                                       
                                                          
 */

/*                                                        
                                                              
                                  
 */

static __inline__ int __atomic_add_return(int i, atomic_t *v)
{
	int ret;
	unsigned long flags;
	_atomic_spin_lock_irqsave(v, flags);

	ret = (v->counter += i);

	_atomic_spin_unlock_irqrestore(v, flags);
	return ret;
}

static __inline__ void atomic_set(atomic_t *v, int i) 
{
	unsigned long flags;
	_atomic_spin_lock_irqsave(v, flags);

	v->counter = i;

	_atomic_spin_unlock_irqrestore(v, flags);
}

static __inline__ int atomic_read(const atomic_t *v)
{
	return (*(volatile int *)&(v)->counter);
}

/*                    */
#define atomic_cmpxchg(v, o, n) (cmpxchg(&((v)->counter), (o), (n)))
#define atomic_xchg(v, new) (xchg(&((v)->counter), new))

/* 
                                                               
                               
                                
                                 
  
                                                      
                               
 */
static __inline__ int __atomic_add_unless(atomic_t *v, int a, int u)
{
	int c, old;
	c = atomic_read(v);
	for (;;) {
		if (unlikely(c == (u)))
			break;
		old = atomic_cmpxchg((v), c, c + (a));
		if (likely(old == c))
			break;
		c = old;
	}
	return c;
}


#define atomic_add(i,v)	((void)(__atomic_add_return( (i),(v))))
#define atomic_sub(i,v)	((void)(__atomic_add_return(-(i),(v))))
#define atomic_inc(v)	((void)(__atomic_add_return(   1,(v))))
#define atomic_dec(v)	((void)(__atomic_add_return(  -1,(v))))

#define atomic_add_return(i,v)	(__atomic_add_return( (i),(v)))
#define atomic_sub_return(i,v)	(__atomic_add_return(-(i),(v)))
#define atomic_inc_return(v)	(__atomic_add_return(   1,(v)))
#define atomic_dec_return(v)	(__atomic_add_return(  -1,(v)))

#define atomic_add_negative(a, v)	(atomic_add_return((a), (v)) < 0)

/*
                                           
                               
  
                                
                                                           
               
 */
#define atomic_inc_and_test(v) (atomic_inc_return(v) == 0)

#define atomic_dec_and_test(v)	(atomic_dec_return(v) == 0)

#define atomic_sub_and_test(i,v)	(atomic_sub_return((i),(v)) == 0)

#define ATOMIC_INIT(i)	((atomic_t) { (i) })

#define smp_mb__before_atomic_dec()	smp_mb()
#define smp_mb__after_atomic_dec()	smp_mb()
#define smp_mb__before_atomic_inc()	smp_mb()
#define smp_mb__after_atomic_inc()	smp_mb()

#ifdef CONFIG_64BIT

#define ATOMIC64_INIT(i) ((atomic64_t) { (i) })

static __inline__ s64
__atomic64_add_return(s64 i, atomic64_t *v)
{
	s64 ret;
	unsigned long flags;
	_atomic_spin_lock_irqsave(v, flags);

	ret = (v->counter += i);

	_atomic_spin_unlock_irqrestore(v, flags);
	return ret;
}

static __inline__ void
atomic64_set(atomic64_t *v, s64 i)
{
	unsigned long flags;
	_atomic_spin_lock_irqsave(v, flags);

	v->counter = i;

	_atomic_spin_unlock_irqrestore(v, flags);
}

static __inline__ s64
atomic64_read(const atomic64_t *v)
{
	return (*(volatile long *)&(v)->counter);
}

#define atomic64_add(i,v)	((void)(__atomic64_add_return( ((s64)(i)),(v))))
#define atomic64_sub(i,v)	((void)(__atomic64_add_return(-((s64)(i)),(v))))
#define atomic64_inc(v)		((void)(__atomic64_add_return(   1,(v))))
#define atomic64_dec(v)		((void)(__atomic64_add_return(  -1,(v))))

#define atomic64_add_return(i,v)	(__atomic64_add_return( ((s64)(i)),(v)))
#define atomic64_sub_return(i,v)	(__atomic64_add_return(-((s64)(i)),(v)))
#define atomic64_inc_return(v)		(__atomic64_add_return(   1,(v)))
#define atomic64_dec_return(v)		(__atomic64_add_return(  -1,(v)))

#define atomic64_add_negative(a, v)	(atomic64_add_return((a), (v)) < 0)

#define atomic64_inc_and_test(v) 	(atomic64_inc_return(v) == 0)
#define atomic64_dec_and_test(v)	(atomic64_dec_return(v) == 0)
#define atomic64_sub_and_test(i,v)	(atomic64_sub_return((i),(v)) == 0)

/*                    */
#define atomic64_cmpxchg(v, o, n) \
	((__typeof__((v)->counter))cmpxchg(&((v)->counter), (o), (n)))
#define atomic64_xchg(v, new) (xchg(&((v)->counter), new))

/* 
                                                               
                                 
                                
                                 
  
                                                      
                               
 */
static __inline__ int atomic64_add_unless(atomic64_t *v, long a, long u)
{
	long c, old;
	c = atomic64_read(v);
	for (;;) {
		if (unlikely(c == (u)))
			break;
		old = atomic64_cmpxchg((v), c, c + (a));
		if (likely(old == c))
			break;
		c = old;
	}
	return c != (u);
}

#define atomic64_inc_not_zero(v) atomic64_add_unless((v), 1, 0)

#endif /*               */


#endif /*                       */
