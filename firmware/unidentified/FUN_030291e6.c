/**
 * FUN_030291e6 @ 0x030291e6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_030291e6(undefined4 param_1,code *param_2,undefined4 param_3,undefined4 *param_4,int param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_02ffb400(DAT_03029490,0x40);
  iVar1 = FUN_0302905e(DAT_03029490,param_4,param_5,param_6,param_7);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(param_5 + 0x16) < 1) {
      (*param_2)(*param_4,*(undefined4 *)(param_5 + 10),0);
    }
    else {
      (*param_2)(*param_4,*(int *)(DAT_03029490 + 0xc) * (*(int *)(DAT_03029490 + 4) + -1) +
                          *(int *)(param_5 + 10),0);
    }
    uVar2 = 1;
  }
  return uVar2;
}


