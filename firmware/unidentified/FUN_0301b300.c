/**
 * FUN_0301b300 @ 0x0301b300
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301b300(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1[1] == 0) {
    uVar1 = 0x10;
  }
  else {
    if ((param_2[5] == 0) || (param_2[6] == 0)) {
      iVar2 = (*(code *)*DAT_0301b728)(*param_1,param_1[1],*DAT_0301b724);
    }
    else {
      iVar3 = param_1[1] - (param_2[6] - *param_2);
      if (*param_2 == param_2[6]) {
        iVar3 = 0;
        iVar2 = (*(code *)*DAT_0301b728)(*param_2,param_1[1],*DAT_0301b724);
      }
      else {
        FUN_02ff5d5a(*param_2,param_2[6],iVar3);
        iVar2 = (*(code *)*DAT_0301b728)(*param_2 + iVar3,param_1[1] - iVar3,*DAT_0301b724);
      }
    }
    if (iVar2 == 0) {
      param_1[1] = 0;
      uVar1 = 0x10;
    }
    else {
      param_1[1] = iVar2 + iVar3;
      FUN_0301c3b4(param_2,*param_1,param_1[1]);
      uVar1 = 0;
    }
  }
  return uVar1;
}


