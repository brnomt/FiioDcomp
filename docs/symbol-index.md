# Echo Mini Firmware — Module Reference

## Labeled Functions (Ghidra custom-named grows each pass; 651/2,776 = 23.5%)

Phase goal: convert the entire IMG to C. Progress is tracked by custom-named
count vs total. New C files land under `firmware/` as symbols are named.

**SDK matching pass (Aug 2026):** Auto-analysis +21, similarity matching +8,
ROM API naming +7, functionality matching (constants) +85, structural matching
+195, combined matching +67, call graph propagation +80, additional matching +27. See `docs/sdk-matching-progress.md` for details.

**Boundary repair pending (do not trust oversized decomp bodies):**
`hifi_busy_delay_ovl_09e3`, `_0fd1`, `_0e48` — Ghidra body starts ~0xb00 before entry.
Needs `delete_function` + `create_function` at the true entry when approved.

### Entry & Init
| Name | Address | Tags |
|------|---------|------|
| `firmware_entry` | `0x03000010` | init, entry |
| `MusicInit` | `0x0302b9d8` | audio, init |
| `MusicService_Init` | `0x0302a3e0` | audio, init |
| `FormatList_Init` | `0x03013c10` | media, init |

### Boot ROM API (0x02FE0000–0x02FFFFFF)
| Name | Address | Tags |
|------|---------|------|
| `rom_early_init` | `0x02fe860e` | rom, init |
| `rom_hw_init` | `0x02feeebe` | rom, init |
| `rom_hw_init2` | `0x02feee7c` | rom, init |
| `rom_alloc` | `0x02feeedc` | rom, heap |
| `rom_dac_mute` | `0x02ff44ce` | rom, audio |
| `rom_dac_unmute` | `0x02ff4580` | rom, audio |
| `rom_dsp_bypass_disable` | `0x02ff55ba` | rom, dsp |
| `rom_dsp_start` | `0x02ff55c0` | rom, dsp |
| `rom_i2s_master_config` | `0x02ff5752` | rom, audio |
| `rom_audio_clock_off` | `0x02ff5c30` | rom, audio |
| `rom_dma_or_copy` | `0x02ff63d2` | rom, dma |
| `rom_dma_config` | `0x02ff6814` | rom, dma |
| `rom_i2s_dma_start` | `0x02ff68f0` | rom, dma |
| `rom_gui_check_area` | `0x02ff7e0a` | rom, ui |
| `rom_get_input_event` | `0x02ff813a` | rom, input |
| `rom_memcpy` | `0x02ff952e` | rom, memory |
| `rom_memzero` | `0x02ff957c` | rom, memory |
| `rom_buffer_ready` | `0x02ffa224` | rom, audio |
| `rom_playback_start` | `0x02ffa410` | rom, audio |
| `rom_audio_path_route` | `0x02ffa6f0` | rom, audio |
| `rom_audio_path_disable` | `0x02ffa72a` | rom, audio |
| `rom_usb_connect` | `0x02ffb2e0` | rom, usb |
| `rom_usb_disconnect` | `0x02ffb3e6` | rom, usb |
| `rom_post_event` | `0x02ffe648` | rom, event |
| `rom_event_clear_id` | `0x02ffe68a` | rom, event |
| `rom_event_pending` | `0x02ffe6a8` | rom, event |
| `rom_ui_cmd` | `0x02ffe872` | rom, ui |

### Audio Services
| Name | Address | Tags |
|------|---------|------|
| `AudioPlayback_Start` | `0x0302a398` | audio |
| `AudioPause` | `0x0302a69e` | audio, sdk match |
| `audiocodec_open` | `0x03029d0e` | audio, hardware |

