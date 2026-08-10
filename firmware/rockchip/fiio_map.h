/*
 * fiio_map.h — Fiio Echo Mini v3.7.0 symbol addresses (Ghidra FIIO-3.7.0-Decomp)
 *
 * Cross-reference when reading firmware/rockchip/ SDK sources.
 * SDK function names match; addresses are Fiio-specific (RKnanoC).
 */
#ifndef FIIO_MAP_H
#define FIIO_MAP_H

/* --- Entry / init --- */
#define FIIO_firmware_entry           0x03000010u
#define FIIO_boot_param_layout        0x030000dau
#define FIIO_FormatList_Init          0x03013c10u
#define FIIO_MusicInit                  0x0302b9d8u
#define FIIO_MusicService_Init          0x0302a3e0u
#define FIIO_AudioPlayback_Start        0x0302a398u
#define FIIO_audiocodec_open            0x03029d0eu

/* --- HifiFile / AudioFile (SDK: bbsystem/audio_file_access2.c) --- */
#define FIIO_HifiFileSeek               0x0306b8e6u
#define FIIO_HifiFileRead               0x0306b94cu
#define FIIO_HifiFileWrite              0x0306b9bcu
#define FIIO_HifiFileClose              0x0306ba1eu
#define FIIO_HifiFileSeek_ovl           0x03080e96u
#define FIIO_HifiFileRead_ovl           0x03080efcu
/* HifiFileOpen: SDK spin-wait; timeout string @ 0x0306bb94 has no code xrefs on Fiio */
#define FIIO_HIFI_OPC_SEEK              0x69u
#define FIIO_HIFI_OPC_READ              0x6bu
#define FIIO_HIFI_OPC_WRITE             0x6du
#define FIIO_HIFI_OPC_CLOSE             0x73u
#define FIIO_AudioFileBufferSwitch2     0x0306da52u
#define FIIO_AudioFileInput2            0x0306dac4u
#define FIIO_AudioFileMhRead2           0x0306dc72u
#define FIIO_AudioFileSeek2             0x0306dd54u
#define FIIO_AudioFileMhSeek2           0x0306dec4u
#define FIIO_FLAC_FileSeekFast          0x0306e1f4u
#define FIIO_FLAC_FileGetSeekInfo       0x0306e24au
#define FIIO_buffered_fseek             0x030ae61au
#define FIIO_buffered_fread             0x030ae6b0u

/* --- Codec dispatch (SDK: audio/Common/pCODECS.c) --- */
#define FIIO_DICTDECODER_InitStream     0x0304fb44u  /* Fiio-only container */
#define FIIO_dict_stream_read           0x0304eec4u
#define FIIO_dict_build_frame_index     0x0304f90au
#define FIIO_mp3_dec_internal           0x0306e5deu
#define FIIO_wma_audio_parse            0x0308cddcu
#define FIIO_hifi_flac_dec              0x030df64cu
#define FIIO_APE_Codec_Open             0x030eef60u
#define FIIO_DSD_DecodeBlock            0x030ffa3cu

/* --- DSP (Fiio-only external GOODE chip) --- */
#define FIIO_DSP_GOODEF_Init            0x0300f7dcu
#define FIIO_DSP_GOODEF_Process         0x0300fb0eu
#define FIIO_DSP_GOODEF_Reload          0x0301022cu

/* --- OS / runtime --- */
#define FIIO_event_set                  0x03073840u
#define FIIO_event_clear                0x03073882u
#define FIIO_ipc_post_cmd               0x03073c7cu
#define FIIO_ipc_post_arg               0x03073ca8u
#define FIIO_hifi_busy_delay            0x0306c2e8u
#define FIIO_hifi_debug_printf          0x0306c07eu

/* --- UI --- */
#define FIIO_MainUI_KeyHandler          0x0301020cu
#define FIIO_BroMemSelKeyMenu_Handler   0x03013280u
#define FIIO_FLAC_ThemeColor_Select     0x030054bau

/* --- ROM API stubs @ 0x02FE0000 --- */
#define FIIO_rom_dac_mute               0x02ff44ceu
#define FIIO_rom_sample_rate_set        0x02ffa410u
#define FIIO_rom_gui_check_area         0x02ff7e0au

#endif /* FIIO_MAP_H */
