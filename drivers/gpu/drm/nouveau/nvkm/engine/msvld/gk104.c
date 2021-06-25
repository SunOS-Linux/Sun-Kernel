/*
 * Copyright 2012 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs
 */
#include "priv.h"

#include <nvif/class.h>

static const struct nvkm_falcon_func
gk104_msvld = {
	.init = gf100_msvld_init,
	.sclass = {
		{ -1, -1, GK104_MSVLD },
		{}
	}
};

int
<<<<<<< HEAD
gk104_msvld_new(struct nvkm_device *device, enum nvkm_subdev_type type, int inst,
		struct nvkm_engine **pengine)
{
	return nvkm_msvld_new_(&gk104_msvld, device, type, inst, pengine);
=======
gk104_msvld_new(struct nvkm_device *device, int index,
		struct nvkm_engine **pengine)
{
	return nvkm_msvld_new_(&gk104_msvld, device, index, pengine);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}
