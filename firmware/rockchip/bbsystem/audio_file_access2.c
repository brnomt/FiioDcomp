/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name：   audio_file_access.c
*
* Description:  Audio File Operation Interface
*
* History:      <author>          <time>        <version>
*             Vincent Hsiung    2009-01-08         1.0
*    desc:    ORG.
********************************************************************************
*
* Fiio Echo Mini port note (FiioDcomp):
*   Source: RKNanoD_MP3 v1.3 — Common/BBSystem/audio_file_access2.c
*   Fiio v3.7.0 verified symbols (see firmware/rockchip/fiio_map.h):
*     HifiFileSeek       @ 0x0306b8e6   (+ overlay @ 0x03080e96)
*     HifiFileRead       @ 0x0306b94c   (+ overlay @ 0x03080efc)
*     HifiFileOpen/Close/Write — SDK impl here; xref recovery pending in Ghidra
*     AudioFile*2, buffered_fread/fseek — same file, Fiio addresses in fiio_map.h
*   Ghidra decomp reference: firmware/firmware/filesystem/hifi_file.c
*   Status: PORTED (reference) — not build-wired yet
********************************************************************************
*/
#include <stdio.h>
#include <string.h>
#include "SysInclude.h"
#include "audio_main.h"
#include "audio_globals.h"
#include "audio_file_access.h"
#include "mailbox.h"
#include "Msg.h"
#include "pcm.h"
#include "fsinclude.h"

/*
*-------------------------------------------------------------------------------
*
*                           type define
*
*-------------------------------------------------------------------------------
*/
typedef unsigned int size_t;
typedef     int8                    HANDLE;

//size_t   (*RKFIO_FOpen2)(uint8 * /*shortname*/, int32 /*DirClus*/, int32 /*Index*/, FS_TYPE /*FsType*/, uint8* /*Type*/) ;
size_t   (*RKFIO_FOpen)();
size_t   (*RKFIO_FRead)(void * /*buffer*/, size_t /*length*/,FILE *) ;
int      (*RKFIO_FSeek)(long int /*offset*/, int /*whence*/ , FILE * /*stream*/);
long int (*RKFIO_FTell)(FILE * /*stream*/);
size_t   (*RKFIO_FWrite)(void * /*buffer*/, size_t /*length*/,FILE * /*stream*/);
unsigned long (*RKFIO_FLength)(FILE *in /*stream*/);
int      (*RKFIO_FClose)(FILE * /*stream*/);
int (*RKFIO_FEof)(FILE *);

FILE *pRawFileCache,*pFlacFileHandleBake,*pAacFileHandleSize,*pAacFileHandleOffset;

/*
*-------------------------------------------------------------------------------
*
*                           AudioFile Buffer define
*
*-------------------------------------------------------------------------------
*/

unsigned long          SRC_Num_Forehead;

extern uint32          gCmd;
extern uint32          gData;
extern int             CurrentCodec2;
extern UINT32          Msg[(MSG_ID_MAX / 32) + 1];

extern  short         *outbuf[2];
extern short          *AACoutBuf[2];
extern short          *gAPEPingPangBuf[2];
extern unsigned short *g_FlacCodecBuffer[2];
extern short          *OggPcmOut[2];
extern uint8          *gHAPEPingPangBuf[2];
extern uint8          *gAlacPingPangBuf[2];
extern uint8          *gFlacPingPangBuf[2];
extern uint8          *gDffPingPangBuf[2];
extern uint8          *gDsfPingPangBuf[2];

#ifdef WAV_DEC_INCLUDE
extern  tPCM          pcm_s;
extern char           PcmOutputBuff[WAV_IMAMAX_PCM_LENGTH*8];
#endif

#ifdef MP3_ENC_INCLUDE2
    _ATTR_AUDIO_BSS_ uint8 __align(4) AudioBuffer2[4];
#else
    _ATTR_AUDIO_BSS_ uint8 __align(4) AudioBuffer2[HIFI_AUDIO_BUF_SIZE];
#endif

_ATTR_AUDIO_BSS_ uint8  *AudioFileBuf2;
_ATTR_AUDIO_BSS_ char   *AudioCodecBuf2;
_ATTR_AUDIO_BSS_ uint32  CodecBufSize2;
_ATTR_AUDIO_BSS_ uint32  AudioFilePIPOBufSize2;     //分配给文件缓冲PIPO Buffer 的大小,总大小AudioFilePIPOBufSize x 2
//不同的文件，其大小不一样
_ATTR_AUDIO_BSS_ uint32  AudioFileBufBusy2;
_ATTR_AUDIO_BSS_ uint32  AudioFileBufSize2[2];
_ATTR_AUDIO_BSS_ uint32  AudioFileBufPos2;
_ATTR_AUDIO_BSS_ uint32  AudioFileRdBufID2;
_ATTR_AUDIO_BSS_ uint32  AudioFileWrBufID2;


