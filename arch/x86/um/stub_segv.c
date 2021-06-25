/*
 * Copyright (C) 2004 - 2007 Jeff Dike (jdike@{addtoit,linux.intel}.com)
 * Licensed under the GPL
 */

#include <sysdep/stub.h>
#include <sysdep/faultinfo.h>
#include <sysdep/mcontext.h>
#include <sys/ucontext.h>

void __attribute__ ((__section__ (".__syscall_stub")))
stub_segv_handler(int sig, siginfo_t *info, void *p)
{
<<<<<<< HEAD
	int stack;
	ucontext_t *uc = p;
	struct faultinfo *f = (void *)(((unsigned long)&stack) & ~(UM_KERN_PAGE_SIZE - 1));

	GET_FAULTINFO_FROM_MC(*f, &uc->uc_mcontext);
=======
	ucontext_t *uc = p;

	GET_FAULTINFO_FROM_MC(*((struct faultinfo *) STUB_DATA),
			      &uc->uc_mcontext);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	trap_myself();
}

