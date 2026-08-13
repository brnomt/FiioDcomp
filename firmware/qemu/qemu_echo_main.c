/* qemu_echo_main.c — ReChord QEMU test: run OUR REAL firmware logic
 * (rechord_firmware_entry + Main2 heartbeat) in QEMU mps2-an385.
 *
 * Compiles the REAL firmware sources with -DRECHORD_QEMU_TEST:
 *   - firmware/rechord_app.c         (rechord_firmware_entry, V0.15 init)
 *   - firmware/rockchip/bbsystem/Main2.c  (Main2 + the V0.17 heartbeat)
 *   - firmware/stubs.c               (weak link stubs: MailBox*, bb_printf1)
 * plus this file: vector table, ROM stubs, Main2 support stubs.
 *
 * What is verified (telemetry readable via the QEMU monitor):
 *   1. rechord_firmware_entry(mode=0xb) returns 0x191 and runs the EXACT
 *      stock ROM-init sequence (rom_alloc(0x1dc) -> rom_hw_init(0x1dc,
 *      0x16f,0x16f) -> rom_hw_init2(0x171) -> rom_hw_init(0x170) ->
 *      rom_early_init), writes the boot layout (base=8, mode_clamped=0xb)
 *      and the 'BOOT'/BOOT_DONE telemetry.
 *   2. rechord_firmware_entry(mode=0x5) returns 0x18f (early path).
 *   3. Main2() reaches its heartbeat loop: the whole framebuffer is
 *      written red/black, the ROM display calls fire (wait/ctx/color/
 *      rect/refresh), and the BOOT_DONE marker is written.
 *
 * Telemetry layout (QEMU RAM @0x20000000, 4 MB):
 *   0x20008000  crash log      (fault handler, if anything faults)
 *   0x20008018  boot log       (redirected boot_log; [2] = BOOT_DONE)
 *   0x20008040  test results   (res[0..8])
 *   0x20008064  boot layout    (redirected lay/bmode)
 *   0x20008080  ROM-init trace (rechord_firmware_entry's ROM calls)
 *   0x200080A0  ROM-display trace (Main2 heartbeat's ROM display calls)
 *   0x200080C0  ROM-init trace counter, 0x200080C4 display trace counter
 *   0x2000F000  rom_alloc return value
 *   0x20010000  framebuffer    (redirected fb, 320*170 RGB565)
 *   stack @ 0x203FFFF0 (top of RAM)
 */
#include <stdint.h>

/* ---------------- telemetry (fixed addresses, outside BB_SYS_DATA) ------ */
#define CRASH_LOG    ((volatile uint32_t *)0x20008000u)
#define BOOT_LOG     ((volatile uint32_t *)0x20008018u)
#define TEST_RES     ((volatile uint32_t *)0x20008040u)
#define LAY_ADDR     ((volatile uint8_t  *)0x20008080u)
#define BMODE_ADDR   ((volatile uint16_t *)0x20008084u)
#define ROM_INIT_TR  ((volatile uint32_t *)0x200080A0u)   /* 16 words (14 used) */
#define ROM_DISP_TR  ((volatile uint32_t *)0x20008100u)   /* 256 words (8/iter) */
#define RI_N         (*(volatile uint32_t *)0x20008500u)
#define RD_N         (*(volatile uint32_t *)0x20008504u)
#define QEMU_FB      ((volatile uint16_t *)0x20010000u)
#define ROM_ALLOC_RET ((void *)0x2000F000u)

/* ---------------- real firmware entry points ----------------------------- */
extern uint32_t rechord_firmware_entry(void *param);
extern int Main2(void);
extern void rechord_main(void);

/* ---------------- vector table + fault handler --------------------------- */
void fault_c(uint32_t sp, uint32_t pc)   /* non-static: naked asm branches to it */
{
    CRASH_LOG[0] = 0x52454348u;   /* 'RECH' */
    CRASH_LOG[1] = pc;
    CRASH_LOG[2] = sp;
    for (;;) ;
}

__attribute__((naked)) void hardfault_handler(void)
{
    __asm__ volatile(
        "mov r0, sp\n"
        "ldr r1, [r0, #24]\n"
        "b  fault_c\n");
}

/* ---------------- ROM stubs (redirected under RECHORD_QEMU_TEST) --------- */
void *rch_qemu_rom_alloc(uint32_t size)
{
    ROM_INIT_TR[RI_N++] = 0x10000000u | size;   /* alloc */
    return ROM_ALLOC_RET;
}
void rch_qemu_rom_hw_init(uint32_t code)
{
    ROM_INIT_TR[RI_N++] = 0x20000000u | code;   /* hw_init */
}
void rch_qemu_rom_hw_init2(uint32_t code)
{
    ROM_INIT_TR[RI_N++] = 0x30000000u | code;   /* hw_init2 */
}
void rch_qemu_rom_early_init(void)
{
    ROM_INIT_TR[RI_N++] = 0x40000000u;          /* early_init */
}
uint32_t rch_qemu_rom_wait(uint32_t code)
{
    ROM_DISP_TR[RD_N++] = 0x10000000u | code;   /* wait: ready (return 0) */
    return 0;
}
uint32_t rch_qemu_rom_ctx(uint32_t v)
{
    ROM_DISP_TR[RD_N++] = 0x20000000u | v;      /* save/set ctx -> returns v */
    return v;
}
void rch_qemu_rom_color(uint32_t c)
{
    ROM_DISP_TR[RD_N++] = 0x30000000u | c;      /* set color */
}
void rch_qemu_rom_rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h,
                       uint32_t a5, uint32_t a6)
{
    ROM_DISP_TR[RD_N++] = 0x40000000u | (w & 0xFFFFu) |
                          ((h & 0xFFu) << 16);   /* fill rect (w + h<<16) */
    (void)x; (void)y; (void)a5; (void)a6;
}
void rch_qemu_rom_refresh(uint32_t v)
{
    ROM_DISP_TR[RD_N++] = 0x50000000u | v;      /* refresh */
}

