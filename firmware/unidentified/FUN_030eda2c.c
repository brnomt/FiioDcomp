/**
 * FUN_030eda2c @ 0x030eda2c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030eda2c(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_030edd78;
  piVar1 = DAT_030edd74;
  if ((undefined4 *)*DAT_030edd74 != DAT_030edd78) {
    *DAT_030edd78 = DAT_030edd7c;
    puVar2[1] = DAT_030edd80;
    uVar3 = DAT_030edd84;
    uVar5 = 1;
    puVar2[2] = DAT_030edd84;
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


