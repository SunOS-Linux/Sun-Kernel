/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * rWTM BIU Mailbox driver for Armada 37xx
 *
<<<<<<< HEAD
 * Author: Marek Behún <kabel@kernel.org>
=======
 * Author: Marek Behun <marek.behun@nic.cz>
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
 */

#ifndef _LINUX_ARMADA_37XX_RWTM_MAILBOX_H_
#define _LINUX_ARMADA_37XX_RWTM_MAILBOX_H_

#include <linux/types.h>

struct armada_37xx_rwtm_tx_msg {
	u16 command;
	u32 args[16];
};

struct armada_37xx_rwtm_rx_msg {
	u32 retval;
	u32 status[16];
};

#endif /* _LINUX_ARMADA_37XX_RWTM_MAILBOX_H_ */
