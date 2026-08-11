/**
 * FUN_030ddfe8 @ 0x030ddfe8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ddfe8(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_030de328;
  if (DAT_030de328[4] == 1) {
    hifi_busy_delay_ovl_0dc7(1);
    iVar3 = DAT_030de330;
    do {
      if (piVar1[4] != 1) goto LAB_030de010;
      hifi_busy_delay_ovl_0dc7(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_ovl_0dc5(s_AudioFileInput2__timeout___030de33c);
  }
LAB_030de010:
  *(undefined1 *)(DAT_030de32c + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_030dbed4(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030de334 + piVar1[7] * 4) = uVar2;
  return 0;
}


