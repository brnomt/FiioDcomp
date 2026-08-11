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
