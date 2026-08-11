/* recordcontrol.h — Recorder control.
 * Auto-created for SDK build (Aug 2026).
 */
#ifndef RECORDCONTROL_H
#define RECORDCONTROL_H

#include "typedef.h"

API void RecordControl_Init(void);
API void RecordControl_Start(void);
API void RecordControl_Stop(void);

#endif /* RECORDCONTROL_H */

/* ---- Recorder encode types ---- */
#ifndef RECORDCONTROL_ENCODE
#define RECORDCONTROL_ENCODE
#define RECORD_ENCODE_TYPE_PCM  0
#define RECORD_ENCODE_TYPE_WAV  1
#define RECORD_ENCODE_TYPE_REV  2
#endif

/* ---- RecordControl.c constants ---- */
#ifndef RECORDCTRL_CONSTS
#define RECORDCTRL_CONSTS
#define REC_Flag       1
#define RECORD_BEING   2
#define RECORD_PAUSE   3
#define RECORD_ERROR   4
#define NOT_OPEN_FILE  0xFF
#define RECORD_QUALITY_HIGH  0

#define I2S_CH    0
#define I2S_PORT  0
#define I2S_START_DMA_RX  1
#define FM_OUT_CONFIG  0
#define FM_I2S_HP      0

#define Codec_MicStero   0
#define Codec_Mic2Mono   1
#define Codec_LineinStereo 2
#endif
