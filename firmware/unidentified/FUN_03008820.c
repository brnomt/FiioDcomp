/**
 * FUN_03008820 @ 0x03008820
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03008820(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int unaff_r4;
  int unaff_r5;
  undefined4 unaff_r6;
  ushort *unaff_r7;
  ushort unaff_r8;
  int unaff_r9;
  int unaff_r10;
  undefined2 in_stack_00000008;
  
  iVar3 = FUN_02ff0b76();
  iVar6 = DAT_0300899c;
  iVar5 = unaff_r4;
  if (iVar3 == 0) {
    iVar3 = FUN_02ff0b76(0xa0,0x7d,0x140,0xaa);
    if (iVar3 == 0) {
      iVar6 = FUN_02ff0b76(0,0x1b,0x140,0x7d);
      if (iVar6 == 0) {
        iVar6 = FUN_02ff0b76(0,0,0x3c,0x32);
        iVar5 = DAT_03008bf0;
        if (iVar6 == 0) {
          iVar5 = 0;
        }
      }
      else {
        iVar6 = FUN_02ff0b76(0,0x1b,0x140,0x33);
        if (iVar6 != 0) {
          unaff_r5 = 0;
        }
        iVar6 = FUN_02ff0b76(0,0x33,0x140,0x4b);
        if (iVar6 != 0) {
          unaff_r5 = 1;
        }
        iVar6 = FUN_02ff0b76(0,0x4b,0x140,99);
        if (iVar6 != 0) {
          unaff_r5 = 2;
        }
        iVar6 = FUN_02ff0b76(0,99,0x140,0x7b);
        if (iVar6 != 0) {
          unaff_r5 = 3;
        }
        iVar6 = FUN_02ff0b76(0,0x7b,0x140,0x93);
        if (iVar6 != 0) {
          unaff_r5 = 4;
        }
        if ((iVar6 != 0 || unaff_r5 != 0xff) &&
           (uVar4 = unaff_r5 + (*unaff_r7 / 6) * 6, *unaff_r7 = (ushort)uVar4,
           (uVar4 & 0xffff) < 0x1e)) {
          FUN_02ff73b4(0x98);
          FUN_02ff73b4(0xce);
          FUN_0300862e();
          FUN_02ff4124();
          FUN_02ff06bc();
          iVar5 = DAT_030089b8;
        }
      }
    }
    else {
      iVar5 = DAT_030089ac;
      if (((unaff_r4 != unaff_r9) && (iVar5 = DAT_030089b0, unaff_r4 != unaff_r10)) &&
         (iVar5 = unaff_r4, unaff_r4 == iVar6)) {
        iVar5 = DAT_030089b4;
      }
    }
  }
  else {
    iVar5 = DAT_030089a0;
    if (((unaff_r4 != unaff_r9) && (iVar5 = DAT_030089a4, unaff_r4 != unaff_r10)) &&
       (iVar5 = unaff_r4, unaff_r4 == DAT_0300899c)) {
      iVar5 = DAT_030089a8;
    }
  }
  FUN_02ff73f6(1);
  iVar6 = DAT_030089c4;
  puVar1 = DAT_030089c0;
  iVar3 = iVar5 - DAT_030089b8;
  if (iVar5 == DAT_030089b8) {
    iVar6 = FUN_02ff7414(1);
    if (iVar6 == 0) {
      if (*DAT_03008bfc != 2) {
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73f6(0x9c);
        FUN_02ff73b4(0x9d);
        return 1;
      }
      iVar6 = *DAT_03008c00;
      iVar5 = iVar6 + (uint)*unaff_r7 * 2;
      if (*(short *)(iVar5 + 0x14) == 0) {
        return unaff_r6;
      }
      *(ushort *)(iVar6 + 0x54) = *unaff_r7;
      *(uint *)(iVar6 + 0xc) = (uint)*(ushort *)(iVar5 + 0x14);
      FUN_03021672(0xac,1);
      return unaff_r6;
    }
    goto LAB_03008a56;
  }
  if (DAT_030089b8 <= iVar5) {
    if (iVar3 != 0x3fc0) {
      if (iVar3 < 0x3fc1) {
        if (iVar3 != 0x1c0) {
          if (iVar3 == 0x3c0) goto LAB_03008ba0;
          if (iVar3 == 0x7c0) goto LAB_03008b7a;
          if (iVar3 != 0xfc0) {
            return unaff_r6;
          }
        }
      }
      else {
        if (iVar3 == 0x7fc0) {
LAB_03008ba0:
          uVar4 = (*unaff_r7 / 5) * 5;
          uVar2 = (ushort)uVar4;
          *unaff_r7 = uVar2;
          if ((uVar4 & 0xffff) < 0x18) {
            uVar2 = uVar2 + 5;
          }
          else {
            uVar2 = 0x19;
          }
          *unaff_r7 = uVar2;
          FUN_02ff73b4(0x98);
          return unaff_r6;
        }
        if (iVar3 == 0xffffc0) {
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar3 == 0x1ffffc0) {
          in_stack_00000008 = 1;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar3 != 0x100001c0) {
          return unaff_r6;
        }
      }
      iVar6 = FUN_02ff7414(1);
      if (iVar6 == 0) {
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
    uVar4 = (*unaff_r7 / 5) * 5;
    uVar2 = (ushort)uVar4;
    *unaff_r7 = uVar2;
    if ((uVar4 & 0xffff) < 5) {
      *unaff_r7 = unaff_r8;
    }
    else {
      *unaff_r7 = uVar2 - 5;
    }
    uVar7 = 0x98;
    goto LAB_03008b9a;
  }
  iVar3 = iVar5 - DAT_030089bc;
  if (iVar5 == DAT_030089bc) {
LAB_03008b3a:
    iVar5 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar5 == 1) && (*(char *)(iVar6 + 0x12) != '\0')) {
      *(char *)(iVar6 + 0x12) = *(char *)(iVar6 + 0x12) + -1;
      FUN_030147fc(0xff,0);
    }
    iVar5 = FUN_02fe6440(*puVar1,DAT_03008c08);
    if ((iVar5 == 1) && (*(char *)(iVar6 + 0x12) != '\0')) {
      *(char *)(iVar6 + 0x12) = *(char *)(iVar6 + 0x12) + -1;
      FUN_03021672(0xb6,0);
    }
  }
  else {
    if (DAT_030089bc <= iVar5) {
      if (iVar3 == 0x3e0) goto LAB_03008b7a;
      if (iVar3 == 0x7e0) goto LAB_03008ba0;
      if (iVar3 + DAT_03008bf4 == 0) goto LAB_03008aec;
      if (iVar3 + DAT_03008bf4 != 0x10) {
        return unaff_r6;
      }
      goto LAB_03008b3a;
    }
    iVar5 = iVar5 + -0x20000400;
    if (iVar5 == 0) goto LAB_03008ba0;
    if (iVar5 == 0x400) goto LAB_03008b7a;
    if (iVar5 == 0xc00) {
      iVar6 = FUN_02ff7414(1);
      if (iVar6 == 0) {
        FUN_03009ee4();
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73b4(0x93);
        return 1;
      }
      goto LAB_03008a56;
    }
    if (iVar5 + DAT_03008bec != 0) {
      return unaff_r6;
    }
LAB_03008aec:
    iVar5 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar5 == 1) && (*(byte *)(iVar6 + 0x12) < *(byte *)(iVar6 + 0x1e))) {
      *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) + 1;
      FUN_030147fc(0xff,0);
    }
    iVar5 = FUN_02fe6440(*puVar1,DAT_03008c08);
    if ((iVar5 == 1) && (*(byte *)(iVar6 + 0x12) < *(byte *)(iVar6 + 0x1e))) {
      *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) + 1;
      FUN_03021672(0xb6,0);
    }
  }
  uVar7 = 0x1a9;
LAB_03008b9a:
  FUN_02ff73b4(uVar7);
  return unaff_r6;
}