_ATTR_BB_SYS_DATA_ uint8              gCmdDone = 0;
_ATTR_BB_SYS_DATA_ uint8              gBufByPass = 0;
_ATTR_AUDIO_BSS_   uint32             FileTotalSize;
_ATTR_AUDIO_BSS_   uint32             CurFileOffset[8];
_ATTR_AUDIO_BSS_   FILE_SEEK_OP_t     gFileSeekParam;
_ATTR_AUDIO_BSS_   FILE_READ_OP_t     gFileReadParam;
_ATTR_AUDIO_BSS_   FILE_WRITE_OP_t    gFileWriteParam;
_ATTR_AUDIO_BSS_   FLAC_SEEKFAST_OP_t gFlacSeekParam;

//Record Variable define
_ATTR_AUDIO_BSS_  INT16               hRecFile;
_ATTR_AUDIO_BSS_  uint32              RecFileOffset;
#if(defined WAV_DEC_INCLUDE2) || (defined MP3_ENC_INCLUDE2)
tPCM_enc   PCM_source;          //structure.
extern SF_PRIVATE sf_enc;

extern void InitADPCMEncoder(tPCM_enc *pPCM);
extern int msadpcm_enc_init (SF_PRIVATE *psf, int blockalign, int samplesperblock);
UINT32 __align(4) EncodeInputBufferPIPO2[WAV_AD_PIPO_BUFFER_SIZE];  //Buffer must align 4
UINT16      RecordInputBufIndex;
UINT16      RecordInputBufLength;
UINT8*      WavEncodeHeadBuffer2;


UINT16     *pRecordEncodeInputBuffer2;
UINT16     *pRecordPCMInputBuffer2;
UINT16     *pRecordInputBuffer2;
#endif

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
size_t HifiFileOpen()
{
    uint32 timeout = 3000000;

    while (!gCmdDone)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("HifiFileOpen: timeout!!");
            break;
        }
    }
    gCmdDone = 0;
    return 0;
}

bool HifiFileEof(FILE *in)
{
    if (CurFileOffset[(HANDLE)in] == FileTotalSize)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

uint32 HifiRKFLength(HANDLE in)
{

#if 0
    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FILE_GET_LENGTH,MAILBOX_ID_0, MAILBOX_CHANNEL_2);
    MailBoxWriteB2AData((int)in, MAILBOX_ID_0, MAILBOX_CHANNEL_2);

    while (!gCmdDone)
    {
        __WFI2();
    }

    gCmdDone = 0;
    return gData;
#else
    return FileTotalSize;
#endif
}

unsigned long HifiRKFTell(HANDLE in)
{
#if 0
    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FILE_TELL,MAILBOX_ID_0, MAILBOX_CHANNEL_2);
    MailBoxWriteB2AData((int)in, MAILBOX_ID_0, MAILBOX_CHANNEL_2);

    while (!gCmdDone)
    {
        __WFI2();
    }

    gCmdDone = 0;
    return gData;
#else
    return CurFileOffset[in];
#endif
}

uint8 HifiFileSeek(int32 offset, uint8 Whence, HANDLE Handle)
{
    uint32 timeout = 3000000;

    gFileSeekParam.offset = offset;
    gFileSeekParam.whence = Whence;
    gFileSeekParam.handle = Handle;
    gCmdDone = 0;
    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FILE_SEEK,MAILBOX_ID_0, MAILBOX_CHANNEL_2);
    MailBoxWriteB2AData((uint32)&gFileSeekParam, MAILBOX_ID_0, MAILBOX_CHANNEL_2);

    while (!gCmdDone)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("HifiFileSeek: timeout!!");
            break;
        }
    }
    CurFileOffset[gFileSeekParam.handle] = gFileSeekParam.offset;
    gCmdDone = 0;
    return gData;
}

uint32 HifiFileRead(uint8 *pData, uint32 NumBytes, HANDLE Handle)
{
    uint32 timeout = 200000;

    gFileReadParam.pData    = pData;
    gFileReadParam.NumBytes = NumBytes;
    gFileReadParam.handle   = Handle;

    gCmdDone = 0;
    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FILE_READ,MAILBOX_ID_0, MAILBOX_CHANNEL_2);
    MailBoxWriteB2AData((uint32)&gFileReadParam, MAILBOX_ID_0, MAILBOX_CHANNEL_2);

    if(gBufByPass)
    {
        timeout = 3000000;
        while (!gCmdDone)
        {
            //__WFI2();
            DelayUs2(1);
            if (--timeout == 0)
            {
                bb_printf1("HifiFileRead: timeout!!");
                break;
            }
        }
        CurFileOffset[gFileReadParam.handle] = gFileReadParam.NumBytes;
        gCmdDone = 0;

        return gData;   //return read data length
    }
    else
    {
        return 0;
    }
}

