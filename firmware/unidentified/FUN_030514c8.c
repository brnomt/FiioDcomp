/**
 * FUN_030514c8 @ 0x030514c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030514c8(void)

{
  int iVar1;
  undefined2 *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  ushort uVar6;
  short sVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  
  puVar3 = DAT_03051664;
  puVar2 = DAT_03051660;
  iVar1 = DAT_03051658;
  if ((*(uint *)(DAT_03051658 + 0x18) < 0x7d01) &&
     (*(int *)(DAT_03051658 + 0x28) == 2 || *(int *)(DAT_03051658 + 0x28) == 0)) {
    uVar12 = 0x4000;
  }
  else {
    uVar12 = 0x5000;
  }
  if (*(int *)(DAT_03051658 + 0x4c) - 0x200U < (*(uint *)(DAT_03051658 + 0x50) >> 10) + 1) {
    FUN_0303a438(0x70);
    FUN_0303a438(0x61);
    *puVar2 = 3;
    return 0;
  }
  if (DAT_03051664[2] < uVar12) {
    return 1;
  }
  uVar13 = (uint)(ushort)*DAT_03051664;
  iVar10 = DAT_0305165c + *(short *)(DAT_03051658 + 8) * 0x27e;
  iVar11 = (int)(char)*(short *)(DAT_03051658 + 8);
  if ((int)uVar12 < (int)(0xc000 - uVar13)) {
    uVar6 = FUN_0302edec(DAT_03051668 + uVar13,*(undefined4 *)(iVar10 + 0x10),uVar12,iVar11);
  }
  else {
    sVar7 = FUN_0302edec(DAT_03051668 + uVar13,*(undefined4 *)(iVar10 + 0x10),0xc000 - uVar13,iVar11
                        );
    sVar8 = FUN_0302edec(DAT_03051668,
                         *(undefined4 *)(DAT_0305165c + *(short *)(iVar1 + 8) * 0x27e + 0x10),
                         uVar12 - (0xc000 - uVar13),(int)(char)*(short *)(iVar1 + 8));
    uVar6 = sVar8 + sVar7;
  }
  uVar4 = DAT_0305166c;
  if (uVar12 != uVar6) {
    FUN_0303a438(0x71);
    *puVar2 = 3;
    return 0;
  }
  uVar9 = (uint)uVar6 + *(int *)(iVar1 + 0x50);
  *(uint *)(iVar1 + 0x50) = uVar9;
  if (uVar4 < uVar9 >> 10) {
    FUN_0303a438(0x78);
    puVar5 = DAT_03051670;
    *puVar2 = 3;
    *puVar5 = 1;
  }
  puVar3[2] = puVar3[2] - uVar12;
  *puVar3 = (uVar13 + uVar12) % 0xc000;
  return 1;
}


