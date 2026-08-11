/**
 * FUN_030a2bfa @ 0x030a2bfa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a2bfa(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  uVar8 = (param_2 << 0xf) / ((int)(short)param_3 << 1);
  iVar7 = (param_2 - (param_2 >> 0x1f)) * 0x8000 >> 0x10;
  iVar2 = FUN_030a2b1c(iVar7 * 0x61 >> 2);
  iVar3 = FUN_030a2b1c(((iVar7 * iVar7 & 0x7fffU) * 5 >> 0xd) + (short)(iVar7 * iVar7 >> 0xf) * 0x14
                      );
  iVar1 = DAT_030a2e5c;
  iVar7 = iVar7 * 0xd1b + iVar2 * 0x68cd + iVar3 * 0x11ec;
  iVar3 = (((param_1 + -1) * 0x10000 >> 0x11) + iVar7) / (param_1 + -1);
  *(int *)(DAT_030a2e5c + 0x1b00) = param_1;
  *(int *)(iVar1 + 0x1b04) = param_3;
  iVar2 = 0;
  if (0 < param_3) {
    do {
      iVar9 = (int)(short)((short)iVar2 * (short)((uVar8 << 1) >> 0x10) +
                          (short)((int)((uVar8 & 0x7fff) * (int)(short)iVar2 + 0x4000) >> 0xf));
      iVar4 = FUN_030a2b1c(iVar9 * 0x61 >> 2);
      iVar5 = FUN_030a2b1c((iVar9 * iVar9 * 2 >> 0x10) * 0x14 +
                           ((iVar9 * iVar9 & 0x7fffU) * 5 >> 0xd));
      iVar4 = iVar9 * 0xd1b + iVar4 * 0x68cd + iVar5 * 0x11ec;
      if (iVar7 < iVar4) {
        return iVar1;
      }
      iVar5 = iVar4 / iVar3;
      if (param_1 + -2 < iVar5) {
        sVar6 = 0x7fff;
        iVar5 = param_1 + -2;
      }
      else {
        sVar6 = (short)((iVar4 - iVar5 * iVar3) / ((iVar3 + 0x4000) * 2 >> 0x10));
      }
      *(int *)(iVar1 + iVar2 * 4) = iVar5;
      iVar4 = iVar1 + iVar2 * 2;
      *(short *)(iVar4 + 0x1200) = 0x7fff - sVar6;
      *(int *)(iVar1 + iVar2 * 4 + 0x900) = iVar5 + 1;
      *(short *)(iVar4 + 0x1680) = sVar6;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return iVar1;
}


