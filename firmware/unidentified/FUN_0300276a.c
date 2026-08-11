/**
 * FUN_0300276a @ 0x0300276a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300276a(int param_1)

{
  short sVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  short unaff_r4;
  int unaff_r5;
  uint unaff_r6;
  short unaff_r8;
  int unaff_r11;
  char in_ZR;
  undefined4 in_stack_00000008;
  short sStack0000000c;
  short sStack0000000e;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  undefined2 uStack00000030;
  short sStack00000032;
  short sStack00000034;
  short sStack00000036;
  ushort in_stack_00000038;
  undefined4 in_stack_0000003c;
  short in_stack_0000004c;
  
code_r0x0300276a:
  if (in_ZR != '\0') goto LAB_0300279c;
LAB_0300276c:
  sVar1 = unaff_r8 + *(short *)(param_1 + 0x18) * 0x18 + in_stack_0000003c._2_2_;
  uVar3 = 0x6e;
  do {
    FUN_02fec55a(uVar3,(int)(short)(in_stack_0000004c + unaff_r4),(int)sVar1);
    do {
      if (*(ushort *)(DAT_03002ab4 + 0x16) == unaff_r6) {
        if (unaff_r6 == 0) {
          FUN_02fec55a(in_stack_0000001c & 0xffff);
        }
        else {
          FUN_02fec55a();
        }
        sVar1 = *DAT_03002ab8;
        if (sVar1 == 5) {
          if (*(short *)(DAT_03002ab4 + 10) == 3) goto LAB_0300284c;
LAB_03002810:
          FUN_02fec55a(0x74,(int)(short)(in_stack_0000004c + unaff_r4),
                       (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + (short)(unaff_r11 << 3)));
        }
        else {
          if (sVar1 == 4) {
            if (*(short *)(DAT_03002ab4 + 10) != 1) goto LAB_03002810;
LAB_0300284c:
            sVar1 = (short)(unaff_r11 << 3);
            uVar3 = 0x75;
          }
          else {
            if ((sVar1 != 3) || (*(short *)(DAT_03002ab4 + 10) == 2)) goto LAB_0300284c;
            sVar1 = (short)(unaff_r11 << 3);
            uVar3 = 0x74;
          }
          FUN_02fec55a(uVar3,(int)(short)(in_stack_0000004c + unaff_r4),
                       (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + sVar1));
        }
        *DAT_03002ac0 = *DAT_03002abc;
        uVar4 = FUN_02fea94e(unaff_r5 + 0xc);
        *(int *)(DAT_03002ac4 + 4) = unaff_r5 + 0xc;
        if (in_stack_00000038 < uVar4) {
          in_stack_0000002c = _uStack00000030;
          in_stack_00000008 = CONCAT22(sStack00000032 + 5,(short)_uStack00000030);
          sStack0000000c = sStack00000034;
          sStack0000000e = sStack00000032 + 0x14;
          FUN_02feb550(&stack0x00000008,_uStack00000030,0x100005,0x8c);
          FUN_02ff008c(0x178);
        }
        else {
          FUN_02ff00ce(0x178);
        }
      }
      else {
        *DAT_03002ac0 = *DAT_03002ac8;
      }
      sStack00000036 = sStack00000032;
      _uStack00000030 = CONCAT22(sStack00000032 + 5,uStack00000030);
      sStack00000036 = sStack00000036 + 0x14;
      FUN_02feacc0(&stack0x00000030,&stack0x00000030,unaff_r5 + 0xc,0);
      do {
        uVar4 = unaff_r6 + 1;
        unaff_r5 = *(int *)(unaff_r5 + 4);
        unaff_r6 = uVar4 & 0xffff;
        if (5 < unaff_r6) {
          FUN_02ff008c(0x18d);
          iVar5 = FUN_02ff00ec(0x178);
          if (iVar5 != 0) {
            in_stack_00000010 = FUN_02feb810(1);
            iVar5 = FUN_02ff00ec(0x1dc);
            puVar2 = DAT_03002ac0;
            if (iVar5 == 0) {
              *DAT_03002ac0 = *DAT_03002abc;
              FUN_02feb428(*(undefined4 *)(DAT_03002ac4 + 4));
              FUN_02ff008c(0x3e);
              *puVar2 = *DAT_03002ac8;
            }
            FUN_02feb810(in_stack_00000010);
          }
          FUN_02feb810(in_stack_00000010);
          *DAT_03002ac0 = (short)in_stack_00000020;
          FUN_02feb7ec(in_stack_00000018);
          return;
        }
      } while (*(ushort *)(DAT_03002ab4 + 0x16) != unaff_r6 &&
               *(ushort *)(DAT_03002ab4 + 0x18) != unaff_r6);
      unaff_r11 = unaff_r6 * 3;
      sVar1 = (short)uVar4 * 0x18;
      sStack00000034 = (short)in_stack_00000024 + in_stack_00000038;
      sStack00000036 = sVar1 + 0x2f;
      _uStack00000030 = CONCAT22(sVar1 + 0x17,(short)in_stack_00000024);
    } while (*(ushort *)(DAT_03002ab4 + 0x18) != unaff_r6);
    in_stack_00000008 = 0x19;
    FUN_02fec2ac(0x7a);
    sVar1 = *DAT_03002ab8;
    param_1 = DAT_03002ab4;
    if (sVar1 == 5) {
      in_ZR = *(short *)(DAT_03002ab4 + 10) == 3;
      goto code_r0x0300276a;
    }
    if (sVar1 == 4) {
      if (*(short *)(DAT_03002ab4 + 10) != 1) goto LAB_0300276c;
    }
    else if ((sVar1 == 3) && (*(short *)(DAT_03002ab4 + 10) != 2)) goto LAB_0300276c;
LAB_0300279c:
    sVar1 = unaff_r8 + *(short *)(DAT_03002ab4 + 0x18) * 0x18 + in_stack_0000003c._2_2_;
    uVar3 = 0x6f;
  } while( true );
}


