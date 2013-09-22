/*
 * Copyright (C) 2001 Mike Corrigan & Dave Engebretsen, IBM Corporation
 *
 * Rewrite, cleanup:
 *
 * Copyright (C) 2004 Olof Johansson <olof@lixom.net>, IBM Corporation
 * Copyright (C) 2006 Olof Johansson <olof@lixom.net>
 *
 * Dynamic DMA mapping support, pSeries-specific parts, both SMP and LPAR.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#include <linux/init.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/spinlock.h>
#include <linux/sched.h>	/*                */
#include <linux/string.h>
#include <linux/pci.h>
#include <linux/dma-mapping.h>
#include <linux/crash_dump.h>
#include <linux/memory.h>
#include <asm/io.h>
#include <asm/prom.h>
#include <asm/rtas.h>
#include <asm/iommu.h>
#include <asm/pci-bridge.h>
#include <asm/machdep.h>
#include <asm/abs_addr.h>
#include <asm/pSeries_reconfig.h>
#include <asm/firmware.h>
#include <asm/tce.h>
#include <asm/ppc-pci.h>
#include <asm/udbg.h>
#include <asm/mmzone.h>

#include "plpar_wrappers.h"


static void tce_invalidate_pSeries_sw(struct iommu_table *tbl,
				      u64 *startp, u64 *endp)
{
	u64 __iomem *invalidate = (u64 __iomem *)tbl->it_index;
	unsigned long start, end, inc;

	start = __pa(startp);
	end = __pa(endp);
	inc = L1_CACHE_BYTES; /*                                          */

	/*                                                      
                                                      */
	if (tbl->it_busno) {
		start <<= 12;
		end <<= 12;
		inc <<= 12;
		start |= tbl->it_busno;
		end |= tbl->it_busno;
	}

	end |= inc - 1; /*                                         */

	mb(); /*                                      */
	while (start <= end) {
		out_be64(invalidate, start);
		start += inc;
	}
}

static int tce_build_pSeries(struct iommu_table *tbl, long index,
			      long npages, unsigned long uaddr,
			      enum dma_data_direction direction,
			      struct dma_attrs *attrs)
{
	u64 proto_tce;
	u64 *tcep, *tces;
	u64 rpn;

	proto_tce = TCE_PCI_READ; //             

	if (direction != DMA_TO_DEVICE)
		proto_tce |= TCE_PCI_WRITE;

	tces = tcep = ((u64 *)tbl->it_base) + index;

	while (npages--) {
		/*                                                            */
		rpn = (virt_to_abs(uaddr)) >> TCE_SHIFT;
		*tcep = proto_tce | (rpn & TCE_RPN_MASK) << TCE_RPN_SHIFT;

		uaddr += TCE_PAGE_SIZE;
		tcep++;
	}

	if (tbl->it_type == TCE_PCI_SWINV_CREATE)
		tce_invalidate_pSeries_sw(tbl, tces, tcep - 1);
	return 0;
}


static void tce_free_pSeries(struct iommu_table *tbl, long index, long npages)
{
	u64 *tcep, *tces;

	tces = tcep = ((u64 *)tbl->it_base) + index;

	while (npages--)
		*(tcep++) = 0;

	if (tbl->it_type == TCE_PCI_SWINV_FREE)
		tce_invalidate_pSeries_sw(tbl, tces, tcep - 1);
}

static unsigned long tce_get_pseries(struct iommu_table *tbl, long index)
{
	u64 *tcep;

	tcep = ((u64 *)tbl->it_base) + index;

	return *tcep;
}

static void tce_free_pSeriesLP(struct iommu_table*, long, long);
static void tce_freemulti_pSeriesLP(struct iommu_table*, long, long);

static int tce_build_pSeriesLP(struct iommu_table *tbl, long tcenum,
				long npages, unsigned long uaddr,
				enum dma_data_direction direction,
				struct dma_attrs *attrs)
{
	u64 rc = 0;
	u64 proto_tce, tce;
	u64 rpn;
	int ret = 0;
	long tcenum_start = tcenum, npages_start = npages;

	rpn = (virt_to_abs(uaddr)) >> TCE_SHIFT;
	proto_tce = TCE_PCI_READ;
	if (direction != DMA_TO_DEVICE)
		proto_tce |= TCE_PCI_WRITE;

	while (npages--) {
		tce = proto_tce | (rpn & TCE_RPN_MASK) << TCE_RPN_SHIFT;
		rc = plpar_tce_put((u64)tbl->it_index, (u64)tcenum << 12, tce);

		if (unlikely(rc == H_NOT_ENOUGH_RESOURCES)) {
			ret = (int)rc;
			tce_free_pSeriesLP(tbl, tcenum_start,
			                   (npages_start - (npages + 1)));
			break;
		}

		if (rc && printk_ratelimit()) {
			printk("tce_build_pSeriesLP: plpar_tce_put failed. rc=%lld\n", rc);
			printk("\tindex   = 0x%llx\n", (u64)tbl->it_index);
			printk("\ttcenum  = 0x%llx\n", (u64)tcenum);
			printk("\ttce val = 0x%llx\n", tce );
			show_stack(current, (unsigned long *)__get_SP());
		}

		tcenum++;
		rpn++;
	}
	return ret;
}

