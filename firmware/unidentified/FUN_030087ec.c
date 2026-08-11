/**
 * FUN_030087ec @ 0x030087ec
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030087ec(int param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int unaff_r5;
  undefined4 unaff_r6;
  ushort *unaff_r7;
  undefined2 in_stack_00000008;
  
  iVar6 = DAT_03008998;
  iVar8 = DAT_03008994;
  iVar7 = param_1;
  if (param_1 == DAT_03008994 || param_1 == DAT_03008998) {
    iVar3 = FUN_02ff73d0(1);
    if (iVar3 == 0) {
      iVar4 = FUN_02ff0b76(0,0x7d,0xa0,0xaa);
      iVar3 = DAT_0300899c;
      if (iVar4 == 0) {
        iVar4 = FUN_02ff0b76(0xa0,0x7d,0x140,0xaa);
        if (iVar4 == 0) {
          iVar8 = FUN_02ff0b76(0,0x1b,0x140,0x7d);
          if (iVar8 == 0) {
            iVar8 = FUN_02ff0b76(0,0,0x3c,0x32);
            iVar7 = DAT_03008bf0;
            if (iVar8 == 0) {
              iVar7 = 0;
            }
          }
          else {
            iVar8 = FUN_02ff0b76(0,0x1b,0x140,0x33);
            if (iVar8 != 0) {
              unaff_r5 = 0;
            }
            iVar8 = FUN_02ff0b76(0,0x33,0x140,0x4b);
            if (iVar8 != 0) {
              unaff_r5 = 1;
            }
            iVar8 = FUN_02ff0b76(0,0x4b,0x140,99);
            if (iVar8 != 0) {
              unaff_r5 = 2;
            }
            iVar8 = FUN_02ff0b76(0,99,0x140,0x7b);
            if (iVar8 != 0) {
              unaff_r5 = 3;
            }
            iVar8 = FUN_02ff0b76(0,0x7b,0x140,0x93);
            if (iVar8 != 0) {
              unaff_r5 = 4;
            }
            if ((iVar8 != 0 || unaff_r5 != 0xff) &&
               (uVar5 = unaff_r5 + (*unaff_r7 / 6) * 6, *unaff_r7 = (ushort)uVar5,
               (uVar5 & 0xffff) < 0x1e)) {
              FUN_02ff73b4(0x98);
              FUN_02ff73b4(0xce);
              FUN_0300862e();
              FUN_02ff4124();
              FUN_02ff06bc();
              iVar7 = DAT_030089b8;
            }
          }
        }
        else {
          iVar7 = DAT_030089ac;
          if (((param_1 != iVar8) && (iVar7 = DAT_030089b0, param_1 != iVar6)) &&
             (iVar7 = param_1, param_1 == iVar3)) {
            iVar7 = DAT_030089b4;
          }
        }
      }
      else {
        iVar7 = DAT_030089a0;
        if (((param_1 != iVar8) && (iVar7 = DAT_030089a4, param_1 != iVar6)) &&
           (iVar7 = param_1, param_1 == DAT_0300899c)) {
          iVar7 = DAT_030089a8;
        }
      }
    }
    else {
      FUN_02ff73b4(0x2f);
      iVar7 = 0;
    }
  }
  FUN_02ff73f6(1);
  iVar8 = DAT_030089c4;
  puVar1 = DAT_030089c0;
  iVar6 = iVar7 - DAT_030089b8;
  if (iVar7 == DAT_030089b8) {
    iVar8 = FUN_02ff7414(1);
    if (iVar8 == 0) {
      if (*DAT_03008bfc != 2) {
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73f6(0x9c);
        FUN_02ff73b4(0x9d);
        return 1;
      }
      iVar8 = *DAT_03008c00;
      iVar6 = iVar8 + (uint)*unaff_r7 * 2;
      if (*(short *)(iVar6 + 0x14) == 0) {
        return unaff_r6;
      }
      *(ushort *)(iVar8 + 0x54) = *unaff_r7;
      *(uint *)(iVar8 + 0xc) = (uint)*(ushort *)(iVar6 + 0x14);
      FUN_03021672(0xac,1);
      return unaff_r6;
    }
    goto LAB_03008a56;
  }
  if (DAT_030089b8 <= iVar7) {
    if (iVar6 != 0x3fc0) {
      if (iVar6 < 0x3fc1) {
        if (iVar6 != 0x1c0) {
          if (iVar6 == 0x3c0) goto LAB_03008ba0;
          if (iVar6 == 0x7c0) goto LAB_03008b7a;
          if (iVar6 != 0xfc0) {
            return unaff_r6;
          }
        }
      }
      else {
        if (iVar6 == 0x7fc0) {
LAB_03008ba0:
          uVar5 = (*unaff_r7 / 5) * 5;
          uVar2 = (ushort)uVar5;
          *unaff_r7 = uVar2;
          if ((uVar5 & 0xffff) < 0x18) {
            uVar2 = uVar2 + 5;
          }
          else {
            uVar2 = 0x19;
          }
          *unaff_r7 = uVar2;
          FUN_02ff73b4(0x98);
          return unaff_r6;
        }
        if (iVar6 == 0xffffc0) {
          in_stack_00000008 = 0;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar6 == 0x1ffffc0) {
          in_stack_00000008 = 1;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar6 != 0x100001c0) {
          return unaff_r6;
        }
      }
      iVar8 = FUN_02ff7414(1);
      if (iVar8 == 0) {
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
    uVar5 = (*unaff_r7 / 5) * 5;
    uVar2 = (ushort)uVar5;
    *unaff_r7 = uVar2;
    if ((uVar5 & 0xffff) < 5) {
      *unaff_r7 = 0;
    }
    else {
      *unaff_r7 = uVar2 - 5;
    }
    uVar9 = 0x98;
    goto LAB_03008b9a;
  }
  iVar6 = iVar7 - DAT_030089bc;
  if (iVar7 == DAT_030089bc) {
LAB_03008b3a:
    iVar6 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar6 == 1) && (*(char *)(iVar8 + 0x12) != '\0')) {
      *(char *)(iVar8 + 0x12) = *(char *)(iVar8 + 0x12) + -1;
      FUN_030147fc(0xff,0);
    }
    iVar6 = FUN_02fe6440(*puVar1,DAT_03008c08);
    if ((iVar6 == 1) && (*(char *)(iVar8 + 0x12) != '\0')) {
      *(char *)(iVar8 + 0x12) = *(char *)(iVar8 + 0x12) + -1;
      FUN_03021672(0xb6,0);
    }
  }
  else {
    if (DAT_030089bc <= iVar7) {
      if (iVar6 == 0x3e0) goto LAB_03008b7a;
      if (iVar6 == 0x7e0) goto LAB_03008ba0;
      if (iVar6 + DAT_03008bf4 == 0) goto LAB_03008aec;
      if (iVar6 + DAT_03008bf4 != 0x10) {
        return unaff_r6;
      }
      goto LAB_03008b3a;
    }
    iVar7 = iVar7 + -0x20000400;
    if (iVar7 == 0) goto LAB_03008ba0;
    if (iVar7 == 0x400) goto LAB_03008b7a;
    if (iVar7 == 0xc00) {
      iVar8 = FUN_02ff7414(1);
      if (iVar8 == 0) {
        FUN_03009ee4();
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73b4(0x93);
        return 1;
      }
      goto LAB_03008a56;
    }
    if (iVar7 + DAT_03008bec != 0) {
      return unaff_r6;
    }
LAB_03008aec:
    iVar6 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar6 == 1) && (*(byte *)(iVar8 + 0x12) < *(byte *)(iVar8 + 0x1e))) {
      *(byte *)(iVar8 + 0x12) = *(byte *)(iVar8 + 0x12) + 1;
      FUN_030147fc(0xff,0);
    }
    iVar6 = FUN_02fe6440(*puVar1,DAT_03008c08);
    if ((iVar6 == 1) && (*(byte *)(iVar8 + 0x12) < *(byte *)(iVar8 + 0x1e))) {
      *(byte *)(iVar8 + 0x12) = *(byte *)(iVar8 + 0x12) + 1;
      FUN_03021672(0xb6,0);
    }
  }
  uVar9 = 0x1a9;
LAB_03008b9a:
  FUN_02ff73b4(uVar9);
  return unaff_r6;
}


