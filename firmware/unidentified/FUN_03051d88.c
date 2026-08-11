/**
 * FUN_03051d88 @ 0x03051d88
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03051d88(void)

{
  byte bVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 local_90;
  ushort local_8e;
  undefined4 local_8c;
  undefined4 local_88;
  undefined2 local_84;
  undefined2 local_82;
  undefined2 local_80;
  undefined2 local_7e;
  undefined2 local_7c;
  undefined2 local_7a [15];
  undefined4 local_5c [4];
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  puVar2 = DAT_03051fe4;
  local_5c[0] = *DAT_03052014;
  local_5c[1] = DAT_03052014[1];
  local_5c[2] = DAT_03052014[2];
  local_5c[3] = DAT_03052014[3];
  local_44 = DAT_03052014[6];
  local_4c = DAT_03052014[4];
  uStack_48 = DAT_03052014[5];
  local_40[0] = DAT_03052014[7];
  local_40[1] = DAT_03052014[8];
  local_40[2] = DAT_03052014[9];
  local_40[3] = DAT_03052014[10];
  local_30 = DAT_03052014[0xb];
  local_2c = DAT_03052014[0xc];
  uStack_28 = DAT_03052014[0xd];
  iVar5 = 0xfff;
  *DAT_03052018 = (int)DAT_03051fe4;
  do {
    puVar2[iVar5] = 0;
    iVar5 = iVar5 + -1;
  } while (-1 < iVar5);
  *puVar2 = 0x52;
  puVar2[1] = 0x49;
  puVar2[2] = 0x46;
  puVar2[3] = 0x46;
  puVar2[8] = 0x57;
  puVar2[9] = 0x41;
  puVar2[10] = 0x56;
  puVar2[0xb] = 0x45;
  puVar2[0xc] = 0x66;
  puVar2[0xd] = 0x6d;
  puVar2[0xe] = 0x74;
  puVar2[0xf] = 0x20;
  puVar2[0x10] = 0x32;
  puVar2[0x11] = 0;
  piVar3 = DAT_03051ff4;
  puVar2[0x12] = 0;
  puVar2[0x13] = 0;
  iVar5 = DAT_03051fec;
  if (*piVar3 == 2) {
    local_90 = 1;
    bVar1 = *(byte *)(DAT_03051fec + 0x228);
    local_8c = *(undefined4 *)(DAT_03051fec + 0x224);
    local_88 = *(undefined4 *)(DAT_03051fec + 0x220);
    if (*DAT_03051ffc == 0x17) {
      local_84 = 6;
      local_82 = 0x18;
    }
    else {
      local_84 = *(undefined2 *)(DAT_03051fec + 0x22a);
      local_82 = 0x10;
    }
    local_7e = *(undefined2 *)(DAT_03051fec + 0x22c);
    local_7c = 0;
    iVar4 = 0;
    do {
      iVar6 = iVar4 + 1;
      local_7a[iVar4 * 2] = 0;
      local_7a[iVar4 * 2 + 1] = 0;
      iVar4 = iVar6;
    } while (iVar6 < 7);
  }
  else {
    local_90 = 2;
    bVar1 = *(byte *)(DAT_03051fec + 0x228);
    local_8c = *(undefined4 *)(DAT_03051fec + 0x224);
    local_88 = *(undefined4 *)(DAT_03051fec + 0x220);
    local_84 = *(undefined2 *)(DAT_03051fec + 0x22a);
    local_82 = 4;
    local_7e = *(undefined2 *)(DAT_03051fec + 0x22c);
    local_7c = 7;
    iVar4 = 0;
    do {
      local_7a[iVar4 * 2] = *(undefined2 *)(local_5c + iVar4);
      iVar6 = iVar4 + 1;
      local_7a[iVar4 * 2 + 1] = *(undefined2 *)(local_40 + iVar4);
      iVar4 = iVar6;
    } while (iVar6 < 7);
  }
  local_8e = (ushort)bVar1;
  local_80 = 0x20;
  FUN_030272b2(puVar2 + 0x14,&local_90,0x32);
  iVar4 = *DAT_03052018;
  *(undefined1 *)(iVar4 + 0x46) = 0x66;
  *(undefined1 *)(iVar4 + 0x47) = 0x61;
  *(undefined1 *)(iVar4 + 0x48) = 99;
  *(undefined1 *)(iVar4 + 0x49) = 0x74;
  *(undefined1 *)(iVar4 + 0x4a) = 4;
  *(undefined1 *)(iVar4 + 0x4b) = 0;
  *(undefined1 *)(iVar4 + 0x4c) = 0;
  *(undefined1 *)(iVar4 + 0x4d) = 0;
  *(undefined1 *)(iVar4 + 0x4e) = *(undefined1 *)(iVar5 + 0x238);
  *(char *)(iVar4 + 0x4f) = (char)((ushort)*(undefined2 *)(iVar5 + 0x238) >> 8);
  *(char *)(iVar4 + 0x50) = (char)((uint)*(undefined4 *)(iVar5 + 0x238) >> 0x10);
  *(char *)(iVar4 + 0x51) = (char)((uint)*(undefined4 *)(iVar5 + 0x238) >> 0x18);
  *(undefined1 *)(iVar4 + 0x52) = 0x4c;
  *(undefined1 *)(iVar4 + 0x53) = 0x49;
  *(undefined1 *)(iVar4 + 0x54) = 0x53;
  *(undefined1 *)(iVar4 + 0x55) = 0x54;
  *(undefined1 *)(iVar4 + 0x56) = 0x9e;
  *(undefined1 *)(iVar4 + 0x57) = 0xf;
  *(undefined1 *)(iVar4 + 0x5a) = 0x49;
  *(undefined1 *)(iVar4 + 0x5b) = 0x4e;
  *(undefined1 *)(iVar4 + 0x5c) = 0x46;
  *(undefined1 *)(iVar4 + 0x5d) = 0x4f;
  *(undefined1 *)(iVar4 + 0x5e) = 0x52;
  *(undefined1 *)(iVar4 + 0x5f) = 0x6f;
  *(undefined1 *)(iVar4 + 0x60) = 99;
  *(undefined1 *)(iVar4 + 0x61) = 0x6b;
  *(undefined1 *)(iVar4 + 0x62) = 0x92;
  *(undefined1 *)(iVar4 + 99) = 0xf;
  *(undefined1 *)(iVar4 + 0xff8) = 100;
  *(undefined1 *)(iVar4 + 0xff9) = 0x61;
  *(undefined1 *)(iVar4 + 0xffa) = 0x74;
  *(undefined1 *)(iVar4 + 0xffb) = 0x61;
  *(undefined1 *)(iVar4 + 0xffc) = 0xff;
  *(undefined1 *)(iVar4 + 0xffd) = 0xff;
  *(undefined1 *)(iVar4 + 0xffe) = 0xff;
  *(undefined1 *)(iVar4 + 0xfff) = 0xff;
  *(undefined1 *)(iVar4 + 4) = 0xff;
  *(undefined1 *)(iVar4 + 5) = 0xff;
  *(undefined1 *)(iVar4 + 6) = 0xff;
  *(undefined1 *)(iVar4 + 7) = 0xff;
  return;
}


