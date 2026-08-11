/**
 * FUN_03024878 @ 0x03024878
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03024878(char param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [4];
  byte bStack_24;
  byte bStack_22;
  byte bStack_21;
  
  iVar5 = (int)param_1;
  iVar1 = FUN_02ffcece(10,0);
  if (iVar1 == 0) {
    uVar2 = FUN_02ffce8c(iVar5);
    iVar3 = FUN_02ffce8c(iVar5);
    iVar1 = DAT_03024a2c;
    if ((uint)(iVar3 + *DAT_03024a28) < uVar2) {
      return 0xffffffff;
    }
    uVar2 = FUN_02ffc9d6(auStack_28,10,iVar5);
    if (9 < uVar2) {
      FUN_02ff8972(auStack_30,auStack_28,4);
      if (*(char *)(iVar1 + 3) == '\x03') {
        iVar1 = (uint)bStack_24 * 0x1000000 + (uint)bStack_22 * 0x100 + (uint)bStack_21;
      }
      else {
        iVar1 = (uint)bStack_21 + (bStack_22 & 1) * 0x80;
      }
      if (0 < iVar1) {
        uVar4 = FUN_02ff89ce(auStack_30,&DAT_03024a30,4);
        return uVar4;
      }
    }
  }
  return 0xffffffff;
}


