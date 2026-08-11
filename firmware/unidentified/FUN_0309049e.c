/**
 * FUN_0309049e @ 0x0309049e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0309049e(uint *param_1,uint *param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint local_178 [80];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  iVar7 = 0x10;
  puVar5 = local_178;
  do {
    uVar9 = *param_2;
    pbVar1 = (byte *)((int)param_2 + 3);
    param_2 = param_2 + 1;
    *puVar5 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              (uint)*pbVar1;
    iVar7 = iVar7 + -1;
    puVar5 = puVar5 + 1;
  } while (iVar7 != 0);
  FUN_03083e10(&local_38,param_1,5);
  iVar4 = DAT_0309056c;
  iVar3 = DAT_03090568;
  iVar7 = DAT_03090564;
  puVar5 = local_178 + 0xd;
  iVar6 = 0x40;
  do {
    uVar9 = *puVar5 ^ puVar5[-5] ^ puVar5[-0xb] ^ puVar5[-0xd];
    puVar5[3] = uVar9 >> 0x1f | uVar9 << 1;
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 0;
  do {
    uVar13 = *param_1;
    uVar8 = param_1[2];
    uVar9 = param_1[3];
    uVar10 = param_1[1];
    if (iVar6 < 0x3c) {
      if (iVar6 < 0x28) {
        if (0x13 < iVar6) goto LAB_030905d8;
        if (-1 < iVar6) {
          uVar12 = ~uVar10;
          uVar2 = uVar8;
          goto LAB_03090524;
        }
        uVar12 = 0;
      }
      else {
        uVar2 = uVar8 | uVar9;
        uVar12 = uVar8;
LAB_03090524:
        uVar12 = uVar2 & uVar10 | uVar12 & uVar9;
      }
    }
    else {
LAB_030905d8:
      uVar12 = uVar10 ^ uVar8 ^ uVar9;
    }
    iVar11 = iVar7;
    if ((((iVar6 < 0x3c) && (iVar11 = iVar3, iVar6 < 0x28)) && (iVar11 = iVar4, iVar6 < 0x14)) &&
       (iVar11 = DAT_03090570, iVar6 < 0)) {
      iVar11 = 0;
    }
    uVar12 = iVar11 + local_178[iVar6] + (uVar13 >> 0x1b | uVar13 << 5) + uVar12 + param_1[4];
    param_1[3] = uVar8;
    param_1[4] = uVar9;
    *param_1 = uVar12;
    param_1[1] = uVar13;
    param_1[2] = uVar10 >> 2 | uVar10 << 0x1e;
    iVar6 = (int)(short)((short)iVar6 + 1);
    if (0x4f < iVar6) {
      local_38 = local_38 + uVar12;
      local_34 = local_34 + param_1[1];
      local_30 = local_30 + param_1[2];
      local_2c = local_2c + param_1[3];
      local_28 = local_28 + param_1[4];
      FUN_03083e10(param_1,&local_38,5);
      return;
    }
  } while( true );
}