uint32 HifiFileWrite(uint8 *Buf, uint32 fileOffset, uint32 Size, HANDLE Handle)
{
    uint32 timeout = 200000;

    gFileWriteParam.buf         = Buf;
    gFileWriteParam.fileOffset  = fileOffset;
    gFileWriteParam.size        = Size;
    gFileWriteParam.handle      = Handle;
    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FILE_WRITE,MAILBOX_ID_0, MAILBOX_CHANNEL_2);
    MailBoxWriteB2AData((uint32)&gFileWriteParam, MAILBOX_ID_0, MAILBOX_CHANNEL_2);

    if(gBufByPass)
    {
        timeout = 3000000;
        while (!gCmdDone)
        {
            //__WFI2();
            DelayUs2(1);
            if (--timeout == 0)
            {
                bb_printf1("HifiFileWrite: timeout!!");
                break;
            }
        }
        gCmdDone = 0;
        return gData;
    }
    else
    {
        return 0;
    }
}

uint8 HifiFileClose(HANDLE Handle)
{
    uint32 timeout = 3000000;

    gCmdDone = 0;
    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FILE_CLOSE,MAILBOX_ID_0, MAILBOX_CHANNEL_2);
    MailBoxWriteB2AData((uint32)Handle, MAILBOX_ID_0, MAILBOX_CHANNEL_2);

    while (!gCmdDone)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("HifiFileClose: timeout!!");
            break;
        }
    }
    gCmdDone = 0;

    return gData;
}


void RKFileFuncInit2(void)
{
    gBufByPass = 1;

    RKFIO_FOpen   = HifiFileOpen;
    RKFIO_FLength = HifiRKFLength;
    RKFIO_FRead   = HifiFileRead;
    RKFIO_FWrite  = HifiFileWrite;
    RKFIO_FSeek   = HifiFileSeek;
    RKFIO_FTell   = HifiRKFTell;
    RKFIO_FClose  = HifiFileClose;
    RKFIO_FEof    = HifiFileEof;
}
#if(defined WAV_DEC_INCLUDE2) || (defined MP3_ENC_INCLUDE2)

void RecordBufferInit()
{
    RecordInputBufIndex   = 0;   //used for buffer switch.
    pRecordInputBuffer2       = (UINT16*)EncodeInputBufferPIPO2;
    pRecordPCMInputBuffer2    = pRecordInputBuffer2;
    pRecordEncodeInputBuffer2 = pRecordInputBuffer2 + WAV_AD_PIPO_BUFFER_SIZE;
}
#endif
#ifdef MP3_ENC_INCLUDE2

unsigned int RecordMP3Init(int samplerate,int channel,int  Bitrate)
{
    unsigned int samples_per_frame;
    //bb_printf1("RecordMP3Init");
    samples_per_frame = Mp3EncodeVariableInit2(samplerate,channel,Bitrate);
    //bb_printf1("RecordMP3Init over");
    return samples_per_frame;
}
#endif

#ifdef WAV_DEC_INCLUDE2

void RecordADPCMInit(tPCM_enc* pPCM)
{
    //bb_printf1("pPCM addr= 0x%08x ",pPCM);
    InitADPCMEncoder(pPCM);

    //bb_printf1("usBytesPerBlock= %d,usSamplesPerBlock = %d",pPCM->usBytesPerBlock, pPCM->usSamplesPerBlock);

    sf_enc.sf.channels = pPCM->ucChannels;
    sf_enc.sf.samplerate = pPCM->usSampleRate;
    sf_enc.sf.format = (SF_FORMAT_WAV | SF_FORMAT_MS_ADPCM);
    if(pPCM->wFormatTag == WAVE_FORMAT_ADPCM)
    {
        sf_enc.mode = SFM_WRITE;
        sf_enc.datalength = pPCM->ulLength;

        msadpcm_enc_init (&sf_enc, pPCM->usBytesPerBlock, pPCM->usSamplesPerBlock);
    }
    else if(pPCM->wFormatTag == WAVE_FORMAT_PCM)
    {
        sf_enc.mode = SFM_WRITE;
        sf_enc.datalength = pPCM->ulLength;
    }

}


#endif

