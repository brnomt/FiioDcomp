/**
 * FUN_03081b38 @ 0x03081b38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03081b38(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_03081e80;
  piVar1 = DAT_03081e7c;
  if ((undefined4 *)*DAT_03081e7c != DAT_03081e80) {
    *DAT_03081e80 = DAT_03081e84;
    puVar2[1] = DAT_03081e88;
    uVar3 = DAT_03081e8c;
    uVar5 = 1;
    puVar2[2] = DAT_03081e8c;
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


