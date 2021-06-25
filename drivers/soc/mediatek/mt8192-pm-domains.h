/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __SOC_MEDIATEK_MT8192_PM_DOMAINS_H
#define __SOC_MEDIATEK_MT8192_PM_DOMAINS_H

#include "mtk-pm-domains.h"
#include <dt-bindings/power/mt8192-power.h>

/*
 * MT8192 power domain support
 */

static const struct scpsys_domain_data scpsys_domain_data_mt8192[] = {
	[MT8192_POWER_DOMAIN_AUDIO] = {
<<<<<<< HEAD
		.name = "audio",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(21),
		.ctl_offs = 0x0354,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_2_AUDIO,
				    MT8192_TOP_AXI_PROT_EN_2_SET,
				    MT8192_TOP_AXI_PROT_EN_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_2_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_CONN] = {
<<<<<<< HEAD
		.name = "conn",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = PWR_STATUS_CONN,
		.ctl_offs = 0x0304,
		.sram_pdn_bits = 0,
		.sram_pdn_ack_bits = 0,
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_CONN,
				    MT8192_TOP_AXI_PROT_EN_SET,
				    MT8192_TOP_AXI_PROT_EN_CLR,
				    MT8192_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_CONN_2ND,
				    MT8192_TOP_AXI_PROT_EN_SET,
				    MT8192_TOP_AXI_PROT_EN_CLR,
				    MT8192_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_1_CONN,
				    MT8192_TOP_AXI_PROT_EN_1_SET,
				    MT8192_TOP_AXI_PROT_EN_1_CLR,
				    MT8192_TOP_AXI_PROT_EN_1_STA1),
		},
		.caps = MTK_SCPD_KEEP_DEFAULT_OFF,
	},
	[MT8192_POWER_DOMAIN_MFG0] = {
<<<<<<< HEAD
		.name = "mfg0",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(2),
		.ctl_offs = 0x0308,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_MFG1] = {
<<<<<<< HEAD
		.name = "mfg1",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(3),
		.ctl_offs = 0x030c,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_1_MFG1,
				    MT8192_TOP_AXI_PROT_EN_1_SET,
				    MT8192_TOP_AXI_PROT_EN_1_CLR,
				    MT8192_TOP_AXI_PROT_EN_1_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_2_MFG1,
				    MT8192_TOP_AXI_PROT_EN_2_SET,
				    MT8192_TOP_AXI_PROT_EN_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_2_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MFG1,
				    MT8192_TOP_AXI_PROT_EN_SET,
				    MT8192_TOP_AXI_PROT_EN_CLR,
				    MT8192_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_2_MFG1_2ND,
				    MT8192_TOP_AXI_PROT_EN_2_SET,
				    MT8192_TOP_AXI_PROT_EN_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_2_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_MFG2] = {
<<<<<<< HEAD
		.name = "mfg2",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(4),
		.ctl_offs = 0x0310,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_MFG3] = {
<<<<<<< HEAD
		.name = "mfg3",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(5),
		.ctl_offs = 0x0314,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_MFG4] = {
<<<<<<< HEAD
		.name = "mfg4",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(6),
		.ctl_offs = 0x0318,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_MFG5] = {
<<<<<<< HEAD
		.name = "mfg5",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(7),
		.ctl_offs = 0x031c,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_MFG6] = {
<<<<<<< HEAD
		.name = "mfg6",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(8),
		.ctl_offs = 0x0320,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_DISP] = {
<<<<<<< HEAD
		.name = "disp",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(20),
		.ctl_offs = 0x0350,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR_IGN(MT8192_TOP_AXI_PROT_EN_MM_DISP,
					MT8192_TOP_AXI_PROT_EN_MM_SET,
					MT8192_TOP_AXI_PROT_EN_MM_CLR,
					MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR_IGN(MT8192_TOP_AXI_PROT_EN_MM_2_DISP,
					MT8192_TOP_AXI_PROT_EN_MM_2_SET,
					MT8192_TOP_AXI_PROT_EN_MM_2_CLR,
					MT8192_TOP_AXI_PROT_EN_MM_2_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_DISP,
				    MT8192_TOP_AXI_PROT_EN_SET,
				    MT8192_TOP_AXI_PROT_EN_CLR,
				    MT8192_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_DISP_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_2_DISP_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_2_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_2_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_IPE] = {
<<<<<<< HEAD
		.name = "ipe",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(14),
		.ctl_offs = 0x0338,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_IPE,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_IPE_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_ISP] = {
<<<<<<< HEAD
		.name = "isp",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(12),
		.ctl_offs = 0x0330,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_2_ISP,
				    MT8192_TOP_AXI_PROT_EN_MM_2_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_2_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_2_ISP_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_2_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_2_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_ISP2] = {
<<<<<<< HEAD
		.name = "isp2",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(13),
		.ctl_offs = 0x0334,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_ISP2,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_ISP2_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_MDP] = {
<<<<<<< HEAD
		.name = "mdp",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(19),
		.ctl_offs = 0x034c,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_2_MDP,
				    MT8192_TOP_AXI_PROT_EN_MM_2_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_2_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_2_MDP_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_2_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_2_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_VENC] = {
<<<<<<< HEAD
		.name = "venc",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(17),
		.ctl_offs = 0x0344,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_VENC,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_VENC_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_VDEC] = {
<<<<<<< HEAD
		.name = "vdec",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(15),
		.ctl_offs = 0x033c,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_VDEC,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_VDEC_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_VDEC2] = {
<<<<<<< HEAD
		.name = "vdec2",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(16),
		.ctl_offs = 0x0340,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_CAM] = {
<<<<<<< HEAD
		.name = "cam",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(23),
		.ctl_offs = 0x035c,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_2_CAM,
				    MT8192_TOP_AXI_PROT_EN_2_SET,
				    MT8192_TOP_AXI_PROT_EN_2_CLR,
				    MT8192_TOP_AXI_PROT_EN_2_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_CAM,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_1_CAM,
				    MT8192_TOP_AXI_PROT_EN_1_SET,
				    MT8192_TOP_AXI_PROT_EN_1_CLR,
				    MT8192_TOP_AXI_PROT_EN_1_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_MM_CAM_2ND,
				    MT8192_TOP_AXI_PROT_EN_MM_SET,
				    MT8192_TOP_AXI_PROT_EN_MM_CLR,
				    MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR(MT8192_TOP_AXI_PROT_EN_VDNR_CAM,
				    MT8192_TOP_AXI_PROT_EN_VDNR_SET,
				    MT8192_TOP_AXI_PROT_EN_VDNR_CLR,
				    MT8192_TOP_AXI_PROT_EN_VDNR_STA1),
		},
	},
	[MT8192_POWER_DOMAIN_CAM_RAWA] = {
<<<<<<< HEAD
		.name = "cam_rawa",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(24),
		.ctl_offs = 0x0360,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_CAM_RAWB] = {
<<<<<<< HEAD
		.name = "cam_rawb",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(25),
		.ctl_offs = 0x0364,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT8192_POWER_DOMAIN_CAM_RAWC] = {
<<<<<<< HEAD
		.name = "cam_rawc",
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		.sta_mask = BIT(26),
		.ctl_offs = 0x0368,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
};

static const struct scpsys_soc_data mt8192_scpsys_data = {
	.domains_data = scpsys_domain_data_mt8192,
	.num_domains = ARRAY_SIZE(scpsys_domain_data_mt8192),
	.pwr_sta_offs = 0x016c,
	.pwr_sta2nd_offs = 0x0170,
};

#endif /* __SOC_MEDIATEK_MT8192_PM_DOMAINS_H */
