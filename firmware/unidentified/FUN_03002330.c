/**
 * FUN_03002330 @ 0x03002330
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03002330(void)

{
  short sVar1;
  short sVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  undefined2 uVar12;
  undefined4 local_78;
  short sStack_74;
  short sStack_72;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint uStack_64;
  uint local_60;
  undefined4 local_5c;
  int local_58;
  uint local_54;
  undefined4 uStack_50;
  short sStack_4c;
  short sStack_4a;
  ushort auStack_48 [3];
  short sStack_42;
  undefined1 auStack_38 [4];
  short sStack_34;
  uint local_28;
  
  local_6c = 0xbd;
  iVar9 = *(int *)(DAT_030025ec + 0x1c);
  local_60 = (uint)*DAT_030025d8;
  *DAT_030025d8 = *DAT_030025dc;
  local_68 = FUN_02feb7ec(2);
  local_70 = FUN_02feb810(1);
  iVar5 = FUN_02ff00ec(0x26);
  if (((iVar5 != 0) || (iVar5 = FUN_02ff00a8(0x172), iVar5 != 0)) ||
     (iVar5 = FUN_02ff00a8(0x2f), iVar5 != 0)) {
    FUN_030021e4();
    puVar3 = DAT_030025d8;
    *DAT_030025d8 = *DAT_030025e8;
    iVar5 = FUN_02ff00ec(0x1dc);
    if (iVar5 == 0) {
      uVar12 = *DAT_030025f0;
    }
    else {
      uVar12 = 0x58;
    }
    FUN_02feb8bc(0,3,0x140,0x10,2,uVar12);
    *puVar3 = 0xffff;
    FUN_02ff008c(0x173);
    FUN_02ff008c(0x1a9);
    FUN_02febbb2(1);
  }
  FUN_02febbb2(0);
  iVar5 = FUN_02ff00a8(0x173);
  if (iVar5 != 0) {
    *DAT_030025d8 = *DAT_030025e8;
    iVar5 = FUN_02ff00ec(0x1dc);
    if (iVar5 != 0) {
      FUN_02fec0f6(0x7a,0,0,0,0x14);
      FUN_02feb8bc(0,3,0x140,0x10,2,0x58);
      FUN_02febbb2(1);
    }
    local_78 = 0x93;
    FUN_02fec2ac(0x7a,0x85,0x17,0x85,0x17,0xbd);
    FUN_02febdc2(0x8c,auStack_48);
    FUN_02febdc2(0x6e,auStack_38);
    uVar11 = 0;
    local_28 = (uint)*(ushort *)(DAT_030025ec + 0x1a);
    local_58 = 0xa1;
    local_54 = 0x89;
    local_5c = 0x8b;
    do {
      if (local_28 <= uVar11) break;
      sVar2 = (short)uVar11;
      uStack_50 = CONCAT22(sVar2 * 0x18 + 0x17,(short)local_58);
      sStack_4c = (short)local_58 + auStack_48[0];
      sStack_4a = sVar2 * 0x18 + 0x2f;
      if ((*(ushort *)(DAT_030025ec + 0x16) == uVar11) && (iVar5 = FUN_02ff00ec(0x1dc), iVar5 == 0))
      {
        if (uVar11 == 0) {
          FUN_02fec55a(local_54 & 0xffff,0x89,(int)uStack_50._2_2_);
        }
        else {
          uVar8 = local_5c;
          if (uVar11 != 5) {
            uVar8 = 0x8a;
          }
          FUN_02fec55a(uVar8,0x89,(int)uStack_50._2_2_);
        }
        *DAT_030025d8 = *DAT_030025e8;
        uVar7 = FUN_02fea94e(iVar9 + 0xc);
        *(int *)(DAT_030025f0 + 2) = iVar9 + 0xc;
        if (auStack_48[0] < uVar7) {
          uStack_64 = uStack_50;
          local_78 = CONCAT22(uStack_50._2_2_ + 5,(short)uStack_50);
          sStack_74 = sStack_4c;
          sStack_72 = uStack_50._2_2_ + 0x14;
          FUN_02feb550(&local_78,uStack_50,0x100005,0x8c,iVar9 + 0xc,0x1e);
          FUN_02ff008c(0x178);
        }
        else {
          FUN_02ff00ce(0x178);
        }
      }
      else {
        *DAT_030025d8 = *DAT_030025dc;
      }
      iVar5 = DAT_030025ec;
      if ((*(ushort *)(DAT_030025ec + 0x16) == uVar11) && (iVar6 = FUN_02ff00ec(0x1dc), iVar6 == 0))
      {
        sVar1 = *DAT_030025e4;
        if (sVar1 != 5) {
          if (sVar1 == 4) {
            if (*(short *)(iVar5 + 10) != 1) goto LAB_03002606;
          }
          else if ((sVar1 == 3) && (*(short *)(iVar5 + 10) != 2)) {
LAB_03002606:
            iVar6 = (int)(short)(sStack_42 + sVar2 * 0x18 + 0x1c);
            iVar5 = (int)(short)(sStack_34 + 0x85);
            uVar8 = 0x74;
            goto LAB_03002634;
          }
LAB_0300261e:
          iVar6 = (int)(short)(sStack_42 + sVar2 * 0x18 + 0x1c);
          iVar5 = (int)(short)(sStack_34 + 0x85);
          uVar8 = 0x75;
          goto LAB_03002634;
        }
        if (*(short *)(iVar5 + 10) == 3) goto LAB_0300261e;
        FUN_02fec55a(0x74,(int)(short)(sStack_34 + 0x85),
                     (int)(short)(sStack_42 + sVar2 * 0x18 + 0x1c));
      }
      else {
        sVar1 = *DAT_030025e4;
        if (sVar1 == 5) {
          if (*(short *)(iVar5 + 10) != 3) goto LAB_0300272c;
        }
        else if (sVar1 == 4) {
          if (*(short *)(iVar5 + 10) != 1) goto LAB_0300272c;
        }
        else if ((sVar1 == 3) && (*(short *)(iVar5 + 10) != 2)) {
LAB_0300272c:
          iVar6 = (int)(short)(sStack_42 + sVar2 * 0x18 + 0x1c);
          iVar5 = (int)(short)(sStack_34 + 0x85);
          uVar8 = 0x6e;
          goto LAB_03002634;
        }
        iVar6 = (int)(short)(sStack_42 + sVar2 * 0x18 + 0x1c);
        iVar5 = (int)(short)(sStack_34 + 0x85);
        uVar8 = 0x6f;
LAB_03002634:
        FUN_02fec55a(uVar8,iVar5,iVar6);
      }
      sStack_4a = uStack_50._2_2_;
      uStack_50 = CONCAT22(uStack_50._2_2_ + 5,(undefined2)uStack_50);
      sStack_4a = sStack_4a + 0x14;
      FUN_02feacc0(&uStack_50,&uStack_50,iVar9 + 0xc,0);
      iVar9 = *(int *)(iVar9 + 4);
      uVar11 = uVar11 + 1 & 0xffff;
    } while (uVar11 < 6);
    FUN_02ff008c(0x18d);
  }
  iVar5 = FUN_02ff00a8(0x174);
  if (iVar5 != 0) {
    FUN_02ff008c(0x3e);
    FUN_02febdc2(0x8c,auStack_48);
    FUN_02febdc2(0x6e,auStack_38);
    local_5c = 0xa1;
    uVar10 = 0;
    local_58 = (int)(short)((short)local_6c + 1);
    uStack_64 = 0x89;
    local_6c = 0x8b;
    do {
      if (*(ushort *)(DAT_03002ab4 + 0x16) == uVar10 || *(ushort *)(DAT_03002ab4 + 0x18) == uVar10)
      {
        sVar2 = uVar10 * 0x18 + 0x17;
        sStack_4c = (short)local_5c + auStack_48[0];
        sStack_4a = uVar10 * 0x18 + 0x2f;
        uStack_50 = CONCAT22(sVar2,(short)local_5c);
        if (*(ushort *)(DAT_03002ab4 + 0x18) == uVar10) {
          local_78 = 0x19;
          FUN_02fec2ac(0x7a,0x85,(int)sVar2,0x85,(int)sVar2,local_58);
          sVar2 = *DAT_03002ab8;
          if (sVar2 == 5) {
            if (*(short *)(DAT_03002ab4 + 10) == 3) goto LAB_0300279c;
LAB_0300276c:
            sVar2 = *(short *)(DAT_03002ab4 + 0x18);
            uVar8 = 0x6e;
          }
          else {
            if (sVar2 == 4) {
              if (*(short *)(DAT_03002ab4 + 10) == 1) goto LAB_0300279c;
              goto LAB_0300276c;
            }
            if ((sVar2 == 3) && (*(short *)(DAT_03002ab4 + 10) != 2)) goto LAB_0300276c;
LAB_0300279c:
            sVar2 = *(short *)(DAT_03002ab4 + 0x18);
            uVar8 = 0x6f;
          }
          FUN_02fec55a(uVar8,(int)(short)(sStack_34 + 0x85),
                       (int)(short)(sVar2 * 0x18 + 0x1c + sStack_42));
        }
        if (*(ushort *)(DAT_03002ab4 + 0x16) == uVar10) {
          if (uVar10 == 0) {
            FUN_02fec55a(uStack_64 & 0xffff,0x89,(int)uStack_50._2_2_);
          }
          else {
            uVar8 = local_6c;
            if (uVar10 != 5) {
              uVar8 = 0x8a;
            }
            FUN_02fec55a(uVar8,0x89,(int)uStack_50._2_2_);
          }
          sVar2 = *DAT_03002ab8;
          if (sVar2 == 5) {
            if (*(short *)(DAT_03002ab4 + 10) == 3) goto LAB_0300284c;
LAB_03002810:
            FUN_02fec55a(0x74,(int)(short)(sStack_34 + 0x85),
                         (int)(short)(sStack_42 + uVar10 * 0x18 + 0x1c));
          }
          else {
            if (sVar2 == 4) {
              if (*(short *)(DAT_03002ab4 + 10) != 1) goto LAB_03002810;
LAB_0300284c:
              uVar8 = 0x75;
            }
            else {
              if ((sVar2 != 3) || (*(short *)(DAT_03002ab4 + 10) == 2)) goto LAB_0300284c;
              uVar8 = 0x74;
            }
            FUN_02fec55a(uVar8,(int)(short)(sStack_34 + 0x85),
                         (int)(short)(sStack_42 + uVar10 * 0x18 + 0x1c));
          }
          *DAT_03002ac0 = *DAT_03002abc;
          uVar11 = FUN_02fea94e(iVar9 + 0xc);
          *(int *)(DAT_03002ac4 + 4) = iVar9 + 0xc;
          if (auStack_48[0] < uVar11) {
            local_54 = uStack_50;
            local_78 = CONCAT22(uStack_50._2_2_ + 5,(short)uStack_50);
            sStack_74 = sStack_4c;
            sStack_72 = uStack_50._2_2_ + 0x14;
            FUN_02feb550(&local_78,uStack_50,0x100005,0x8c,iVar9 + 0xc,0x1e);
            FUN_02ff008c(0x178);
          }
          else {
            FUN_02ff00ce(0x178);
          }
        }
        else {
          *DAT_03002ac0 = *DAT_03002ac8;
        }
        sStack_4a = uStack_50._2_2_;
        uStack_50 = CONCAT22(uStack_50._2_2_ + 5,(undefined2)uStack_50);
        sStack_4a = sStack_4a + 0x14;
        FUN_02feacc0(&uStack_50,&uStack_50,iVar9 + 0xc,0);
      }
      uVar10 = uVar10 + 1;
      iVar9 = *(int *)(iVar9 + 4);
    } while (uVar10 < 6);
    FUN_02ff008c(0x18d);
  }
  iVar5 = FUN_02ff00ec(0x178);
  if (iVar5 != 0) {
    local_70 = FUN_02feb810(1);
    iVar5 = FUN_02ff00ec(0x1dc);
    puVar4 = DAT_03002ac0;
    if (iVar5 == 0) {
      *DAT_03002ac0 = *DAT_03002abc;
      FUN_02feb428(*(undefined4 *)(DAT_03002ac4 + 4));
      FUN_02ff008c(0x3e);
      *puVar4 = *DAT_03002ac8;
    }
    FUN_02feb810(local_70);
  }
  FUN_02feb810(local_70);
  *DAT_03002ac0 = (short)local_60;
  FUN_02feb7ec(local_68);
  return;
}


