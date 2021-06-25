/* SPDX-License-Identifier: MIT */
#ifndef __NV10_GR_H__
#define __NV10_GR_H__
#include "priv.h"

<<<<<<< HEAD
int nv10_gr_new_(const struct nvkm_gr_func *, struct nvkm_device *, enum nvkm_subdev_type, int,
=======
int nv10_gr_new_(const struct nvkm_gr_func *, struct nvkm_device *, int index,
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		 struct nvkm_gr **);
int nv10_gr_init(struct nvkm_gr *);
void nv10_gr_intr(struct nvkm_gr *);
void nv10_gr_tile(struct nvkm_gr *, int, struct nvkm_fb_tile *);

int nv10_gr_chan_new(struct nvkm_gr *, struct nvkm_fifo_chan *,
		     const struct nvkm_oclass *, struct nvkm_object **);
#endif
