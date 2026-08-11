/**
 * FUN_03009754 @ 0x03009754
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03009754(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_02ff73f6(0xdf);
  FUN_02ff73f6(0xe0);
  FUN_02ff73b4(0x82);
  puVar1 = DAT_03009808;
  iVar2 = FUN_02fe6440(*DAT_03009808,DAT_03009804);
  if (iVar2 == 1) {
    FUN_02fe6398(puVar1,DAT_03009804);
  }
  FUN_02fe15f0(2,2,0);
  FUN_02fe53f0(2,2,1);
  FUN_02fe542a(2,2,1);
  if ((param_1 != 0) && (*(short *)(param_1 + 2) == 1)) {
    FUN_02ff73b4(0xa7);
  }
  FUN_02ff0b46();
  iVar2 = FUN_02fe6440(*puVar1,DAT_03009804);
  if (iVar2 == 1) {
    FUN_02fe6398(DAT_03009808,DAT_03009804);
  }
  FUN_0300981c(0);
  FUN_02ff73b4(0x82);
  iVar2 = FUN_02fe6440(*puVar1,DAT_0300980c);
  if (iVar2 == 1) {
    *DAT_03009810 = 1;
  }
  else {
    *DAT_03009810 = 0;
  }
  iVar2 = FUN_02ff73d0(0xaa);
  if (iVar2 == 0) {
    if (*DAT_03009814 != 0) {
      *DAT_03009814 = 0;
    }
    *DAT_03009818 = 0;
    return;
  }
  return;
}