static DEFINE_PER_CPU(u64 *, tce_page);

static int tce_buildmulti_pSeriesLP(struct iommu_table *tbl, long tcenum,
				     long npages, unsigned long uaddr,
				     enum dma_data_direction direction,
				     struct dma_attrs *attrs)
{
	u64 rc = 0;
	u64 proto_tce;
	u64 *tcep;
	u64 rpn;
	long l, limit;
	long tcenum_start = tcenum, npages_start = npages;
	int ret = 0;

	if (npages == 1) {
		return tce_build_pSeriesLP(tbl, tcenum, npages, uaddr,
		                           direction, attrs);
	}

	tcep = __get_cpu_var(tce_page);

	/*                                                              
                            
  */
	if (!tcep) {
		tcep = (u64 *)__get_free_page(GFP_ATOMIC);
		/*                                                           */
		if (!tcep) {
			return tce_build_pSeriesLP(tbl, tcenum, npages, uaddr,
					    direction, attrs);
		}
		__get_cpu_var(tce_page) = tcep;
	}

	rpn = (virt_to_abs(uaddr)) >> TCE_SHIFT;
	proto_tce = TCE_PCI_READ;
	if (direction != DMA_TO_DEVICE)
		proto_tce |= TCE_PCI_WRITE;

	/*                                              */
	do {
		/*
                                                               
                
   */
		limit = min_t(long, npages, 4096/TCE_ENTRY_SIZE);

		for (l = 0; l < limit; l++) {
			tcep[l] = proto_tce | (rpn & TCE_RPN_MASK) << TCE_RPN_SHIFT;
			rpn++;
		}

		rc = plpar_tce_put_indirect((u64)tbl->it_index,
					    (u64)tcenum << 12,
					    (u64)virt_to_abs(tcep),
					    limit);

		npages -= limit;
		tcenum += limit;
	} while (npages > 0 && !rc);

	if (unlikely(rc == H_NOT_ENOUGH_RESOURCES)) {
		ret = (int)rc;
		tce_freemulti_pSeriesLP(tbl, tcenum_start,
		                        (npages_start - (npages + limit)));
		return ret;
	}

	if (rc && printk_ratelimit()) {
		printk("tce_buildmulti_pSeriesLP: plpar_tce_put failed. rc=%lld\n", rc);
		printk("\tindex   = 0x%llx\n", (u64)tbl->it_index);
		printk("\tnpages  = 0x%llx\n", (u64)npages);
		printk("\ttce[0] val = 0x%llx\n", tcep[0]);
		show_stack(current, (unsigned long *)__get_SP());
	}
	return ret;
}

static void tce_free_pSeriesLP(struct iommu_table *tbl, long tcenum, long npages)
{
	u64 rc;

	while (npages--) {
		rc = plpar_tce_put((u64)tbl->it_index, (u64)tcenum << 12, 0);

		if (rc && printk_ratelimit()) {
			printk("tce_free_pSeriesLP: plpar_tce_put failed. rc=%lld\n", rc);
			printk("\tindex   = 0x%llx\n", (u64)tbl->it_index);
			printk("\ttcenum  = 0x%llx\n", (u64)tcenum);
			show_stack(current, (unsigned long *)__get_SP());
		}

		tcenum++;
	}
}


static void tce_freemulti_pSeriesLP(struct iommu_table *tbl, long tcenum, long npages)
{
	u64 rc;

	rc = plpar_tce_stuff((u64)tbl->it_index, (u64)tcenum << 12, 0, npages);

	if (rc && printk_ratelimit()) {
		printk("tce_freemulti_pSeriesLP: plpar_tce_stuff failed\n");
		printk("\trc      = %lld\n", rc);
		printk("\tindex   = 0x%llx\n", (u64)tbl->it_index);
		printk("\tnpages  = 0x%llx\n", (u64)npages);
		show_stack(current, (unsigned long *)__get_SP());
	}
}

static unsigned long tce_get_pSeriesLP(struct iommu_table *tbl, long tcenum)
{
	u64 rc;
	unsigned long tce_ret;

	rc = plpar_tce_get((u64)tbl->it_index, (u64)tcenum << 12, &tce_ret);

	if (rc && printk_ratelimit()) {
		printk("tce_get_pSeriesLP: plpar_tce_get failed. rc=%lld\n", rc);
		printk("\tindex   = 0x%llx\n", (u64)tbl->it_index);
		printk("\ttcenum  = 0x%llx\n", (u64)tcenum);
		show_stack(current, (unsigned long *)__get_SP());
	}

	return tce_ret;
}

/*                                                            */
struct dynamic_dma_window_prop {
	__be32	liobn;		/*                  */
	__be64	dma_base;	/*               */
	__be32	tce_shift;	/*                      */
	__be32	window_shift;	/*                        */
};

struct direct_window {
	struct device_node *device;
	const struct dynamic_dma_window_prop *prop;
	struct list_head list;
};

