/**
 * FUN_030e9848 @ 0x030e9848
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e9848(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_030e98a0 + param_1 * 0x50;
  if (param_2 == 0) {
    return *(undefined4 *)(iVar1 + 0xc);
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      if (param_2 == 3) {
        uVar2 = *(undefined4 *)(iVar1 + 0x24);
      }
      else {
        uVar2 = 0;
      }
      return uVar2;
    }
    return *(undefined4 *)(iVar1 + 0x1c);
  }
  return *(undefined4 *)(iVar1 + 0x14);
}


