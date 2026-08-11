/**
 * FUN_030b1610 @ 0x030b1610
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030b1610(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  
  uVar1 = ((uint)param_1[1] >> (0x1f - (param_2 & 0x1f) & 0xff)) >> 1;
  iVar5 = (param_2 & 0x1f) - param_1[2];
  if (iVar5 < 1) {
    return uVar1;
  }
  uVar6 = 0;
  iVar2 = -7 - iVar5;
  uVar7 = iVar2 + ((uint)(iVar2 >> 0x1f) >> 0x1d);
  iVar3 = (int)uVar7 >> 3;
  pbVar8 = (byte *)*param_1;
  iVar9 = -iVar3;
  if (iVar3 != 0 && -1 < iVar9) {
    pbVar4 = pbVar8 + -1;
    if ((uVar7 & 8) != 0) {
      uVar6 = (uint)*pbVar8;
      pbVar4 = pbVar8;
    }
    for (iVar9 = iVar9 >> 1; iVar9 != 0; iVar9 = iVar9 + -1) {
      pbVar8 = pbVar4 + 1;
      pbVar4 = pbVar4 + 2;
      uVar6 = (uint)*pbVar4 | ((uint)*pbVar8 | uVar6 << 8) << 8;
    }
    iVar5 = iVar5 + (iVar2 / 8) * 8;
  }
  return uVar1 | uVar6 >> (-iVar5 & 0xffU);
}


