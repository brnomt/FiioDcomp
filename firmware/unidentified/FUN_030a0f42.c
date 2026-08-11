/**
 * FUN_030a0f42 @ 0x030a0f42
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a0f42(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  sVar1 = (short)param_2;
  sVar3 = (short)param_1;
  if (param_2 < param_1) {
    iVar4 = FUN_030a0b86((int)(short)(sVar3 * 0xec));
    if (iVar4 >> 1 < 0x8000) {
      iVar4 = FUN_030a0b86((int)(short)(sVar3 * 0xec));
      sVar2 = (short)(iVar4 >> 1);
    }
    else {
      sVar2 = 0x7fff;
    }
    iVar7 = (int)(short)((sVar1 - sVar3) * 0x1d8);
    iVar4 = FUN_030a0b86(iVar7);
    if (iVar4 >> 1 < 0x8000) {
      iVar4 = FUN_030a0b86(iVar7);
      sVar3 = (short)(iVar4 >> 1);
    }
    else {
      sVar3 = 0x7fff;
    }
    iVar4 = 0;
    if (0 < param_6) {
      do {
        uVar5 = *(uint *)(param_4 + iVar4 * 4);
        iVar6 = *(int *)(param_3 + iVar4 * 4) + 0x40 >> 7;
        iVar7 = (int)sVar3 * ((int)(uVar5 << 1) >> 0x10) +
                iVar6 + ((int)((int)sVar3 * (uVar5 & 0x7fff)) >> 0xf);
        iVar6 = uVar5 + iVar6 + 1;
        if (iVar7 >> 0xf < iVar6) {
          if (0x7fffff < iVar6) {
            iVar7 = iVar7 >> 8;
            iVar6 = iVar6 >> 8;
          }
          if (0x7ffff < iVar6) {
            iVar7 = iVar7 >> 4;
            iVar6 = iVar6 >> 4;
          }
          if (0x7fff < iVar6) {
            iVar7 = iVar7 >> 4;
            iVar6 = iVar6 >> 4;
          }
          iVar7 = (int)(short)((iVar7 * 0x7fff) / (int)(short)iVar6);
        }
        else {
          iVar7 = 0x7fff;
        }
        iVar7 = FUN_030a0b0c(iVar7 << 0xf);
        *(short *)(param_5 + iVar4 * 2) = (short)((uint)(iVar7 * sVar2 * 2) >> 0x10);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_6);
      return;
    }
    return;
  }
  iVar4 = FUN_030a0b86((int)(short)(sVar1 * 0xec));
  if (iVar4 >> 1 < 0x8000) {
    iVar4 = FUN_030a0b86((int)(short)(sVar1 * 0xec));
    sVar2 = (short)(iVar4 >> 1);
  }
  else {
    sVar2 = 0x7fff;
  }
  iVar7 = (int)(short)((sVar3 - sVar1) * 0x1d8);
  iVar4 = FUN_030a0b86(iVar7);
  if (iVar4 >> 1 < 0x8000) {
    iVar4 = FUN_030a0b86(iVar7);
    sVar3 = (short)(iVar4 >> 1);
  }
  else {
    sVar3 = 0x7fff;
  }
  iVar4 = 0;
  if (0 < param_6) {
    do {
      iVar6 = *(int *)(param_4 + iVar4 * 4);
      uVar5 = *(int *)(param_3 + iVar4 * 4) + 0x40;
      iVar7 = (int)sVar3 * ((int)uVar5 >> 0x16) + iVar6 +
              ((int)((int)sVar3 * ((uVar5 & 0x3fffff) >> 7)) >> 0xf);
      iVar6 = ((int)uVar5 >> 7) + 1 + iVar6;
      if (iVar7 >> 0xf < iVar6) {
        if (0x7fffff < iVar6) {
          iVar7 = iVar7 >> 8;
          iVar6 = iVar6 >> 8;
        }
        if (0x7ffff < iVar6) {
          iVar7 = iVar7 >> 4;
          iVar6 = iVar6 >> 4;
        }
        if (0x7fff < iVar6) {
          iVar7 = iVar7 >> 4;
          iVar6 = iVar6 >> 4;
        }
        iVar7 = (int)(short)((iVar7 * 0x7fff) / (int)(short)iVar6);
      }
      else {
        iVar7 = 0x7fff;
      }
      iVar7 = FUN_030a0b0c(iVar7 << 0xf);
      *(short *)(param_5 + iVar4 * 2) = (short)((uint)(iVar7 * sVar2 * 2) >> 0x10);
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_6);
    return;
  }
  return;
}


