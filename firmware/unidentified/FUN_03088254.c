/**
 * FUN_03088254 @ 0x03088254
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03088254(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  uVar11 = (uint)*(short *)(param_1 + 0x188);
  iVar4 = *(int *)(param_1 + 0xd8);
  bVar13 = true;
  if (0 < (int)(uVar11 - 1)) {
    psVar6 = *(short **)(param_1 + 0x18c);
    psVar7 = psVar6 + -1;
    if ((uVar11 & 1) == 0) {
      bVar13 = *(int *)(iVar4 + *psVar6 * 0xfc + 0x30) == 0;
      psVar7 = psVar6;
    }
    sVar2 = psVar7[1];
    for (iVar9 = (int)(uVar11 - 1) >> 1; iVar9 != 0; iVar9 = iVar9 + -1) {
      iVar10 = (int)sVar2;
      sVar2 = psVar7[3];
      bVar13 = (bool)(bVar13 & *(int *)(iVar4 + iVar10 * 0xfc + 0x30) == 0 &
                     *(int *)(iVar4 + psVar7[2] * 0xfc + 0x30) == 0);
      psVar7 = psVar7 + 2;
    }
  }
  if (-1 < (int)(uVar11 - 1)) {
    bVar13 = (bool)(bVar13 & *(int *)(iVar4 + *(short *)(*(int *)(param_1 + 0x18c) +
                                                        (uVar11 - 1) * 2) * 0xfc + 0x30) == 0);
  }
  bVar12 = *(int *)(param_1 + 0x40) == 2;
  if (*(int *)(param_1 + 0x40) < 3) {
    bVar12 = param_2 == 0;
  }
  if (((bVar12) && (*(char *)(iVar4 + 0x50) != '\0')) && (!bVar13)) {
    uVar1 = *(ushort *)(param_1 + 0x26);
    uVar8 = (uint)uVar1;
    piVar5 = *(int **)(iVar4 + 0x44);
    piVar3 = *(int **)(iVar4 + 0x140);
    uVar11 = 0;
    if (uVar8 != 0) {
      uVar11 = uVar8 & 1;
    }
    if (uVar8 != 0 && (uVar1 & 1) != 0) {
      *(undefined4 *)(iVar4 + 0x30) = 1;
    }
    if (uVar11 < *(ushort *)(param_1 + 0x26)) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0xd8) + uVar11 * 0xfc + 0x30) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0xd8) + uVar11 * 0xfc + 300) = 1;
        uVar11 = (uint)(short)((short)uVar11 + 2);
      } while ((int)uVar11 < (int)(uint)*(ushort *)(param_1 + 0x26));
    }
    iVar4 = (int)*(short *)(iVar4 + 0x82);
    if (0 < iVar4) {
      do {
        iVar9 = *piVar5;
        iVar10 = *piVar3;
        iVar4 = iVar4 + -1;
        *piVar5 = iVar9 + iVar10;
        *piVar3 = iVar9 - iVar10;
        piVar3 = piVar3 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 != 0);
    }
  }
  return 0;
}


