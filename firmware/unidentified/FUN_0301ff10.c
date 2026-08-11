/**
 * FUN_0301ff10 @ 0x0301ff10
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301ff10(int param_1,int param_2,short *param_3,short param_4,short *param_5,int param_6)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  short sVar6;
  
  psVar5 = (short *)(param_1 + param_2 * 0x1e);
  sVar6 = *param_3;
  sVar2 = *param_5;
  cVar1 = *(char *)(param_1 + param_2 + 0xb4);
  *param_3 = sVar6 + sVar2;
  param_4 = param_4 * (sVar6 + sVar2);
  *psVar5 = param_4;
  if ((param_6 == 0) || (0x22 < param_6)) {
    if (param_4 < -0x800) {
      param_4 = (short)DAT_0301ffe0;
    }
    else if (0x7ff < param_4) {
      param_4 = 0x7ff;
    }
    *psVar5 = param_4;
  }
  if (cVar1 == '\x01') {
    uVar3 = 1;
    do {
      sVar6 = param_3[uVar3];
      sVar2 = param_5[uVar3];
      param_3[uVar3] = sVar6 + sVar2;
      psVar5[uVar3] = sVar6 + sVar2;
      uVar4 = uVar3 + 1;
      psVar5[uVar3 + 7] = param_3[uVar3 * 8];
      uVar3 = uVar4;
    } while (uVar4 < 8);
    return;
  }
  uVar3 = 1;
  if (cVar1 != '\x02') {
    do {
      psVar5[uVar3] = param_3[uVar3];
      uVar4 = uVar3 + 1;
      psVar5[uVar3 + 7] = param_3[uVar3 * 8];
      uVar3 = uVar4;
    } while (uVar4 < 8);
    return;
  }
  do {
    sVar6 = param_3[uVar3 * 8] + param_5[uVar3];
    param_3[uVar3 * 8] = sVar6;
    psVar5[uVar3 + 7] = sVar6;
    psVar5[uVar3] = param_3[uVar3];
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  return;
}


