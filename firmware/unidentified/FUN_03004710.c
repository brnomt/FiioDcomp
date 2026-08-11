/**
 * FUN_03004710 @ 0x03004710
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03004710(int param_1)

{
  ushort *puVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  byte abStack_138 [256];
  undefined1 auStack_38 [8];
  int local_30;
  int local_28;
  ushort local_24 [4];
  
  if (*(char *)(DAT_03004ae4 + 0x35c) != '\0') {
    return 0xffffffff;
  }
  func_0x02fdfc5e(DAT_03004aec,DAT_03004ae8,0x118);
  puVar1 = DAT_03004aec;
  iVar6 = DAT_03004ae8;
  puVar8 = &DAT_03004af0;
  *(undefined **)(DAT_03004aec + 8) = &DAT_03004af0;
  uVar4 = DAT_03004afc;
  piVar3 = DAT_03004af8;
  pcVar2 = DAT_03004af4;
  if (*(short *)(iVar6 + 0xf2) == 99) {
    if (*DAT_03004af4 != '\x03') {
      uVar5 = FUN_02fe5872(*(undefined4 *)(puVar1 + 0x1a),&DAT_03004af0,3);
      goto LAB_030047d6;
    }
  }
  else {
    local_28 = *(int *)(iVar6 + 0x34);
    FUN_02ff30d0(DAT_03004afc,
                 *DAT_03004af8 * 0x200 + 0xa600000 + (local_28 + *(int *)(iVar6 + 0x38) + -1) * 2,2,
                 local_24);
    FUN_02ff30d0(uVar4,*piVar3 * 0x200 + 0x8000000 + (local_28 + (uint)local_24[0]) * 0x10,0x10,
                 auStack_38);
    FUN_02ff30d0(uVar4,*piVar3 * 0x200 + local_30 * 0x800,4,&local_28);
    FUN_02ff30d0(uVar4,*piVar3 * 0x200 + local_30 * 0x800 + 0x34,0x2a,puVar1 + 0x28);
    *DAT_03004b00 = (char)puVar1[0x2e];
    *(undefined4 *)(puVar1 + 0x28) = *(undefined4 *)(puVar1 + 0x1a);
    *(undefined4 *)(puVar1 + 0x2a) = *(undefined4 *)(puVar1 + 0x1c);
    puVar8 = *(undefined **)(puVar1 + 8);
    if (*pcVar2 != '\x03') {
      uVar5 = FUN_02fe5872(*(undefined4 *)(puVar1 + 0x1a),puVar8,3);
      goto LAB_030047d6;
    }
  }
  uVar5 = FUN_02fe59fa(puVar1 + 0x28,puVar8,3);
LAB_030047d6:
  *puVar1 = uVar5;
  iVar6 = 0;
  do {
    if (*(short *)(param_1 + iVar6 * 2) == 0) break;
    iVar6 = (int)(short)((short)iVar6 + 1);
  } while (iVar6 < 0x80);
  uVar10 = iVar6 - 4U & 0xffff;
  iVar6 = FUN_02fe57ac(puVar1 + 10,puVar1 + 0x1a,*(undefined4 *)(puVar1 + 8),3);
  if ((iVar6 == 0) && (puVar1[1] = 1, *puVar1 != 0)) {
    do {
      if (*pcVar2 == '\x03') {
        FUN_02fe4f14(puVar1 + 0x28,*(int *)(puVar1 + 0x1c) + -1,3,abStack_138);
      }
      else {
        FUN_02fe5d7c(*(undefined4 *)(puVar1 + 0x1a),*(int *)(puVar1 + 0x1c) + -1,3,abStack_138);
      }
      uVar9 = 0;
      if (uVar10 != 0) {
        do {
          uVar7 = (uint)*(byte *)(param_1 + uVar9 * 2);
          uVar11 = (uint)abStack_138[uVar9 * 2];
          if (uVar7 - 0x61 < 0x1a) {
            uVar7 = uVar7 - 0x20 & 0xff;
          }
          if (uVar11 - 0x61 < 0x1a) {
            uVar11 = uVar11 - 0x20 & 0xff;
          }
        } while ((uVar7 == uVar11) &&
                (uVar9 = (uint)(short)((short)uVar9 + 1), (int)uVar9 < (int)uVar10));
      }
      if (uVar9 == uVar10) {
        return 0;
      }
      iVar6 = FUN_02fe5780(puVar1 + 10,puVar1 + 0x1a,*(undefined4 *)(puVar1 + 8),3);
      uVar5 = puVar1[1] + 1;
      puVar1[1] = uVar5;
      bVar12 = uVar5 == *puVar1;
      if (uVar5 <= *puVar1) {
        bVar12 = iVar6 == 0;
      }
    } while (bVar12);
  }
  return 0xffffffff;
}


