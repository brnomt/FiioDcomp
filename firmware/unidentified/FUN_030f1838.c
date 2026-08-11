/**
 * FUN_030f1838 @ 0x030f1838
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f1838(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  piVar1 = DAT_030f1984;
  local_28 = *DAT_030f1990;
  uStack_24 = DAT_030f1990[1];
  uStack_20 = DAT_030f1990[2];
  uStack_1c = DAT_030f1990[3];
  *DAT_030f1984 = 0;
  FUN_030ed70e(piVar1[2]);
  FUN_030ed858(piVar1[2],param_1,param_2,param_3,&local_28,0);
  iVar2 = *piVar1;
  while (iVar2 == 0) {
    FUN_030f0fb4();
    iVar2 = *piVar1;
  }
  FUN_030ed6f0(piVar1[2]);
  return;
}


