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
    uint32  Clus;           /* current cluster (SysFindFile.c) */
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

/* MAX_FILENAME_LEN (AudioControl.h) */
#ifndef FSINCLUDE_NAME
#define FSINCLUDE_NAME
#define MAX_FILENAME_LEN   256
#define MAX_PATH_LEN       512
#endif

/* ---- File-system DB / sort types (SysFindFile.c) ---- */
#ifndef FSINCLUDE_DBTYPES
#define FSINCLUDE_DBTYPES
typedef enum {
    FS_TYPE_AUDIO = 0,
    FS_TYPE_VIDEO,
    FS_TYPE_PICTURE,
    FS_TYPE_TEXT,
    FS_TYPE_RECORD,
    FS_TYPE_MAX
} FS_TYPE;

#define MUSIC_DB        0
#define VIDEO_DB        1
#define PICTURE_DB      2
#define RECORD_DB       3
#define TEXT_DB         4

#define SORT_TYPE_SEL_FOLDER     0
#define MUSIC_TYPE_SEL_FMFILE    0
#define SORT_TYPE_SEL_SONGFILE   1
#endif

#define FS_FAT  0
#define SORT_TYPE_SEL_BROWSER  2

#define MUSIC_TYPE_SEL_RECORDFILE  2
#define NOT_FIND_FILE              0xFFFFFFFF
#define SORT_TYPE_SEL_NOW_PLAY     3
