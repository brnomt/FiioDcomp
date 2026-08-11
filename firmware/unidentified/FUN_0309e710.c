/**
 * FUN_0309e710 @ 0x0309e710
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0309e710(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_0309ea5c;
  piVar1 = DAT_0309ea58;
  if ((undefined4 *)*DAT_0309ea58 != DAT_0309ea5c) {
    *DAT_0309ea5c = DAT_0309ea60;
    puVar2[1] = DAT_0309ea64;
    uVar3 = DAT_0309ea68;
    uVar5 = 1;
    puVar2[2] = DAT_0309ea68;
    iVar4 = 1;
    do {
      puVar2[iVar4 + 2] = uVar3;
      uVar5 = uVar5 + 2;
      puVar2[iVar4 + 3] = uVar3;
      iVar4 = iVar4 + 2;
    } while (uVar5 < 0x37);
    *piVar1 = (int)puVar2;
  }
  puVar2[param_1] = param_2;
  return;
}


