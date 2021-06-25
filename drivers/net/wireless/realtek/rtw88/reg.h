/* SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause */
/* Copyright(c) 2018-2019  Realtek Corporation
 */

#ifndef __RTW_REG_DEF_H__
#define __RTW_REG_DEF_H__

#define REG_SYS_FUNC_EN		0x0002
#define BIT_FEN_EN_25_1		BIT(13)
#define BIT_FEN_ELDR		BIT(12)
#define BIT_FEN_CPUEN		BIT(2)
#define BIT_FEN_BB_GLB_RST	BIT(1)
#define BIT_FEN_BB_RSTB		BIT(0)
#define BIT_R_DIS_PRST		BIT(6)
#define BIT_WLOCK_1C_B6		BIT(5)
#define REG_SYS_PW_CTRL		0x0004
#define BIT_PFM_WOWL		BIT(3)
#define REG_SYS_CLK_CTRL	0x0008
#define BIT_CPU_CLK_EN		BIT(14)

#define REG_SYS_CLKR		0x0008
#define BIT_ANA8M		BIT(1)
#define BIT_WAKEPAD_EN		BIT(3)
#define BIT_LOADER_CLK_EN	BIT(5)

#define REG_RSV_CTRL		0x001C
#define DISABLE_PI		0x3
#define ENABLE_PI		0x2
#define BITS_RFC_DIRECT		(BIT(31) | BIT(30))
#define BIT_WLMCU_IOIF		BIT(0)
#define REG_RF_CTRL		0x001F
#define BIT_RF_SDM_RSTB		BIT(2)
#define BIT_RF_RSTB		BIT(1)
#define BIT_RF_EN		BIT(0)

#define REG_AFE_CTRL1		0x0024
#define BIT_MAC_CLK_SEL		(BIT(20) | BIT(21))
#define REG_EFUSE_CTRL		0x0030
#define BIT_EF_FLAG		BIT(31)
#define BIT_SHIFT_EF_ADDR	8
#define BIT_MASK_EF_ADDR	0x3ff
#define BIT_MASK_EF_DATA	0xff
#define BITS_EF_ADDR		(BIT_MASK_EF_ADDR << BIT_SHIFT_EF_ADDR)
#define BITS_PLL		0xf0

#define REG_AFE_XTAL_CTRL	0x24
#define REG_AFE_PLL_CTRL	0x28
#define REG_AFE_CTRL3		0x2c
#define BIT_MASK_XTAL		0x00FFF000
#define BIT_XTAL_GMP_BIT4	BIT(28)

#define REG_LDO_EFUSE_CTRL	0x0034
#define BIT_MASK_EFUSE_BANK_SEL	(BIT(8) | BIT(9))

#define BIT_LDO25_VOLTAGE_V25	0x03
#define BIT_MASK_LDO25_VOLTAGE	GENMASK(6, 4)
#define BIT_SHIFT_LDO25_VOLTAGE	4
#define BIT_LDO25_EN		BIT(7)

#define REG_GPIO_MUXCFG		0x0040
#define BIT_FSPI_EN		BIT(19)
#define BIT_EN_SIC		BIT(12)

#define BIT_PO_BT_PTA_PINS	BIT(9)
#define BIT_BT_PTA_EN		BIT(5)
#define BIT_WLRFE_4_5_EN	BIT(2)

#define REG_LED_CFG		0x004C
#define BIT_LNAON_SEL_EN	BIT(26)
#define BIT_PAPE_SEL_EN		BIT(25)
#define BIT_DPDT_WL_SEL		BIT(24)
#define BIT_DPDT_SEL_EN		BIT(23)
#define REG_LEDCFG2		0x004E
#define REG_PAD_CTRL1		0x0064
#define BIT_BT_BTG_SEL		BIT(31)
#define BIT_PAPE_WLBT_SEL	BIT(29)
#define BIT_LNAON_WLBT_SEL	BIT(28)
#define BIT_BTGP_JTAG_EN	BIT(24)
#define BIT_BTGP_SPI_EN		BIT(20)
#define BIT_LED1DIS		BIT(15)
#define BIT_SW_DPDT_SEL_DATA	BIT(0)
#define REG_WL_BT_PWR_CTRL	0x0068
#define BIT_BT_FUNC_EN		BIT(18)
#define BIT_BT_DIG_CLK_EN	BIT(8)
#define REG_SYS_SDIO_CTRL	0x0070
#define BIT_DBG_GNT_WL_BT	BIT(27)
#define BIT_LTE_MUX_CTRL_PATH	BIT(26)
#define REG_HCI_OPT_CTRL	0x0074
#define BIT_USB_SUS_DIS		BIT(8)

#define REG_AFE_CTRL_4		0x0078
#define BIT_CK320M_AFE_EN	BIT(4)
#define BIT_EN_SYN		BIT(15)