### OS Primitives
| Name | Address | Tags |
|------|---------|------|
| `event_set` | `0x03073840` | os, event |
| `event_clear` | `0x03073882` | os, event |
| `event_test_and_clear` | `0x0307385c` | os, event |
| `dac_gain_curve_apply` | `0x030098e4` | audio, volume (**was** `os_delay_ms`) |
| `MediaLib_thunk_GetFiles` | `0x03012838` | media (**was** `debug_printf`) |
| `hifi_busy_delay` | `0x0306c2e8` | os, utility |
| `hifi_busy_delay_ovl_0817` | `0x0308175c` | os, overlay |
| `hifi_busy_delay_ovl_09e3` | `0x0309e334` | os, overlay (**body unsound**) |
| `hifi_busy_delay_ovl_0ab8` | `0x030ab880` | os, overlay |
| `hifi_busy_delay_ovl_0bff` | `0x030bff80` | os, overlay |
| `hifi_busy_delay_ovl_0dc7` | `0x030dc734` | os, overlay |
| `hifi_busy_delay_ovl_0e48` | `0x030e4808` | os, overlay (**body unsound**) |
| `hifi_busy_delay_ovl_0ed6` | `0x030ed650` | os, overlay |
| `hifi_busy_delay_ovl_0f53` | `0x030f5360` | os, overlay |
| `hifi_busy_delay_ovl_0fd1` | `0x030fd100` | os, overlay (**body unsound**) |
| `hifi_debug_printf` | `0x0306c07e` | os, utility |
| `hifi_debug_printf_ovl` | `0x030ab6b6` | os, utility |
| `hifi_debug_printf_ovl_09e0` | `0x0309e078` | os, overlay |
| `hifi_debug_printf_ovl_0dc5` | `0x030dc56a` | os, overlay |
| `hifi_debug_printf_sync_ovl_0e45` | `0x030e454c` | os, overlay |
| `log_printf_ts` | `0x030ed3e6` | os, logging |
| `hifi_memmove` | `0x0306d330` | os, utility |
| `memset_byte` | `0x030bfa36` | os, utility |
| `modinv_u32` | `0x0308fb94` | os, math |
| `softfloat_dmul_a` | `0x030f6622` | os, softfloat |
| `softfloat_dmul_b` | `0x030fe3c2` | os, softfloat |
| `softfloat_dadd_a` | `0x030f6a66` | os, softfloat |
| `softfloat_dadd_b` | `0x030fe806` | os, softfloat |
| `sbuf_read_bits` | `0x030ce930` | os, bitstream, sbuf |
| `sbuf_byte_at` | `0x030c6984` | os, bitstream, sbuf |
| `ipc_post_cmd` | `0x03073c7c` | os, ipc |
| `ipc_post_arg` | `0x03073ca8` | os, ipc |
| `bitreader_peek` | `0x0301e724` | os, bitstream |
| `bitreader_refill` | `0x0301e760` | os, bitstream |
| `bitstream_getbits` | `0x030b15ca` | os, bitstream |
| `bitstream_getbits_copy` | `0x030b1682` | os, bitstream (similarity match) |
| `bitstream_getbits_be` | `0x03070b0c` | os, bitstream |
| `bitstream_getbits_be_ovl_01c7` | `0x0301c7dc` | os, bitstream |
| `bitreader_get_u32_be` | `0x030f068c` | os, bitstream |
| `bitreader_get_u32_be_copy` | `0x030f05d8` | os, bitstream (similarity match) |
| `bitreader_get_u32_be_copy` | `0x030f064c` | os, bitstream (similarity match) |
| `bitreader_get_u32_be_copy_copy` | `0x030f061a` | os, bitstream (similarity match) |
| `saturate_s16` | `0x030b38e0` | os, math |
| `mp3_bitstream_getbits` | `0x0302837a` | os, bitstream, mp3 |
| `MediaLib_GetTotalFiles` | `0x03000f94` | media, library |
| `MediaLib_GetTotalFiles_b` | `0x03000fb0` | media, library |
| `MediaLib_GetTotalFiles_c` | `0x03000fd6` | media, library |
| `MediaLib_GetTotalFiles_d` | `0x03000ff4` | media, library |
| `ui_post_redraw` | `0x030037ea` | ui |
| `ui_refresh_and_redraw` | `0x03003808` | ui |
| `shared_frame_epilogue_c6b4` | `0x0300c6b4` | os (**bogus former event_set**) |
| `shared_mid_entry_c6f6` | `0x0300c6f6` | os (**bogus former event_clear**) |

