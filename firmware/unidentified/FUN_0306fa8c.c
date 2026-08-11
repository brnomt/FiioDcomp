/**
 * FUN_0306fa8c @ 0x0306fa8c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0306fa8c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0306d3a2(param_1,DAT_0306fd74,8);
  if (((iVar1 == 0) && (((uint)*(byte *)(param_1 + 8) | *(int *)(param_1 + 9) << 8) < 0x7d1)) &&
     (uVar2 = (uint)*(byte *)(param_1 + 0xc) | *(int *)(param_1 + 0xd) << 8,
     uVar2 - 0x20 < 0x1000001)) {
    return uVar2;
  }
  return 0;
}


