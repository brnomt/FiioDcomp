/**
 * FUN_0302b892 @ 0x0302b892
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302b892(short *param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  FUN_0300c558(0x23);
  *DAT_0302b9cc = 0;
  if (*DAT_0302b9d0 == '\0') {
    *DAT_0302b9d0 = '\x01';
    rom_i2s_dma_start(2,0xe,0);
    rom_audio_path_route(2,0xe,1);
    rom_audio_path_disable(2,0xe,1);
    rom_i2s_dma_start(2,0);
    rom_audio_path_route(2,0,1);
    rom_audio_path_disable(2,0,1);
    rom_i2s_dma_start(1,4,0);
    rom_audio_path_route(1,4);
    rom_audio_path_disable(1,4,0);
    rom_i2s_dma_start(2,2,0);
    rom_audio_path_route(2,2,1);
    rom_audio_path_disable(2,2,1);
    dac_gain_curve_apply(2);
    rom_i2s_dma_start(2,1,0);
    rom_audio_path_route(2,1);
    rom_audio_path_disable(2,1,0);
    dac_gain_curve_apply(1);
    rom_i2s_dma_start(2,1,0);
    rom_audio_path_route(2,1);
    rom_audio_path_disable(2,1);
    dac_gain_curve_apply(8);
    rom_i2s_dma_start(2,1,0);
    rom_audio_path_route(2,1);
    rom_audio_path_disable(2,1,0);
    FUN_030059bc();
    rom_audio_clock_off();
    rom_playback_start(1,2,1,48000,0,0x17,0);
    rom_dac_mute(1,4);
    dac_gain_curve_apply(100);
    rom_dac_unmute(1,4);
    rom_dma_config(4,1);
  }
  MediaLib_thunk_GetFiles(s_MusicInit___0302be10);
  shared_mid_entry_c6f6(0x2a);
  puVar5 = DAT_0302be20;
  iVar4 = DAT_0302be1c;
  *(undefined2 *)(DAT_0302be1c + 4) = 0;
  *puVar5 = 4;
  shared_mid_entry_c6f6(0x114);
  iVar6 = DAT_0302be24;
  if (param_1 == (short *)0x0) {
LAB_0302ba76:
    *(undefined2 *)(iVar6 + 0x66) = 1;
  }
  else {
    sVar3 = *param_1;
    *(short *)(DAT_0302be24 + 0x66) = sVar3;
    if (sVar3 == -1 || sVar3 == 0) goto LAB_0302ba76;
  }
  iVar10 = FUN_0300c714(0x159);
  puVar7 = DAT_0302be28;
  if (iVar10 != 0) {
    DAT_0302be28[0x79] = 99;
  }
  *(uint *)(iVar4 + 0x18) = *(ushort *)(iVar6 + 0x66) - 1;
  if (puVar7[0x79] == 99) {
    iVar10 = USB_DAC_OpenStream(3);
    if (iVar10 != 0) {
LAB_0302bb18:
      FUN_0300c5a4(0x23);
      return;
    }
  }
  else if (puVar7[0x79] == 10) {
    iVar10 = FUN_02ffe3a0(DAT_0302be2c,1);
    *puVar7 = (ushort)iVar10;
    if (iVar10 == 0) {
      shared_frame_epilogue_c6b4(0xf5);
      goto LAB_0302bb18;
    }
  }
  puVar5 = DAT_0302be34;
  iVar10 = DAT_0302be30;
  *(int *)(iVar4 + 0xc) = DAT_0302be30;
  *puVar5 = 0;
  *(uint *)(iVar10 + 0x1c) = (uint)*(byte *)(iVar6 + 0x6d);
  *(uint *)(iVar10 + 0x20) = (uint)*(byte *)(iVar6 + 0x6f);
  iVar8 = DAT_0302be38;
  *(undefined1 *)(iVar10 + 0x28) = *(undefined1 *)(iVar10 + -8 + (uint)*(byte *)(iVar6 + 0x74));
  *(undefined1 *)(iVar8 + 0xc) = *(undefined1 *)(iVar10 + -8 + (uint)*(byte *)(iVar6 + 0x74));
  iVar11 = 0;
  do {
    iVar1 = iVar11 * 2;
    iVar2 = iVar11 * 2;
    iVar11 = iVar11 + 1;
    *(undefined2 *)(iVar10 + iVar2 + 0x2b) =
         *(undefined2 *)(iVar10 + 0xa0 + *(short *)(iVar6 + iVar1 + 0x77) * 2);
  } while (iVar11 < 5);
  rom_memcpy(iVar8 + 0xc,iVar10 + 0x28,0xd);
  uVar12 = *(uint *)(iVar10 + 0x1c);
  if ((uVar12 == 2 || uVar12 == 3) || (uVar12 < 2)) {
    *(undefined4 *)(iVar10 + 0x24) = 2;
  }
  if (puVar7[0x79] == 99 || puVar7[0x79] == 10) {
    FUN_03001694(DAT_0302be28,*(undefined2 *)(iVar6 + 0x66),*(undefined2 *)(iVar10 + 0x24),
                 *(undefined2 *)(iVar10 + 0x20),DAT_0302be2c);
    if (puVar7[0x79] != 99) goto LAB_0302bb7c;
  }
  else {
    puVar7[6] = (ushort)*(byte *)(iVar6 + 0x6f);
    *(undefined4 *)(puVar7 + 8) = DAT_0302be3c;
    puVar9 = DAT_0302be4c;
    *DAT_0302be40 = 1;
    *DAT_0302be44 = 1;
    *DAT_0302be48 = 1;
    *puVar9 = (uint)puVar7[1];
LAB_0302bb7c:
    if (0x2000 < *puVar7) {
      *puVar7 = 0x2000;
      if (0x2000 < puVar7[1]) {
        puVar7[1] = 0x1fff;
      }
    }
  }
  puVar9 = DAT_0302be50;
  if (*(int *)(*(int *)(iVar4 + 0xc) + 0x20) != 1) goto LAB_0302bbfe;
  *(undefined4 *)(iVar4 + 0x14) = 1;
  uVar12 = (uint)*puVar7;
  if (uVar12 == 1) {
LAB_0302bcce:
    *(undefined4 *)(iVar4 + 0x50) = 0;
  }
  else if (uVar12 == 2) {
    if (puVar7[1] != 1) goto LAB_0302bcce;
    *(undefined4 *)(iVar4 + 0x50) = 1;
  }
  else {
    iVar10 = 0;
    *(uint *)(iVar4 + 0x50) = *puVar9 - uVar12 * (*puVar9 / uVar12);
    do {
      if ((*(int *)(iVar6 + 0x70) != *(int *)(iVar4 + 0x50)) &&
         (puVar7[1] - 1 != *(int *)(iVar4 + 0x50))) break;
      *(uint *)(iVar4 + 0x50) = *puVar9 - (uint)*puVar7 * (*puVar9 / (uint)*puVar7);
      dac_gain_curve_apply(0xf);
      iVar10 = iVar10 + 1;
    } while (iVar10 < 200);
  }
  FUN_030299d2(*puVar7,*(undefined4 *)(iVar4 + 0x50));
  *(undefined4 *)(iVar6 + 0x70) = *(undefined4 *)(iVar4 + 0x50);
  *(undefined4 *)(iVar4 + 0x54) = 1;
LAB_0302bbfe:
  FUN_0300c5a4(0x23);
  dac_gain_curve_apply(0xf);
  FUN_0300a926();
  rom_dsp_start();
  rom_dsp_bypass_disable();
  FUN_030120a4();
  FUN_0300b960(0x1a,DAT_0302be54);
  rom_usb_disconnect(0x1a);
  FUN_03012358(0,2);
  FUN_0301231c(0,2);
  rom_usb_connect(0x1a);
  FUN_0300b960(0x1b,0x302add1);
  rom_usb_disconnect(0x1b);
  FUN_03012358(0,4);
  FUN_0301231c(0,4);
  rom_usb_connect(0x1b);
  FUN_0300c558(4);
  FUN_0302b646(0xec,0);
  if (*DAT_0302be58 == '\0') {
    rom_i2s_dma_start(2,0);
    rom_audio_path_route(2,0,1);
    rom_audio_path_disable(2,0);
    rom_i2s_dma_start(2,0xe,0);
    rom_audio_path_route(2,0xe,1);
    rom_audio_path_disable(2,0xe,1);
  }
  else {
    rom_i2s_dma_start(2,0);
    rom_audio_path_route(2,0,1);
    rom_audio_path_disable(2,0,1);
    rom_i2s_dma_start(2,0xe,0);
    rom_audio_path_route(2,0xe,1);
    rom_audio_path_disable(2,0xe,0);
  }
  shared_frame_epilogue_c6b4(0x23);
  *DAT_0302be5c = 0x50;
  *DAT_0302be60 = *puVar9;
  *DAT_0302be64 = 0xff;
  return;
}


