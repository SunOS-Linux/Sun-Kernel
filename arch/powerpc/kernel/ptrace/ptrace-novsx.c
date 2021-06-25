// SPDX-License-Identifier: GPL-2.0-or-later

#include <linux/regset.h>

#include <asm/switch_to.h>

#include "ptrace-decl.h"

/*
 * Regardless of transactions, 'fp_state' holds the current running
 * value of all FPR registers and 'ckfp_state' holds the last checkpointed
 * value of all FPR registers for the current transaction.
 *
 * Userspace interface buffer layout:
 *
 * struct data {
 *	u64	fpr[32];
 *	u64	fpscr;
 * };
 */
int fpr_get(struct task_struct *target, const struct user_regset *regset,
	    struct membuf to)
{
<<<<<<< HEAD
#ifdef CONFIG_PPC_FPU_REGS
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BUILD_BUG_ON(offsetof(struct thread_fp_state, fpscr) !=
		     offsetof(struct thread_fp_state, fpr[32]));

	flush_fp_to_thread(target);

	return membuf_write(&to, &target->thread.fp_state, 33 * sizeof(u64));
<<<<<<< HEAD
#else
	return membuf_write(&to, &empty_zero_page, 33 * sizeof(u64));
#endif
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

/*
 * Regardless of transactions, 'fp_state' holds the current running
 * value of all FPR registers and 'ckfp_state' holds the last checkpointed
 * value of all FPR registers for the current transaction.
 *
 * Userspace interface buffer layout:
 *
 * struct data {
 *	u64	fpr[32];
 *	u64	fpscr;
 * };
 *
 */
int fpr_set(struct task_struct *target, const struct user_regset *regset,
	    unsigned int pos, unsigned int count,
	    const void *kbuf, const void __user *ubuf)
{
<<<<<<< HEAD
#ifdef CONFIG_PPC_FPU_REGS
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BUILD_BUG_ON(offsetof(struct thread_fp_state, fpscr) !=
		     offsetof(struct thread_fp_state, fpr[32]));

	flush_fp_to_thread(target);

	return user_regset_copyin(&pos, &count, &kbuf, &ubuf,
				  &target->thread.fp_state, 0, -1);
<<<<<<< HEAD
#else
	return 0;
#endif
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}
