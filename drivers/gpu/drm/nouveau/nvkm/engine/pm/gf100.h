/* SPDX-License-Identifier: MIT */
#ifndef __NVKM_PM_NVC0_H__
#define __NVKM_PM_NVC0_H__
#include "priv.h"

struct gf100_pm_func {
	const struct nvkm_specdom *doms_hub;
	const struct nvkm_specdom *doms_gpc;
	const struct nvkm_specdom *doms_part;
};

<<<<<<< HEAD
int gf100_pm_new_(const struct gf100_pm_func *, struct nvkm_device *, enum nvkm_subdev_type, int,
		  struct nvkm_pm **);
=======
int gf100_pm_new_(const struct gf100_pm_func *, struct nvkm_device *,
		  int index, struct nvkm_pm **);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

extern const struct nvkm_funcdom gf100_perfctr_func;
extern const struct nvkm_specdom gf100_pm_gpc[];

extern const struct nvkm_specsrc gf100_pbfb_sources[];
extern const struct nvkm_specsrc gf100_pmfb_sources[];
#endif
