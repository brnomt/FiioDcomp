/**
 * FUN_03017d6a @ 0x03017d6a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03017d6a(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  longlong lVar7;
  ushort *puVar8;
  ushort *puVar9;
  byte *pbVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  bool bVar16;
  
  pbVar10 = DAT_03017fa4;
  puVar9 = DAT_03017fa0;
  puVar8 = DAT_03017f80;
  iVar14 = DAT_03017f74;
  iVar13 = param_1 - DAT_03017f94;
  bVar1 = *(byte *)(DAT_03017f74 + 1);
  if (param_1 == DAT_03017f94) {
LAB_03017ef6:
    if (bVar1 == 0) {
      return 0;
    }
    FUN_03017cca(0);
    func_0x030037a8(0x1b3);
    return 0;
  }
  if (DAT_03017f94 <= param_1) {
    if (iVar13 == 0x38) {
      uVar6 = *DAT_03017f80;
      *DAT_03017fa0 = uVar6;
      bVar1 = (byte)puVar8[1];
      *(byte *)(puVar9 + 1) = bVar1;
      bVar2 = (byte)puVar8[2];
      *(byte *)((int)puVar9 + 3) = bVar2;
      bVar3 = (byte)puVar8[3];
      *pbVar10 = bVar3;
      bVar4 = (byte)puVar8[4];
      pbVar10[1] = bVar4;
      bVar5 = (byte)puVar8[5];
      pbVar10[2] = bVar5;
      *(undefined1 *)(iVar14 + 1) = 0;
      uVar11 = DAT_03017fa8;
      iVar14 = DAT_03017f7c;
      *(byte *)(DAT_03017f7c + 4) =
           bVar3 + (char)(uint)((ulonglong)DAT_03017fa8 * (ulonglong)(uint)bVar3 >> 0x23) * -10 +
           (char)(bVar3 / 10 << 4) & 0x3f;
      *(byte *)(iVar14 + 3) =
           bVar4 + (char)(uint)((ulonglong)uVar11 * (ulonglong)(uint)bVar4 >> 0x23) * -10 +
           (char)(bVar4 / 10 << 4) & 0x7f;
      *(byte *)(iVar14 + 2) =
           bVar5 + (char)(uint)((ulonglong)uVar11 * (ulonglong)(uint)bVar5 >> 0x23) * -10 +
           (char)(bVar5 / 10 << 4) & 0x7f;
      iVar13 = uVar6 - 2000;
      lVar7 = (longlong)DAT_03017fac * (longlong)iVar13;
      *(char *)(iVar14 + 8) =
           (char)iVar13 + ((char)(int)(lVar7 >> 0x22) - (char)(lVar7 >> 0x3f)) * '\x06';
      *(byte *)(iVar14 + 5) =
           bVar2 + (char)(uint)((ulonglong)uVar11 * (ulonglong)(uint)bVar2 >> 0x23) * -10 +
           (char)(bVar2 / 10 << 4) & 0x3f;
      *(byte *)(iVar14 + 7) =
           bVar1 + (char)(uint)((ulonglong)uVar11 * (ulonglong)(uint)bVar1 >> 0x23) * -10 +
           (char)(bVar1 / 10 << 4) & 0x1f;
      iVar14 = FUN_02ffcda8(0);
      if (iVar14 == 0) {
        FUN_02ffcda8(0);
      }
    }
    else {
      iVar14 = iVar13 + -0xff8;
      bVar15 = iVar14 != 0;
      bVar16 = iVar14 != 0xf000;
      if (bVar15 && bVar16) {
        iVar14 = iVar13 + -0x10000ff8;
      }
      if ((bVar15 && bVar16) && iVar14 != 0xf000) {
        return 0;
      }
    }
    FUN_02ff26bc(DAT_03017fb0);
    func_0x030037a8(199);
    return 1;
  }
  iVar14 = param_1 - DAT_03017f98;
  if (param_1 == DAT_03017f98) goto LAB_03017ef6;
  if (param_1 < DAT_03017f98) {
    if (iVar14 == -6) {
LAB_03017ee8:
      if (bVar1 < 6) {
        *(byte *)(DAT_03017f74 + 1) = bVar1 + 1;
      }
      else {
        *(undefined1 *)(DAT_03017f74 + 1) = 0;
      }
      uVar12 = 0xde;
      goto LAB_03017f14;
    }
    if (iVar14 != -4) {
      return 0;
    }
  }
  else {
    if (iVar14 + DAT_03017f9c == 0) goto LAB_03017ee8;
    if (iVar14 + DAT_03017f9c != 2) {
      return 0;
    }
  }
  if (bVar1 == 0) {
    return 0;
  }
  FUN_03017cca(1);
  uVar12 = 0x1b3;
LAB_03017f14:
  func_0x030037a8(uVar12);
  return 0;
}


