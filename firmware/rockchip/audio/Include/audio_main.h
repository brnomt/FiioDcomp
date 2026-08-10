/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name：   audio_main.h
*
* Description:
*
* History:      <author>          <time>        <version>
*             Vincent Hsiung     2009-1-8          1.0
*    desc:    ORG.
********************************************************************************
*/

#ifndef _AUDIO_MAIN_H_
#define _AUDIO_MAIN_H_

#include "SysConfig.h"

/************************************************************
1. Select any Audio CODEC plug-in
*************************************************************/
#ifdef _MP3_DECODE_
#define MP3_DEC_INCLUDE
#endif

#ifdef _WAV_DECODE_
#define WAV_DEC_INCLUDE
#endif

#ifdef _AAC_DECODE_
#define AAC_DEC_INCLUDE
#endif

#ifdef _HIFI_APE_DEC
#define HIFI_APE_DECODE
#endif

#ifdef _HIFI_FLAC_DEC
#define HIFI_FlAC_DECODE
#endif

#ifdef _HIFI_ALAC_DEC
#define HIFI_AlAC_DECODE
#endif

#ifdef _DSDIFF_DECODE_
#define DSDIFF_DEC_INCLUDE
#endif

#ifdef _DSF_DECODE_
#define DSF_DEC_INCLUDE
#endif

#ifdef _OGG_DECODE_
#define OGG_DEC_INCLUDE
#endif

#ifdef _RK_EQ_
#define RK_MP3_EQ_WAIT_SYNTH
#endif

#ifdef RK_MP3_EQ_WAIT_SYNTH
#define MP3_EQ_WAIT_SYNTH  1
#else
#define MP3_EQ_WAIT_SYNTH  0
#endif

#ifdef _RK_ID3_
#endif

#ifdef VIDEO_MP2_DECODE
#define MP2_INCLUDE
#endif
/************************************************************
2. Include MP3 Encoding or ADPCM Encoding
                   Use Only One Encoding
*************************************************************/
/*------------------------------------------------------------
- Select One of Encoding
------------------------------------------------------------*/
#ifdef _WAV_ENCODE_
#define ADPCM_ENC_INCLUDE
#endif

typedef enum _MEDIA_MSGBOX_DECODE_CMD
{
    MEDIA_MSGBOX_CMD_DECODE_NULL,

    MEDIA_MSGBOX_CMD_DEC_OPEN,
    MEDIA_MSGBOX_CMD_DEC_OPEN_ERR,     /*解析音频文件头信息出差, 不支持该文件*/
    MEDIA_MSGBOX_CMD_DEC_OPEN_CMPL,    /*解析音频文件头信息成功*/

    MEDIA_MSGBOX_CMD_DECODE,
    MEDIA_MSGBOX_CMD_DECODE_CMPL,      /*完成一次解码操作*/
    MEDIA_MSGBOX_CMD_DECODE_ERR,       /*解码出错*/

    MEDIA_MSGBOX_CMD_DECODE_GETBUFFER,
    MEDIA_MSGBOX_CMD_DECODE_GETBUFFER_CMPL,

    MEDIA_MSGBOX_CMD_DECODE_GETTIME,
    MEDIA_MSGBOX_CMD_DECODE_GETTIME_CMPL,   // 10

    MEDIA_MSGBOX_CMD_DECODE_SEEK,
    MEDIA_MSGBOX_CMD_DECODE_SEEK_CMPL,

    MEDIA_MSGBOX_CMD_DECODE_CLOSE,
    MEDIA_MSGBOX_CMD_DECODE_CLOSE_CMPL,
//------------------------------------------------------------------------------
    MEDIA_MSGBOX_CMD_FLAC_SEEKFAST,
    MEDIA_MSGBOX_CMD_FLAC_SEEKFAST_CMPL,

    MEDIA_MSGBOX_CMD_FLAC_GETSEEK_INFO,
    MEDIA_MSGBOX_CMD_FLAC_SEEKFAST_INFO_CMPL,
    MEDIA_MSGBOX_CMD_DECODE_NUM

}MEDIA_MSGBOX_DECODE_CMD;


