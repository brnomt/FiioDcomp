/**
 * FUN_0301f8bc @ 0x0301f8bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301f8bc(short *param_1,short *param_2,uint param_3,short param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  
  uVar1 = DAT_0301f934;
  iVar3 = param_3 * 2;
  if ((param_3 & 1) == 0) {
    param_3 = param_3 - 1;
  }
  param_4 = *param_2 * param_4;
  *param_1 = param_4;
  if (param_4 < -0x800) {
    *param_1 = (short)uVar1;
  }
  else if (0x7ff < param_4) {
    *param_1 = 0x7ff;
  }
  iVar2 = 1;
  do {
    iVar5 = (int)param_2[iVar2];
    if (iVar5 == 0) {
      param_1[iVar2] = 0;
    }
    else {
      if (iVar5 < 0) {
        iVar5 = param_3 - iVar3 * iVar5;
        sVar4 = (short)uVar1;
        if (iVar5 < 0x801) {
          sVar4 = -(short)iVar5;
        }
      }
      else {
        iVar5 = iVar3 * iVar5 + param_3;
        if (0x7ff < iVar5) {
          iVar5 = 0x7ff;
        }
        sVar4 = (short)iVar5;
      }
      param_1[iVar2] = sVar4;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  return 0;
}


