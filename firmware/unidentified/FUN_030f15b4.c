/**
 * FUN_030f15b4 @ 0x030f15b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f15b4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_030f15e0 + param_1 * 0x50;
  if (param_2 == 0) {
    return *(undefined4 *)(iVar1 + 8);
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      if (param_2 == 3) {
        uVar2 = *(undefined4 *)(iVar1 + 0x20);
      }
      else {
        uVar2 = 0;
      }
      return uVar2;
    }
    return *(undefined4 *)(iVar1 + 0x18);
  }
  return *(undefined4 *)(iVar1 + 0x10);
}


