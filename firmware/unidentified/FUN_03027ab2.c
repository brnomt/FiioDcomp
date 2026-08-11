/**
 * FUN_03027ab2 @ 0x03027ab2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03027ab2(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)(*(ushort *)(DAT_03027e38 + 0x54) >> 8);
  uVar2 = *(uint *)(param_1 + uVar3 * 4);
  if ((int)uVar2 < 0) {
    FUN_03027a7c(8);
    do {
      iVar1 = FUN_03027592(1);
      uVar2 = *(uint *)(param_1 + ((1 - iVar1) + ~uVar2) * 4 + 0x500);
    } while ((int)uVar2 < 0);
  }
  else {
    FUN_03027a7c(uVar2);
    uVar2 = (uint)*(byte *)(param_1 + uVar3 + 0x400);
  }
  return uVar2;
}


