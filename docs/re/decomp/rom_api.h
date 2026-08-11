/*
 * firmware/rom_api.h
 * Boot ROM API @ 0x02FE0000–0x02FFFFFF (RKnanoC internal ROM)
 *
 * For host compile / link tests, implementations are weak stubs in
 * stubs/rom_api_stubs.c. On device, replace with absolute-address
 * thunks or omit stubs so calls land in ROM.
 *
 * Addresses from docs/memory-map.md + Ghidra v3.7.0 cross-refs.
 */

#ifndef ROM_API_H
#define ROM_API_H

#include <stdint.h>
#include <stddef.h>

/* --- Boot / heap -------------------------------------------------------- */
void *rom_alloc(uint32_t size);                         /* 0x02feeedc */
void  rom_hw_init(uint32_t code);                       /* 0x02feeebe */
void  rom_hw_init2(uint32_t code);
void  rom_early_init(void);                             /* 0x02fe860e */

/* --- Memory ------------------------------------------------------------- */
void  rom_memcpy(void *dst, const void *src, uint32_t len);   /* 0x02ff952e */
void  rom_memzero(uint32_t addr, uint32_t len);               /* 0x02ff957c */
void *rom_mem_alloc(uint32_t base, uint32_t size);
int   rom_memcmp(const void *a, const void *b, int n);
int   rom_memcmp_n(const void *a, const void *b, int n);
int   rom_memmem(const void *hay, const void *needle, int n);
int   rom_strcmp(const char *a, const char *b);
void  rom_dma_or_copy(uint32_t a, uint32_t b);                /* 0x02ff63d2 */

/* --- Audio / DAC / I2S -------------------------------------------------- */
void  rom_audio_cleanup(void);
void  rom_peripheral_reset(void);
void  rom_i2s_master_config(void);                      /* 0x02ff5752 */
void  rom_i2s_master_init(int a, int b, int c, int d);
void  rom_dma_buffer_config(void);
void  rom_dma_config(int ch, int mode);                 /* 0x02ff6814 */
void  rom_dma_channel_set(int ch, int mode);
void  rom_dac_gain_set(uint32_t gain);
void  rom_dac_gain_set_channel(int ch, uint32_t gain);
void  rom_buffer_calculate(uint32_t *size, uint32_t *count);
int   rom_buffer_ready(int id);                         /* 0x02ffa224 */
void  rom_dma_set_source(uint32_t buf, uint32_t count, uint32_t src);
void  rom_clock_divider_set(void);
void  rom_pll_reconfig(void);
void  rom_audio_path_set_441(uint8_t mode);
void  rom_dac_output_enable(uint8_t mode);
void  rom_audio_path_set(int a, int b, int c);
void  rom_audio_path_enable(int a, int b, int c);
void  rom_audio_path_select(int a, int b, int c);
void  rom_audio_path_disable(int a, int b);
void  rom_playback_start(int a, int b, int c, uint32_t rate); /* 0x02ffa410 */
void  rom_dma_start(int ch, uint32_t buf, uint32_t dest, uint32_t count);
void  rom_bt_playback_init(void);
void  rom_volume_sync(void);
void  rom_dac_unmute(int a, int b);                     /* 0x02ff4580 */
void  rom_dac_mute(int ch, int sub);                    /* 0x02ff44ce */
void  rom_audio_clock_off(void);                        /* 0x02ff5c30 */
void  rom_sample_rate_set(int a, int b, int c, uint32_t rate);
void  rom_dsp_param_set(uint32_t rate, uint32_t samples);
void  rom_dsp_start(void);                              /* 0x02ff55c0 */
void  rom_dsp_bypass_disable(void);                     /* 0x02ff55ba */
void  rom_i2s_channel_setup(int ch, uint32_t clock);
void  rom_i2s_format_set(int a, int fmt);
void  rom_i2s_dma_start(int a, int b);                  /* 0x02ff68f0 */
int   rom_bt_stream_open(void *addr, int mode);
void  rom_dac_volume_set(uint8_t vol);
void  rom_dac_output_config(uint32_t cfg);
void  rom_dac_commit(uint8_t val);
void  rom_spi_write_reg(uint32_t a, uint32_t b, uint32_t c);
void  rom_spi_send(int n);
void  rom_display_update(void *cmd);
void  rom_ogg_picture_init(const char *tag);

