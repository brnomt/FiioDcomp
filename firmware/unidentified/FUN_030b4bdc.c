/**
 * FUN_030b4bdc @ 0x030b4bdc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030b4bdc(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_030b4f1c;
  if (DAT_030b4f1c[4] == 1) {
    hifi_busy_delay_ovl_0ab8(1);
    iVar3 = DAT_030b4f24;
    do {
      if (piVar1[4] != 1) goto LAB_030b4c04;
      hifi_busy_delay_ovl_0ab8(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_ovl(s_AudioFileInput2__timeout___030b4f30);
  }
LAB_030b4c04:
  *(undefined1 *)(DAT_030b4f20 + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_030ab020(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030b4f28 + piVar1[7] * 4) = uVar2;
  return 0;
}


