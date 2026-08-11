/**
 * FUN_03090190 @ 0x03090190
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_03090190(uint *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  if (param_3 != 0 && param_2 != 0) {
    param_1[0x9a] = 0;
    uVar5 = DAT_03090574;
    param_1[0x9b] = 0;
    param_1[0x95] = uVar5;
    param_1[0x96] = DAT_03090578;
    param_1[0x97] = DAT_0309057c;
    param_1[0x98] = DAT_03090580;
    param_1[0x99] = DAT_03090584;
    FUN_0308fee4(param_3,0,param_2,param_1 + 0x8f);
    FUN_030900ac(param_1 + 0x8f,param_1 + 0x1f);
    FUN_0308fd1e(param_1 + 0x6b,param_1 + 0x22);
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    iVar2 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    sVar4 = 0;
    local_24 = 0;
    do {
      *(char *)((int)param_1 + iVar2 + 0xa8) = (char)iVar2;
      sVar4 = sVar4 + 2;
      *(char *)((int)param_1 + iVar2 + 0xa9) = (char)iVar2 + '\x01';
      iVar2 = iVar2 + 2;
    } while (sVar4 < 0x100);
    uVar5 = 0;
    *(undefined1 *)(param_1 + 0x6a) = 0;
    *(undefined1 *)((int)param_1 + 0x1a9) = 0;
    uVar7 = 0;
    iVar2 = 0;
    iVar8 = 0x100;
    do {
      bVar1 = *(byte *)((int)param_1 + iVar2 + 0xa8);
      uVar5 = uVar5 + bVar1 + (uint)*(byte *)((int)param_1 + uVar7 + 0x7c) & 0xff;
      *(undefined1 *)((int)param_1 + iVar2 + 0xa8) = *(undefined1 *)((int)param_1 + uVar5 + 0xa8);
      *(byte *)((int)param_1 + uVar5 + 0xa8) = bVar1;
      uVar7 = (uVar7 + 1) % 0xc;
      iVar2 = iVar2 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    uVar5 = (uint)(byte)param_1[0x6a];
    uVar7 = (uint)*(byte *)((int)param_1 + 0x1a9);
    iVar2 = 0;
    sVar4 = 0x40;
    do {
      uVar3 = uVar5 + 1;
      uVar5 = uVar3 & 0xff;
      bVar1 = *(byte *)((int)param_1 + uVar5 + 0xa8);
      uVar6 = uVar7 + bVar1;
      uVar7 = uVar6 & 0xff;
      *(undefined1 *)((int)param_1 + uVar5 + 0xa8) = *(undefined1 *)((int)param_1 + uVar7 + 0xa8);
      *(byte *)((int)param_1 + uVar7 + 0xa8) = bVar1;
      *(byte *)((int)&local_60 + iVar2) =
           *(byte *)((int)param_1 +
                    ((uint)bVar1 + (uint)*(byte *)((int)param_1 + uVar5 + 0xa8) & 0xff) + 0xa8) ^
           *(byte *)((int)&local_60 + iVar2);
      sVar4 = sVar4 + -1;
      iVar2 = (int)(short)((short)iVar2 + 1);
    } while (sVar4 != 0);
    *(char *)(param_1 + 0x6a) = (char)uVar3;
    *(char *)((int)param_1 + 0x1a9) = (char)uVar6;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    *(undefined2 *)(param_1 + 0x1c) = 0;
    *param_1 = local_60 | 1;
    param_1[1] = local_5c | 1;
    param_1[2] = local_58 | 1;
    param_1[3] = local_54 | 1;
    param_1[4] = local_50 | 1;
    param_1[5] = local_4c | 1;
    param_1[6] = local_48 | 1;
    param_1[7] = local_44 | 1;
    param_1[8] = local_40 | 1;
    param_1[9] = local_3c | 1;
    param_1[10] = local_38 | 1;
    param_1[0xb] = local_34 | 1;
    uVar5 = modinv_u32(local_60 | 1);
    param_1[0xc] = uVar5;
    uVar5 = modinv_u32(param_1[6]);
    param_1[0x12] = uVar5;
    uVar5 = modinv_u32(param_1[1]);
    param_1[0xd] = uVar5;
    uVar5 = modinv_u32(param_1[7]);
    param_1[0x13] = uVar5;
    uVar5 = modinv_u32(param_1[2]);
    param_1[0xe] = uVar5;
    uVar5 = modinv_u32(param_1[8]);
    param_1[0x14] = uVar5;
    uVar5 = modinv_u32(param_1[3]);
    param_1[0xf] = uVar5;
    uVar5 = modinv_u32(param_1[9]);
    param_1[0x15] = uVar5;
    uVar5 = modinv_u32(param_1[4]);
    param_1[0x10] = uVar5;
    uVar5 = modinv_u32(param_1[10]);
    param_1[0x16] = uVar5;
    uVar5 = modinv_u32(param_1[5]);
    param_1[0x11] = uVar5;
    uVar5 = modinv_u32(param_1[0xb]);
    param_1[0x17] = uVar5;
    param_1[0x26] = local_28;
    param_1[0x27] = local_24;
    param_1[0x28] = local_30;
    param_1[0x29] = local_2c;
    *(undefined1 *)(param_1 + 0x24) = 1;
  }
  return param_3 == 0 || param_2 == 0;
}


