/**
 * FUN_0309fcc0 @ 0x0309fcc0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0309fcc0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_0309fffc;
  if (DAT_0309fffc[4] == 1) {
    hifi_busy_delay_ovl_09e3(1);
    iVar3 = DAT_030a0004;
    do {
      if (piVar1[4] != 1) goto LAB_0309fce8;
      hifi_busy_delay_ovl_09e3(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_ovl_09e0(s_AudioFileInput2__timeout___030a0010);
  }
LAB_0309fce8:
  *(undefined1 *)(DAT_030a0000 + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_0309d924(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030a0008 + piVar1[7] * 4) = uVar2;
  return 0;
}