/*                            */
struct ddw_query_response {
	u32 windows_available;
	u32 largest_available_block;
	u32 page_size;
	u32 migration_capable;
};

struct ddw_create_response {
	u32 liobn;
	u32 addr_hi;
	u32 addr_lo;
};

static LIST_HEAD(direct_window_list);
/*                                                              */
static DEFINE_SPINLOCK(direct_window_list_lock);
/*                                                    */
static DEFINE_MUTEX(direct_window_init_mutex);
#define DIRECT64_PROPNAME "linux,direct64-ddr-window-info"

static int tce_clearrange_multi_pSeriesLP(unsigned long start_pfn,
					unsigned long num_pfn, const void *arg)
{
	const struct dynamic_dma_window_prop *maprange = arg;
	int rc;
	u64 tce_size, num_tce, dma_offset, next;
	u32 tce_shift;
	long limit;

	tce_shift = be32_to_cpu(maprange->tce_shift);
	tce_size = 1ULL << tce_shift;
	next = start_pfn << PAGE_SHIFT;
	num_tce = num_pfn << PAGE_SHIFT;

	/*                                                  */
	num_tce += next & (tce_size - 1);
	next &= ~(tce_size - 1);

	/*                          */
	num_tce |= tce_size - 1;
	num_tce >>= tce_shift;

	do {
		/*
                                                               
                
   */
		limit = min_t(long, num_tce, 512);
		dma_offset = next + be64_to_cpu(maprange->dma_base);

		rc = plpar_tce_stuff((u64)be32_to_cpu(maprange->liobn),
					     dma_offset,
					     0, limit);
		num_tce -= limit;
	} while (num_tce > 0 && !rc);

	return rc;
}

static int tce_setrange_multi_pSeriesLP(unsigned long start_pfn,
					unsigned long num_pfn, const void *arg)
{
	const struct dynamic_dma_window_prop *maprange = arg;
	u64 *tcep, tce_size, num_tce, dma_offset, next, proto_tce, liobn;
	u32 tce_shift;
	u64 rc = 0;
	long l, limit;

	local_irq_disable();	/*                                        */
	tcep = __get_cpu_var(tce_page);

	if (!tcep) {
		tcep = (u64 *)__get_free_page(GFP_ATOMIC);
		if (!tcep) {
			local_irq_enable();
			return -ENOMEM;
		}
		__get_cpu_var(tce_page) = tcep;
	}

	proto_tce = TCE_PCI_READ | TCE_PCI_WRITE;

	liobn = (u64)be32_to_cpu(maprange->liobn);
	tce_shift = be32_to_cpu(maprange->tce_shift);
	tce_size = 1ULL << tce_shift;
	next = start_pfn << PAGE_SHIFT;
	num_tce = num_pfn << PAGE_SHIFT;

	/*                                                  */
	num_tce += next & (tce_size - 1);
	next &= ~(tce_size - 1);

	/*                          */
	num_tce |= tce_size - 1;
	num_tce >>= tce_shift;

	/*                                              */
	do {
		/*
                                                               
                
   */
		limit = min_t(long, num_tce, 4096/TCE_ENTRY_SIZE);
		dma_offset = next + be64_to_cpu(maprange->dma_base);

		for (l = 0; l < limit; l++) {
			tcep[l] = proto_tce | next;
			next += tce_size;
		}

		rc = plpar_tce_put_indirect(liobn,
					    dma_offset,
					    (u64)virt_to_abs(tcep),
					    limit);

		num_tce -= limit;
	} while (num_tce > 0 && !rc);

	/*                                              */

	local_irq_enable();
	return rc;
}

static int tce_setrange_multi_pSeriesLP_walk(unsigned long start_pfn,
		unsigned long num_pfn, void *arg)
{
	return tce_setrange_multi_pSeriesLP(start_pfn, num_pfn, arg);
}


#ifdef CONFIG_PCI
static void iommu_table_setparms(struct pci_controller *phb,
				 struct device_node *dn,
				 struct iommu_table *tbl)
{
	struct device_node *node;
	const unsigned long *basep, *sw_inval;
	const u32 *sizep;

	node = phb->dn;

	basep = of_get_property(node, "linux,tce-base", NULL);
	sizep = of_get_property(node, "linux,tce-size", NULL);
	if (basep == NULL || sizep == NULL) {
		printk(KERN_ERR "PCI_DMA: iommu_table_setparms: %s has "
				"missing tce entries !\n", dn->full_name);
		return;
	}

	tbl->it_base = (unsigned long)__va(*basep);

	if (!is_kdump_kernel())
		memset((void *)tbl->it_base, 0, *sizep);

	tbl->it_busno = phb->bus->number;

	/*                      */
	tbl->it_offset = phb->dma_window_base_cur >> IOMMU_PAGE_SHIFT;

	/*                                            */
	if (phb->dma_window_base_cur + phb->dma_window_size > 0x80000000ul) {
		udbg_printf("PCI_DMA: Unexpected number of IOAs under this PHB.\n");
		panic("PCI_DMA: Unexpected number of IOAs under this PHB.\n");
	}

	phb->dma_window_base_cur += phb->dma_window_size;

