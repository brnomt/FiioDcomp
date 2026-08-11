/**
 * FUN_030c1546 @ 0x030c1546
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c1546(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_030c18f8;
  if (DAT_030c18f8[4] == 1) {
    hifi_busy_delay_ovl_0bff(1);
    iVar4 = DAT_030c1900;
    do {
      if (piVar1[4] != 1) goto LAB_030c156e;
      hifi_busy_delay_ovl_0bff(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030bfd16(DAT_030c1908);
  }
LAB_030c156e:
  piVar1[5] = 0;
  iVar4 = DAT_030c1904;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030c1904 + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030c18fc + 1) = 1;
    uVar3 = FUN_030bf680(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030cd468(0x115);
  return;
}