/* sections define */
//------------------------------------------------------------------------------
//Music Section define
#define     _ATTR_AUDIO_TEXT_          __attribute__((section("AudioCode")))
#define     _ATTR_AUDIO_DATA_          __attribute__((section("AudioData")))
#define     _ATTR_AUDIO_BSS_           __attribute__((section("AudioBss"),zero_init))


//-------------------------------------------MP3----------------------------------------------------------
#define _ATTR_MP3INIT_TEXT_     __attribute__((section("Mp3InitCode")))
#define _ATTR_MP3INIT_DATA_     __attribute__((section("Mp3InitData")))
#define _ATTR_MP3INIT_BSS_      __attribute__((section("Mp3InitBss"),zero_init))

#define _ATTR_MP3DEC_TEXT_     __attribute__((section("Mp3DecCode")))
#define _ATTR_MP3DEC_DATA_     __attribute__((section("Mp3DecData")))
#define _ATTR_MP3DEC_BSS_      __attribute__((section("Mp3DecBss"),zero_init))

//-------------------------------------------WAV----------------------------------------------------------
#define _ATTR_WAVDEC_INIT_TEXT_     __attribute__((section("WavDecInitCode")))
#define _ATTR_WAVDEC_INIT_DATA_     __attribute__((section("WavDecInitData")))
#define _ATTR_WAVDEC_INIT_BSS_      __attribute__((section("WavDecInitBss"),zero_init))

#define _ATTR_WAVDEC_TEXT_     __attribute__((section("WavDecCode")))
#define _ATTR_WAVDEC_DATA_     __attribute__((section("WavDecData")))
#define _ATTR_WAVDEC_BSS_      __attribute__((section("WavDecBss"),zero_init))

//-----------------------------------------FLAC----------------------------------------------------------
#define     _ATTR_FLACDEC_TEXT_          __attribute__((section("FlacDecCode")))
#define     _ATTR_FLACDEC_DATA_          __attribute__((section("FlacDecData")))
#define     _ATTR_FLACDEC_BSS_           __attribute__((section("FlacDecBss"),zero_init))

//-----------------------------------------AAC----------------------------------------------------------
#define     _ATTR_AACDEC_TEXT_          __attribute__((section("AacDecCode")))
#define     _ATTR_AACDEC_DATA_          __attribute__((section("AacDecData")))
#define     _ATTR_AACDEC_BSS_           __attribute__((section("AacDecBss"),zero_init))
#define     _ATTR_AACDEC_DATA_RO        __attribute__((section("AacROData")))

//-----------------------------------------APE----------------------------------------------------------
#define     _ATTR_APEDEC_TEXT_          __attribute__((section("ApeDecCode")))
#define     _ATTR_APEDEC_DATA_          __attribute__((section("ApeDecData")))
#define     _ATTR_APEDEC_BSS_           __attribute__((section("ApeDecBss"),zero_init))

//-----------------------------------------OGG----------------------------------------------------------
#define     _ATTR_OGGDEC_TEXT_          __attribute__((section("OggDecCode")))
#define     _ATTR_OGGDEC_DATA_          __attribute__((section("OggDecData")))
#define     _ATTR_OGGDEC_BSS_           __attribute__((section("OggDecBss"),zero_init))

//-----------------------------------------HIFI APE----------------------------------------------------------
#define     _ATTR_HIFI_APEDEC_TEXT_          __attribute__((section("ApeHDecCode")))
#define     _ATTR_HIFI_APEDEC_DATA_          __attribute__((section("ApeHDecData")))
#define     _ATTR_HIFI_APEDEC_BSS_           __attribute__((section("ApeHDecBss"),zero_init))

//-----------------------------------------HIFI FLAC----------------------------------------------------------
#define     _ATTR_HIFI_FLACDEC_TEXT_          __attribute__((section("FlacHDecCode")))
#define     _ATTR_HIFI_FLACDEC_DATA_          __attribute__((section("FlacHDecData")))
#define     _ATTR_HIFI_FLACDEC_BSS_           __attribute__((section("FlacHDecBss"),zero_init))

//-----------------------------------------HIFI ALAC----------------------------------------------------------
#define     _ATTR_HIFI_ALACDEC_TEXT_          __attribute__((section("AlacHDecCode")))
#define     _ATTR_HIFI_ALACDEC_DATA_          __attribute__((section("AlacHDecData")))
#define     _ATTR_HIFI_ALACDEC_BSS_           __attribute__((section("AlacHDecBss"),zero_init))

