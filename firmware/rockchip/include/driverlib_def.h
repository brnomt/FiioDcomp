/*
 * driverlib_def.h — RKnanoC SoC register definitions (minimal build set).
 *
 * Derived from: docs/memory-map.md (SoC base 0x20000000), bootloader analysis
 * (CRU @ 0x20000000), SDK usage (cru2.c, interrupt2.c, dma2.c) and the
 * RKnano datasheet layout (Rockchip clock/peripheral block standard).
 *
 * This is the MINIMAL set needed to compile the SDK. Register fields are
 * refined from Ghidra decompilation as each driver is integrated.
 */
#ifndef DRIVERLIB_DEF_H
#define DRIVERLIB_DEF_H

#include <stdint.h>
#include "armcc_compat.h"

/* ================= SoC peripheral bases ================= */
#define RKNANO_CRU_BASE      0x20000000UL   /* Clock & Reset Unit */
#define RKNANO_INTC_BASE     0x400B0000UL   /* Interrupt controller */

/* ================= CRU (Clock & Reset Unit) ================= */
typedef struct {
    volatile uint32_t CRU_APLL_CON[6];      /* +0x000 APLL config */
    volatile uint32_t CRU_DPLL_CON[6];      /* +0x018 DPLL config */
    volatile uint32_t CRU_GPLL_CON[6];      /* +0x030 GPLL config */
    volatile uint32_t CRU_CPLL_CON[6];      /* +0x048 CPLL config */
    volatile uint32_t CRU_MODE_CON;         /* +0x060 clock mode */
    volatile uint32_t CRU_CLKSEL_CON[32];   /* +0x064 clock selectors */
    volatile uint32_t CRU_CLKGATE_CON[8];  /* +0x0E4 clock gates */
    volatile uint32_t CRU_SOFTRST[8];       /* +0x104 soft resets */
    volatile uint32_t CRU_GLB_CNT_TH;       /* +0x124 */
    volatile uint32_t CRU_GLB_CNT;          /* +0x128 */
    volatile uint32_t CRU_GLB_RST_ST;       /* +0x12C */
    volatile uint32_t CRU_GLB_SRST_FST;     /* +0x130 */
    volatile uint32_t CRU_GLB_SRST_SND;     /* +0x134 */
} RKNANO_CRU;

#define CRU ((volatile RKNANO_CRU *)RKNANO_CRU_BASE)

/* APLL bit fields (cru2.c macros) */
#define APLL_REFDIV_SHIFT        0
#define APLL_REFDIV_MASK         0x0000003F
#define APLL_FBDIV_SHIFT         6
#define APLL_FBDIV_MASK          0x00000FFF
#define APLL_POSTDIV1_SHIFT      18
#define APLL_POSTDIV1_MASK       0x00000007
#define APLL_POSTDIV2_SHIFT      21
#define APLL_POSTDIV2_MASK       0x00000007
#define APLL_DSMPD_SHIFT         24
#define APLL_DSMPD_MASK          0x00000001
#define APLL_LOCK_SHIFT          31
#define APLL_LOCK_MASK           0x80000000

#define GPLL_REFDIV_SHIFT        0
#define GPLL_REFDIV_MASK         0x0000003F
#define GPLL_FBDIV_SHIFT         6
#define GPLL_FBDIV_MASK          0x00000FFF
#define GPLL_POSTDIV1_SHIFT      18
#define GPLL_POSTDIV1_MASK       0x00000007
#define GPLL_POSTDIV2_SHIFT      21
#define GPLL_POSTDIV2_MASK       0x00000007
#define GPLL_DSMPD_SHIFT         24
#define GPLL_DSMPD_MASK          0x00000001
#define GPLL_LOCK_SHIFT          31
#define GPLL_LOCK_MASK           0x80000000

/* ================= Interrupt controller ================= */
#define INTC_ISR                 (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x00))
#define INTC_IPR                 (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x04))
#define INTC_IER                 (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x08))
#define INTC_ISR_SET             (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x0C))
#define INTC_IPR_SET             (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x10))
#define INTC_IER_SET             (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x14))
#define INTC_ICR                 (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x18))
#define INTC_IPR_CLEAR           (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x1C))
#define INTC_IER_CLEAR           (*(volatile uint32_t *)(RKNANO_INTC_BASE + 0x20))

/* ================= System registers (misc) ================= */
#define SYS_CRU_BASE             RKNANO_CRU_BASE
#define SYS_INTC_BASE            RKNANO_INTC_BASE

#endif /* DRIVERLIB_DEF_H */

/* ---- CRU clock gate / soft-reset enums (cru2.c) ---- */
#ifndef DRIVERLIB_CRU_ENUMS
#define DRIVERLIB_CRU_ENUMS
typedef enum {
    GATE_ACLK_CPU = 0, GATE_HCLK_CPU, GATE_PCLK_CPU,
    GATE_ACLK_PERI, GATE_HCLK_PERI, GATE_PCLK_PERI,
    GATE_ACLK_DSP, GATE_HCLK_DSP, GATE_PCLK_DSP,
    GATE_ACLK_SDMMC, GATE_HCLK_SDMMC, GATE_ACLK_USB, GATE_HCLK_USB,
    GATE_ACLK_I2S, GATE_HCLK_I2S, GATE_PCLK_I2C, GATE_PCLK_UART,
    GATE_ACLK_SPI, GATE_PCLK_SPI, GATE_PCLK_PWM, GATE_PCLK_SARADC,
    GATE_ACLK_LCDC, GATE_DCLK_LCDC, GATE_ACLK_GPU, GATE_ACLK_VEPU,
    GATE_ACLK_VDPU, GATE_HCLK_VIO, GATE_PCLK_VIO, GATE_ACLK_CIF, GATE_HCLK_CIF,
    GATE_ACLK_HDMI, GATE_PCLK_HDMI, GATE_ACLK_EMMC, GATE_HCLK_EMMC,
    GATE_MAX
} eCLOCK_GATE;

typedef enum {
    RST_ACLK_CPU = 0, RST_HCLK_CPU, RST_PCLK_CPU,
    RST_ACLK_PERI, RST_HCLK_PERI, RST_PCLK_PERI,
    RST_ACLK_DSP, RST_HCLK_DSP, RST_PCLK_DSP,
    RST_ACLK_SDMMC, RST_HCLK_SDMMC, RST_ACLK_USB, RST_HCLK_USB,
    RST_ACLK_I2S, RST_HCLK_I2S, RST_PCLK_I2C, RST_PCLK_UART,
    RST_ACLK_SPI, RST_PCLK_SPI, RST_PCLK_PWM, RST_PCLK_SARADC,
    RST_ACLK_LCDC, RST_DCLK_LCDC, RST_ACLK_GPU, RST_ACLK_VEPU,
    RST_ACLK_VDPU, RST_HCLK_VIO, RST_PCLK_VIO, RST_ACLK_CIF, RST_HCLK_CIF,
    RST_ACLK_HDMI, RST_PCLK_HDMI, RST_ACLK_EMMC, RST_HCLK_EMMC,
    RST_MAX
} eSOFT_RST;
#endif

/* ---- CPU frequency type (Delay2.c) ---- */
#ifndef DRIVERLIB_FREQ
#define DRIVERLIB_FREQ
typedef enum {
    CHIP_FREQ_24M = 0,
    CHIP_FREQ_48M,
    CHIP_FREQ_96M,
    CHIP_FREQ_120M,
    CHIP_FREQ_144M,
    CHIP_FREQ_192M,
    CHIP_FREQ_MAX
} chip_freq_t;
#endif
