/**
 * FUN_030ca0ca @ 0x030ca0ca
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ca0ca(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 >> 2 < 1) {
    return;
  }
  puVar1 = (undefined4 *)(param_2 + -4);
  puVar2 = param_3 + -1;
  if ((param_1 >> 2 & 1U) != 0) {
    *param_3 = *(undefined4 *)(param_2 + 4);
    puVar1 = (undefined4 *)(param_2 + 4);
    puVar2 = param_3;
  }
  param_1 = param_1 >> 3;
  if (param_1 == 0) {
    return;
  }
  do {
    puVar2[1] = puVar1[2];
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 2;
    *puVar2 = *puVar1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}