#define REG_LDO_SWR_CTRL	0x007C
#define LDO_SEL			0xC3
#define SPS_SEL			0x83
#define BIT_XTA1		BIT(29)
#define BIT_XTA0		BIT(28)

#define REG_MCUFW_CTRL		0x0080
#define BIT_ANA_PORT_EN		BIT(22)
#define BIT_MAC_PORT_EN		BIT(21)
#define BIT_BOOT_FSPI_EN	BIT(20)
#define BIT_ROM_DLEN		BIT(19)
#define BIT_ROM_PGE		GENMASK(18, 16)	/* legacy only */
#define BIT_SHIFT_ROM_PGE	16
#define BIT_FW_INIT_RDY		BIT(15)
#define BIT_FW_DW_RDY		BIT(14)
#define BIT_RPWM_TOGGLE		BIT(7)
#define BIT_RAM_DL_SEL		BIT(7)	/* legacy only */
#define BIT_DMEM_CHKSUM_OK	BIT(6)
#define BIT_WINTINI_RDY		BIT(6)	/* legacy only */
#define BIT_DMEM_DW_OK		BIT(5)
#define BIT_IMEM_CHKSUM_OK	BIT(4)
#define BIT_IMEM_DW_OK		BIT(3)
#define BIT_IMEM_BOOT_LOAD_CHECKSUM_OK BIT(2)
#define BIT_FWDL_CHK_RPT	BIT(2)	/* legacy only */
#define BIT_MCUFWDL_RDY		BIT(1)	/* legacy only */
#define BIT_MCUFWDL_EN		BIT(0)
#define BIT_CHECK_SUM_OK	(BIT(4) | BIT(6))
#define FW_READY		(BIT_FW_INIT_RDY | BIT_FW_DW_RDY |             \
				 BIT_IMEM_DW_OK | BIT_DMEM_DW_OK |             \
				 BIT_CHECK_SUM_OK)
#define FW_READY_LEGACY		(BIT_MCUFWDL_RDY | BIT_FWDL_CHK_RPT |	       \
				 BIT_WINTINI_RDY | BIT_RAM_DL_SEL)
#define FW_READY_MASK		0xffff

#define REG_MCU_TST_CFG		0x84
#define VAL_FW_TRIGGER		0x1

#define REG_EFUSE_ACCESS	0x00CF
#define EFUSE_ACCESS_ON		0x69
#define EFUSE_ACCESS_OFF	0x00

#define REG_WLRF1		0x00EC
#define REG_WIFI_BT_INFO	0x00AA
#define BIT_BT_INT_EN		BIT(15)
#define REG_SYS_CFG1		0x00F0
#define	BIT_RTL_ID		BIT(23)
#define BIT_LDO			BIT(24)
#define BIT_RF_TYPE_ID		BIT(27)
#define BIT_SHIFT_VENDOR_ID	16
#define BIT_MASK_VENDOR_ID	0xf
#define BIT_VENDOR_ID(x) (((x) & BIT_MASK_VENDOR_ID) << BIT_SHIFT_VENDOR_ID)
#define BITS_VENDOR_ID		(BIT_MASK_VENDOR_ID << BIT_SHIFT_VENDOR_ID)
#define BIT_CLEAR_VENDOR_ID(x)	((x) & (~BITS_VENDOR_ID))
#define BIT_GET_VENDOR_ID(x) (((x) >> BIT_SHIFT_VENDOR_ID) & BIT_MASK_VENDOR_ID)
#define BIT_SHIFT_CHIP_VER	12
#define BIT_MASK_CHIP_VER	0xf
#define BIT_CHIP_VER(x)	 (((x) & BIT_MASK_CHIP_VER) << BIT_SHIFT_CHIP_VER)
#define BITS_CHIP_VER		(BIT_MASK_CHIP_VER << BIT_SHIFT_CHIP_VER)
#define BIT_CLEAR_CHIP_VER(x)	((x) & (~BITS_CHIP_VER))
#define BIT_GET_CHIP_VER(x) (((x) >> BIT_SHIFT_CHIP_VER) & BIT_MASK_CHIP_VER)
#define REG_SYS_STATUS1		0x00F4
#define REG_SYS_STATUS2		0x00F8
#define REG_SYS_CFG2		0x00FC
#define REG_WLRF1		0x00EC
#define BIT_WLRF1_BBRF_EN	(BIT(24) | BIT(25) | BIT(26))
#define REG_CR			0x0100
#define BIT_32K_CAL_TMR_EN	BIT(10)
#define BIT_MAC_SEC_EN		BIT(9)
#define BIT_ENSWBCN		BIT(8)
#define BIT_MACRXEN		BIT(7)
#define BIT_MACTXEN		BIT(6)
#define BIT_SCHEDULE_EN		BIT(5)
#define BIT_PROTOCOL_EN		BIT(4)
#define BIT_RXDMA_EN		BIT(3)
#define BIT_TXDMA_EN		BIT(2)
#define BIT_HCI_RXDMA_EN	BIT(1)
#define BIT_HCI_TXDMA_EN	BIT(0)
#define MAC_TRX_ENABLE	(BIT_HCI_TXDMA_EN | BIT_HCI_RXDMA_EN | BIT_TXDMA_EN | \
			BIT_RXDMA_EN | BIT_PROTOCOL_EN | BIT_SCHEDULE_EN | \
			BIT_MACTXEN | BIT_MACRXEN)
