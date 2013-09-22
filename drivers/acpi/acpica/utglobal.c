/*                                                                             
  
                                                                  
  
                                                                             */

/*
 * Copyright (C) 2000 - 2012, Intel Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 * 3. Neither the names of the above-listed copyright holders nor the names
 *    of any contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 */

#define DEFINE_ACPI_GLOBALS

#include <linux/export.h>
#include <acpi/acpi.h>
#include "accommon.h"

#define _COMPONENT          ACPI_UTILITIES
ACPI_MODULE_NAME("utglobal")

/*                                                                              
  
                                         
  
                                                                              */
/*
                                                            
                                                
 */
/*                                     */
u32 acpi_dbg_level = ACPI_DEBUG_DEFAULT;

/*                                       */

u32 acpi_dbg_layer = 0;
u32 acpi_gbl_nesting_level = 0;

/*                  */

u8 acpi_gbl_db_terminate_threads = FALSE;
u8 acpi_gbl_abort_method = FALSE;
u8 acpi_gbl_method_executing = FALSE;

/*              */

u32 acpi_gbl_startup_flags = 0;

/*                             */

u8 acpi_gbl_shutdown = TRUE;

const char *acpi_gbl_sleep_state_names[ACPI_S_STATE_COUNT] = {
	"\\_S0_",
	"\\_S1_",
	"\\_S2_",
	"\\_S3_",
	"\\_S4_",
	"\\_S5_"
};

const char *acpi_gbl_lowest_dstate_names[ACPI_NUM_sx_w_METHODS] = {
	"_S0W",
	"_S1W",
	"_S2W",
	"_S3W",
	"_S4W"
};

const char *acpi_gbl_highest_dstate_names[ACPI_NUM_sx_d_METHODS] = {
	"_S1D",
	"_S2D",
	"_S3D",
	"_S4D"
};

/*                                                                              
  
                    
  
                                                                              */
/*
                                                      
  
         
                                                                  
                                         
                                                                        
                                                                          
                                                                     
                                              
 */
const struct acpi_predefined_names acpi_gbl_pre_defined_names[] = {
	{"_GPE", ACPI_TYPE_LOCAL_SCOPE, NULL},
	{"_PR_", ACPI_TYPE_LOCAL_SCOPE, NULL},
	{"_SB_", ACPI_TYPE_DEVICE, NULL},
	{"_SI_", ACPI_TYPE_LOCAL_SCOPE, NULL},
	{"_TZ_", ACPI_TYPE_DEVICE, NULL},
	{"_REV", ACPI_TYPE_INTEGER, (char *)ACPI_CA_SUPPORT_LEVEL},
	{"_OS_", ACPI_TYPE_STRING, ACPI_OS_NAME},
	{"_GL_", ACPI_TYPE_MUTEX, (char *)1},

#if !defined (ACPI_NO_METHOD_EXECUTION) || defined (ACPI_CONSTANT_EVAL_ONLY)
	{"_OSI", ACPI_TYPE_METHOD, (char *)1},
#endif

	/*                  */

	{NULL, ACPI_TYPE_ANY, NULL}
};

#if (!ACPI_REDUCED_HARDWARE)
/*                                                                             
  
                             
  
                                                                              */