### Filesystem — HifiFile / AudioFile
| Name | Address | Tags |
|------|---------|------|
| `HifiFileSeek` | `0x0306b8e6` | fs |
| `HifiFileRead` | `0x0306b94c` | fs |
| `HifiFileWrite` | `0x0306b9bc` | fs |
| `HifiFileClose` | `0x0306ba1e` | fs |
| `HifiFileSeek_ovl` | `0x03080e96` | fs, overlay |
| `HifiFileRead_ovl` | `0x03080efc` | fs, overlay |
| `AudioFileInput2` | `0x0306dac4` | fs, audio |
| `AudioFileMhRead2` | `0x0306dc72` | fs, audio |
| `AudioFileSeek2` | `0x0306dd54` | fs, audio |
| `AudioFileMhSeek2` | `0x0306dec4` | fs, audio |
| `AudioFileBufferSwitch2` | `0x0306da52` | fs, audio |
| `FLAC_FileSeekFast` | `0x0306e1f4` | fs, flac |
| `FLAC_FileGetSeekInfo` | `0x0306e24a` | fs, flac |
| `buffered_fread` | `0x030ae6b0` | fs, buffer |
| `buffered_fseek` | `0x030ae61a` | fs, buffer |
| `buffered_fread_ovl_0e65` | `0x030e6560` | fs, buffer, overlay |
| `buffered_fseek_ovl_0e64` | `0x030e64ca` | fs, buffer, overlay |

### Codec — MP3
| Name | Address | Tags |
|------|---------|------|
| `mp3_dec_internal` | `0x0306e5de` | codec, mp3 |
| `mp3_id3v2_handler` | `0x0306fec4` | codec, mp3 |
| `mp3_bitstream_getbits_copy` | `0x03028338` | codec, mp3, bitstream (similarity match) |

### Codec — WMA
| Name | Address | Tags |
|------|---------|------|
| `wma_audio_parse` | `0x0308cddc` | codec, wma |
| `wma_memcmp` | `0x0308283c` | codec, wma |
| `wma_memmove` | `0x030827ca` | codec, wma |
| `wma_memset` | `0x0308280a` | codec, wma |
| `wma_memclr` | `0x03082818` | codec, wma |
| `wma_input_cache_read` | `0x03083d48` | codec, wma |
| `wma_bitreader_getbits` | `0x03084970` | codec, wma |
| `wma_bitreader_getbits_copy` | `0x0308482e` | codec, wma (similarity match) |
| `wma_bitreader_getbits_copy` | `0x030848dc` | codec, wma (similarity match) |
| `wma_bitreader_getbits_copy_copy` | `0x03088390` | codec, wma (similarity match) |
| `wma_floor_log2` | `0x030842cc` | codec, wma |

### Codec — AAC/M4A
| Name | Address | Tags |
|------|---------|------|
| `aac_aac_dec` | `0x030ad690` | codec, aac |
| `aac_movfile_parser` | `0x030aeb90` | codec, aac |
| `aac_movfile_seek` | `0x030ae90c` | codec, aac |
| `aac_dec_init` | `0x030af458` | codec, aac |

### Codec — FLAC
| Name | Address | Tags |
|------|---------|------|
| `hifi_flac_dec` | `0x030df64c` | codec, flac |
| `hifi_flac_helper` | `0x030df52a` | codec, flac |
| `flac_bitstream_getbits_u` | `0x030dd736` | codec, flac, bitstream |
| `flac_bitstream_getbits_s` | `0x030dd6f6` | codec, flac, bitstream |

### Codec — WAV
| Name | Address | Tags |
|------|---------|------|
| `wav_lib_decode` | `0x030a42ee` | codec, wav |
| `wav_lib_parse_header` | `0x030a46c8` | codec, wav |

### Codec — OGG
| Name | Address | Tags |
|------|---------|------|
| `VorbisOGG_Parser` | `0x03023be8` | codec, ogg, media |
| `OGG_Picture_Metadata` | `0x030059d6` | codec, media |

### Codec — APE
| Name | Address | Tags |
|------|---------|------|
| `APE_Codec_Open` | `0x030eef60` | codec, ape |
| `ape_scan_cuesheet` | `0x0301dcb8` | codec, ape |
| `ape_rom_read_thunk` | `0x0301d670` | codec, ape, fs |
| `ape_rom_seek_thunk` | `0x0301d678` | codec, ape, fs |
| `DSD_BufferReady` | `0x030ff2d8` | codec, dsd |
| `DSD_IFF_Open` | `0x030ff2e8` | codec, dsd |
| `DSD_DecodeBlock` | `0x030ffa3c` | codec, dsd |

### USB
| Name | Address | Tags |
|------|---------|------|
| `USB_DAC_OpenStream` | `0x0302b80a` | usb, audio |

### Boot
| Name | Address | Tags |
|------|---------|------|
| `boot_param_layout` | `0x030000da` | init |

### Codec — DICTDECODER (container/stream layer)
| Name | Address | Tags |
|------|---------|------|
| `DICTDECODER_InitStream` | `0x0304fb44` | codec, parser |
| `dict_stream_read` | `0x0304eec4` | codec, parser |
| `dict_build_frame_index` | `0x0304f90a` | codec, parser |

