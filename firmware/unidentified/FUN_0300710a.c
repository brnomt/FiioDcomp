/**
 * FUN_0300710a @ 0x0300710a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300710a(undefined2 *param_1)

{
  short sVar1;
  uint *puVar2;
  undefined2 *puVar3;
  short *psVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint extraout_r3;
  uint extraout_r3_00;
  undefined2 *unaff_r4;
  char *unaff_r5;
  undefined2 unaff_r6;
  uint unaff_r7;
  uint uVar9;
  ushort unaff_r8;
  int unaff_r9;
  int *unaff_r11;
  undefined4 in_stack_00000008;
  ushort in_stack_0000000c;
  short sStack00000010;
  undefined2 uStack00000012;
  short sStack00000014;
  undefined2 uStack00000016;
  undefined1 in_stack_00000018;
  undefined1 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  
  do {
    FUN_02feeb60(param_1[2] + in_stack_0000000c + 0x14,param_1[3] + 0x99,*param_1,param_1[1]);
    in_stack_0000000c = in_stack_0000000c + 1;
    param_1 = DAT_03007504;
  } while (in_stack_0000000c < 0x122);
  FUN_02fef2b2(0xf6,(int)(short)((short)in_stack_0000002c + 0x13 + DAT_03007504[2]),
               (int)(short)(DAT_03007504[3] + 0x98));
  iVar6 = FUN_02ff2e00(0x40);
  if (iVar6 == 1) {
    if (*(int *)(unaff_r9 + 0x44) == 1) {
      uVar9 = *(int *)(unaff_r9 + 0x4c) - *(int *)(unaff_r9 + 0x48);
    }
    else {
      uVar9 = *(uint *)*unaff_r11;
    }
    unaff_r7 = uVar9 / 1000;
    FUN_02fe1968(unaff_r7,&stack0x0000000c,&stack0x00000018,&stack0x0000001c);
    FUN_0300584c(in_stack_0000000c,in_stack_00000018,in_stack_0000001c,1);
  }
  iVar6 = FUN_02ff2e00(0x3f);
  puVar2 = DAT_03007508;
  if (iVar6 == 1) {
    if (*(uint *)(*unaff_r11 + 4) != unaff_r7) {
      unaff_r7 = *(uint *)(*unaff_r11 + 4);
    }
    uVar9 = unaff_r7 / 1000;
    if (uVar9 != *DAT_03007508) {
      FUN_02ff2de4(0x4c);
      if (*(int *)(unaff_r9 + 0x44) == 1) {
        uVar8 = *(uint *)(unaff_r9 + 0x48) / 1000;
        if (uVar9 < uVar8) {
          uVar9 = uVar8;
        }
        uVar9 = uVar9 - uVar8;
      }
      *puVar2 = uVar9;
      FUN_02fe1968(uVar9,&stack0x0000000c,&stack0x00000018,&stack0x0000001c);
      FUN_0300584c(in_stack_0000000c,in_stack_00000018,in_stack_0000001c,0);
    }
  }
  iVar7 = FUN_02ff2e00(0x49);
  psVar4 = DAT_03007514;
  iVar6 = DAT_03007510;
  puVar3 = DAT_0300750c;
  if (iVar7 == 1) {
    if (*unaff_r5 != '\x01') {
      sStack00000014 = 0x122;
      sStack00000010 = 0x1e;
      uStack00000012 = 0x21;
      uStack00000016 = 0x30;
      in_stack_0000000c = unaff_r8;
      do {
        uVar9 = (uint)in_stack_0000000c;
        psVar4[uVar9] = *(short *)(iVar6 + uVar9 * 2 + 0x60);
        iVar7 = DAT_03007518;
        in_stack_0000000c = (ushort)(uVar9 + 1);
      } while ((uVar9 + 1 & 0xffff) < 0x80);
      uVar5 = unaff_r8;
      if (*psVar4 == 0) {
        do {
          in_stack_0000000c = uVar5;
          uVar9 = (uint)in_stack_0000000c;
          sVar1 = *(short *)(iVar7 + uVar9 * 2);
          if (sVar1 == 0) {
            psVar4[in_stack_0000000c] = unaff_r8;
            if (psVar4[uVar9 - 4] == 0x2e) {
              psVar4[uVar9 - 4] = unaff_r8;
            }
            if (psVar4[uVar9 - 5] == 0x2e) {
              psVar4[uVar9 - 5] = unaff_r8;
            }
            break;
          }
          psVar4[uVar9] = sVar1;
          in_stack_0000000c = (ushort)(uVar9 + 1);
          uVar5 = in_stack_0000000c;
        } while ((uVar9 + 1 & 0xffff) < 0x80);
      }
      FUN_02fef2b2(0x50);
      uVar9 = FUN_02fed6a6(DAT_03007514);
      if ((uint)((int)sStack00000014 - (int)sStack00000010) < uVar9) {
        FUN_02fee2a8(&stack0x00000010,CONCAT22(uStack00000012,sStack00000010),unaff_r8 | 0x100000,
                     extraout_r3 & 0xffff0000 | 0x50);
        FUN_02ff2de4(0x4a);
      }
      else {
        FUN_02ff2e26(0x4a);
      }
      *unaff_r4 = *puVar3;
      FUN_02feda18(&stack0x00000010,&stack0x00000010,DAT_03007514,2);
      *unaff_r4 = unaff_r6;
      goto LAB_0300733c;
    }
  }
  else {
LAB_0300733c:
    if (*unaff_r5 != '\x01') goto LAB_030073e8;
  }
  FUN_030041b4(0);
  iVar6 = FUN_02ff2e00(0x4f);
  if (iVar6 == 1) {
    sStack00000014 = 0x122;
    sStack00000010 = 0x1e;
    uStack00000016 = 0x30;
    uStack00000012 = 0x21;
    FUN_02fef2b2(0x50);
    uVar9 = FUN_02fed6a6(DAT_0300751c);
    if ((uint)((int)sStack00000014 - (int)sStack00000010) < uVar9) {
      FUN_02fee2a8(&stack0x00000010,CONCAT22(uStack00000012,sStack00000010),unaff_r8 | 0x100000,
                   extraout_r3_00 & 0xffff0000 | 0x50);
      FUN_02ff2de4(0x4a);
    }
    else {
      FUN_02ff2e26(0x4a);
    }
    *unaff_r4 = *puVar3;
    FUN_02feda18(&stack0x00000010,&stack0x00000010,DAT_0300751c,2);
    iVar6 = FUN_02ff2e44(1);
    if (iVar6 != 0) {
      FUN_02ff2de4(0x33);
    }
  }
LAB_030073e8:
  iVar6 = FUN_02ff2e44(0x4a);
  if (iVar6 == 1) {
    if (*unaff_r5 == '\x01') {
      in_stack_00000008 = FUN_02fee544(2);
      *unaff_r4 = *puVar3;
      FUN_02fee180(DAT_0300751c);
      *unaff_r4 = unaff_r6;
    }
    else {
      in_stack_00000008 = FUN_02fee544(2);
      *unaff_r4 = *puVar3;
      FUN_02fee180(DAT_03007514);
      *unaff_r4 = unaff_r6;
    }
  }
  iVar6 = FUN_02ff2e44(0xae);
  if (iVar6 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *puVar3;
    FUN_02fedc4e(DAT_03007520,1);
    *unaff_r4 = unaff_r6;
  }
  iVar6 = FUN_02ff2e44(0xaf);
  if (iVar6 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *puVar3;
    FUN_02fedd96(DAT_03007524,1);
    *unaff_r4 = unaff_r6;
  }
  iVar6 = FUN_02ff2e44(0xb0);
  if (iVar6 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *puVar3;
    FUN_02fedede(DAT_03007528,1);
    *unaff_r4 = unaff_r6;
  }
  FUN_02fee568(in_stack_00000020);
  unaff_r4[1] = (short)in_stack_00000024;
  *unaff_r4 = (short)in_stack_00000028;
  FUN_02fee544(in_stack_00000008);
  return;
}


