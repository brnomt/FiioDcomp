# Echo Mini Firmware — Module Reference

## Labeled Functions (Ghidra custom-named grows each pass; ~2,175 `FUN_*` remain)

Phase goal: convert the entire IMG to C. Progress is tracked by custom-named
count vs total (~2,256). New C files land under `firmware/` as symbols are named.

### Entry & Init
| Name | Address | Tags |
|------|---------|------|
| `firmware_entry` | `0x03000010` | init, entry |
| `MusicInit` | `0x0302b9d8` | audio, init |
| `MusicService_Init` | `0x0302a3e0` | audio, init |
| `FormatList_Init` | `0x03013c10` | media, init |

### Audio Services
| Name | Address | Tags |
|------|---------|------|
| `AudioPlayback_Start` | `0x0302a398` | audio |
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
| `hifi_debug_printf` | `0x0306c07e` | os, utility |
| `hifi_debug_printf_ovl` | `0x030ab6b6` | os, utility |
| `hifi_memmove` | `0x0306d330` | os, utility |
| `memset_byte` | `0x030bfa36` | os, utility |
| `ipc_post_cmd` | `0x03073c7c` | os, ipc |
| `ipc_post_arg` | `0x03073ca8` | os, ipc |
| `bitreader_peek` | `0x0301e724` | os, bitstream |
| `bitreader_refill` | `0x0301e760` | os, bitstream |
| `bitstream_getbits` | `0x030b15ca` | os, bitstream |
| `bitstream_getbits_be` | `0x03070b0c` | os, bitstream |
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

### Codec — MP3
| Name | Address | Tags |
|------|---------|------|
| `mp3_dec_internal` | `0x0306e5de` | codec, mp3 |
| `mp3_id3v2_handler` | `0x0306fec4` | codec, mp3 |

### Codec — WMA
| Name | Address | Tags |
|------|---------|------|
| `wma_audio_parse` | `0x0308cddc` | codec, wma |

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
