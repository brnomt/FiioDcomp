/**
 * FUN_0300af38 @ 0x0300af38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300af38(uint param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *extraout_r1;
  undefined1 *puVar4;
  undefined1 *extraout_r1_00;
  undefined1 *extraout_r1_01;
  undefined1 *extraout_r1_02;
  undefined1 *extraout_r1_03;
  undefined1 *extraout_r1_04;
  int unaff_r4;
  undefined4 unaff_r5;
  int unaff_r6;
  ushort *puVar5;
  undefined1 *unaff_r8;
  undefined1 unaff_r11;
  undefined8 uVar6;
  undefined2 in_stack_00000008;
  
  if ((param_1 & 0x100000) == 0 || (param_1 & 0xfffff) == 0) {
    puVar4 = &stack0x000000a0;
    if (!SCARRY4(unaff_r4 + 100,0x68)) {
LAB_0300afec:
      if (param_1 == 2) {
        FUN_02ff9700(0x6c,puVar4);
        FUN_03010d78(0x80,0);
        puVar4 = extraout_r1_04;
      }
      FUN_02ff9700(0x76,puVar4);
      return;
    }
    puVar4 = (undefined1 *)(param_1 << 0xc);
    iVar2 = *(int *)(unaff_r4 + 0xe8) << 1;
    puVar5 = *(ushort **)(unaff_r4 + 0xec);
code_r0x0300af60:
    if (iVar2 == 0xff000) {
      FUN_02fe85fc(DAT_0300b030,DAT_0300b02c,&stack0x00000008);
      return;
    }
    if (iVar2 == 0x10ff000) {
      in_stack_00000008 = (undefined2)unaff_r5;
      FUN_02fe85fc(DAT_0300b030,DAT_0300b02c,&stack0x00000008);
      return;
    }
    if (iVar2 != 0xf0ff200) {
      return;
    }
  }
  else {
    uVar6 = FUN_02ff2ec2();
    puVar4 = (undefined1 *)((ulonglong)uVar6 >> 0x20);
    if ((int)uVar6 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x40000040;
      FUN_02ff9700(0x42);
      puVar4 = extraout_r1;
    }
    puVar5 = DAT_0300af2c;
    unaff_r5 = 1;
    unaff_r8 = &DAT_0307a928;
    unaff_r11 = 2;
    if (iVar2 != unaff_r6) {
      if (unaff_r6 <= iVar2) {
        iVar2 = iVar2 + -0x40f01000;
        unaff_r11 = 2;
        goto code_r0x0300af60;
      }
      if (iVar2 == 0x20000002) {
        param_1 = (uint)*DAT_0300af2c;
        if (param_1 == 1) {
          DAT_0307a92c = 1;
        }
        goto LAB_0300afec;
      }
      if (iVar2 != 0x20001000) {
        puVar4 = (undefined1 *)0xe0000fc0;
        if (iVar2 == 0x40000040) {
          uVar6 = FUN_02ff9760(0x73);
          puVar4 = (undefined1 *)((ulonglong)uVar6 >> 0x20);
          if ((int)uVar6 != 0) {
            return;
          }
          DAT_0307a92c = 1;
          uVar1 = *puVar5;
          if (uVar1 == 0) {
            FUN_03010d78(0x7d,0);
            *puVar5 = 1;
            FUN_02ff9700(0x6a);
            uVar3 = 0x5b;
            puVar4 = extraout_r1_01;
            goto LAB_0300afaa;
          }
          if (uVar1 == 1) {
            FUN_03010d78(0x7e,0);
            *puVar5 = 2;
            uVar3 = 0x6b;
            puVar4 = extraout_r1_02;
            goto LAB_0300afaa;
          }
          if (uVar1 == 2) {
            FUN_03010d78(0x7f,0);
            *puVar5 = 1;
            uVar3 = 0x6a;
            puVar4 = extraout_r1_03;
            goto LAB_0300afaa;
          }
        }
        else if (iVar2 != 0x40000200) {
          return;
        }
      }
    }
  }
  *(undefined4 *)(unaff_r8 + 4) = unaff_r5;
  if (*puVar5 == 1 || *puVar5 == 2) {
    *unaff_r8 = unaff_r11;
  }
  else {
    FUN_02ff9700(0x79,puVar4);
    puVar4 = extraout_r1_00;
  }
  uVar3 = 0x6c;
LAB_0300afaa:
  FUN_02ff9700(uVar3,puVar4);
  return;
}


