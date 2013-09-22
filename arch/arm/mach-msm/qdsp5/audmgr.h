/* arch/arm/mach-msm/qdsp5/audmgr.h
 *
 * Copyright (C) 2008 Google, Inc.
 * Copyright (c) 2008-2009, 2012 The Linux Foundation. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _AUDIO_RPC_H_
#define _AUDIO_RPC_H_

#include <mach/qdsp5/qdsp5audppcmdi.h>

enum rpc_aud_def_sample_rate_type {
	RPC_AUD_DEF_SAMPLE_RATE_NONE,
	RPC_AUD_DEF_SAMPLE_RATE_8000,
	RPC_AUD_DEF_SAMPLE_RATE_11025,
	RPC_AUD_DEF_SAMPLE_RATE_12000,
	RPC_AUD_DEF_SAMPLE_RATE_16000,
	RPC_AUD_DEF_SAMPLE_RATE_22050,
	RPC_AUD_DEF_SAMPLE_RATE_24000,
	RPC_AUD_DEF_SAMPLE_RATE_32000,
	RPC_AUD_DEF_SAMPLE_RATE_44100,
	RPC_AUD_DEF_SAMPLE_RATE_48000,
	RPC_AUD_DEF_SAMPLE_RATE_MAX,
};

enum rpc_aud_def_method_type {
	RPC_AUD_DEF_METHOD_NONE,
	RPC_AUD_DEF_METHOD_KEY_BEEP,
	RPC_AUD_DEF_METHOD_PLAYBACK,
	RPC_AUD_DEF_METHOD_VOICE,
	RPC_AUD_DEF_METHOD_RECORD,
	RPC_AUD_DEF_METHOD_HOST_PCM,
	RPC_AUD_DEF_METHOD_MIDI_OUT,
	RPC_AUD_DEF_METHOD_RECORD_SBC,
	RPC_AUD_DEF_METHOD_DTMF_RINGER,
	RPC_AUD_DEF_METHOD_MAX,
};

enum rpc_aud_def_codec_type {
	RPC_AUD_DEF_CODEC_NONE,
	RPC_AUD_DEF_CODEC_DTMF,
	RPC_AUD_DEF_CODEC_MIDI,
	RPC_AUD_DEF_CODEC_MP3,
	RPC_AUD_DEF_CODEC_PCM,
	RPC_AUD_DEF_CODEC_AAC,
	RPC_AUD_DEF_CODEC_WMA,
	RPC_AUD_DEF_CODEC_RA,
	RPC_AUD_DEF_CODEC_ADPCM,
	RPC_AUD_DEF_CODEC_GAUDIO,
	RPC_AUD_DEF_CODEC_VOC_EVRC,
	RPC_AUD_DEF_CODEC_VOC_13K,
	RPC_AUD_DEF_CODEC_VOC_4GV_NB,
	RPC_AUD_DEF_CODEC_VOC_AMR,
	RPC_AUD_DEF_CODEC_VOC_EFR,
	RPC_AUD_DEF_CODEC_VOC_FR,
	RPC_AUD_DEF_CODEC_VOC_HR,
	RPC_AUD_DEF_CODEC_VOC_CDMA,
	RPC_AUD_DEF_CODEC_VOC_CDMA_WB,
	RPC_AUD_DEF_CODEC_VOC_UMTS,
	RPC_AUD_DEF_CODEC_VOC_UMTS_WB,
	RPC_AUD_DEF_CODEC_SBC,
	RPC_AUD_DEF_CODEC_VOC_PCM,
	RPC_AUD_DEF_CODEC_AMR_WB,
	RPC_AUD_DEF_CODEC_AMR_WB_PLUS,
	RPC_AUD_DEF_CODEC_AAC_BSAC,
	RPC_AUD_DEF_CODEC_MAX,
	RPC_AUD_DEF_CODEC_AMR_NB,
	RPC_AUD_DEF_CODEC_13K,
	RPC_AUD_DEF_CODEC_EVRC,
	RPC_AUD_DEF_CODEC_AC3,
	RPC_AUD_DEF_CODEC_MAX_002,
};

enum rpc_snd_method_type {
	RPC_SND_METHOD_VOICE = 0,
	RPC_SND_METHOD_KEY_BEEP,
	RPC_SND_METHOD_MESSAGE,
	RPC_SND_METHOD_RING,
	RPC_SND_METHOD_MIDI,
	RPC_SND_METHOD_AUX,
	RPC_SND_METHOD_MAX,
};

enum rpc_voc_codec_type {
	RPC_VOC_CODEC_DEFAULT,
	RPC_VOC_CODEC_ON_CHIP_0 = RPC_VOC_CODEC_DEFAULT,
	RPC_VOC_CODEC_ON_CHIP_1,
	RPC_VOC_CODEC_STEREO_HEADSET,
	RPC_VOC_CODEC_ON_CHIP_AUX,
	RPC_VOC_CODEC_BT_OFF_BOARD,
	RPC_VOC_CODEC_BT_A2DP,
	RPC_VOC_CODEC_OFF_BOARD,
	RPC_VOC_CODEC_SDAC,
	RPC_VOC_CODEC_RX_EXT_SDAC_TX_INTERNAL,
	RPC_VOC_CODEC_IN_STEREO_SADC_OUT_MONO_HANDSET,
	RPC_VOC_CODEC_IN_STEREO_SADC_OUT_STEREO_HEADSET,
	RPC_VOC_CODEC_TX_INT_SADC_RX_EXT_AUXPCM,
	RPC_VOC_CODEC_EXT_STEREO_SADC_OUT_MONO_HANDSET,
	RPC_VOC_CODEC_EXT_STEREO_SADC_OUT_STEREO_HEADSET,
	RPC_VOC_CODEC_TTY_ON_CHIP_1,
	RPC_VOC_CODEC_TTY_OFF_BOARD,
	RPC_VOC_CODEC_TTY_VCO,
	RPC_VOC_CODEC_TTY_HCO,
	RPC_VOC_CODEC_ON_CHIP_0_DUAL_MIC,
	RPC_VOC_CODEC_MAX,
	RPC_VOC_CODEC_NONE,
};

enum rpc_audmgr_status_type {
	RPC_AUDMGR_STATUS_READY,
	RPC_AUDMGR_STATUS_CODEC_CONFIG,
	RPC_AUDMGR_STATUS_PENDING,
	RPC_AUDMGR_STATUS_SUSPEND,
	RPC_AUDMGR_STATUS_FAILURE,
	RPC_AUDMGR_STATUS_VOLUME_CHANGE,
	RPC_AUDMGR_STATUS_DISABLED,
	RPC_AUDMGR_STATUS_ERROR,
	RPC_AUDMGR_STATUS_DEVICE_CONFIG,
	RPC_AUDMGR_STATUS_DEVICE_INFO

};

struct rpc_audmgr_enable_client_args {
	uint32_t set_to_one;
	uint32_t tx_sample_rate;
	uint32_t rx_sample_rate;
	uint32_t def_method;
	uint32_t codec_type;
	uint32_t snd_method;

	uint32_t cb_func;
	uint32_t client_data;
};
	
#define AUDMGR_ENABLE_CLIENT			2
#define AUDMGR_DISABLE_CLIENT			3
#define AUDMGR_SUSPEND_EVENT_RSP		4
#define AUDMGR_REGISTER_OPERATION_LISTENER	5
#define AUDMGR_UNREGISTER_OPERATION_LISTENER	6
#define AUDMGR_REGISTER_CODEC_LISTENER		7
#define AUDMGR_GET_RX_SAMPLE_RATE		8
#define AUDMGR_GET_TX_SAMPLE_RATE		9
#define AUDMGR_SET_DEVICE_MODE			10
#define MIN_RPC_DATA_LENGTH 16

#define AUDMGR_PROG_VERS "rs30000013:0x7feccbff"
#define AUDMGR_PROG 0x30000013
#define AUDMGR_VERS 0x7feccbff
#define AUDMGR_VERS_COMP 0x00010001
#define AUDMGR_VERS_COMP_VER2 0x00020001
#define AUDMGR_VERS_COMP_VER3 0x00030001
#define AUDMGR_VERS_COMP_VER4 0x00040001

struct cad_device_info_type {
	uint32_t rx_device;
	uint32_t tx_device;
	uint32_t ear_mute;
	uint32_t mic_mute;
	uint32_t volume;
};

struct rpc_audmgr_cb_common {
	uint32_t cb_id; /*         */
	uint32_t status; /*               */
	uint32_t set_to_one;  /*                                          */
	uint32_t disc;
	/*                                          
                                                      
                                                          
                                                               */
};

