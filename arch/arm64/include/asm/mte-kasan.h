/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 ARM Ltd.
 */
#ifndef __ASM_MTE_KASAN_H
#define __ASM_MTE_KASAN_H

#include <asm/mte-def.h>

#ifndef __ASSEMBLY__

#include <linux/types.h>

<<<<<<< HEAD
#ifdef CONFIG_ARM64_MTE

/*
 * These functions are meant to be only used from KASAN runtime through
 * the arch_*() interface defined in asm/memory.h.
 * These functions don't include system_supports_mte() checks,
 * as KASAN only calls them when MTE is supported and enabled.
 */
=======
/*
 * The functions below are meant to be used only for the
 * KASAN_HW_TAGS interface defined in asm/memory.h.
 */
#ifdef CONFIG_ARM64_MTE
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

static inline u8 mte_get_ptr_tag(void *ptr)
{
	/* Note: The format of KASAN tags is 0xF<x> */
	u8 tag = 0xF0 | (u8)(((u64)(ptr)) >> MTE_TAG_SHIFT);

	return tag;
}

<<<<<<< HEAD
/* Get allocation tag for the address. */
static inline u8 mte_get_mem_tag(void *addr)
{
	asm(__MTE_PREAMBLE "ldg %0, [%0]"
		: "+r" (addr));

	return mte_get_ptr_tag(addr);
}

/* Generate a random tag. */
static inline u8 mte_get_random_tag(void)
{
	void *addr;

	asm(__MTE_PREAMBLE "irg %0, %0"
		: "=r" (addr));

	return mte_get_ptr_tag(addr);
}

/*
 * Assign allocation tags for a region of memory based on the pointer tag.
 * Note: The address must be non-NULL and MTE_GRANULE_SIZE aligned and
 * size must be non-zero and MTE_GRANULE_SIZE aligned.
 */
static inline void mte_set_mem_tag_range(void *addr, size_t size, u8 tag)
{
	u64 curr, end;

	if (!size)
		return;

	curr = (u64)__tag_set(addr, tag);
	end = curr + size;

	do {
		/*
		 * 'asm volatile' is required to prevent the compiler to move
		 * the statement outside of the loop.
		 */
		asm volatile(__MTE_PREAMBLE "stg %0, [%0]"
			     :
			     : "r" (curr)
			     : "memory");

		curr += MTE_GRANULE_SIZE;
	} while (curr != end);
}
=======
u8 mte_get_mem_tag(void *addr);
u8 mte_get_random_tag(void);
void *mte_set_mem_tag_range(void *addr, size_t size, u8 tag);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

void mte_enable_kernel(void);
void mte_init_tags(u64 max_tag);

<<<<<<< HEAD
void mte_set_report_once(bool state);
bool mte_report_once(void);

=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
#else /* CONFIG_ARM64_MTE */

static inline u8 mte_get_ptr_tag(void *ptr)
{
	return 0xFF;
}

static inline u8 mte_get_mem_tag(void *addr)
{
	return 0xFF;
}
<<<<<<< HEAD

=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
static inline u8 mte_get_random_tag(void)
{
	return 0xFF;
}
<<<<<<< HEAD

static inline void mte_set_mem_tag_range(void *addr, size_t size, u8 tag)
{
=======
static inline void *mte_set_mem_tag_range(void *addr, size_t size, u8 tag)
{
	return addr;
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

static inline void mte_enable_kernel(void)
{
}

static inline void mte_init_tags(u64 max_tag)
{
}

<<<<<<< HEAD
static inline void mte_set_report_once(bool state)
{
}

static inline bool mte_report_once(void)
{
	return false;
}

=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
#endif /* CONFIG_ARM64_MTE */

#endif /* __ASSEMBLY__ */

#endif /* __ASM_MTE_KASAN_H  */