struct acpi_bit_register_info acpi_gbl_bit_register_info[ACPI_NUM_BITREG] = {
	/*                                                                                                                                      */

	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_TIMER_STATUS,
						ACPI_BITMASK_TIMER_STATUS},
	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_BUS_MASTER_STATUS,
						ACPI_BITMASK_BUS_MASTER_STATUS},
	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_GLOBAL_LOCK_STATUS,
						ACPI_BITMASK_GLOBAL_LOCK_STATUS},
	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_POWER_BUTTON_STATUS,
						ACPI_BITMASK_POWER_BUTTON_STATUS},
	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_SLEEP_BUTTON_STATUS,
						ACPI_BITMASK_SLEEP_BUTTON_STATUS},
	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_RT_CLOCK_STATUS,
						ACPI_BITMASK_RT_CLOCK_STATUS},
	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_WAKE_STATUS,
						ACPI_BITMASK_WAKE_STATUS},
	/*                                  */ {ACPI_REGISTER_PM1_STATUS,
						ACPI_BITPOSITION_PCIEXP_WAKE_STATUS,
						ACPI_BITMASK_PCIEXP_WAKE_STATUS},

	/*                                  */ {ACPI_REGISTER_PM1_ENABLE,
						ACPI_BITPOSITION_TIMER_ENABLE,
						ACPI_BITMASK_TIMER_ENABLE},
	/*                                  */ {ACPI_REGISTER_PM1_ENABLE,
						ACPI_BITPOSITION_GLOBAL_LOCK_ENABLE,
						ACPI_BITMASK_GLOBAL_LOCK_ENABLE},
	/*                                  */ {ACPI_REGISTER_PM1_ENABLE,
						ACPI_BITPOSITION_POWER_BUTTON_ENABLE,
						ACPI_BITMASK_POWER_BUTTON_ENABLE},
	/*                                  */ {ACPI_REGISTER_PM1_ENABLE,
						ACPI_BITPOSITION_SLEEP_BUTTON_ENABLE,
						ACPI_BITMASK_SLEEP_BUTTON_ENABLE},
	/*                                  */ {ACPI_REGISTER_PM1_ENABLE,
						ACPI_BITPOSITION_RT_CLOCK_ENABLE,
						ACPI_BITMASK_RT_CLOCK_ENABLE},
	/*                                  */ {ACPI_REGISTER_PM1_ENABLE,
						ACPI_BITPOSITION_PCIEXP_WAKE_DISABLE,
						ACPI_BITMASK_PCIEXP_WAKE_DISABLE},

	/*                                  */ {ACPI_REGISTER_PM1_CONTROL,
						ACPI_BITPOSITION_SCI_ENABLE,
						ACPI_BITMASK_SCI_ENABLE},
	/*                                  */ {ACPI_REGISTER_PM1_CONTROL,
						ACPI_BITPOSITION_BUS_MASTER_RLD,
						ACPI_BITMASK_BUS_MASTER_RLD},
	/*                                  */ {ACPI_REGISTER_PM1_CONTROL,
						ACPI_BITPOSITION_GLOBAL_LOCK_RELEASE,
						ACPI_BITMASK_GLOBAL_LOCK_RELEASE},
	/*                                  */ {ACPI_REGISTER_PM1_CONTROL,
						ACPI_BITPOSITION_SLEEP_TYPE,
						ACPI_BITMASK_SLEEP_TYPE},
	/*                                  */ {ACPI_REGISTER_PM1_CONTROL,
						ACPI_BITPOSITION_SLEEP_ENABLE,
						ACPI_BITMASK_SLEEP_ENABLE},

	/*                                  */ {ACPI_REGISTER_PM2_CONTROL,
						ACPI_BITPOSITION_ARB_DISABLE,
						ACPI_BITMASK_ARB_DISABLE}
};

struct acpi_fixed_event_info acpi_gbl_fixed_event_info[ACPI_NUM_FIXED_EVENTS] = {
	/*                          */ {ACPI_BITREG_TIMER_STATUS,
					ACPI_BITREG_TIMER_ENABLE,
					ACPI_BITMASK_TIMER_STATUS,
					ACPI_BITMASK_TIMER_ENABLE},
	/*                          */ {ACPI_BITREG_GLOBAL_LOCK_STATUS,
					ACPI_BITREG_GLOBAL_LOCK_ENABLE,
					ACPI_BITMASK_GLOBAL_LOCK_STATUS,
					ACPI_BITMASK_GLOBAL_LOCK_ENABLE},
	/*                          */ {ACPI_BITREG_POWER_BUTTON_STATUS,
					ACPI_BITREG_POWER_BUTTON_ENABLE,
					ACPI_BITMASK_POWER_BUTTON_STATUS,
					ACPI_BITMASK_POWER_BUTTON_ENABLE},
	/*                          */ {ACPI_BITREG_SLEEP_BUTTON_STATUS,
					ACPI_BITREG_SLEEP_BUTTON_ENABLE,
					ACPI_BITMASK_SLEEP_BUTTON_STATUS,
					ACPI_BITMASK_SLEEP_BUTTON_ENABLE},
	/*                          */ {ACPI_BITREG_RT_CLOCK_STATUS,
					ACPI_BITREG_RT_CLOCK_ENABLE,
					ACPI_BITMASK_RT_CLOCK_STATUS,
					ACPI_BITMASK_RT_CLOCK_ENABLE},
};
#endif				/*                        */

/*                                                                              
  
                                    
  
                    
  
                      
  
                                                                        
                                                          
  
                                                                              */

