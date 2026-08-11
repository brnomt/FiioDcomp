/**
 * FUN_030a4a44 @ 0x030a4a44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a4a44(uint param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_2;
  if (iVar2 < 0x59) {
    iVar3 = *(int *)(DAT_030a4e4c + iVar2 * 4);
    iVar1 = iVar3 >> 3;
    if ((param_1 & 1) != 0) {
      iVar1 = iVar1 + (iVar3 >> 2);
    }
    if ((param_1 & 2) != 0) {
      iVar1 = iVar1 + (iVar3 >> 1);
    }
    if ((param_1 & 4) != 0) {
      iVar1 = iVar1 + iVar3;
    }
    if ((param_1 & 8) != 0) {
      iVar1 = -iVar1;
    }
    param_3 = param_3 + iVar1;
    if (param_3 < 0x8000) {
      if (param_3 < -0x8000) {
        param_3 = DAT_030a4e50;
      }
    }
    else {
      param_3 = 0x7fff;
    }
    iVar2 = *(int *)(DAT_030a4e54 + (param_1 & 7) * 4) + iVar2;
    *param_2 = iVar2;
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    *param_2 = iVar2;
    if (0x58 < iVar2) {
      iVar2 = 0x58;
    }
    *param_2 = iVar2;
    return (int)(short)param_3;
  }
  return 0;
}


