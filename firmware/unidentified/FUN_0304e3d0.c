/**
 * FUN_0304e3d0 @ 0x0304e3d0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304e3d0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  short *psVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  piVar5 = DAT_0304e65c;
  piVar10 = DAT_0304e654;
  puVar3 = DAT_0304e63c;
  piVar2 = DAT_0304e630;
  switch(param_1) {
  case 3:
    uVar7 = DAT_0304e63c[2];
    goto LAB_0304e5e8;
  case 4:
    *param_2 = DAT_0304e63c[4];
    return 1;
  case 5:
    *param_2 = DAT_0304e63c[5];
    return 1;
  case 6:
    uVar7 = DAT_0304e63c[1];
LAB_0304e5e8:
    *param_2 = uVar7;
    break;
  case 7:
    *param_2 = *DAT_0304e63c;
    return 1;
  case 8:
    *DAT_0304e630 = 0;
    FUN_03032a28(1,0);
    FUN_030329fc(0,0,1);
    iVar8 = *piVar2;
    iVar9 = DAT_0304e634;
    while (iVar8 == 0) {
      FUN_03025f44();
      FUN_03017978();
      FUN_03029e48(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar2;
    }
    piVar10 = DAT_0304e638;
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
    if (DAT_0304e63c[9] == 1) {
      if (DAT_0304e63c[0xb] == 1) {
        return 0;
      }
      *param_3 = DAT_0304e63c[8];
      puVar3[9] = 0;
      puVar3[10] = 1;
      FUN_03032a28(4,0,1);
      FUN_030329fc(0,0,1);
      pcVar4 = DAT_0304e640;
      psVar1 = DAT_0304e62c;
      if (*DAT_0304e640 != '\0') {
        local_30 = DAT_0304e644[4];
        uStack_2c = DAT_0304e644[5];
        local_28 = DAT_0304e644[6];
        uStack_24 = DAT_0304e644[7];
        *DAT_0304e62c = 0;
        uVar6 = thunk_EXT_FUN_02ff89ce();
        FUN_03024b90(uVar6,puVar3[7],DAT_0304e64c,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                     DAT_0304e648);
        do {
          FUN_0301a73c();
        } while (*psVar1 != 1);
        *param_2 = DAT_0304e64c;
        *pcVar4 = '\0';
        return 1;
      }
      local_30 = *DAT_0304e644;
      uStack_2c = DAT_0304e644[1];
      local_28 = DAT_0304e644[2];
      uStack_24 = DAT_0304e644[3];
      *DAT_0304e62c = 0;
      uVar6 = thunk_EXT_FUN_02ff89ce();
      FUN_03024b90(uVar6,puVar3[7],DAT_0304e650,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                   DAT_0304e648);
      do {
        FUN_0301a73c();
      } while (*psVar1 != 1);
      *param_2 = DAT_0304e650;
      *pcVar4 = '\x01';
      return 1;
    }
    if (DAT_0304e63c[10] == 0) {
      DAT_0304e63c[10] = 1;
      FUN_03032a28(4,0,1);
      FUN_030329fc(0,0,1);
      return 2;
    }
    if (DAT_0304e63c[10] != 1) {
      return 0;
    }
    return 2;
  case 0xc:
    FUN_03032a28(4,0,1);
    FUN_030329fc(0,0,1);
    break;
  case 0xe:
    *DAT_0304e654 = 0;
    FUN_03032a28(0xb,0,1);
    FUN_030329fc(param_2,0,1);
    iVar8 = *piVar10;
    iVar9 = DAT_0304e658;
    while (iVar8 == 0) {
      FUN_03025f44();
      FUN_03017978();
      FUN_03029e48(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar10;
    }
    goto LAB_0304e59e;
  case 0xf:
    *DAT_0304e65c = 0;
    FUN_03032a28(0xd,0,1);
    FUN_030329fc(0,0,1);
    iVar8 = *piVar5;
    iVar9 = DAT_0304e660;
    while (piVar10 = piVar5, iVar8 == 0) {
      FUN_03025f44();
      FUN_03017978();
      FUN_03029e48(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar5;
    }
LAB_0304e59e:
    *piVar10 = 0;
    break;
  case 0x11:
    *param_2 = DAT_0304e63c[3];
    break;
  default:
    return 0;
  }
  return 1;
}


