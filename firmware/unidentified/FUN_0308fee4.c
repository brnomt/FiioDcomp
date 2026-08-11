/**
 * FUN_0308fee4 @ 0x0308fee4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0308fee4(int param_1,int param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint local_190 [80];
  uint local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_34;
  int iStack_30;
  uint uStack_2c;
  int local_28;
  
  local_50 = *(uint *)(param_4 + 0x30) & 0x3f;
  uVar5 = *(uint *)(param_4 + 0x30) + param_3;
  *(uint *)(param_4 + 0x30) = uVar5;
  if (uVar5 < param_3) {
    *(int *)(param_4 + 0x2c) = *(int *)(param_4 + 0x2c) + 1;
  }
  iVar8 = DAT_03090564;
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  iVar3 = param_4;
  if ((local_50 != 0) && (uVar5 = 0x40 - local_50, iVar3 = param_4, uVar5 <= param_3)) {
    local_28 = param_4;
    wma_memmove(param_4 + local_50 + 0x34,param_1 + param_2,0x40 - local_50);
    FUN_0309049e(local_28 + 0x18,local_28 + 0x34);
    param_3 = param_3 - uVar5;
    param_2 = param_2 + uVar5;
    local_50 = 0;
    iVar8 = DAT_03090564;
    iVar3 = local_28;
  }
  do {
    iVar4 = DAT_03090564;
    DAT_03090564 = iVar8;
    local_28 = iVar3;
    if (param_3 < 0x40) {
      if (param_3 == 0) {
        return;
      }
      wma_memmove(iVar3 + local_50 + 0x34,local_34 + param_2,param_3);
      return;
    }
    puVar11 = (uint *)(iVar3 + 0x18);
    iVar8 = 0x10;
    puVar6 = (uint *)(local_34 + param_2);
    puVar7 = local_190;
    do {
      uVar5 = *puVar6;
      pbVar1 = (byte *)((int)puVar6 + 3);
      puVar6 = puVar6 + 1;
      *puVar7 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                (uint)*pbVar1;
      iVar8 = iVar8 + -1;
      puVar7 = puVar7 + 1;
    } while (iVar8 != 0);
    FUN_03083e10(&local_4c,puVar11,5);
    puVar7 = local_190 + 0xd;
    iVar8 = 0x40;
    do {
      uVar5 = *puVar7 ^ puVar7[-5] ^ puVar7[-0xb] ^ puVar7[-0xd];
      puVar7[3] = uVar5 >> 0x1f | uVar5 << 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar8 = 0;
    do {
      uVar9 = *puVar11;
      uVar10 = *(uint *)(iVar3 + 0x20);
      uVar5 = *(uint *)(iVar3 + 0x24);
      uVar14 = *(uint *)(iVar3 + 0x1c);
      if (iVar8 < 0x3c) {
        if (iVar8 < 0x28) {
          if (0x13 < iVar8) goto LAB_03090084;
          if (-1 < iVar8) {
            uVar13 = ~uVar14;
            uVar2 = uVar10;
            goto LAB_0308ffcc;
          }
          uVar13 = 0;
        }
        else {
          uVar2 = uVar10 | uVar5;
          uVar13 = uVar10;
LAB_0308ffcc:
          uVar13 = uVar2 & uVar14 | uVar13 & uVar5;
        }
      }
      else {
LAB_03090084:
        uVar13 = uVar14 ^ uVar10 ^ uVar5;
      }
      iVar12 = iVar4;
      if ((((iVar8 < 0x3c) && (iVar12 = DAT_03090568, iVar8 < 0x28)) &&
          (iVar12 = DAT_0309056c, iVar8 < 0x14)) && (iVar12 = DAT_03090570, iVar8 < 0)) {
        iVar12 = 0;
      }
      uVar13 = iVar12 + local_190[iVar8] +
                        (uVar9 >> 0x1b | uVar9 << 5) + uVar13 + *(int *)(iVar3 + 0x28);
      *(uint *)(iVar3 + 0x24) = uVar10;
      *(uint *)(iVar3 + 0x28) = uVar5;
      *puVar11 = uVar13;
      *(uint *)(iVar3 + 0x1c) = uVar9;
      *(uint *)(iVar3 + 0x20) = uVar14 >> 2 | uVar14 << 0x1e;
      iVar8 = (int)(short)((short)iVar8 + 1);
    } while (iVar8 < 0x50);
    local_4c = local_4c + uVar13;
    local_48 = local_48 + *(int *)(iVar3 + 0x1c);
    local_44 = local_44 + *(int *)(iVar3 + 0x20);
    local_40 = local_40 + *(int *)(iVar3 + 0x24);
    local_3c = local_3c + *(int *)(iVar3 + 0x28);
    FUN_03083e10(puVar11,&local_4c,5);
    param_2 = param_2 + 0x40;
    param_3 = param_3 - 0x40;
    iVar8 = DAT_03090564;
    iVar3 = local_28;
    DAT_03090564 = iVar4;
  } while( true );
}