//-----------------------------------------DSDIFF----------------------------------------------------------
#define     _ATTR_DSDIFFDEC_TEXT_          __attribute__((section("DsdiffDecCode")))
#define     _ATTR_DSDIFFDEC_DATA_          __attribute__((section("DsdiffDecData")))
#define     _ATTR_DSDIFFDEC_BSS_           __attribute__((section("DsdiffDecBss"),zero_init))

//-----------------------------------------DSF----------------------------------------------------------
#define     _ATTR_DSFDEC_TEXT_          __attribute__((section("DsfDecCode")))
#define     _ATTR_DSFDEC_DATA_          __attribute__((section("DsfDecData")))
#define     _ATTR_DSFDEC_BSS_           __attribute__((section("DsfDecBss"),zero_init))

//-----------for B core-----------
//-------------------------------------------MP3 BIN----------------------------------------------------------
#define _ATTR_MP3DEC_BIN_TEXT_     __attribute__((section("Mp3DecBinCode")))
#define _ATTR_MP3DEC_BIN_DATA_     __attribute__((section("Mp3DecBinData")))
#define _ATTR_MP3DEC_BIN_BSS_      __attribute__((section("Mp3DecBinBss"),zero_init))

#define _ATTR_MP3ENC_BIN_TEXT_     __attribute__((section("Mp3EncBinCode")))
#define _ATTR_MP3ENC_BIN_DATA_     __attribute__((section("Mp3EncBinData")))
#define _ATTR_MP3ENC_BIN_BSS_      __attribute__((section("Mp3EncBinBss"),zero_init))

//-------------------------------------------WAV BIN----------------------------------------------------------
#define _ATTR_WAVDEC_BIN_TEXT_     __attribute__((section("WavDecBinCode")))
#define _ATTR_WAVDEC_BIN_DATA_     __attribute__((section("WavDecBinData")))
#define _ATTR_WAVDEC_BIN_BSS_      __attribute__((section("WavDecBinBss"),zero_init))

//-----------------------------------------FLAC BIN----------------------------------------------------------
#define     _ATTR_FLACDEC_BIN_TEXT_          __attribute__((section("FlacDecBinCode")))
#define     _ATTR_FLACDEC_BIN_DATA_          __attribute__((section("FlacDecBinData")))
#define     _ATTR_FLACDEC_BIN_BSS_           __attribute__((section("FlacDecBinBss"),zero_init))


//-----------------------------------------AAC BIN----------------------------------------------------------
#define     _ATTR_AACDEC_BIN_TEXT_          __attribute__((section("AacDecBinCode")))
#define     _ATTR_AACDEC_BIN_DATA_          __attribute__((section("AacDecBinData")))
#define     _ATTR_AACDEC_BIN_BSS_           __attribute__((section("AacDecBinBss"),zero_init))


//-----------------------------------------APE BIN----------------------------------------------------------
#define     _ATTR_APEDEC_BIN_TEXT_          __attribute__((section("ApeDecBinCode")))
#define     _ATTR_APEDEC_BIN_DATA_          __attribute__((section("ApeDecBinData")))
#define     _ATTR_APEDEC_BIN_BSS_           __attribute__((section("ApeDecBinBss"),zero_init))

//-----------------------------------------OGG BIN----------------------------------------------------------
#define     _ATTR_OGGDEC_BIN_TEXT_          __attribute__((section("OggDecBinCode")))
#define     _ATTR_OGGDEC_BIN_DATA_          __attribute__((section("OggDecBinData")))
#define     _ATTR_OGGDEC_BIN_BSS_           __attribute__((section("OggDecBinBss"),zero_init))


//-----------------------------------------HIFI APE BIN----------------------------------------------------------
#define     _ATTR_HIFI_APEDEC_BIN_TEXT_          __attribute__((section("ApeHDecBinCode")))
#define     _ATTR_HIFI_APEDEC_BIN_DATA_          __attribute__((section("ApeHDecBinData")))
#define     _ATTR_HIFI_APEDEC_BIN_BSS_           __attribute__((section("ApeHDecBinBss"),zero_init))


