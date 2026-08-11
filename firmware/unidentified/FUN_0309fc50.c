/**
 * FUN_0309fc50 @ 0x0309fc50
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0309fc50(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_0309fffc;
  if (DAT_0309fffc[4] == 1) {
    hifi_busy_delay_ovl_09e3(1);
    iVar4 = DAT_030a0004;
    do {
      if (piVar1[4] != 1) goto LAB_0309fc78;
      hifi_busy_delay_ovl_09e3(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_ovl_09e0(DAT_030a000c);
  }
LAB_0309fc78:
  piVar1[5] = 0;
  iVar4 = DAT_030a0008;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030a0008 + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030a0000 + 1) = 1;
    uVar3 = FUN_0309d924(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030a3900(0xf2);
  return;
}


