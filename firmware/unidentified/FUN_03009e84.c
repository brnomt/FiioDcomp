/**
 * FUN_03009e84 @ 0x03009e84
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03009e84(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar3 = DAT_0300a130;
  uVar1 = *DAT_0300a130;
  uVar2 = DAT_0300a130[1];
  uVar4 = FUN_02ff2b38(1);
  uVar5 = FUN_02ff2b14(2);
  *puVar3 = *DAT_0300a144;
  puVar3[1] = *DAT_0300a148;
  iVar6 = FUN_02ff7414(0x26);
  if ((iVar6 != 0) || (iVar6 = FUN_02ff7414(0x2f), iVar6 != 0)) {
    FUN_02ff73b4(0x33);
    FUN_02ff2eda(1);
  }
  FUN_02ff73d0(0x33);
  FUN_02ff2b38(uVar4);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ff2b14(uVar5);
  return;
}


