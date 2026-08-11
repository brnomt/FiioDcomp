/**
 * FUN_03026c02 @ 0x03026c02
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026c02(void)

{
  int iVar1;
  
  iVar1 = FUN_0302742e();
  if (iVar1 != 0) {
    FUN_030266b4();
    FUN_0302850a();
    iVar1 = FUN_030274e0();
    if (iVar1 == 0) {
      FUN_02ff8a10(DAT_03026e14,*DAT_03026e10 << 2);
      *DAT_03026e18 = 0;
      if (*DAT_03026e1c != 0) {
        *DAT_03026e20 = *DAT_03026e1c;
        *DAT_03026e24 = 0;
      }
      FUN_030275f6();
      return 0;
    }
  }
  return 0xffffff28;
}


