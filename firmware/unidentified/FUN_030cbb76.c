/**
 * FUN_030cbb76 @ 0x030cbb76
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030cbb76(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = param_1[0x1a];
  if (param_1[0x1c] == param_2) {
    if (2 < iVar1) {
      return 0;
    }
  }
  else {
    if (iVar1 == 5) {
      FUN_030c3f8e(param_1[0x23]);
      param_1[0x23] = 0;
      param_1[0x1a] = 3;
    }
    else if (iVar1 < 3) goto LAB_030cbbc6;
    FUN_030c7b12(param_1 + 0xc);
    FUN_030c7ab4(param_1 + 0x14);
    param_1[0x1a] = 2;
  }
LAB_030cbbc6:
  piVar2 = (int *)(param_1[8] + param_2 * 8);
  iVar1 = *piVar2;
  iVar4 = piVar2[1];
  if (*param_1 != -1) {
    (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],iVar1,iVar4,0);
    param_1[2] = iVar1;
    param_1[3] = iVar4;
    FUN_030c6c66(param_1[6]);
  }
  FUN_030c756e(param_1[0x22],*(undefined4 *)(param_1[10] + param_2 * 4));
  param_1[0x1b] = *(int *)(param_1[10] + param_2 * 4);
  param_1[0x1c] = param_2;
  uVar3 = FUN_030cba38(param_1,param_1 + 0xc,param_1 + 0x14,param_1 + 0x1b,0);
  return uVar3;
}


