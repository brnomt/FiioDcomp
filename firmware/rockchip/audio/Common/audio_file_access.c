/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name:   audio_file_access.c
*
* Description:  Audio File Operation Interface
*
* History:      <author>          <time>        <version>
*             Vincent Hsiung    2009-01-08         1.0
*    desc:    ORG.
********************************************************************************
*/

#include "audio_main.h"
#include "audio_file_access.h"
#include <stdio.h>
#include <string.h>
#include "FsInclude.h"
#include "File.h"

/*
*-------------------------------------------------------------------------------
*
*                           type define
*
*-------------------------------------------------------------------------------
*/
typedef unsigned int size_t;


size_t   (*RKFIO_FOpen)(uint8 * /*shortname*/, int32 /*DirClus*/, int32 /*Index*/, FS_TYPE /*FsType*/, uint8* /*Type*/) ;
size_t   (*RKFIO_FRead)(void * /*buffer*/, size_t /*length*/,FILE *) ;
int      (*RKFIO_FSeek)(long int /*offset*/, int /*whence*/ , FILE * /*stream*/);
long int (*RKFIO_FTell)(FILE * /*stream*/);
size_t   (*RKFIO_FWrite)(void * /*buffer*/, size_t /*length*/,FILE * /*stream*/);
unsigned long (*RKFIO_FLength)(FILE *in /*stream*/);
int      (*RKFIO_FClose)(FILE * /*stream*/);
int (*RKFIO_FEof)(FILE *);

FILE *pRawFileCache, *pFlacFileHandleBake, *pAacFileHandleSize, *pAacFileHandleOffset;

/*
*-------------------------------------------------------------------------------
*
*                           AudioFile Buffer define
*
*-------------------------------------------------------------------------------
*/


/*
--------------------------------------------------------------------------------
  Function name : File access interface
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                                    2009/02/20         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
unsigned long RKFLength(FILE *in)
{
    return (FileInfo[(int)in].FileSize); // modified by huweiguo, 09/04/11

}

unsigned long RKFTell(FILE *in)
{
    return (FileInfo[(int)in].Offset);
}

void RKFileFuncInit(void)
{
    RKFIO_FOpen   = FileOpen;
    RKFIO_FLength = RKFLength;
    RKFIO_FRead   = FileRead;
    RKFIO_FWrite  = FileWrite;
    RKFIO_FSeek   = FileSeek;
    RKFIO_FTell   = RKFTell;
    RKFIO_FClose  = FileClose;
    RKFIO_FEof    = FileEof;
}

 _ATTR_FLACDEC_TEXT_
int FLAC_FileSeekFast(int offset, int clus, FILE *in)
{
    FileInfo[(int)in].Offset = offset;
    FileInfo[(int)in].Clus   = clus;
    return 0;
}

_ATTR_FLACDEC_TEXT_
int FLAC_FileGetSeekInfo(int *pOffset, int *pClus, FILE *in)
{
    *pOffset = FileInfo[(int)in].Offset;
    *pClus   = FileInfo[(int)in].Clus;
    return 0;
}

/*
********************************************************************************
*
*                         End of Audio_file_access.c
*
********************************************************************************
*/



