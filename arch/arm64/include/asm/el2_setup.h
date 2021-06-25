/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012,2013 - ARM Ltd
 * Author: Marc Zyngier <marc.zyngier@arm.com>
 */

#ifndef __ARM_KVM_INIT_H__
#define __ARM_KVM_INIT_H__

#ifndef __ASSEMBLY__
#error Assembly-only header
#endif

#include <asm/kvm_arm.h>
#include <asm/ptrace.h>
#include <asm/sysreg.h>
#include <linux/irqchip/arm-gic-v3.h>

.macro __init_el2_sctlr
	mov_q	x0, INIT_SCTLR_EL2_MMU_OFF
	msr	sctlr_el2, x0
	isb
.endm

/*
 * Allow Non-secure EL1 and EL0 to access physical timer and counter.
 * This is not necessary for VHE, since the host kernel runs in EL2,
 * and EL0 accesses are configured in the later stage of boot process.
 * Note that when HCR_EL2.E2H == 1, CNTHCTL_EL2 has the same bit layout
 * as CNTKCTL_EL1, and CNTKCTL_EL1 accessing instructions are redefined
 * to access CNTHCTL_EL2. This allows the kernel designed to run at EL1
 * to transparently mess with the EL0 bits via CNTKCTL_EL1 access in
 * EL2.
 */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
.macro __init_el2_timers
	mrs	x0, cnthctl_el2
	orr	x0, x0, #3			// Enable EL1 physical timers
	msr	cnthctl_el2, x0
	msr	cntvoff_el2, xzr		// Clear virtual offset
.endm

.macro __init_el2_debug
	mrs	x1, id_aa64dfr0_el1
	sbfx	x0, x1, #ID_AA64DFR0_PMUVER_SHIFT, #4
	cmp	x0, #1
	b.lt	.Lskip_pmu_\@			// Skip if no PMU present
	mrs	x0, pmcr_el0			// Disable debug access traps
	ubfx	x0, x0, #11, #5			// to EL2 and allow access to
.Lskip_pmu_\@:
<<<<<<< HEAD
=======
=======
.macro __init_el2_timers mode
.ifeqs "\mode", "nvhe"
	mrs	x0, cnthctl_el2
	orr	x0, x0, #3			// Enable EL1 physical timers
	msr	cnthctl_el2, x0
.endif
	msr	cntvoff_el2, xzr		// Clear virtual offset
.endm

.macro __init_el2_debug mode
	mrs	x1, id_aa64dfr0_el1
	sbfx	x0, x1, #ID_AA64DFR0_PMUVER_SHIFT, #4
	cmp	x0, #1
	b.lt	1f				// Skip if no PMU present
	mrs	x0, pmcr_el0			// Disable debug access traps
	ubfx	x0, x0, #11, #5			// to EL2 and allow access to
1:
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	csel	x2, xzr, x0, lt			// all PMU counters from EL1

	/* Statistical profiling */
	ubfx	x0, x1, #ID_AA64DFR0_PMSVER_SHIFT, #4
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	cbz	x0, .Lskip_spe_\@		// Skip if SPE not present

	mrs_s	x0, SYS_PMBIDR_EL1              // If SPE available at EL2,
	and	x0, x0, #(1 << SYS_PMBIDR_EL1_P_SHIFT)
	cbnz	x0, .Lskip_spe_el2_\@		// then permit sampling of physical
	mov	x0, #(1 << SYS_PMSCR_EL2_PCT_SHIFT | \
		      1 << SYS_PMSCR_EL2_PA_SHIFT)
	msr_s	SYS_PMSCR_EL2, x0		// addresses and physical counter
.Lskip_spe_el2_\@:
	mov	x0, #(MDCR_EL2_E2PB_MASK << MDCR_EL2_E2PB_SHIFT)
	orr	x2, x2, x0			// If we don't have VHE, then
						// use EL1&0 translation.

.Lskip_spe_\@:
<<<<<<< HEAD
=======
=======
	cbz	x0, 3f				// Skip if SPE not present

.ifeqs "\mode", "nvhe"
	mrs_s	x0, SYS_PMBIDR_EL1              // If SPE available at EL2,
	and	x0, x0, #(1 << SYS_PMBIDR_EL1_P_SHIFT)
	cbnz	x0, 2f				// then permit sampling of physical
	mov	x0, #(1 << SYS_PMSCR_EL2_PCT_SHIFT | \
		      1 << SYS_PMSCR_EL2_PA_SHIFT)
	msr_s	SYS_PMSCR_EL2, x0		// addresses and physical counter
2:
	mov	x0, #(MDCR_EL2_E2PB_MASK << MDCR_EL2_E2PB_SHIFT)
	orr	x2, x2, x0			// If we don't have VHE, then
						// use EL1&0 translation.
.else
	orr	x2, x2, #MDCR_EL2_TPMS		// For VHE, use EL2 translation
						// and disable access from EL1
.endif

3:
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	msr	mdcr_el2, x2			// Configure debug traps
.endm

/* LORegions */
.macro __init_el2_lor
	mrs	x1, id_aa64mmfr1_el1
	ubfx	x0, x1, #ID_AA64MMFR1_LOR_SHIFT, 4
<<<<<<< HEAD
	cbz	x0, .Lskip_lor_\@
	msr_s	SYS_LORC_EL1, xzr
