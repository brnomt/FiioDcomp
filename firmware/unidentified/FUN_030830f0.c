/**
 * FUN_030830f0 @ 0x030830f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030830f0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_03083430;
  if (DAT_03083430[4] == 1) {
    hifi_busy_delay_ovl_0817(1);
    iVar3 = DAT_03083438;
    do {
      if (piVar1[4] != 1) goto LAB_03083118;
      hifi_busy_delay_ovl_0817(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_03081592(s_AudioFileInput2__timeout___03083444);
  }
LAB_03083118:
  *(undefined1 *)(DAT_03083434 + 1) = 0;
  piVar1[4] = 1;
  uVar2 = HifiFileRead_ovl(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_0308343c + piVar1[7] * 4) = uVar2;
  return 0;
}