//-----------------------------------------HIFI FLAC BIN----------------------------------------------------------
#define     _ATTR_HIFI_FLACDEC_BIN_TEXT_          __attribute__((section("FlacHDecBinCode")))
#define     _ATTR_HIFI_FLACDEC_BIN_DATA_          __attribute__((section("FlacHDecBinData")))
#define     _ATTR_HIFI_FLACDEC_BIN_BSS_           __attribute__((section("FlacHDecBinBss"),zero_init))


//-----------------------------------------HIFI ALAC BIN----------------------------------------------------------
#define     _ATTR_HIFI_ALACDEC_BIN_TEXT_          __attribute__((section("AlacHDecBinCode")))
#define     _ATTR_HIFI_ALACDEC_BIN_DATA_          __attribute__((section("AlacHDecBinData")))
#define     _ATTR_HIFI_ALACDEC_BIN_BSS_           __attribute__((section("AlacHDecBinBss"),zero_init))

//-----------------------------------------DSDIFF BIN----------------------------------------------------------
#define     _ATTR_DSDIFFDEC_BIN_TEXT_           __attribute__((section("DsdiffDecBinCode")))
#define     _ATTR_DSDIFFDEC_BIN_DATA_           __attribute__((section("DsdiffDecBinData")))
#define     _ATTR_DSDIFFDEC_BIN_BSS_            __attribute__((section("DsdiffDecBinBss"),zero_init))

//-----------------------------------------DSF BIN----------------------------------------------------------
#define     _ATTR_DSFDEC_BIN_TEXT_           __attribute__((section("DsfDecBinCode")))
#define     _ATTR_DSFDEC_BIN_DATA_           __attribute__((section("DsfDecBinData")))
#define     _ATTR_DSFDEC_BIN_BSS_            __attribute__((section("DsfDecBinBss"),zero_init))


//-------------------------------------------ID3----------------------------------------------------------
#define _ATTR_ID3_TEXT_     __attribute__((section("Id3Code")))
#define _ATTR_ID3_DATA_     __attribute__((section("Id3Data")))
#define _ATTR_ID3_BSS_      __attribute__((section("Id3Bss"),zero_init))

//-------------------------------------------ID3 JPG------------------------------------------------------
//#define _ATTR_ID3JPG_TEXT_     __attribute__((section("Id3JpgCode")))
//#define _ATTR_ID3JPG_DATA_     __attribute__((section("Id3JpgData")))
//#define _ATTR_ID3JPG_BSS_      __attribute__((section("Id3JpgBss"),zero_init))

//-------------------------------------------WAV Encode----------------------------------------------------------
#define _ATTR_MSADPCM_TEXT_     __attribute__((section("EncodeMsadpcmCode")))
#define _ATTR_MSADPCM_DATA_     __attribute__((section("EncodeMsadpcmData")))
#define _ATTR_MSADPCM_BSS_      __attribute__((section("EncodeMsadpcmBss"),zero_init))

//-------------------------------------------MP3 Encode----------------------------------------------------------

#define _ATTR_AUDIO_TEXT_     __attribute__((section("AudioCode")))
#define _ATTR_AUDIO_DATA_     __attribute__((section("AudioData")))
#define _ATTR_AUDIO_BSS_      __attribute__((section("AudioBss"),zero_init))

#define _ATTR_MSEQ_TEXT_     __attribute__((section("MsEqCode")))
#define _ATTR_MSEQ_DATA_     __attribute__((section("MsEqData")))
#define _ATTR_MSEQ_BSS_      __attribute__((section("MsEqBss"),zero_init))

//-------------------------------------------MP2 Encode----------------------------------------------------------
#define _ATTR_MP2DEC_TEXT_     __attribute__((section("Mp2Code"/*"MP3DEC_CODE_SEG"*/)))
#define _ATTR_MP2DEC_DATA_     __attribute__((section("Mp2Data"/*"MP3DEC_DATA_SEG"*/)))
#define _ATTR_MP2DEC_BSS_      __attribute__((section("Mp2Bss"/*"MP3DEC_BSS_SEG"*/),zero_init))

