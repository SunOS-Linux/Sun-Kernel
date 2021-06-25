/* SPDX-License-Identifier: GPL-2.0 */
/*
 *  S390 version
 *    Copyright IBM Corp. 1999
 *
 *  Derived from "include/asm-i386/timex.h"
 *    Copyright (C) 1992, Linus Torvalds
 */

#ifndef _ASM_S390_TIMEX_H
#define _ASM_S390_TIMEX_H

#include <linux/preempt.h>
#include <linux/time64.h>
#include <asm/lowcore.h>

/* The value of the TOD clock for 1.1.1970. */
#define TOD_UNIX_EPOCH 0x7d91048bca000000ULL

extern u64 clock_comparator_max;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
union tod_clock {
	__uint128_t val;
	struct {
		__uint128_t ei	:  8; /* epoch index */
		__uint128_t tod : 64; /* bits 0-63 of tod clock */
		__uint128_t	: 40;
		__uint128_t pf	: 16; /* programmable field */
	};
	struct {
		__uint128_t eitod : 72; /* epoch index + bits 0-63 tod clock */
		__uint128_t	  : 56;
	};
	struct {
		__uint128_t us	: 60; /* micro-seconds */
		__uint128_t sus	: 12; /* sub-microseconds */
		__uint128_t	: 56;
	};
} __packed;

<<<<<<< HEAD
=======
=======
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
/* Inline functions for clock register access. */
static inline int set_tod_clock(__u64 time)
{
	int cc;

	asm volatile(
		"   sck   %1\n"
		"   ipm   %0\n"
		"   srl   %0,28\n"
		: "=d" (cc) : "Q" (time) : "cc");
	return cc;
}

<<<<<<< HEAD
static inline int store_tod_clock_ext_cc(union tod_clock *clk)
=======
<<<<<<< HEAD
static inline int store_tod_clock_ext_cc(union tod_clock *clk)
=======
static inline int store_tod_clock(__u64 *time)
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
{
	int cc;

	asm volatile(
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		"   stcke  %1\n"
		"   ipm   %0\n"
		"   srl   %0,28\n"
		: "=d" (cc), "=Q" (*clk) : : "cc");
	return cc;
}

static inline void store_tod_clock_ext(union tod_clock *tod)
{
	asm volatile("stcke %0" : "=Q" (*tod) : : "cc");
}

<<<<<<< HEAD
=======
=======
		"   stck  %1\n"
		"   ipm   %0\n"
		"   srl   %0,28\n"
		: "=d" (cc), "=Q" (*time) : : "cc");
	return cc;
}

>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
static inline void set_clock_comparator(__u64 time)
{
	asm volatile("sckc %0" : : "Q" (time));
}

static inline void set_tod_programmable_field(u16 val)
{
	register unsigned long reg0 asm("0") = val;

	asm volatile("sckpf" : : "d" (reg0));
}

void clock_comparator_work(void);

void __init time_early_init(void);

extern unsigned char ptff_function_mask[16];

/* Function codes for the ptff instruction. */
#define PTFF_QAF	0x00	/* query available functions */
#define PTFF_QTO	0x01	/* query tod offset */
#define PTFF_QSI	0x02	/* query steering information */
#define PTFF_QUI	0x04	/* query UTC information */
#define PTFF_ATO	0x40	/* adjust tod offset */
#define PTFF_STO	0x41	/* set tod offset */
#define PTFF_SFS	0x42	/* set fine steering rate */
#define PTFF_SGS	0x43	/* set gross steering rate */

/* Query TOD offset result */
struct ptff_qto {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	unsigned long physical_clock;
	unsigned long tod_offset;
	unsigned long logical_tod_offset;
	unsigned long tod_epoch_difference;
<<<<<<< HEAD
=======
=======
	unsigned long long physical_clock;
	unsigned long long tod_offset;
	unsigned long long logical_tod_offset;
	unsigned long long tod_epoch_difference;
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
} __packed;

static inline int ptff_query(unsigned int nr)
{
	unsigned char *ptr;

	ptr = ptff_function_mask + (nr >> 3);
	return (*ptr & (0x80 >> (nr & 7))) != 0;
}

/* Query UTC information result */
struct ptff_qui {
	unsigned int tm : 2;
	unsigned int ts : 2;
	unsigned int : 28;
	unsigned int pad_0x04;
	unsigned long leap_event;
	short old_leap;
	short new_leap;
	unsigned int pad_0x14;
	unsigned long prt[5];
	unsigned long cst[3];
	unsigned int skew;
	unsigned int pad_0x5c[41];
} __packed;

/*
 * ptff - Perform timing facility function
 * @ptff_block: Pointer to ptff parameter block
 * @len: Length of parameter block
 * @func: Function code
 * Returns: Condition code (0 on success)
 */
#define ptff(ptff_block, len, func)					\
({									\
	struct addrtype { char _[len]; };				\
	register unsigned int reg0 asm("0") = func;			\
	register unsigned long reg1 asm("1") = (unsigned long) (ptff_block);\
	int rc;								\
									\
	asm volatile(							\
		"	.word	0x0104\n"				\
		"	ipm	%0\n"					\
		"	srl	%0,28\n"				\
		: "=d" (rc), "+m" (*(struct addrtype *) reg1)		\
		: "d" (reg0), "d" (reg1) : "cc");			\
	rc;								\
})

