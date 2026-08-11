/**
 * FUN_0302af78 @ 0x0302af78
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302af78(void)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  psVar1 = DAT_0302b0e8;
  iVar3 = 20000;
  if (*DAT_0302b0e8 != 4) {
    *(undefined4 *)(DAT_0302b0dc + 0x24) = 0;
    FUN_03005604(0);
    *psVar1 = 4;
    iVar2 = rom_buffer_ready(5);
    while ((iVar2 == 1 && (iVar3 = iVar3 + -1, iVar3 != 0))) {
      dac_gain_curve_apply(1);
      iVar2 = rom_buffer_ready(5);
    }
    *DAT_0302b0ec = 0;
    *DAT_0302b0f0 = 0;
  }
  return 1;
}


