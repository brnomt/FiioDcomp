/**
 * FUN_0304d8a0 @ 0x0304d8a0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304d8a0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  short *psVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  piVar5 = DAT_0304db40;
  puVar3 = DAT_0304db28;
  piVar10 = DAT_0304db20;
  piVar2 = DAT_0304db14;
  switch(param_1) {
  case 3:
    *param_2 = DAT_0304db28[2];
    break;
  case 4:
    *param_2 = DAT_0304db28[4];
    return 1;
  case 5:
    *param_2 = DAT_0304db28[5];
    return 1;
  case 6:
    uVar8 = DAT_0304db28[1];
    goto LAB_0304db02;
  case 7:
    *param_2 = *DAT_0304db28;
    return 1;
  case 8:
    *DAT_0304db14 = 0;
    FUN_03031ef8(1,0);
    FUN_03031ecc(0,0,1);
    iVar7 = *piVar2;
    iVar9 = DAT_0304db18;
    while (iVar7 == 0) {
      FUN_03025414();
      FUN_03016e48();
      FUN_03029318(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar7 = *piVar2;
    }
    piVar10 = DAT_0304db1c;
    *piVar2 = 0;
    if (*piVar10 != 0) {
      return 0;
    }
    break;
  case 9:
  case 0xb:
  case 0xd:
  case 0x10:
    return 0;
  case 10:
    if (DAT_0304db28[9] != 1) {
      if (DAT_0304db28[10] == 0) {
        DAT_0304db28[10] = 1;
        FUN_03031ef8(4,0,1);
        FUN_03031ecc(0,0,1);
        return 2;
      }
      if (DAT_0304db28[10] == 1) {
        return 2;
      }
      return 0;
    }
    if (DAT_0304db28[0xb] == 1) {
      return 0;
    }
    *param_3 = DAT_0304db28[8];
    puVar3[9] = 0;
    puVar3[10] = 1;
    FUN_03031ef8(4,0,1);
    FUN_03031ecc(0,0,1);
    pcVar4 = DAT_0304db2c;
    psVar1 = DAT_0304db10;
    if (*DAT_0304db2c == '\0') {
      local_30 = *DAT_0304db30;
      uStack_2c = DAT_0304db30[1];
      local_28 = DAT_0304db30[2];
      uStack_24 = DAT_0304db30[3];
      *DAT_0304db10 = 0;
      uVar6 = func_0x03024034();
      FUN_03024060(uVar6,puVar3[7],DAT_0304db3c,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                   DAT_0304db34);
      do {
        FUN_03019c0c();
      } while (*psVar1 != 1);
      *param_2 = DAT_0304db3c;
      *pcVar4 = '\x01';
      return 1;
    }
    local_30 = DAT_0304db30[4];
    uStack_2c = DAT_0304db30[5];
    local_28 = DAT_0304db30[6];
    uStack_24 = DAT_0304db30[7];
    *DAT_0304db10 = 0;
    uVar6 = func_0x03024034();
    FUN_03024060(uVar6,puVar3[7],DAT_0304db38,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                 DAT_0304db34);
    do {
      FUN_03019c0c();
    } while (*psVar1 != 1);
    *param_2 = DAT_0304db38;
    *pcVar4 = '\0';
    return 1;
  case 0xc:
    FUN_03031ef8(4,0,1);
    FUN_03031ecc(0,0,1);
    break;
  case 0xe:
    *DAT_0304db20 = 0;
    FUN_03031ef8(0xb,0,1);
    FUN_03031ecc(param_2,0,1);
    iVar7 = *piVar10;
    iVar9 = DAT_0304db24;
    while (iVar7 == 0) {
      FUN_03025414();
      FUN_03016e48();
      FUN_03029318(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar7 = *piVar10;
    }
    goto LAB_0304d95c;
  case 0xf:
    *DAT_0304db40 = 0;
    FUN_03031ef8(0xd,0,1);
    FUN_03031ecc(0,0,1);
    iVar7 = *piVar5;
    iVar9 = DAT_0304db44;
    while (piVar10 = piVar5, iVar7 == 0) {
      FUN_03025414();
      FUN_03016e48();
      FUN_03029318(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar7 = *piVar5;
    }
LAB_0304d95c:
    *piVar10 = 0;
    break;
  case 0x11:
    uVar8 = DAT_0304db28[3];
LAB_0304db02:
    *param_2 = uVar8;
    break;
  default:
    return 0;
  }
  return 1;
}


