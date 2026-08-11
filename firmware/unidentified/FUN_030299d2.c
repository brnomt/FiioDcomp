/**
 * FUN_030299d2 @ 0x030299d2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030299d2(uint param_1,uint param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint *puVar3;
  uint uVar4;
  uint unaff_r8;
  uint unaff_r9;
  
  *DAT_03029af4 = 0;
  puVar2 = DAT_03029aec;
  if (param_1 <= param_2) {
    unaff_r9 = (uint)DAT_03029aec[1];
    unaff_r8 = (uint)DAT_03029aec[param_1];
  }
  if (0x2000 < param_1) {
    param_1 = 0x2000;
  }
  uVar4 = 0;
  if (param_1 != 0) {
    do {
      puVar2[uVar4 + 1] = (ushort)uVar4;
      FUN_030059bc();
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_1);
  }
  *puVar2 = 0;
  puVar2[0x2002] = 0;
  puVar2[0x2001] = (ushort)param_1;
  puVar3 = DAT_03029af0;
  if (param_1 <= param_2) {
    if (param_1 == 1) {
      param_2 = 0;
    }
    else if (param_1 == 2) {
      param_2 = 1 - unaff_r8;
    }
    else {
      do {
        param_2 = *puVar3 - param_1 * (*puVar3 / param_1);
        FUN_030059bc();
      } while (param_2 == unaff_r9 || param_2 == unaff_r8);
    }
  }
  uVar1 = puVar2[param_2 + 1];
  puVar2[param_2 + 1] = puVar2[*puVar2 + 1];
  puVar2[*puVar2 + 1] = uVar1;
  uVar1 = *puVar2;
  *puVar2 = uVar1 + 1;
  puVar2[0x2002] = uVar1;
  return;
}


