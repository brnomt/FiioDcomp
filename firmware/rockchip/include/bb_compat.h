/* BB-only compatibility declarations for the original ReChord baseline.
 *
 * The complete AP SDK now supplies its own driver and filesystem definitions.
 * The BB build intentionally keeps the smaller integration headers that were
 * used before that import, so those compatibility constants must not leak into
 * the AP compilation.
 */
#ifndef RECHORD_BB_COMPAT_H
#define RECHORD_BB_COMPAT_H

#include "mailbox.h"
#include "service_globals.h"

extern uint32 DataDiskID;

#ifndef ATTR_DIRECTORY
#define ATTR_DIRECTORY 0x10
#endif
#ifndef DMA_CTLL_M2M_WORD
#define DMA_CTLL_M2M_WORD 0x00000010
#define DMA_CFGL_M2M_WORD 0x00000001
#define DMA_CFGH_M2M_WORD 0x00000000
#define DMA_FALSE 0
#endif
#ifndef MODULE_ID_WAV_DECODE_BIN
#define MODULE_ID_WAV_DECODE_BIN 15
#endif
#ifndef MEDIA_ID3_SAVE_CHAR_NUM
#define MEDIA_ID3_SAVE_CHAR_NUM 128
#endif
#ifndef MEDIA_FILE_TYPE_DELETED
#define MEDIA_FILE_TYPE_DELETED 0xE5
#define MEDIA_FILE_TYPE_FILE 0
#endif
#ifndef RECORD_NULL
#define RECORD_NULL 0
#endif
#ifndef I2S_NORMAL_MODE
#define I2S_NORMAL_MODE 0
#define I2S_MODE 0
#define I2S_FORMAT 0
#endif
#ifndef LogSecPerClus
#define LogSecPerClus 0
#endif
#ifndef FILE_NAME_SAVE_ADDR_OFFSET
#define FILE_NAME_SAVE_ADDR_OFFSET 0
#define DIR_CLUS_SAVE_ADDR_OFFSET 1
#define DIR_INDEX_SAVE_ADDR_OFFSET 2
#define ATTR_SAVE_ADDR_OFFSET 3
#endif

#endif /* RECHORD_BB_COMPAT_H */
