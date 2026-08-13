/* BlueToothControl.h — the SDK's real BT-control header (Common/Codec/BlueTooth/
 * BlueToothControl.h) is not imported yet, so this shim declares the BT thread
 * global the AP BT code references. BT_WIN_STATUS_* come from ui/SetMenu/
 * SetBluetooth.h. */
#ifndef BLUETOOTHCONTROL_H
#define BLUETOOTHCONTROL_H
#include "typedef.h"
#include "Thread.h"

extern THREAD BlueToothThread;

#define _ATTR_BLUETOOTHCONTROL_CODE_  __attribute__((section("BlueToothControlCode")))
#define _ATTR_BLUETOOTHCONTROL_DATA_  __attribute__((section("BlueToothControlData")))
#define _ATTR_BLUETOOTHCONTROL_BSS_   __attribute__((section("BlueToothControlBss")))

#endif /* BLUETOOTHCONTROL_H */
