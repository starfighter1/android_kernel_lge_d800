/*
 *  mm/pgtable-generic.c
 *
 *  Generic pgtable methods declared in asm-generic/pgtable.h
 *
 *  Copyright (C) 2010  Linus Torvalds
 */

#include <linux/pagemap.h>
#include <asm/tlb.h>
#include <asm-generic/pgtable.h>

#ifndef __HAVE_ARCH_PTEP_SET_ACCESS_FLAGS
/*
                                                   
                                                                
                                                                   
                                                                  
                                                                  
                                                                 
                                                             
 */
int ptep_set_access_flags(struct vm_area_struct *vma,
			  unsigned long address, pte_t *ptep,
			  pte_t entry, int dirty)
{
	int changed = !pte_same(*ptep, entry);
	if (changed) {
		set_pte_at(vma->vm_mm, address, ptep, entry);
		flush_tlb_page(vma, address);
	}
	return changed;
}
#endif

#ifndef __HAVE_ARCH_PMDP_SET_ACCESS_FLAGS
int pmdp_set_access_flags(struct vm_area_struct *vma,
			  unsigned long address, pmd_t *pmdp,
			  pmd_t entry, int dirty)
{
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
	int changed = !pmd_same(*pmdp, entry);
	VM_BUG_ON(address & ~HPAGE_PMD_MASK);
	if (changed) {
		set_pmd_at(vma->vm_mm, address, pmdp, entry);
		flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
	}
	return changed;
#else /*                             */
	BUG();
	return 0;
#endif /*                             */
}
#endif

#ifndef __HAVE_ARCH_PTEP_CLEAR_YOUNG_FLUSH
int ptep_clear_flush_young(struct vm_area_struct *vma,
			   unsigned long address, pte_t *ptep)
{
	int young;
	young = ptep_test_and_clear_young(vma, address, ptep);
	if (young)
		flush_tlb_page(vma, address);
	return young;
}
#endif

#ifndef __HAVE_ARCH_PMDP_CLEAR_YOUNG_FLUSH
int pmdp_clear_flush_young(struct vm_area_struct *vma,
			   unsigned long address, pmd_t *pmdp)
{
	int young;
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
	VM_BUG_ON(address & ~HPAGE_PMD_MASK);
#else
	BUG();
#endif /*                             */
	young = pmdp_test_and_clear_young(vma, address, pmdp);
	if (young)
		flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
	return young;
}
#endif

#ifndef __HAVE_ARCH_PTEP_CLEAR_FLUSH
pte_t ptep_clear_flush(struct vm_area_struct *vma, unsigned long address,
		       pte_t *ptep)
{
	pte_t pte;
	pte = ptep_get_and_clear((vma)->vm_mm, address, ptep);
	flush_tlb_page(vma, address);
	return pte;
}
#endif

#ifndef __HAVE_ARCH_PMDP_CLEAR_FLUSH
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
pmd_t pmdp_clear_flush(struct vm_area_struct *vma, unsigned long address,
		       pmd_t *pmdp)
{
	pmd_t pmd;
	VM_BUG_ON(address & ~HPAGE_PMD_MASK);
	pmd = pmdp_get_and_clear(vma->vm_mm, address, pmdp);
	flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
	return pmd;
}
#endif /*                             */
#endif

#ifndef __HAVE_ARCH_PMDP_SPLITTING_FLUSH
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
pmd_t pmdp_splitting_flush(struct vm_area_struct *vma, unsigned long address,
			   pmd_t *pmdp)
{
	pmd_t pmd = pmd_mksplitting(*pmdp);
	VM_BUG_ON(address & ~HPAGE_PMD_MASK);
	set_pmd_at(vma->vm_mm, address, pmdp, pmd);
	/*                                              */
	flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
}
#endif /*                             */
#endif