/*
--------------------------------------------------------------------------------
  Function name : AudioFileBufferInit with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
void AudioFileBufferInit2(HANDLE Handle)
{
    AudioFileBufPos2      = 0;
    AudioFileRdBufID2     = 0;
    AudioFileBufBusy2 = 0;

    gBufByPass = 1;

    AudioFileBufSize2[AudioFileRdBufID2]
    = HifiFileRead((uint8*)(&AudioFileBuf2[AudioFileRdBufID2 * AudioFilePIPOBufSize2]),
                   AudioFilePIPOBufSize2, Handle);

    AudioFileWrBufID2     = 1;
    AudioFileBufSize2[AudioFileWrBufID2]  = 0;

    SendMsg(MSG_AUDIO_DECODE_FILL_BUFFER);
}

/*
--------------------------------------------------------------------------------
  Function name : AudioFileBufferSwitch with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
void AudioFileBufferSwitch2(HANDLE Handle)
{
    //if the second buffer empty, fill buffer
    uint32 timeout = 3000000;

    while(AudioFileBufBusy2 == 1)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("AudioFileBufferSwitch2: timeout!!");
            break;
        }
    }

    AudioFileBufPos2 = 0;
    AudioFileBufSize2[AudioFileRdBufID2] = 0;
    AudioFileWrBufID2 = AudioFileRdBufID2;
    AudioFileRdBufID2 = 1 - AudioFileRdBufID2;

    if (AudioFileBufSize2[AudioFileRdBufID2] == 0)
    {
        gBufByPass = 1;

        AudioFileBufSize2[AudioFileRdBufID2]
        = HifiFileRead((uint8*)(&AudioFileBuf2[AudioFileRdBufID2 * AudioFilePIPOBufSize2]),
                       AudioFilePIPOBufSize2, Handle);
    }

    SendMsg(MSG_AUDIO_DECODE_FILL_BUFFER);
}

/*
--------------------------------------------------------------------------------
  Function name : AudioFileInput with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
uint32 AudioFileInput2(HANDLE Handle)
{
    uint32 timeout = 3000000;

    {
       while(AudioFileBufBusy2 == 1)
       {
            //__WFI2();
            DelayUs2(1);
            if (--timeout == 0)
            {
                bb_printf1("AudioFileInput2: timeout!!");
                break;
            }
       }

        gBufByPass = 0;

        AudioFileBufBusy2 = 1;

        AudioFileBufSize2[AudioFileWrBufID2]
        = HifiFileRead((uint8*)(&AudioFileBuf2[AudioFileWrBufID2 * AudioFilePIPOBufSize2]),
                       AudioFilePIPOBufSize2, Handle);
    }
    return 0;
}

/*
--------------------------------------------------------------------------------
  Function name : AudioFileRead with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
uint32 AudioFileRead2(uint8 *pData, uint32 NumBytes, HANDLE Handle)
{
    uint32 remain;
    uint32 retval;
    uint32 readcnt;
    uint32 temp;

    readcnt = 0;
    while (NumBytes)
    {
        //printf("\nread = %d", NumBytes);

        /*
        if ((AudioFileBufSize[AudioFileRdBufID] < AudioFilePIPOBufSize2) && (AudioFileBufPos >= AudioFileBufSize[AudioFileRdBufID]))
        {
            break;
        }
        */


