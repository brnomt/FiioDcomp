/**
 * FUN_0308e68c @ 0x0308e68c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_0308e68c(byte *param_1,uint *param_2,int param_3,int param_4,undefined4 param_5,int param_6
                 ,int *param_7,uint *param_8,uint *param_9,undefined4 *param_10)

{
  undefined1 uVar1;
  ulonglong uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  undefined1 uVar14;
  undefined1 *puVar15;
  int iVar16;
  undefined1 auStack_160 [116];
  undefined1 auStack_ec [8];
  undefined1 *puStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 *puStack_d8;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 auStack_bc [15];
  int iStack_80;
  undefined1 auStack_78 [24];
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined4 auStack_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  uint auStack_40 [6];
  byte *local_28;
  
  local_28 = param_1 + 2;
  local_48 = DAT_0308e9ac;
  local_44 = DAT_0308e9b0;
  iVar16 = 0;
  if (param_10 == (undefined4 *)0x0) {
    return 1;
  }
  sVar3 = wma_memcmp(param_5,local_28,0x40);
  if ((((sVar3 != 0) || (*(int *)(param_1 + 0x44) == 0)) || (*(short *)(param_1 + 0x48) != param_4))
     || (sVar3 = wma_memcmp(param_3,*(int *)(param_1 + 0x44),param_4), sVar3 != 0)) {
    if ((*param_8 != 0) || (*param_9 < 0x54)) {
      *param_8 = 0;
      *param_9 = 0x54;
      return 4;
    }
    if (*param_7 != 0x10001) {
      return 3;
    }
    FUN_03090174(auStack_ec);
    sVar3 = FUN_0308282e(param_5);
    FUN_030900a2(auStack_ec,param_5,(int)sVar3);
    FUN_030900ac(auStack_ec,auStack_40);
    uVar2 = (ulonglong)DAT_0308e9a8;
    uVar9 = (uint)(uVar2 * auStack_40[0] >> 0x23);
    iVar5 = auStack_40[0] + uVar9 * -10;
    *(int *)(param_1 + 0x5c) = iVar5;
    uStack_60 = (undefined1)param_7[iVar5 * 2 + 2];
    uStack_5f = *(undefined1 *)((int)param_7 + iVar5 * 8 + 9);
    uStack_5e = *(undefined1 *)((int)param_7 + iVar5 * 8 + 10);
    uStack_5d = *(undefined1 *)((int)param_7 + iVar5 * 8 + 0xb);
    uVar6 = FUN_030842ba(&uStack_60,uVar9 * -5,(int)(uVar2 * auStack_40[0]));
    *(undefined4 *)(param_1 + 0x54) = uVar6;
    uStack_60 = (undefined1)param_7[iVar5 * 2 + 1];
    uStack_5f = *(undefined1 *)((int)param_7 + iVar5 * 8 + 5);
    uStack_5e = 0;
    uStack_5d = 0;
    iVar5 = FUN_030842ba(&uStack_60);
    *(int *)(param_1 + 0x58) = iVar5;
    if (*(int *)(param_1 + 0x54) == 0 || iVar5 == 0) {
      return 5;
    }
    do {
      uVar9 = param_7[iVar16 * 2 + 2];
      if (uVar9 == 0) {
        if ((short)param_7[iVar16 * 2 + 1] != 0) {
          return 9;
        }
      }
      else if ((((short)param_7[iVar16 * 2 + 1] == 0) || (uVar9 < 0x54)) ||
              ((uVar9 - 0x54) +
               (uint)((ulonglong)DAT_0308e9b4 * (ulonglong)(uVar9 - 0x54) >> 0x26) * -0x58 != 0)) {
        return 9;
      }
      iVar16 = (int)(short)((short)iVar16 + 1);
    } while (iVar16 < 10);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x54);
    param_1[0x50] = 0;
    param_1[0x51] = 0;
    param_1[0x52] = 0;
    param_1[0x53] = 0;
    *param_1 = 5;
    wma_memmove(local_28,param_5,0x40);
    *(int *)(param_1 + 0x44) = param_3;
    *(short *)(param_1 + 0x48) = (short)param_4;
  }
  if ((*(uint *)(param_1 + 0x4c) < *param_8) ||
     (*param_8 + *param_9 < *(uint *)(param_1 + 0x4c) + 0x58)) {
    uVar9 = 4;
  }
  else {
    FUN_03090174(auStack_160);
    FUN_030900a2(auStack_160,&local_48,4);
    iVar16 = (int)param_7 + (*(int *)(param_1 + 0x4c) - *param_8);
    for (uStack_d0 = ((uint)((ulonglong)DAT_0308e9b4 *
                             (ulonglong)(*param_9 - (*(int *)(param_1 + 0x4c) - *param_8)) >> 0x20)
                     & 0x3fffff) >> 6; uStack_d0 != 0; uStack_d0 = uStack_d0 - 1) {
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
      *param_1 = 0;
      FUN_030900a2(auStack_160,&local_44,4);
      sVar3 = *(short *)(iVar16 + 0x44);
      uStack_cc = auStack_78;
      uStack_d4 = 0x14;
      iVar5 = iVar16 + 8;
      auStack_bc[0] = *DAT_0308e9a0;
      uStack_c8 = *DAT_0308e9a4;
      uStack_c4 = DAT_0308e9a4[1];
      if (param_3 == 0 || param_4 == 0) {
        return 1;
      }
      if (iVar5 == 0 || param_2 == (uint *)0x0) {
        return 1;
      }
      sVar4 = FUN_0308282e(iVar5);
      puStack_e4 = (undefined1 *)(int)sVar4;
      if (0x19 < (int)puStack_e4 + 1) {
        return 1;
      }
      FUN_030900a2(auStack_160,auStack_bc,4);
      if (sVar3 != 0) {
        return 10;
      }
      FUN_030900a2(auStack_160,&uStack_c8,8);
      wma_memmove(param_2 + 0x90,auStack_160,0x74);
      FUN_030900a2(param_2 + 0x90,param_3,param_4);
      FUN_030900a2(param_2 + 0x90,iVar5,puStack_e4);
      FUN_030900ac(param_2 + 0x90,param_2 + 0x20);
      wma_memmove(uStack_cc,param_2 + 0x20,uStack_d4);
      puStack_e4 = auStack_78;
      iStack_80 = 0x40;
      puStack_d8 = auStack_58;
      puVar15 = (undefined1 *)(iVar16 + 8);
      wma_memclr(param_2 + 0xad,0x60);
      FUN_03083faa(param_2 + 0x2b,0x14,puStack_e4);
      FUN_03083f5c(param_2 + 0x2b,0x60,param_2 + 0xad);
      uStack_c8 = CONCAT31(uStack_c8._1_3_,*puVar15);
      uVar14 = *(undefined1 *)(iVar16 + 9);
      iVar5 = 0x1f;
      puVar7 = puVar15;
      puVar10 = &uStack_c8;
      do {
        uVar1 = puVar7[2];
        *(undefined1 *)((int)puVar10 + 1) = uVar14;
        uVar14 = puVar7[3];
        puVar10 = (undefined4 *)((int)puVar10 + 2);
        *(undefined1 *)puVar10 = uVar1;
        iVar5 = iVar5 + -1;
        puVar7 = puVar7 + 2;
      } while (iVar5 != 0);
      *(undefined1 *)((int)&uStack_c8 + iStack_80 + -1) = puVar15[iStack_80 + -1];
      iVar5 = (int)(short)((short)iStack_80 + 7U & 0xfff8) >> 2;
      puVar8 = param_2 + 0xac;
      iVar13 = 6;
      puVar11 = param_2;
      do {
        iVar13 = iVar13 + -1;
        puVar11[1] = puVar8[1] | 1;
        puVar8 = puVar8 + 2;
        puVar11 = puVar11 + 2;
        *puVar11 = *puVar8 | 1;
      } while (iVar13 != 0);
      FUN_030903c0(&uStack_c8,iVar5,&uStack_e0,param_2 + 1);
      *puStack_d8 = uStack_e0;
      puStack_d8[1] = uStack_dc;
      puVar8 = param_2 + 0xba;
      param_2[1] = param_2[0xad] + 0xc | 1;
      puVar11 = param_2 + 2;
      param_2[2] = param_2[0xba] | 1;
      iVar13 = 5;
      do {
        iVar13 = iVar13 + -1;
        puVar11[1] = puVar8[1] | 1;
        puVar8 = puVar8 + 2;
        puVar11 = puVar11 + 2;
        *puVar11 = *puVar8 | 1;
      } while (iVar13 != 0);
      FUN_030903c0(&uStack_c8,iVar5,&uStack_e0,param_2 + 1);
      puStack_d8[2] = uStack_e0;
      puStack_d8[3] = uStack_dc;
      sVar3 = wma_memcmp(auStack_58,iVar16 + 0x48,0x10);
      if (sVar3 == 0) {
        wma_memmove(param_6,iVar16,0x48);
        *param_10 = *(undefined4 *)(param_6 + 0x21);
        param_10[1] = *(undefined4 *)(param_6 + 0x25);
        param_10[2] = *(undefined4 *)(param_6 + 0x29);
        param_10[3] = *(undefined4 *)(param_6 + 0x2d);
        uVar9 = FUN_0308e278(param_2,auStack_78,(int)*(short *)(param_6 + 0x40),param_10);
        return uVar9;
      }
      *param_1 = 9;
    }
    uVar9 = (uint)*param_1;
    if (uVar9 == 0) {
      return 0;
    }
    if ((uVar9 != 5 && uVar9 != 6) && ((uVar9 != 7 && uVar9 != 8) && uVar9 != 4)) {
      return uVar9;
    }
  }
  if (*(uint *)(param_1 + 0x50) < *(uint *)(param_1 + 0x58)) {
    uVar12 = *(int *)(param_1 + 0x54) + *(uint *)(param_1 + 0x50) * 0x58;
    *param_8 = uVar12;
    *(uint *)(param_1 + 0x4c) = uVar12;
    uVar12 = *(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x50);
    if (5 < uVar12) {
      uVar12 = 5;
    }
    *param_9 = uVar12 * 0x58;
    return uVar9;
  }
  return uVar9;
}


