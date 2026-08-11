/**
 * FUN_030a0a90 @ 0x030a0a90
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a0a90(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_030a0b04;
  *DAT_030a0b04 = param_1;
  uVar3 = FUN_030a25aa(0x100);
  puVar2 = DAT_030a0b08;
  *DAT_030a0b08 = uVar3;
  if (*piVar1 < 0x241) {
    uVar3 = FUN_030a1116(*piVar1,param_2,uVar3);
    puVar2[1] = uVar3;
    return 1;
  }
  return 0xffffffff;
}