#define BIT_SHIFT_TXDMA_VOQ_MAP	4
#define BIT_MASK_TXDMA_VOQ_MAP	0x3
#define BIT_TXDMA_VOQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_VOQ_MAP) << BIT_SHIFT_TXDMA_VOQ_MAP)
#define BIT_SHIFT_TXDMA_VIQ_MAP	6
#define BIT_MASK_TXDMA_VIQ_MAP	0x3
#define BIT_TXDMA_VIQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_VIQ_MAP) << BIT_SHIFT_TXDMA_VIQ_MAP)
#define REG_TXDMA_PQ_MAP	0x010C
#define BIT_SHIFT_TXDMA_BEQ_MAP	8
#define BIT_MASK_TXDMA_BEQ_MAP	0x3
#define BIT_TXDMA_BEQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_BEQ_MAP) << BIT_SHIFT_TXDMA_BEQ_MAP)
#define BIT_SHIFT_TXDMA_BKQ_MAP	10
#define BIT_MASK_TXDMA_BKQ_MAP	0x3
#define BIT_TXDMA_BKQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_BKQ_MAP) << BIT_SHIFT_TXDMA_BKQ_MAP)
#define BIT_SHIFT_TXDMA_MGQ_MAP	12
#define BIT_MASK_TXDMA_MGQ_MAP	0x3
#define BIT_TXDMA_MGQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_MGQ_MAP) << BIT_SHIFT_TXDMA_MGQ_MAP)
#define BIT_SHIFT_TXDMA_HIQ_MAP	14
#define BIT_MASK_TXDMA_HIQ_MAP	0x3
#define BIT_TXDMA_HIQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_HIQ_MAP) << BIT_SHIFT_TXDMA_HIQ_MAP)
#define BIT_SHIFT_TXSC_40M	4
#define BIT_MASK_TXSC_40M	0xf
#define BIT_TXSC_40M(x)							       \
	(((x) & BIT_MASK_TXSC_40M) << BIT_SHIFT_TXSC_40M)
#define BIT_SHIFT_TXSC_20M	0
#define BIT_MASK_TXSC_20M	0xf
#define BIT_TXSC_20M(x)							       \
	(((x) & BIT_MASK_TXSC_20M) << BIT_SHIFT_TXSC_20M)
#define BIT_SHIFT_MAC_CLK_SEL	20
#define MAC_CLK_HW_DEF_80M	0
#define MAC_CLK_HW_DEF_40M	1
#define MAC_CLK_HW_DEF_20M	2
#define MAC_CLK_SPEED		80

#define REG_CR			0x0100
#define REG_TRXFF_BNDY		0x0114
#define REG_RXFF_BNDY		0x011C
#define REG_FE1IMR		0x0120
#define BIT_FS_RXDONE		BIT(16)
#define REG_PKTBUF_DBG_CTRL	0x0140
#define REG_C2HEVT		0x01A0
#define REG_MCUTST_1		0x01C0
#define REG_MCUTST_II		0x01C4
#define REG_WOWLAN_WAKE_REASON	0x01C7
#define REG_HMETFR		0x01CC
#define REG_HMEBOX0		0x01D0
#define REG_HMEBOX1		0x01D4
#define REG_HMEBOX2		0x01D8
#define REG_HMEBOX3		0x01DC
#define REG_HMEBOX0_EX		0x01F0
#define REG_HMEBOX1_EX		0x01F4
#define REG_HMEBOX2_EX		0x01F8
#define REG_HMEBOX3_EX		0x01FC

#define REG_RQPN		0x0200
#define BIT_MASK_HPQ		0xff
#define BIT_SHIFT_HPQ		0
#define BIT_RQPN_HPQ(x)		(((x) & BIT_MASK_HPQ) << BIT_SHIFT_HPQ)
#define BIT_MASK_LPQ		0xff
#define BIT_SHIFT_LPQ		8
#define BIT_RQPN_LPQ(x)		(((x) & BIT_MASK_LPQ) << BIT_SHIFT_LPQ)
#define BIT_MASK_PUBQ		0xff
#define BIT_SHIFT_PUBQ		16
#define BIT_RQPN_PUBQ(x)	(((x) & BIT_MASK_PUBQ) << BIT_SHIFT_PUBQ)
#define BIT_RQPN_HLP(h, l, p)	(BIT_LD_RQPN | BIT_RQPN_HPQ(h) |	       \
				 BIT_RQPN_LPQ(l) | BIT_RQPN_PUBQ(p))

