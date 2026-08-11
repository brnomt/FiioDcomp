/**
 * FUN_030087e4 @ 0x030087e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030087e4(undefined2 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 unaff_r6;
  ushort *unaff_r7;
  undefined2 in_stack_00000008;
  
  iVar11 = 0xff;
  *param_2 = param_1;
  iVar4 = FUN_02ff0ea6();
  iVar1 = DAT_03008998;
  iVar8 = DAT_03008994;
  iVar9 = iVar4;
  if (iVar4 == DAT_03008994 || iVar4 == DAT_03008998) {
    iVar5 = FUN_02ff73d0(1);
    if (iVar5 == 0) {
      iVar6 = FUN_02ff0b76(0,0x7d,0xa0,0xaa);
      iVar5 = DAT_0300899c;
      if (iVar6 == 0) {
        iVar6 = FUN_02ff0b76(0xa0,0x7d,0x140,0xaa);
        if (iVar6 == 0) {
          iVar8 = FUN_02ff0b76(0,0x1b,0x140,0x7d);
          if (iVar8 == 0) {
            iVar11 = FUN_02ff0b76(0,0,0x3c,0x32);
            iVar9 = DAT_03008bf0;
            if (iVar11 == 0) {
              iVar9 = 0;
            }
          }
          else {
            iVar8 = FUN_02ff0b76(0,0x1b,0x140,0x33);
            if (iVar8 != 0) {
              iVar11 = 0;
            }
            iVar8 = FUN_02ff0b76(0,0x33,0x140,0x4b);
            if (iVar8 != 0) {
              iVar11 = 1;
            }
            iVar8 = FUN_02ff0b76(0,0x4b,0x140,99);
            if (iVar8 != 0) {
              iVar11 = 2;
            }
            iVar8 = FUN_02ff0b76(0,99,0x140,0x7b);
            if (iVar8 != 0) {
              iVar11 = 3;
            }
            iVar8 = FUN_02ff0b76(0,0x7b,0x140,0x93);
            if (iVar8 != 0) {
              iVar11 = 4;
            }
            if ((iVar8 != 0 || iVar11 != 0xff) &&
               (uVar7 = iVar11 + (*unaff_r7 / 6) * 6, *unaff_r7 = (ushort)uVar7,
               (uVar7 & 0xffff) < 0x1e)) {
              FUN_02ff73b4(0x98);
              FUN_02ff73b4(0xce);
              FUN_0300862e();
              FUN_02ff4124();
              FUN_02ff06bc();
              iVar9 = DAT_030089b8;
            }
          }
        }
        else {
          iVar9 = DAT_030089ac;
          if (((iVar4 != iVar8) && (iVar9 = DAT_030089b0, iVar4 != iVar1)) &&
             (iVar9 = iVar4, iVar4 == iVar5)) {
            iVar9 = DAT_030089b4;
          }
        }
      }
      else {
        iVar9 = DAT_030089a0;
        if (((iVar4 != iVar8) && (iVar9 = DAT_030089a4, iVar4 != iVar1)) &&
           (iVar9 = iVar4, iVar4 == DAT_0300899c)) {
          iVar9 = DAT_030089a8;
        }
      }
    }
    else {
      FUN_02ff73b4(0x2f);
      iVar9 = 0;
    }
  }
  FUN_02ff73f6(1);
  iVar11 = DAT_030089c4;
  puVar2 = DAT_030089c0;
  iVar8 = iVar9 - DAT_030089b8;
  if (iVar9 == DAT_030089b8) {
    iVar11 = FUN_02ff7414(1);
    if (iVar11 == 0) {
      if (*DAT_03008bfc != 2) {
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73f6(0x9c);
        FUN_02ff73b4(0x9d);
        return 1;
      }
      iVar11 = *DAT_03008c00;
      iVar8 = iVar11 + (uint)*unaff_r7 * 2;
      if (*(short *)(iVar8 + 0x14) == 0) {
        return unaff_r6;
      }
      *(ushort *)(iVar11 + 0x54) = *unaff_r7;
      *(uint *)(iVar11 + 0xc) = (uint)*(ushort *)(iVar8 + 0x14);
      FUN_03021672(0xac,1);
      return unaff_r6;
    }
    goto LAB_03008a56;
  }
  if (DAT_030089b8 <= iVar9) {
    if (iVar8 != 0x3fc0) {
      if (iVar8 < 0x3fc1) {
        if (iVar8 != 0x1c0) {
          if (iVar8 == 0x3c0) goto LAB_03008ba0;
          if (iVar8 == 0x7c0) goto LAB_03008b7a;
          if (iVar8 != 0xfc0) {
            return unaff_r6;
          }
        }
      }
      else {
        if (iVar8 == 0x7fc0) {
LAB_03008ba0:
          uVar7 = (*unaff_r7 / 5) * 5;
          uVar3 = (ushort)uVar7;
          *unaff_r7 = uVar3;
          if ((uVar7 & 0xffff) < 0x18) {
            uVar3 = uVar3 + 5;
          }
          else {
            uVar3 = 0x19;
          }
          *unaff_r7 = uVar3;
          FUN_02ff73b4(0x98);
          return unaff_r6;
        }
        if (iVar8 == 0xffffc0) {
          in_stack_00000008 = 0;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar8 == 0x1ffffc0) {
          in_stack_00000008 = 1;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar8 != 0x100001c0) {
          return unaff_r6;
        }
      }
      iVar11 = FUN_02ff7414(1);
      if (iVar11 == 0) {
        FUN_03009ee4();
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73b4(0xa1);
        return 1;
      }
LAB_03008a56:
      FUN_02ff73f6(1);
      return unaff_r6;
    }
LAB_03008b7a:
    uVar7 = (*unaff_r7 / 5) * 5;
    uVar3 = (ushort)uVar7;
    *unaff_r7 = uVar3;
    if ((uVar7 & 0xffff) < 5) {
      *unaff_r7 = 0;
    }
    else {
      *unaff_r7 = uVar3 - 5;
    }
    uVar10 = 0x98;
    goto LAB_03008b9a;
  }
  iVar8 = iVar9 - DAT_030089bc;
  if (iVar9 == DAT_030089bc) {
LAB_03008b3a:
    iVar8 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar8 == 1) && (*(char *)(iVar11 + 0x12) != '\0')) {
      *(char *)(iVar11 + 0x12) = *(char *)(iVar11 + 0x12) + -1;
      FUN_030147fc(0xff,0);
    }
    iVar8 = FUN_02fe6440(*puVar2,DAT_03008c08);
    if ((iVar8 == 1) && (*(char *)(iVar11 + 0x12) != '\0')) {
      *(char *)(iVar11 + 0x12) = *(char *)(iVar11 + 0x12) + -1;
      FUN_03021672(0xb6,0);
    }
  }
  else {
    if (DAT_030089bc <= iVar9) {
      if (iVar8 == 0x3e0) goto LAB_03008b7a;
      if (iVar8 == 0x7e0) goto LAB_03008ba0;
      if (iVar8 + DAT_03008bf4 == 0) goto LAB_03008aec;
      if (iVar8 + DAT_03008bf4 != 0x10) {
        return unaff_r6;
      }
      goto LAB_03008b3a;
    }
    iVar9 = iVar9 + -0x20000400;
    if (iVar9 == 0) goto LAB_03008ba0;
    if (iVar9 == 0x400) goto LAB_03008b7a;
    if (iVar9 == 0xc00) {
      iVar11 = FUN_02ff7414(1);
      if (iVar11 == 0) {
        FUN_03009ee4();
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73b4(0x93);
        return 1;
      }
      goto LAB_03008a56;
    }
    if (iVar9 + DAT_03008bec != 0) {
      return unaff_r6;
    }
LAB_03008aec:
    iVar8 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar8 == 1) && (*(byte *)(iVar11 + 0x12) < *(byte *)(iVar11 + 0x1e))) {
      *(byte *)(iVar11 + 0x12) = *(byte *)(iVar11 + 0x12) + 1;
      FUN_030147fc(0xff,0);
    }
    iVar8 = FUN_02fe6440(*puVar2,DAT_03008c08);
    if ((iVar8 == 1) && (*(byte *)(iVar11 + 0x12) < *(byte *)(iVar11 + 0x1e))) {
      *(byte *)(iVar11 + 0x12) = *(byte *)(iVar11 + 0x12) + 1;
      FUN_03021672(0xb6,0);
    }
  }
  uVar10 = 0x1a9;
LAB_03008b9a:
  FUN_02ff73b4(uVar10);
  return unaff_r6;
}


