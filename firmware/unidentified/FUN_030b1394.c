/**
 * FUN_030b1394 @ 0x030b1394
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030b1394(undefined1 *param_1,int param_2)

{
  short sVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int local_10;
  
  iVar3 = DAT_030b1514;
  iVar4 = 0;
  local_10 = param_2;
  if ((*(int *)(DAT_030b1518 + 0x4c) != 0) && (*(short *)(DAT_030b1514 + 0xd0) == 1)) {
    *(undefined4 *)(DAT_030b1518 + 0x4c) = 0;
    *param_1 = 0x23;
    param_1[1] = 0x21;
    param_1[2] = 0x41;
    param_1[3] = 0x4d;
    puVar2 = param_1 + 5;
    param_1[4] = 0x52;
    local_10 = param_2 + -6;
    param_1 = param_1 + 6;
    *puVar2 = 10;
    iVar4 = 6;
  }
  sVar1 = *(short *)(DAT_030b1514 + 0xd0);
  if (sVar1 == 1 || sVar1 == 3) {
    iVar3 = 1;
  }
  else if (sVar1 == 2) {
    iVar3 = FUN_030b056e(iVar3 + 0x2e0,DAT_030b1514,param_1,&local_10);
  }
  else {
    iVar3 = -1;
  }
  iVar3 = iVar3 + iVar4;
  if (iVar3 < 1) {
    iVar3 = 0;
  }
  return iVar3;
}


