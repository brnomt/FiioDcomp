/**
 * FUN_030e0ac0 @ 0x030e0ac0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e0ac0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  piVar1 = DAT_030e0c0c;
  local_28 = *DAT_030e0c18;
  uStack_24 = DAT_030e0c18[1];
  uStack_20 = DAT_030e0c18[2];
  uStack_1c = DAT_030e0c18[3];
  *DAT_030e0c0c = 0;
  FUN_030dc7f2(piVar1[2]);
  FUN_030dc93c(piVar1[2],param_1,param_2,param_3,&local_28,0);
  iVar2 = *piVar1;
  while (iVar2 == 0) {
    FUN_030de630();
    iVar2 = *piVar1;
  }
  FUN_030dc7d4(piVar1[2]);
  return;
}