	/*                                              */
	tbl->it_size = phb->dma_window_size >> IOMMU_PAGE_SHIFT;

	tbl->it_index = 0;
	tbl->it_blocksize = 16;
	tbl->it_type = TCE_PCI;

	sw_inval = of_get_property(node, "linux,tce-sw-invalidate-info", NULL);
	if (sw_inval) {
		/*
                                                 
                                                     
                                                      
                                                       
                                                    
                                                     
             
   */
		tbl->it_index = (unsigned long) ioremap(sw_inval[0], 8);
		tbl->it_busno = sw_inval[1]; /*                          */
		tbl->it_type = TCE_PCI_SWINV_CREATE | TCE_PCI_SWINV_FREE;
	}
}

/*
                            
  
                                                                             
 */
static void iommu_table_setparms_lpar(struct pci_controller *phb,
				      struct device_node *dn,
				      struct iommu_table *tbl,
				      const void *dma_window)
{
	unsigned long offset, size;

	of_parse_dma_window(dn, dma_window, &tbl->it_index, &offset, &size);

	tbl->it_busno = phb->bus->number;
	tbl->it_base   = 0;
	tbl->it_blocksize  = 16;
	tbl->it_type = TCE_PCI;
	tbl->it_offset = offset >> IOMMU_PAGE_SHIFT;
	tbl->it_size = size >> IOMMU_PAGE_SHIFT;
}

static void pci_dma_bus_setup_pSeries(struct pci_bus *bus)
{
	struct device_node *dn;
	struct iommu_table *tbl;
	struct device_node *isa_dn, *isa_dn_orig;
	struct device_node *tmp;
	struct pci_dn *pci;
	int children;

	dn = pci_bus_to_OF_node(bus);

	pr_debug("pci_dma_bus_setup_pSeries: setting up bus %s\n", dn->full_name);

	if (bus->self) {
		/*                                                       
                                                            
   */
		return;
	}
	pci = PCI_DN(dn);

	/*                                            
             
  */
	isa_dn = isa_dn_orig = of_find_node_by_type(NULL, "isa");

	while (isa_dn && isa_dn != dn)
		isa_dn = isa_dn->parent;

	if (isa_dn_orig)
		of_node_put(isa_dn_orig);

	/*                                                 */
	for (children = 0, tmp = dn->child; tmp; tmp = tmp->sibling)
		children++;

	pr_debug("Children: %d\n", children);

	/*                                                             
                                                              
   
                                       
  */

	if (!isa_dn) {
		/*                                              */
		pci->phb->dma_window_size = 0x80000000ul; /*               */

		while (pci->phb->dma_window_size * children > 0x80000000ul)
			pci->phb->dma_window_size >>= 1;
		pr_debug("No ISA/IDE, window size is 0x%llx\n",
			 pci->phb->dma_window_size);
		pci->phb->dma_window_base_cur = 0;

		return;
	}

	/*                                             
                                              
                                                 
          
  */
	pci->phb->dma_window_size = 0x8000000ul;
	pci->phb->dma_window_base_cur = 0x8000000ul;

	tbl = kzalloc_node(sizeof(struct iommu_table), GFP_KERNEL,
			   pci->phb->node);

	iommu_table_setparms(pci->phb, dn, tbl);
	pci->iommu_table = iommu_init_table(tbl, pci->phb->node);

	/*                                             */
	pci->phb->dma_window_size = 0x80000000ul;
	while (pci->phb->dma_window_size * children > 0x70000000ul)
		pci->phb->dma_window_size >>= 1;

	pr_debug("ISA/IDE, window size is 0x%llx\n", pci->phb->dma_window_size);
}


static void pci_dma_bus_setup_pSeriesLP(struct pci_bus *bus)
{
	struct iommu_table *tbl;
	struct device_node *dn, *pdn;
	struct pci_dn *ppci;
	const void *dma_window = NULL;

	dn = pci_bus_to_OF_node(bus);

	pr_debug("pci_dma_bus_setup_pSeriesLP: setting up bus %s\n",
		 dn->full_name);

	/*                                                         */
	for (pdn = dn; pdn != NULL; pdn = pdn->parent) {
		dma_window = of_get_property(pdn, "ibm,dma-window", NULL);
		if (dma_window != NULL)
			break;
	}

	if (dma_window == NULL) {
		pr_debug("  no ibm,dma-window property !\n");
		return;
	}

	ppci = PCI_DN(pdn);

	pr_debug("  parent is %s, iommu_table: 0x%p\n",
		 pdn->full_name, ppci->iommu_table);

	if (!ppci->iommu_table) {
		tbl = kzalloc_node(sizeof(struct iommu_table), GFP_KERNEL,
				   ppci->phb->node);
		iommu_table_setparms_lpar(ppci->phb, pdn, tbl, dma_window);
		ppci->iommu_table = iommu_init_table(tbl, ppci->phb->node);
		pr_debug("  created table: %p\n", ppci->iommu_table);
	}
}


