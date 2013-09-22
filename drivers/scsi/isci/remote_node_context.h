/*
 * This file is provided under a dual BSD/GPLv2 license.  When using or
 * redistributing this file, you may do so under either license.
 *
 * GPL LICENSE SUMMARY
 *
 * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * The full GNU General Public License is included in this distribution
 * in the file called LICENSE.GPL.
 *
 * BSD LICENSE
 *
 * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SCIC_SDS_REMOTE_NODE_CONTEXT_H_
#define _SCIC_SDS_REMOTE_NODE_CONTEXT_H_

/* 
                                                                               
                                                                            
                                             
  
  
 */

#include "isci.h"

/* 
  
  
                                                                              
                                                                             
                    
 */
#define SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX    0x0FFF

#define SCU_HARDWARE_SUSPENSION  (0)
#define SCI_SOFTWARE_SUSPENSION  (1)

struct isci_request;
struct isci_remote_device;
struct sci_remote_node_context;

typedef void (*scics_sds_remote_node_context_callback)(void *);

/* 
                                      
                                                                         
                                                                        
  
                                                                              
                                                                
  
                                                                              
                                                                              
                                   
  
                                                                          
                                                                           
                                                          
  
                                                                             
                      
  
                                                                                
                                                       
  
                                                                              
                                                               
  
                                                                               
                                                                            
                                                                               
                                                                           
 */
#define RNC_STATES {\
	C(RNC_INITIAL),\
	C(RNC_POSTING),\
	C(RNC_INVALIDATING),\
	C(RNC_RESUMING),\
	C(RNC_READY),\
	C(RNC_TX_SUSPENDED),\
	C(RNC_TX_RX_SUSPENDED),\
	C(RNC_AWAIT_SUSPENSION),\
	}
#undef C
#define C(a) SCI_##a
enum scis_sds_remote_node_context_states RNC_STATES;
#undef C
const char *rnc_state_name(enum scis_sds_remote_node_context_states state);

/* 
  
  
                                                                              
                
 */
enum sci_remote_node_context_destination_state {
	SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_UNSPECIFIED,
	SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_READY,
	SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_FINAL
};

/* 
                                                                    
                                                                              
                                                                               
                      
 */
struct sci_remote_node_context {
	/* 
                                                                    
             
  */
	u16 remote_node_index;

	/* 
                                                                               
                       
  */
	u32 suspension_code;

	/* 
                                                                              
                                                                        
                 
  */
	enum sci_remote_node_context_destination_state destination_state;

	/* 
                                                                           
                                                           
  */
	scics_sds_remote_node_context_callback user_callback;

	/* 
                                                                            
                                  
  */
	void *user_cookie;

	/* 
                                                                
  */
	struct sci_base_state_machine sm;
};

void sci_remote_node_context_construct(struct sci_remote_node_context *rnc,
					    u16 remote_node_index);


bool sci_remote_node_context_is_ready(
	struct sci_remote_node_context *sci_rnc);

enum sci_status sci_remote_node_context_event_handler(struct sci_remote_node_context *sci_rnc,
							   u32 event_code);
enum sci_status sci_remote_node_context_destruct(struct sci_remote_node_context *sci_rnc,
						      scics_sds_remote_node_context_callback callback,
						      void *callback_parameter);
enum sci_status sci_remote_node_context_suspend(struct sci_remote_node_context *sci_rnc,
						     u32 suspend_type,
						     scics_sds_remote_node_context_callback cb_fn,
						     void *cb_p);
enum sci_status sci_remote_node_context_resume(struct sci_remote_node_context *sci_rnc,
						    scics_sds_remote_node_context_callback cb_fn,
						    void *cb_p);
enum sci_status sci_remote_node_context_start_task(struct sci_remote_node_context *sci_rnc,
							struct isci_request *ireq);
enum sci_status sci_remote_node_context_start_io(struct sci_remote_node_context *sci_rnc,
						      struct isci_request *ireq);

#endif  /*                                  */