.Lskip_lor_\@:
=======
<<<<<<< HEAD
	cbz	x0, .Lskip_lor_\@
	msr_s	SYS_LORC_EL1, xzr
.Lskip_lor_\@:
=======
	cbz	x0, 1f
	msr_s	SYS_LORC_EL1, xzr
1:
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
.endm

/* Stage-2 translation */
.macro __init_el2_stage2
	msr	vttbr_el2, xzr
.endm

/* GICv3 system register access */
.macro __init_el2_gicv3
	mrs	x0, id_aa64pfr0_el1
	ubfx	x0, x0, #ID_AA64PFR0_GIC_SHIFT, #4
<<<<<<< HEAD
	cbz	x0, .Lskip_gicv3_\@
=======
<<<<<<< HEAD
	cbz	x0, .Lskip_gicv3_\@
=======
	cbz	x0, 1f
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

	mrs_s	x0, SYS_ICC_SRE_EL2
	orr	x0, x0, #ICC_SRE_EL2_SRE	// Set ICC_SRE_EL2.SRE==1
	orr	x0, x0, #ICC_SRE_EL2_ENABLE	// Set ICC_SRE_EL2.Enable==1
	msr_s	SYS_ICC_SRE_EL2, x0
	isb					// Make sure SRE is now set
	mrs_s	x0, SYS_ICC_SRE_EL2		// Read SRE back,
	tbz	x0, #0, 1f			// and check that it sticks
	msr_s	SYS_ICH_HCR_EL2, xzr		// Reset ICC_HCR_EL2 to defaults
<<<<<<< HEAD
.Lskip_gicv3_\@:
=======
<<<<<<< HEAD
.Lskip_gicv3_\@:
=======
1:
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
.endm

.macro __init_el2_hstr
	msr	hstr_el2, xzr			// Disable CP15 traps to EL2
.endm

/* Virtual CPU ID registers */
<<<<<<< HEAD
.macro __init_el2_nvhe_idregs
=======
<<<<<<< HEAD
.macro __init_el2_nvhe_idregs
=======
.macro __init_el2_idregs
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	mrs	x0, midr_el1
	mrs	x1, mpidr_el1
	msr	vpidr_el2, x0
	msr	vmpidr_el2, x1
.endm

/* Coprocessor traps */
.macro __init_el2_nvhe_cptr
	mov	x0, #0x33ff
	msr	cptr_el2, x0			// Disable copro. traps to EL2
.endm

/* SVE register access */
.macro __init_el2_nvhe_sve
	mrs	x1, id_aa64pfr0_el1
	ubfx	x1, x1, #ID_AA64PFR0_SVE_SHIFT, #4
<<<<<<< HEAD
	cbz	x1, .Lskip_sve_\@
=======
<<<<<<< HEAD
	cbz	x1, .Lskip_sve_\@
=======
	cbz	x1, 1f
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

	bic	x0, x0, #CPTR_EL2_TZ		// Also disable SVE traps
	msr	cptr_el2, x0			// Disable copro. traps to EL2
	isb
	mov	x1, #ZCR_ELx_LEN_MASK		// SVE: Enable full vector
	msr_s	SYS_ZCR_EL2, x1			// length for EL1.
<<<<<<< HEAD
.Lskip_sve_\@:
=======
<<<<<<< HEAD
.Lskip_sve_\@:
=======
1:
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
.endm

.macro __init_el2_nvhe_prepare_eret
	mov	x0, #INIT_PSTATE_EL1
	msr	spsr_el2, x0
.endm

/**
 * Initialize EL2 registers to sane values. This should be called early on all
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
 * cores that were booted in EL2. Note that everything gets initialised as
 * if VHE was not evailable. The kernel context will be upgraded to VHE
 * if possible later on in the boot process
 *
 * Regs: x0, x1 and x2 are clobbered.
 */
.macro init_el2_state
	__init_el2_sctlr
	__init_el2_timers
	__init_el2_debug
<<<<<<< HEAD
=======
=======
 * cores that were booted in EL2.
 *
 * Regs: x0, x1 and x2 are clobbered.
 */
.macro init_el2_state mode
.ifnes "\mode", "vhe"
.ifnes "\mode", "nvhe"
.error "Invalid 'mode' argument"
.endif
.endif

	__init_el2_sctlr
	__init_el2_timers \mode
	__init_el2_debug \mode
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	__init_el2_lor
	__init_el2_stage2
	__init_el2_gicv3
	__init_el2_hstr
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	__init_el2_nvhe_idregs
	__init_el2_nvhe_cptr
	__init_el2_nvhe_sve
	__init_el2_nvhe_prepare_eret
<<<<<<< HEAD
=======
=======
	__init_el2_idregs

	/*
	 * When VHE is not in use, early init of EL2 needs to be done here.
	 * When VHE _is_ in use, EL1 will not be used in the host and
	 * requires no configuration, and all non-hyp-specific EL2 setup
	 * will be done via the _EL1 system register aliases in __cpu_setup.
	 */
.ifeqs "\mode", "nvhe"
	__init_el2_nvhe_cptr
	__init_el2_nvhe_sve
	__init_el2_nvhe_prepare_eret
.endif
>>>>>>> stable
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
.endm

#endif /* __ARM_KVM_INIT_H__ */