static void pci_dma_dev_setup_pSeries(struct pci_dev *dev)
{
	struct device_node *dn;
	struct iommu_table *tbl;

	pr_debug("pci_dma_dev_setup_pSeries: %s\n", pci_name(dev));

	dn = dev->dev.of_node;

	/*                                                                  
                                                                  
                             
  */
	if (!dev->bus->self) {
		struct pci_controller *phb = PCI_DN(dn)->phb;

		pr_debug(" --> first child, no bridge. Allocating iommu table.\n");
		tbl = kzalloc_node(sizeof(struct iommu_table), GFP_KERNEL,
				   phb->node);
		iommu_table_setparms(phb, dn, tbl);
		PCI_DN(dn)->iommu_table = iommu_init_table(tbl, phb->node);
		set_iommu_table_base(&dev->dev, PCI_DN(dn)->iommu_table);
		return;
	}

	/*                                                                  
                                                           
  */

	while (dn && PCI_DN(dn) && PCI_DN(dn)->iommu_table == NULL)
		dn = dn->parent;

	if (dn && PCI_DN(dn))
		set_iommu_table_base(&dev->dev, PCI_DN(dn)->iommu_table);
	else
		printk(KERN_WARNING "iommu: Device %s has no iommu table\n",
		       pci_name(dev));
}

static int __read_mostly disable_ddw;

static int __init disable_ddw_setup(char *str)
{
	disable_ddw = 1;
	printk(KERN_INFO "ppc iommu: disabling ddw.\n");

	return 0;
}

early_param("disable_ddw", disable_ddw_setup);

static void remove_ddw(struct device_node *np)
{
	struct dynamic_dma_window_prop *dwp;
	struct property *win64;
	const u32 *ddw_avail;
	u64 liobn;
	int len, ret;

	ddw_avail = of_get_property(np, "ibm,ddw-applicable", &len);
	win64 = of_find_property(np, DIRECT64_PROPNAME, NULL);
	if (!win64)
		return;

	if (!ddw_avail || len < 3 * sizeof(u32) || win64->length < sizeof(*dwp))
		goto delprop;

	dwp = win64->value;
	liobn = (u64)be32_to_cpu(dwp->liobn);

	/*                                                         */
	ret = tce_clearrange_multi_pSeriesLP(0,
		1ULL << (be32_to_cpu(dwp->window_shift) - PAGE_SHIFT), dwp);
	if (ret)
		pr_warning("%s failed to clear tces in window.\n",
			 np->full_name);
	else
		pr_debug("%s successfully cleared tces in window.\n",
			 np->full_name);

	ret = rtas_call(ddw_avail[2], 1, 1, NULL, liobn);
	if (ret)
		pr_warning("%s: failed to remove direct window: rtas returned "
			"%d to ibm,remove-pe-dma-window(%x) %llx\n",
			np->full_name, ret, ddw_avail[2], liobn);
	else
		pr_debug("%s: successfully removed direct window: rtas returned "
			"%d to ibm,remove-pe-dma-window(%x) %llx\n",
			np->full_name, ret, ddw_avail[2], liobn);

delprop:
	ret = prom_remove_property(np, win64);
	if (ret)
		pr_warning("%s: failed to remove direct window property: %d\n",
			np->full_name, ret);
}

static u64 find_existing_ddw(struct device_node *pdn)
{
	struct direct_window *window;
	const struct dynamic_dma_window_prop *direct64;
	u64 dma_addr = 0;

	spin_lock(&direct_window_list_lock);
	/*                                                                 */
	list_for_each_entry(window, &direct_window_list, list) {
		if (window->device == pdn) {
			direct64 = window->prop;
			dma_addr = direct64->dma_base;
			break;
		}
	}
	spin_unlock(&direct_window_list_lock);

	return dma_addr;
}

static int find_existing_ddw_windows(void)
{
	int len;
	struct device_node *pdn;
	struct direct_window *window;
	const struct dynamic_dma_window_prop *direct64;

	if (!firmware_has_feature(FW_FEATURE_LPAR))
		return 0;

	for_each_node_with_property(pdn, DIRECT64_PROPNAME) {
		direct64 = of_get_property(pdn, DIRECT64_PROPNAME, &len);
		if (!direct64)
			continue;

		window = kzalloc(sizeof(*window), GFP_KERNEL);
		if (!window || len < sizeof(struct dynamic_dma_window_prop)) {
			kfree(window);
			remove_ddw(pdn);
			continue;
		}

		window->device = pdn;
		window->prop = direct64;
		spin_lock(&direct_window_list_lock);
		list_add(&window->list, &direct_window_list);
		spin_unlock(&direct_window_list_lock);
	}

	return 0;
}
machine_arch_initcall(pseries, find_existing_ddw_windows);

static int query_ddw(struct pci_dev *dev, const u32 *ddw_avail,
			struct ddw_query_response *query)
{
	struct eeh_dev *edev;
	u32 cfg_addr;
	u64 buid;
	int ret;

	/*
                                                         
                                        
                                                            
                       
  */
	edev = pci_dev_to_eeh_dev(dev);
	cfg_addr = edev->config_addr;
	if (edev->pe_config_addr)
		cfg_addr = edev->pe_config_addr;
	buid = edev->phb->buid;

