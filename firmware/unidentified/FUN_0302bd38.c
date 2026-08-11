/**
 * FUN_0302bd38 @ 0x0302bd38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0302bd38(char *param_1)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  short sVar6;
  ushort *puVar7;
  char *pcVar8;
  uint *puVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  int *piVar12;
  short *psVar13;
  ushort uVar14;
  ushort uVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  int iVar19;
  int extraout_r1;
  int iVar20;
  uint uVar21;
  int iVar22;
  int unaff_r7;
  bool bVar23;
  uint in_stack_00000000;
  undefined4 in_stack_00000008;
  
  if (*param_1 == '\0') {
    *DAT_0302be6c = *(undefined4 *)(*(int *)(unaff_r7 + 0xc) + 8);
  }
  FUN_0302b5a4();
  puVar10 = DAT_0302be74;
  puVar9 = DAT_0302be70;
  puVar7 = DAT_0302be34;
  if (*DAT_0302be34 == 0) {
    uVar17 = func_0x0300bba6();
    if (0x32 < uVar17 - puVar9[2]) {
      puVar9[2] = uVar17;
      if (*puVar9 == 0) {
        FUN_0302c96e(DAT_0302be78);
        *(undefined4 *)(unaff_r7 + 0x10) = 0;
      }
      uVar17 = *puVar9;
      *puVar9 = uVar17 + 1;
      if (5 < uVar17 + 1) {
        FUN_0302c96e();
        if (in_stack_00000000 - puVar9[1] < 600) {
          *puVar9 = 0;
          *(undefined4 *)(unaff_r7 + 8) = 0;
          *(int *)(unaff_r7 + 0x10) = *(int *)(unaff_r7 + 0x10) + 8000;
          *puVar10 = 1;
          FUN_0302a74e(1);
          *DAT_0302c288 = *DAT_0302c284;
          shared_frame_epilogue_c6b4(0x110);
        }
        else {
          *puVar9 = 0;
          puVar9[1] = in_stack_00000000;
          *(undefined4 *)(unaff_r7 + 0x10) = 0;
        }
      }
    }
  }
  else {
    DAT_0302be70[2] = 0;
    *puVar9 = 0;
    puVar9[1] = *(uint *)(*(int *)(unaff_r7 + 0xc) + 4);
  }
  pcVar8 = DAT_0302be58;
  iVar19 = DAT_0302be24;
  cVar3 = *DAT_0302be58;
  if (cVar3 != *(char *)(unaff_r7 + 3)) {
    *(char *)(unaff_r7 + 3) = cVar3;
    if (cVar3 == '\0') {
LAB_0302be7c:
      rom_i2s_dma_start(2,0);
      rom_audio_path_route(2,0,1);
      rom_audio_path_disable(2,0);
      rom_i2s_dma_start(2,0xe,0);
      rom_audio_path_route(2,0xe,1);
      rom_audio_path_disable(2,0xe,1);
    }
    else {
      if (*(char *)(iVar19 + 0x34a) == '\0') {
        *pcVar8 = '\0';
        goto LAB_0302be7c;
      }
      rom_i2s_dma_start(2,0);
      rom_audio_path_route(2,0,1);
      rom_audio_path_disable(2,0,1);
      rom_i2s_dma_start(2,0xe,0);
      rom_audio_path_route(2,0xe,1);
      rom_audio_path_disable(2,0xe,0);
    }
    FUN_03007f4c();
    FUN_0302aad4();
  }
  iVar16 = FUN_02ffa74a(2,8);
  if (iVar16 == 0) {
    iVar16 = FUN_030055e8();
    if (iVar16 == 0) {
      FUN_030055e2(1);
      iVar16 = FUN_0300c714(0x2b);
      if (iVar16 == 0) {
        FUN_0302aad4();
      }
    }
    *(undefined1 *)(unaff_r7 + 2) = 0;
  }
  else if (*(byte *)(unaff_r7 + 2) < 0x3d) {
    *(byte *)(unaff_r7 + 2) = *(byte *)(unaff_r7 + 2) + 1;
  }
  else {
    iVar16 = FUN_030055e8();
    if (iVar16 == 1) {
      FUN_030055e2(0);
      iVar16 = FUN_0300c714(0x2b);
      if (iVar16 == 0) {
        FUN_0302aad4();
      }
    }
    else {
      FUN_030055e2(0);
    }
  }
  pbVar11 = _DAT_0302c28c;
  if (*puVar7 == 0) {
    FUN_0300ad0c();
    cVar3 = *(char *)(iVar19 + 0x34a);
    if (cVar3 != *_DAT_0302c290) {
      *_DAT_0302c290 = cVar3;
      if (cVar3 == '\0') {
        rom_i2s_dma_start(2,0);
        rom_audio_path_route(2,0,1);
        rom_audio_path_disable(2,0);
        rom_i2s_dma_start(2,0xe,0);
        rom_audio_path_route(2,0xe,1);
        rom_audio_path_disable(2,0xe,1);
        *pcVar8 = '\0';
        FUN_03007f4c();
        *pbVar11 = 0;
        shared_frame_epilogue_c6b4(0x2b);
        *_DAT_0302c294 = 2;
        shared_frame_epilogue_c6b4(0x23);
        *_DAT_0302c298 = *DAT_0302c284;
      }
      else {
        rom_i2s_dma_start(2,0);
        rom_audio_path_route(2,0,1);
        rom_audio_path_disable(2,0,1);
        rom_i2s_dma_start(2,0xe,0);
        rom_audio_path_route(2,0xe,1);
        rom_audio_path_disable(2,0xe,0);
        *pcVar8 = '\x01';
        FUN_03007f4c();
      }
    }
  }
  iVar16 = FUN_0300c714(0x2b);
  piVar12 = _DAT_0302c29c;
  if ((iVar16 != 0) && (*puVar7 == 0)) {
    if (*_DAT_0302c29c == 0) {
      if (*DAT_0302c284 / 3 != *_DAT_0302c2a0) {
        *_DAT_0302c2a0 = *DAT_0302c284 / 3;
        bVar5 = *(byte *)(piVar12 + 4);
        bVar4 = *pbVar11;
        *pbVar11 = bVar5;
        if (bVar5 < bVar4) {
          shared_mid_entry_c6f6(0x2b);
          cVar3 = *(char *)(iVar19 + 0x34a);
        }
        else {
          FUN_03005604();
          *pbVar11 = *(byte *)(_DAT_0302c29c + 4);
          cVar3 = *(char *)(iVar19 + 0x34a);
        }
        if (cVar3 != '\0') {
          shared_frame_epilogue_c6b4(0x1d5);
        }
        shared_mid_entry_c6f6(0x2b);
      }
    }
    else {
      FUN_03005604((char)_DAT_0302c29c[4]);
      shared_mid_entry_c6f6(0x2b);
    }
  }
  iVar16 = FUN_0300c6d0(0x2a);
  if (iVar16 != 0) {
    uVar14 = *puVar7;
    bVar23 = uVar14 == 0;
    if (bVar23) {
      uVar14 = (ushort)*(byte *)(iVar19 + 0x34a);
    }
    if (bVar23 && uVar14 == 0) {
      MusicService(0xed,0);
      shared_frame_epilogue_c6b4(0x42);
    }
  }
  iVar16 = FUN_0300c6d0(0x1b7);
  psVar13 = _DAT_0302c2a4;
  if (iVar16 != 0) {
    if (*puVar7 == 0) {
      if (*(char *)(iVar19 + 0x34a) != '\0') {
        if (*_DAT_0302c2a4 == 2) {
          FUN_0300afd8(0x87);
          iVar16 = FUN_0300c6d0(0x1ca);
          if (iVar16 != 0) {
            FUN_0300b00a(_DAT_0302c2ac,(int)*_DAT_0302c2a8);
          }
        }
        *psVar13 = 1;
      }
      MusicService(0xed,0);
      dac_gain_curve_apply(100);
    }
    else if (*puVar7 == 3) {
      if (*(char *)(iVar19 + 0x34a) != '\0') {
        if (*_DAT_0302c2a4 == 1) {
          FUN_0300afd8(0x86);
          iVar16 = FUN_0300c6d0(0x1ca);
          if (iVar16 != 0) {
            FUN_0300b00a(_DAT_0302c2ac,(int)*_DAT_0302c2a8);
          }
          dac_gain_curve_apply(100);
        }
        *psVar13 = 2;
      }
      MusicService(0xee,0);
      shared_frame_epilogue_c6b4(0x2b);
    }
    shared_frame_epilogue_c6b4(0x42);
  }
  iVar16 = FUN_0300c6d0(0x1b5);
  if (iVar16 != 0) {
    *(undefined2 *)(unaff_r7 + 4) = 0;
    *(undefined4 *)(unaff_r7 + 8) = 1;
    *puVar10 = 1;
    MusicService(0x110,1);
  }
  iVar16 = FUN_0300c6d0(0x1b6);
  puVar7 = _DAT_0302c2b0;
  if (iVar16 != 0) {
    uVar17 = *(uint *)(*(int *)(unaff_r7 + 0xc) + 4);
    if (((uVar17 < 3000) && (*(int *)(_DAT_0302c2b0 + 0x22) == 0)) ||
       ((uVar17 - *(int *)(_DAT_0302c2b0 + 0x24) < 3000 && (*(int *)(_DAT_0302c2b0 + 0x22) == 1))))
    {
      *(undefined2 *)(unaff_r7 + 4) = 0;
      *(undefined4 *)(unaff_r7 + 8) = 1;
      *puVar10 = 0xffffffff;
      MusicService(0x110);
    }
    else {
      sVar6 = *_DAT_0302c2b4;
      if ((sVar6 != 3) && (sVar6 == 0)) {
        shared_frame_epilogue_c6b4(0x40);
      }
      MusicService(0xed,0);
      shared_frame_epilogue_c6b4(0x19d);
      dac_gain_curve_apply(100);
      MusicService(0xfa,8000);
      iVar16 = *(int *)(puVar7 + 0x22);
      bVar23 = iVar16 == 1;
      iVar20 = extraout_r1;
      if (bVar23) {
        iVar16 = *(int *)(puVar7 + 0x24);
        iVar20 = *(int *)(unaff_r7 + 0xc);
      }
      if (bVar23) {
        *(int *)(iVar20 + 4) = iVar16;
      }
      else {
        iVar16 = *(int *)(unaff_r7 + 0xc);
      }
      if (!bVar23) {
        *(undefined4 *)(iVar16 + 4) = 0;
      }
      *(undefined4 *)(unaff_r7 + 0x2c) = 0;
      FUN_0302c950(*(undefined4 *)(*(int *)(unaff_r7 + 0xc) + 4),0);
      if (sVar6 == 3) {
        *(undefined4 *)(unaff_r7 + 0x38) = 0xffffffff;
      }
      else {
        MusicService(0xee,0);
      }
      *_DAT_0302c2b4 = sVar6;
      shared_frame_epilogue_c6b4(0x4c);
    }
  }
  iVar16 = FUN_0300c6d0(0x1d7);
  if (iVar16 != 0) {
    FUN_03007f4c();
    if (*(char *)(iVar19 + 0x12) != '\0') {
      *(char *)(iVar19 + 0x12) = *(char *)(iVar19 + 0x12) + -1;
    }
    cVar3 = '\0';
    if (*pcVar8 != '\0') {
      cVar3 = *(char *)(iVar19 + 0x34a);
    }
    if (*pcVar8 != '\0' && cVar3 != '\0') {
      *(undefined1 *)(iVar19 + 0x15) = *(undefined1 *)(iVar19 + 0x12);
    }
    else {
      *(undefined1 *)(iVar19 + 0x13) = *(undefined1 *)(iVar19 + 0x12);
    }
    MusicService(0xff,0);
    shared_frame_epilogue_c6b4(0x33);
  }
  iVar16 = FUN_0300c6d0(0x1d6);
  if (iVar16 != 0) {
    FUN_03007f4c();
    if (*(byte *)(iVar19 + 0x12) < *(byte *)(iVar19 + 0x1e)) {
      *(byte *)(iVar19 + 0x12) = *(byte *)(iVar19 + 0x12) + 1;
    }
    cVar3 = '\0';
    if (*pcVar8 != '\0') {
      cVar3 = *(char *)(iVar19 + 0x34a);
    }
    if (*pcVar8 != '\0' && cVar3 != '\0') {
      *(undefined1 *)(iVar19 + 0x15) = *(undefined1 *)(iVar19 + 0x12);
    }
    else {
      *(undefined1 *)(iVar19 + 0x13) = *(undefined1 *)(iVar19 + 0x12);
    }
    MusicService(0xff,0);
    shared_frame_epilogue_c6b4(0x33);
  }
  if ((*_DAT_0302c6c4 != '\x03') && (iVar16 = FUN_0300c6d0(0x55), iVar16 != 0)) {
    uVar14 = *(short *)(unaff_r7 + 4) + 1;
    *(ushort *)(unaff_r7 + 4) = uVar14;
    psVar13 = _DAT_0302c6c8;
    if ((uVar14 < *puVar7) &&
       ((iVar16 = *(int *)(*(int *)(unaff_r7 + 0xc) + 0x1c), iVar16 != 8 && iVar16 != 1 &&
        (iVar16 != 5)))) {
      uVar18 = 0;
    }
    else {
      if (*(char *)(iVar19 + 0x34a) != '\0') {
        if (*_DAT_0302c6c8 == 0 || *_DAT_0302c6c8 == 2) {
          FUN_0300afd8(0x87);
          iVar16 = FUN_0300c6d0(0x1ca);
          if (iVar16 != 0) {
            FUN_0300b00a(_DAT_0302c6d0,(int)*_DAT_0302c6cc);
          }
        }
        *psVar13 = 1;
      }
      uVar18 = 1;
    }
    FUN_0302b278(uVar18);
  }
  uVar21 = (*(uint **)(unaff_r7 + 0xc))[1];
  uVar17 = **(uint **)(unaff_r7 + 0xc);
  bVar23 = uVar21 == uVar17;
  if (uVar17 <= uVar21) {
    bVar23 = *(int *)(puVar7 + 0x22) == 0;
  }
  if (bVar23) {
    *puVar10 = 1;
    MusicService(0x110,1);
    shared_frame_epilogue_c6b4(0x39);
  }
  iVar20 = FUN_0300c6d0(0xf3);
  iVar16 = _DAT_0302c6d4;
  if (iVar20 != 0) {
    *(undefined2 *)(unaff_r7 + 4) = 0;
    if ((*(int *)(iVar16 + 0x2c) == 1) &&
       (iVar19 = _DAT_0302c6dc + *_DAT_0302c6d8 * 0x27e,
       *(uint *)(iVar19 + 0x20) <= *(uint *)(iVar19 + 0x10) >> 1)) {
      shared_frame_epilogue_c6b4(0xf2);
      return in_stack_00000008;
    }
    FUN_0302b278(0);
    return in_stack_00000008;
  }
  if ((*(int *)(unaff_r7 + 0xc) != 0) && (*_DAT_0302c6e0 == 0)) {
    FUN_0302c96e(*(int *)(unaff_r7 + 0xc) + 4);
  }
  iVar16 = FUN_0300c6d0(0x113);
  pcVar8 = _DAT_0302c6e4;
  if (iVar16 != 0) {
    if (puVar7[0x79] == 99) {
      bVar5 = *(byte *)(iVar19 + 0x6d);
      if ((bVar5 == 2 || bVar5 == 3) || (bVar5 < 2)) {
        puVar7[5] = 2;
        iVar16 = *(int *)(unaff_r7 + 0xc);
        *(undefined4 *)(iVar16 + 0x24) = 2;
        uVar17 = *(uint *)(iVar16 + 0x1c);
        if ((uVar17 == 2 || uVar17 == 3) || (uVar17 < 2)) goto LAB_0302c498;
        uVar14 = FUN_02ffe3f4(puVar7[1],puVar7 + 0x1a,_DAT_0302c6e8,3);
        if (*pcVar8 != '\x03') {
          uVar15 = FUN_02fff142(*(undefined4 *)(puVar7 + 0x1a),_DAT_0302c6e8,3);
          goto LAB_0302c492;
        }
        uVar15 = FUN_02fff2ca(puVar7 + 0x28,_DAT_0302c6e8,3);
        *puVar7 = uVar15;
      }
      else {
        puVar7[5] = 3;
        iVar16 = *(int *)(unaff_r7 + 0xc);
        *(undefined4 *)(iVar16 + 0x24) = 3;
        uVar17 = *(uint *)(iVar16 + 0x1c);
        if ((uVar17 == 2 || uVar17 == 3) || (uVar17 < 2)) {
          uVar14 = FUN_02fff910(puVar7[1],*(undefined4 *)(puVar7 + 0x1a),_DAT_0302c6e8,3);
          uVar15 = FUN_02ffe3a0(_DAT_0302c6e8,3);
LAB_0302c492:
          *puVar7 = uVar15;
        }
        else {
LAB_0302c498:
          uVar14 = puVar7[1];
        }
      }
      *(uint *)(*(int *)(unaff_r7 + 0xc) + 0x1c) = (uint)*(byte *)(iVar19 + 0x6d);
      puVar7[1] = uVar14;
      puVar7[3] = uVar14;
    }
    else {
      if (puVar7[0x79] == 10) {
        bVar5 = *(byte *)(iVar19 + 0x6d);
        if ((bVar5 == 2 || bVar5 == 3) || (bVar5 < 2)) {
          puVar7[5] = 2;
          iVar16 = *(int *)(unaff_r7 + 0xc);
          *(undefined4 *)(iVar16 + 0x24) = 2;
          uVar17 = *(uint *)(iVar16 + 0x1c);
          if ((uVar17 == 2 || uVar17 == 3) || (uVar17 < 2)) goto LAB_0302c55a;
          uVar14 = FUN_02ffe3f4(puVar7[1],puVar7 + 0x1a,_DAT_0302c6e8,1);
          if (*pcVar8 != '\x03') {
            uVar15 = FUN_02fff142(*(undefined4 *)(puVar7 + 0x1a),_DAT_0302c6e8,1);
            goto LAB_0302c554;
          }
          uVar15 = FUN_02fff2ca(puVar7 + 0x28,_DAT_0302c6e8,3);
          *puVar7 = uVar15;
        }
        else {
          puVar7[5] = 3;
          iVar16 = *(int *)(unaff_r7 + 0xc);
          *(undefined4 *)(iVar16 + 0x24) = 3;
          uVar17 = *(uint *)(iVar16 + 0x1c);
          if ((uVar17 == 2 || uVar17 == 3) || (uVar17 < 2)) {
            uVar14 = FUN_02fff910(puVar7[1],*(undefined4 *)(puVar7 + 0x1a),_DAT_0302c6e8,1);
            uVar15 = FUN_02ffe3a0(_DAT_0302c6e8,1);
LAB_0302c554:
            *puVar7 = uVar15;
          }
          else {
LAB_0302c55a:
            uVar14 = puVar7[1];
          }
        }
        puVar7[1] = uVar14;
        puVar7[3] = uVar14;
      }
      *(uint *)(*(int *)(unaff_r7 + 0xc) + 0x1c) = (uint)*(byte *)(iVar19 + 0x6d);
    }
    if (*puVar7 == 0) {
      return 0xffffffff;
    }
  }
  iVar16 = FUN_0300c6d0(0x114);
  if (iVar16 == 0) goto LAB_0302c618;
  iVar16 = *(int *)(unaff_r7 + 0xc);
  bVar5 = *(byte *)(iVar19 + 0x6f);
  *(uint *)(iVar16 + 0x20) = (uint)bVar5;
  puVar7[6] = (ushort)bVar5;
  *(undefined4 *)(_DAT_0302c6ec + 0x20) = *(undefined4 *)(iVar16 + 0x20);
  pcVar8 = _DAT_0302c6f0;
  if (bVar5 != 1) goto LAB_0302c618;
  *(undefined4 *)(unaff_r7 + 0x14) = 0;
  *pcVar8 = *pcVar8 + '\x01';
  puVar9 = _DAT_0302c6f4;
  uVar17 = (uint)*puVar7;
  if (uVar17 == 1) {
LAB_0302c64e:
    *(undefined4 *)(unaff_r7 + 0x50) = 0;
  }
  else if (uVar17 == 2) {
    if (puVar7[1] != 1) goto LAB_0302c64e;
    *(undefined4 *)(unaff_r7 + 0x50) = 1;
  }
  else {
    *(uint *)(unaff_r7 + 0x50) = *_DAT_0302c6f4 - uVar17 * (*_DAT_0302c6f4 / uVar17);
    while ((*(int *)(iVar19 + 0x70) == *(int *)(unaff_r7 + 0x50) ||
           (puVar7[1] - 1 == *(int *)(unaff_r7 + 0x50)))) {
      *(uint *)(unaff_r7 + 0x50) = *puVar9 - (uint)*puVar7 * (*puVar9 / (uint)*puVar7);
      dac_gain_curve_apply(10);
    }
  }
  FUN_030299d2(*puVar7,*(undefined4 *)(unaff_r7 + 0x50));
  *(undefined4 *)(iVar19 + 0x70) = *(undefined4 *)(unaff_r7 + 0x50);
  puVar10 = _DAT_0302c6f8;
  *(undefined4 *)(unaff_r7 + 0x54) = 1;
  *puVar10 = 0;
  *_DAT_0302c6fc = 0;
LAB_0302c618:
  if (*(int *)(*(int *)(unaff_r7 + 0xc) + 8) != 0x2ee00) {
    iVar20 = *_DAT_0302c700;
    bVar23 = SBORROW4(iVar20,8);
    iVar16 = iVar20 + -8;
    if (iVar20 < 8) {
      iVar16 = *(int *)(*(int *)(unaff_r7 + 0xc) + 0x9c);
      bVar23 = SBORROW4(iVar16,0x18);
      iVar16 = iVar16 + -0x18;
    }
    if ((iVar16 < 0 != bVar23) &&
       ((iVar16 = FUN_0300c6d0(0x102), iVar16 != 0 || (iVar16 = FUN_0300c6d0(0x103), iVar16 != 0))))
    {
      psVar13 = _DAT_0302c6e0;
      sVar6 = *_DAT_0302c6e0;
      if (sVar6 == 0) {
        *(undefined4 *)(unaff_r7 + 0x24) = 0;
        FUN_03005604(0);
        *psVar13 = 3;
        iVar16 = 20000;
        iVar20 = rom_buffer_ready(5);
        while (iVar20 == 1) {
          dac_gain_curve_apply(1);
          iVar16 = iVar16 + -1;
          if (iVar16 == 0) break;
          iVar20 = rom_buffer_ready(5);
        }
      }
      iVar20 = _DAT_0302c704;
      iVar16 = _DAT_0302c6ec;
      iVar22 = *(int *)(unaff_r7 + 0xc);
      *(undefined4 *)(iVar22 + 0x98) = 1;
      uVar2 = *(undefined1 *)(iVar20 + (uint)*(byte *)(iVar19 + 0x74));
      *(undefined1 *)(iVar22 + 0x28) = uVar2;
      iVar22 = _DAT_0302c708;
      cVar3 = *(char *)(iVar20 + (uint)*(byte *)(iVar19 + 0x74));
      *(char *)(_DAT_0302c708 + 0xc) = cVar3;
      *(undefined1 *)(iVar16 + 0x28) = uVar2;
      iVar16 = _DAT_0302c8a8;
      if (cVar3 == '\a') {
        uVar17 = 0;
        do {
          iVar20 = uVar17 * 2;
          iVar1 = uVar17 * 2;
          uVar17 = uVar17 + 1 & 0xffff;
          *(undefined2 *)(iVar22 + iVar1 + 0xf) =
               *(undefined2 *)(iVar16 + *(short *)(iVar19 + iVar20 + 0x77) * 2);
        } while (uVar17 < 5);
      }
      MusicService(0x101,0);
      puVar10 = _DAT_0302c8b0;
      piVar12 = _DAT_0302c8ac;
      if (sVar6 == 0) {
        *(undefined4 *)(unaff_r7 + 0x1c) = 0;
        FUN_0302ca40(puVar10,piVar12);
        puVar10 = _DAT_0302c8b0;
        FUN_03009fe8(*_DAT_0302c8b0,_DAT_0302c8ac,*(undefined4 *)(*(int *)(unaff_r7 + 0xc) + 0x9c));
        piVar12 = _DAT_0302c8ac;
        rom_memzero(*puVar10,*_DAT_0302c8ac << 2);
        uVar18 = _DAT_0302c8c0;
        *_DAT_0302c8b4 = 1;
        FUN_03004608(5,*puVar10,uVar18,*piVar12);
        rom_dac_mute(1,4);
        puVar10 = _DAT_0302c8c4;
        *psVar13 = 0;
        *puVar10 = 1;
        FUN_0300bb32();
        shared_frame_epilogue_c6b4(0x2b);
      }
    }
  }
  FUN_0300c6d0(0x58);
  *(undefined4 *)(unaff_r7 + 0x20) = *_DAT_0302c8c8;
  return in_stack_00000008;
}


