/**
 * FUN_03019ef6 @ 0x03019ef6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03019ef6(void)

{
  ushort *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  
  iVar6 = FUN_03008820(0x16e);
  if (iVar6 == 0) {
    iVar6 = FUN_03008820(0x16b);
    puVar5 = DAT_0301a008;
    piVar4 = DAT_0301a004;
    puVar3 = DAT_0301a000;
    puVar2 = DAT_03019ffc;
    puVar1 = DAT_03019ff8;
    if (iVar6 == 0) {
      iVar6 = FUN_03008820(0x16d);
      if (iVar6 == 0) {
        return;
      }
      iVar6 = piVar4[1];
      if ((uint)(iVar6 - *piVar4) < (uint)piVar4[7]) {
        if (piVar4[3] == *puVar5) {
          FUN_03004580(*puVar2,iVar6 + (uint)*puVar1 & 0xffff,*puVar5 & 0xffff,1);
        }
        else {
          FUN_03004580(*puVar2,iVar6 + (uint)*puVar1 & 0xffff,*puVar3,1);
        }
      }
    }
    else {
      iVar6 = DAT_0301a004[1];
      if ((uint)(iVar6 - *DAT_0301a004) < (uint)DAT_0301a004[7]) {
        if (DAT_0301a004[3] == *DAT_0301a008) {
          FUN_03004580(*DAT_03019ffc,iVar6 + (uint)*DAT_03019ff8 & 0xffff,*DAT_0301a008 & 0xffff,1);
        }
        else {
          FUN_03004580(*DAT_03019ffc,iVar6 + (uint)*DAT_03019ff8 & 0xffff,*DAT_0301a000,1);
        }
        FUN_03008804(0x160);
        return;
      }
    }
  }
  FUN_03008804(0x163);
  return;
}


