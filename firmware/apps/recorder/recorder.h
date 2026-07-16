/*
 * firmware/apps/recorder/recorder.h
 * RecordWinSvc — microphone recording service
 */

#ifndef RECORDER_H
#define RECORDER_H

#include <stdint.h>

/* RecordWinSvc lifecycle:
 *   RecordWinSvc_Start @ 0x0300aabc → "RecordWinSvcStart"
 *   RecordWinSvc_Stop  @ 0x0300b060 → "RecordWinSvcStop"
 * Output path: U:\RECORD
 */

void RecordWinSvc_Start(void);
/*   @ 0x0300aabc */

void RecordWinSvc_Stop(void);
/*   string reference: "RecordWinSvcStop  \n" */

#endif /* RECORDER_H */
