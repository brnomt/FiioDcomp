/**
 * FUN_03017f1e @ 0x03017f1e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined2 FUN_03017f1e(void)

{
  byte bVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  iVar5 = FUN_02ffd29a();
  puVar2 = DAT_03017fb4;
  cVar3 = *DAT_03017f70;
  if (cVar3 == '\0') {
    uVar4 = FUN_03017d6a();
    return uVar4;
  }
  if (cVar3 != '\x03') {
    if (cVar3 != '\x06') {
      if (iVar5 != DAT_03017fb8) {
        if (iVar5 < DAT_03017fb8) {
          if ((iVar5 != 0x40000040 && iVar5 != 0x40000200) && iVar5 != 0x40001000) {
            return 0;
          }
        }
        else {
          iVar5 = (iVar5 - DAT_03017fb8) + DAT_03018488;
          if (iVar5 != 0 && iVar5 != 0xfe00) {
            return 0;
          }
        }
      }
      *DAT_03017fbc = 0;
      goto LAB_0301809e;
    }
    if (iVar5 == DAT_03018480) {
      iVar5 = FUN_02ff2834(*DAT_03017fb4,DAT_03018478);
      if (iVar5 == 1) {
        FUN_03020bf0(0xff,0);
      }
      FUN_02ff26bc(DAT_0301847c);
      func_0x030037a8(199);
    }
    else {
      if (iVar5 < DAT_03018480) {
        if (iVar5 == 0x30000004) {
LAB_0301810c:
          if (*(byte *)(DAT_03017f78 + 0x35d) < 0x18) {
            *(byte *)(DAT_03017f78 + 0x35d) = *(byte *)(DAT_03017f78 + 0x35d) + 1;
          }
          iVar5 = FUN_02ff2834(*puVar2,DAT_03018478);
        }
        else {
          if (iVar5 != 0x30000008) {
            if (iVar5 == 0x40000004) goto LAB_0301810c;
            if (iVar5 != 0x40000008) goto LAB_03018172;
          }
          if (*(char *)(DAT_03017f78 + 0x35d) != '\0') {
            *(char *)(DAT_03017f78 + 0x35d) = *(char *)(DAT_03017f78 + 0x35d) + -1;
          }
          iVar5 = FUN_02ff2834(*puVar2,DAT_03018478);
        }
        if (iVar5 == 1) {
          FUN_03020bf0(0xff,0);
        }
        uVar6 = 0x1c3;
      }
      else {
        bVar8 = iVar5 - DAT_03018480 == 0xfc0;
        if (!bVar8) {
          iVar5 = (iVar5 - DAT_03018480) + -0xffc0;
          bVar8 = iVar5 == 0;
        }
        if (!bVar8) {
          bVar8 = iVar5 == 0x10000000;
        }
        if (!bVar8) goto LAB_03018172;
        iVar5 = FUN_02ff2834(*DAT_03017fb4,DAT_03018478);
        if (iVar5 == 1) {
          FUN_03020bf0(0xff,0);
        }
        FUN_02ff26bc(DAT_0301847c);
        uVar6 = 199;
      }
      func_0x030037a8(uVar6);
    }
LAB_03018172:
    iVar5 = ui_refresh_and_redraw(0x19);
    if (((iVar5 == 0) && (*DAT_03018484 != '\x01')) &&
       (iVar5 = ui_refresh_and_redraw(0x27), iVar5 == 0)) {
      return 0;
    }
LAB_0301809e:
    FUN_02ff26bc(DAT_0301847c);
    func_0x030037a8(199);
    return 0;
  }
  iVar7 = iVar5 - DAT_0301846c;
  if (iVar5 != DAT_0301846c) {
    if (iVar5 < DAT_0301846c) {
      if (iVar5 == DAT_03018470) {
LAB_0301803e:
        bVar1 = *(byte *)(DAT_03017f78 + 0x1e);
        if (*(char *)(DAT_03017f78 + 0x35a) != '\0') goto joined_r0x0301806e;
joined_r0x03018068:
        if (bVar1 < 0x78) {
          cVar3 = bVar1 + 1;
          goto LAB_03018054;
        }
      }
      else {
        if (DAT_03018470 <= iVar5) {
          if (iVar5 - DAT_03018470 == 0x38) goto LAB_0301809e;
          if (iVar5 - DAT_03018470 != 0xf8) {
            return 0;
          }
          goto LAB_03018072;
        }
        if (iVar5 != 0x30000004) {
          if (iVar5 == 0x30000008) goto LAB_0301803e;
          if (iVar5 != 0x40000004) {
            return 0;
          }
        }
        bVar1 = *(byte *)(DAT_03017f78 + 0x1e);
        if (*(char *)(DAT_03017f78 + 0x35a) != '\0') goto joined_r0x03018068;
joined_r0x0301806e:
        if (bVar1 != 0) {
          cVar3 = bVar1 - 1;
LAB_03018054:
          *(char *)(DAT_03017f78 + 0x1e) = cVar3;
        }
      }
      uVar6 = 0x1c3;
      goto LAB_03018098;
    }
    if (iVar7 != DAT_03018474) {
      if (iVar7 < DAT_03018474) {
        if (iVar7 != 0xe00 && iVar7 != 0xfe00) {
          return 0;
        }
      }
      else if (iVar7 - DAT_03018474 != 0x100 && iVar7 - DAT_03018474 != 0xff00) {
        return 0;
      }
    }
  }
LAB_03018072:
  if (*(byte *)(DAT_03017f78 + 0x1e) < *(byte *)(DAT_03017f78 + 0x12)) {
    *(byte *)(DAT_03017f78 + 0x12) = *(byte *)(DAT_03017f78 + 0x1e);
  }
  iVar5 = FUN_02ff2834(*puVar2,DAT_03018478);
  if (iVar5 == 1) {
    FUN_03020bf0(0xff,0);
  }
  FUN_02ff26bc(DAT_0301847c);
  uVar6 = 199;
LAB_03018098:
  func_0x030037a8(uVar6);
  return 0;
}


