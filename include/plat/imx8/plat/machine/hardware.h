/*
 * Copyright 2017, DornerWorks
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_DORNERWORKS_GPL)
 */

#ifndef __PLAT_MACHINE_HARDWARE_H
#define __PLAT_MACHINE_HARDWARE_H

#include <config.h>
#include <types.h>
#include <basic_types.h>
#include <arch/linker.h>
#include <arch/object/vcpu.h>
#include <plat/machine.h>
#include <plat/machine/devices.h>
#include <plat_mode/machine/hardware.h>
#include <machine/io.h>

#define physBase        0x880000000


static const kernel_frame_t BOOT_RODATA kernel_devices[] = {
    {
        /* GIC Distributor*/
        Dblog_GIC_DISTRIBUTOR_PADDR,
        GIC_500_DISTRIBUTOR_PPTR,
        16,
        true  /* armExecuteNever */
    },
    {
        /* GIC Controller */
        Dblog_GIC_REDIST_PADDR,
        GIC_500_REDIST_PPTR,
        32,
        true /* armExecuteNever */
    },
#ifdef CONFIG_PRINTING
    {
        /*  UART */
        UART_PADDR,
        UART_PPTR,
        1,
        true  /* armExecuteNever */
    }
#endif /* CONFIG_PRINTING */
};


/* Available physical memory regions on platform (RAM) */
/* NOTE: Regions are not allowed to be adjacent! */
const p_region_t BOOT_RODATA avail_p_regs[] = {
    { /* .start = */ 0x880000000, /* .end = */ 0x980000000},
};

const p_region_t BOOT_RODATA dev_p_regs[] = {
{ /* .start = */ DMA_LPUART4_PADDR           , /* .end = */ DMA_LPUART4_PADDR + ( 16 << PAGE_BITS)}, /* 64KB */
{ /* .start = */ DMA_LPUART3_PADDR           , /* .end = */ DMA_LPUART3_PADDR + ( 16 << PAGE_BITS)}, /* 64KB */
{ /* .start = */ DMA_LPUART2_PADDR           , /* .end = */ DMA_LPUART2_PADDR + ( 16 << PAGE_BITS)}, /* 64KB */
{ /* .start = */ DMA_LPUART1_PADDR           , /* .end = */ DMA_LPUART1_PADDR + ( 16 << PAGE_BITS)}, /* 64KB */
{ /* .start = */ DMA_LPUART0_PADDR           , /* .end = */ DMA_LPUART0_PADDR + ( 16 << PAGE_BITS)}, /* 64KB */
{ /* .start = */ Dblog_GIC_PADDR             , /* .end = */ Dblog_GIC_PADDR   + ( 2 << 20)},  /* 2MB */
{ /* .start = */ Dblog_SMMU_PADDR            , /* .end = */ Dblog_SMMU_PADDR  + ( 4 << 20)},  /* 4MB */
{ /* .start = */ Dblog_STM_PADDR             , /* .end = */ Dblog_STM_PADDR   + ( 2 << 20)},  /* 2MB */
{ /* .start = */ Dblog_LPCG_PADDR            , /* .end = */ Dblog_LPCG_PADDR  + ( 16 << PAGE_BITS)}, /* 64KB */
{ /* .start = */ GPT0_PADDR                  , /* .end = */ GPT0_PADDR   + ( 1 << PAGE_BITS)},
{ /* .start = */ GPT1_PADDR                  , /* .end = */ GPT1_PADDR   + ( 1 << PAGE_BITS)},
{ /* .start = */ GPT2_PADDR                  , /* .end = */ GPT2_PADDR   + ( 1 << PAGE_BITS)},
{ /* .start = */ GPT3_PADDR                  , /* .end = */ GPT3_PADDR   + ( 1 << PAGE_BITS)},
{ /* .start = */ GPT4_PADDR                  , /* .end = */ GPT4_PADDR   + ( 1 << PAGE_BITS)},
};

/* Handle a platform-reserved IRQ. */
static inline void
handleReservedIRQ(irq_t irq)
{
}

#endif /* __PLAT_MACHINE_HARDWARE_H */