acpi_status acpi_ut_init_globals(void)
{
	acpi_status status;
	u32 i;

	ACPI_FUNCTION_TRACE(ut_init_globals);

	/*                          */

	status = acpi_ut_create_caches();
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/*                     */

	for (i = 0; i < ACPI_ADDRESS_RANGE_MAX; i++) {
		acpi_gbl_address_range_list[i] = NULL;
	}

	/*                    */

	for (i = 0; i < ACPI_NUM_MUTEX; i++) {
		acpi_gbl_mutex_info[i].mutex = NULL;
		acpi_gbl_mutex_info[i].thread_id = ACPI_MUTEX_NOT_ACQUIRED;
		acpi_gbl_mutex_info[i].use_count = 0;
	}

	for (i = 0; i < ACPI_NUM_OWNERID_MASKS; i++) {
		acpi_gbl_owner_id_mask[i] = 0;
	}

	/*                              */

	acpi_gbl_owner_id_mask[ACPI_NUM_OWNERID_MASKS - 1] = 0x80000000;

#if (!ACPI_REDUCED_HARDWARE)

	/*             */

	acpi_gbl_gpe_xrupt_list_head = NULL;
	acpi_gbl_gpe_fadt_blocks[0] = NULL;
	acpi_gbl_gpe_fadt_blocks[1] = NULL;
	acpi_current_gpe_count = 0;
	acpi_gbl_all_gpes_initialized = FALSE;

	acpi_gbl_global_event_handler = NULL;

#endif				/*                        */

	/*                 */

	acpi_gbl_system_notify.handler = NULL;
	acpi_gbl_device_notify.handler = NULL;
	acpi_gbl_exception_handler = NULL;
	acpi_gbl_init_handler = NULL;
	acpi_gbl_table_handler = NULL;
	acpi_gbl_interface_handler = NULL;

	/*                     */

	acpi_gbl_global_lock_semaphore = NULL;
	acpi_gbl_global_lock_mutex = NULL;
	acpi_gbl_global_lock_acquired = FALSE;
	acpi_gbl_global_lock_handle = 0;
	acpi_gbl_global_lock_present = FALSE;

	/*                         */

	acpi_gbl_DSDT = NULL;
	acpi_gbl_cm_single_step = FALSE;
	acpi_gbl_db_terminate_threads = FALSE;
	acpi_gbl_shutdown = FALSE;
	acpi_gbl_ns_lookup_count = 0;
	acpi_gbl_ps_find_count = 0;
	acpi_gbl_acpi_hardware_present = TRUE;
	acpi_gbl_last_owner_id_index = 0;
	acpi_gbl_next_owner_id_offset = 0;
	acpi_gbl_trace_method_name = 0;
	acpi_gbl_trace_dbg_level = 0;
	acpi_gbl_trace_dbg_layer = 0;
	acpi_gbl_debugger_configuration = DEBUGGER_THREADING;
	acpi_gbl_db_output_flags = ACPI_DB_CONSOLE_OUTPUT;
	acpi_gbl_osi_data = 0;
	acpi_gbl_osi_mutex = NULL;
	acpi_gbl_reg_methods_executed = FALSE;

	/*                   */

	acpi_gbl_events_initialized = FALSE;
	acpi_gbl_system_awake_and_running = TRUE;

	/*           */

	acpi_gbl_module_code_list = NULL;
	acpi_gbl_root_node = NULL;
	acpi_gbl_root_node_struct.name.integer = ACPI_ROOT_NAME;
	acpi_gbl_root_node_struct.descriptor_type = ACPI_DESC_TYPE_NAMED;
	acpi_gbl_root_node_struct.type = ACPI_TYPE_DEVICE;
	acpi_gbl_root_node_struct.parent = NULL;
	acpi_gbl_root_node_struct.child = NULL;
	acpi_gbl_root_node_struct.peer = NULL;
	acpi_gbl_root_node_struct.object = NULL;

#ifdef ACPI_DEBUG_OUTPUT
	acpi_gbl_lowest_stack_pointer = ACPI_CAST_PTR(acpi_size, ACPI_SIZE_MAX);
#endif

#ifdef ACPI_DBG_TRACK_ALLOCATIONS
	acpi_gbl_display_final_mem_stats = FALSE;
#endif

	return_ACPI_STATUS(AE_OK);
}

ACPI_EXPORT_SYMBOL(acpi_gbl_FADT)
ACPI_EXPORT_SYMBOL(acpi_dbg_level)
ACPI_EXPORT_SYMBOL(acpi_dbg_layer)
ACPI_EXPORT_SYMBOL(acpi_current_gpe_count)