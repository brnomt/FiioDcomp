/**
 * FUN_030ef1b0 @ 0x030ef1b0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ef1b0(void)

{
  longlong lVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  short sVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  uVar3 = DAT_030ef57c;
  piVar2 = DAT_030ef578;
  iVar7 = FUN_030f0474();
  piVar9 = DAT_030ef588;
  *DAT_030ef588 = iVar7;
  if (iVar7 != 0) {
    log_printf_ts(s_ape_tag_len___d_030ef58c,iVar7);
  }
  *piVar2 = 0;
  iVar7 = bitreader_get_u32_be(uVar3);
  if (iVar7 != s_MAC_tag_error____030ef5a0._0_4_) {
    log_printf_ts(s_MAC_tag_error____030ef5a0 + 4);
    return 0xffffffff;
  }
  sVar5 = FUN_030f064c(uVar3);
  *(short *)(piVar2 + 8) = sVar5;
  if (0xdc < (int)sVar5 - 0xf6eU) {
    log_printf_ts(s_file_version_error____Max_versio_030ef5b4);
    return 0xfffffffe;
  }
  if (sVar5 < 0xf8c) {
    piVar2[9] = 0;
    piVar2[10] = 0x20;
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)(piVar2 + 0x14) = uVar6;
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)((int)piVar2 + 0x52) = uVar6;
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)((int)piVar2 + 0x62) = uVar6;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0x19] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0xc] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0xf] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0x17] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0x16] = iVar7;
    if ((*(byte *)((int)piVar2 + 0x52) & 4) != 0) {
      FUN_030f06ee(uVar3,4,1);
      piVar2[10] = piVar2[10] + 4;
    }
    if ((*(byte *)((int)piVar2 + 0x52) & 0x10) == 0) {
      piVar2[0xb] = piVar2[0x17] << 2;
    }
    else {
      iVar7 = bitreader_get_u32_be(uVar3);
      piVar2[0xb] = iVar7;
      piVar2[10] = piVar2[10] + 4;
      piVar2[0xb] = piVar2[0xb] << 2;
    }
    if ((*(ushort *)((int)piVar2 + 0x52) & 1) == 0) {
      if ((*(ushort *)((int)piVar2 + 0x52) & 8) == 0) {
        *(undefined2 *)(piVar2 + 0x18) = 0x10;
      }
      else {
        *(undefined2 *)(piVar2 + 0x18) = 0x18;
      }
    }
    else {
      *(undefined2 *)(piVar2 + 0x18) = 8;
    }
    sVar5 = (short)piVar2[8];
    if (sVar5 < 0xf6e) {
      if ((sVar5 < 0xf3c) && ((sVar5 < 0xed8 || (*(ushort *)(piVar2 + 0x14) < 4000)))) {
        iVar7 = 0x2400;
      }
      else {
        iVar7 = 0x12000;
      }
      piVar2[0x15] = iVar7;
    }
    else {
      piVar2[0x15] = 0x48000;
    }
    if ((*(byte *)((int)piVar2 + 0x52) & 0x20) == 0) {
      FUN_030f06d0(uVar3,(short)piVar2[0xc]);
    }
  }
  else {
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)((int)piVar2 + 0x22) = uVar6;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[9] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[10] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0xb] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0xc] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0xd] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0xe] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0xf] = iVar7;
    FUN_030f0712(uVar3,piVar2 + 0x10,0x10);
    if (0x34 < (uint)piVar2[9]) {
      FUN_030f06ee(uVar3,piVar2[9] - 0x34U & 0xffff,1);
    }
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)(piVar2 + 0x14) = uVar6;
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)((int)piVar2 + 0x52) = uVar6;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0x15] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0x16] = iVar7;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0x17] = iVar7;
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)(piVar2 + 0x18) = uVar6;
    uVar6 = FUN_030f064c(uVar3);
    *(undefined2 *)((int)piVar2 + 0x62) = uVar6;
    iVar7 = bitreader_get_u32_be(uVar3);
    piVar2[0x19] = iVar7;
  }
  iVar7 = (*(code *)*DAT_030ef5f4)(*DAT_030ef5f0);
  piVar2[0x1a] = iVar7;
  iVar7 = piVar2[0x15] * (piVar2[0x17] + -1) + piVar2[0x16];
  piVar2[0x1b] = iVar7;
  uVar17 = FUN_030eeb0e(piVar2[0x19]);
  uVar18 = FUN_030eeb0e(iVar7);
  uVar18 = FUN_030ee94c((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,DAT_030ef5f8);
  FUN_030eea30((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
               (int)((ulonglong)uVar17 >> 0x20));
  iVar7 = FUN_030eeb50();
  piVar2[0x1c] = iVar7;
  uVar17 = FUN_030eeb0e();
  piVar4 = DAT_030ef5fc;
  lVar1 = (ulonglong)(uint)((piVar2[0x1a] - *DAT_030ef5fc) - *piVar9) * 8000;
  uVar18 = FUN_030eeb28((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
  FUN_030eea30((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
               (int)((ulonglong)uVar17 >> 0x20));
  iVar7 = FUN_030eeb50();
  piVar2[0x1d] = iVar7;
  log_printf_ts(&DAT_030ef600,(int)(short)piVar2[8]);
  log_printf_ts(&DAT_030ef60c,(short)piVar2[0x14]);
  log_printf_ts(&DAT_030ef618,piVar2[0x17]);
  log_printf_ts(&DAT_030ef624,piVar2[0x15]);
  log_printf_ts(&DAT_030ef634,(short)piVar2[0x18]);
  log_printf_ts(&DAT_030ef640,piVar2[0x19]);
  log_printf_ts(&DAT_030ef64c,*(undefined2 *)((int)piVar2 + 0x62));
  log_printf_ts(&DAT_030ef658,piVar2[0x1a]);
  log_printf_ts(&DAT_030ef668,piVar2[0x1c]);
  log_printf_ts(&DAT_030ef674,piVar2[0x1d]);
  if (0xaf0 < (uint)piVar2[0x17]) {
    log_printf_ts(&DAT_030ef680);
    return 0xfffffffd;
  }
  iVar7 = FUN_030f0800(piVar2[0x17] << 5);
  piVar2[4] = iVar7;
  if (iVar7 == 0) {
    return 0xfffffffc;
  }
  piVar2[3] = 0;
  piVar2[1] = *piVar2 + piVar2[9] + piVar2[10] + piVar2[0xb] + piVar2[0xc];
  piVar2[2] = piVar2[0x16];
  if (1 < (uint)piVar2[0x17]) {
    piVar2[2] = piVar2[0x15] * (piVar2[0x17] - 1U) + piVar2[0x16];
  }
  if (piVar2[0xb] != 0) {
    iVar7 = FUN_030f0800(piVar2[0x17] << 2);
    piVar2[0x1f] = iVar7;
    uVar12 = 0;
    if (piVar2[0x17] != 0) {
      do {
        iVar7 = bitreader_get_u32_be(uVar3);
        *(int *)(piVar2[0x1f] + uVar12 * 4) = iVar7 + *piVar4;
        uVar12 = uVar12 + 1;
      } while (uVar12 < (uint)piVar2[0x17]);
    }
    FUN_030f06d0(uVar3,(short)piVar2[0xb] + (short)piVar2[0x17] * -4);
  }
  piVar9 = (int *)piVar2[4];
  *piVar9 = piVar2[1] + *piVar4;
  piVar9[1] = 0;
  *(int *)(piVar2[4] + 8) = piVar2[0x15];
  *(undefined4 *)(piVar2[4] + 0x10) = 0;
  uVar12 = 1;
  if (1 < (uint)piVar2[0x17]) {
    do {
      puVar16 = (undefined4 *)(piVar2[4] + uVar12 * 0x20);
      *puVar16 = *(undefined4 *)(piVar2[0x1f] + uVar12 * 4);
      puVar16[1] = 0;
      *(int *)(piVar2[4] + uVar12 * 0x20 + 8) = piVar2[0x15];
      iVar7 = piVar2[4];
      *(int *)(iVar7 + uVar12 * 0x20 + -0x14) =
           *(int *)(iVar7 + uVar12 * 0x20) - *(int *)(iVar7 + uVar12 * 0x20 + -0x20);
      piVar9 = (int *)piVar2[4];
      piVar9[uVar12 * 8 + 4] = piVar9[uVar12 * 8] - *piVar9 & 3;
      uVar12 = uVar12 + 1;
    } while (uVar12 < (uint)piVar2[0x17]);
  }
  *(int *)(piVar2[4] + piVar2[0x17] * 0x20 + -0x14) = piVar2[0x16] << 2;
  *(int *)(piVar2[4] + piVar2[0x17] * 0x20 + -0x18) = piVar2[0x16];
  iVar7 = piVar2[0x17];
  if (iVar7 != 0) {
    iVar8 = 0;
    do {
      iVar10 = iVar8 * 0x20 + 0x10;
      uVar12 = *(uint *)(piVar2[4] + iVar10);
      if (uVar12 != 0) {
        puVar13 = (uint *)(piVar2[4] + iVar8 * 0x20);
        uVar15 = *puVar13;
        *puVar13 = uVar15 - uVar12;
        puVar13[1] = (puVar13[1] - ((int)uVar12 >> 0x1f)) - (uint)(uVar15 < uVar12);
        iVar11 = piVar2[4];
        iVar14 = iVar8 * 0x20 + 0xc;
        *(int *)(iVar11 + iVar14) = *(int *)(iVar11 + iVar10) + *(int *)(iVar11 + iVar14);
      }
      iVar10 = iVar8 * 0x20 + 0xc;
      iVar8 = iVar8 + 1;
      *(uint *)(piVar2[4] + iVar10) = *(int *)(piVar2[4] + iVar10) + 3U & 0xfffffffc;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return 1;
}


