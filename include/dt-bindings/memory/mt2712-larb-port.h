/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2017 MediaTek Inc.
 * Author: Yong Wu <yong.wu@mediatek.com>
 */
<<<<<<< HEAD
#ifndef _DT_BINDINGS_MEMORY_MT2712_LARB_PORT_H_
#define _DT_BINDINGS_MEMORY_MT2712_LARB_PORT_H_

#include <dt-bindings/memory/mtk-memory-port.h>
=======
#ifndef __DTS_IOMMU_PORT_MT2712_H
#define __DTS_IOMMU_PORT_MT2712_H

#define MTK_M4U_ID(larb, port)		(((larb) << 5) | (port))
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

#define M4U_LARB0_ID			0
#define M4U_LARB1_ID			1
#define M4U_LARB2_ID			2
#define M4U_LARB3_ID			3
#define M4U_LARB4_ID			4
#define M4U_LARB5_ID			5
#define M4U_LARB6_ID			6
#define M4U_LARB7_ID			7
#define M4U_LARB8_ID			8
#define M4U_LARB9_ID			9

/* larb0 */
#define M4U_PORT_DISP_OVL0		MTK_M4U_ID(M4U_LARB0_ID, 0)
#define M4U_PORT_DISP_RDMA0		MTK_M4U_ID(M4U_LARB0_ID, 1)
#define M4U_PORT_DISP_WDMA0		MTK_M4U_ID(M4U_LARB0_ID, 2)
#define M4U_PORT_DISP_OD_R		MTK_M4U_ID(M4U_LARB0_ID, 3)
#define M4U_PORT_DISP_OD_W		MTK_M4U_ID(M4U_LARB0_ID, 4)
#define M4U_PORT_MDP_RDMA0		MTK_M4U_ID(M4U_LARB0_ID, 5)
#define M4U_PORT_MDP_WDMA		MTK_M4U_ID(M4U_LARB0_ID, 6)
#define M4U_PORT_DISP_RDMA2		MTK_M4U_ID(M4U_LARB0_ID, 7)

/* larb1 */
#define M4U_PORT_HW_VDEC_MC_EXT		MTK_M4U_ID(M4U_LARB1_ID, 0)
#define M4U_PORT_HW_VDEC_PP_EXT		MTK_M4U_ID(M4U_LARB1_ID, 1)
#define M4U_PORT_HW_VDEC_UFO_EXT	MTK_M4U_ID(M4U_LARB1_ID, 2)
#define M4U_PORT_HW_VDEC_VLD_EXT	MTK_M4U_ID(M4U_LARB1_ID, 3)
#define M4U_PORT_HW_VDEC_VLD2_EXT	MTK_M4U_ID(M4U_LARB1_ID, 4)
#define M4U_PORT_HW_VDEC_AVC_MV_EXT	MTK_M4U_ID(M4U_LARB1_ID, 5)
#define M4U_PORT_HW_VDEC_PRED_RD_EXT	MTK_M4U_ID(M4U_LARB1_ID, 6)
#define M4U_PORT_HW_VDEC_PRED_WR_EXT	MTK_M4U_ID(M4U_LARB1_ID, 7)
#define M4U_PORT_HW_VDEC_PPWRAP_EXT	MTK_M4U_ID(M4U_LARB1_ID, 8)
#define M4U_PORT_HW_VDEC_TILE		MTK_M4U_ID(M4U_LARB1_ID, 9)
#define M4U_PORT_HW_IMG_RESZ_EXT	MTK_M4U_ID(M4U_LARB1_ID, 10)

/* larb2 */
#define M4U_PORT_CAM_DMA0		MTK_M4U_ID(M4U_LARB2_ID, 0)
#define M4U_PORT_CAM_DMA1		MTK_M4U_ID(M4U_LARB2_ID, 1)
#define M4U_PORT_CAM_DMA2		MTK_M4U_ID(M4U_LARB2_ID, 2)