#define REG_FIFOPAGE_CTRL_2	0x0204
#define BIT_BCN_VALID_V1	BIT(15)
#define BIT_MASK_BCN_HEAD_1_V1	0xfff
#define REG_AUTO_LLT_V1		0x0208
#define BIT_AUTO_INIT_LLT_V1	BIT(0)
#define REG_DWBCN0_CTRL		0x0208
#define BIT_BCN_VALID		BIT(16)
#define REG_TXDMA_OFFSET_CHK	0x020C
#define BIT_DROP_DATA_EN	BIT(9)
#define REG_TXDMA_STATUS	0x0210
#define BTI_PAGE_OVF		BIT(2)

#define REG_RQPN_NPQ		0x0214
#define BIT_MASK_NPQ		0xff
#define BIT_SHIFT_NPQ		0
#define BIT_MASK_EPQ		0xff
#define BIT_SHIFT_EPQ		16
#define BIT_RQPN_NPQ(x)		(((x) & BIT_MASK_NPQ) << BIT_SHIFT_NPQ)
#define BIT_RQPN_EPQ(x)		(((x) & BIT_MASK_EPQ) << BIT_SHIFT_EPQ)
#define BIT_RQPN_NE(n, e)	(BIT_RQPN_NPQ(n) | BIT_RQPN_EPQ(e))

#define REG_AUTO_LLT		0x0224
#define BIT_AUTO_INIT_LLT	BIT(16)
#define REG_RQPN_CTRL_1		0x0228
#define REG_RQPN_CTRL_2		0x022C
#define BIT_LD_RQPN		BIT(31)
#define REG_FIFOPAGE_INFO_1	0x0230
#define REG_FIFOPAGE_INFO_2	0x0234
#define REG_FIFOPAGE_INFO_3	0x0238
#define REG_FIFOPAGE_INFO_4	0x023C
#define REG_FIFOPAGE_INFO_5	0x0240
#define REG_H2C_HEAD		0x0244
#define REG_H2C_TAIL		0x0248
#define REG_H2C_READ_ADDR	0x024C
#define REG_H2C_INFO		0x0254
#define REG_RXPKT_NUM		0x0284
#define BIT_RXDMA_REQ		BIT(19)
#define BIT_RW_RELEASE		BIT(18)
#define BIT_RXDMA_IDLE		BIT(17)
#define REG_RXPKTNUM		0x02B0

#define REG_INT_MIG		0x0304
#define REG_HCI_MIX_CFG		0x03FC
#define BIT_PCIE_EMAC_PDN_AUX_TO_FAST_CLK BIT(26)

#define REG_BCNQ_INFO		0x0418
#define BIT_MGQ_CPU_EMPTY	BIT(24)
#define REG_FWHW_TXQ_CTRL	0x0420
#define BIT_EN_BCNQ_DL		BIT(22)
#define BIT_EN_WR_FREE_TAIL	BIT(20)
#define REG_HWSEQ_CTRL		0x0423

#define REG_BCNQ_BDNY_V1	0x0424
#define REG_BCNQ_BDNY		0x0424
#define REG_MGQ_BDNY		0x0425
#define REG_LIFETIME_EN		0x0426
#define BIT_BA_PARSER_EN	BIT(5)
#define REG_SPEC_SIFS		0x0428
#define REG_RETRY_LIMIT		0x042a
#define REG_DARFRC		0x0430
#define REG_DARFRCH		0x0434
#define REG_RARFRCH		0x043C
<<<<<<< HEAD
#define REG_RRSR		0x0440
#define BITS_RRSR_RSC		GENMASK(22, 21)
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
#define REG_ARFR0		0x0444
#define REG_ARFRH0		0x0448
#define REG_ARFR1_V1		0x044C
#define REG_ARFRH1_V1		0x0450
#define REG_CCK_CHECK		0x0454
#define BIT_CHECK_CCK_EN	BIT(7)
#define REG_AMPDU_MAX_TIME_V1	0x0455
#define REG_BCNQ1_BDNY_V1	0x0456
#define REG_AMPDU_MAX_TIME	0x0456
#define REG_WMAC_LBK_BF_HD	0x045D
#define REG_TX_HANG_CTRL	0x045E
#define BIT_EN_GNT_BT_AWAKE	BIT(3)
#define BIT_EN_EOF_V1		BIT(2)
#define REG_DATA_SC		0x0483
#define REG_ARFR4		0x049C
#define BIT_WL_RFK		BIT(0)
#define REG_ARFRH4		0x04A0
#define REG_ARFR5		0x04A4
#define REG_ARFRH5		0x04A8
#define REG_SW_AMPDU_BURST_MODE_CTRL 0x04BC
#define BIT_PRE_TX_CMD		BIT(6)
#define REG_QUEUE_CTRL		0x04C6
#define BIT_PTA_WL_TX_EN	BIT(4)
#define BIT_PTA_EDCCA_EN	BIT(5)
#define REG_SINGLE_AMPDU_CTRL	0x04C7
#define BIT_EN_SINGLE_APMDU	BIT(7)
#define REG_PROT_MODE_CTRL	0x04C8
#define REG_MAX_AGGR_NUM	0x04CA
#define REG_BAR_MODE_CTRL	0x04CC
#define REG_PRECNT_CTRL		0x04E5
#define BIT_BTCCA_CTRL		(BIT(0) | BIT(1))
#define BIT_EN_PRECNT		BIT(11)
#define REG_DUMMY_PAGE4_V1	0x04FC

