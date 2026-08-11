/**
 * FUN_030f03cc @ 0x030f03cc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f03cc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_1 + 0x954);
  *(int *)(param_1 + 0x24) = param_2;
  if ((~*(uint *)(param_1 + 0x1c) & 3) == 0) {
    FUN_030ed106(puVar2,0,param_2 << 2);
    FUN_030ed106((undefined4 *)(param_1 + 0x4954),0,param_2 << 2);
  }
  else if (param_3 == 0) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      uVar1 = FUN_030ef8d0(param_1,param_1 + 0x8978);
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    }
  }
  else if (param_2 != 0) {
    puVar3 = (undefined4 *)(param_1 + 0x4954);
    do {
      param_2 = param_2 + -1;
      uVar1 = FUN_030ef8d0(param_1,param_1 + 0x8978);
      *puVar2 = uVar1;
      uVar1 = FUN_030ef8d0(param_1,param_1 + 0x8970);
      *puVar3 = uVar1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (param_2 != 0);
  }
  if (*(int *)(param_1 + 0x24) == *(int *)(param_1 + 0x20)) {
    FUN_030ef7b0(param_1);
    return;
  }
  return;
}


