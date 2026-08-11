/**
 * FUN_0302bd2a @ 0x0302bd2a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0302bd2a(void)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  short sVar6;
  int iVar7;
  ushort *puVar8;
  char *pcVar9;
  uint *puVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  int *piVar13;
  short *psVar14;
  ushort uVar15;
  ushort uVar16;
  int iVar17;
  uint uVar18;
  undefined4 uVar19;
  int iVar20;
  int extraout_r1;
  int iVar21;
  uint uVar22;
  int iVar23;
  bool bVar24;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  
  iVar20 = DAT_0302be1c;
  local_28 = 0;
  if (*DAT_0302be68 == '\0') {
    *DAT_0302be6c = *(undefined4 *)(*(int *)(DAT_0302be1c + 0xc) + 8);
  }
  FUN_0302b5a4();
  puVar11 = DAT_0302be74;
  puVar10 = DAT_0302be70;
  puVar8 = DAT_0302be34;
  if (*DAT_0302be34 == 0) {
    uVar18 = func_0x0300bba6();
    if (0x32 < uVar18 - puVar10[2]) {
      puVar10[2] = uVar18;
      if (*puVar10 == 0) {
        FUN_0302c96e(DAT_0302be78);
        *(undefined4 *)(iVar20 + 0x10) = 0;
      }
      uVar18 = *puVar10;
      *puVar10 = uVar18 + 1;
      if (5 < uVar18 + 1) {
        FUN_0302c96e(&uStack_30);
        if (uStack_30 - puVar10[1] < 600) {
          *puVar10 = 0;
          *(undefined4 *)(iVar20 + 8) = 0;
          *(int *)(iVar20 + 0x10) = *(int *)(iVar20 + 0x10) + 8000;
          *puVar11 = 1;
          FUN_0302a74e(1);
          *DAT_0302c288 = *DAT_0302c284;
          shared_frame_epilogue_c6b4(0x110);
        }
        else {
          *puVar10 = 0;
          puVar10[1] = uStack_30;
          *(undefined4 *)(iVar20 + 0x10) = 0;
        }
      }
    }
  }
  else {
    DAT_0302be70[2] = 0;
    *puVar10 = 0;
    puVar10[1] = *(uint *)(*(int *)(iVar20 + 0xc) + 4);
  }
  pcVar9 = DAT_0302be58;
  iVar7 = DAT_0302be24;
  cVar3 = *DAT_0302be58;
  if (cVar3 != *(char *)(iVar20 + 3)) {
    *(char *)(iVar20 + 3) = cVar3;
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
      if (*(char *)(iVar7 + 0x34a) == '\0') {
        *pcVar9 = '\0';
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
  iVar17 = FUN_02ffa74a(2,8);
  if (iVar17 == 0) {
    iVar17 = FUN_030055e8();
    if (iVar17 == 0) {
      FUN_030055e2(1);
      iVar17 = FUN_0300c714(0x2b);
      if (iVar17 == 0) {
        FUN_0302aad4();
      }
    }
    *(undefined1 *)(iVar20 + 2) = 0;
  }
  else if (*(byte *)(iVar20 + 2) < 0x3d) {
    *(byte *)(iVar20 + 2) = *(byte *)(iVar20 + 2) + 1;
  }
  else {
    iVar17 = FUN_030055e8();
    if (iVar17 == 1) {
      FUN_030055e2(0);
      iVar17 = FUN_0300c714(0x2b);
      if (iVar17 == 0) {
        FUN_0302aad4();
      }
    }
    else {
      FUN_030055e2(0);
    }
  }
  pbVar12 = _DAT_0302c28c;
  if (*puVar8 == 0) {
    FUN_0300ad0c();
    cVar3 = *(char *)(iVar7 + 0x34a);
    if (cVar3 != *_DAT_0302c290) {
      *_DAT_0302c290 = cVar3;
      if (cVar3 == '\0') {
        rom_i2s_dma_start(2,0);
        rom_audio_path_route(2,0,1);
        rom_audio_path_disable(2,0);
        rom_i2s_dma_start(2,0xe,0);
        rom_audio_path_route(2,0xe,1);
        rom_audio_path_disable(2,0xe,1);
        *pcVar9 = '\0';
        FUN_03007f4c();
        *pbVar12 = 0;
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
        *pcVar9 = '\x01';
        FUN_03007f4c();
      }
    }
  }
  iVar17 = FUN_0300c714(0x2b);
  piVar13 = _DAT_0302c29c;
  if ((iVar17 != 0) && (*puVar8 == 0)) {
    if (*_DAT_0302c29c == 0) {
      if (*DAT_0302c284 / 3 != *_DAT_0302c2a0) {
        *_DAT_0302c2a0 = *DAT_0302c284 / 3;
        bVar5 = *(byte *)(piVar13 + 4);
        bVar4 = *pbVar12;
        *pbVar12 = bVar5;
        if (bVar5 < bVar4) {
          shared_mid_entry_c6f6(0x2b);
          cVar3 = *(char *)(iVar7 + 0x34a);
        }
        else {
          FUN_03005604();
          *pbVar12 = *(byte *)(_DAT_0302c29c + 4);
          cVar3 = *(char *)(iVar7 + 0x34a);
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
  iVar17 = FUN_0300c6d0(0x2a);
  if (iVar17 != 0) {
    uVar15 = *puVar8;
    bVar24 = uVar15 == 0;
    if (bVar24) {
      uVar15 = (ushort)*(byte *)(iVar7 + 0x34a);
    }
    if (bVar24 && uVar15 == 0) {
      MusicService(0xed,0);
      shared_frame_epilogue_c6b4(0x42);
    }
  }
  iVar17 = FUN_0300c6d0(0x1b7);
  psVar14 = _DAT_0302c2a4;
  if (iVar17 != 0) {
    if (*puVar8 == 0) {
      if (*(char *)(iVar7 + 0x34a) != '\0') {
        if (*_DAT_0302c2a4 == 2) {
          FUN_0300afd8(0x87);
          iVar17 = FUN_0300c6d0(0x1ca);
          if (iVar17 != 0) {
            FUN_0300b00a(_DAT_0302c2ac,(int)*_DAT_0302c2a8);
          }
        }
        *psVar14 = 1;
      }
      MusicService(0xed,0);
      dac_gain_curve_apply(100);
    }
    else if (*puVar8 == 3) {
      if (*(char *)(iVar7 + 0x34a) != '\0') {
        if (*_DAT_0302c2a4 == 1) {
          FUN_0300afd8(0x86);
          iVar17 = FUN_0300c6d0(0x1ca);
          if (iVar17 != 0) {
            FUN_0300b00a(_DAT_0302c2ac,(int)*_DAT_0302c2a8);
          }
          dac_gain_curve_apply(100);
        }
        *psVar14 = 2;
      }
      MusicService(0xee,0);
      shared_frame_epilogue_c6b4(0x2b);
    }
    shared_frame_epilogue_c6b4(0x42);
  }
  iVar17 = FUN_0300c6d0(0x1b5);
  if (iVar17 != 0) {
    *(undefined2 *)(iVar20 + 4) = 0;
    *(undefined4 *)(iVar20 + 8) = 1;
    *puVar11 = 1;
    MusicService(0x110,1);
  }
  iVar17 = FUN_0300c6d0(0x1b6);
  puVar8 = _DAT_0302c2b0;
  if (iVar17 != 0) {
    uVar18 = *(uint *)(*(int *)(iVar20 + 0xc) + 4);
    if (((uVar18 < 3000) && (*(int *)(_DAT_0302c2b0 + 0x22) == 0)) ||
       ((uVar18 - *(int *)(_DAT_0302c2b0 + 0x24) < 3000 && (*(int *)(_DAT_0302c2b0 + 0x22) == 1))))
    {
      *(undefined2 *)(iVar20 + 4) = 0;
      *(undefined4 *)(iVar20 + 8) = 1;
      *puVar11 = 0xffffffff;
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
      iVar17 = *(int *)(puVar8 + 0x22);
      bVar24 = iVar17 == 1;
      iVar21 = extraout_r1;
      if (bVar24) {
        iVar17 = *(int *)(puVar8 + 0x24);
        iVar21 = *(int *)(iVar20 + 0xc);
      }
      if (bVar24) {
        *(int *)(iVar21 + 4) = iVar17;
      }
      else {
        iVar17 = *(int *)(iVar20 + 0xc);
      }
      if (!bVar24) {
        *(undefined4 *)(iVar17 + 4) = 0;
      }
      *(undefined4 *)(iVar20 + 0x2c) = 0;
      FUN_0302c950(*(undefined4 *)(*(int *)(iVar20 + 0xc) + 4),0);
      if (sVar6 == 3) {
        *(undefined4 *)(iVar20 + 0x38) = 0xffffffff;
      }
      else {
        MusicService(0xee,0);
      }
      *_DAT_0302c2b4 = sVar6;
      shared_frame_epilogue_c6b4(0x4c);
    }
  }
  iVar17 = FUN_0300c6d0(0x1d7);
  if (iVar17 != 0) {
    FUN_03007f4c();
    if (*(char *)(iVar7 + 0x12) != '\0') {
      *(char *)(iVar7 + 0x12) = *(char *)(iVar7 + 0x12) + -1;
    }
    cVar3 = '\0';
    if (*pcVar9 != '\0') {
      cVar3 = *(char *)(iVar7 + 0x34a);
    }
    if (*pcVar9 != '\0' && cVar3 != '\0') {
      *(undefined1 *)(iVar7 + 0x15) = *(undefined1 *)(iVar7 + 0x12);
    }
    else {
      *(undefined1 *)(iVar7 + 0x13) = *(undefined1 *)(iVar7 + 0x12);
    }
    MusicService(0xff,0);
    shared_frame_epilogue_c6b4(0x33);
  }
  iVar17 = FUN_0300c6d0(0x1d6);
  if (iVar17 != 0) {
    FUN_03007f4c();
    if (*(byte *)(iVar7 + 0x12) < *(byte *)(iVar7 + 0x1e)) {
      *(byte *)(iVar7 + 0x12) = *(byte *)(iVar7 + 0x12) + 1;
    }
    cVar3 = '\0';
    if (*pcVar9 != '\0') {
      cVar3 = *(char *)(iVar7 + 0x34a);
    }
    if (*pcVar9 != '\0' && cVar3 != '\0') {
      *(undefined1 *)(iVar7 + 0x15) = *(undefined1 *)(iVar7 + 0x12);
    }
    else {
      *(undefined1 *)(iVar7 + 0x13) = *(undefined1 *)(iVar7 + 0x12);
    }
    MusicService(0xff,0);
    shared_frame_epilogue_c6b4(0x33);
  }
  if ((*_DAT_0302c6c4 != '\x03') && (iVar17 = FUN_0300c6d0(0x55), iVar17 != 0)) {
    uVar15 = *(short *)(iVar20 + 4) + 1;
    *(ushort *)(iVar20 + 4) = uVar15;
    psVar14 = _DAT_0302c6c8;
    if ((uVar15 < *puVar8) &&
       ((iVar17 = *(int *)(*(int *)(iVar20 + 0xc) + 0x1c), iVar17 != 8 && iVar17 != 1 &&
        (iVar17 != 5)))) {
      uVar19 = 0;
    }
    else {
      if (*(char *)(iVar7 + 0x34a) != '\0') {
        if (*_DAT_0302c6c8 == 0 || *_DAT_0302c6c8 == 2) {
          FUN_0300afd8(0x87);
          iVar17 = FUN_0300c6d0(0x1ca);
          if (iVar17 != 0) {
            FUN_0300b00a(_DAT_0302c6d0,(int)*_DAT_0302c6cc);
          }
        }
        *psVar14 = 1;
      }
      uVar19 = 1;
    }
    FUN_0302b278(uVar19);
  }
  uVar22 = (*(uint **)(iVar20 + 0xc))[1];
  uVar18 = **(uint **)(iVar20 + 0xc);
  bVar24 = uVar22 == uVar18;
  if (uVar18 <= uVar22) {
    bVar24 = *(int *)(puVar8 + 0x22) == 0;
  }
  if (bVar24) {
    *puVar11 = 1;
    MusicService(0x110,1);
    shared_frame_epilogue_c6b4(0x39);
  }
  iVar21 = FUN_0300c6d0(0xf3);
  iVar17 = _DAT_0302c6d4;
  if (iVar21 != 0) {
    *(undefined2 *)(iVar20 + 4) = 0;
    if ((*(int *)(iVar17 + 0x2c) == 1) &&
       (iVar20 = _DAT_0302c6dc + *_DAT_0302c6d8 * 0x27e,
       *(uint *)(iVar20 + 0x20) <= *(uint *)(iVar20 + 0x10) >> 1)) {
      shared_frame_epilogue_c6b4(0xf2);
      return local_28;
    }
    FUN_0302b278(0);
    return local_28;
  }
  if ((*(int *)(iVar20 + 0xc) != 0) && (*_DAT_0302c6e0 == 0)) {
    FUN_0302c96e(*(int *)(iVar20 + 0xc) + 4);
  }
  iVar17 = FUN_0300c6d0(0x113);
  pcVar9 = _DAT_0302c6e4;
  if (iVar17 != 0) {
    if (puVar8[0x79] == 99) {
      bVar5 = *(byte *)(iVar7 + 0x6d);
      if ((bVar5 == 2 || bVar5 == 3) || (bVar5 < 2)) {
        puVar8[5] = 2;
        iVar17 = *(int *)(iVar20 + 0xc);
        *(undefined4 *)(iVar17 + 0x24) = 2;
        uVar18 = *(uint *)(iVar17 + 0x1c);
        if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) goto LAB_0302c498;
        uVar15 = FUN_02ffe3f4(puVar8[1],puVar8 + 0x1a,_DAT_0302c6e8,3);
        if (*pcVar9 != '\x03') {
          uVar16 = FUN_02fff142(*(undefined4 *)(puVar8 + 0x1a),_DAT_0302c6e8,3);
          goto LAB_0302c492;
        }
        uVar16 = FUN_02fff2ca(puVar8 + 0x28,_DAT_0302c6e8,3);
        *puVar8 = uVar16;
      }
      else {
        puVar8[5] = 3;
        iVar17 = *(int *)(iVar20 + 0xc);
        *(undefined4 *)(iVar17 + 0x24) = 3;
        uVar18 = *(uint *)(iVar17 + 0x1c);
        if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) {
          uVar15 = FUN_02fff910(puVar8[1],*(undefined4 *)(puVar8 + 0x1a),_DAT_0302c6e8,3);
          uVar16 = FUN_02ffe3a0(_DAT_0302c6e8,3);
LAB_0302c492:
          *puVar8 = uVar16;
        }
        else {
LAB_0302c498:
          uVar15 = puVar8[1];
        }
      }
      *(uint *)(*(int *)(iVar20 + 0xc) + 0x1c) = (uint)*(byte *)(iVar7 + 0x6d);
      puVar8[1] = uVar15;
      puVar8[3] = uVar15;
    }
    else {
      if (puVar8[0x79] == 10) {
        bVar5 = *(byte *)(iVar7 + 0x6d);
        if ((bVar5 == 2 || bVar5 == 3) || (bVar5 < 2)) {
          puVar8[5] = 2;
          iVar17 = *(int *)(iVar20 + 0xc);
          *(undefined4 *)(iVar17 + 0x24) = 2;
          uVar18 = *(uint *)(iVar17 + 0x1c);
          if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) goto LAB_0302c55a;
          uVar15 = FUN_02ffe3f4(puVar8[1],puVar8 + 0x1a,_DAT_0302c6e8,1);
          if (*pcVar9 != '\x03') {
            uVar16 = FUN_02fff142(*(undefined4 *)(puVar8 + 0x1a),_DAT_0302c6e8,1);
            goto LAB_0302c554;
          }
          uVar16 = FUN_02fff2ca(puVar8 + 0x28,_DAT_0302c6e8,3);
          *puVar8 = uVar16;
        }
        else {
          puVar8[5] = 3;
          iVar17 = *(int *)(iVar20 + 0xc);
          *(undefined4 *)(iVar17 + 0x24) = 3;
          uVar18 = *(uint *)(iVar17 + 0x1c);
          if ((uVar18 == 2 || uVar18 == 3) || (uVar18 < 2)) {
            uVar15 = FUN_02fff910(puVar8[1],*(undefined4 *)(puVar8 + 0x1a),_DAT_0302c6e8,1);
            uVar16 = FUN_02ffe3a0(_DAT_0302c6e8,1);
LAB_0302c554:
            *puVar8 = uVar16;
          }
          else {
LAB_0302c55a:
            uVar15 = puVar8[1];
          }
        }
        puVar8[1] = uVar15;
        puVar8[3] = uVar15;
      }
      *(uint *)(*(int *)(iVar20 + 0xc) + 0x1c) = (uint)*(byte *)(iVar7 + 0x6d);
    }
    if (*puVar8 == 0) {
      return 0xffffffff;
    }
  }
  iVar17 = FUN_0300c6d0(0x114);
  if (iVar17 == 0) goto LAB_0302c618;
  iVar17 = *(int *)(iVar20 + 0xc);
  bVar5 = *(byte *)(iVar7 + 0x6f);
  *(uint *)(iVar17 + 0x20) = (uint)bVar5;
  puVar8[6] = (ushort)bVar5;
  *(undefined4 *)(_DAT_0302c6ec + 0x20) = *(undefined4 *)(iVar17 + 0x20);
  pcVar9 = _DAT_0302c6f0;
  if (bVar5 != 1) goto LAB_0302c618;
  *(undefined4 *)(iVar20 + 0x14) = 0;
  *pcVar9 = *pcVar9 + '\x01';
  puVar10 = _DAT_0302c6f4;
  uVar18 = (uint)*puVar8;
  if (uVar18 == 1) {
LAB_0302c64e:
    *(undefined4 *)(iVar20 + 0x50) = 0;
  }
  else if (uVar18 == 2) {
    if (puVar8[1] != 1) goto LAB_0302c64e;
    *(undefined4 *)(iVar20 + 0x50) = 1;
  }
  else {
    *(uint *)(iVar20 + 0x50) = *_DAT_0302c6f4 - uVar18 * (*_DAT_0302c6f4 / uVar18);
    while ((*(int *)(iVar7 + 0x70) == *(int *)(iVar20 + 0x50) ||
           (puVar8[1] - 1 == *(int *)(iVar20 + 0x50)))) {
      *(uint *)(iVar20 + 0x50) = *puVar10 - (uint)*puVar8 * (*puVar10 / (uint)*puVar8);
      dac_gain_curve_apply(10);
    }
  }
  FUN_030299d2(*puVar8,*(undefined4 *)(iVar20 + 0x50));
  *(undefined4 *)(iVar7 + 0x70) = *(undefined4 *)(iVar20 + 0x50);
  puVar11 = _DAT_0302c6f8;
  *(undefined4 *)(iVar20 + 0x54) = 1;
  *puVar11 = 0;
  *_DAT_0302c6fc = 0;
LAB_0302c618:
  if (*(int *)(*(int *)(iVar20 + 0xc) + 8) != 0x2ee00) {
    iVar21 = *_DAT_0302c700;
    bVar24 = SBORROW4(iVar21,8);
    iVar17 = iVar21 + -8;
    if (iVar21 < 8) {
      iVar17 = *(int *)(*(int *)(iVar20 + 0xc) + 0x9c);
      bVar24 = SBORROW4(iVar17,0x18);
      iVar17 = iVar17 + -0x18;
    }
    if ((iVar17 < 0 != bVar24) &&
       ((iVar17 = FUN_0300c6d0(0x102), iVar17 != 0 || (iVar17 = FUN_0300c6d0(0x103), iVar17 != 0))))
    {
      psVar14 = _DAT_0302c6e0;
      sVar6 = *_DAT_0302c6e0;
      if (sVar6 == 0) {
        *(undefined4 *)(iVar20 + 0x24) = 0;
        FUN_03005604(0);
        *psVar14 = 3;
        iVar17 = 20000;
        iVar21 = rom_buffer_ready(5);
        while (iVar21 == 1) {
          dac_gain_curve_apply(1);
          iVar17 = iVar17 + -1;
          if (iVar17 == 0) break;
          iVar21 = rom_buffer_ready(5);
        }
      }
      iVar21 = _DAT_0302c704;
      iVar17 = _DAT_0302c6ec;
      iVar23 = *(int *)(iVar20 + 0xc);
      *(undefined4 *)(iVar23 + 0x98) = 1;
      uVar2 = *(undefined1 *)(iVar21 + (uint)*(byte *)(iVar7 + 0x74));
      *(undefined1 *)(iVar23 + 0x28) = uVar2;
      iVar23 = _DAT_0302c708;
      cVar3 = *(char *)(iVar21 + (uint)*(byte *)(iVar7 + 0x74));
      *(char *)(_DAT_0302c708 + 0xc) = cVar3;
      *(undefined1 *)(iVar17 + 0x28) = uVar2;
      iVar17 = _DAT_0302c8a8;
      if (cVar3 == '\a') {
        uVar18 = 0;
        do {
          iVar21 = uVar18 * 2;
          iVar1 = uVar18 * 2;
          uVar18 = uVar18 + 1 & 0xffff;
          *(undefined2 *)(iVar23 + iVar1 + 0xf) =
               *(undefined2 *)(iVar17 + *(short *)(iVar7 + iVar21 + 0x77) * 2);
        } while (uVar18 < 5);
      }
      MusicService(0x101,0);
      puVar11 = _DAT_0302c8b0;
      piVar13 = _DAT_0302c8ac;
      if (sVar6 == 0) {
        *(undefined4 *)(iVar20 + 0x1c) = 0;
        FUN_0302ca40(puVar11,piVar13);
        puVar11 = _DAT_0302c8b0;
        FUN_03009fe8(*_DAT_0302c8b0,_DAT_0302c8ac,*(undefined4 *)(*(int *)(iVar20 + 0xc) + 0x9c));
        piVar13 = _DAT_0302c8ac;
        rom_memzero(*puVar11,*_DAT_0302c8ac << 2);
        uVar19 = _DAT_0302c8c0;
        uStack_2c = _DAT_0302c8b8;
        *_DAT_0302c8b4 = 1;
        FUN_03004608(5,*puVar11,uVar19,*piVar13);
        rom_dac_mute(1,4);
        puVar11 = _DAT_0302c8c4;
        *psVar14 = 0;
        *puVar11 = 1;
        FUN_0300bb32();
        shared_frame_epilogue_c6b4(0x2b);
      }
    }
  }
  FUN_0300c6d0(0x58);
  *(undefined4 *)(iVar20 + 0x20) = *_DAT_0302c8c8;
  return local_28;
}


