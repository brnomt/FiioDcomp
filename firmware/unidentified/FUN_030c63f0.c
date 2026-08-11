/**
 * FUN_030c63f0 @ 0x030c63f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c63f0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  piVar1 = DAT_030c66e8;
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 0) {
    iVar3 = DAT_030c66f0 + *DAT_030c66e8 * 0x10;
    memset_byte(iVar3,0,0x10);
    iVar2 = *piVar1 + 1;
    *piVar1 = iVar2;
    if (0x2c < iVar2) {
      return 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar3 + 0xc);
  }
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  return iVar3;
}


