/*
 * SysConfig.h — System build configuration for the Echo Mini (v3.7.0).
 *
 * Derives from Ghidra analysis of section_3 (which modules are compiled in)
 * and the stock feature set (changelogs + symbol-index.md):
 *   - MUSIC:      yes (core)
 *   - RADIO:      yes (FM radio — FMControlTask, FMUITask, FmDev_Shell)
 *   - RECORD:     yes (RecordWinSvc, RecordServiceGetTotalTime)
 *   - PICTURE:    yes (ID3_Picture_Parser, GUI_BmpFronDisplay)
 *   - BLUETOOTH:  yes (BT_Music_Handler, RKBT_FRead)
 *   - USB_HOST:   yes (MscSendCSW, USBMSCHost_Read)
 *   - VIDEO/EBOOK/CDROM: NO (not present in the binary)
 *
 * Confirmed via Ghidra function inventory (Aug 2026).
 */
#ifndef SYSCONFIG_H
#define SYSCONFIG_H

/* ---- Module selection (matches the stock firmware build) ---- */
#define _MUSIC_         1
#define _RADIO_         1
#define _RECORD_        1
#define _PICTURE_       1
#define _BLUETOOTH_     1
#define _USB_HOST_      1
/* #define _VIDEO_         1   // not in Echo Mini */
/* #define _EBOOK_         1   // not in Echo Mini */
/* #define _CDROM_         1   // not in Echo Mini */

/* ---- System language count ---- */
#define LANGUAGE_MAX_COUNT  1

/* ---- Chip / platform ---- */
#define _RKNANO_        1
#define _RKNANOC_       1
#define __CPU_NANOC__   1

/* ---- Memory config (from docs/memory-map.md + segment table) ---- */
#define SYS_DRAM_SIZE   0x04000000   /* 64 MB (8G variant uses same DRAM size) */
#define SYS_SRAM_BASE   0x03000000
#define SYS_SRAM_SIZE   0x00939000

/* ---- Display ---- */
#define LCD_WIDTH       320
#define LCD_HEIGHT      170
#define LCD_BPP         16

/* ---- Firmware identity (matches stock IMG strings) ---- */
#define FIRMWARE_NAME   "ECHO MINI"
#define FIRMWARE_MAJOR  3
#define FIRMWARE_MINOR  7
#define FIRMWARE_PATCH  0

#endif /* SYSCONFIG_H */
