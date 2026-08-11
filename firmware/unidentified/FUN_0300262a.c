/**
 * FUN_0300262a @ 0x0300262a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300262a(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  short sVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  short unaff_r4;
  int unaff_r5;
  ushort uVar8;
  uint unaff_r6;
  short unaff_r8;
  int unaff_r9;
  undefined4 in_stack_00000008;
  short sStack0000000c;
  short sStack0000000e;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  uint in_stack_0000002c;
  undefined2 uStack00000030;
  short sStack00000032;
  short sStack00000034;
  short sStack00000036;
  ushort in_stack_00000038;
  undefined4 in_stack_0000003c;
  short in_stack_0000004c;
  uint in_stack_00000058;
  
code_r0x0300262a:
  iVar7 = (int)(short)(in_stack_0000004c + unaff_r4);
  uVar5 = 0x75;
LAB_03002634:
  FUN_02fec55a(uVar5,iVar7,param_3);
  do {
    sStack00000036 = sStack00000032;
    _uStack00000030 = CONCAT22(sStack00000032 + 5,uStack00000030);
    sStack00000036 = sStack00000036 + 0x14;
    FUN_02feacc0(&stack0x00000030,&stack0x00000030,unaff_r5 + 0xc,0);
    uVar6 = unaff_r6 + 1;
    unaff_r5 = *(int *)(unaff_r5 + 4);
    unaff_r6 = uVar6 & 0xffff;
    if ((5 < unaff_r6) || (in_stack_00000058 <= unaff_r6)) {
      FUN_02ff008c(0x18d);
      iVar7 = FUN_02ff00a8(0x174);
      if (iVar7 == 0) goto LAB_0300292a;
      FUN_02ff008c(0x3e);
      FUN_02febdc2(0x8c,&stack0x00000038);
      FUN_02febdc2(0x6e,&stack0x00000048);
      in_stack_00000024 = (int)(short)(unaff_r4 + 0x1c);
      uVar8 = 0;
      in_stack_00000028 = (int)(short)((short)in_stack_00000014 + 1);
      in_stack_0000001c = unaff_r9 - 1;
      in_stack_00000014 = unaff_r9 + 1;
      break;
    }
    sVar2 = (short)uVar6;
    _uStack00000030 = CONCAT22(sVar2 * 0x18 + 0x17,(short)in_stack_00000028);
    sStack00000034 = (short)in_stack_00000028 + in_stack_00000038;
    sStack00000036 = sVar2 * 0x18 + 0x2f;
    if ((*(ushort *)(DAT_030025ec + 0x16) == unaff_r6) && (iVar7 = FUN_02ff00ec(0x1dc), iVar7 == 0))
    {
      if (unaff_r6 == 0) {
        FUN_02fec55a(in_stack_0000002c & 0xffff);
      }
      else {
        FUN_02fec55a();
      }
      *DAT_030025d8 = *DAT_030025e8;
      uVar6 = FUN_02fea94e(unaff_r5 + 0xc);
      *(int *)(DAT_030025f0 + 4) = unaff_r5 + 0xc;
      if (in_stack_00000038 < uVar6) {
        in_stack_0000001c = _uStack00000030;
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
      *DAT_030025d8 = *DAT_030025dc;
    }
    iVar7 = DAT_030025ec;
    if ((*(ushort *)(DAT_030025ec + 0x16) != unaff_r6) || (iVar4 = FUN_02ff00ec(0x1dc), iVar4 != 0))
    {
      sVar1 = *DAT_030025e4;
      if (sVar1 == 5) {
        if (*(short *)(iVar7 + 10) != 3) goto LAB_0300272c;
      }
      else if (sVar1 == 4) {
        if (*(short *)(iVar7 + 10) != 1) goto LAB_0300272c;
      }
      else if ((sVar1 == 3) && (*(short *)(iVar7 + 10) != 2)) {
LAB_0300272c:
        param_3 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + sVar2 * 0x18);
        iVar7 = (int)(short)(in_stack_0000004c + unaff_r4);
        uVar5 = 0x6e;
        goto LAB_03002634;
      }
      param_3 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + sVar2 * 0x18);
      iVar7 = (int)(short)(in_stack_0000004c + unaff_r4);
      uVar5 = 0x6f;
      goto LAB_03002634;
    }
    sVar1 = *DAT_030025e4;
    if (sVar1 != 5) goto code_r0x030025a6;
    if (*(short *)(iVar7 + 10) == 3) goto LAB_0300261e;
    FUN_02fec55a(0x74,(int)(short)(in_stack_0000004c + unaff_r4),
                 (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + sVar2 * 0x18));
  } while( true );
LAB_030026b8:
  if (*(ushort *)(DAT_03002ab4 + 0x16) == uVar8 || *(ushort *)(DAT_03002ab4 + 0x18) == uVar8) {
    sStack00000034 = (short)in_stack_00000024 + in_stack_00000038;
    sStack00000036 = uVar8 * 0x18 + 0x2f;
    _uStack00000030 = CONCAT22(uVar8 * 0x18 + 0x17,(short)in_stack_00000024);
    if (*(ushort *)(DAT_03002ab4 + 0x18) == uVar8) {
      in_stack_00000008 = 0x19;
      FUN_02fec2ac(0x7a,(int)unaff_r4);
      sVar2 = *DAT_03002ab8;
      if (sVar2 == 5) {
        if (*(short *)(DAT_03002ab4 + 10) == 3) goto LAB_0300279c;
LAB_0300276c:
        sVar2 = *(short *)(DAT_03002ab4 + 0x18);
        uVar5 = 0x6e;
      }
      else {
        if (sVar2 == 4) {
          if (*(short *)(DAT_03002ab4 + 10) == 1) goto LAB_0300279c;
          goto LAB_0300276c;
        }
        if ((sVar2 == 3) && (*(short *)(DAT_03002ab4 + 10) != 2)) goto LAB_0300276c;
LAB_0300279c:
        sVar2 = *(short *)(DAT_03002ab4 + 0x18);
        uVar5 = 0x6f;
      }
      FUN_02fec55a(uVar5,(int)(short)(in_stack_0000004c + unaff_r4),
                   (int)(short)(unaff_r8 + sVar2 * 0x18 + in_stack_0000003c._2_2_));
    }
    if (*(ushort *)(DAT_03002ab4 + 0x16) == uVar8) {
      if (uVar8 == 0) {
        FUN_02fec55a(in_stack_0000001c & 0xffff,(int)(short)(unaff_r4 + 4),(int)sStack00000032);
      }
      else {
        FUN_02fec55a();
      }
      sVar2 = *DAT_03002ab8;
      if (sVar2 == 5) {
        if (*(short *)(DAT_03002ab4 + 10) == 3) goto LAB_0300284c;
LAB_03002810:
        FUN_02fec55a(0x74,(int)(short)(in_stack_0000004c + unaff_r4),
                     (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + uVar8 * 0x18));
      }
      else {
        if (sVar2 == 4) {
          if (*(short *)(DAT_03002ab4 + 10) != 1) goto LAB_03002810;
LAB_0300284c:
          uVar5 = 0x75;
        }
        else {
          if ((sVar2 != 3) || (*(short *)(DAT_03002ab4 + 10) == 2)) goto LAB_0300284c;
          uVar5 = 0x74;
        }
        FUN_02fec55a(uVar5,(int)(short)(in_stack_0000004c + unaff_r4),
                     (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + uVar8 * 0x18));
      }
      *DAT_03002ac0 = *DAT_03002abc;
      uVar6 = FUN_02fea94e(unaff_r5 + 0xc);
      *(int *)(DAT_03002ac4 + 4) = unaff_r5 + 0xc;
      if (in_stack_00000038 < uVar6) {
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
  }
  uVar8 = uVar8 + 1;
  unaff_r5 = *(int *)(unaff_r5 + 4);
  if (5 < uVar8) {
    FUN_02ff008c(0x18d);
LAB_0300292a:
    iVar7 = FUN_02ff00ec(0x178);
    if (iVar7 != 0) {
      in_stack_00000010 = FUN_02feb810(1);
      iVar7 = FUN_02ff00ec(0x1dc);
      puVar3 = DAT_03002ac0;
      if (iVar7 == 0) {
        *DAT_03002ac0 = *DAT_03002abc;
        FUN_02feb428(*(undefined4 *)(DAT_03002ac4 + 4));
        FUN_02ff008c(0x3e);
        *puVar3 = *DAT_03002ac8;
      }
      FUN_02feb810(in_stack_00000010);
    }
    FUN_02feb810(in_stack_00000010);
    *DAT_03002ac0 = (short)in_stack_00000020;
    FUN_02feb7ec(in_stack_00000018);
    return;
  }
  goto LAB_030026b8;
code_r0x030025a6:
  if (sVar1 == 4) {
    if (*(short *)(iVar7 + 10) == 1) goto LAB_0300261e;
  }
  else if ((sVar1 != 3) || (*(short *)(iVar7 + 10) == 2)) goto LAB_0300261e;
  param_3 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + sVar2 * 0x18);
  iVar7 = (int)(short)(in_stack_0000004c + unaff_r4);
  uVar5 = 0x74;
  goto LAB_03002634;
LAB_0300261e:
  param_3 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + sVar2 * 0x18);
  goto code_r0x0300262a;
}


