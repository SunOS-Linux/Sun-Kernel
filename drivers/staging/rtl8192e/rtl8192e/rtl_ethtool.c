// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright(c) 2008 - 2010 Realtek Corporation. All rights reserved.
 *
 * Based on the r8180 driver, which is:
 * Copyright 2004-2005 Andrea Merello <andrea.merello@gmail.com>, et al.
 *
 * Contact Information: wlanfae <wlanfae@realtek.com>
 */
#include <linux/netdevice.h>
#include <linux/ethtool.h>
#include <linux/delay.h>

#include "rtl_core.h"

static void _rtl92e_ethtool_get_drvinfo(struct net_device *dev,
					struct ethtool_drvinfo *info)
{
	struct r8192_priv *priv = rtllib_priv(dev);

<<<<<<< HEAD
	strscpy(info->driver, DRV_NAME, sizeof(info->driver));
	strscpy(info->version, DRV_VERSION, sizeof(info->version));
	strscpy(info->bus_info, pci_name(priv->pdev), sizeof(info->bus_info));
=======
	strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
	strlcpy(info->version, DRV_VERSION, sizeof(info->version));
	strlcpy(info->bus_info, pci_name(priv->pdev), sizeof(info->bus_info));
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

static u32 _rtl92e_ethtool_get_link(struct net_device *dev)
{
	struct r8192_priv *priv = rtllib_priv(dev);

	return ((priv->rtllib->state == RTLLIB_LINKED) ||
		(priv->rtllib->state == RTLLIB_LINKED_SCANNING));
}

const struct ethtool_ops rtl819x_ethtool_ops = {
	.get_drvinfo = _rtl92e_ethtool_get_drvinfo,
	.get_link = _rtl92e_ethtool_get_link,
};
