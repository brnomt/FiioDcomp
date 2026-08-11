/**
 * FUN_030e8918 @ 0x030e8918
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030e8918(int param_1,undefined4 param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int extraout_r3;
  int iVar6;
  
  iVar2 = FUN_030e5964(param_1,*param_3,param_3[1]);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar3 = FUN_030e595c(param_1);
  iVar2 = DAT_030e8ae8;
  if (iVar3 < 3) {
    return -1;
  }
  do {
    FUN_030e6372(param_1,0x4000);
    bVar1 = FUN_030e57da(param_1,3);
    if (bVar1 == 7) {
      FUN_030e578e(param_1);
      iVar2 = FUN_030e578e(param_1);
      return iVar2 + 7 >> 3;
    }
    iVar3 = extraout_r3;
    if (bVar1 == 1) {
      iVar3 = 2;
    }
    if (bVar1 < 2) {
      if (bVar1 != 1) goto LAB_030e8984;
    }
    else {
      if (bVar1 != 3) {
        return -1;
      }
LAB_030e8984:
      iVar3 = 1;
    }
    iVar4 = *(int *)(param_1 + 0x10);
    if (iVar4 < iVar6 + iVar3) {
      return -1;
    }
    if (iVar4 < (int)((uint)*(byte *)(iVar2 + iVar4 * 8 + iVar6 + -8) + iVar3)) {
      return -1;
    }
    iVar4 = FUN_030e82d8(param_1,param_2);
    if ((iVar4 < 0) && (iVar5 = FUN_030e595c(param_1), iVar5 != 0)) {
      return iVar4;
    }
    iVar4 = FUN_030e595c(param_1);
    iVar6 = iVar6 + iVar3;
    if (iVar4 < 3) {
      return -1;
    }
  } while( true );
}


