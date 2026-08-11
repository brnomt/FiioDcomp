/**
 * FUN_0308307e @ 0x0308307e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308307e(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_03083430;
  if (DAT_03083430[4] == 1) {
    hifi_busy_delay_ovl_0817(1);
    iVar4 = DAT_03083438;
    do {
      if (piVar1[4] != 1) goto LAB_030830a6;
      hifi_busy_delay_ovl_0817(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_03081592(DAT_03083440);
  }
LAB_030830a6:
  piVar1[5] = 0;
  iVar4 = DAT_0308343c;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_0308343c + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_03083434 + 1) = 1;
    uVar3 = HifiFileRead_ovl(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_0308392c(0x102);
  return;
}


