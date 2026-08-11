/**
 * FUN_0302bdda @ 0x0302bdda
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0302bdda(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  short sVar6;
  short sVar7;
  byte *pbVar8;
  byte *pbVar9;
  int *piVar10;
  short *psVar11;
  ushort *puVar12;
  char *pcVar13;
  uint *puVar14;
  undefined4 *puVar15;
  ushort uVar16;
  ushort uVar17;
  uint uVar18;
  int iVar19;
  undefined4 uVar20;
  int iVar21;
  int extraout_r1;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint *unaff_r4;
  uint unaff_r5;
  undefined4 unaff_r6;
  int unaff_r7;
  ushort *unaff_r8;
  undefined4 *unaff_r11;
  bool bVar25;
  uint in_stack_00000000;
  undefined4 in_stack_00000008;
  
  if (param_1 == 0) {
    FUN_0302c96e(DAT_0302be78);
    *(uint *)(unaff_r7 + 0x10) = unaff_r5;
  }
  uVar18 = *unaff_r4;
  *unaff_r4 = uVar18 + 1;
  if (5 < uVar18 + 1) {
    FUN_0302c96e();
    if (in_stack_00000000 - unaff_r4[1] < 600) {
      *unaff_r4 = unaff_r5;
      *(uint *)(unaff_r7 + 8) = unaff_r5;
      *(int *)(unaff_r7 + 0x10) = *(int *)(unaff_r7 + 0x10) + 8000;
      *unaff_r11 = unaff_r6;
      FUN_0302a74e();
      *DAT_0302c288 = *DAT_0302c284;
      shared_frame_epilogue_c6b4(0x110);
    }
    else {
      *unaff_r4 = unaff_r5;
      unaff_r4[1] = in_stack_00000000;
      *(uint *)(unaff_r7 + 0x10) = unaff_r5;
    }
  }
  pbVar8 = DAT_0302be58;
  iVar21 = DAT_0302be24;
  bVar3 = *DAT_0302be58;
  bVar5 = (byte)unaff_r5;
  if (bVar3 != *(byte *)(unaff_r7 + 3)) {
    *(byte *)(unaff_r7 + 3) = bVar3;
    if (bVar3 == 0) {
LAB_0302be7c:
      rom_i2s_dma_start(2,0);
      rom_audio_path_route(2,0,1);
      rom_audio_path_disable(2,0);
      rom_i2s_dma_start(2,0xe,0);
      rom_audio_path_route(2,0xe,1);
      rom_audio_path_disable(2,0xe,1);
    }
    else {
      if (*(char *)(iVar21 + 0x34a) == '\0') {
        *pbVar8 = bVar5;
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
  iVar19 = FUN_02ffa74a(2,8);
  if (iVar19 == 0) {
    iVar19 = FUN_030055e8();
    if (iVar19 == 0) {
      FUN_030055e2(1);
      iVar19 = FUN_0300c714(0x2b);
      if (iVar19 == 0) {
        FUN_0302aad4();
      }
    }
    *(byte *)(unaff_r7 + 2) = bVar5;
  }
  else if (*(byte *)(unaff_r7 + 2) < 0x3d) {
    *(byte *)(unaff_r7 + 2) = *(byte *)(unaff_r7 + 2) + 1;
  }
  else {
    iVar19 = FUN_030055e8();
    if (iVar19 == 1) {
      FUN_030055e2(0);
      iVar19 = FUN_0300c714(0x2b);
      if (iVar19 == 0) {
        FUN_0302aad4();
      }
    }
    else {
      FUN_030055e2(0);
    }
  }
  pbVar9 = _DAT_0302c28c;
  if (*unaff_r8 == 0) {
    FUN_0300ad0c();
    cVar4 = *(char *)(iVar21 + 0x34a);
    if (cVar4 != *_DAT_0302c290) {
      *_DAT_0302c290 = cVar4;
      if (cVar4 == '\0') {
        rom_i2s_dma_start(2,0);
        rom_audio_path_route(2,0,1);
        rom_audio_path_disable(2,0);
        rom_i2s_dma_start(2,0xe,0);
        rom_audio_path_route(2,0xe,1);
        rom_audio_path_disable(2,0xe,1);
        *pbVar8 = bVar5;
        FUN_03007f4c();
        *pbVar9 = bVar5;
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
        *pbVar8 = (byte)unaff_r6;
        FUN_03007f4c();
      }
    }
  }
  iVar19 = FUN_0300c714(0x2b);
  piVar10 = _DAT_0302c29c;
  if ((iVar19 != 0) && (*unaff_r8 == 0)) {
    if (*_DAT_0302c29c == 0) {
      if (*DAT_0302c284 / 3 != *_DAT_0302c2a0) {
        *_DAT_0302c2a0 = *DAT_0302c284 / 3;
        bVar3 = *(byte *)(piVar10 + 4);
        bVar5 = *pbVar9;
        *pbVar9 = bVar3;
        if (bVar3 < bVar5) {
          shared_mid_entry_c6f6(0x2b);
          cVar4 = *(char *)(iVar21 + 0x34a);
        }
        else {
          FUN_03005604();
          *pbVar9 = *(byte *)(_DAT_0302c29c + 4);
          cVar4 = *(char *)(iVar21 + 0x34a);
        }
        if (cVar4 != '\0') {
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
  iVar19 = FUN_0300c6d0(0x2a);
  if (iVar19 != 0) {
    uVar16 = *unaff_r8;
    bVar25 = uVar16 == 0;
    if (bVar25) {
      uVar16 = (ushort)*(byte *)(iVar21 + 0x34a);
    }
    if (bVar25 && uVar16 == 0) {
      MusicService(0xed,0);
      shared_frame_epilogue_c6b4(0x42);
    }
  }
  iVar19 = FUN_0300c6d0(0x1b7);
  psVar11 = _DAT_0302c2a4;
  if (iVar19 != 0) {
    if (*unaff_r8 == 0) {
      if (*(char *)(iVar21 + 0x34a) != '\0') {
        if (*_DAT_0302c2a4 == 2) {
          FUN_0300afd8(0x87);
          iVar19 = FUN_0300c6d0(0x1ca);
          if (iVar19 != 0) {
            FUN_0300b00a(_DAT_0302c2ac,(int)*_DAT_0302c2a8);
          }
        }
        *psVar11 = (short)unaff_r6;
      }
      MusicService(0xed,0);
      dac_gain_curve_apply(100);
    }
    else if (*unaff_r8 == 3) {
      if (*(char *)(iVar21 + 0x34a) != '\0') {
        if (*_DAT_0302c2a4 == 1) {
          FUN_0300afd8(0x86);
          iVar19 = FUN_0300c6d0(0x1ca);
          if (iVar19 != 0) {
            FUN_0300b00a(_DAT_0302c2ac,(int)*_DAT_0302c2a8);
          }
          dac_gain_curve_apply(100);
        }
        *psVar11 = 2;
      }
      MusicService(0xee,0);
      shared_frame_epilogue_c6b4(0x2b);
    }
    shared_frame_epilogue_c6b4(0x42);
  }
  iVar19 = FUN_0300c6d0(0x1b5);
  sVar7 = (short)unaff_r5;
  if (iVar19 != 0) {
    *(short *)(unaff_r7 + 4) = sVar7;
    *(undefined4 *)(unaff_r7 + 8) = unaff_r6;
    *unaff_r11 = unaff_r6;
    MusicService(0x110);
  }
  iVar19 = FUN_0300c6d0(0x1b6);
  puVar12 = _DAT_0302c2b0;
  if (iVar19 != 0) {
    uVar18 = *(uint *)(*(int *)(unaff_r7 + 0xc) + 4);
    if (((uVar18 < 3000) && (*(int *)(_DAT_0302c2b0 + 0x22) == 0)) ||
       ((uVar18 - *(int *)(_DAT_0302c2b0 + 0x24) < 3000 && (*(int *)(_DAT_0302c2b0 + 0x22) == 1))))
    {
      *(short *)(unaff_r7 + 4) = sVar7;
      *(undefined4 *)(unaff_r7 + 8) = unaff_r6;
      *unaff_r11 = 0xffffffff;
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
      iVar19 = *(int *)(puVar12 + 0x22);
      bVar25 = iVar19 == 1;
      iVar22 = extraout_r1;
      if (bVar25) {
        iVar19 = *(int *)(puVar12 + 0x24);
        iVar22 = *(int *)(unaff_r7 + 0xc);
      }
      if (bVar25) {
        *(int *)(iVar22 + 4) = iVar19;
      }
      else {
        iVar19 = *(int *)(unaff_r7 + 0xc);
      }
      if (!bVar25) {
        *(uint *)(iVar19 + 4) = unaff_r5;
      }
      *(uint *)(unaff_r7 + 0x2c) = unaff_r5;
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
  iVar19 = FUN_0300c6d0(0x1d7);
  if (iVar19 != 0) {
    FUN_03007f4c();
    if (*(char *)(iVar21 + 0x12) != '\0') {
      *(char *)(iVar21 + 0x12) = *(char *)(iVar21 + 0x12) + -1;
    }
    cVar4 = '\0';
    if (*pbVar8 != 0) {
      cVar4 = *(char *)(iVar21 + 0x34a);
    }
    if (*pbVar8 != 0 && cVar4 != '\0') {
      *(undefined1 *)(iVar21 + 0x15) = *(undefined1 *)(iVar21 + 0x12);
    }
    else {
      *(undefined1 *)(iVar21 + 0x13) = *(undefined1 *)(iVar21 + 0x12);
    }
    MusicService(0xff,0);
    shared_frame_epilogue_c6b4(0x33);
  }
  iVar19 = FUN_0300c6d0(0x1d6);
  if (iVar19 != 0) {
    FUN_03007f4c();
    if (*(byte *)(iVar21 + 0x12) < *(byte *)(iVar21 + 0x1e)) {
      *(byte *)(iVar21 + 0x12) = *(byte *)(iVar21 + 0x12) + 1;
    }
    cVar4 = '\0';
    if (*pbVar8 != 0) {
      cVar4 = *(char *)(iVar21 + 0x34a);
    }
    if (*pbVar8 != 0 && cVar4 != '\0') {
      *(undefined1 *)(iVar21 + 0x15) = *(undefined1 *)(iVar21 + 0x12);
    }
    else {
      *(undefined1 *)(iVar21 + 0x13) = *(undefined1 *)(iVar21 + 0x12);
    }
    MusicService(0xff,0);
    shared_frame_epilogue_c6b4(0x33);
  }
  if ((*_DAT_0302c6c4 != '\x03') && (iVar19 = FUN_0300c6d0(0x55), iVar19 != 0)) {
    uVar16 = *(short *)(unaff_r7 + 4) + 1;
    *(ushort *)(unaff_r7 + 4) = uVar16;
    psVar11 = _DAT_0302c6c8;
    if ((uVar16 < *puVar12) &&
       ((iVar19 = *(int *)(*(int *)(unaff_r7 + 0xc) + 0x1c), iVar19 != 8 && iVar19 != 1 &&
        (iVar19 != 5)))) {
      uVar20 = 0;
    }
    else {
      if (*(char *)(iVar21 + 0x34a) != '\0') {
        if (*_DAT_0302c6c8 == 0 || *_DAT_0302c6c8 == 2) {
          FUN_0300afd8(0x87);
          iVar19 = FUN_0300c6d0(0x1ca);
          if (iVar19 != 0) {
            FUN_0300b00a(_DAT_0302c6d0,(int)*_DAT_0302c6cc);
          }
        }
        *psVar11 = (short)unaff_r6;
      }
      uVar20 = 1;
    }
    FUN_0302b278(uVar20);
  }
  uVar23 = (*(uint **)(unaff_r7 + 0xc))[1];
  uVar18 = **(uint **)(unaff_r7 + 0xc);
  bVar25 = uVar23 == uVar18;
  if (uVar18 <= uVar23) {
    bVar25 = *(int *)(puVar12 + 0x22) == 0;
  }
  if (bVar25) {
    *unaff_r11 = unaff_r6;
    MusicService(0x110);
    shared_frame_epilogue_c6b4(0x39);
  }
  iVar22 = FUN_0300c6d0(0xf3);
  iVar19 = _DAT_0302c6d4;
  if (iVar22 != 0) {
    *(short *)(unaff_r7 + 4) = sVar7;
    if ((*(int *)(iVar19 + 0x2c) == 1) &&
       (iVar21 = _DAT_0302c6dc + *_DAT_0302c6d8 * 0x27e,
       *(uint *)(iVar21 + 0x20) <= *(uint *)(iVar21 + 0x10) >> 1)) {
      shared_frame_epilogue_c6b4(0xf2);
      return in_stack_00000008;
    }
    FUN_0302b278(0);
    return in_stack_00000008;
  }
  if ((*(int *)(unaff_r7 + 0xc) != 0) && (*_DAT_0302c6e0 == 0)) {
    FUN_0302c96e(*(int *)(unaff_r7 + 0xc) + 4);
  }
  iVar19 = FUN_0300c6d0(0x113);
  pcVar13 = _DAT_0302c6e4;
  if (iVar19 != 0) {
    if (puVar12[0x79] == 99) {
      bVar3 = *(byte *)(iVar21 + 0x6d);
      if ((bVar3 == 2 || bVar3 == 3) || (bVar3 < 2)) {
        puVar12[5] = 2;
        iVar19 = *(int *)(unaff_r7 + 0xc);
        *(undefined4 *)(iVar19 + 0x24) = 2;
        uVar18 = *(uint *)(iVar19 + 0x1c);
        if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) goto LAB_0302c498;
        uVar16 = FUN_02ffe3f4(puVar12[1],puVar12 + 0x1a,_DAT_0302c6e8,3);
        if (*pcVar13 != '\x03') {
          uVar17 = FUN_02fff142(*(undefined4 *)(puVar12 + 0x1a),_DAT_0302c6e8,3);
          goto LAB_0302c492;
        }
        uVar17 = FUN_02fff2ca(puVar12 + 0x28,_DAT_0302c6e8,3);
        *puVar12 = uVar17;
      }
      else {
        puVar12[5] = 3;
        iVar19 = *(int *)(unaff_r7 + 0xc);
        *(undefined4 *)(iVar19 + 0x24) = 3;
        uVar18 = *(uint *)(iVar19 + 0x1c);
        if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) {
          uVar16 = FUN_02fff910(puVar12[1],*(undefined4 *)(puVar12 + 0x1a),_DAT_0302c6e8,3);
          uVar17 = FUN_02ffe3a0(_DAT_0302c6e8,3);
LAB_0302c492:
          *puVar12 = uVar17;
        }
        else {
LAB_0302c498:
          uVar16 = puVar12[1];
        }
      }
      *(uint *)(*(int *)(unaff_r7 + 0xc) + 0x1c) = (uint)*(byte *)(iVar21 + 0x6d);
      puVar12[1] = uVar16;
      puVar12[3] = uVar16;
    }
    else {
      if (puVar12[0x79] == 10) {
        bVar3 = *(byte *)(iVar21 + 0x6d);
        if ((bVar3 == 2 || bVar3 == 3) || (bVar3 < 2)) {
          puVar12[5] = 2;
          iVar19 = *(int *)(unaff_r7 + 0xc);
          *(undefined4 *)(iVar19 + 0x24) = 2;
          uVar18 = *(uint *)(iVar19 + 0x1c);
          if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) goto LAB_0302c55a;
          uVar16 = FUN_02ffe3f4(puVar12[1],puVar12 + 0x1a,_DAT_0302c6e8,1);
          if (*pcVar13 != '\x03') {
            uVar17 = FUN_02fff142(*(undefined4 *)(puVar12 + 0x1a),_DAT_0302c6e8,1);
            goto LAB_0302c554;
          }
          uVar17 = FUN_02fff2ca(puVar12 + 0x28,_DAT_0302c6e8,3);
          *puVar12 = uVar17;
        }
        else {
          puVar12[5] = 3;
          iVar19 = *(int *)(unaff_r7 + 0xc);
          *(undefined4 *)(iVar19 + 0x24) = 3;
          uVar18 = *(uint *)(iVar19 + 0x1c);
          if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) {
            uVar16 = FUN_02fff910(puVar12[1],*(undefined4 *)(puVar12 + 0x1a),_DAT_0302c6e8,1);
            uVar17 = FUN_02ffe3a0(_DAT_0302c6e8,1);
LAB_0302c554:
            *puVar12 = uVar17;
          }
          else {
LAB_0302c55a:
            uVar16 = puVar12[1];
          }
        }
        puVar12[1] = uVar16;
        puVar12[3] = uVar16;
      }
      *(uint *)(*(int *)(unaff_r7 + 0xc) + 0x1c) = (uint)*(byte *)(iVar21 + 0x6d);
    }
    if (*puVar12 == 0) {
      return 0xffffffff;
    }
  }
  iVar19 = FUN_0300c6d0(0x114);
  if (iVar19 == 0) goto LAB_0302c618;
  iVar19 = *(int *)(unaff_r7 + 0xc);
  bVar3 = *(byte *)(iVar21 + 0x6f);
  *(uint *)(iVar19 + 0x20) = (uint)bVar3;
  puVar12[6] = (ushort)bVar3;
  *(undefined4 *)(_DAT_0302c6ec + 0x20) = *(undefined4 *)(iVar19 + 0x20);
  pcVar13 = _DAT_0302c6f0;
  if (bVar3 != 1) goto LAB_0302c618;
  *(uint *)(unaff_r7 + 0x14) = unaff_r5;
  *pcVar13 = *pcVar13 + '\x01';
  puVar14 = _DAT_0302c6f4;
  uVar18 = (uint)*puVar12;
  if (uVar18 == 1) {
LAB_0302c64e:
    *(uint *)(unaff_r7 + 0x50) = unaff_r5;
  }
  else if (uVar18 == 2) {
    if (puVar12[1] != 1) goto LAB_0302c64e;
    *(undefined4 *)(unaff_r7 + 0x50) = unaff_r6;
  }
  else {
    *(uint *)(unaff_r7 + 0x50) = *_DAT_0302c6f4 - uVar18 * (*_DAT_0302c6f4 / uVar18);
    while ((*(int *)(iVar21 + 0x70) == *(int *)(unaff_r7 + 0x50) ||
           (puVar12[1] - 1 == *(int *)(unaff_r7 + 0x50)))) {
      *(uint *)(unaff_r7 + 0x50) = *puVar14 - (uint)*puVar12 * (*puVar14 / (uint)*puVar12);
      dac_gain_curve_apply(10);
    }
  }
  FUN_030299d2(*puVar12,*(undefined4 *)(unaff_r7 + 0x50));
  *(undefined4 *)(iVar21 + 0x70) = *(undefined4 *)(unaff_r7 + 0x50);
  puVar14 = _DAT_0302c6f8;
  *(undefined4 *)(unaff_r7 + 0x54) = unaff_r6;
  *puVar14 = unaff_r5;
  *_DAT_0302c6fc = unaff_r5;
LAB_0302c618:
  if (*(int *)(*(int *)(unaff_r7 + 0xc) + 8) != 0x2ee00) {
    iVar22 = *_DAT_0302c700;
    bVar25 = SBORROW4(iVar22,8);
    iVar19 = iVar22 + -8;
    if (iVar22 < 8) {
      iVar19 = *(int *)(*(int *)(unaff_r7 + 0xc) + 0x9c);
      bVar25 = SBORROW4(iVar19,0x18);
      iVar19 = iVar19 + -0x18;
    }
    if ((iVar19 < 0 != bVar25) &&
       ((iVar19 = FUN_0300c6d0(0x102), iVar19 != 0 || (iVar19 = FUN_0300c6d0(0x103), iVar19 != 0))))
    {
      psVar11 = _DAT_0302c6e0;
      sVar6 = *_DAT_0302c6e0;
      if (sVar6 == 0) {
        *(uint *)(unaff_r7 + 0x24) = unaff_r5;
        FUN_03005604(0);
        *psVar11 = 3;
        iVar19 = 20000;
        iVar22 = rom_buffer_ready(5);
        while (iVar22 == 1) {
          dac_gain_curve_apply(1);
          iVar19 = iVar19 + -1;
          if (iVar19 == 0) break;
          iVar22 = rom_buffer_ready(5);
        }
      }
      iVar22 = _DAT_0302c704;
      iVar19 = _DAT_0302c6ec;
      iVar24 = *(int *)(unaff_r7 + 0xc);
      *(undefined4 *)(iVar24 + 0x98) = unaff_r6;
      uVar2 = *(undefined1 *)(iVar22 + (uint)*(byte *)(iVar21 + 0x74));
      *(undefined1 *)(iVar24 + 0x28) = uVar2;
      iVar24 = _DAT_0302c708;
      cVar4 = *(char *)(iVar22 + (uint)*(byte *)(iVar21 + 0x74));
      *(char *)(_DAT_0302c708 + 0xc) = cVar4;
      *(undefined1 *)(iVar19 + 0x28) = uVar2;
      iVar19 = _DAT_0302c8a8;
      if (cVar4 == '\a') {
        uVar18 = 0;
        do {
          iVar22 = uVar18 * 2;
          iVar1 = uVar18 * 2;
          uVar18 = uVar18 + 1 & 0xffff;
          *(undefined2 *)(iVar24 + iVar1 + 0xf) =
               *(undefined2 *)(iVar19 + *(short *)(iVar21 + iVar22 + 0x77) * 2);
        } while (uVar18 < 5);
      }
      MusicService(0x101,0);
      puVar15 = _DAT_0302c8b0;
      piVar10 = _DAT_0302c8ac;
      if (sVar6 == 0) {
        *(uint *)(unaff_r7 + 0x1c) = unaff_r5;
        FUN_0302ca40(puVar15,piVar10);
        puVar15 = _DAT_0302c8b0;
        FUN_03009fe8(*_DAT_0302c8b0,_DAT_0302c8ac,*(undefined4 *)(*(int *)(unaff_r7 + 0xc) + 0x9c));
        piVar10 = _DAT_0302c8ac;
        rom_memzero(*puVar15,*_DAT_0302c8ac << 2);
        uVar20 = _DAT_0302c8c0;
        *_DAT_0302c8b4 = unaff_r6;
        FUN_03004608(5,*puVar15,uVar20,*piVar10);
        rom_dac_mute(1,4);
        puVar15 = _DAT_0302c8c4;
        *psVar11 = sVar7;
        *puVar15 = unaff_r6;
        FUN_0300bb32();
        shared_frame_epilogue_c6b4(0x2b);
      }
    }
  }
  FUN_0300c6d0(0x58);
  *(undefined4 *)(unaff_r7 + 0x20) = *_DAT_0302c8c8;
  return in_stack_00000008;
}


