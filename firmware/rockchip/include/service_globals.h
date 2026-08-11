/* service_globals.h — audio service globals (Service.c needs these).
 * Separate from Service.h (which redefines EXT and breaks inclusion). */
#ifndef SERVICE_GLOBALS_H
#define SERVICE_GLOBALS_H
#include "typedef.h"

extern UINT8   SetPowerOffFlag;
extern INT8    AutoPowerOffDisableCounter;
extern UINT16  AudioPlayState;
extern UINT16  AudioCodecOpenErr;
extern uint32  AudioPtr;
extern uint32  AudioDecodeing;
extern uint32  DmaTransting;
extern uint32  AudioNeedDecode;
extern uint32  AudioLen;
extern UINT32  AudioDecodeCnt;

extern void FMThread;
extern void RecordThread;
extern void LowPowerWin;
typedef struct {
    uint32 FmState;
} RADIO_REG_KEY;
extern RADIO_REG_KEY *gpRadioplayerRegKey;
typedef struct {
    uint32 Offset;
    uint32 FileSize;
} FILE_INFO_T;
extern FILE_INFO_T FileInfo[];

extern uint32 FM_State_StepStation;
#endif