Container magic: `g_dwDictMagicVaT` @ `0x0304fd4c` ('VaT '), `g_dwDictMagicVAT` @ `0x0304fd50` ('VAT ').

### DSP
| Name | Address | Tags |
|------|---------|------|
| `DSP_GOODEF_Init` | `0x0300f7dc` | dsp |
| `DSP_GOODEF_Process` | `0x0300fb0e` | dsp |
| `DSP_GOODEF_Reload` | `0x0301022c` | dsp, ui |

### Media/Tags
| Name | Address | Tags |
|------|---------|------|
| `ID3_Picture_Parser` | `0x03023526` | media, codec |

### UI/Theme
| Name | Address | Tags |
|------|---------|------|
| `MainUI_KeyHandler` | `0x0301020c` | ui, menu |
| `BroMemSelKeyMenu_Handler` | `0x03013280` | ui, menu |
| `FLAC_ThemeColor_Select` | `0x030054ba` | ui, theme, flac |

### Bluetooth
| Name | Address | Tags |
|------|---------|------|
| `BT_Music_Handler` | `0x0300ddea` | bluetooth |

### Recording
| Name | Address | Tags |
|------|---------|------|
| `RecordWinSvc_Start` | `0x0300aabc` | recording, service |

### SDK-Matched Functions (Aug 2026 pass)
| Name | Address | Tags |
|------|---------|------|
| `rk_printf` | `0x03000e08` | os, logging |
| `mbedtls_x509_dn_gets` | `0x03003df4` | crypto, tls |
| `SDC_Init` | `0x03004612` | sd, init |
| `mbedtls_timing_self_test` | `0x030093f4` | crypto, test |
| `mbedtls_x509_crt_parse_path` | `0x0300d184` | crypto, tls |
| `GUI_BmpFronDisplay` | `0x03012128` | ui, gui |
| `SNAND_Write` | `0x03019246` | flash, storage |
| `OGGInfo_Parse` | `0x0301930e` | codec, ogg |
| `dhcpd_add_option` | `0x0301a30e` | network, dhcp |
| `DisplayDev_ClrRect` | `0x0301c978` | ui, display |
| `SNOR_Erase` | `0x030264dc` | flash, storage |
| `ScuClockGateCtr` | `0x03029822` | system, clock |
| `TransCodeFromUTF8ToUnicode` | `0x0302cab0` | codec, encoding |
| `FatDev_FileSeek` | `0x0304ed3e` | fs, fat |
| `UartDevShellBspSetStopB` | `0x030506b0` | uart, config |
| `FATDelClusChain` | `0x030644c4` | fs, fat |
| `SDC_UpdateFreq` | `0x03082bfa` | sd, config |
| `besl_p2p_host_find_device` | `0x03085ce2` | network, p2p |
| `GUI_Setfocus` | `0x0308cb4c` | ui, gui |
| `SNOR_Init` | `0x0308eaf2` | flash, init |
| `FSRealname` | `0x030b1328` | fs, utility |
| `FW_Ansi2Unicode` | `0x030c4dec` | encoding, conversion |
| `APEV1_Parse` | `0x030cb34a` | codec, ape, tags |
| `SDC_WriteData` | `0x030f0384` | sd, storage |

### v3.4.0 Cross-Version Names (Aug 2026, program `sec3_3_4_0.bin`)

104 functions named via 3.4.0→3.5.0 fuzzy match (73 direct ≥0.9) +
3-hop chain 3.4→3.5→3.6→3.7 (39, combo ≥0.7, offset-ok). Addresses are
v3.4.0 addresses (imported at base 0x03000000).

