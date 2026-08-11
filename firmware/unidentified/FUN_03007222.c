/**
 * FUN_03007222 @ 0x03007222
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03007222(void)

{
  short sVar1;
  undefined2 *puVar2;
  short *psVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint extraout_r3;
  uint extraout_r3_00;
  undefined2 *unaff_r4;
  char *unaff_r5;
  undefined2 unaff_r6;
  uint unaff_r7;
  ushort unaff_r8;
  int unaff_r9;
  uint unaff_r10;
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
  
  uVar6 = *(uint *)(unaff_r9 + 0x48) / unaff_r10;
  if (unaff_r7 < uVar6) {
    unaff_r7 = uVar6;
  }
  *unaff_r11 = unaff_r7 - uVar6;
  FUN_02fe1968(unaff_r7 - uVar6,&stack0x0000000c,&stack0x00000018,&stack0x0000001c);
  FUN_0300584c(in_stack_0000000c,in_stack_00000018,in_stack_0000001c,0);
  iVar5 = FUN_02ff2e00(0x49);
  psVar3 = DAT_03007514;
  iVar7 = DAT_03007510;
  puVar2 = DAT_0300750c;
  if (iVar5 == 1) {
    if (*unaff_r5 != '\x01') {
      sStack00000014 = 0x122;
      sStack00000010 = 0x1e;
      uStack00000012 = 0x21;
      uStack00000016 = 0x30;
      in_stack_0000000c = unaff_r8;
      do {
        uVar6 = (uint)in_stack_0000000c;
        psVar3[uVar6] = *(short *)(iVar7 + uVar6 * 2 + 0x60);
        iVar5 = DAT_03007518;
        in_stack_0000000c = (ushort)(uVar6 + 1);
      } while ((uVar6 + 1 & 0xffff) < 0x80);
      uVar4 = unaff_r8;
      if (*psVar3 == 0) {
        do {
          in_stack_0000000c = uVar4;
          uVar6 = (uint)in_stack_0000000c;
          sVar1 = *(short *)(iVar5 + uVar6 * 2);
          if (sVar1 == 0) {
            psVar3[in_stack_0000000c] = unaff_r8;
            if (psVar3[uVar6 - 4] == 0x2e) {
              psVar3[uVar6 - 4] = unaff_r8;
            }
            if (psVar3[uVar6 - 5] == 0x2e) {
              psVar3[uVar6 - 5] = unaff_r8;
            }
            break;
          }
          psVar3[uVar6] = sVar1;
          in_stack_0000000c = (ushort)(uVar6 + 1);
          uVar4 = in_stack_0000000c;
        } while ((uVar6 + 1 & 0xffff) < 0x80);
      }
      FUN_02fef2b2(0x50);
      uVar6 = FUN_02fed6a6(DAT_03007514);
      if ((uint)((int)sStack00000014 - (int)sStack00000010) < uVar6) {
        FUN_02fee2a8(&stack0x00000010,CONCAT22(uStack00000012,sStack00000010),unaff_r8 | 0x100000,
                     extraout_r3 & 0xffff0000 | 0x50);
        FUN_02ff2de4(0x4a);
      }
      else {
        FUN_02ff2e26(0x4a);
      }
      *unaff_r4 = *puVar2;
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
  iVar7 = FUN_02ff2e00(0x4f);
  if (iVar7 == 1) {
    sStack00000014 = 0x122;
    sStack00000010 = 0x1e;
    uStack00000016 = 0x30;
    uStack00000012 = 0x21;
    FUN_02fef2b2(0x50);
    uVar6 = FUN_02fed6a6(DAT_0300751c);
    if ((uint)((int)sStack00000014 - (int)sStack00000010) < uVar6) {
      FUN_02fee2a8(&stack0x00000010,CONCAT22(uStack00000012,sStack00000010),unaff_r8 | 0x100000,
                   extraout_r3_00 & 0xffff0000 | 0x50);
      FUN_02ff2de4(0x4a);
    }
    else {
      FUN_02ff2e26(0x4a);
    }
    *unaff_r4 = *puVar2;
    FUN_02feda18(&stack0x00000010,&stack0x00000010,DAT_0300751c,2);
    iVar7 = FUN_02ff2e44(1);
    if (iVar7 != 0) {
      FUN_02ff2de4(0x33);
    }
  }
LAB_030073e8:
  iVar7 = FUN_02ff2e44(0x4a);
  if (iVar7 == 1) {
    if (*unaff_r5 == '\x01') {
      in_stack_00000008 = FUN_02fee544(2);
      *unaff_r4 = *puVar2;
      FUN_02fee180(DAT_0300751c);
      *unaff_r4 = unaff_r6;
    }
    else {
      in_stack_00000008 = FUN_02fee544(2);
      *unaff_r4 = *puVar2;
      FUN_02fee180(DAT_03007514);
      *unaff_r4 = unaff_r6;
    }
  }
  iVar7 = FUN_02ff2e44(0xae);
  if (iVar7 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *puVar2;
    FUN_02fedc4e(DAT_03007520,1);
    *unaff_r4 = unaff_r6;
  }
  iVar7 = FUN_02ff2e44(0xaf);
  if (iVar7 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *puVar2;
    FUN_02fedd96(DAT_03007524,1);
    *unaff_r4 = unaff_r6;
  }
  iVar7 = FUN_02ff2e44(0xb0);
  if (iVar7 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *puVar2;
    FUN_02fedede(DAT_03007528,1);
    *unaff_r4 = unaff_r6;
  }
  FUN_02fee568(in_stack_00000020);
  unaff_r4[1] = (short)in_stack_00000024;
  *unaff_r4 = (short)in_stack_00000028;
  FUN_02fee544(in_stack_00000008);
  return;
}