retry:

        remain = AudioFileBufSize2[AudioFileRdBufID2] - AudioFileBufPos2;

        //printf("\nremain = %d", remain);

        if (NumBytes < remain)
        {
            memcpy(pData, &AudioFileBuf2[AudioFileRdBufID2 * AudioFilePIPOBufSize2 + AudioFileBufPos2], NumBytes);
            readcnt         += NumBytes;
            pData           += NumBytes;
            AudioFileBufPos2 += NumBytes;
            if (AudioFileBufPos2 >= AudioFileBufSize2[AudioFileRdBufID2])
            {
                AudioFileBufPos2 = 0;
                AudioFileBufferSwitch2(Handle);
            }
            break;
        }
        else
        {
            //read buffer remain data, buffer empty
            memcpy(pData, &AudioFileBuf2[AudioFileRdBufID2 * AudioFilePIPOBufSize2 + AudioFileBufPos2], remain);
            NumBytes        -= remain;
            readcnt         += remain;
            pData           += remain;
            AudioFileBufPos2 += remain;
            if (AudioFileBufPos2 >= AudioFileBufSize2[AudioFileRdBufID2])
            {
                //printf("\nNumBytes = %d, remain = %d",NumBytes, remain);
                AudioFileBufPos2 = 0;
                AudioFileBufferSwitch2(Handle);
                if (AudioFileBufSize2[AudioFileRdBufID2] == 0)
                {
                    break;
                }
            }

            goto retry;
        }

    }

    return readcnt;

}
/*
--------------------------------------------------------------------------------
  Function name : AudioFileRead with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
uint32 AudioFileMhRead2(uint8 *pData, uint32 NumBytes, FILE * Handle)
{
    uint32 timeout = 3000000;

    if(Handle == 0)
    {
        return AudioFileRead2(pData, NumBytes, (HANDLE)Handle);
    }
    else
    {
       while(AudioFileBufBusy2 == 1)
       {
            //__WFI2();
            DelayUs2(1);
            if (--timeout == 0)
            {
                bb_printf1("AudioFileMhRead2: timeout!!");
                break;
            }
       }
        return HifiFileRead(pData, NumBytes, (HANDLE)Handle);
    }
}

/*
--------------------------------------------------------------------------------
  Function name : AudioFileTell with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
unsigned long AudioFileTell2(HANDLE in)
{
    uint32 offset;
    uint32 ret;
    offset = HifiRKFTell(in);
    ret = (offset - ((AudioFileBufSize2[0] + AudioFileBufSize2[1]) - AudioFileBufPos2));

    //bb_printf1("hifirkTell = %d",ret);
    return ret;
}

/*
--------------------------------------------------------------------------------
  Function name : AudioFileTell with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
unsigned long AudioFileMhTell2(FILE * in)
{
    if(in == 0)
    {
        return AudioFileTell2((HANDLE)in);
    }
    else
    {
        return HifiRKFTell((HANDLE)in);
    }
}


/*
--------------------------------------------------------------------------------
  Function name :  with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
bool AudioFileEof2(FILE *in)
{
    if (HifiRKFTell((HANDLE)in) == HifiRKFLength((HANDLE)in))
    {
        if (((AudioFileBufSize2[0] + AudioFileBufSize2[1]) - AudioFileBufPos2) == 0)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    return FALSE;
}


/*
--------------------------------------------------------------------------------
  Function name :  with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
bool AudioFileMhEof2(FILE *in)
{
    if(in == 0)
    {
        return AudioFileEof2(in);
    }
    else
    {
        return HifiFileEof(in);
    }

}


/*
--------------------------------------------------------------------------------
  Function name : AudioFileSeek with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
uint8 AudioFileSeek2(int32 offset, uint8 Whence, HANDLE Handle)
{
    uint8 ret = RETURN_OK;
    uint32 FileBuffStart, FileBufcurPos, FileBufferEnd;
    uint32 temp;
    uint32 fileoffset;
    uint32 timeout = 3000000;

    while(AudioFileBufBusy2 == 1)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("AudioFileSeek2: timeout!!");
            break;
        }
    }

    fileoffset = HifiRKFTell(Handle);

    if (Whence == SEEK_SET)
    {
        //printf("\n audio file seek = whence ---%d, %d",Whence, offset);
        FileBufferEnd = fileoffset;
        FileBuffStart = fileoffset - (AudioFileBufSize2[0] + AudioFileBufSize2[1]);

        //bb_printf1("FileBuffStart = %d FileBufferEnd = %d",FileBuffStart,FileBufferEnd);

        if ((FileBuffStart <= offset) && (offset < FileBufferEnd))
        {
            temp = offset - FileBuffStart;
            if (temp < AudioFileBufSize2[AudioFileRdBufID2])
            {
                AudioFileBufPos2 = temp;
            }
            else
            {
                temp -= AudioFileBufSize2[AudioFileRdBufID2];
                AudioFileBufPos2 = temp;

                AudioFileBufSize2[AudioFileRdBufID2] = 0;
                AudioFileWrBufID2 = AudioFileRdBufID2;
                AudioFileRdBufID2 = 1 - AudioFileRdBufID2;
                SendMsg(MSG_AUDIO_DECODE_FILL_BUFFER);
            }
        }
        else
        {
            ret = HifiFileSeek((offset / 512) * 512, Whence, Handle);
            AudioFileBufferInit2(Handle);
            AudioFileBufPos2 += (offset % 512);

            //bb_printf1("filebufPos = %d",AudioFileBufPos2);
        }

    }
    else if (Whence == SEEK_CUR)
    {
        temp = AudioFileBufPos2 + offset;
        if ((0 <= temp) && (temp < (AudioFileBufSize2[0] + AudioFileBufSize2[1])))
        {
            if (offset > 0)
            {
                AudioFileBufPos2 += offset;
                if (AudioFileBufPos2 > AudioFileBufSize2[AudioFileRdBufID2])
                {
                    AudioFileBufPos2 -= AudioFileBufSize2[AudioFileRdBufID2];
                    AudioFileBufSize2[AudioFileRdBufID2] = 0;
                    AudioFileWrBufID2 = AudioFileRdBufID2;
                    AudioFileRdBufID2 = 1 - AudioFileRdBufID2;
                    SendMsg(MSG_AUDIO_DECODE_FILL_BUFFER);
                }
            }
            else if (offset < 0)
            {
                AudioFileBufPos2 += offset;
            }
        }
        else
        {
            FileBuffStart = fileoffset - (AudioFileBufSize2[0] + AudioFileBufSize2[1]);

            FileBuffStart = FileBuffStart + temp;

            ret = HifiFileSeek((FileBuffStart / 512) * 512, 0, Handle);
            AudioFileBufferInit2(Handle);
            AudioFileBufPos2 += (FileBuffStart % 512);
        }
    }
    else
    {
        ret = HifiFileSeek((offset / 512) * 512, Whence, Handle);
        AudioFileBufferInit2(Handle);
        AudioFileBufPos2 += (offset % 512);
    }

    return ret;
}


/*
--------------------------------------------------------------------------------
  Function name : AudioFileSeek with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
uint8 AudioFileMhSeek2(int32 offset, uint8 Whence, FILE * Handle)
{
    uint32 timeout = 3000000;

    if(Handle == 0)
    {
        return AudioFileSeek2(offset, Whence, (HANDLE)Handle);
    }
    else
    {
        while(AudioFileBufBusy2 == 1)
       {
           //__WFI2();
            DelayUs2(1);
            if (--timeout == 0)
            {
                bb_printf1("AudioFileMhSeek2: timeout!!");
                break;
            }
       }

        return HifiFileSeek(offset, Whence, (HANDLE)Handle);
    }

}


/*
--------------------------------------------------------------------------------
  Function name : File access with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
void AudioFileFuncInit2(HANDLE Handle, uint32 CodecBufSize)
{
    RKFIO_FOpen   = HifiFileOpen;
    RKFIO_FLength = HifiRKFLength;
    RKFIO_FRead   = AudioFileRead2;
    RKFIO_FSeek   = AudioFileSeek2;
    RKFIO_FTell   = AudioFileTell2;
    RKFIO_FClose  = HifiFileClose;
    RKFIO_FEof    = AudioFileEof2;

    AudioFileBuf2  = (uint8 *)AudioBuffer2;
    AudioFilePIPOBufSize2 = ((HIFI_AUDIO_BUF_SIZE - CodecBufSize) / 1024) * 1024;
    AudioFilePIPOBufSize2 = AudioFilePIPOBufSize2 >> 1;

    AudioFileBufferInit2(Handle);
}

/*
--------------------------------------------------------------------------------
  Function name : File access with Buffer
  Author        :
  Description   :
  Input         :
  Return        :
  History       : <author>         <time>         <version>
                       zyz            2013/11/07         Ver1.0
  desc          :   ORG
--------------------------------------------------------------------------------
*/
_ATTR_AUDIO_TEXT_
void AudioFileMhFuncInit2(FILE * Handle, uint32 CodecBufSize)
{
    RKFIO_FOpen   = HifiFileOpen;
    RKFIO_FLength = HifiRKFLength;
    RKFIO_FRead   = AudioFileMhRead2;
    RKFIO_FSeek   = AudioFileMhSeek2;
    RKFIO_FTell   = AudioFileMhTell2;
    RKFIO_FClose  = HifiFileClose;
    RKFIO_FEof    = AudioFileMhEof2;

    AudioFileBuf2  = (uint8 *)AudioBuffer2;
    AudioFilePIPOBufSize2 = ((HIFI_AUDIO_BUF_SIZE - CodecBufSize) / 1024) * 1024;
    AudioFilePIPOBufSize2 = AudioFilePIPOBufSize2 >> 1;
    //bb_printf1("2AudioFilePIPOBufSize2 = %d, %x CodecBufSize = %d", AudioFilePIPOBufSize2, &AudioFilePIPOBufSize2, CodecBufSize);
    AudioFileBufferInit2((HANDLE)Handle);
}