	ret = rtas_call(ddw_avail[0], 3, 5, (u32 *)query,
		  cfg_addr, BUID_HI(buid), BUID_LO(buid));
	dev_info(&dev->dev, "ibm,query-pe-dma-windows(%x) %x %x %x"
		" returned %d\n", ddw_avail[0], cfg_addr, BUID_HI(buid),
		BUID_LO(buid), ret);
	return ret;
}

static int create_ddw(struct pci_dev *dev, const u32 *ddw_avail,
			struct ddw_create_response *create, int page_shift,
			int window_shift)
{
	struct eeh_dev *edev;
	u32 cfg_addr;
	u64 buid;
	int ret;

	/*
                                                         
                                        
                                                            
                       
  */
	edev = pci_dev_to_eeh_dev(dev);
	cfg_addr = edev->config_addr;
	if (edev->pe_config_addr)
		cfg_addr = edev->pe_config_addr;
	buid = edev->phb->buid;

	do {
		/*                                               */
		ret = rtas_call(ddw_avail[1], 5, 4, (u32 *)create, cfg_addr,
				BUID_HI(buid), BUID_LO(buid), page_shift, window_shift);
	} while (rtas_busy_delay(ret));
	dev_info(&dev->dev,
		"ibm,create-pe-dma-window(%x) %x %x %x %x %x returned %d "
		"(liobn = 0x%x starting addr = %x %x)\n", ddw_avail[1],
		 cfg_addr, BUID_HI(buid), BUID_LO(buid), page_shift,
		 window_shift, ret, create->liobn, create->addr_hi, create->addr_lo);

	return ret;
}

/*
                                                                         
                                                                      
                                                  
  
                                      
                                                           
                                                                            
  
                                                 
 */
static u64 enable_ddw(struct pci_dev *dev, struct device_node *pdn)
{
	int len, ret;
	struct ddw_query_response query;
	struct ddw_create_response create;
	int page_shift;
	u64 dma_addr, max_addr;
	struct device_node *dn;
	const u32 *uninitialized_var(ddw_avail);
	struct direct_window *window;
	struct property *win64;
	struct dynamic_dma_window_prop *ddwprop;

	mutex_lock(&direct_window_init_mutex);

	dma_addr = find_existing_ddw(pdn);
	if (dma_addr != 0)
		goto out_unlock;

	/*
                                                         
                           
                            
                            
                                     
                                                      
  */
	ddw_avail = of_get_property(pdn, "ibm,ddw-applicable", &len);
	if (!ddw_avail || len < 3 * sizeof(u32))
		goto out_unlock;

       /*
                                                        
                                                              
                                                               
                                                           
  */
	dn = pci_device_to_OF_node(dev);
	ret = query_ddw(dev, ddw_avail, &query);
	if (ret != 0)
		goto out_unlock;

	if (query.windows_available == 0) {
		/*
                                                         
                                                        
                                       
   */
		dev_dbg(&dev->dev, "no free dynamic windows");
		goto out_unlock;
	}
	if (query.page_size & 4) {
		page_shift = 24; /*      */
	} else if (query.page_size & 2) {
		page_shift = 16; /*      */
	} else if (query.page_size & 1) {
		page_shift = 12; /*     */
	} else {
		dev_dbg(&dev->dev, "no supported direct page size in mask %x",
			  query.page_size);
		goto out_unlock;
	}
	/*                                                           */
	/*                                                           */
	max_addr = memory_hotplug_max();
	if (query.largest_available_block < (max_addr >> page_shift)) {
		dev_dbg(&dev->dev, "can't map partiton max 0x%llx with %u "
			  "%llu-sized pages\n", max_addr,  query.largest_available_block,
			  1ULL << page_shift);
		goto out_unlock;
	}
	len = order_base_2(max_addr);
	win64 = kzalloc(sizeof(struct property), GFP_KERNEL);
	if (!win64) {
		dev_info(&dev->dev,
			"couldn't allocate property for 64bit dma window\n");
		goto out_unlock;
	}
	win64->name = kstrdup(DIRECT64_PROPNAME, GFP_KERNEL);
	win64->value = ddwprop = kmalloc(sizeof(*ddwprop), GFP_KERNEL);
	win64->length = sizeof(*ddwprop);
	if (!win64->name || !win64->value) {
		dev_info(&dev->dev,
			"couldn't allocate property name and value\n");
		goto out_free_prop;
	}

	ret = create_ddw(dev, ddw_avail, &create, page_shift, len);
	if (ret != 0)
		goto out_free_prop;

	ddwprop->liobn = cpu_to_be32(create.liobn);
	ddwprop->dma_base = cpu_to_be64(of_read_number(&create.addr_hi, 2));
	ddwprop->tce_shift = cpu_to_be32(page_shift);
	ddwprop->window_shift = cpu_to_be32(len);

	dev_dbg(&dev->dev, "created tce table LIOBN 0x%x for %s\n",
		  create.liobn, dn->full_name);

	window = kzalloc(sizeof(*window), GFP_KERNEL);
	if (!window)
		goto out_clear_window;

	ret = walk_system_ram_range(0, memblock_end_of_DRAM() >> PAGE_SHIFT,
			win64->value, tce_setrange_multi_pSeriesLP_walk);
	if (ret) {
		dev_info(&dev->dev, "failed to map direct window for %s: %d\n",
			 dn->full_name, ret);
		goto out_free_window;
	}

	ret = prom_add_property(pdn, win64);
	if (ret) {
		dev_err(&dev->dev, "unable to add dma window property for %s: %d",
			 pdn->full_name, ret);
		goto out_free_window;
	}

	window->device = pdn;
	window->prop = ddwprop;
	spin_lock(&direct_window_list_lock);
	list_add(&window->list, &direct_window_list);
	spin_unlock(&direct_window_list_lock);

	dma_addr = of_read_number(&create.addr_hi, 2);
	goto out_unlock;

out_free_window:
	kfree(window);

out_clear_window:
	remove_ddw(pdn);

out_free_prop:
	kfree(win64->name);
	kfree(win64->value);
	kfree(win64);

out_unlock:
	mutex_unlock(&direct_window_init_mutex);
	return dma_addr;
}

