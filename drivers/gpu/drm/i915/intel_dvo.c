/*
 * Copyright 2006 Dave Airlie <airlied@linux.ie>
 * Copyright © 2006-2007 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *	Eric Anholt <eric@anholt.net>
 */
#include <linux/i2c.h>
#include <linux/slab.h>
#include "drmP.h"
#include "drm.h"
#include "drm_crtc.h"
#include "intel_drv.h"
#include "i915_drm.h"
#include "i915_drv.h"
#include "dvo.h"

#define SIL164_ADDR	0x38
#define CH7xxx_ADDR	0x76
#define TFP410_ADDR	0x38

static const struct intel_dvo_device intel_dvo_devices[] = {
	{
		.type = INTEL_DVO_CHIP_TMDS,
		.name = "sil164",
		.dvo_reg = DVOC,
		.slave_addr = SIL164_ADDR,
		.dev_ops = &sil164_ops,
	},
	{
		.type = INTEL_DVO_CHIP_TMDS,
		.name = "ch7xxx",
		.dvo_reg = DVOC,
		.slave_addr = CH7xxx_ADDR,
		.dev_ops = &ch7xxx_ops,
	},
	{
		.type = INTEL_DVO_CHIP_LVDS,
		.name = "ivch",
		.dvo_reg = DVOA,
		.slave_addr = 0x02, /*                                */
		.dev_ops = &ivch_ops,
	},
	{
		.type = INTEL_DVO_CHIP_TMDS,
		.name = "tfp410",
		.dvo_reg = DVOC,
		.slave_addr = TFP410_ADDR,
		.dev_ops = &tfp410_ops,
	},
	{
		.type = INTEL_DVO_CHIP_LVDS,
		.name = "ch7017",
		.dvo_reg = DVOC,
		.slave_addr = 0x75,
		.gpio = GMBUS_PORT_DPB,
		.dev_ops = &ch7017_ops,
	}
};

struct intel_dvo {
	struct intel_encoder base;

	struct intel_dvo_device dev;

	struct drm_display_mode *panel_fixed_mode;
	bool panel_wants_dither;
};

static struct intel_dvo *enc_to_intel_dvo(struct drm_encoder *encoder)
{
	return container_of(encoder, struct intel_dvo, base.base);
}

static struct intel_dvo *intel_attached_dvo(struct drm_connector *connector)
{
	return container_of(intel_attached_encoder(connector),
			    struct intel_dvo, base);
}

static void intel_dvo_dpms(struct drm_encoder *encoder, int mode)
{
	struct drm_i915_private *dev_priv = encoder->dev->dev_private;
	struct intel_dvo *intel_dvo = enc_to_intel_dvo(encoder);
	u32 dvo_reg = intel_dvo->dev.dvo_reg;
	u32 temp = I915_READ(dvo_reg);

	if (mode == DRM_MODE_DPMS_ON) {
		I915_WRITE(dvo_reg, temp | DVO_ENABLE);
		I915_READ(dvo_reg);
		intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, mode);
	} else {
		intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, mode);
		I915_WRITE(dvo_reg, temp & ~DVO_ENABLE);
		I915_READ(dvo_reg);
	}
}

static int intel_dvo_mode_valid(struct drm_connector *connector,
				struct drm_display_mode *mode)
{
	struct intel_dvo *intel_dvo = intel_attached_dvo(connector);

	if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
		return MODE_NO_DBLESCAN;

	/*                           */

	if (intel_dvo->panel_fixed_mode) {
		if (mode->hdisplay > intel_dvo->panel_fixed_mode->hdisplay)
			return MODE_PANEL;
		if (mode->vdisplay > intel_dvo->panel_fixed_mode->vdisplay)
			return MODE_PANEL;
	}

	return intel_dvo->dev.dev_ops->mode_valid(&intel_dvo->dev, mode);
}

static bool intel_dvo_mode_fixup(struct drm_encoder *encoder,
				 struct drm_display_mode *mode,
				 struct drm_display_mode *adjusted_mode)
{
	struct intel_dvo *intel_dvo = enc_to_intel_dvo(encoder);

	/*                                                            
                                                                 
                                                               
                         
  */
	if (intel_dvo->panel_fixed_mode != NULL) {
#define C(x) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
		C(hdisplay);
		C(hsync_start);
		C(hsync_end);
		C(htotal);
		C(vdisplay);
		C(vsync_start);
		C(vsync_end);
		C(vtotal);
		C(clock);
#undef C
	}

	if (intel_dvo->dev.dev_ops->mode_fixup)
		return intel_dvo->dev.dev_ops->mode_fixup(&intel_dvo->dev, mode, adjusted_mode);

	return true;
}

