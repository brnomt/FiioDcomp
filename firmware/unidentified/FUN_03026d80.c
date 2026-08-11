/**
 * FUN_03026d80 @ 0x03026d80
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03026d80(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_03026df8;
  iVar3 = 0;
  *DAT_03026df8 = param_1;
  FUN_03026564();
  iVar2 = FUN_03027280();
  if (iVar2 != 0) {
    iVar3 = -1;
  }
  iVar2 = FUN_03026c46();
  if ((iVar2 == 0) && (iVar2 = FUN_03026b52(), iVar2 == 0)) {
    iVar2 = FUN_03026c02();
  }
  if (iVar2 != 0) {
    iVar3 = -1;
  }
  iVar2 = *piVar1;
  *(int *)(iVar2 + 0x1c) = (int)*DAT_03026e04;
  *(int *)(iVar2 + 0x20) = (int)*DAT_03026e08;
  if (iVar3 != 0) {
    FUN_03027548();
  }
  return iVar3;
}


