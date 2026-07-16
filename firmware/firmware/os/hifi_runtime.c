/*
 * firmware/firmware/os/hifi_runtime.c
 * Low-level runtime used by HifiFile / codec overlays.
 *
 *   hifi_memmove       @ 0x0306d330
 *   hifi_busy_delay    @ 0x0306c2e8
 *   hifi_debug_printf  @ 0x0306c07e  (overlay twin @ 0x030ab6b6)
 *   ipc_post_cmd       @ 0x03073c7c
 *   ipc_post_arg       @ 0x03073ca8
 *   MediaLib_GetTotalFiles @ 0x03000f94 (+ _b/_c/_d clones, MediaLib_thunk_GetFiles)
 *
 *   dac_gain_curve_apply @ 0x030098e4 (formerly misnamed os_delay_ms)
 *   event_set/clear      @ 0x03073840 / 0x03073882 — bitset (not 0x0300c6b4/f6)
 */

#include <stdint.h>
#include <stdarg.h>

extern uint32_t g_tick_scale_a; /* DAT_0306c364.. */
extern uint32_t g_tick_scale_b;
extern uint32_t g_tick_scale_c;
extern uint32_t g_tick_now;

extern uint8_t *g_ipc_base; /* DAT_03073d2c — array of 0x50-byte slots */

extern int hifi_vsnprintf(char *dst, uint32_t cap, const char *fmt, void *args);
extern void hifi_uart_write(void *port, const void *buf, uint32_t n);

/* hifi_memmove @ 0x0306d330 */
void hifi_memmove(void *dst, const void *src, uint32_t n)
{
    uint8_t *d = (uint8_t *)dst;
    const uint8_t *s = (const uint8_t *)src;
    if (n <= (uint32_t)(d - s)) {
        if ((((uintptr_t)d | (uintptr_t)s) & 3) == 0) {
            while (n > 3) {
                *(uint32_t *)d = *(const uint32_t *)s;
                d += 4;
                s += 4;
                n -= 4;
            }
        }
        while (n--)
            *d++ = *s++;
        return;
    }
    d += n;
    s += n;
    while (n--) {
        *--d = *--s;
    }
}

/* hifi_busy_delay @ 0x0306c2e8 — calibrated spin */
void hifi_busy_delay(int param_1)
{
    uint32_t u =
        (uint32_t)(((uint64_t)g_tick_scale_c *
                    (uint64_t)((*(uint32_t *)(g_tick_now + 0x20) / g_tick_scale_b) *
                              (uint32_t)param_1)) >>
                   0x22);
    if (u == 0)
        return;
    do {
        /* empty spin */
    } while (--u != 0);
}

/* ipc_post_cmd @ 0x03073c7c — write opcode into slot bank */
int ipc_post_cmd(uint32_t opcode, int slot, int bank)
{
    uint8_t *row = g_ipc_base + slot * 0x50;
    if (bank == 0)
        *(uint32_t *)(row + 0x30) = opcode;
    else if (bank == 1)
        *(uint32_t *)(row + 0x38) = opcode;
    else if (bank == 2)
        *(uint32_t *)(row + 0x40) = opcode;
    else if (bank == 3)
        *(uint32_t *)(row + 0x48) = opcode;
    return 0;
}

/* ipc_post_arg @ 0x03073ca8 — write arg pointer beside opcode */
int ipc_post_arg(void *arg, int slot, int bank)
{
    uint8_t *row = g_ipc_base + slot * 0x50;
    if (bank == 0)
        *(void **)(row + 0x34) = arg;
    else if (bank == 1)
        *(void **)(row + 0x3c) = arg;
    else if (bank == 2)
        *(void **)(row + 0x44) = arg;
    else if (bank == 3)
        *(void **)(row + 0x4c) = arg;
    return 0;
}

/*
 * hifi_debug_printf @ 0x0306c07e
 * Prefixes "[Bxx.xx.xx.xx]" timestamp then formats message to UART.
 */
void hifi_debug_printf(const char *fmt, ...)
{
    /* Timestamp digit extraction + UART write — see Ghidra for full body.
       Overlay twin: hifi_debug_printf_ovl @ 0x030ab6b6 */
    (void)fmt;
}

/*
 * MediaLib_GetTotalFiles @ 0x03000f94
 * Returns playlist/library file count for the current browse mode.
 * Prints "totalFmfile = %d" for modes 8/0xc.
 */
uint16_t MediaLib_GetTotalFiles(void)
{
    extern uint16_t *g_ml_state; /* DAT_0300161c / 20 / 24 */
    /* Mode switch table in Ghidra; returns ushort count. */
    return 0;
}
