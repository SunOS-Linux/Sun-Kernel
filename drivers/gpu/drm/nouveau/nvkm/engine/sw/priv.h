/* SPDX-License-Identifier: MIT */
#ifndef __NVKM_SW_PRIV_H__
#define __NVKM_SW_PRIV_H__
#define nvkm_sw(p) container_of((p), struct nvkm_sw, engine)
#include <engine/sw.h>
struct nvkm_sw_chan;

<<<<<<< HEAD
int nvkm_sw_new_(const struct nvkm_sw_func *, struct nvkm_device *, enum nvkm_subdev_type, int,
		 struct nvkm_sw **);
=======
int nvkm_sw_new_(const struct nvkm_sw_func *, struct nvkm_device *,
		 int index, struct nvkm_sw **);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

struct nvkm_sw_chan_sclass {
	int (*ctor)(struct nvkm_sw_chan *, const struct nvkm_oclass *,
		    void *data, u32 size, struct nvkm_object **);
	struct nvkm_sclass base;
};

struct nvkm_sw_func {
	int (*chan_new)(struct nvkm_sw *, struct nvkm_fifo_chan *,
			const struct nvkm_oclass *, struct nvkm_object **);
	const struct nvkm_sw_chan_sclass sclass[];
};
#endif
