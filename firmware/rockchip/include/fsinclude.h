/* fsinclude.h — Filesystem includes (FAT, media lib).
 * Auto-created for SDK build (Aug 2026).
 */
#ifndef FSINCLUDE_H
#define FSINCLUDE_H

#include "typedef.h"

#include "fat.h"
#include "media_lib.h"
#include "SysFindFile.h"


#endif /* FSINCLUDE_H */

/* ---- Filesystem find types (SysFindFile.h) ---- */
#ifndef FSINCLUDE_FIND
#define FSINCLUDE_FIND
#define MAX_DIR_DEPTH   8

typedef struct _FDT {
    uint32  dwFileSize;
    uint8   bFileType;        /* 0=file, 1=dir */
    uint8   bFileAttr;
    char    szFileName[256];
    char    szPath[256];
} FDT;

typedef struct _FIND_DATA {
    FDT     Fdt;
    uint8   bOpened;
    uint32  dwDirCluster;
} FIND_DATA;
#endif

/* ---- Filesystem sample-rate constants ---- */
#ifndef FSINCLUDE_FS
#define FSINCLUDE_FS
#define FS_22050Hz   22050
#define FS_44100Hz   44100
#define FS_48000Hz   48000
#define FS_96000Hz   96000
#define FS_192000Hz  192000
#endif
