/**
 * FUN_030ef820 @ 0x030ef820
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ef820(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  FUN_030ef7b0();
  uVar1 = *(uint *)(param_1 + 0x8964) >> (param_2 & 0xff);
  *(uint *)(param_1 + 0x8964) = uVar1;
  uVar2 = *(uint *)(param_1 + 0x8960);
  *(uint *)(param_1 + 0x8960) = uVar2 - uVar1 * (uVar2 / uVar1);
  return;
}