<<<<<<< HEAD
static inline unsigned long local_tick_disable(void)
{
	unsigned long old;
=======
<<<<<<< HEAD
static inline unsigned long local_tick_disable(void)
{
	unsigned long old;
=======
static inline unsigned long long local_tick_disable(void)
{
	unsigned long long old;
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

	old = S390_lowcore.clock_comparator;
	S390_lowcore.clock_comparator = clock_comparator_max;
	set_clock_comparator(S390_lowcore.clock_comparator);
	return old;
}

<<<<<<< HEAD
static inline void local_tick_enable(unsigned long comp)
=======
<<<<<<< HEAD
static inline void local_tick_enable(unsigned long comp)
=======
static inline void local_tick_enable(unsigned long long comp)
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
{
	S390_lowcore.clock_comparator = comp;
	set_clock_comparator(S390_lowcore.clock_comparator);
}

#define CLOCK_TICK_RATE		1193180 /* Underlying HZ */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

typedef unsigned long cycles_t;

static inline unsigned long get_tod_clock(void)
{
	union tod_clock clk;

	store_tod_clock_ext(&clk);
	return clk.tod;
}

static inline unsigned long get_tod_clock_fast(void)
{
#ifdef CONFIG_HAVE_MARCH_Z9_109_FEATURES
	unsigned long clk;
<<<<<<< HEAD
=======
=======
#define STORE_CLOCK_EXT_SIZE	16	/* stcke writes 16 bytes */

typedef unsigned long long cycles_t;

static inline void get_tod_clock_ext(char *clk)
{
	typedef struct { char _[STORE_CLOCK_EXT_SIZE]; } addrtype;

	asm volatile("stcke %0" : "=Q" (*(addrtype *) clk) : : "cc");
}

static inline unsigned long long get_tod_clock(void)
{
	char clk[STORE_CLOCK_EXT_SIZE];

	get_tod_clock_ext(clk);
	return *((unsigned long long *)&clk[1]);
}

static inline unsigned long long get_tod_clock_fast(void)
{
#ifdef CONFIG_HAVE_MARCH_Z9_109_FEATURES
	unsigned long long clk;
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

	asm volatile("stckf %0" : "=Q" (clk) : : "cc");
	return clk;
#else
	return get_tod_clock();
#endif
}

static inline cycles_t get_cycles(void)
{
	return (cycles_t) get_tod_clock() >> 2;
}

int get_phys_clock(unsigned long *clock);
void init_cpu_timer(void);

<<<<<<< HEAD
extern union tod_clock tod_clock_base;
=======
<<<<<<< HEAD
extern union tod_clock tod_clock_base;
=======
extern unsigned char tod_clock_base[16] __aligned(8);
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

/**
 * get_clock_monotonic - returns current time in clock rate units
 *
 * The clock and tod_clock_base get changed via stop_machine.
 * Therefore preemption must be disabled, otherwise the returned
 * value is not guaranteed to be monotonic.
 */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
static inline unsigned long get_tod_clock_monotonic(void)
{
	unsigned long tod;

	preempt_disable_notrace();
	tod = get_tod_clock() - tod_clock_base.tod;
<<<<<<< HEAD
=======
=======
static inline unsigned long long get_tod_clock_monotonic(void)
{
	unsigned long long tod;

	preempt_disable_notrace();
	tod = get_tod_clock() - *(unsigned long long *) &tod_clock_base[1];
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	preempt_enable_notrace();
	return tod;
}

/**
 * tod_to_ns - convert a TOD format value to nanoseconds
 * @todval: to be converted TOD format value
 * Returns: number of nanoseconds that correspond to the TOD format value
 *
 * Converting a 64 Bit TOD format value to nanoseconds means that the value
 * must be divided by 4.096. In order to achieve that we multiply with 125
 * and divide by 512:
 *
 *    ns = (todval * 125) >> 9;
 *
 * In order to avoid an overflow with the multiplication we can rewrite this.
 * With a split todval == 2^9 * th + tl (th upper 55 bits, tl lower 9 bits)
 * we end up with
 *
 *    ns = ((2^9 * th + tl) * 125 ) >> 9;
 * -> ns = (th * 125) + ((tl * 125) >> 9);
 *
 */
<<<<<<< HEAD
static inline unsigned long tod_to_ns(unsigned long todval)
=======
<<<<<<< HEAD
static inline unsigned long tod_to_ns(unsigned long todval)
=======
static inline unsigned long long tod_to_ns(unsigned long long todval)
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
{
	return ((todval >> 9) * 125) + (((todval & 0x1ff) * 125) >> 9);
}

/**
 * tod_after - compare two 64 bit TOD values
 * @a: first 64 bit TOD timestamp
 * @b: second 64 bit TOD timestamp
 *
 * Returns: true if a is later than b
 */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
static inline int tod_after(unsigned long a, unsigned long b)
{
	if (MACHINE_HAS_SCC)
		return (long) a > (long) b;
<<<<<<< HEAD
=======
=======
static inline int tod_after(unsigned long long a, unsigned long long b)
{
	if (MACHINE_HAS_SCC)
		return (long long) a > (long long) b;
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	return a > b;
}

/**
 * tod_after_eq - compare two 64 bit TOD values
 * @a: first 64 bit TOD timestamp
 * @b: second 64 bit TOD timestamp
 *
 * Returns: true if a is later than b
 */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
static inline int tod_after_eq(unsigned long a, unsigned long b)
{
	if (MACHINE_HAS_SCC)
		return (long) a >= (long) b;
<<<<<<< HEAD
=======
=======
static inline int tod_after_eq(unsigned long long a, unsigned long long b)
{
	if (MACHINE_HAS_SCC)
		return (long long) a >= (long long) b;
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	return a >= b;
}

#endif
