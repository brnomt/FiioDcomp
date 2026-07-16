/*
 * firmware/firmware/os/bitreader.c
 * Shared bitstream helpers used by codecs (MP3 / AAC / etc.).
 *
 *   bitreader_peek     @ 0x0301e724  (157-xref sibling cluster)
 *   bitreader_refill   @ 0x0301e760  (top xref unlabeled → now named)
 *   bitstream_getbits  @ 0x030b15ca
 *   mp3_bitstream_getbits @ 0x0302837a
 */

#include <stdint.h>

typedef struct {
    uint32_t cache;       /* [0] current bit cache */
    uint32_t next;        /* [1] next word (BE-swapped) */
    uint32_t _pad2;
    int32_t  bits_left;   /* [3] bits remaining in cache */
    uint8_t *ptr;         /* [4] read pointer into window */
    uint8_t *base;        /* [5] window base */
    uint32_t avail;       /* [6] bytes available in window */
    uint32_t _pad7;
    uint32_t eof;         /* [8] EOF / status */
} BitReader;

extern int bitreader_fill_window(uint8_t *dst, uint32_t want, uint32_t *status);
extern void rom_dma_or_copy(uint32_t a, uint32_t b); /* func_0x02ff63d2 */

/* bitreader_peek @ 0x0301e724 — peek `nbits` without consuming (approx) */
uint32_t bitreader_peek(BitReader *br, int nbits)
{
    uint32_t left = (uint32_t)br->bits_left;
    uint32_t shift = (uint32_t)(nbits - 0x20) + left;
    uint32_t hi = br->cache & (0xFFFFFFFFu >> (left & 0x1f));
    if ((int)shift > 0)
        return (br->next >> (0x20 - shift)) | (hi << (shift & 0x1f));
    return hi >> ((0x20 - left) - (uint32_t)nbits);
}

/* bitreader_refill @ 0x0301e760 — ensure >= 32 bits; pull BE words */
void bitreader_refill(BitReader *br, int need, uint32_t a, uint32_t b)
{
    int left = br->bits_left;
    br->bits_left = left + need;
    if ((uint32_t)(left + need) <= 0x1f)
        return;

    br->cache = br->next;
    if (br->avail < 5 && br->eof != 1) {
        if (br->avail != 0)
            rom_dma_or_copy((uint32_t)br->base, (uint32_t)br->ptr);
        uint32_t status = b;
        int n = bitreader_fill_window(br->base + br->avail, 0x2000, &status);
        br->eof = status;
        if (n == -1)
            n = 0;
        else if (n == 0)
            br->eof = 1;
        br->avail += (uint32_t)n;
        if (br->avail < 4)
            br->avail = 4;
        br->ptr = br->base;
    }
    uint32_t *p = (uint32_t *)br->ptr;
    br->ptr = (uint8_t *)(p + 1);
    uint32_t w = *p;
    br->avail -= 4;
    /* byteswap to host-order cache */
    br->next = (w << 24) | ((w >> 8) & 0xff) << 16 | ((w >> 16) & 0xff) << 8 | (w >> 24);
    br->bits_left -= 0x20;
}

/* bitstream_getbits @ 0x030b15ca — consume up to 31 bits from BE cache */
uint32_t bitstream_getbits(int ctx, uint32_t nbits)
{
    nbits &= 0x1f;
    uint32_t *cache = (uint32_t *)(ctx + 4);
    int *left = (int *)(ctx + 8);
    uint32_t v = *cache;
    *cache = v << nbits;
    uint32_t out = (v >> (0x1f - nbits)) >> 1;
    int rem = *left - (int)nbits;
    *left = rem;
    if (rem < 0) {
        extern void bitstream_refill_ctx(int ctx); /* FUN_030b1532 */
        bitstream_refill_ctx(ctx);
        out |= (*(uint32_t *)(ctx + 4)) >> (rem + 0x20);
        *(uint32_t *)(ctx + 4) <<= (uint32_t)(-rem);
        *left = *(int *)(ctx + 8) + rem;
    }
    return out;
}

/* bitstream_getbits_be @ 0x03070b0c — consume n bits from BE word stream */
uint32_t bitstream_getbits_be(int *ctx, int nbits)
{
    if (nbits == 0)
        return 0;
    uint32_t bitpos = (uint32_t)ctx[1];
    ctx[1] = (int)(bitpos + (uint32_t)nbits);
    uint32_t *word = (uint32_t *)(*ctx + (int)(bitpos >> 5) * 4);
    uint32_t w = *word;
    w = (w << 24) | ((w >> 8) & 0xff) << 16 | ((w >> 16) & 0xff) << 8 | (w >> 24);
    w <<= (bitpos & 0x1f);
    if ((bitpos & 0x1f) + (uint32_t)nbits > 0x20) {
        uint32_t w2 = word[1];
        w2 = (w2 << 24) | ((w2 >> 8) & 0xff) << 16 | ((w2 >> 16) & 0xff) << 8 | (w2 >> 24);
        return (w + (w2 >> (-(int)bitpos & 0x1f))) >> (0x20u - (uint32_t)nbits);
    }
    return w >> (0x20u - (uint32_t)nbits);
}

/* memset_byte @ 0x030bfa36 */
void memset_byte(uint8_t *dst, uint8_t val, uint32_t n)
{
    if (n == 0)
        return;
    uint8_t *p = dst - 1;
    if (n & 1) {
        *dst = val;
        p = dst;
    }
    n >>= 1;
    while (n--) {
        p[1] = val;
        p += 2;
        *p = val;
    }
}
