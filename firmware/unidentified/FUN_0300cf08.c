/**
 * FUN_0300cf08 @ 0x0300cf08
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300cf08(undefined4 param_1,int param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  
  FUN_02fe6148();
  uVar2 = 0;
  if (param_3 >> 1 != 0) {
    do {
      uVar1 = *(ushort *)(param_2 + uVar2 * 2);
      *(ushort *)(param_2 + uVar2 * 2) = uVar1 << 8 | uVar1 >> 8;
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < param_3 >> 1);
    return;
  }
  return;
}


