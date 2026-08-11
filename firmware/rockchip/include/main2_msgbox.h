/* main2_msgbox.h — ENCODE/REC mailbox commands for Main2.c.
 * (RecordControl.h also defines them as an enum; Main2.c doesn't include
 *  RecordControl.h, so macros are safe here.) */
#ifndef MAIN2_MSGBOX_H
#define MAIN2_MSGBOX_H
#define MEDIA_MSGBOX_CMD_ENCODE            0x100
#define MEDIA_MSGBOX_CMD_ENCODE_PREPARE    0x101
#define MEDIA_MSGBOX_CMD_ENCODE_INIT       0x102
#define MEDIA_MSGBOX_CMD_ENCODE_INIT_CMPL  0x103
#define MEDIA_MSGBOX_CMD_ENCODE_CMPL       0x104
#define MEDIA_MSGBOX_CMD_ENCODE_ERR        0x105
#define MEDIA_MSGBOX_CMD_REC_FILE_CLOSE         0x106
#define MEDIA_MSGBOX_CMD_REC_FILE_CLOSE_CMPL    0x107
#define MEDIA_MSGBOX_CMD_REC_FILE_CLOSE_HANDSHK 0x108
#endif
