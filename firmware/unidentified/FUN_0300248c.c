/**
 * FUN_0300248c @ 0x0300248c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300248c(short param_1,uint param_2)

{
  short sVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  short unaff_r4;
  int unaff_r5;
  ushort uVar7;
  uint unaff_r6;
  int unaff_r7;
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
  uint in_stack_00000028;
  uint in_stack_0000002c;
  undefined2 uStack00000030;
  short sStack00000032;
  short sStack00000034;
  short sStack00000036;
  ushort in_stack_00000038;
  undefined4 in_stack_0000003c;
  short in_stack_0000004c;
  uint in_stack_00000058;
  
  do {
    param_1 = param_1 + (short)unaff_r7 * 8;
    _uStack00000030 = CONCAT22(param_1,uStack00000030);
    sStack00000034 = (short)param_2 + in_stack_00000038;
    sStack00000036 = param_1 + 0x18;
    if ((*(ushort *)(DAT_030025ec + 0x16) == unaff_r6) && (iVar3 = FUN_02ff00ec(0x1dc), iVar3 == 0))
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
    iVar3 = DAT_030025ec;
    if ((*(ushort *)(DAT_030025ec + 0x16) == unaff_r6) && (iVar4 = FUN_02ff00ec(0x1dc), iVar4 == 0))
    {
      sVar1 = *DAT_030025e4;
      if (sVar1 != 5) {
        if (sVar1 == 4) {
          if (*(short *)(iVar3 + 10) != 1) goto LAB_03002606;
        }
        else if ((sVar1 == 3) && (*(short *)(iVar3 + 10) != 2)) {
LAB_03002606:
          iVar4 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + (short)(unaff_r7 << 3));
          iVar3 = (int)(short)(in_stack_0000004c + unaff_r4);
          uVar5 = 0x74;
          goto LAB_03002634;
        }
LAB_0300261e:
        iVar4 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + (short)(unaff_r7 << 3));
        iVar3 = (int)(short)(in_stack_0000004c + unaff_r4);
        uVar5 = 0x75;
        goto LAB_03002634;
      }
      if (*(short *)(iVar3 + 10) == 3) goto LAB_0300261e;
      FUN_02fec55a(0x74,(int)(short)(in_stack_0000004c + unaff_r4),
                   (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + (short)(unaff_r7 << 3)));
    }
    else {
      sVar1 = *DAT_030025e4;
      if (sVar1 == 5) {
        if (*(short *)(iVar3 + 10) != 3) goto LAB_0300272c;
      }
      else if (sVar1 == 4) {
        if (*(short *)(iVar3 + 10) != 1) goto LAB_0300272c;
      }
      else if ((sVar1 == 3) && (*(short *)(iVar3 + 10) != 2)) {
LAB_0300272c:
        iVar4 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + (short)(unaff_r7 << 3));
        iVar3 = (int)(short)(in_stack_0000004c + unaff_r4);
        uVar5 = 0x6e;
        goto LAB_03002634;
      }
      iVar4 = (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + (short)(unaff_r7 << 3));
      iVar3 = (int)(short)(in_stack_0000004c + unaff_r4);
      uVar5 = 0x6f;
LAB_03002634:
      FUN_02fec55a(uVar5,iVar3,iVar4);
    }
    sStack00000036 = sStack00000032;
    _uStack00000030 = CONCAT22(sStack00000032 + 5,uStack00000030);
    sStack00000036 = sStack00000036 + 0x14;
    FUN_02feacc0(&stack0x00000030,&stack0x00000030,unaff_r5 + 0xc,0);
    unaff_r5 = *(int *)(unaff_r5 + 4);
    unaff_r6 = unaff_r6 + 1 & 0xffff;
    if ((5 < unaff_r6) || (in_stack_00000058 <= unaff_r6)) break;
    _uStack00000030 = in_stack_00000028 & 0xffff;
    unaff_r7 = unaff_r6 * 3;
    param_1 = 0x17;
    param_2 = in_stack_00000028;
  } while( true );
  FUN_02ff008c(0x18d);
  iVar3 = FUN_02ff00a8(0x174);
  if (iVar3 != 0) {
    FUN_02ff008c(0x3e);
    FUN_02febdc2(0x8c,&stack0x00000038);
    FUN_02febdc2(0x6e,&stack0x00000048);
    in_stack_00000024 = (int)(short)(unaff_r4 + 0x1c);
    uVar7 = 0;
    in_stack_00000028 = (uint)(short)((short)in_stack_00000014 + 1);
    in_stack_0000001c = unaff_r9 - 1;
    in_stack_00000014 = unaff_r9 + 1;
    do {
      if (*(ushort *)(DAT_03002ab4 + 0x16) == uVar7 || *(ushort *)(DAT_03002ab4 + 0x18) == uVar7) {
        sStack00000034 = (short)in_stack_00000024 + in_stack_00000038;
        sStack00000036 = uVar7 * 0x18 + 0x2f;
        _uStack00000030 = CONCAT22(uVar7 * 0x18 + 0x17,(short)in_stack_00000024);
        if (*(ushort *)(DAT_03002ab4 + 0x18) == uVar7) {
          in_stack_00000008 = 0x19;
          FUN_02fec2ac(0x7a,(int)unaff_r4);
          sVar1 = *DAT_03002ab8;
          if (sVar1 == 5) {
            if (*(short *)(DAT_03002ab4 + 10) == 3) goto LAB_0300279c;
LAB_0300276c:
            sVar1 = *(short *)(DAT_03002ab4 + 0x18);
            uVar5 = 0x6e;
          }
          else {
            if (sVar1 == 4) {
              if (*(short *)(DAT_03002ab4 + 10) == 1) goto LAB_0300279c;
              goto LAB_0300276c;
            }
            if ((sVar1 == 3) && (*(short *)(DAT_03002ab4 + 10) != 2)) goto LAB_0300276c;
LAB_0300279c:
            sVar1 = *(short *)(DAT_03002ab4 + 0x18);
            uVar5 = 0x6f;
          }
          FUN_02fec55a(uVar5,(int)(short)(in_stack_0000004c + unaff_r4),
                       (int)(short)(unaff_r8 + sVar1 * 0x18 + in_stack_0000003c._2_2_));
        }
        if (*(ushort *)(DAT_03002ab4 + 0x16) == uVar7) {
          if (uVar7 == 0) {
            FUN_02fec55a(in_stack_0000001c & 0xffff,(int)(short)(unaff_r4 + 4),(int)sStack00000032);
          }
          else {
            FUN_02fec55a();
          }
          sVar1 = *DAT_03002ab8;
          if (sVar1 == 5) {
            if (*(short *)(DAT_03002ab4 + 10) == 3) goto LAB_0300284c;
LAB_03002810:
            FUN_02fec55a(0x74,(int)(short)(in_stack_0000004c + unaff_r4),
                         (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + uVar7 * 0x18));
          }
          else {
            if (sVar1 == 4) {
              if (*(short *)(DAT_03002ab4 + 10) != 1) goto LAB_03002810;
LAB_0300284c:
              uVar5 = 0x75;
            }
            else {
              if ((sVar1 != 3) || (*(short *)(DAT_03002ab4 + 10) == 2)) goto LAB_0300284c;
              uVar5 = 0x74;
            }
            FUN_02fec55a(uVar5,(int)(short)(in_stack_0000004c + unaff_r4),
                         (int)(short)(in_stack_0000003c._2_2_ + unaff_r8 + uVar7 * 0x18));
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
      uVar7 = uVar7 + 1;
      unaff_r5 = *(int *)(unaff_r5 + 4);
    } while (uVar7 < 6);
    FUN_02ff008c(0x18d);
  }
  iVar3 = FUN_02ff00ec(0x178);
  if (iVar3 != 0) {
    in_stack_00000010 = FUN_02feb810(1);
    iVar3 = FUN_02ff00ec(0x1dc);
    puVar2 = DAT_03002ac0;
    if (iVar3 == 0) {
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


