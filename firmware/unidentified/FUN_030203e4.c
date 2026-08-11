/**
 * FUN_030203e4 @ 0x030203e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030203e4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  piVar1 = DAT_03020430;
  uVar4 = *(uint *)(param_1 + 0x78);
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      FUN_030202ce(param_1,param_2,param_3,param_4);
      uVar3 = uVar3 + 1;
      *piVar1 = *piVar1 + 1;
    } while (uVar3 < uVar4);
  }
  puVar2 = puRam03020444;
  *piVar1 = 0;
  *puVar2 = 1;
  return;
}