#define REG_EDCA_VO_PARAM	0x0500
#define REG_EDCA_VI_PARAM	0x0504
#define REG_EDCA_BE_PARAM	0x0508
#define REG_EDCA_BK_PARAM	0x050C
#define BIT_MASK_TXOP_LMT	GENMASK(26, 16)
#define BIT_MASK_CWMAX		GENMASK(15, 12)
#define BIT_MASK_CWMIN		GENMASK(11, 8)
#define BIT_MASK_AIFS		GENMASK(7, 0)
#define REG_PIFS		0x0512
#define REG_SIFS		0x0514
#define BIT_SHIFT_SIFS_OFDM_CTX	8
#define BIT_SHIFT_SIFS_CCK_TRX	16
#define BIT_SHIFT_SIFS_OFDM_TRX	24
#define REG_AGGR_BREAK_TIME	0x051A
#define REG_SLOT		0x051B
#define REG_TX_PTCL_CTRL	0x0520
#define BIT_SIFS_BK_EN		BIT(12)
#define REG_TXPAUSE		0x0522
#define REG_RD_CTRL		0x0524
#define BIT_DIS_TXOP_CFE	BIT(10)
#define BIT_DIS_LSIG_CFE	BIT(9)
#define BIT_DIS_STBC_CFE	BIT(8)
#define REG_TBTT_PROHIBIT	0x0540
#define BIT_SHIFT_TBTT_HOLD_TIME_AP 8
#define REG_RD_NAV_NXT		0x0544
#define REG_NAV_PROT_LEN	0x0546
#define REG_BCN_CTRL		0x0550
#define BIT_DIS_TSF_UDT		BIT(4)
#define BIT_EN_BCN_FUNCTION	BIT(3)
#define BIT_EN_TXBCN_RPT	BIT(2)
#define REG_BCN_CTRL_CLINT0	0x0551
#define REG_DRVERLYINT		0x0558
#define REG_BCNDMATIM		0x0559
#define REG_ATIMWND		0x055A
#define REG_USTIME_TSF		0x055C
#define REG_BCN_MAX_ERR		0x055D
#define REG_RXTSF_OFFSET_CCK	0x055E
#define REG_MISC_CTRL		0x0577
#define BIT_EN_FREE_CNT		BIT(3)
#define BIT_DIS_SECOND_CCA	(BIT(0) | BIT(1))
#define REG_HIQ_NO_LMT_EN	0x5A7
#define BIT_HIQ_NO_LMT_EN_ROOT	BIT(0)
#define REG_TIMER0_SRC_SEL	0x05B4
#define BIT_TSFT_SEL_TIMER0	(BIT(4) | BIT(5) | BIT(6))

#define REG_TCR			0x0604
#define BIT_PWRMGT_HWDATA_EN	BIT(7)
#define REG_RCR			0x0608
#define BIT_APP_FCS		BIT(31)
#define BIT_APP_MIC		BIT(30)
#define BIT_APP_ICV		BIT(29)
#define BIT_APP_PHYSTS		BIT(28)
#define BIT_APP_BASSN		BIT(27)
#define BIT_VHT_DACK		BIT(26)
#define BIT_TCPOFLD_EN		BIT(25)
#define BIT_ENMBID		BIT(24)
#define BIT_LSIGEN		BIT(23)
#define BIT_MFBEN		BIT(22)
#define BIT_DISCHKPPDLLEN	BIT(21)
#define BIT_PKTCTL_DLEN		BIT(20)
#define BIT_TIM_PARSER_EN	BIT(18)
#define BIT_BC_MD_EN		BIT(17)
#define BIT_UC_MD_EN		BIT(16)
#define BIT_RXSK_PERPKT		BIT(15)
#define BIT_HTC_LOC_CTRL	BIT(14)
#define BIT_RPFM_CAM_ENABLE	BIT(12)
#define BIT_TA_BCN		BIT(11)
#define BIT_RCR_ADF		BIT(11)
#define BIT_DISDECMYPKT		BIT(10)
#define BIT_AICV		BIT(9)
#define BIT_ACRC32		BIT(8)
#define BIT_CBSSID_BCN		BIT(7)
#define BIT_CBSSID_DATA		BIT(6)
#define BIT_APWRMGT		BIT(5)
#define BIT_ADD3		BIT(4)
#define BIT_AB			BIT(3)
#define BIT_AM			BIT(2)
#define BIT_APM			BIT(1)
#define BIT_AAP			BIT(0)
#define REG_RX_PKT_LIMIT	0x060C
#define REG_RX_DRVINFO_SZ	0x060F
#define BIT_APP_PHYSTS		BIT(28)
#define REG_MAR			0x0620
#define REG_USTIME_EDCA		0x0638
#define REG_ACKTO_CCK		0x0639
#define REG_MAC_SPEC_SIFS	0x063A
#define REG_RESP_SIFS_CCK	0x063C
#define REG_RESP_SIFS_OFDM	0x063E
#define REG_ACKTO		0x0640
#define REG_EIFS		0x0642
#define REG_NAV_CTRL		0x0650
#define REG_WMAC_TRXPTCL_CTL	0x0668
#define BIT_RFMOD		(BIT(7) | BIT(8))
#define BIT_RFMOD_80M		BIT(8)
#define BIT_RFMOD_40M		BIT(7)
#define REG_WMAC_TRXPTCL_CTL_H	0x066C
#define REG_WKFMCAM_CMD		0x0698
#define BIT_WKFCAM_POLLING_V1	BIT(31)
#define BIT_WKFCAM_CLR_V1	BIT(30)
#define BIT_WKFCAM_WE		BIT(16)
#define BIT_SHIFT_WKFCAM_ADDR_V2	8
#define BIT_MASK_WKFCAM_ADDR_V2		0xff
#define BIT_WKFCAM_ADDR_V2(x)						       \
	(((x) & BIT_MASK_WKFCAM_ADDR_V2) << BIT_SHIFT_WKFCAM_ADDR_V2)
