/**
 * FUN_03029b80 @ 0x03029b80
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03029b80(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0xc) + 0xc);
  if (uVar1 < 0x1f400) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    if (iVar2 == 32000) {
      uVar1 = uVar1 - 22000;
    }
    else {
      if (iVar2 != 0xac44) goto LAB_03029ba6;
      uVar1 = uVar1 - 48000;
    }
    if (999 < uVar1) {
LAB_03029ba6:
      FUN_0300c558(7);
      return;
    }
  }
  FUN_0300c558(8);
  return;
}


