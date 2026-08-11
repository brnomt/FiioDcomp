/**
 * FUN_03005e54 @ 0x03005e54
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03005e54(uint param_1,int param_2,uint param_3)

{
  longlong lVar1;
  short sVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  short local_b8 [68];
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  
  iVar5 = 0;
  iVar11 = *DAT_03005eac;
  if (iVar11 == 0) {
    local_b8[0] = 0x4d;
    local_b8[1] = 0x50;
    local_b8[2] = 0x33;
LAB_03005f2e:
    iVar5 = 3;
  }
  else if (iVar11 == 6) {
    local_b8[0] = 0x46;
    local_b8[2] = 0x41;
    local_b8[1] = 0x4c;
    local_b8[3] = 0x43;
    iVar5 = 4;
  }
  else {
    if (iVar11 != 7) {
      if (iVar11 == 2) {
        local_b8[0] = 0x41;
        local_b8[1] = 0x41;
        local_b8[2] = 0x43;
      }
      else if (iVar11 == 5) {
        local_b8[0] = 0x41;
        local_b8[1] = 0x50;
        local_b8[2] = 0x45;
      }
      else if (iVar11 == 8) {
        local_b8[0] = 0x44;
        local_b8[1] = 0x53;
        local_b8[2] = 0x44;
      }
      else if (iVar11 == 9) {
        local_b8[0] = 0x44;
        local_b8[1] = 0x53;
        local_b8[2] = 0x46;
      }
      else if (iVar11 == 1) {
        local_b8[0] = 0x57;
        local_b8[1] = 0x4d;
        local_b8[2] = 0x41;
      }
      else if (iVar11 == 4) {
        local_b8[0] = 0x4f;
        local_b8[2] = 0x47;
        local_b8[1] = 0x47;
      }
      else {
        if (iVar11 != 3) goto LAB_03005f30;
        local_b8[0] = 0x57;
        local_b8[1] = 0x41;
        local_b8[2] = 0x56;
      }
      goto LAB_03005f2e;
    }
    local_b8[0] = 0x41;
    local_b8[2] = 0x41;
    local_b8[1] = 0x4c;
    local_b8[3] = 0x43;
    iVar5 = 4;
  }
LAB_03005f30:
  local_b8[iVar5] = 0x7c;
  iVar7 = param_2 / 1000;
  iVar6 = iVar5 + 1;
  if (param_3 < 10) {
    if (999 < param_1 + DAT_0300632c) {
      if (DAT_03006330 + param_1 < 1000) {
        local_b8[iVar6] = 0x35;
        local_b8[iVar5 + 2] = 0x2e;
        local_b8[iVar5 + 3] = 0x36;
        local_b8[iVar5 + 4] = 0x4d;
        local_b8[iVar5 + 5] = 0x48;
        local_b8[iVar5 + 6] = 0x5a;
        FUN_030060e4();
        return;
      }
      if (DAT_03006334 + param_1 < 1000) {
        local_b8[iVar6] = 0x31;
        local_b8[iVar5 + 2] = 0x31;
        local_b8[iVar5 + 3] = 0x2e;
        local_b8[iVar5 + 4] = 0x32;
        local_b8[iVar5 + 5] = 0x4d;
        local_b8[iVar5 + 6] = 0x48;
        local_b8[iVar5 + 7] = 0x5a;
        FUN_030060e4();
        return;
      }
    }
    local_b8[iVar6] = 0x32;
    local_b8[iVar5 + 2] = 0x2e;
    local_b8[iVar5 + 3] = 0x38;
    local_b8[iVar5 + 4] = 0x4d;
    local_b8[iVar5 + 5] = 0x48;
    local_b8[iVar5 + 6] = 0x5a;
    FUN_030060e4();
    return;
  }
  if (99 < iVar7) {
    iVar10 = (int)((ulonglong)((longlong)DAT_03006338 * (longlong)iVar7) >> 0x20);
    iVar10 = (iVar10 >> 5) - (iVar10 >> 0x1f);
    lVar1 = (longlong)DAT_03006328 * (longlong)iVar10;
    local_b8[iVar6] =
         (short)iVar10 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
    iVar6 = iVar5 + 2;
  }
  iVar5 = (int)((ulonglong)((longlong)DAT_03006328 * (longlong)iVar7) >> 0x20);
  iVar5 = (iVar5 >> 2) - (iVar5 >> 0x1f);
  lVar1 = (longlong)DAT_03006328 * (longlong)iVar5;
  sVar2 = (short)iVar5;
  local_b8[iVar6] = sVar2 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
  local_b8[iVar6 + 1] = (short)iVar7 + sVar2 * -10 + 0x30;
  local_b8[iVar6 + 2] = 0x4b;
  local_b8[iVar6 + 3] = 0x48;
  local_b8[iVar6 + 4] = 0x5a;
  local_b8[iVar6 + 5] = 0x7c;
  iVar5 = iVar6 + 6;
  uVar8 = (uint)((ulonglong)DAT_0300633c * (ulonglong)param_3 >> 0x23);
  sVar2 = (short)uVar8;
  if (9 < param_3) {
    local_b8[iVar5] =
         sVar2 + (short)(uint)((ulonglong)DAT_0300633c * (ulonglong)uVar8 >> 0x23) * -10 + 0x30;
    iVar5 = iVar6 + 7;
  }
  local_b8[iVar5] = (short)param_3 + sVar2 * -10 + 0x30;
  local_b8[iVar5 + 1] = 0x62;
  local_b8[iVar5 + 2] = 0x69;
  local_b8[iVar5 + 3] = 0x74;
  local_b8[iVar5 + 4] = 0x7c;
  iVar6 = iVar5 + 5;
  if (9 >= param_3) {
    local_b8[iVar6] = 0x44;
    local_b8[iVar5 + 6] = 0x53;
    iVar5 = iVar5 + 7;
    local_b8[iVar5] = 0x44;
    FUN_02fef2b2(0x13c,0x127,0x67);
    goto LAB_030062bc;
  }
  uVar8 = param_1 / 1000;
  if (999 < param_1) {
    lVar1 = (longlong)DAT_03006328 * (longlong)(int)(uVar8 / 1000);
    local_b8[iVar6] =
         (short)(uVar8 / 1000) + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30
    ;
    iVar6 = iVar5 + 6;
  }
  if (99 < param_1) {
    iVar5 = (int)((ulonglong)((longlong)DAT_03006338 * (longlong)(int)uVar8) >> 0x20);
    iVar5 = (iVar5 >> 5) - (iVar5 >> 0x1f);
    lVar1 = (longlong)DAT_03006328 * (longlong)iVar5;
    local_b8[iVar6] =
         (short)iVar5 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
    iVar6 = iVar6 + 1;
  }
  iVar5 = (int)((ulonglong)((longlong)DAT_03006328 * (longlong)(int)uVar8) >> 0x20);
  iVar5 = (iVar5 >> 2) - (iVar5 >> 0x1f);
  lVar1 = (longlong)DAT_03006328 * (longlong)iVar5;
  sVar2 = (short)iVar5;
  local_b8[iVar6] = sVar2 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
  local_b8[iVar6 + 1] = (short)uVar8 + sVar2 * -10 + 0x30;
  local_b8[iVar6 + 2] = 0x6b;
  local_b8[iVar6 + 3] = 0x62;
  local_b8[iVar6 + 4] = 0x70;
  iVar5 = iVar6 + 5;
  local_b8[iVar5] = 0x73;
  if ((iVar11 == 3 || iVar11 == 5) || (iVar11 == 6 || iVar11 == 7)) {
    if (param_3 < 0x18) {
      if (DAT_03006340 <= param_2) goto LAB_0300629e;
      if (param_2 < 0xac44) goto LAB_0300628c;
      uVar3 = 0x13a;
    }
    else {
      if (param_2 < 0xac44) goto LAB_0300628c;
LAB_0300629e:
      uVar3 = 0x13b;
    }
  }
  else {
LAB_0300628c:
    uVar3 = 0x147;
  }
  FUN_02fef2b2(uVar3,0x127,0x67);
LAB_030062bc:
  uVar9 = iVar5 + 1U & 0xff;
  uVar8 = uVar9 + 1 & 0xff;
  local_b8[uVar9] = 0;
  local_b8[uVar8] = 0;
  uVar8 = uVar8 + 1 & 0xff;
  local_b8[uVar8] = 0;
  local_b8[uVar8 + 1 & 0xff] = 0;
  uStack_30 = 0xa3;
  uStack_2e = 0x7d;
  uStack_2c = 0x140;
  uStack_2a = 0x8c;
  FUN_02fee544(1);
  if (*(char *)(DAT_03006344 + 0x34f) == '\x04') {
    uVar4 = 0xe162;
  }
  else {
    uVar4 = 0x44de;
  }
  *DAT_03006348 = uVar4;
  FUN_02feda18(&uStack_30,&uStack_30,local_b8,2);
  FUN_02fee544(2);
  return;
}


