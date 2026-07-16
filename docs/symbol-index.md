# Echo Mini Firmware — Module Reference

## Labeled Functions (29 of 2,232 completed in Phase 1)

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
| `event_set` | `0x0300c6b4` | os, event |
| `event_clear` | `0x0300c6f6` | os, event |
| `os_delay_ms` | `0x030098e4` | os, utility |
| `debug_printf` | `0x03012838` | os, utility |

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

### Codec — Dispatch
| Name | Address | Tags |
|------|---------|------|
| `DICTDECODER_InitStream` | `0x0304fb44` | codec, parser |
| `DICTDECODER_OpenFile` | `0x0301020c` | codec |
| `DICTDECODER_DispatchFile` | `0x0301022c` | codec |

### DSP
| Name | Address | Tags |
|------|---------|------|
| `DSP_GOODEF_Init` | `0x0300f7dc` | dsp |
| `DSP_GOODEF_Process` | `0x0300fb0e` | dsp |

### Media/Tags
| Name | Address | Tags |
|------|---------|------|
| `ID3_Picture_Parser` | `0x03023526` | media, codec |

### UI/Theme
| Name | Address | Tags |
|------|---------|------|
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
