/**
 * FUN_030e083c @ 0x030e083c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e083c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_030e0868 + param_1 * 0x50;
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


