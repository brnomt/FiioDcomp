/* mailbox.h — CPU <-> DSP (GOODE) mailbox protocol.
 * MailBoxWriteB2ACmd / MailBoxReadA2BCmd bridge the CPU and the GOODE
 * DSP chip. Command IDs follow the RKnanoD media protocol (sequential).
 * Derived from SDK usage in Main2.c / AudioControl.c. */
#ifndef MAILBOX_H
#define MAILBOX_H

#include "typedef.h"

/* ---- Mailbox channel / ID assignment ---- */
#define MAILBOX_ID_0        0
#define MAILBOX_ID_1        1
#define MAILBOX_ID_2        2
#define MAILBOX_ID_3        3

#define MAILBOX_INT_0       0
#define MAILBOX_INT_1       1
#define MAILBOX_INT_2       2

#define MAILBOX_CHANNEL_0   0
#define MAILBOX_CHANNEL_1   1
#define MAILBOX_CHANNEL_2   2

/* ---- Media mailbox commands (CPU -> DSP) ---- */
#define MSGBOX_CMD_SYSTEM_START_OK          0x0001

#define MEDIA_MSGBOX_CMD_ENCODE             0x0100
#define MEDIA_MSGBOX_CMD_ENCODE_INIT        0x0101
#define MEDIA_MSGBOX_CMD_FILE_OPEN          0x0102
#define MEDIA_MSGBOX_CMD_FILE_OPEN_HANDSHK  0x0103
#define MEDIA_MSGBOX_CMD_FILE_OPEN_CMPL     0x0104
#define MEDIA_MSGBOX_CMD_FILE_CLOSE         0x0105
#define MEDIA_MSGBOX_CMD_FILE_CLOSE_HANDSHK 0x0106
#define MEDIA_MSGBOX_CMD_FILE_CLOSE_CMPL    0x0107
#define MEDIA_MSGBOX_CMD_FILE_CREATE        0x0108
#define MEDIA_MSGBOX_CMD_FILE_CREATE_HANDSHK 0x0109
#define MEDIA_MSGBOX_CMD_FILE_CREATE_CMPL   0x010A
#define MEDIA_MSGBOX_CMD_FILE_READ          0x010B
#define MEDIA_MSGBOX_CMD_FILE_READ_CMPL     0x010C
#define MEDIA_MSGBOX_CMD_FILE_WRITE         0x010D
#define MEDIA_MSGBOX_CMD_FILE_WRITE_CMPL    0x010E
#define MEDIA_MSGBOX_CMD_FILE_SEEK          0x010F
#define MEDIA_MSGBOX_CMD_FILE_SEEK_CMPL     0x0110
#define MEDIA_MSGBOX_CMD_FILE_TELL          0x0111
#define MEDIA_MSGBOX_CMD_FILE_TELL_CMPL     0x0112
#define MEDIA_MSGBOX_CMD_FILE_GET_LENGTH    0x0113
#define MEDIA_MSGBOX_CMD_FILE_GET_LENGTH_CMPL 0x0114
#define MEDIA_MSGBOX_CMD_REC_FILE_CLOSE     0x0115
#define MEDIA_MSGBOX_CMD_REC_FILE_CLOSE_HANDSHK 0x0116

/* ---- API ---- */
API int  MailBoxWriteB2ACmd(uint32 cmd, uint32 id, uint32 channel);
API int  MailBoxWriteB2AData(uint32 data, uint32 id, uint32 channel);
API int  MailBoxReadA2BCmd(uint32 id, uint32 channel);
API int  MailBoxReadA2BData(uint32 id, uint32 channel);
API void MailBoxClearA2BInt(uint32 id, uint32 int_sel);
API void MailBoxInit(void);

#endif /* MAILBOX_H */
