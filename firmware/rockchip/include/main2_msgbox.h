/* main2_msgbox.h — the ENCODE/REC mailbox command IDs (MEDIA_MSGBOX_CMD_*)
 * are defined by the real SDK in audio/RecordControl/RecordControl.h.
 * Main2.c includes recordcontrol.h AFTER its filesystem headers, so this
 * shim no longer needs to define anything — the old macros collided with the
 * SDK's enum. */
#ifndef MAIN2_MSGBOX_H
#define MAIN2_MSGBOX_H
#endif /* MAIN2_MSGBOX_H */
