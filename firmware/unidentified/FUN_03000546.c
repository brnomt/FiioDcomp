/**
 * FUN_03000546 @ 0x03000546
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03000546(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort *puVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 local_70;
  short local_6c;
  short local_6a;
  short local_68;
  short local_66;
  short local_64;
  short local_62;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  
  puVar4 = DAT_030005fc;
  local_2c = (uint)*DAT_030005fc;
  local_38 = (uint)DAT_030005fc[1];
  local_34 = FUN_02fea600(1);
  local_30 = FUN_02fea5dc(2);
  *puVar4 = *DAT_03000600;
  puVar4[1] = *DAT_03000604;
  iVar6 = rom_alloc(0x26);
  if (((iVar6 != 0) || (iVar6 = FUN_02feee98(0x16f), iVar6 != 0)) ||
     (iVar6 = FUN_02feee98(0x2f), iVar6 != 0)) {
    FUN_02feaeae(0x7a);
    *puVar4 = *DAT_03000608;
    FUN_02fea6ac(0,3,0x140,0x10,2,0x58);
    *puVar4 = *DAT_03000a10;
    rom_hw_init2(0x21);
    FUN_02fea9a2(1);
    rom_hw_init2(0x170);
  }
  iVar6 = FUN_02feee98(0x170);
  pbVar5 = DAT_03000a14;
  if (iVar6 != 0) {
    FUN_02feaee6(0x7a,0,0,0x17,0x8f);
    FUN_02feabb2(0x8c,auStack_60);
    FUN_02feabb2(0x9e,auStack_50);
    bVar1 = *pbVar5;
    bVar2 = pbVar5[1];
    uVar9 = 0;
    do {
      if (((uint)bVar1 - (uint)bVar2 & 0xffff) <= uVar9) break;
      sVar3 = (short)uVar9;
      local_66 = sVar3 * 0x18 + 0x17;
      local_64 = 0x7e;
      local_68 = 0x1c;
      local_62 = sVar3 * 0x18 + 0x26;
      if (pbVar5[2] == uVar9) {
        if (uVar9 == 0) {
          FUN_02feb34a(0x86,4);
        }
        else {
          if (uVar9 == 5) {
            uVar8 = 0x88;
          }
          else {
            uVar8 = 0x85;
          }
          FUN_02feb34a(uVar8,4);
        }
        iVar6 = DAT_03000a18;
        FUN_02feb34a(*(short *)(DAT_03000a18 + (pbVar5[1] + uVar9) * 6) + 9,5,
                     (int)(short)(sVar3 * 0x18 + 0x18));
        local_66 = sVar3 * 0x18 + 0x1c;
        local_62 = sVar3 * 0x18 + 0x2b;
        *puVar4 = *DAT_03000a1c;
        FUN_02fea552(*(undefined2 *)(iVar6 + (pbVar5[1] + uVar9) * 6 + 2),iVar6 + 0x4c,0x50);
        uVar7 = FUN_02fe973e(iVar6 + 0x4c);
        uVar8 = DAT_03000a20;
        if ((uint)((int)local_64 - (int)local_68) < uVar7) {
          local_40 = CONCAT22(local_66,local_68);
          local_3c = 0x100000;
          local_70 = CONCAT22(local_66,local_68);
          local_6c = local_64;
          local_6a = local_66 + 0xf;
          FUN_02fea340(&local_70,local_40,0x100000,(int)local_68 & 0xffff0000U | 0x8d,DAT_03000a20,
                       0x1e);
          FUN_02fe9ab0(&local_68,&local_68,uVar8,0);
          rom_hw_init2(0x154);
        }
        else {
          rom_hw_init(0x154);
        }
      }
      else {
        FUN_02feb34a(*(undefined2 *)(DAT_03000a18 + (pbVar5[1] + uVar9) * 6),5,
                     (int)(short)(sVar3 * 0x18 + 0x18));
        *puVar4 = *DAT_03000a10;
      }
      FUN_02fea6ac(0x1c,uVar9 * 0x18 + 0x1c & 0xffff,local_64 - local_68,0x10,0,
                   *(undefined2 *)(DAT_03000a18 + (pbVar5[1] + uVar9) * 6 + 2));
      rom_hw_init2(399);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < 6);
  }
  iVar6 = FUN_02feee98(0x171);
  if (iVar6 != 0) {
    FUN_02feabb2(0x8c,auStack_60);
    FUN_02feabb2(0x9e,auStack_50);
    local_68 = 0x1c;
    local_62 = (ushort)pbVar5[3] * 0x18;
    local_66 = local_62 + 0x17;
    local_64 = 0x7e;
    local_62 = local_62 + 0x26;
    local_70 = 0x19;
    FUN_02feb09c(0x7a,0,local_66,0,(ushort)pbVar5[3] * 0x18 + 0x17,0x84);
    iVar6 = DAT_03000a18;
    FUN_02feb34a(*(undefined2 *)(DAT_03000a18 + ((uint)pbVar5[1] + (uint)pbVar5[3]) * 6),5,
                 (uint)pbVar5[3] * 0x18 + 0x18);
    *puVar4 = *DAT_03000a10;
    local_62 = local_66 + 0x17;
    local_66 = local_66 + 8;
    FUN_02fea6ac(0x1c,(uint)pbVar5[3] * 0x18 + 0x1c,local_64 - local_68,0x10,0,
                 *(undefined2 *)(iVar6 + ((uint)pbVar5[1] + (uint)pbVar5[3]) * 6 + 2));
    local_68 = 0x1c;
    bVar1 = pbVar5[2];
    local_64 = 0x7e;
    local_66 = (ushort)bVar1 * 0x18 + 0x17;
    local_62 = (ushort)bVar1 * 0x18 + 0x26;
    if (bVar1 == 0) {
      FUN_02feb34a(0x86,4);
    }
    else {
      if (bVar1 == 5) {
        uVar8 = 0x88;
      }
      else {
        uVar8 = 0x85;
      }
      FUN_02feb34a(uVar8,4);
    }
    FUN_02feb34a(*(short *)(iVar6 + ((uint)pbVar5[1] + (uint)pbVar5[2]) * 6) + 9,5,
                 (uint)pbVar5[2] * 0x18 + 0x18);
    FUN_02fea552(*(undefined2 *)(iVar6 + ((uint)pbVar5[1] + (uint)pbVar5[2]) * 6 + 2),DAT_03000a20,
                 0x50);
    uVar9 = FUN_02fe973e(DAT_03000a20);
    uVar8 = DAT_03000a20;
    if ((uint)((int)local_64 - (int)local_68) < uVar9) {
      local_66 = (ushort)pbVar5[2] * 0x18 + 0x1c;
      local_62 = (ushort)pbVar5[2] * 0x18 + 0x2b;
      *puVar4 = *DAT_03000a1c;
      FUN_030004f4(&local_68,0x8d,uVar8,0x1e);
      FUN_02fe9ab0(&local_68,&local_68,DAT_03000a20,0);
      rom_hw_init2(0x154);
    }
    else {
      rom_hw_init(0x154);
      *puVar4 = *DAT_03000a1c;
      local_62 = local_66 + 0x17;
      local_66 = local_66 + 8;
      FUN_02fea6ac(0x1c,(uint)pbVar5[2] * 0x18 + 0x1c,local_64 - local_68,0x10,0,
                   *(undefined2 *)(iVar6 + ((uint)pbVar5[1] + (uint)pbVar5[2]) * 6 + 2));
      *puVar4 = *DAT_03000a10;
    }
    rom_hw_init2(399);
  }
  iVar6 = rom_alloc(0x154);
  if (iVar6 != 0) {
    *puVar4 = *DAT_03000a1c;
    puVar4[1] = 0xbdf7;
    FUN_02fea218(DAT_03000a20);
    rom_hw_init2(0x3e);
  }
  FUN_02fea9a2(0);
  iVar6 = rom_alloc(1);
  if ((iVar6 != 0) && (iVar6 = FUN_02feee98(0x3e), iVar6 == 1)) {
    FUN_02feb3a0(*(byte *)(DAT_03000e40 + 0x12) + 0xd2,0,0x50);
  }
  FUN_02fea600(local_34);
  puVar4[1] = (ushort)local_38;
  *puVar4 = (ushort)local_2c;
  FUN_02fea5dc(local_30);
  return;
}


