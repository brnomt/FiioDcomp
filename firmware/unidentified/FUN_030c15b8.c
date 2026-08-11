/**
 * FUN_030c15b8 @ 0x030c15b8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c15b8(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_030c18f8;
  if (DAT_030c18f8[4] == 1) {
    hifi_busy_delay_ovl_0bff(1);
    iVar3 = DAT_030c1900;
    do {
      if (piVar1[4] != 1) goto LAB_030c15e0;
      hifi_busy_delay_ovl_0bff(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_030bfd16(s_AudioFileInput2__timeout___030c190c);
  }
LAB_030c15e0:
  *(undefined1 *)(DAT_030c18fc + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_030bf680(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030c1904 + piVar1[7] * 4) = uVar2;
  return 0;
}


