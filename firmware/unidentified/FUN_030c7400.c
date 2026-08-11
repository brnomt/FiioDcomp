/**
 * FUN_030c7400 @ 0x030c7400
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c7400(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_28 [20];
  
  iVar1 = FUN_030c68e6(auStack_28,*param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_030c69b6(auStack_28,0xe);
  }
  else {
    iVar1 = -1;
  }
  iVar2 = FUN_030c68e6(auStack_28,*param_2);
  if (iVar2 == 0) {
    iVar2 = sbuf_byte_at(auStack_28,4);
  }
  else {
    iVar2 = -1;
  }
  iVar3 = param_1[6];
  if (iVar3 != iVar1) {
    if (param_2 != (int *)0x0) {
      FUN_030c673e(*param_2);
      FUN_030c673e(param_2[2]);
      memset_byte(param_2,0,0x10);
    }
    return 0xfffffff3;
  }
  if (0 < iVar2) {
    if (param_2 != (int *)0x0) {
      FUN_030c673e(*param_2);
      FUN_030c673e(param_2[2]);
      memset_byte(param_2,0,0x10);
    }
    return 0xfffffff4;
  }
  if (param_1[3] == 0) {
    param_1[3] = param_2[2];
    iVar1 = param_2[2];
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 0xc);
    }
    if (iVar1 != 0 && iVar3 != 0) {
      do {
        iVar1 = iVar3;
        iVar3 = *(int *)(iVar1 + 0xc);
      } while (*(int *)(iVar1 + 0xc) != 0);
      iVar3 = 0;
    }
  }
  else {
    iVar3 = param_1[2];
    iVar1 = param_2[2];
    if (iVar3 != 0) {
      for (iVar2 = *(int *)(iVar3 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
        iVar3 = iVar2;
      }
      *(int *)(iVar3 + 0xc) = iVar1;
      if (iVar1 != 0) {
        iVar3 = *(int *)(iVar1 + 0xc);
      }
      iVar2 = iVar3;
      if (iVar1 != 0 && iVar3 != 0) {
        do {
          iVar1 = iVar2;
          iVar3 = 0;
          iVar2 = *(int *)(iVar1 + 0xc);
        } while (*(int *)(iVar1 + 0xc) != 0);
      }
    }
  }
  param_1[2] = iVar1;
  if (param_1[1] == 0) {
    param_1[1] = *param_2;
    iVar1 = *param_2;
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 0xc);
    }
    if (iVar1 != 0 && iVar3 != 0) {
      do {
        iVar1 = iVar3;
        iVar3 = *(int *)(iVar1 + 0xc);
      } while (*(int *)(iVar1 + 0xc) != 0);
    }
    *param_1 = iVar1;
    param_1[0xc] = -0x1b;
  }
  else {
    iVar1 = *param_1;
    iVar2 = *param_2;
    if (iVar1 != 0) {
      for (iVar3 = *(int *)(iVar1 + 0xc); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
        iVar1 = iVar3;
      }
      *(int *)(iVar1 + 0xc) = iVar2;
      if (iVar2 != 0) {
        iVar1 = *(int *)(iVar2 + 0xc);
      }
      if (iVar2 != 0 && iVar1 != 0) {
        do {
          iVar2 = iVar1;
          iVar1 = *(int *)(iVar2 + 0xc);
        } while (*(int *)(iVar2 + 0xc) != 0);
      }
    }
    *param_1 = iVar2;
  }
  memset_byte(param_2,0,0x10);
  return 0;
}


