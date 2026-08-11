/**
 * FUN_030eeeee @ 0x030eeeee
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030eeeee(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  param_1 = param_1 * 0x3c;
  if (param_2 < 0xf8c) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80000000;
  }
  *(uint *)(param_1 + 0x1060020) = uVar1;
  if (param_3 != 1000) {
    if (param_3 == 2000) {
      uVar1 = uVar1 | 0x40b0000;
    }
    else if (param_3 == 3000) {
      uVar1 = *(uint *)(param_1 + 0x1060020) | 0x100b0000;
    }
    else if (param_3 == 4000) {
      uVar1 = *(uint *)(param_1 + 0x1060020) | 0x280ad000;
    }
    else {
      if (param_3 != 5000) {
        return;
      }
      uVar1 = *(uint *)(param_1 + 0x1060020) | DAT_030eef5c;
    }
    *(uint *)(param_1 + 0x1060020) = uVar1;
    return;
  }
  return;
}