static void pci_dma_dev_setup_pSeriesLP(struct pci_dev *dev)
{
	struct device_node *pdn, *dn;
	struct iommu_table *tbl;
	const void *dma_window = NULL;
	struct pci_dn *pci;

	pr_debug("pci_dma_dev_setup_pSeriesLP: %s\n", pci_name(dev));

	/*                                                                   
                                                                    
                                                                  
                                                                   
                      
  */
	dn = pci_device_to_OF_node(dev);
	pr_debug("  node is %s\n", dn->full_name);

	for (pdn = dn; pdn && PCI_DN(pdn) && !PCI_DN(pdn)->iommu_table;
	     pdn = pdn->parent) {
		dma_window = of_get_property(pdn, "ibm,dma-window", NULL);
		if (dma_window)
			break;
	}

	if (!pdn || !PCI_DN(pdn)) {
		printk(KERN_WARNING "pci_dma_dev_setup_pSeriesLP: "
		       "no DMA window found for pci dev=%s dn=%s\n",
				 pci_name(dev), dn? dn->full_name : "<null>");
		return;
	}
	pr_debug("  parent is %s\n", pdn->full_name);

	pci = PCI_DN(pdn);
	if (!pci->iommu_table) {
		tbl = kzalloc_node(sizeof(struct iommu_table), GFP_KERNEL,
				   pci->phb->node);
		iommu_table_setparms_lpar(pci->phb, pdn, tbl, dma_window);
		pci->iommu_table = iommu_init_table(tbl, pci->phb->node);
		pr_debug("  created table: %p\n", pci->iommu_table);
	} else {
		pr_debug("  found DMA window, table: %p\n", pci->iommu_table);
	}

	set_iommu_table_base(&dev->dev, pci->iommu_table);
}

static int dma_set_mask_pSeriesLP(struct device *dev, u64 dma_mask)
{
	bool ddw_enabled = false;
	struct device_node *pdn, *dn;
	struct pci_dev *pdev;
	const void *dma_window = NULL;
	u64 dma_offset;

	if (!dev->dma_mask)
		return -EIO;

	if (!dev_is_pci(dev))
		goto check_mask;

	pdev = to_pci_dev(dev);

	/*                                                             */
	if (!disable_ddw && dma_mask == DMA_BIT_MASK(64)) {
		dn = pci_device_to_OF_node(pdev);
		dev_dbg(dev, "node is %s\n", dn->full_name);

		/*
                                                            
                                                              
                                                                
                                                               
   */
		for (pdn = dn; pdn && PCI_DN(pdn) && !PCI_DN(pdn)->iommu_table;
				pdn = pdn->parent) {
			dma_window = of_get_property(pdn, "ibm,dma-window", NULL);
			if (dma_window)
				break;
		}
		if (pdn && PCI_DN(pdn)) {
			dma_offset = enable_ddw(pdev, pdn);
			if (dma_offset != 0) {
				dev_info(dev, "Using 64-bit direct DMA at offset %llx\n", dma_offset);
				set_dma_offset(dev, dma_offset);
				set_dma_ops(dev, &dma_direct_ops);
				ddw_enabled = true;
			}
		}
	}

	/*                                                        */
	if (!ddw_enabled && get_dma_ops(dev) != &dma_iommu_ops) {
		dev_info(dev, "Restoring 32-bit DMA via iommu\n");
		set_dma_ops(dev, &dma_iommu_ops);
		pci_dma_dev_setup_pSeriesLP(pdev);
	}

check_mask:
	if (!dma_supported(dev, dma_mask))
		return -EIO;

	*dev->dma_mask = dma_mask;
	return 0;
}

static u64 dma_get_required_mask_pSeriesLP(struct device *dev)
{
	if (!dev->dma_mask)
		return 0;

	if (!disable_ddw && dev_is_pci(dev)) {
		struct pci_dev *pdev = to_pci_dev(dev);
		struct device_node *dn;

		dn = pci_device_to_OF_node(pdev);

		/*                                   */
		for (; dn && PCI_DN(dn) && !PCI_DN(dn)->iommu_table;
				dn = dn->parent)
			if (of_get_property(dn, "ibm,dma-window", NULL))
				break;
		/*                                                           */
		if (dn && PCI_DN(dn) &&
				of_get_property(dn, "ibm,ddw-applicable", NULL))
			return DMA_BIT_MASK(64);
	}

	return dma_iommu_ops.get_required_mask(dev);
}