/* --- Files -------------------------------------------------------------- */
int   rom_file_open(uint32_t addr, uint32_t size, int index);
void  rom_file_close(int fd);
int   rom_file_load_block(int fd, void *buf);
int   rom_file_read_sync(int fd, uint32_t offset);
void  rom_file_seek(int off, int whence, int fd);
int   rom_file_read(void *buf, int n, int fd);
int   rom_file_size(int fd);
int   rom_file_tell(int fd);

/* --- USB ---------------------------------------------------------------- */
int   rom_usb_stream_open(void *dev, int mode);
int   rom_usb_query(void);
void  rom_usb_set_mode(uint8_t mode);
void  rom_usb_status(int a, int b);

/* --- UI / events -------------------------------------------------------- */
int   rom_get_input_event(void);
int   rom_gui_check_area(int x1, int y1, int x2, int y2, int unused);
int   rom_event_pending(int id);
void  rom_event_clear_id(int id);
void  rom_post_event(int id);
void  rom_ui_cmd(int cmd, void *arg);
void  rom_draw_glyph(void *a, void *b, void *msg);
void  rom_lcd_refresh(void *ctx);
int   rom_event_clear_bit(int id);
void  rom_status_led(int a, int b);
void  debug_printf(const char *fmt, ...);

/* --- Storage / keys ----------------------------------------------------- */
int   rom_storage_cmp(void *a, void *b);
void  rom_storage_copy(void *a, void *b);
void  rom_key_remap_apply(void);
char  rom_set_key_mode(uint8_t mode);
void  rom_draw_dialog(void *a, void *b, void *msg);
void  rom_key_remap_done(void);

/* --- BT display --------------------------------------------------------- */
uint32_t rom_audio_save(int mode);
uint32_t rom_dsp_save(int mode);
int   rom_bt_event_check(int id);
void  rom_bt_processing_start(int id);
void  rom_bt_display_lock(int on);
void  rom_bt_display_default(int a, int b, int c, int d, int e, int f);
int   rom_bt_metadata_ready(int id);
void  rom_bt_copy_track_name(void *dst, int idx, void *unused);
void  rom_bt_display_set(int a, int b, int c);
uint32_t rom_bt_string_len(const char *s);
void  rom_bt_display_error(int id);
void  rom_bt_display_complete(int *x, int a, void *disp, int b);
void  rom_bt_display_clear(int id);
void  rom_bt_display_next(int *x, int *y, const char *name, int z);
void  rom_bt_display_commit(void *disp);
void  rom_bt_display_unlock(int on);

/* --- Record ------------------------------------------------------------- */
int   rom_record_file_exists(void *path, uint32_t size);
void  rom_record_start(void *a, void *b, void *c, void *d);

/* --- Bitstream / codec helpers (ROM or linked blobs) -------------------- */
uint32_t rom_bitstream_read(uint32_t ctx, int nbits);
int32_t  rom_bitstream_read_signed(uint32_t ctx, int nbits);
uint32_t rom_peek_byte(uint32_t ctx, int bit_pos);
int      rom_clz(uint32_t v);

/* --- MAD / MP3 ROM helpers ---------------------------------------------- */
void  rom_mad_init(void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h);
void  rom_mad_header_init(void);
void  rom_mad_layer3_init(void *buf);
void  rom_mad_huffman_init(void *buf);
void  rom_mad_start(void *a, void *b);
int   rom_mad_decode_frame(void *a, void *b);
int   rom_mad_bitstream_fill(void *a, void *b, void *c, void *d);
int   rom_mad_header_sync(void *a, void *b, void *c, void *d);
void  rom_mad_cleanup(void);
uint32_t rom_mad_bitrate_calc(uint32_t a, uint32_t b);

#endif /* ROM_API_H */