/* larb3 */
#define M4U_PORT_VENC_RCPU		MTK_M4U_ID(M4U_LARB3_ID, 0)
#define M4U_PORT_VENC_REC		MTK_M4U_ID(M4U_LARB3_ID, 1)
#define M4U_PORT_VENC_BSDMA		MTK_M4U_ID(M4U_LARB3_ID, 2)
#define M4U_PORT_VENC_SV_COMV		MTK_M4U_ID(M4U_LARB3_ID, 3)
#define M4U_PORT_VENC_RD_COMV		MTK_M4U_ID(M4U_LARB3_ID, 4)
#define M4U_PORT_VENC_CUR_CHROMA	MTK_M4U_ID(M4U_LARB3_ID, 5)
#define M4U_PORT_VENC_REF_CHROMA	MTK_M4U_ID(M4U_LARB3_ID, 6)
#define M4U_PORT_VENC_CUR_LUMA		MTK_M4U_ID(M4U_LARB3_ID, 7)
#define M4U_PORT_VENC_REF_LUMA		MTK_M4U_ID(M4U_LARB3_ID, 8)

/* larb4 */
#define M4U_PORT_DISP_OVL1		MTK_M4U_ID(M4U_LARB4_ID, 0)
#define M4U_PORT_DISP_RDMA1		MTK_M4U_ID(M4U_LARB4_ID, 1)
#define M4U_PORT_DISP_WDMA1		MTK_M4U_ID(M4U_LARB4_ID, 2)
#define M4U_PORT_DISP_OD1_R		MTK_M4U_ID(M4U_LARB4_ID, 3)
#define M4U_PORT_DISP_OD1_W		MTK_M4U_ID(M4U_LARB4_ID, 4)
#define M4U_PORT_MDP_RDMA1		MTK_M4U_ID(M4U_LARB4_ID, 5)
#define M4U_PORT_MDP_WROT1		MTK_M4U_ID(M4U_LARB4_ID, 6)

/* larb5 */
#define M4U_PORT_DISP_OVL2		MTK_M4U_ID(M4U_LARB5_ID, 0)
#define M4U_PORT_DISP_WDMA2		MTK_M4U_ID(M4U_LARB5_ID, 1)
#define M4U_PORT_MDP_RDMA2		MTK_M4U_ID(M4U_LARB5_ID, 2)
#define M4U_PORT_MDP_WROT0		MTK_M4U_ID(M4U_LARB5_ID, 3)

/* larb6 */
#define M4U_PORT_JPGDEC_WDMA_0		MTK_M4U_ID(M4U_LARB6_ID, 0)
#define M4U_PORT_JPGDEC_WDMA_1		MTK_M4U_ID(M4U_LARB6_ID, 1)
#define M4U_PORT_JPGDEC_BSDMA_0		MTK_M4U_ID(M4U_LARB6_ID, 2)
#define M4U_PORT_JPGDEC_BSDMA_1		MTK_M4U_ID(M4U_LARB6_ID, 3)

/* larb7 */
#define M4U_PORT_MDP_RDMA3		MTK_M4U_ID(M4U_LARB7_ID, 0)
#define M4U_PORT_MDP_WROT2		MTK_M4U_ID(M4U_LARB7_ID, 1)

/* larb8 */
#define M4U_PORT_VDO			MTK_M4U_ID(M4U_LARB8_ID, 0)
#define M4U_PORT_NR			MTK_M4U_ID(M4U_LARB8_ID, 1)
#define M4U_PORT_WR_CHANNEL0		MTK_M4U_ID(M4U_LARB8_ID, 2)

/* larb9 */
#define M4U_PORT_TVD			MTK_M4U_ID(M4U_LARB9_ID, 0)
#define M4U_PORT_WR_CHANNEL1		MTK_M4U_ID(M4U_LARB9_ID, 1)

#endif
