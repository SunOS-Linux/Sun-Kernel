/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _ASM_RISCV_STACKTRACE_H
#define _ASM_RISCV_STACKTRACE_H

#include <linux/sched.h>
#include <asm/ptrace.h>

struct stackframe {
	unsigned long fp;
	unsigned long ra;
};

extern void notrace walk_stackframe(struct task_struct *task, struct pt_regs *regs,
				    bool (*fn)(void *, unsigned long), void *arg);
<<<<<<< HEAD
extern void dump_backtrace(struct pt_regs *regs, struct task_struct *task,
			   const char *loglvl);
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

#endif /* _ASM_RISCV_STACKTRACE_H */
