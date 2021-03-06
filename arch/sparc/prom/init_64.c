/*
 * init.c:  Initialize internal variables used by the PROM
 *          library functions.
 *
 * Copyright (C) 1995 David S. Miller (davem@caip.rutgers.edu)
 * Copyright (C) 1996,1997 Jakub Jelinek (jj@sunsite.mff.cuni.cz)
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/ctype.h>

#include <asm/openprom.h>
#include <asm/oplib.h>

/*                     */
char prom_version[80];

/*                                        */
int prom_stdout;
phandle prom_chosen_node;

/*                                                               
                                                               
                                                           
 */

extern void prom_cif_init(void *, void *);

void __init prom_init(void *cif_handler, void *cif_stack)
{
	phandle node;

	prom_cif_init(cif_handler, cif_stack);

	prom_chosen_node = prom_finddevice(prom_chosen_path);
	if (!prom_chosen_node || (s32)prom_chosen_node == -1)
		prom_halt();

	prom_stdout = prom_getint(prom_chosen_node, "stdout");

	node = prom_finddevice("/openprom");
	if (!node || (s32)node == -1)
		prom_halt();

	prom_getstring(node, "version", prom_version, sizeof(prom_version));

	prom_printf("\n");
}

void __init prom_init_report(void)
{
	printk("PROMLIB: Sun IEEE Boot Prom '%s'\n", prom_version);
	printk("PROMLIB: Root node compatible: %s\n", prom_root_compatible);
}