| Name | Address (v3.4.0) | Tags |
|------|------------------|------|
| `dac_gain_curve_apply` | `0x030096f4` | audio, dac, volume |
| `AmrFunction` | `0x0300dafc` | codec, amr |
| `RKDeviceUnRegister` | `0x03009d00` | system, device |
| `SDDecodeCSD` | `0x030175f2` | sd, config |
| `pbuf_free` | `0x0302145a` | network, pbuf |
| `cmd_wifi_tcp_server` | `0x03028a02` | network, wifi |
| `USBGetRxFIFOIntType` | `0x03027428` | usb, dma |
| `my_bui_clz` | `0x03026530` | util, bit |
| `CodeResume` | `0x0301fa9c` | codec, state |
| `udp_server` | `0x0302af84` | network, udp |
| `IsrDisable2` | `0x03087db0` | system, irq |
| `UsbAdpterProbe` | `0x03087fa4` | usb, init |
| `mbedtls_havege_random` | `0x0304c942` | crypto, rng |
| `StartCASystem` | `0x03050348` | crypto, ca |
| `FmFreqToChan` | `0x0306af18` | audio, fm |
| `hifi_busy_delay` | `0x0306c038` | util, delay |
| `hifi_memmove` | `0x0306d080` | util, memory |
| `wma_memcmp` | `0x0308258c` | codec, wma |
| `FatDev_PrevDir` | `0x030825a6` | fs, fat |
| `DmaConfig_for_LLP2` | `0x03083cac` | dma, config |
| `DmaReConfig2` | `0x03083cfa` | dma, config |
| `wma_floor_log2` | `0x0308401c` | codec, wma |
| `Unicode2Ascii2` | `0x03087808` | encoding, conversion |
| `Unicode2Ascii` | `0x0308783e` | encoding, conversion |
| `modinv_u32` | `0x0308f8e4` | util, math |
| `FsIsLongName` | `0x030a21cc` | fs, utility |
| `SetSPIFreq` | `0x030a286c` | flash, spi |
| `buffered_fseek` | `0x030ae36a` | fs, io |
| `find_option` | `0x030b4714` | util, parser |
| `aac_aac_dec` | `0x030ad3e0` | codec, aac |
| `aac_movfile_parser` | `0x030ae8e0` | codec, aac, parser |
| `AudioFileOpen` | `0x030aeed2` | audio, file |
| `AudioFileMhSeek2` | `0x0306dc14` | audio, file |
| `AudioControlTask_Enter` | `0x03085274` | audio, task |
| `ReadFDTInfo` | `0x0306e6e0` | fs, fat |
| `DICTDECODER_InitStream` | `0x0304f894` | codec, dict |
| `OGGInfo_Parse` | `0x030c885c` | codec, ogg |
| `rkos_memory_malloc` | `0x030c9128` | os, heap |
| `FW_Ansi2UnicodeStr` | `0x030c9950` | encoding, conversion |
| `rkos_memory_free` | `0x030c9a2c` | os, heap |
| `printchar` | `0x030c9e4e` | os, logging |
| `RecordStop` | `0x030adbd4` | recording |
| `event_set` | `0x03073590` (×8 sites) | os, event |
| `ipc_post_cmd` / `ipc_post_arg` | `0x030739cc` / `0x030739f8` (×9 sites) | os, ipc |
| `hifi_busy_delay_ovl_0817` / `_09e3` / `_0bff` | `0x030814ac` / `0x0309e084` / `0x030bfcd0` | util, delay |

### v3.3.0 Cross-Version Names (Aug 2026, program `sec3_3_3_0.bin`)

106 functions named via 3.3.0→3.4.0 fuzzy match (71 direct ≥0.9) + 4-hop
chain 3.3→3.4→3.5→3.6→3.7 (79, combo ≥0.9; no offset check — 3.3→3.4 had a
relink shift, 31/32 segments MOVE +24). Addresses are v3.3.0 addresses
(imported at base 0x03000000).

| Name | Address (v3.3.0) | Tags |
|------|------------------|------|
| `DSD_DecodeBlock` | `0x030fe650` | codec, dsd (v3.3 changelog: DSD ID3 ✓) |
| `flac_bitstream_getbits_s` / `_u` | `0x030e437e` / `0x030e43be` | codec, flac |
| `APE_Set_CFG` | `0x030edad2` | codec, ape |
| `wma_floor_log2` | `0x03083ccc` | codec, wma |
| `AmrFunction` | `0x0300d888` | codec, amr |
| `bitstream_getbits_be` | `0x0301c2cc` (×2) | codec, bitreader |
| `pbuf_free` | `0x03021162` | network, pbuf |
| `CodeResume` | `0x0301f7a4` | codec, state |
| `my_bui_clz` | `0x03026238` | util, bit |
| `USBGetRxFIFOIntType` | `0x03027130` | usb, dma |
| `cmd_wifi_tcp_server` | `0x0302870a` | network, wifi |
| `udp_server` | `0x0302ac66` | network, udp |
| `RKDeviceUnRegister` | `0x03009a8c` | system, device |
| `DICTDECODER_InitStream` | (chained) | codec, dict |
| `event_set` / `ipc_post_cmd` / `ipc_post_arg` | (×8 sites) | os, event/ipc |
