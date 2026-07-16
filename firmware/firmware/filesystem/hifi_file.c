/*
 * firmware/firmware/filesystem/hifi_file.c
 * HifiFile IPC wrappers — post cmd to FS task, wait with timeout.
 *
 * Pattern: ipc_post_cmd(opcode) + ipc_post_arg(params) then spin on
 * a completion flag via hifi_busy_delay(1). On timeout, hifi_debug_printf.
 *
 * Observed opcodes: Seek=0x69, Read=0x6b.
 * Open/Write/Close timeout strings exist in the binary but were not
 * linked to recovered functions in this pass (likely dead or overlay-only).
 *
 * A second copy of Seek/Read lives in an overlay at 0x03080e96 / 0x03080efc.
 */

#include <stdint.h>
#include <stddef.h>

#include "fs_layer.h"

/* IPC mailbox helpers @ 0x03073c7c / 0x03073ca8 */
extern int ipc_post_cmd(uint32_t opcode, int slot, int bank);
extern int ipc_post_arg(void *arg, int slot, int bank);

extern void hifi_busy_delay(int ticks);
extern void hifi_debug_printf(const char *fmt, ...);
extern void hifi_memmove(void *dst, const void *src, uint32_t n);

/* Shared mailbox / status (addresses from Ghidra DAT_* — interpretive) */
extern volatile uint32_t *g_hifi_seek_mbox;   /* DAT_0306bbb0 */
extern volatile char     *g_hifi_seek_done;   /* mbox - 10 */
extern volatile uint8_t  *g_hifi_seek_status; /* DAT_0306bbb4 */
extern uint32_t          *g_hifi_pos_table;   /* DAT_0306bbac */
extern int                g_hifi_timeout_iters; /* DAT_0306bb90 */

extern volatile uint32_t *g_hifi_read_mbox;   /* DAT_0306bbd0 */
extern volatile char     *g_hifi_read_done;   /* mbox - 0xd */

#define HIFI_OPC_SEEK  0x69
#define HIFI_OPC_READ  0x6b

/*
 * HifiFileSeek @ 0x0306b8e6
 * Posts seek request; updates per-fd position table on completion.
 */
uint8_t HifiFileSeek(uint32_t offset, uint32_t whence, uint8_t fd)
{
    volatile uint32_t *mbox = g_hifi_seek_mbox;
    volatile char *done = (volatile char *)((uintptr_t)mbox - 10);

    mbox[0] = offset;
    mbox[1] = whence;
    *(volatile uint8_t *)&mbox[2] = fd;
    *done = 0;

    ipc_post_cmd(HIFI_OPC_SEEK, 0, 2);
    ipc_post_arg((void *)mbox, 0, 2);

    if (*done == 0) {
        hifi_busy_delay(1);
        int left = g_hifi_timeout_iters;
        do {
            if (*done != 0)
                break;
            hifi_busy_delay(1);
        } while (--left != 0);
        if (*done == 0)
            hifi_debug_printf("HifiFileSeek: timeout!!");
    }

    g_hifi_pos_table[fd] = mbox[0];
    *done = 0;
    return *g_hifi_seek_status;
}

/*
 * HifiFileRead @ 0x0306b94c
 * Returns bytes read (status word); 0 if pre-check fails.
 */
uint32_t HifiFileRead(uint32_t buf, uint32_t len, uint8_t fd)
{
    volatile uint32_t *mbox = g_hifi_read_mbox;
    volatile char *done = (volatile char *)((uintptr_t)mbox - 0xd);

    mbox[0] = buf;
    mbox[1] = len;
    *(volatile uint8_t *)&mbox[2] = fd;
    *done = 0;

    ipc_post_cmd(HIFI_OPC_READ, 0, 2);
    ipc_post_arg((void *)mbox, 0, 2);

    if (*(volatile char *)((uintptr_t)mbox - 0x33) == 0)
        return 0;

    if (*done == 0) {
        hifi_busy_delay(1);
        int left = g_hifi_timeout_iters;
        do {
            if (*done != 0)
                break;
            hifi_busy_delay(1);
        } while (--left != 0);
        if (*done == 0)
            hifi_debug_printf("HifiFileRead: timeout!!");
    }

    g_hifi_pos_table[fd] = mbox[1];
    *done = 0;
    return *(volatile uint32_t *)g_hifi_seek_status;
}

/* Overlay copies (same logic, different globals) @ 0x03080e96 / 0x03080efc */
uint8_t  HifiFileSeek_ovl(uint32_t offset, uint32_t whence, uint8_t fd);
uint32_t HifiFileRead_ovl(uint32_t buf, uint32_t len, uint8_t fd);
