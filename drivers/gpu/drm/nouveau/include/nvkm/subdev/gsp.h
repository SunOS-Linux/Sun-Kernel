#ifndef __NVKM_GSP_H__
#define __NVKM_GSP_H__
#define nvkm_gsp(p) container_of((p), struct nvkm_gsp, subdev)
#include <core/subdev.h>
#include <core/falcon.h>

struct nvkm_gsp {
	struct nvkm_subdev subdev;
	struct nvkm_falcon falcon;
};

<<<<<<< HEAD
int gv100_gsp_new(struct nvkm_device *, enum nvkm_subdev_type, int, struct nvkm_gsp **);
=======
int gv100_gsp_new(struct nvkm_device *, int, struct nvkm_gsp **);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
#endif
