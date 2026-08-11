/**
 * FUN_03003f78 @ 0x03003f78
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03003f78(int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 uVar7;
  
  puVar3 = DAT_030040b8;
  puVar2 = DAT_030040b4;
  *DAT_030040b4 = 0;
  puVar4 = DAT_030040bc;
  *puVar3 = 0xffffffff;
  *puVar4 = 1;
  puVar4 = DAT_030040d4;
  *DAT_030040c0 = 0;
  *DAT_030040c4 = 0;
  *DAT_030040c8 = 0;
  *DAT_030040cc = 0;
  *DAT_030040d0 = 0xffffffff;
  puVar5 = DAT_030040d8;
  *(undefined4 *)(puVar4 + 4) = 0;
  uVar7 = DAT_030040e0;
  *puVar5 = 0;
  *DAT_030040dc = 0;
  sVar1 = *(short *)(param_1 + 2);
  iVar6 = FUN_02fe1e70(*DAT_030040e4,uVar7);
  if (iVar6 != 1 && sVar1 != 0) {
    *DAT_030040e8 = sVar1;
  }
  *(undefined4 *)(puVar2 + 0x1c) = 10;
  uVar7 = FUN_02ff22d6();
  *(undefined4 *)(puVar2 + 0x18) = uVar7;
  FUN_02ff2de4(0x39);
  FUN_02ff2e26(0x53);
  FUN_02ff2e26(0x55);
  FUN_02ff2e26(0x17c);
  FUN_02ff2e26(0x1da);
  *puVar4 = 0;
  FUN_02ff2e26(0x82);
  FUN_0300417c(param_1);
  puVar5 = DAT_030040ec;
  DAT_030040ec[1] = 0;
  puVar5[3] = 0;
  *puVar5 = 0;
  puVar5[2] = 0;
  *DAT_030040f0 = 0;
  FUN_030111fe(1);
  FUN_02fef94c(0x66,DAT_030040f4);
  FUN_02fef922(0x66,DAT_030040f8,0x18);
  FUN_02fef922(0x67,DAT_030040fc,0x18);
  FUN_02ff2e26(0x1b6);
  FUN_02ff2e26(0x1b5);
  FUN_02ff2e26(0x11d);
  *DAT_03004100 = 8000;
  FUN_02ff3430(0x12,7);
  *(undefined2 *)(puVar4 + 2) = 0xffff;
  return;
}