_ATTR_AUDIO_TEXT_
void AudioFileChangeBuf2(HANDLE Handle, uint32 CodecBufSize)
{
    uint32 fileoffset;
    uint32 timeout = 3000000;

    while(AudioFileBufBusy2 == 1)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("AudioFileChangeBuf2: timeout!!");
            break;
        }
    }

    fileoffset = HifiRKFTell(Handle);

    AudioFilePIPOBufSize2 = ((HIFI_AUDIO_BUF_SIZE - CodecBufSize) / 1024) * 1024;
    AudioFilePIPOBufSize2 = AudioFilePIPOBufSize2 >> 1;
    HifiFileSeek((fileoffset - AudioFileBufSize2[0] - AudioFileBufSize2[1]), SEEK_SET, Handle);


    gBufByPass = 1;
    AudioFileBufSize2[AudioFileRdBufID2]
    = HifiFileRead((uint8*)(&AudioFileBuf2[AudioFileRdBufID2 * AudioFilePIPOBufSize2]),
                   AudioFilePIPOBufSize2, Handle);

    AudioFileBufSize2[AudioFileWrBufID2]  = 0;

    SendMsg(MSG_AUDIO_DECODE_FILL_BUFFER);

}

uint32 AudioCodecGetBufferSize2(int codec, int samplerate)
{
    //Get Codecs output buffersize
    {
        if (codec == CODEC_MP3_DEC)
        {
            CodecBufSize2 = 1152 * 8;                    // 1152*4*2 = 9216
        }

#ifdef WAV_DEC_INCLUDE2
        else if (codec == CODEC_WAV_DEC)
        {
            CodecBufSize2 = 2730 * 8;                    // 2730*4*2 = 21840 / 2
        }
#endif

#ifdef  AAC_DEC_INCLUDE2
        else if (codec == CODEC_AAC_DEC)
        {
            CodecBufSize2 = 1024* 8;                     // 1024*4*2 = 8192
        }
#endif

#ifdef APE_DEC_INCLUDE2
        else if (codec == CODEC_APE_DEC)
        {
            CodecBufSize2 = 1152 * 8;                    // 1152*4*2 = 9216
        }
#endif

#ifdef FLAC_DEC_INCLUDE2
        else if (codec == CODEC_FLAC_DEC)
        {
            CodecBufSize2 = 2320 * 12;          // 2320*4*2= 18560  该值/8应为四字节对齐
        }
#endif

#ifdef OGG_DEC_INCLUDE2
        else if (codec == CODEC_OGG_DEC)
        {
            CodecBufSize2 = 1024*8;
        }
#endif
#ifdef HIFI_APE_DECODE2
        else if (codec == CODEC_HIFI_APE_DEC)
        {
            CodecBufSize2 = 1024*32;
        }
#endif
#ifdef HIFI_AlAC_DECODE2
        else if (codec == CODEC_HIFI_ALAC_DEC)
        {
            CodecBufSize2 = 1024*32;
        }
#endif
#ifdef HIFI_FlAC_DECODE2
        else if (codec == CODEC_HIFI_FLAC_DEC)
        {
            CodecBufSize2 = 1024*36; // 4096*4*2*1.5  4608*4*2*1.5
        }
#endif

#ifdef DSDIFF_DEC_INCLUDE2
        else if (codec == CODEC_DSDIFF_DEC)
        {
            CodecBufSize2 = 1176 * 8 * 2;                    // 2048*4*2 = 16384
        }
#endif

#ifdef DSF_DEC_INCLUDE2
        else if (codec == CODEC_DSF_DEC)
        {
            CodecBufSize2 = 1024 * 8 * 2;                    // 2048*4*2 = 16384
        }
#endif
        else
        {
            CodecBufSize2 = 0;
        }

        CodecBufSize2 = (CodecBufSize2 ) * 2;
        SRC_Num_Forehead = 0;
    }

    AudioCodecBuf2 = AudioBuffer2 + HIFI_AUDIO_BUF_SIZE - CodecBufSize2;

    if (codec == CODEC_MP3_DEC)
    {
#ifdef MP3_DEC_INCLUDE2
        outbuf[0] = (short*)AudioCodecBuf2;
        outbuf[1] = (short*)(&AudioCodecBuf2[CodecBufSize2>>1]);
#endif
    }

#ifdef WAV_DEC_INCLUDE2
    else if (codec == CODEC_WAV_DEC)
    {
        pcm_s.OutputBuff[0] = (short*)AudioCodecBuf2;
        pcm_s.OutputBuff[1] = (short *)PcmOutputBuff;
    }
#endif

#ifdef  AAC_DEC_INCLUDE2
    else if (codec == CODEC_AAC_DEC)
    {
        AACoutBuf[0] = (short*)AudioCodecBuf2;
        AACoutBuf[1] = (short*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif

#ifdef APE_DEC_INCLUDE2
    else if (codec == CODEC_APE_DEC)
    {
        gAPEPingPangBuf[0] = (short*)AudioCodecBuf2;
        gAPEPingPangBuf[1] = (short*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif

#ifdef FLAC_DEC_INCLUDE2
    else if (codec == CODEC_FLAC_DEC)
    {
        //extern unsigned char FlacOutputBuff[4608*4];;
        g_FlacCodecBuffer[0] = (short*)AudioCodecBuf2;
        g_FlacCodecBuffer[1] = (short*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif

#ifdef  OGG_DEC_INCLUDE2
    else if (codec == CODEC_OGG_DEC)
    {
        OggPcmOut[0] = (short*)AudioCodecBuf2;
        OggPcmOut[1] = (short*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif
#ifdef HIFI_APE_DECODE2
    else if (codec == CODEC_HIFI_APE_DEC)
    {
        gHAPEPingPangBuf[0] = (uint8*)AudioCodecBuf2;
        gHAPEPingPangBuf[1] = (uint8*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif
#ifdef HIFI_AlAC_DECODE2
    else if (codec == CODEC_HIFI_ALAC_DEC)
    {
        gAlacPingPangBuf[0] = (uint8*)AudioCodecBuf2;
        gAlacPingPangBuf[1] = (uint8*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif
#ifdef HIFI_FlAC_DECODE2
    else if (codec == CODEC_HIFI_FLAC_DEC)
    {
        gFlacPingPangBuf[0] = (uint8*)AudioCodecBuf2;
        gFlacPingPangBuf[1] = (uint8*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif

#ifdef DSDIFF_DEC_INCLUDE2
    else if (codec == CODEC_DSDIFF_DEC)
    {
        gDffPingPangBuf[0] = (uint8*)AudioCodecBuf2;
        gDffPingPangBuf[1] = (uint8*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
#endif

#ifdef DSF_DEC_INCLUDE2
    else if (codec == CODEC_DSF_DEC)
    {
        gDsfPingPangBuf[0] = (uint8*)AudioCodecBuf2;
        gDsfPingPangBuf[1] = (uint8*)(&AudioCodecBuf2[CodecBufSize2>>1]);
    }
   #endif

    return CodecBufSize2;
}

extern void imdct36_handler();
extern void synth_handler();
void AudioIntAndDmaInit2(void)
{
    /*---------clear interrupt flag.------------*/
#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
        IntPendingClear2(INT_ID_IMDCT);
        IntPendingClear2(INT_ID_SYNTH);
    }
#endif

#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
        IntRegister2(INT_ID_IMDCT, imdct36_handler);
        IntRegister2(INT_ID_SYNTH, synth_handler);
    }
#endif


#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
        IntEnable2(INT_ID_IMDCT);
        IntEnable2(INT_ID_SYNTH);
    }
#endif
}

void AudioIntAndDmaDeInit2(void)
{
    /*---------clear interrupt enable------------*/
#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
#if(MP3_EQ_WAIT_SYNTH)
        mp3_wait_synth();
#endif
        IntDisable2(INT_ID_IMDCT);
        IntDisable2(INT_ID_SYNTH);
    }
#endif

    /*---------clear interrupt Pending---------*/
#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
        IntPendingClear2(INT_ID_IMDCT);
        IntPendingClear2(INT_ID_SYNTH);
    }
#endif

    /*-----------interrupt callback auti-register--------------*/
#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
        IntUnregister2(INT_ID_IMDCT);
        IntUnregister2(INT_ID_SYNTH);
    }
#endif

}

extern void AcceleratorHWInit(void);
extern void AcceleratorHWExit();
void AudioHWInit2(void)
{
#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
        AcceleratorHWInit();
    }
#endif
}

void AudioHWDeInit2(void)
{
#ifdef MP3_DEC_INCLUDE2
    if (CurrentCodec2 == CODEC_MP3_DEC)
    {
        AcceleratorHWExit();
    }
#endif
}

_ATTR_FLACDEC_TEXT_
int FLAC_FileSeekFast(int offset, int clus, FILE * in)
{
    uint32 timeout = 3000000;

    gFlacSeekParam.offset = offset;
    gFlacSeekParam.clus   = clus;
    gFlacSeekParam.fp     = (int)in;

    gCmdDone = 0;

    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FLAC_SEEKFAST,MAILBOX_ID_0, MAILBOX_CHANNEL_1);
    MailBoxWriteB2AData((uint32)&gFlacSeekParam, MAILBOX_ID_0, MAILBOX_CHANNEL_1);

    while (!gCmdDone)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("FLAC_FileSeekFast: timeout!!");
            break;
        }
    }

    gCmdDone = 0;

//  FileInfo[(int)in].Offset = offset;
//  FileInfo[(int)in].Clus   = clus;
    return 0;
}
_ATTR_FLACDEC_TEXT_
int FLAC_FileGetSeekInfo(int *pOffset, int *pClus, FILE * in)
{
    FLAC_SEEKFAST_OP_t* ptmep;
    uint32 timeout = 3000000;

    gCmdDone = 0;
    MailBoxWriteB2ACmd(MEDIA_MSGBOX_CMD_FLAC_GETSEEK_INFO,MAILBOX_ID_0, MAILBOX_CHANNEL_1);
    MailBoxWriteB2AData((int)in, MAILBOX_ID_0, MAILBOX_CHANNEL_1);

    while (!gCmdDone)
    {
        //__WFI2();
        DelayUs2(1);
        if (--timeout == 0)
        {
            bb_printf1("FLAC_FileGetSeekInfo: timeout!!");
            break;
        }
    }

    gCmdDone = 0;
    ptmep = (FLAC_SEEKFAST_OP_t*)gData;

    *pOffset = ptmep->offset;
    *pClus   = ptmep->clus;

//  *pOffset = FileInfo[(int)in].Offset;
//  *pClus   = FileInfo[(int)in].Clus;
    return 0;
}

/*
********************************************************************************
*
*                         End of Audio_file_access.c
*
********************************************************************************
*/



