/**
 * FUN_03019c34 @ 0x03019c34
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03019c34(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  undefined1 local_40 [2];
  byte bStack_3e;
  undefined1 uStack_3d;
  
  iVar4 = FUN_030022f6();
  bVar8 = iVar4 == 0x40000080 || iVar4 == 0x50000080;
  if (iVar4 != 0x40000080 && iVar4 != 0x50000080) {
    bVar8 = iVar4 == 0x30000080;
  }
  if (((bVar8) && (iVar5 = FUN_03001fc6(0,10,0x46,0x3c,0), iVar5 == 0)) &&
     (iVar5 = FUN_03001fc6(0xbc,0x14,0xf0,0x32,0), iVar5 == 0)) {
    FUN_03001fc6(0x77,399,0x79,0x191,0);
  }
  iVar5 = FUN_03008864(0x26);
  puVar1 = DAT_03019dc8;
  if (iVar5 != 0) {
    func_0x03008846(0x26);
    func_0x03008846(0xe8);
    *puVar1 = 0;
    func_0x0301eabe(0x163,0);
    func_0x0301eabe(0x165,1);
    func_0x0301eabe(0x165,0);
    FUN_03008804(0x15f);
  }
  puVar2 = DAT_03019de4;
  iVar5 = DAT_03019dcc;
  iVar6 = iVar4 - DAT_03019df0;
  if (iVar4 == DAT_03019df0) goto LAB_03019d62;
  if (iVar4 < DAT_03019df0) {
    iVar6 = iVar4 - DAT_03019df4;
    if (iVar4 == DAT_03019df4) {
LAB_03019eaa:
      if (*(char *)(DAT_03019dcc + 0x224) != '\0') {
        return 0;
      }
      *puVar1 = 1;
      func_0x0301eabe(0x163,0);
      func_0x0301eabe(0x165,0);
      FUN_03008804(0x15f);
      return 0;
    }
    if (iVar4 < DAT_03019df4) {
      iVar6 = iVar4 - DAT_03019df8;
      if (iVar4 != DAT_03019df8) {
        if (DAT_03019df8 <= iVar4) {
          if (iVar6 + DAT_03019dfc != 0) {
            if (iVar6 + DAT_03019dfc != 2) {
              return 0;
            }
            goto LAB_03019e84;
          }
          goto LAB_03019d62;
        }
        if (iVar6 == -0x1e) {
          return 0;
        }
        if (iVar6 != -0x10) {
          return 0;
        }
LAB_03019da0:
        iVar4 = FUN_02ff7890(*DAT_03019de4,DAT_03019e04);
        if ((iVar4 == 1) && (*(byte *)(iVar5 + 0x12) < *(byte *)(iVar5 + 0x1e))) {
          *(byte *)(iVar5 + 0x12) = *(byte *)(iVar5 + 0x12) + 1;
          FUN_03025c4c(0xff,0);
        }
        iVar4 = FUN_02ff7890(*puVar2,DAT_03019fe8);
        if (iVar4 != 1) {
          return 0;
        }
        if (*(byte *)(iVar5 + 0x1e) <= *(byte *)(iVar5 + 0x12)) {
          return 0;
        }
        *(byte *)(iVar5 + 0x12) = *(byte *)(iVar5 + 0x12) + 1;
        FUN_03032ac2(0xb6,0);
        return 0;
      }
    }
    else {
      if (iVar6 == 8) goto LAB_03019da0;
      if (iVar6 != 0x18) {
        if (iVar6 != 0x38 && iVar6 != 0xf8) {
          return 0;
        }
        goto LAB_03019d62;
      }
    }
    iVar4 = FUN_02ff7890(*DAT_03019de4,DAT_03019fec);
    if ((iVar4 == 1) && (*(char *)(iVar5 + 0x12) != '\0')) {
      *(char *)(iVar5 + 0x12) = *(char *)(iVar5 + 0x12) + -1;
      FUN_03025c4c(0xff,0);
    }
    iVar4 = FUN_02ff7890(*puVar2,DAT_03019fe8);
    if (iVar4 != 1) {
      return 0;
    }
    if (*(char *)(iVar5 + 0x12) == '\0') {
      return 0;
    }
    *(char *)(iVar5 + 0x12) = *(char *)(iVar5 + 0x12) + -1;
    FUN_03032ac2(0xb6,0);
    return 0;
  }
  iVar4 = iVar6 - DAT_03019e00;
  if (iVar6 == DAT_03019e00) {
    uVar7 = FUN_03019ee0();
    return uVar7;
  }
  if (iVar6 < DAT_03019e00) {
    if (iVar6 == 0x200) {
LAB_03019e84:
      if (*(char *)(DAT_03019dcc + 0x224) != '\0') {
        return 0;
      }
      *puVar1 = 0;
      func_0x0301eabe(0x163,0);
      func_0x0301eabe(0x165,1);
      FUN_03008804(0x15f);
      return 0;
    }
    if (iVar6 == 0x600) goto LAB_03019eaa;
    if (iVar6 != 0xe00) {
      if (iVar4 != -0x1000000) {
        return 0;
      }
      _local_40 = (uint3)bStack_3e << 0x10;
      FUN_02ff7700(DAT_03019ff4,DAT_03019ff0,local_40);
      return 0;
    }
  }
  else if (iVar4 != 0xe000100 && iVar4 != 0xe000200) {
    if (iVar4 != 0xe000400) {
      if (iVar4 != 0xe000800) {
        return 0;
      }
      goto LAB_03019eaa;
    }
    goto LAB_03019e84;
  }
LAB_03019d62:
  func_0x0301eabe(0x163,0);
  FUN_02ff77e8(DAT_03019de4,DAT_03019de0);
  iVar4 = FUN_03008864(0x157);
  if (iVar4 == 0) {
    uVar3 = 4;
  }
  else {
    uVar3 = 6;
  }
  _local_40 = CONCAT21(*(undefined2 *)(iVar5 + 0x221),uVar3);
  uStack_3d = 0;
  func_0x03008a2e(9,local_40);
  return 1;
}