#define REG_WKFMCAM_RWD         0x069C
#define BIT_WKFMCAM_VALID	BIT(31)
#define BIT_WKFMCAM_BC		BIT(26)
#define BIT_WKFMCAM_MC		BIT(25)
#define BIT_WKFMCAM_UC		BIT(24)

#define REG_RXFLTMAP0		0x06A0
#define REG_RXFLTMAP1		0x06A2
#define REG_RXFLTMAP2		0x06A4
#define REG_RXFLTMAP4		0x068A
#define REG_BT_COEX_TABLE0	0x06C0
#define REG_BT_COEX_TABLE1	0x06C4
#define REG_BT_COEX_BRK_TABLE	0x06C8
#define REG_BT_COEX_TABLE_H	0x06CC
#define REG_BT_COEX_TABLE_H1	0x06CD
#define REG_BT_COEX_TABLE_H2	0x06CE
#define REG_BT_COEX_TABLE_H3	0x06CF
#define REG_BBPSF_CTRL		0x06DC

#define REG_BT_COEX_V2		0x0762
#define BIT_GNT_BT_POLARITY	BIT(12)
#define BIT_LTE_COEX_EN		BIT(7)
#define REG_BT_COEX_ENH_INTR_CTRL	0x76E
#define BIT_R_GRANTALL_WLMASK	BIT(3)
#define BIT_STATIS_BT_EN	BIT(2)
#define REG_BT_ACT_STATISTICS	0x0770
#define REG_BT_ACT_STATISTICS_1	0x0774
#define REG_BT_STAT_CTRL	0x0778
#define REG_BT_TDMA_TIME	0x0790
#define BIT_MASK_SAMPLE_RATE	GENMASK(5, 0)
#define REG_LTR_IDLE_LATENCY	0x0798
#define REG_LTR_ACTIVE_LATENCY	0x079C
#define REG_LTR_CTRL_BASIC	0x07A4
#define REG_WMAC_OPTION_FUNCTION 0x07D0
#define REG_WMAC_OPTION_FUNCTION_1 0x07D4

#define REG_FPGA0_RFMOD		0x0800
#define BIT_CCKEN		BIT(24)
#define BIT_OFDMEN		BIT(25)
#define REG_RX_GAIN_EN		0x081c

#define REG_RFE_CTRL_E		0x0974
#define REG_2ND_CCA_CTRL	0x0976

#define REG_CCK0_FAREPORT	0xa2c
#define BIT_CCK0_2RX		BIT(18)
#define BIT_CCK0_MRC		BIT(22)

#define REG_DIS_DPD		0x0a70
#define DIS_DPD_MASK		GENMASK(9, 0)
#define DIS_DPD_RATE6M		BIT(0)
#define DIS_DPD_RATE9M		BIT(1)
#define DIS_DPD_RATEMCS0	BIT(2)
#define DIS_DPD_RATEMCS1	BIT(3)
#define DIS_DPD_RATEMCS8	BIT(4)
#define DIS_DPD_RATEMCS9	BIT(5)
#define DIS_DPD_RATEVHT1SS_MCS0	BIT(6)
#define DIS_DPD_RATEVHT1SS_MCS1	BIT(7)
#define DIS_DPD_RATEVHT2SS_MCS0	BIT(8)
#define DIS_DPD_RATEVHT2SS_MCS1	BIT(9)
#define DIS_DPD_RATEALL		GENMASK(9, 0)

