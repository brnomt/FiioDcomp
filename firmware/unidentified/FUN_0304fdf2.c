/**
 * FUN_0304fdf2 @ 0x0304fdf2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304fdf2(short *param_1)

{
  short sVar1;
  bool bVar2;
  
  if (param_1 == (short *)0x0) {
    return 0;
  }
  sVar1 = *param_1;
  if (sVar1 != 0x75) {
    bVar2 = sVar1 == 0x70 || sVar1 == 0x71;
    if (sVar1 == 0x70 || sVar1 == 0x71) {
      bVar2 = param_1[1] == 0x62;
    }
    if (!bVar2) {
      return 0;
    }
  }
  return 1;
}