struct rpc_audmgr_cb_ready {
	struct rpc_audmgr_cb_common c_data;
	union {
		uint32_t handle;
		uint32_t volume;
		uint32_t status_disabled;
		uint32_t volume_change;
	} u;
	uint32_t client_data;
};

struct rpc_audmgr_cb_device_info {
	struct rpc_audmgr_cb_common c_data;
	struct cad_device_info_type d;
	uint32_t client_data;
};

#define AUDMGR_CB_FUNC_PTR			1
#define AUDMGR_OPR_LSTNR_CB_FUNC_PTR		2
#define AUDMGR_CODEC_LSTR_FUNC_PTR		3

struct dev_evt_msg {
	struct cad_device_info_type dev_type;
	uint32_t acdb_id;
	int session_info;
	uint32_t sample_rate;
};

typedef void (*device_info_func)(struct dev_evt_msg *evt_msg, void *private);

struct device_info_callback {
	device_info_func func;
	void *private;
};

struct audmgr {
	wait_queue_head_t wait;
	uint32_t handle;
	int state;
	struct dev_evt_msg evt;
};

struct audmgr_config {
	uint32_t tx_rate;
	uint32_t rx_rate;
	uint32_t def_method;
	uint32_t codec;
	uint32_t snd_method;
};

int audmgr_register_device_info_callback(struct device_info_callback *dcb);
int audmgr_deregister_device_info_callback(struct device_info_callback *dcb);

int audmgr_open(struct audmgr *am);
int audmgr_close(struct audmgr *am);
int audmgr_enable(struct audmgr *am, struct audmgr_config *cfg);
int audmgr_disable(struct audmgr *am);
#endif