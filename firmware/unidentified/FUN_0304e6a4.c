/**
 * FUN_0304e6a4 @ 0x0304e6a4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304e6a4(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

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
  
  piVar5 = DAT_0304e930;
  piVar10 = DAT_0304e928;
  puVar3 = DAT_0304e910;
  piVar2 = DAT_0304e904;
  switch(param_1) {
  case 3:
    uVar7 = DAT_0304e910[2];
    goto LAB_0304e8bc;
  case 4:
    *param_2 = DAT_0304e910[4];
    return 1;
  case 5:
    *param_2 = DAT_0304e910[5];
    return 1;
  case 6:
    uVar7 = DAT_0304e910[1];
LAB_0304e8bc:
    *param_2 = uVar7;
    break;
  case 7:
    *param_2 = *DAT_0304e910;
    return 1;
  case 8:
    *DAT_0304e904 = 0;
    FUN_03032cfc(1,0);
    FUN_03032cd0(0,0,1);
    iVar8 = *piVar2;
    iVar9 = DAT_0304e908;
    while (iVar8 == 0) {
      FUN_03026218();
      FUN_03017c4c();
      func_0x0302a11c(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar2;
    }
    piVar10 = DAT_0304e90c;
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
    if (DAT_0304e910[9] == 1) {
      if (DAT_0304e910[0xb] == 1) {
        return 0;
      }
      *param_3 = DAT_0304e910[8];
      puVar3[9] = 0;
      puVar3[10] = 1;
      FUN_03032cfc(4,0,1);
      FUN_03032cd0(0,0,1);
      pcVar4 = DAT_0304e914;
      psVar1 = DAT_0304e900;
      if (*DAT_0304e914 != '\0') {
        local_30 = DAT_0304e918[4];
        uStack_2c = DAT_0304e918[5];
        local_28 = DAT_0304e918[6];
        uStack_24 = DAT_0304e918[7];
        *DAT_0304e900 = 0;
        uVar6 = FUN_03024e38();
        FUN_03024e64(uVar6,puVar3[7],DAT_0304e920,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                     DAT_0304e91c);
        do {
          FUN_0301aa10();
        } while (*psVar1 != 1);
        *param_2 = DAT_0304e920;
        *pcVar4 = '\0';
        return 1;
      }
      local_30 = *DAT_0304e918;
      uStack_2c = DAT_0304e918[1];
      local_28 = DAT_0304e918[2];
      uStack_24 = DAT_0304e918[3];
      *DAT_0304e900 = 0;
      uVar6 = FUN_03024e38();
      FUN_03024e64(uVar6,puVar3[7],DAT_0304e924,(uint)(puVar3[3] * puVar3[8]) >> 4,&local_30,
                   DAT_0304e91c);
      do {
        FUN_0301aa10();
      } while (*psVar1 != 1);
      *param_2 = DAT_0304e924;
      *pcVar4 = '\x01';
      return 1;
    }
    if (DAT_0304e910[10] == 0) {
      DAT_0304e910[10] = 1;
      FUN_03032cfc(4,0,1);
      FUN_03032cd0(0,0,1);
      return 2;
    }
    if (DAT_0304e910[10] != 1) {
      return 0;
    }
    return 2;
  case 0xc:
    FUN_03032cfc(4,0,1);
    FUN_03032cd0(0,0,1);
    break;
  case 0xe:
    *DAT_0304e928 = 0;
    FUN_03032cfc(0xb,0,1);
    FUN_03032cd0(param_2,0,1);
    iVar8 = *piVar10;
    iVar9 = DAT_0304e92c;
    while (iVar8 == 0) {
      FUN_03026218();
      FUN_03017c4c();
      func_0x0302a11c(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar10;
    }
    goto LAB_0304e872;
  case 0xf:
    *DAT_0304e930 = 0;
    FUN_03032cfc(0xd,0,1);
    FUN_03032cd0(0,0,1);
    iVar8 = *piVar5;
    iVar9 = DAT_0304e934;
    while (piVar10 = piVar5, iVar8 == 0) {
      FUN_03026218();
      FUN_03017c4c();
      func_0x0302a11c(1);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) break;
      iVar8 = *piVar5;
    }
LAB_0304e872:
    *piVar10 = 0;
    break;
  case 0x11:
    *param_2 = DAT_0304e910[3];
    break;
  default:
    return 0;
  }
  return 1;
}


