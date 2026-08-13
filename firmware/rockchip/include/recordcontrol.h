/* recordcontrol.h — the SDK's real record-control header now ships with the
 * imported tree (audio/RecordControl/RecordControl.h). This shim forwards to it;
 * the old hand-written approximation (REC_Flag macro, RecordControl_* API) is
 * gone because the real SDK wins. */
#ifndef RECORDCONTROL_H
#define RECORDCONTROL_H
#include "../audio/RecordControl/RecordControl.h"
#endif /* RECORDCONTROL_H */
