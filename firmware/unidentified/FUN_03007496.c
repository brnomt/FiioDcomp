/**
 * FUN_03007496 @ 0x03007496
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03007496(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  
  iVar6 = FUN_02ff2e44(0x28);
  if (iVar6 != 0) {
    return;
  }
  iVar6 = FUN_02ff2e44(0x1ce);
  if (iVar6 != 0) {
    return;
  }
  iVar7 = FUN_02ff2e44(1);
  puVar4 = DAT_03007530;
  iVar6 = DAT_0300752c;
  if (iVar7 == 0) {
    if (*(char *)(DAT_0300752c + 0x35e) == '\0') {
      FUN_0300634c();
    }
    else {
      FUN_03006d6c();
    }
  }
  else {
    uVar2 = *DAT_03007530;
    uVar3 = DAT_03007530[1];
    uVar8 = FUN_02fee568(1);
    uVar9 = FUN_02fee544(2);
    puVar4[1] = 0;
    *puVar4 = *DAT_03007534;
    iVar7 = FUN_02ff2e44(0x26);
    if (((iVar7 != 0) || (iVar7 = FUN_02ff2e00(0x39), iVar7 != 0)) ||
       (iVar7 = FUN_02ff2e00(0x2f), iVar7 != 0)) {
      FUN_02ff2de4(0x33);
      FUN_02feee16(0xd2);
      if (*(char *)(iVar6 + 0x35a) == '\x01') {
        FUN_02fef2b2(0xda,0x6e,0x81);
      }
      FUN_02feee4e(0x4f,0,0);
      cVar1 = '\0';
      if (*DAT_0300796c != '\0') {
        cVar1 = *(char *)(iVar6 + 0x34a);
      }
      if (*DAT_0300796c == '\0' || cVar1 == '\0') {
        FUN_02fee614(0,3,0x140,0x10);
      }
      else {
        FUN_02fee614(0,3,0x140,0x10);
      }
    }
    iVar7 = FUN_02ff2e00(0x33);
    uVar5 = DAT_03007970;
    if (iVar7 == 1) {
      if (*(byte *)(iVar6 + 0x12) < 0x79) {
        FUN_02feee4e(0xd2,0,0,0x2a);
        uVar11 = 0;
        if (*(byte *)(iVar6 + 0x12) >> 1 != 0) {
          do {
            if (*(char *)(iVar6 + 0x35a) == '\0') {
              iVar7 = uVar11 * -4 + 0x115;
              if ((uVar11 & 1) == 0) {
                uVar10 = 0xd9;
              }
              else {
                uVar10 = 0xd8;
              }
            }
            else {
              iVar7 = uVar11 * 4 + 0x29;
              if ((uVar11 & 1) == 0) {
                uVar10 = 0xd8;
              }
              else {
                uVar10 = 0xd9;
              }
            }
            FUN_02fef2b2(uVar10,iVar7);
            uVar11 = uVar11 + 1 & 0xff;
          } while (uVar11 < *(byte *)(iVar6 + 0x12) >> 1);
        }
        iVar7 = (uint)*(byte *)(iVar6 + 0x12) +
                (uint)((ulonglong)uVar5 * (ulonglong)(uint)*(byte *)(iVar6 + 0x12) >> 0x22) * -5;
        if (*(char *)(iVar6 + 0x35a) == '\0') {
          FUN_02fef2b2(iVar7 + 0xd3U & 0xffff,0,0x38);
        }
        else {
          FUN_02fef2b2(0xd7U - iVar7 & 0xffff,0,0x38);
        }
      }
      if (*(char *)(iVar6 + 0x12) == '\0') {
        FUN_02feee16(0xd2);
        if (*(char *)(iVar6 + 0x35a) == '\x01') {
          FUN_02fef2b2(0xda,0x6e,0x81);
        }
        FUN_02feee4e(0x4f,0,0);
        cVar1 = '\0';
        if (*DAT_0300796c != '\0') {
          cVar1 = *(char *)(iVar6 + 0x34a);
        }
        if (*DAT_0300796c == '\0' || cVar1 == '\0') {
          FUN_02fee614(0,3,0x140,0x10);
        }
        else {
          FUN_02fee614(0,3,0x140,0x10);
        }
      }
      FUN_02fee90a(1);
      FUN_02fef2b2(((uint)*(byte *)(iVar6 + 0x12) * 0x29 >> 0xc) + 0x162,0x8c,0x4c);
      uVar11 = *(byte *)(iVar6 + 0x12) / 10;
      FUN_02fef2b2(uVar11 + (uint)((ulonglong)uVar5 * (ulonglong)uVar11 >> 0x23) * -10 + 0x162 &
                   0xffff,0x9a,0x4c);
      FUN_02fef2b2((uint)*(byte *)(iVar6 + 0x12) +
                   (uint)((ulonglong)uVar5 * (ulonglong)(uint)*(byte *)(iVar6 + 0x12) >> 0x23) * -10
                   + 0x162 & 0xffff,0xa8,0x4c);
    }
    FUN_02fee568(uVar8);
    puVar4 = DAT_03007974;
    DAT_03007974[1] = uVar3;
    *puVar4 = uVar2;
    FUN_02fee544(uVar9);
  }
  iVar7 = FUN_02ff2e00(0x43);
  if (iVar7 != 1) goto LAB_03007818;
  iVar7 = FUN_02fef5da(1);
  if (iVar7 == 0) {
    if (*(char *)(iVar6 + 0x35e) == '\x01') {
      uVar10 = 0x76;
      uVar9 = 0x115;
      uVar8 = 0x135;
    }
    else {
      if (*DAT_03007978 == '\x01') goto LAB_030077c8;
      uVar10 = 0x51;
      uVar9 = 0x129;
      uVar8 = 0x137;
    }
LAB_03007794:
    FUN_02fef2b2(uVar8,uVar9,uVar10);
  }
  else {
    if (*(char *)(iVar6 + 0x35e) == '\x01') {
      uVar10 = 0x76;
      uVar9 = 0x115;
      uVar8 = 0x136;
      goto LAB_03007794;
    }
    if (*DAT_03007978 != '\x01') {
      uVar10 = 0x51;
      uVar9 = 0x129;
      uVar8 = 0x138;
      goto LAB_03007794;
    }
  }
LAB_030077c8:
  switch(*(undefined1 *)(iVar6 + 0x6d)) {
  case 0:
  case 4:
    uVar8 = 2;
    iVar7 = 0x56;
    break;
  case 1:
  case 5:
    uVar8 = 2;
    iVar7 = 0x54;
    break;
  case 2:
  case 6:
    uVar8 = 2;
    iVar7 = 0x55;
    break;
  case 3:
  case 7:
    uVar8 = 4;
    iVar7 = *(byte *)(iVar6 + 0x6f) + 0x5a;
    break;
  default:
    goto switchD_030077d0_default;
  }
  FUN_02fef308(iVar7,0xda,uVar8);
switchD_030077d0_default:
  FUN_02ff2de4(0x44);
  if (*(byte *)(iVar6 + 0x6f) != 0) {
    FUN_02fef308(*(byte *)(iVar6 + 0x6f) + 0x5a,0xda,4);
  }
LAB_03007818:
  FUN_02fee90a(0);
  return;
}