#else  /*            */
#define pci_dma_bus_setup_pSeries	NULL
#define pci_dma_dev_setup_pSeries	NULL
#define pci_dma_bus_setup_pSeriesLP	NULL
#define pci_dma_dev_setup_pSeriesLP	NULL
#define dma_set_mask_pSeriesLP		NULL
#define dma_get_required_mask_pSeriesLP	NULL
#endif /*             */

static int iommu_mem_notifier(struct notifier_block *nb, unsigned long action,
		void *data)
{
	struct direct_window *window;
	struct memory_notify *arg = data;
	int ret = 0;

	switch (action) {
	case MEM_GOING_ONLINE:
		spin_lock(&direct_window_list_lock);
		list_for_each_entry(window, &direct_window_list, list) {
			ret |= tce_setrange_multi_pSeriesLP(arg->start_pfn,
					arg->nr_pages, window->prop);
			/*               */
		}
		spin_unlock(&direct_window_list_lock);
		break;
	case MEM_CANCEL_ONLINE:
	case MEM_OFFLINE:
		spin_lock(&direct_window_list_lock);
		list_for_each_entry(window, &direct_window_list, list) {
			ret |= tce_clearrange_multi_pSeriesLP(arg->start_pfn,
					arg->nr_pages, window->prop);
			/*               */
		}
		spin_unlock(&direct_window_list_lock);
		break;
	default:
		break;
	}
	if (ret && action != MEM_CANCEL_ONLINE)
		return NOTIFY_BAD;

	return NOTIFY_OK;
}

static struct notifier_block iommu_mem_nb = {
	.notifier_call = iommu_mem_notifier,
};

static int iommu_reconfig_notifier(struct notifier_block *nb, unsigned long action, void *node)
{
	int err = NOTIFY_OK;
	struct device_node *np = node;
	struct pci_dn *pci = PCI_DN(np);
	struct direct_window *window;

	switch (action) {
	case PSERIES_RECONFIG_REMOVE:
		if (pci && pci->iommu_table)
			iommu_free_table(pci->iommu_table, np->full_name);

		spin_lock(&direct_window_list_lock);
		list_for_each_entry(window, &direct_window_list, list) {
			if (window->device == np) {
				list_del(&window->list);
				kfree(window);
				break;
			}
		}
		spin_unlock(&direct_window_list_lock);

		/*
                                                     
                                                       
                                                        
                                                        
                                                         
                                                 
                                   
   */
		break;
	default:
		err = NOTIFY_DONE;
		break;
	}
	return err;
}

static struct notifier_block iommu_reconfig_nb = {
	.notifier_call = iommu_reconfig_notifier,
};

/*                              */
void iommu_init_early_pSeries(void)
{
	if (of_chosen && of_get_property(of_chosen, "linux,iommu-off", NULL))
		return;

	if (firmware_has_feature(FW_FEATURE_LPAR)) {
		if (firmware_has_feature(FW_FEATURE_MULTITCE)) {
			ppc_md.tce_build = tce_buildmulti_pSeriesLP;
			ppc_md.tce_free	 = tce_freemulti_pSeriesLP;
		} else {
			ppc_md.tce_build = tce_build_pSeriesLP;
			ppc_md.tce_free	 = tce_free_pSeriesLP;
		}
		ppc_md.tce_get   = tce_get_pSeriesLP;
		ppc_md.pci_dma_bus_setup = pci_dma_bus_setup_pSeriesLP;
		ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_pSeriesLP;
		ppc_md.dma_set_mask = dma_set_mask_pSeriesLP;
		ppc_md.dma_get_required_mask = dma_get_required_mask_pSeriesLP;
	} else {
		ppc_md.tce_build = tce_build_pSeries;
		ppc_md.tce_free  = tce_free_pSeries;
		ppc_md.tce_get   = tce_get_pseries;
		ppc_md.pci_dma_bus_setup = pci_dma_bus_setup_pSeries;
		ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_pSeries;
	}


	pSeries_reconfig_notifier_register(&iommu_reconfig_nb);
	register_memory_notifier(&iommu_mem_nb);

	set_pci_dma_ops(&dma_iommu_ops);
}

static int __init disable_multitce(char *str)
{
	if (strcmp(str, "off") == 0 &&
	    firmware_has_feature(FW_FEATURE_LPAR) &&
	    firmware_has_feature(FW_FEATURE_MULTITCE)) {
		printk(KERN_INFO "Disabling MULTITCE firmware feature\n");
		ppc_md.tce_build = tce_build_pSeriesLP;
		ppc_md.tce_free	 = tce_free_pSeriesLP;
		powerpc_firmware_features &= ~FW_FEATURE_MULTITCE;
	}
	return 1;
}

__setup("multitce=", disable_multitce);