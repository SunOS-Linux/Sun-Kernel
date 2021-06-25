/* SPDX-License-Identifier: MIT */
#ifndef __NVKM_DMA_PRIV_H__
#define __NVKM_DMA_PRIV_H__
#define nvkm_dma(p) container_of((p), struct nvkm_dma, engine)
#include <engine/dma.h>

struct nvkm_dmaobj_func {
	int (*bind)(struct nvkm_dmaobj *, struct nvkm_gpuobj *, int align,
		    struct nvkm_gpuobj **);
};

<<<<<<< HEAD
int nvkm_dma_new_(const struct nvkm_dma_func *, struct nvkm_device *, enum nvkm_subdev_type, int,
		  struct nvkm_dma **);
=======
int nvkm_dma_new_(const struct nvkm_dma_func *, struct nvkm_device *,
		  int index, struct nvkm_dma **);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

struct nvkm_dma_func {
	int (*class_new)(struct nvkm_dma *, const struct nvkm_oclass *,
			 void *data, u32 size, struct nvkm_dmaobj **);
};
#endif
