/**
 * FUN_0304cbf2 @ 0x0304cbf2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0304cbf2(uint *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  longlong *plVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  
  iVar7 = DAT_0304cdd8 + param_3 * 0x14;
  iVar15 = *(int *)(iVar7 + 0x144);
  iVar11 = *(int *)(iVar7 + 0x148);
  iVar12 = *(int *)(iVar7 + 0x140);
  iVar13 = *(int *)(iVar7 + 0x14c);
  iVar7 = *(int *)(iVar7 + 0x150);
  plVar8 = (longlong *)(DAT_0304cdd8 + (param_3 + param_4 * 10) * 0x10);
  lVar4 = *plVar8;
  iVar9 = DAT_0304cdd8 + (param_3 * 2 + param_4 * 0x14) * 8;
  plVar2 = (longlong *)(iVar9 + 8);
  lVar3 = *plVar2;
  iVar16 = 0;
  if (0 < param_2) {
    lVar6 = *plVar2;
    lVar4 = *plVar8;
    do {
      uVar10 = *param_1;
      uVar5 = (longlong)(int)uVar10 * (longlong)iVar11 + lVar4 >> 10;
      iVar1 = (int)(uVar5 >> 0x20);
      lVar4 = uVar5 * (longlong)iVar12;
      iVar14 = (int)((ulonglong)lVar4 >> 0x20);
      lVar3 = uVar5 * (longlong)iVar15;
      iVar17 = (int)((ulonglong)lVar3 >> 0x20);
      lVar3 = (longlong)(int)uVar10 * (longlong)iVar7 +
              CONCAT44(iVar17 >> 10,(uint)lVar3 >> 10 | iVar17 * 0x400000);
      lVar4 = (longlong)(int)uVar10 * (longlong)iVar13 +
              lVar6 + CONCAT44(iVar14 >> 10,(uint)lVar4 >> 10 | iVar14 * 0x400000);
      uVar10 = iVar1 >> 0x1f;
      if (uVar10 != iVar1 >> 1) {
        uVar5 = CONCAT44(uVar10,~uVar10) ^ 0x100000000;
      }
      *param_1 = (uint)uVar5 >> 10 | (int)(uVar5 >> 0x20) << 0x16;
      iVar16 = (int)(short)((short)iVar16 + 1);
      param_1 = param_1 + 2;
      lVar6 = lVar3;
    } while (iVar16 < param_2);
  }
  *plVar8 = lVar4;
  *(longlong *)(iVar9 + 8) = lVar3;
  return;
}


