/**
 * FUN_0302ce68 @ 0x0302ce68
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_0302ce68(int param_1,int param_2)

{
  short sVar1;
  int *piVar2;
  uint *puVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  short sVar15;
  uint uVar16;
  short *psVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  
  FUN_0302cfb8();
  iVar21 = *DAT_0302d350;
  psVar17 = (short *)(param_1 + 2);
  uVar7 = *DAT_0302d354;
  uVar5 = DAT_0302d354[1];
  uVar12 = DAT_0302d354[2];
  uVar9 = DAT_0302d354[3];
  iVar20 = param_2;
  do {
    uVar19 = uVar5;
    uVar18 = uVar7;
    iVar20 = iVar20 + -1;
    sVar1 = *psVar17;
    uVar14 = sVar1 * 0x2000;
    sVar15 = (short)iVar21;
    uVar5 = sVar15 * -0x4000;
    iVar11 = iVar21 >> 0x10;
    iVar21 = CONCAT22(sVar15,sVar1);
    uVar6 = iVar11 * 0x2000;
    uVar16 = uVar6 + uVar5 + uVar14;
    uVar7 = (uint)((ulonglong)uVar18 * 0x3fef);
    uVar10 = uVar19 * 0x3fef + (int)((ulonglong)uVar18 * 0x3fef >> 0x20);
    if ((int)uVar10 < 0) {
      uVar7 = ~uVar7;
      iVar11 = ~uVar10 + (uint)(0xfffffffe < uVar7);
      uVar7 = ~(uVar7 + 1 >> 0xd | iVar11 * 0x80000);
      uVar8 = uVar7 + 1;
      iVar11 = ~(iVar11 >> 0xd) + (uint)(0xfffffffe < uVar7);
    }
    else {
      uVar8 = uVar7 >> 0xd | uVar10 * 0x80000;
      iVar11 = (int)uVar10 >> 0xd;
    }
    uVar10 = uVar8 + uVar16;
    uVar7 = (uint)((ulonglong)uVar12 * 0xffffe011);
    uVar12 = uVar9 * -0x1fef + ((int)((ulonglong)uVar12 * 0xffffe011 >> 0x20) - uVar12);
    if ((int)uVar12 < 0) {
      uVar7 = ~uVar7;
      iVar13 = ~uVar12 + (uint)(0xfffffffe < uVar7);
      uVar7 = ~(uVar7 + 1 >> 0xd | iVar13 * 0x80000);
      uVar9 = uVar7 + 1;
      iVar13 = ~(iVar13 >> 0xd) + (uint)(0xfffffffe < uVar7);
    }
    else {
      uVar9 = uVar7 >> 0xd | uVar12 * 0x80000;
      iVar13 = (int)uVar12 >> 0xd;
    }
    uVar7 = uVar9 + uVar10;
    uVar5 = iVar13 + iVar11 + ((int)uVar5 >> 0x1f) +
                              ((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar5,uVar14) +
                              ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,uVar5 + uVar14) +
                              (uint)CARRY4(uVar8,uVar16) + (uint)CARRY4(uVar9,uVar10);
    if ((int)uVar5 < 0) {
      if ((uVar5 == 0xffffffff) && (uVar7 >> 0x1c == 0xf)) {
        sVar4 = ~(ushort)(~uVar7 + 1 >> 0xd) + 1;
      }
      else {
        sVar4 = -0x8000;
      }
    }
    else if ((uVar5 == 0) && (uVar7 >> 0x1c == 0)) {
      sVar4 = (short)(uVar7 >> 0xd);
    }
    else {
      sVar4 = 0x7fff;
    }
    *psVar17 = sVar4;
    piVar2 = DAT_0302d350;
    psVar17 = psVar17 + 2;
    uVar12 = uVar18;
    uVar9 = uVar19;
  } while (iVar20 != 0);
  *(short *)DAT_0302d350 = sVar1;
  *(short *)((int)piVar2 + 2) = sVar15;
  puVar3 = DAT_0302d354;
  *DAT_0302d354 = uVar7;
  puVar3[1] = uVar5;
  puVar3[2] = uVar18;
  puVar3[3] = uVar19;
  return CONCAT44(param_2,(short *)(param_1 + 2));
}


