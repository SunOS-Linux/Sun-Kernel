// SPDX-License-Identifier: GPL-2.0+
/*
 * xarray.c: Userspace shim for XArray test-suite
 * Copyright (c) 2018 Matthew Wilcox <willy@infradead.org>
 */

#define XA_DEBUG
#include "test.h"

#define module_init(x)
#define module_exit(x)
#define MODULE_AUTHOR(x)
#define MODULE_LICENSE(x)
#define dump_stack()	assert(0)

#include "../../../lib/xarray.c"
#undef XA_DEBUG
#include "../../../lib/test_xarray.c"

void xarray_tests(void)
{
	xarray_checks();
	xarray_exit();
}

int __weak main(void)
{
<<<<<<< HEAD
	rcu_register_thread();
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	radix_tree_init();
	xarray_tests();
	radix_tree_cpu_dead(1);
	rcu_barrier();
	if (nr_allocated)
		printf("nr_allocated = %d\n", nr_allocated);
<<<<<<< HEAD
	rcu_unregister_thread();
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	return 0;
}