#define REG_RFE_CTRL8		0x0cb4
#define BIT_MASK_RFE_SEL89	GENMASK(7, 0)
#define REG_RFE_INV8		0x0cbd
#define BIT_MASK_RFE_INV89	GENMASK(1, 0)
#define REG_RFE_INV16		0x0cbe
#define BIT_RFE_BUF_EN		BIT(3)

#define REG_ANAPAR_XTAL_0	0x1040
#define REG_CPU_DMEM_CON	0x1080
#define BIT_WL_PLATFORM_RST	BIT(16)
#define BIT_WL_SECURITY_CLK	BIT(15)
#define BIT_DDMA_EN		BIT(8)

#define REG_H2C_PKT_READADDR	0x10D0
#define REG_H2C_PKT_WRITEADDR	0x10D4
#define REG_FW_DBG7		0x10FC
#define FW_KEY_MASK		0xffffff00

#define REG_CR_EXT		0x1100

#define REG_DDMA_CH0SA		0x1200
#define REG_DDMA_CH0DA		0x1204
#define REG_DDMA_CH0CTRL	0x1208
#define BIT_DDMACH0_OWN		BIT(31)
#define BIT_DDMACH0_CHKSUM_EN	BIT(29)
#define BIT_DDMACH0_CHKSUM_STS	BIT(27)
#define BIT_DDMACH0_RESET_CHKSUM_STS BIT(25)
#define BIT_DDMACH0_CHKSUM_CONT	BIT(24)
#define BIT_MASK_DDMACH0_DLEN	0x3ffff

#define REG_H2CQ_CSR		0x1330
#define BIT_H2CQ_FULL		BIT(31)
#define REG_FAST_EDCA_VOVI_SETTING 0x1448
#define REG_FAST_EDCA_BEBK_SETTING 0x144C

#define REG_RXPSF_CTRL		0x1610
#define BIT_RXGCK_FIFOTHR_EN	BIT(28)

#define BIT_SHIFT_RXGCK_VHT_FIFOTHR 26
#define BIT_MASK_RXGCK_VHT_FIFOTHR 0x3
#define BIT_RXGCK_VHT_FIFOTHR(x)                                               \
	(((x) & BIT_MASK_RXGCK_VHT_FIFOTHR) << BIT_SHIFT_RXGCK_VHT_FIFOTHR)
#define BITS_RXGCK_VHT_FIFOTHR                                                 \
	(BIT_MASK_RXGCK_VHT_FIFOTHR << BIT_SHIFT_RXGCK_VHT_FIFOTHR)

#define BIT_SHIFT_RXGCK_HT_FIFOTHR 24
#define BIT_MASK_RXGCK_HT_FIFOTHR 0x3
#define BIT_RXGCK_HT_FIFOTHR(x)                                                \
	(((x) & BIT_MASK_RXGCK_HT_FIFOTHR) << BIT_SHIFT_RXGCK_HT_FIFOTHR)
#define BITS_RXGCK_HT_FIFOTHR                                                  \
	(BIT_MASK_RXGCK_HT_FIFOTHR << BIT_SHIFT_RXGCK_HT_FIFOTHR)

#define BIT_SHIFT_RXGCK_OFDM_FIFOTHR 22
#define BIT_MASK_RXGCK_OFDM_FIFOTHR 0x3
#define BIT_RXGCK_OFDM_FIFOTHR(x)                                              \
	(((x) & BIT_MASK_RXGCK_OFDM_FIFOTHR) << BIT_SHIFT_RXGCK_OFDM_FIFOTHR)
#define BITS_RXGCK_OFDM_FIFOTHR                                                \
	(BIT_MASK_RXGCK_OFDM_FIFOTHR << BIT_SHIFT_RXGCK_OFDM_FIFOTHR)

#define BIT_SHIFT_RXGCK_CCK_FIFOTHR 20
#define BIT_MASK_RXGCK_CCK_FIFOTHR 0x3
#define BIT_RXGCK_CCK_FIFOTHR(x)                                               \
	(((x) & BIT_MASK_RXGCK_CCK_FIFOTHR) << BIT_SHIFT_RXGCK_CCK_FIFOTHR)
#define BITS_RXGCK_CCK_FIFOTHR                                                 \
	(BIT_MASK_RXGCK_CCK_FIFOTHR << BIT_SHIFT_RXGCK_CCK_FIFOTHR)

#define BIT_RXGCK_OFDMCCA_EN BIT(16)

#define BIT_SHIFT_RXPSF_PKTLENTHR 13
#define BIT_MASK_RXPSF_PKTLENTHR 0x7
#define BIT_RXPSF_PKTLENTHR(x)                                                 \
	(((x) & BIT_MASK_RXPSF_PKTLENTHR) << BIT_SHIFT_RXPSF_PKTLENTHR)
