/* SPDX-License-Identifier: GPL-2.0-only */
/**************************************************************************
 * Copyright (c) 2014 Patrik Jakobsson
 * All Rights Reserved.
 *
 **************************************************************************/

#ifndef _GEM_H
#define _GEM_H

<<<<<<< HEAD
struct drm_device;

=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
extern const struct drm_gem_object_funcs psb_gem_object_funcs;

extern int psb_gem_create(struct drm_file *file, struct drm_device *dev,
			  u64 size, u32 *handlep, int stolen, u32 align);

#endif