static void intel_dvo_mode_set(struct drm_encoder *encoder,
			       struct drm_display_mode *mode,
			       struct drm_display_mode *adjusted_mode)
{
	struct drm_device *dev = encoder->dev;
	struct drm_i915_private *dev_priv = dev->dev_private;
	struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
	struct intel_dvo *intel_dvo = enc_to_intel_dvo(encoder);
	int pipe = intel_crtc->pipe;
	u32 dvo_val;
	u32 dvo_reg = intel_dvo->dev.dvo_reg, dvo_srcdim_reg;
	int dpll_reg = DPLL(pipe);

	switch (dvo_reg) {
	case DVOA:
	default:
		dvo_srcdim_reg = DVOA_SRCDIM;
		break;
	case DVOB:
		dvo_srcdim_reg = DVOB_SRCDIM;
		break;
	case DVOC:
		dvo_srcdim_reg = DVOC_SRCDIM;
		break;
	}

	intel_dvo->dev.dev_ops->mode_set(&intel_dvo->dev, mode, adjusted_mode);

	/*                                                                   */
	dvo_val = I915_READ(dvo_reg) &
		  (DVO_PRESERVE_MASK | DVO_DATA_ORDER_GBRG);
	dvo_val |= DVO_DATA_ORDER_FP | DVO_BORDER_ENABLE |
		   DVO_BLANK_ACTIVE_HIGH;

	if (pipe == 1)
		dvo_val |= DVO_PIPE_B_SELECT;
	dvo_val |= DVO_PIPE_STALL;
	if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
		dvo_val |= DVO_HSYNC_ACTIVE_HIGH;
	if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
		dvo_val |= DVO_VSYNC_ACTIVE_HIGH;

	I915_WRITE(dpll_reg, I915_READ(dpll_reg) | DPLL_DVO_HIGH_SPEED);

	/*                       
                                                             
                                                           */
	I915_WRITE(dvo_srcdim_reg,
		   (adjusted_mode->hdisplay << DVO_SRCDIM_HORIZONTAL_SHIFT) |
		   (adjusted_mode->vdisplay << DVO_SRCDIM_VERTICAL_SHIFT));
	/*                          */
	I915_WRITE(dvo_reg, dvo_val);
}

/* 
                                                  
  
                 
 */
static enum drm_connector_status
intel_dvo_detect(struct drm_connector *connector, bool force)
{
	struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
	return intel_dvo->dev.dev_ops->detect(&intel_dvo->dev);
}

static int intel_dvo_get_modes(struct drm_connector *connector)
{
	struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
	struct drm_i915_private *dev_priv = connector->dev->dev_private;

	/*                                                                   
                                                                       
                                                               
                        
  */
	intel_ddc_get_modes(connector,
			    &dev_priv->gmbus[GMBUS_PORT_DPC].adapter);
	if (!list_empty(&connector->probed_modes))
		return 1;

	if (intel_dvo->panel_fixed_mode != NULL) {
		struct drm_display_mode *mode;
		mode = drm_mode_duplicate(connector->dev, intel_dvo->panel_fixed_mode);
		if (mode) {
			drm_mode_probed_add(connector, mode);
			return 1;
		}
	}

	return 0;
}

static void intel_dvo_destroy(struct drm_connector *connector)
{
	drm_sysfs_connector_remove(connector);
	drm_connector_cleanup(connector);
	kfree(connector);
}

static const struct drm_encoder_helper_funcs intel_dvo_helper_funcs = {
	.dpms = intel_dvo_dpms,
	.mode_fixup = intel_dvo_mode_fixup,
	.prepare = intel_encoder_prepare,
	.mode_set = intel_dvo_mode_set,
	.commit = intel_encoder_commit,
};

static const struct drm_connector_funcs intel_dvo_connector_funcs = {
	.dpms = drm_helper_connector_dpms,
	.detect = intel_dvo_detect,
	.destroy = intel_dvo_destroy,
	.fill_modes = drm_helper_probe_single_connector_modes,
};

static const struct drm_connector_helper_funcs intel_dvo_connector_helper_funcs = {
	.mode_valid = intel_dvo_mode_valid,
	.get_modes = intel_dvo_get_modes,
	.best_encoder = intel_best_encoder,
};

static void intel_dvo_enc_destroy(struct drm_encoder *encoder)
{
	struct intel_dvo *intel_dvo = enc_to_intel_dvo(encoder);

	if (intel_dvo->dev.dev_ops->destroy)
		intel_dvo->dev.dev_ops->destroy(&intel_dvo->dev);

	kfree(intel_dvo->panel_fixed_mode);

	intel_encoder_destroy(encoder);
}

static const struct drm_encoder_funcs intel_dvo_enc_funcs = {
	.destroy = intel_dvo_enc_destroy,
};

/* 
                                                                           
  
                                                                           
                                                  
 */
