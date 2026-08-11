/**
 * FUN_03003f92 @ 0x03003f92
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03003f92(undefined4 *param_1,undefined4 param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 unaff_r4;
  int unaff_r7;
  int unaff_r8;
  
  puVar3 = DAT_030040d4;
  *param_1 = unaff_r4;
  *DAT_030040c4 = unaff_r4;
  *DAT_030040c8 = unaff_r4;
  *DAT_030040cc = unaff_r4;
  *DAT_030040d0 = param_2;
  puVar4 = DAT_030040d8;
  *(undefined4 *)(puVar3 + 4) = unaff_r4;
  uVar6 = DAT_030040e0;
  uVar2 = (undefined2)unaff_r4;
  *puVar4 = uVar2;
  *DAT_030040dc = uVar2;
  sVar1 = *(short *)(unaff_r8 + 2);
  iVar5 = FUN_02fe1e70(*DAT_030040e4,uVar6);
  if (iVar5 != 1 && sVar1 != 0) {
    *DAT_030040e8 = sVar1;
  }
  *(undefined4 *)(unaff_r7 + 0x1c) = 10;
  uVar6 = FUN_02ff22d6();
  *(undefined4 *)(unaff_r7 + 0x18) = uVar6;
  FUN_02ff2de4(0x39);
  FUN_02ff2e26(0x53);
  FUN_02ff2e26(0x55);
  FUN_02ff2e26(0x17c);
  FUN_02ff2e26(0x1da);
  *puVar3 = (char)unaff_r4;
  FUN_02ff2e26(0x82);
  FUN_0300417c();
  puVar4 = DAT_030040ec;
  DAT_030040ec[1] = uVar2;
  puVar4[3] = uVar2;
  *puVar4 = uVar2;
  puVar4[2] = uVar2;
  *DAT_030040f0 = (char)unaff_r4;
  FUN_030111fe(1);
  FUN_02fef94c(0x66,DAT_030040f4);
  FUN_02fef922(0x66,DAT_030040f8,0x18);
  FUN_02fef922(0x67,DAT_030040fc,0x18);
  FUN_02ff2e26(0x1b6);
  FUN_02ff2e26(0x1b5);
  FUN_02ff2e26(0x11d);
  *DAT_03004100 = 8000;
  FUN_02ff3430(0x12,7);
  *(undefined2 *)(puVar3 + 2) = 0xffff;
  return;
}


