/**
 * FUN_0300ced6 @ 0x0300ced6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0300ced6(int param_1,short *param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = 0;
  sVar1 = *param_2;
  while (sVar1 != 0) {
    *(short *)(param_1 + param_3 * 2) = sVar1;
    uVar2 = uVar2 + 1 & 0xffff;
    param_1 = param_1 + 2;
    param_2 = param_2 + 1;
    if (0x12 < uVar2 + param_3) break;
    sVar1 = *param_2;
  }
  return uVar2 + param_3 & 0xffff;
}