#define BITS_RXPSF_PKTLENTHR                                                   \
	(BIT_MASK_RXPSF_PKTLENTHR << BIT_SHIFT_RXPSF_PKTLENTHR)
#define BIT_CLEAR_RXPSF_PKTLENTHR(x) ((x) & (~BITS_RXPSF_PKTLENTHR))
#define BIT_SET_RXPSF_PKTLENTHR(x, v)                                          \
	(BIT_CLEAR_RXPSF_PKTLENTHR(x) | BIT_RXPSF_PKTLENTHR(v))

#define BIT_RXPSF_CTRLEN	BIT(12)
#define BIT_RXPSF_VHTCHKEN	BIT(11)
#define BIT_RXPSF_HTCHKEN	BIT(10)
#define BIT_RXPSF_OFDMCHKEN	BIT(9)
#define BIT_RXPSF_CCKCHKEN	BIT(8)
#define BIT_RXPSF_OFDMRST	BIT(7)
#define BIT_RXPSF_CCKRST	BIT(6)
#define BIT_RXPSF_MHCHKEN	BIT(5)
#define BIT_RXPSF_CONT_ERRCHKEN	BIT(4)
#define BIT_RXPSF_ALL_ERRCHKEN	BIT(3)

#define BIT_SHIFT_RXPSF_ERRTHR 0
#define BIT_MASK_RXPSF_ERRTHR 0x7
#define BIT_RXPSF_ERRTHR(x)                                                    \
	(((x) & BIT_MASK_RXPSF_ERRTHR) << BIT_SHIFT_RXPSF_ERRTHR)
#define BITS_RXPSF_ERRTHR (BIT_MASK_RXPSF_ERRTHR << BIT_SHIFT_RXPSF_ERRTHR)
#define BIT_CLEAR_RXPSF_ERRTHR(x) ((x) & (~BITS_RXPSF_ERRTHR))
#define BIT_GET_RXPSF_ERRTHR(x)                                                \
	(((x) >> BIT_SHIFT_RXPSF_ERRTHR) & BIT_MASK_RXPSF_ERRTHR)
#define BIT_SET_RXPSF_ERRTHR(x, v)                                             \
	(BIT_CLEAR_RXPSF_ERRTHR(x) | BIT_RXPSF_ERRTHR(v))

#define REG_RXPSF_TYPE_CTRL	0x1614
#define REG_GENERAL_OPTION	0x1664
#define BIT_DUMMY_FCS_READY_MASK_EN BIT(9)

#define REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL_V1		0x1700
#define REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA_V1	0x1704
#define REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA_V1	0x1708
#define LTECOEX_READY		BIT(29)
#define LTECOEX_ACCESS_CTRL REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL_V1
#define LTECOEX_WRITE_DATA REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA_V1
#define LTECOEX_READ_DATA REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA_V1

#define REG_IGN_GNT_BT1	0x1860

#define REG_RFESEL_CTRL	0x1990

#define REG_NOMASK_TXBT	0x1ca7
#define REG_ANAPAR	0x1c30
#define BIT_ANAPAR_BTPS	BIT(22)
#define REG_RSTB_SEL	0x1c38
#define BIT_DAC_OFF_ENABLE	BIT(4)
#define BIT_PI_IGNORE_GNT_BT	BIT(3)
#define BIT_NOMASK_TXBT_ENABLE	BIT(3)

#define REG_HRCV_MSG	0x1cf

#define REG_IGN_GNTBT4	0x4160

#define RF_MODE		0x00
#define RF_MODOPT	0x01
#define RF_WLINT	0x01
#define RF_WLSEL	0x02
#define RF_DTXLOK	0x08
#define RF_CFGCH	0x18
#define RF_RCK		0x1d
#define RF_LUTWA	0x33
#define RF_LUTWD1	0x3e
#define RF_LUTWD0	0x3f
#define RF_T_METER	0x42
#define RF_BSPAD	0x54
#define RF_GAINTX	0x56
#define RF_TXATANK	0x64
#define RF_TRXIQ	0x66
#define RF_RXIQGEN	0x8d
<<<<<<< HEAD
#define RF_SYN_PFD	0xb0
#define RF_XTALX2	0xb8
#define RF_SYN_CTRL	0xbb
#define RF_MALSEL	0xbe
#define RF_SYN_AAC	0xc9
#define RF_AAC_CTRL	0xca
#define RF_FAST_LCK	0xcc
=======
#define RF_XTALX2	0xb8
#define RF_MALSEL	0xbe
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
#define RF_RCKD		0xde
#define RF_TXADBG	0xde
#define RF_LUTDBG	0xdf
#define RF_LUTWE2	0xee
#define RF_LUTWE	0xef

#define LTE_COEX_CTRL	0x38
#define LTE_WL_TRX_CTRL	0xa0
#define LTE_BT_TRX_CTRL	0xa4

#endif