//-----------------------------------------SBC----------------------------------------------------------
#define     _ATTR_SBCDEC_TEXT_          __attribute__((section("SbcDecCode")))
#define     _ATTR_SBCDEC_DATA_          __attribute__((section("SbcDecData")))
#define     _ATTR_SBCDEC_BSS_           __attribute__((section("SbcDecBss"),zero_init))

//-------------------------------------------OGG Decode----------------------------------------------------------


//aac
#ifdef B_CORE_DECODE
#define aac_DEBUG  DEBUG2
#define aac_printf rk_printf2
#define aac_delayms DelayMs2

#define aac_MemSet MemSet2
#define aac_Memcpy MemCpy2
#else
#define aac_DEBUG  DEBUG
#define aac_printf rk_printf
#define aac_delayms DelayMs

#define aac_MemSet memset
#define aac_Memcpy memcpy
#endif

//hifi ape
#ifdef B_CORE_DECODE
#define Hifi_Ape_MemSet MemSet2
#define Hifi_Ape_DelayMs DelayMs2
#define Hifi_Ape_Memcpy  MemCpy2

#define Hifi_Ape_Printf rk_printf2
#else
#define Hifi_Ape_MemSet MemSet
#define Hifi_Ape_DelayMs DelayMs
#define Hifi_Ape_Memcpy  MemCpy

#define Hifi_Ape_Printf rk_printf
#endif

//hifi alac
#ifdef B_CORE_DECODE
#define Hifi_Alac_MemSet MemSet2
#define Hifi_Alac_DelayMs DelayMs2
#define Hifi_Alac_Memcpy  MemCpy2
#define Hifi_Alac_Printf rk_printf2
#else
#define Hifi_Alac_MemSet MemSet
#define Hifi_Alac_DelayMs DelayMs
#define Hifi_Alac_Memcpy  MemCpy
#define Hifi_Alac_Printf rk_printf
#endif

//hifi flac
#ifdef B_CORE_DECODE
#define Hifi_Flac_MemSet MemSet2
#define Hifi_Flac_DelayMs DelayMs2
#define Hifi_Flac_Memcpy  MemCpy2
#define Hifi_Flac_Printf rk_printf2
#else
#define Hifi_Flac_MemSet MemSet
#define Hifi_Flac_DelayMs DelayMs
#define Hifi_Flac_Memcpy  MemCpy
#define Hifi_Flac_Printf rk_printf
#endif

//mp3
#ifdef B_CORE_DECODE
#define mp3_printf rk_printf2
#define mp3_DEBUG  DEBUG2
#else
#define mp3_printf rk_printf
#endif
//wav
#ifdef B_CORE_DECODE
#define wav_DEBUG DEBUG2
#define wav_printf rk_printf2
#else
#define wav_DEBUG DEBUG2
#define wav_printf rk_printf
#endif

//dsdiff
#ifdef B_CORE_DECODE
#define dsd_DEBUG DEBUG2
#define dsd_printf rk_printf2
#define DSD_Memcpy  MemCpy2
#else
#define dsd_DEBUG DEBUG2
#define dsd_printf rk_printf
#define DSD_Memcpy  MemCpy
#endif

//dsf
#ifdef B_CORE_DECODE
#define dsf_DEBUG DEBUG2
#define dsf_printf rk_printf2
#define DSF_Memcpy  MemCpy2
#else
#define dsf_DEBUG DEBUG
#define dsf_printf rk_printf
#define DSF_Memcpy  MemCpy
#endif

//flac
#ifdef B_CORE_DECODE
#define flac_MemSet MemSet2
#define flac_DEBUG DEBUG2
#else
#define flac_MemSet MemSet
#define flac_DEBUG DEBUG
#endif

//ape
#ifdef B_CORE_DECODE
#define ape_MemSet MemSet2
#define ape_DEBUG DEBUG2
#define ape_Memcpy MemCpy2
#else
#define ape_MemSet MemSet
#define ape_DEBUG DEBUG
#define ape_Memcpy MemCpy
#endif

//ogg
#ifdef B_CORE_DECODE
#define ogg_MemSet MemSet2
#define ogg_DEBUG DEBUG2
#define ogg_Memcpy MemCpy2
#else
#define ogg_MemSet MemSet
#define ogg_DEBUG DEBUG
#define ogg_Memcpy MemCpy
#endif

#endif        // _AUDIO_MAIN_H_

