/* mailbox.h — CPU<->DSP mailbox (GOODE DSP communication).
 * Auto-created for SDK build (Aug 2026);
 * signatures derived from firmware/rockchip usage.
 */
#ifndef MAILBOX_H
#define MAILBOX_H

#include "typedef.h"

API int MailBoxWriteB2ACmd(uint32 cmd, uint32 data);
API int MailBoxWriteB2AData(uint32 data);
API int MailBoxReadA2BCmd(void);
API void MailBoxInit(void);

#endif /* MAILBOX_H */
