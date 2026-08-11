/**
 * FUN_030dfd86 @ 0x030dfd86
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030dfd86(undefined4 param_1,int *param_2)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  int *piVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint unaff_r9;
  
  piVar4 = DAT_030dff20;
  bVar3 = false;
  iVar9 = 0;
  do {
    iVar7 = hifi_flac_helper(param_1,0x10);
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    cVar5 = flac_bitstream_getbits_u(param_1,8);
    iVar7 = iVar9 + 1;
    unaff_r9 = unaff_r9 & 0xffffff00;
    if (cVar5 == -1) {
      bVar6 = flac_bitstream_getbits_u(param_1,8);
      iVar7 = iVar9 + 2;
      unaff_r9 = (uint)bVar6 << 8;
      if (bVar6 >> 2 == 0x3e) {
        param_2[8] = bVar6 & 1;
        if ((bVar6 & 1) != 0) {
          hifi_debug_printf_ovl_0dc5(s_var_blocksize_not_surport_030dff24);
          return 0xffffffff;
        }
        bVar3 = true;
      }
    }
    iVar8 = piVar4[4];
    iVar9 = iVar8;
    if (iVar8 != 0) {
      iVar9 = iVar8 - iVar7;
    }
    if (iVar9 < 0 != (iVar8 != 0 && SBORROW4(iVar8,iVar7))) {
      hifi_debug_printf_ovl_0dc5(s_invalid_sync_code_030dff40);
      return 0xffffffff;
    }
    iVar9 = iVar7;
  } while (!bVar3);
  hifi_flac_helper(param_1,0x40);
  iVar7 = flac_bitstream_getbits_u(param_1,4);
  iVar9 = flac_bitstream_getbits_u(param_1,4);
  iVar8 = flac_bitstream_getbits_u(param_1,4);
  param_2[4] = iVar8;
  if (iVar8 < 2) {
    param_2[4] = 0;
    param_2[1] = iVar8 + 1;
  }
  else {
    if (0xc < iVar8) {
      hifi_debug_printf_ovl_0dc5(s_invalid_channel_mode___d_030dff98);
      return 0xffffffff;
    }
    param_2[1] = 2;
  }
  iVar8 = flac_bitstream_getbits_u(param_1,3);
  if (iVar8 == 3 || iVar8 == 7) {
    pcVar10 = s_invalid_sample_size_code___d__030dff54;
    iVar9 = iVar8;
LAB_030e0128:
    hifi_debug_printf_ovl_0dc5(pcVar10,iVar9);
  }
  else {
    param_2[2] = *(int *)(DAT_030dff74 + iVar8 * 4);
    iVar8 = FUN_030dd7ae(param_1);
    if (iVar8 != 0) {
      hifi_debug_printf_ovl_0dc5(s_broken_stream__invalid_padding_030dff78);
      return 0xffffffff;
    }
    uVar11 = flac_bitstream_getbits_u(param_1,8);
    iVar8 = FUN_030dd956(uVar11 ^ 0xff | 1);
    if (iVar8 - 0x18U == 1) {
LAB_030dfff8:
      uVar11 = 0xffffffff;
      iVar15 = -1;
    }
    else {
      uVar11 = uVar11 & 0x7fU >> (iVar8 - 0x18U & 0xff);
      iVar15 = 0;
      for (iVar8 = iVar8 + -0x19; 0 < iVar8; iVar8 = iVar8 + -1) {
        iVar12 = flac_bitstream_getbits_u(param_1,8);
        uVar13 = iVar12 - 0x80;
        if ((int)uVar13 >> 6 != 0) goto LAB_030dfff8;
        uVar1 = uVar11 >> 0x1a;
        uVar14 = uVar11 * 0x40;
        uVar11 = uVar14 + uVar13;
        iVar15 = (iVar15 << 6 | uVar1) + ((int)uVar13 >> 0x1f) + (uint)CARRY4(uVar14,uVar13);
      }
    }
    param_2[6] = uVar11;
    param_2[7] = iVar15;
    if (iVar15 < 0) {
      pcVar10 = s_sample_frame_number_invalid__utf_030e0338;
    }
    else {
      if (uVar11 == 0 && iVar15 == 0) {
        *DAT_030e0364 = (char)(unaff_r9 >> 8);
        hifi_debug_printf_ovl_0dc5(s_sync_code_0xFF_0x_x_030e0368);
      }
      if (iVar7 != 0) {
        if (iVar7 == 6) {
          iVar7 = flac_bitstream_getbits_u(param_1,8);
          param_2[3] = iVar7 + 1;
        }
        else {
          if (iVar7 == 7) {
            iVar7 = flac_bitstream_getbits_u(param_1,0x10);
            iVar7 = iVar7 + 1;
          }
          else {
            iVar7 = *(int *)(DAT_030e039c + iVar7 * 4);
          }
          param_2[3] = iVar7;
        }
        if (iVar9 < 0xc) {
          iVar7 = *(int *)(DAT_030e03a0 + iVar9 * 4);
LAB_030e0076:
          *param_2 = iVar7;
          if (*DAT_030e03a4 != 0) {
            *DAT_030e03a4 = 0;
            uVar11 = param_2[3];
            uVar13 = param_2[6];
            iVar7 = param_2[7];
            lVar2 = (ulonglong)uVar13 * (ulonglong)uVar11;
            piVar4[10] = (int)lVar2;
            piVar4[0xb] = uVar13 * ((int)uVar11 >> 0x1f) +
                          iVar7 * uVar11 + (int)((ulonglong)lVar2 >> 0x20);
          }
          if ((*param_2 != *piVar4) || (param_2[2] != piVar4[2])) {
            if (*param_2 != *piVar4) {
              hifi_debug_printf_ovl_0dc5(s_____samplerate_____030e03a8,iVar9);
            }
            if (param_2[2] != piVar4[2]) {
              hifi_debug_printf_ovl_0dc5(s_____bps_____030e03bc,iVar9);
            }
          }
          FUN_030dd7a6(param_1,8);
          iVar9 = FUN_030dd6ea(param_1);
          iVar9 = ((int)(iVar9 + ((uint)(iVar9 >> 0x1f) >> 0x1d)) >> 3) + -1;
          if (0 < iVar9) {
            for (iVar9 = iVar9 >> 1; iVar9 != 0; iVar9 = iVar9 + -1) {
            }
          }
          return 0;
        }
        if (iVar9 == 0xc) {
          iVar7 = flac_bitstream_getbits_u(param_1,8);
          iVar7 = iVar7 * 1000;
          goto LAB_030e0076;
        }
        if (iVar9 == 0xd) {
          iVar7 = flac_bitstream_getbits_u(param_1,0x10);
          goto LAB_030e0076;
        }
        if (iVar9 == 0xe) {
          iVar7 = flac_bitstream_getbits_u(param_1,0x10);
          iVar7 = iVar7 * 10;
          goto LAB_030e0076;
        }
        pcVar10 = s_illegal_sample_rate_code__d_030e03cc;
        goto LAB_030e0128;
      }
      pcVar10 = s_reserved_blocksize_code__0_030e0380;
    }
    hifi_debug_printf_ovl_0dc5(pcVar10);
  }
  return 0xffffffff;
}


