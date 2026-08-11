/**
 * FUN_0307291a @ 0x0307291a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0307291a(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  ushort *puVar13;
  uint uVar14;
  short sVar15;
  uint uVar16;
  uint local_170;
  uint local_16c;
  uint local_7c;
  int local_78;
  undefined1 auStack_70 [8];
  int local_68;
  uint local_60;
  undefined1 *local_54;
  uint local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  int local_40;
  uint local_3c;
  uint local_34;
  int local_2c;
  int local_28;
  
  local_7c = 0;
  local_40 = 0;
  if (*(int *)(param_1 + 0x30) == 0) {
    *(undefined4 *)(param_1 + 0x30) = DAT_03072970;
  }
  if (*(int *)(param_2 + 0x28) == 0) {
    *(undefined4 *)(param_2 + 0x28) = DAT_03072960;
  }
  if (*(char *)(param_2 + 1) == '\0') {
    local_3c = 1;
  }
  else {
    local_3c = 2;
  }
  if ((*(ushort *)(param_2 + 0x18) & 0x1000) == 0) {
    if (local_3c == 1) goto LAB_030729b8;
    iVar11 = 0x20;
  }
  else if (local_3c == 1) {
    iVar11 = 9;
  }
  else {
LAB_030729b8:
    iVar11 = 0x11;
  }
  local_68 = param_2;
  local_2c = param_1;
  local_28 = param_2;
  iVar7 = FUN_03070b86(param_1 + 0x1c);
  if (*(int *)(local_2c + 0x18) - iVar7 < iVar11) {
    *(undefined2 *)(local_2c + 0x3c) = 0x231;
    *(undefined4 *)(local_2c + 0x34) = 0;
    return -1;
  }
  if ((*(byte *)(local_68 + 0x18) & 0x10) != 0) {
    uVar8 = FUN_03070b9a(*(undefined4 *)(local_2c + 0x1c),*(undefined4 *)(local_2c + 0x20),
                         iVar11 << 3,*(undefined2 *)(local_68 + 0x14));
    *(short *)(local_68 + 0x14) = (short)uVar8;
    if ((uVar8 != *(ushort *)(local_68 + 0x16)) && ((*(byte *)(local_28 + 0x20) & 1) == 0)) {
      *(undefined2 *)(local_2c + 0x3c) = 0x201;
      local_40 = -1;
    }
  }
  uVar8 = local_3c;
  sVar15 = 0;
  local_78 = local_2c + 0x1c;
  iVar11 = 0;
  uVar1 = *(ushort *)(local_68 + 0x18);
  if ((uVar1 & 0x1000) == 0) {
    if (local_3c == 1) {
      local_34 = 5;
    }
    else {
      local_34 = 3;
    }
    uVar10 = 9;
  }
  else {
    if (local_3c == 1) {
      local_34 = 1;
    }
    else {
      local_34 = 2;
    }
    uVar10 = 8;
  }
  local_54 = (undefined1 *)&local_170;
  local_170 = bitstream_getbits_be(local_78,uVar10);
  local_16c = bitstream_getbits_be(local_78,local_34);
  local_50 = 1;
  if ((uVar1 & 0x1000) == 0) {
    local_50 = 2;
    uVar16 = 0;
    if (uVar8 != 0) {
      do {
        uVar3 = bitstream_getbits_be(local_78,4);
        uVar12 = uVar16 + 1;
        local_54[uVar16 + 8] = uVar3;
        uVar16 = uVar12;
      } while (uVar12 < uVar8);
    }
  }
  local_60 = 0;
  do {
    puVar2 = local_54;
    uVar16 = 0;
    iVar7 = local_60 * 0x74;
    if (uVar8 != 0) {
      do {
        puVar13 = (ushort *)(puVar2 + uVar16 * 0x3a + iVar7 + 10);
        uVar6 = bitstream_getbits_be(local_78,0xc);
        *puVar13 = uVar6;
        uVar6 = bitstream_getbits_be(local_78,9);
        puVar13[1] = uVar6;
        uVar6 = bitstream_getbits_be(local_78,8);
        puVar13[2] = uVar6;
        if ((uVar1 & 0x1000) == 0) {
          uVar10 = 4;
        }
        else {
          uVar10 = 9;
        }
        uVar6 = bitstream_getbits_be(local_78,uVar10);
        puVar13[3] = uVar6;
        iVar11 = iVar11 + (uint)*puVar13;
        if ((0x120 < puVar13[1]) && (sVar15 == 0)) {
          sVar15 = 0x232;
        }
        *(undefined1 *)(puVar13 + 4) = 0;
        iVar9 = bitstream_getbits_be(local_78,1);
        if (iVar9 == 0) {
          *(undefined1 *)((int)puVar13 + 9) = 0;
        }
        uVar12 = 0;
        if (iVar9 == 0) {
          do {
            uVar3 = bitstream_getbits_be(local_78,5);
            uVar14 = uVar12 + 1;
            *(undefined1 *)((int)puVar13 + uVar12 + 10) = uVar3;
            uVar12 = uVar14;
          } while (uVar14 < 3);
          uVar3 = bitstream_getbits_be(local_78,4);
          *(undefined1 *)(puVar13 + 8) = uVar3;
          uVar3 = bitstream_getbits_be(local_78,3);
          *(undefined1 *)((int)puVar13 + 0x11) = uVar3;
        }
        else {
          cVar4 = bitstream_getbits_be(local_78,2);
          *(char *)((int)puVar13 + 9) = cVar4;
          if (cVar4 == '\0' && sVar15 == 0) {
            sVar15 = 0x233;
          }
          if ((((uVar1 & 0x1000) == 0 && cVar4 == '\x02') && (local_54[uVar16 + 8] != '\0')) &&
             (sVar15 == 0)) {
            sVar15 = 0x234;
          }
          *(undefined1 *)(puVar13 + 8) = 7;
          *(undefined1 *)((int)puVar13 + 0x11) = 0x24;
          iVar9 = bitstream_getbits_be(local_78,1);
          if (iVar9 == 0) {
            if (*(char *)((int)puVar13 + 9) == '\x02') {
              *(undefined1 *)(puVar13 + 8) = 8;
            }
          }
          else {
            *(byte *)(puVar13 + 4) = (byte)puVar13[4] | 8;
          }
          uVar12 = 0;
          do {
            uVar3 = bitstream_getbits_be(local_78,5);
            uVar14 = uVar12 + 1;
            *(undefined1 *)((int)puVar13 + uVar12 + 10) = uVar3;
            uVar12 = uVar14;
          } while (uVar14 < 2);
          *(undefined1 *)(puVar13 + 6) = 4;
          uVar12 = 0;
          do {
            uVar3 = bitstream_getbits_be(local_78,3);
            uVar14 = uVar12 + 1;
            *(undefined1 *)((int)puVar13 + uVar12 + 0xd) = uVar3;
            uVar12 = uVar14;
          } while (uVar14 < 3);
        }
        if ((uVar1 & 0x1000) == 0) {
          uVar10 = 3;
        }
        else {
          uVar10 = 2;
        }
        bVar5 = bitstream_getbits_be(local_78,uVar10);
        uVar16 = uVar16 + 1;
        *(byte *)(puVar13 + 4) = bVar5 | (byte)puVar13[4];
      } while (uVar16 < uVar8);
    }
    local_60 = local_60 + 1;
  } while (local_60 < local_50);
  if ((sVar15 != 0) && (local_40 == 0)) {
    *(short *)(local_2c + 0x3c) = sVar15;
    local_40 = -1;
  }
  *(uint *)(local_68 + 0x18) = *(uint *)(local_68 + 0x18) | local_34;
  *(uint *)(local_68 + 0x1c) = local_16c | *(uint *)(local_68 + 0x1c);
  FUN_03070b64(auStack_70,*(undefined4 *)(local_2c + 0x18));
  uVar8 = bitstream_getbits_be(auStack_70,0x20);
  if ((DAT_03072d74 & uVar8) == 0xffe20000) {
    if ((uVar8 & 0x10000) == 0) {
      FUN_03070b92(auStack_70,0x10);
    }
    if ((uVar8 & 0x80000) == 0) {
      uVar10 = 8;
    }
    else {
      uVar10 = 9;
    }
    local_7c = bitstream_getbits_be(auStack_70,uVar10);
  }
  iVar7 = FUN_03070b86(local_2c + 0x1c);
  uVar8 = *(int *)(local_2c + 0x18) - iVar7;
  if (local_170 + uVar8 < local_7c) {
    local_7c = 0;
  }
  uVar12 = (local_170 + uVar8) - local_7c;
  uVar16 = 0;
  if (local_170 == 0) {
    local_48 = *(undefined4 *)(local_2c + 0x1c);
    uStack_44 = *(undefined4 *)(local_2c + 0x20);
    *(undefined4 *)(local_2c + 0x34) = 0;
    uVar16 = uVar12;
  }
  else if (*(uint *)(local_2c + 0x34) < local_170) {
    if (local_40 == 0) {
      *(undefined2 *)(local_2c + 0x3c) = 0x235;
      local_40 = -1;
      goto LAB_03072cfa;
    }
  }
  else {
    FUN_03070b64(&local_48,(*(uint *)(local_2c + 0x34) + *(int *)(local_2c + 0x30)) - local_170);
    if (local_170 < uVar12) {
      uVar16 = uVar12 - local_170;
      uVar10 = FUN_03070b86(local_2c + 0x1c);
      hifi_memmove(*(int *)(local_2c + 0x30) + *(int *)(local_2c + 0x34),uVar10,uVar16);
      *(uint *)(local_2c + 0x34) = *(int *)(local_2c + 0x34) + uVar16;
    }
  }
  uVar8 = uVar8 - uVar16;
  if (local_40 == 0) {
    iVar7 = FUN_0307112c(&local_48,local_28,&local_170,local_3c);
    if (iVar7 != 0) {
      *(short *)(local_2c + 0x3c) = (short)iVar7;
      local_40 = -1;
    }
    *(undefined4 *)(local_2c + 0x24) = local_48;
    *(undefined4 *)(local_2c + 0x28) = uStack_44;
    *(uint *)(local_2c + 0x2c) = uVar12 * 8 - iVar11;
  }
LAB_03072cfa:
  if (uVar8 < local_7c) {
    if (uVar12 < local_170) {
      uVar12 = local_170 - uVar12;
      if (local_7c < uVar12 + uVar8) {
        uVar12 = local_7c - uVar8;
      }
      if (uVar12 < *(uint *)(local_2c + 0x34)) {
        hifi_memmove(*(int *)(local_2c + 0x30),
                     (*(uint *)(local_2c + 0x34) + *(int *)(local_2c + 0x30)) - uVar12,uVar12);
        *(uint *)(local_2c + 0x34) = uVar12;
      }
    }
    else {
      *(undefined4 *)(local_2c + 0x34) = 0;
    }
    hifi_memmove(*(int *)(local_2c + 0x34) + *(int *)(local_2c + 0x30),
                 *(int *)(local_2c + 0x18) - uVar8,uVar8);
    *(uint *)(local_2c + 0x34) = *(int *)(local_2c + 0x34) + uVar8;
  }
  else {
    hifi_memmove(*(undefined4 *)(local_2c + 0x30),*(int *)(local_2c + 0x18) - local_7c,local_7c);
    *(uint *)(local_2c + 0x34) = local_7c;
  }
  return local_40;
}


