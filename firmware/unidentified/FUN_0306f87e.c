/**
 * FUN_0306f87e @ 0x0306f87e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306f87e(byte *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [8];
  
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x38);
  if ((param_1[0x18] & 8) == 0) {
    iVar2 = FUN_0306f5b8(param_1);
    if (iVar2 == -1) {
      *(undefined4 *)(param_2 + 0x2c) = 0;
      return 0xffffffff;
    }
  }
  piVar1 = DAT_0306f924;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
  if (*param_1 - 1 != piVar1[1]) {
    (*(code *)*DAT_0306f92c)(*DAT_0306f928);
    hifi_debug_printf(s_change_layer_0306f930);
    return 0xffffffff;
  }
  iVar2 = (**(code **)(DAT_0306f940 + piVar1[1] * 4))(param_2,param_1);
  if (iVar2 == -1) {
    FUN_0306e5b0();
    if ((*(ushort *)(param_2 + 0x3c) & 0xff00) == 0) {
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
    }
  }
  else {
    if (*param_1 != 3) {
      FUN_03070b64(auStack_18,*(undefined4 *)(param_2 + 0x18));
      *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_2 + 0x1c);
      *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_2 + 0x20);
      uVar3 = FUN_03070b72(param_2 + 0x1c,auStack_18);
      *(undefined4 *)(param_2 + 0x2c) = uVar3;
    }
    if (*piVar1 == 0) {
      *piVar1 = 0x480;
    }
  }
  return 0;
}


