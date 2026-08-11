/**
 * FUN_03008864 @ 0x03008864
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03008864(void)

{
  uint uVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_r4;
  undefined4 unaff_r6;
  ushort *unaff_r7;
  ushort unaff_r8;
  int unaff_r11;
  char in_ZR;
  undefined2 in_stack_00000008;
  
  if ((in_ZR == '\0') && (unaff_r4 == unaff_r11)) {
    unaff_r4 = DAT_030089b4;
  }
  FUN_02ff73f6(1);
  iVar5 = DAT_030089c4;
  puVar2 = DAT_030089c0;
  iVar4 = unaff_r4 - DAT_030089b8;
  if (unaff_r4 == DAT_030089b8) {
    iVar5 = FUN_02ff7414(1);
    if (iVar5 == 0) {
      if (*DAT_03008bfc != 2) {
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73f6(0x9c);
        FUN_02ff73b4(0x9d);
        return 1;
      }
      iVar5 = *DAT_03008c00;
      iVar4 = iVar5 + (uint)*unaff_r7 * 2;
      if (*(short *)(iVar4 + 0x14) == 0) {
        return unaff_r6;
      }
      *(ushort *)(iVar5 + 0x54) = *unaff_r7;
      *(uint *)(iVar5 + 0xc) = (uint)*(ushort *)(iVar4 + 0x14);
      FUN_03021672(0xac,1);
      return unaff_r6;
    }
    goto LAB_03008a56;
  }
  if (DAT_030089b8 <= unaff_r4) {
    if (iVar4 != 0x3fc0) {
      if (iVar4 < 0x3fc1) {
        if (iVar4 != 0x1c0) {
          if (iVar4 == 0x3c0) goto LAB_03008ba0;
          if (iVar4 == 0x7c0) goto LAB_03008b7a;
          if (iVar4 != 0xfc0) {
            return unaff_r6;
          }
        }
      }
      else {
        if (iVar4 == 0x7fc0) {
LAB_03008ba0:
          uVar1 = (*unaff_r7 / 5) * 5;
          uVar3 = (ushort)uVar1;
          *unaff_r7 = uVar3;
          if ((uVar1 & 0xffff) < 0x18) {
            uVar3 = uVar3 + 5;
          }
          else {
            uVar3 = 0x19;
          }
          *unaff_r7 = uVar3;
          FUN_02ff73b4(0x98);
          return unaff_r6;
        }
        if (iVar4 == 0xffffc0) {
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar4 == 0x1ffffc0) {
          in_stack_00000008 = 1;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,&stack0x00000008);
          return unaff_r6;
        }
        if (iVar4 != 0x100001c0) {
          return unaff_r6;
        }
      }
      iVar5 = FUN_02ff7414(1);
      if (iVar5 == 0) {
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
    uVar1 = (*unaff_r7 / 5) * 5;
    uVar3 = (ushort)uVar1;
    *unaff_r7 = uVar3;
    if ((uVar1 & 0xffff) < 5) {
      *unaff_r7 = unaff_r8;
    }
    else {
      *unaff_r7 = uVar3 - 5;
    }
    uVar6 = 0x98;
    goto LAB_03008b9a;
  }
  iVar4 = unaff_r4 - DAT_030089bc;
  if (unaff_r4 == DAT_030089bc) {
LAB_03008b3a:
    iVar4 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar4 == 1) && (*(char *)(iVar5 + 0x12) != '\0')) {
      *(char *)(iVar5 + 0x12) = *(char *)(iVar5 + 0x12) + -1;
      FUN_030147fc(0xff,0);
    }
    iVar4 = FUN_02fe6440(*puVar2,DAT_03008c08);
    if ((iVar4 == 1) && (*(char *)(iVar5 + 0x12) != '\0')) {
      *(char *)(iVar5 + 0x12) = *(char *)(iVar5 + 0x12) + -1;
      FUN_03021672(0xb6,0);
    }
  }
  else {
    if (DAT_030089bc <= unaff_r4) {
      if (iVar4 == 0x3e0) goto LAB_03008b7a;
      if (iVar4 == 0x7e0) goto LAB_03008ba0;
      if (iVar4 + DAT_03008bf4 == 0) goto LAB_03008aec;
      if (iVar4 + DAT_03008bf4 != 0x10) {
        return unaff_r6;
      }
      goto LAB_03008b3a;
    }
    iVar4 = unaff_r4 + -0x20000400;
    if (iVar4 == 0) goto LAB_03008ba0;
    if (iVar4 == 0x400) goto LAB_03008b7a;
    if (iVar4 == 0xc00) {
      iVar5 = FUN_02ff7414(1);
      if (iVar5 == 0) {
        FUN_03009ee4();
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73b4(0x93);
        return 1;
      }
      goto LAB_03008a56;
    }
    if (iVar4 + DAT_03008bec != 0) {
      return unaff_r6;
    }
LAB_03008aec:
    iVar4 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar4 == 1) && (*(byte *)(iVar5 + 0x12) < *(byte *)(iVar5 + 0x1e))) {
      *(byte *)(iVar5 + 0x12) = *(byte *)(iVar5 + 0x12) + 1;
      FUN_030147fc(0xff,0);
    }
    iVar4 = FUN_02fe6440(*puVar2,DAT_03008c08);
    if ((iVar4 == 1) && (*(byte *)(iVar5 + 0x12) < *(byte *)(iVar5 + 0x1e))) {
      *(byte *)(iVar5 + 0x12) = *(byte *)(iVar5 + 0x12) + 1;
      FUN_03021672(0xb6,0);
    }
  }
  uVar6 = 0x1a9;
LAB_03008b9a:
  FUN_02ff73b4(uVar6);
  return unaff_r6;
}


