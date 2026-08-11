/**
 * FUN_0302b646 @ 0x0302b646
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302b646(int param_1,uint param_2)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  short *psVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  
  puVar5 = DAT_0302b9b4;
  psVar4 = DAT_0302b9b0;
  puVar3 = DAT_0302b9ac;
  iVar9 = DAT_0302b99c;
  piVar2 = DAT_0302b998;
  puVar8 = *(uint **)(DAT_0302b99c + 0xc);
  if (param_1 == 0xfb) {
    if (*puVar8 < param_2) {
      param_2 = *puVar8;
    }
    FUN_0302c950(param_2,0);
    return 1;
  }
  if (param_1 < 0xfc) {
    switch(param_1) {
    case 0xec:
      AudioPlayback_Start();
      return 1;
    case 0xed:
      FUN_0302a69e();
      return 1;
    case 0xee:
      FUN_0302afc0();
      return 1;
    case 0xef:
      iVar9 = 20000;
      if (*DAT_0302b9b0 != 4) {
        *(undefined4 *)(DAT_0302b99c + 0x24) = 0;
        FUN_03005604(0);
        *psVar4 = 4;
        iVar6 = rom_buffer_ready(5);
        while ((iVar6 == 1 && (iVar9 = iVar9 + -1, iVar9 != 0))) {
          dac_gain_curve_apply(1);
          iVar6 = rom_buffer_ready(5);
        }
        *DAT_0302b9c0 = 0;
        *DAT_0302b9c4 = 0;
        return 1;
      }
      return 1;
    case 0xf0:
      FUN_0302b0aa();
      return 1;
    case 0xf1:
      iVar6 = FUN_0302b278(param_2 & 0xffff);
      if (iVar6 != 0) {
        FUN_0302dd18(*(undefined4 *)(*(int *)(iVar9 + 0xc) + 4),DAT_0302b9b8);
        return 1;
      }
      return 1;
    case 0xf9:
      *DAT_0302b9ac = 2;
      FUN_0302b1fa(param_2);
      return 1;
    case 0xfa:
      *DAT_0302b9ac = 2;
      FUN_0302b19c(param_2);
      return 1;
    }
  }
  else {
    if (param_1 == 0x101) {
      if (param_2 != 0) {
        rom_memcpy(DAT_0302b9bc,puVar8 + 10,0xd);
      }
      FUN_03029b00((char)piVar2[4]);
      *puVar5 = 0;
      uVar7 = 0x2b;
LAB_0302b780:
      shared_frame_epilogue_c6b4(uVar7);
      return 1;
    }
    if (param_1 < 0x102) {
      if (param_1 == 0xfc) {
        FUN_0302c96e(puVar8 + 1);
        *piVar2 = 1;
        piVar2[1] = *(int *)(*(int *)(iVar9 + 0xc) + 4);
        uVar7 = 0x106;
        goto LAB_0302b780;
      }
      if (param_1 == 0xfd) {
        if (*DAT_0302b998 == 1) {
          FUN_0302c96e(puVar8 + 1);
          iVar6 = *(int *)(*(int *)(iVar9 + 0xc) + 4);
          *piVar2 = 2;
          piVar2[2] = iVar6;
        }
        *(undefined4 *)(iVar9 + 0x34) = *DAT_0302b9a0;
        return 1;
      }
      if (param_1 == 0xfe) {
        *DAT_0302b998 = 0;
        return 1;
      }
      if (param_1 == 0xff) {
        uVar1 = *(undefined1 *)(DAT_0302b9a4 + 0x12);
        *(undefined1 *)(DAT_0302b998 + 4) = uVar1;
        *puVar5 = uVar1;
        shared_mid_entry_c6f6(0x2b);
        FUN_0302aad4();
        return 1;
      }
    }
    else {
      if (param_1 == 0x10d) {
        FUN_0302c96e(puVar8 + 1);
        return 1;
      }
      if (param_1 == 0x110) {
        if (*(int *)(DAT_0302b99c + 0x4c) != 0) {
          FUN_02ffd4dc((int)(char)*(int *)(DAT_0302b99c + 0x4c));
        }
        *puVar3 = 2;
        FUN_0302b278(1);
        FUN_030059bc();
        FUN_0302a74e(param_2);
        FUN_030059bc();
        shared_frame_epilogue_c6b4(0x110);
        shared_frame_epilogue_c6b4(0x2b);
        return 1;
      }
      if (param_1 == 0x111) {
        FUN_030057ac();
        return 1;
      }
    }
  }
  return 0;
}


