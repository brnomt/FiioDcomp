/**
 * FUN_030f6e14 @ 0x030f6e14
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f6e14(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_030f7150;
  if (DAT_030f7150[4] == 1) {
    hifi_busy_delay_ovl_0f53(1);
    iVar3 = DAT_030f7158;
    do {
      if (piVar1[4] != 1) goto LAB_030f6e3c;
      hifi_busy_delay_ovl_0f53(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_030f50a4(s_AudioFileInput2__timeout___030f7164);
  }
LAB_030f6e3c:
  *(undefined1 *)(DAT_030f7154 + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_030f49d4(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030f715c + piVar1[7] * 4) = uVar2;
  return 0;
}


