/**
 * FUN_030cdb0c @ 0x030cdb0c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030cdb0c(byte *param_1,int *param_2,undefined4 param_3,code *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char extraout_r1;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  char local_39 [5];
  byte *pbStack_34;
  int *local_30;
  undefined4 local_2c;
  code *pcStack_28;
  
  pcStack_28 = param_4;
  local_2c = param_3;
  pbStack_34 = param_1;
  iVar6 = 0;
  local_30 = param_2;
  do {
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar6;
    }
    if (bVar1 == 0x25) {
      uVar8 = 0;
      iVar9 = 0;
      pbVar5 = param_1;
      while( true ) {
        param_1 = pbVar5 + 1;
        uVar2 = 1 << (*param_1 - 0x20 & 0xff);
        if ((uVar2 & DAT_030cdc5c) == 0) break;
        uVar8 = uVar8 | uVar2;
        pbVar5 = param_1;
      }
      if (*param_1 == 0x2e) {
        param_1 = pbVar5 + 2;
        uVar8 = uVar8 | 4;
        if (*param_1 == 0x2a) {
          param_1 = pbVar5 + 3;
          iVar9 = *local_30;
          local_30 = local_30 + 1;
        }
        else {
          for (; *param_1 - 0x30 < 10; param_1 = param_1 + 1) {
            iVar9 = (uint)*param_1 + iVar9 * 10 + -0x30;
          }
        }
      }
      bVar1 = *param_1;
      if (bVar1 == 0) {
        return iVar6;
      }
      if ((bVar1 == 100) || (bVar1 == 0x69)) {
        iVar3 = *local_30;
        local_30 = local_30 + 1;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
          local_39[1] = 0x2d;
        }
        else if ((int)(uVar8 << 0x14) < 0) {
          local_39[1] = 0x2b;
        }
        else {
          if ((uVar8 & 1) == 0) goto LAB_030cdbc4;
          local_39[1] = 0x20;
        }
        iVar4 = 1;
      }
      else {
        if (bVar1 != 0x75) goto LAB_030cdb86;
        iVar3 = *local_30;
        local_30 = local_30 + 1;
LAB_030cdbc4:
        iVar4 = 0;
      }
      pcVar7 = local_39 + 1;
      while (iVar3 != 0) {
        iVar3 = FUN_030c0ff6(iVar3,10);
        pcVar7 = pcVar7 + -1;
        *pcVar7 = extraout_r1 + '0';
      }
      pcVar10 = local_39 + (1 - (int)pcVar7);
      if (-1 < (int)(uVar8 << 0x1d)) {
        iVar9 = 1;
      }
      if ((int)pcVar10 < iVar9) {
        iVar9 = iVar9 - (int)pcVar10;
      }
      else {
        iVar9 = 0;
      }
      for (iVar3 = 0; iVar3 < iVar4; iVar3 = iVar3 + 1) {
        (*param_4)(local_39[iVar3 + 1],local_2c);
        iVar6 = iVar6 + 1;
      }
      while (0 < iVar9) {
        (*param_4)(0x30,local_2c);
        iVar6 = iVar6 + 1;
        iVar9 = iVar9 + -1;
      }
      while (0 < (int)pcVar10) {
        (*param_4)(*pcVar7,local_2c);
        iVar6 = iVar6 + 1;
        pcVar7 = pcVar7 + 1;
        pcVar10 = pcVar10 + -1;
      }
    }
    else {
LAB_030cdb86:
      (*param_4)(bVar1,local_2c);
      iVar6 = iVar6 + 1;
    }
    param_1 = param_1 + 1;
  } while( true );
}


