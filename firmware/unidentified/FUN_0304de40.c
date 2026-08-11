/**
 * FUN_0304de40 @ 0x0304de40
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304de40(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

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
  
  piVar5 = DAT_0304e0cc;
  piVar10 = DAT_0304e0c4;
  puVar3 = DAT_0304e0ac;
  piVar2 = DAT_0304e0a0;
  switch(param_1) {
  case 3:
    uVar7 = DAT_0304e0ac[2];
    goto LAB_0304e058;
  case 4:
    *param_2 = DAT_0304e0ac[4];
    return 1;
  case 5:
    *param_2 = DAT_0304e0ac[5];
    return 1;
  case 6:
    uVar7 = DAT_0304e0ac[1];
LAB_0304e058:
    *param_2 = uVar7;
    break;
  case 7:
    *param_2 = *DAT_0304e0ac;
    return 1;
  case 8:
    *DAT_0304e0a0 = 0;
    FUN_03032498(1,0);
    FUN_0303246c(0,0,1);
    iVar8 = *piVar2;
    iVar9 = DAT_0304e0a4;
    while (iVar8 == 0) {
      func_0x030259b4();
      FUN_030173e8();
      FUN_030298b8(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar2;
    }
    piVar10 = DAT_0304e0a8;
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
    if (DAT_0304e0ac[9] == 1) {
      if (DAT_0304e0ac[0xb] == 1) {
        return 0;
      }
      *param_3 = DAT_0304e0ac[8];
      puVar3[9] = 0;
      puVar3[10] = 1;
      FUN_03032498(4,0,1);
      FUN_0303246c(0,0,1);
      pcVar4 = DAT_0304e0b0;
      psVar1 = DAT_0304e09c;
      if (*DAT_0304e0b0 != '\0') {
        local_30 = DAT_0304e0b4[4];
        uStack_2c = DAT_0304e0b4[5];
        local_28 = DAT_0304e0b4[6];
        uStack_24 = DAT_0304e0b4[7];
        *DAT_0304e09c = 0;
        uVar6 = FUN_030245d4();
        func_0x03024600(uVar6,puVar3[7],DAT_0304e0bc,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                        DAT_0304e0b8);
        do {
          FUN_0301a1ac();
        } while (*psVar1 != 1);
        *param_2 = DAT_0304e0bc;
        *pcVar4 = '\0';
        return 1;
      }
      local_30 = *DAT_0304e0b4;
      uStack_2c = DAT_0304e0b4[1];
      local_28 = DAT_0304e0b4[2];
      uStack_24 = DAT_0304e0b4[3];
      *DAT_0304e09c = 0;
      uVar6 = FUN_030245d4();
      func_0x03024600(uVar6,puVar3[7],DAT_0304e0c0,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                      DAT_0304e0b8);
      do {
        FUN_0301a1ac();
      } while (*psVar1 != 1);
      *param_2 = DAT_0304e0c0;
      *pcVar4 = '\x01';
      return 1;
    }
    if (DAT_0304e0ac[10] == 0) {
      DAT_0304e0ac[10] = 1;
      FUN_03032498(4,0,1);
      FUN_0303246c(0,0,1);
      return 2;
    }
    if (DAT_0304e0ac[10] != 1) {
      return 0;
    }
    return 2;
  case 0xc:
    FUN_03032498(4,0,1);
    FUN_0303246c(0,0,1);
    break;
  case 0xe:
    *DAT_0304e0c4 = 0;
    FUN_03032498(0xb,0,1);
    FUN_0303246c(param_2,0,1);
    iVar8 = *piVar10;
    iVar9 = DAT_0304e0c8;
    while (iVar8 == 0) {
      func_0x030259b4();
      FUN_030173e8();
      FUN_030298b8(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar10;
    }
    goto LAB_0304e00e;
  case 0xf:
    *DAT_0304e0cc = 0;
    FUN_03032498(0xd,0,1);
    FUN_0303246c(0,0,1);
    iVar8 = *piVar5;
    iVar9 = DAT_0304e0d0;
    while (piVar10 = piVar5, iVar8 == 0) {
      func_0x030259b4();
      FUN_030173e8();
      FUN_030298b8(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar5;
    }
LAB_0304e00e:
    *piVar10 = 0;
    break;
  case 0x11:
    *param_2 = DAT_0304e0ac[3];
    break;
  default:
    return 0;
  }
  return 1;
}