/* ---------------- Main2 support stubs (no hardware in QEMU) -------------- */
void BSP_Init2(void)
{
    ROM_INIT_TR[RI_N++] = 0x51000000u;          /* marker: BSP_Init2 called */
}
void ClearMsg(uint32_t m) { (void)m; }
uint32_t GetMsg(uint32_t m) { (void)m; return 0; }
void MemSet2(uint8_t *trg, int data, uint32_t len)
{ while (len--) *trg++ = (uint8_t)data; }
void IntMasterDisable2(void) { __asm volatile("cpsid i" ::: "memory"); }
void IntMasterEnable2(void)  { __asm volatile("cpsie i" ::: "memory"); }
void IntRegister2(int id, void *fn) { (void)id; (void)fn; }
void IntPendingClear2(int id) { (void)id; }
void IntEnable2(int id) { (void)id; }
void RKFileFuncInit2(void) { }
void AudioFileFuncInit2(void) { }
void AudioHWInit2(void) { }
void AudioHWDeInit2(void) { }
void AudioIntAndDmaInit2(void) { }
void AudioIntAndDmaDeInit2(void) { }
void AudioFileChangeBuf2(void) { }
void AudioFileInput2(void) { }
uint32_t AudioCodecGetBufferSize2(void) { return 0; }

void *memset(void *s, int c, uint32_t n)
{ uint8_t *p = (uint8_t *)s; while (n--) *p++ = (uint8_t)c; return s; }

/* ---------------- globals Main2.o references (not in stubs.c) ------------ */
typedef struct {
    unsigned char *pData;
    unsigned int  NumBytes;
    unsigned char handle;
} FILE_READ_OP_t;
typedef unsigned char FILE;               /* opaque; only FILE* is used */

uint32_t AudioFileBufBusy2;
uint32_t AudioFileBufSize2[2];
uint32_t AudioFileWrBufID2;
uint32_t CodecBufSize2;
uint32_t CurFileOffset[8];
uint32_t FileTotalSize;
uint8_t  gBufByPass;
uint8_t  gCmdDone;
FILE_READ_OP_t gFileReadParam;
FILE *pRawFileCache;

/* ---------------- _start: the test --------------------------------------- */
void _start(void)
{
    volatile uint32_t *res = TEST_RES;
    uint32_t r;

    res[0] = 0x00000001u;              /* start reached */

    /* ---- Test 1: rechord_firmware_entry, boot mode 0xb -> expect 0x191 -- */
    {
        uint16_t mode = 0x000b;
        r = rechord_firmware_entry(&mode);
        res[0] = 0x11110000u | (r & 0xFFFFu);
        res[5] = *BMODE_ADDR;          /* boot mode written = 0xb */
    }
    /* ---- Test 2: rechord_firmware_entry, boot mode 0x5 -> expect 0x18f - */
    {
        uint16_t mode = 0x0005;
        r = rechord_firmware_entry(&mode);
        res[1] = 0x22220000u | (r & 0xFFFFu);
    }
    res[2] = BOOT_LOG[0];              /* 'BOOT' = 0x424F4F54 */
    res[3] = BOOT_LOG[2];              /* BOOT_DONE = 0xfeed0002 */
    res[4] = LAY_ADDR[0];              /* layout base = 8 */
    res[6] = ROM_INIT_TR[0];           /* first ROM call = alloc(0x1dc) */
    res[7] = ROM_INIT_TR[6];           /* last ROM call of test1 = early_init */

    /* ---- Test 3: rechord_main (M1 app main: ScatterLoader2 + BSP_Init2
     *              + UI draw loop via the ROM display API) ---- */
    {
        uint32_t i;
        for (i = 0; i < (320 * 170) / 2; i++)
            QEMU_FB[i] = 0x0000u;      /* clear fb so a later non-zero = ours */
    }
    res[8] = 0x33330000u;              /* about to call rechord_main */
    rechord_main();                    /* never returns */

    res[9] = 0xDEADBEEFu;              /* unreachable */
    for (;;) ;
}

__attribute__((section(".vectors"), used, aligned(256)))
const uint32_t vectors[8] = {
    0x203FFFF0u,                     /* initial MSP (top of RAM) */
    (uint32_t)_start,                /* reset */
    (uint32_t)hardfault_handler + 1, /* NMI */
    (uint32_t)hardfault_handler + 1, /* HardFault */
    (uint32_t)hardfault_handler + 1, /* MemManage */
    (uint32_t)hardfault_handler + 1, /* BusFault */
    (uint32_t)hardfault_handler + 1, /* UsageFault */
    0,
};