static struct drm_display_mode *
intel_dvo_get_current_mode(struct drm_connector *connector)
{
	struct drm_device *dev = connector->dev;
	struct drm_i915_private *dev_priv = dev->dev_private;
	struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
	uint32_t dvo_val = I915_READ(intel_dvo->dev.dvo_reg);
	struct drm_display_mode *mode = NULL;

	/*                                                                   
                                                     
  */
	if (dvo_val & DVO_ENABLE) {
		struct drm_crtc *crtc;
		int pipe = (dvo_val & DVO_PIPE_B_SELECT) ? 1 : 0;

		crtc = intel_get_crtc_for_pipe(dev, pipe);
		if (crtc) {
			mode = intel_crtc_mode_get(dev, crtc);
			if (mode) {
				mode->type |= DRM_MODE_TYPE_PREFERRED;
				if (dvo_val & DVO_HSYNC_ACTIVE_HIGH)
					mode->flags |= DRM_MODE_FLAG_PHSYNC;
				if (dvo_val & DVO_VSYNC_ACTIVE_HIGH)
					mode->flags |= DRM_MODE_FLAG_PVSYNC;
			}
		}
	}

	return mode;
}

void intel_dvo_init(struct drm_device *dev)
{
	struct drm_i915_private *dev_priv = dev->dev_private;
	struct intel_encoder *intel_encoder;
	struct intel_dvo *intel_dvo;
	struct intel_connector *intel_connector;
	int i;
	int encoder_type = DRM_MODE_ENCODER_NONE;

	intel_dvo = kzalloc(sizeof(struct intel_dvo), GFP_KERNEL);
	if (!intel_dvo)
		return;

	intel_connector = kzalloc(sizeof(struct intel_connector), GFP_KERNEL);
	if (!intel_connector) {
		kfree(intel_dvo);
		return;
	}

	intel_encoder = &intel_dvo->base;
	drm_encoder_init(dev, &intel_encoder->base,
			 &intel_dvo_enc_funcs, encoder_type);

	/*                               */
	for (i = 0; i < ARRAY_SIZE(intel_dvo_devices); i++) {
		struct drm_connector *connector = &intel_connector->base;
		const struct intel_dvo_device *dvo = &intel_dvo_devices[i];
		struct i2c_adapter *i2c;
		int gpio;

		/*                                                            
                                                           
                 
   */
		if (dvo->gpio != 0)
			gpio = dvo->gpio;
		else if (dvo->type == INTEL_DVO_CHIP_LVDS)
			gpio = GMBUS_PORT_SSC;
		else
			gpio = GMBUS_PORT_DPB;

		/*                                                         
                                                             
                                                
   */
		i2c = &dev_priv->gmbus[gpio].adapter;

		intel_dvo->dev = *dvo;
		if (!dvo->dev_ops->init(&intel_dvo->dev, i2c))
			continue;

		intel_encoder->type = INTEL_OUTPUT_DVO;
		intel_encoder->crtc_mask = (1 << 0) | (1 << 1);
		switch (dvo->type) {
		case INTEL_DVO_CHIP_TMDS:
			intel_encoder->clone_mask =
				(1 << INTEL_DVO_TMDS_CLONE_BIT) |
				(1 << INTEL_ANALOG_CLONE_BIT);
			drm_connector_init(dev, connector,
					   &intel_dvo_connector_funcs,
					   DRM_MODE_CONNECTOR_DVII);
			encoder_type = DRM_MODE_ENCODER_TMDS;
			break;
		case INTEL_DVO_CHIP_LVDS:
			intel_encoder->clone_mask =
				(1 << INTEL_DVO_LVDS_CLONE_BIT);
			drm_connector_init(dev, connector,
					   &intel_dvo_connector_funcs,
					   DRM_MODE_CONNECTOR_LVDS);
			encoder_type = DRM_MODE_ENCODER_LVDS;
			break;
		}

		drm_connector_helper_add(connector,
					 &intel_dvo_connector_helper_funcs);
		connector->display_info.subpixel_order = SubPixelHorizontalRGB;
		connector->interlace_allowed = false;
		connector->doublescan_allowed = false;

		drm_encoder_helper_add(&intel_encoder->base,
				       &intel_dvo_helper_funcs);

		intel_connector_attach_encoder(intel_connector, intel_encoder);
		if (dvo->type == INTEL_DVO_CHIP_LVDS) {
			/*                                                   
                                                       
                                                       
                                                          
                                                        
                                    
    */
			intel_dvo->panel_fixed_mode =
				intel_dvo_get_current_mode(connector);
			intel_dvo->panel_wants_dither = true;
		}

		drm_sysfs_connector_add(connector);
		return;
	}

	drm_encoder_cleanup(&intel_encoder->base);
	kfree(intel_dvo);
	kfree(intel_connector);
}
