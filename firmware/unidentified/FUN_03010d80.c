/**
 * FUN_03010d80 @ 0x03010d80
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03010d80(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined2 local_38 [18];
  
  uVar9 = FUN_02ff96ba();
  iVar4 = DAT_03010fec;
  iVar5 = (int)((ulonglong)uVar9 >> 0x20);
  iVar3 = (int)uVar9;
  if (iVar3 != DAT_03010fec) {
    iVar5 = iVar3 + -0x20000000;
  }
  if ((iVar3 == DAT_03010fec || iVar5 == 0x80) &&
     (iVar5 = FUN_02ff938a(0,0x2d,0x140,0x7d,0), iVar3 = DAT_03010ff0, iVar5 == 0)) {
    iVar5 = FUN_02ff938a(0,0,0x3c,0x32,0);
    iVar3 = 0;
    if (iVar5 != 0) {
      iVar3 = DAT_03010ff4;
    }
  }
  iVar5 = DAT_03010ffc;
  iVar6 = iVar3 - DAT_03010ff8;
  puVar7 = (undefined1 *)(DAT_03010ffc + -8);
  pcVar8 = (char *)(DAT_03010ffc + -0x14);
  if (iVar3 == DAT_03010ff8) {
    bVar1 = *(byte *)(DAT_03010ffc + -0x13);
    *(byte *)(DAT_03010ffc + -0x12) = bVar1;
    if (bVar1 < 4) {
      *(byte *)(iVar5 + -0x13) = bVar1 + 1;
    }
    else {
      *(undefined1 *)(iVar5 + -0x13) = 0;
    }
    cVar2 = *pcVar8;
joined_r0x03010e74:
    if (cVar2 != '\x02') {
      iVar4 = iVar5 + (uint)*(byte *)(iVar5 + -0x13) * 4;
      *puVar7 = *(undefined1 *)(iVar5 + (uint)*(byte *)(iVar5 + -0x13) * 4);
      *(undefined1 *)(iVar5 + -7) = *(undefined1 *)(iVar4 + 1);
      *(undefined1 *)(iVar5 + -6) = *(undefined1 *)(iVar4 + 2);
      *(undefined1 *)(iVar5 + -5) = *(undefined1 *)(iVar4 + 3);
    }
    FUN_02fffbc8(0x1ad);
    FUN_02fffbc8(0x1af);
    FUN_02fffbc8(0x1ae);
    return 0;
  }
  if (iVar3 < DAT_03010ff8) {
    if (iVar3 == iVar4) {
LAB_03010e20:
      if (*pcVar8 == '\x02') {
        *pcVar8 = '\0';
        return 0;
      }
      *pcVar8 = '\x02';
      return 0;
    }
    if (iVar3 < iVar4) {
      if (iVar3 + -0x20001000 != 0) {
        if (iVar3 + -0x20001000 + DAT_03011000 != 0) {
          return 0;
        }
        goto LAB_03010e20;
      }
    }
    else if (iVar6 != -0x600) {
      if (iVar6 != -0x400) {
        return 0;
      }
      cVar2 = *(char *)(DAT_03010ffc + -0x13);
      *(char *)(DAT_03010ffc + -0x12) = cVar2;
      if (cVar2 == '\0') {
        cVar2 = '\x04';
      }
      else {
        cVar2 = cVar2 + -1;
      }
      *(char *)(iVar5 + -0x13) = cVar2;
      cVar2 = *pcVar8;
      goto joined_r0x03010e74;
    }
  }
  else if (iVar6 != 0x800) {
    if (iVar6 != 0xf800) {
      if (iVar6 + DAT_03011004 == 0) goto LAB_03010e34;
      if (iVar6 + DAT_03011004 != 0xfe00) {
        return 0;
      }
    }
    local_38[0] = CONCAT11(local_38[0]._1_1_,10);
    FUN_02fffdf2(0,local_38);
    return 1;
  }
LAB_03010e34:
  local_38[0] = 7;
  FUN_02fffdf2(10,local_38);
  return 1;
}


