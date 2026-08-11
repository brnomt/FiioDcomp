/**
 * FUN_030a418c @ 0x030a418c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a418c(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = DAT_030a4540;
  puVar1 = DAT_030a4534;
  *(undefined4 *)(param_1 + 0x821c) = *(undefined4 *)(param_1 + 0x8214);
  uVar3 = (*(code *)*puVar2)(*puVar1);
  if (uVar3 < param_2) {
    param_2 = (*(code *)*puVar2)(*puVar1);
  }
  *(uint *)(param_1 + 0x8220) = param_2;
  return 1;
}


