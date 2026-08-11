/**
 * FUN_030087d6 @ 0x030087d6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030087d6(void)

{
  ushort *puVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  undefined2 auStack_48 [18];
  
  puVar1 = DAT_0300897c;
  iVar12 = 0xff;
  *DAT_03008990 = *DAT_0300897c;
  iVar5 = FUN_02ff0ea6();
  iVar2 = DAT_03008998;
  iVar9 = DAT_03008994;
  iVar10 = iVar5;
  if (iVar5 == DAT_03008994 || iVar5 == DAT_03008998) {
    iVar6 = FUN_02ff73d0(1);
    if (iVar6 == 0) {
      iVar7 = FUN_02ff0b76(0,0x7d,0xa0,0xaa,0);
      iVar6 = DAT_0300899c;
      if (iVar7 == 0) {
        iVar7 = FUN_02ff0b76(0xa0,0x7d,0x140,0xaa,0);
        if (iVar7 == 0) {
          iVar9 = FUN_02ff0b76(0,0x1b,0x140,0x7d,0);
          if (iVar9 == 0) {
            iVar12 = FUN_02ff0b76(0,0,0x3c,0x32,0);
            iVar10 = DAT_03008bf0;
            if (iVar12 == 0) {
              iVar10 = 0;
            }
          }
          else {
            iVar9 = FUN_02ff0b76(0,0x1b,0x140,0x33,0);
            if (iVar9 != 0) {
              iVar12 = 0;
            }
            iVar9 = FUN_02ff0b76(0,0x33,0x140,0x4b,0);
            if (iVar9 != 0) {
              iVar12 = 1;
            }
            iVar9 = FUN_02ff0b76(0,0x4b,0x140,99,0);
            if (iVar9 != 0) {
              iVar12 = 2;
            }
            iVar9 = FUN_02ff0b76(0,99,0x140,0x7b,0);
            if (iVar9 != 0) {
              iVar12 = 3;
            }
            iVar9 = FUN_02ff0b76(0,0x7b,0x140,0x93,0);
            if (iVar9 != 0) {
              iVar12 = 4;
            }
            if ((iVar9 != 0 || iVar12 != 0xff) &&
               (uVar8 = iVar12 + (*puVar1 / 6) * 6, *puVar1 = (ushort)uVar8, (uVar8 & 0xffff) < 0x1e
               )) {
              FUN_02ff73b4(0x98);
              FUN_02ff73b4(0xce);
              FUN_0300862e();
              FUN_02ff4124();
              FUN_02ff06bc();
              iVar10 = DAT_030089b8;
            }
          }
        }
        else {
          iVar10 = DAT_030089ac;
          if (((iVar5 != iVar9) && (iVar10 = DAT_030089b0, iVar5 != iVar2)) &&
             (iVar10 = iVar5, iVar5 == iVar6)) {
            iVar10 = DAT_030089b4;
          }
        }
      }
      else {
        iVar10 = DAT_030089a0;
        if (((iVar5 != iVar9) && (iVar10 = DAT_030089a4, iVar5 != iVar2)) &&
           (iVar10 = iVar5, iVar5 == DAT_0300899c)) {
          iVar10 = DAT_030089a8;
        }
      }
    }
    else {
      FUN_02ff73b4(0x2f);
      iVar10 = 0;
    }
  }
  FUN_02ff73f6(1);
  iVar12 = DAT_030089c4;
  puVar3 = DAT_030089c0;
  iVar9 = iVar10 - DAT_030089b8;
  if (iVar10 == DAT_030089b8) {
    iVar12 = FUN_02ff7414(1);
    if (iVar12 == 0) {
      if (*DAT_03008bfc != 2) {
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73f6(0x9c);
        FUN_02ff73b4(0x9d);
        return 1;
      }
      iVar12 = *DAT_03008c00;
      iVar9 = iVar12 + (uint)*puVar1 * 2;
      if (*(short *)(iVar9 + 0x14) == 0) {
        return 0;
      }
      *(ushort *)(iVar12 + 0x54) = *puVar1;
      *(uint *)(iVar12 + 0xc) = (uint)*(ushort *)(iVar9 + 0x14);
      FUN_03021672(0xac,1);
      return 0;
    }
    goto LAB_03008a56;
  }
  if (DAT_030089b8 <= iVar10) {
    if (iVar9 != 0x3fc0) {
      if (iVar9 < 0x3fc1) {
        if (iVar9 != 0x1c0) {
          if (iVar9 == 0x3c0) goto LAB_03008ba0;
          if (iVar9 == 0x7c0) goto LAB_03008b7a;
          if (iVar9 != 0xfc0) {
            return 0;
          }
        }
      }
      else {
        if (iVar9 == 0x7fc0) {
LAB_03008ba0:
          uVar8 = (*puVar1 / 5) * 5;
          uVar4 = (ushort)uVar8;
          *puVar1 = uVar4;
          if ((uVar8 & 0xffff) < 0x18) {
            uVar4 = uVar4 + 5;
          }
          else {
            uVar4 = 0x19;
          }
          *puVar1 = uVar4;
          FUN_02ff73b4(0x98);
          return 0;
        }
        if (iVar9 == 0xffffc0) {
          auStack_48[0] = 0;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,auStack_48);
          return 0;
        }
        if (iVar9 == 0x1ffffc0) {
          auStack_48[0] = 1;
          FUN_02fe62b0(DAT_03008bf8,DAT_03008c0c,auStack_48);
          return 0;
        }
        if (iVar9 != 0x100001c0) {
          return 0;
        }
      }
      iVar12 = FUN_02ff7414(1);
      if (iVar12 == 0) {
        FUN_03009ee4();
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73b4(0xa1);
        return 1;
      }
LAB_03008a56:
      FUN_02ff73f6(1);
      return 0;
    }
LAB_03008b7a:
    uVar8 = (*puVar1 / 5) * 5;
    uVar4 = (ushort)uVar8;
    *puVar1 = uVar4;
    if ((uVar8 & 0xffff) < 5) {
      *puVar1 = 0;
    }
    else {
      *puVar1 = uVar4 - 5;
    }
    uVar11 = 0x98;
    goto LAB_03008b9a;
  }
  iVar9 = iVar10 - DAT_030089bc;
  if (iVar10 == DAT_030089bc) {
LAB_03008b3a:
    iVar9 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar9 == 1) && (*(char *)(iVar12 + 0x12) != '\0')) {
      *(char *)(iVar12 + 0x12) = *(char *)(iVar12 + 0x12) + -1;
      FUN_030147fc(0xff,0);
    }
    iVar9 = FUN_02fe6440(*puVar3,DAT_03008c08);
    if ((iVar9 == 1) && (*(char *)(iVar12 + 0x12) != '\0')) {
      *(char *)(iVar12 + 0x12) = *(char *)(iVar12 + 0x12) + -1;
      FUN_03021672(0xb6,0);
    }
  }
  else {
    if (DAT_030089bc <= iVar10) {
      if (iVar9 == 0x3e0) goto LAB_03008b7a;
      if (iVar9 == 0x7e0) goto LAB_03008ba0;
      if (iVar9 + DAT_03008bf4 == 0) goto LAB_03008aec;
      if (iVar9 + DAT_03008bf4 != 0x10) {
        return 0;
      }
      goto LAB_03008b3a;
    }
    iVar10 = iVar10 + -0x20000400;
    if (iVar10 == 0) goto LAB_03008ba0;
    if (iVar10 == 0x400) goto LAB_03008b7a;
    if (iVar10 == 0xc00) {
      iVar12 = FUN_02ff7414(1);
      if (iVar12 == 0) {
        FUN_03009ee4();
        FUN_02fe62c8(DAT_03008bf8);
        FUN_02ff0b46();
        FUN_02ff73b4(0x93);
        return 1;
      }
      goto LAB_03008a56;
    }
    if (iVar10 + DAT_03008bec != 0) {
      return 0;
    }
LAB_03008aec:
    iVar9 = FUN_02fe6440(*DAT_030089c0,DAT_03008c04);
    if ((iVar9 == 1) && (*(byte *)(iVar12 + 0x12) < *(byte *)(iVar12 + 0x1e))) {
      *(byte *)(iVar12 + 0x12) = *(byte *)(iVar12 + 0x12) + 1;
      FUN_030147fc(0xff,0);
    }
    iVar9 = FUN_02fe6440(*puVar3,DAT_03008c08);
    if ((iVar9 == 1) && (*(byte *)(iVar12 + 0x12) < *(byte *)(iVar12 + 0x1e))) {
      *(byte *)(iVar12 + 0x12) = *(byte *)(iVar12 + 0x12) + 1;
      FUN_03021672(0xb6,0);
    }
  }
  uVar11 = 0x1a9;
LAB_03008b9a:
  FUN_02ff73b4(uVar11);
  return 0;
}


