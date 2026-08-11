/**
 * FUN_0301a9fe @ 0x0301a9fe
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301a9fe(void)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = DAT_0301ace0;
  if (*(short *)(DAT_0301ace0 + 4) != 3 && *(short *)(DAT_0301ace0 + 4) != 1) {
    return 0;
  }
  FUN_03001e04(*(undefined1 *)(DAT_0301ace4 + 0x12));
  FUN_0301db2a();
  FUN_0301b10a();
  FUN_0301ddf2();
  bVar1 = *(byte *)(iVar2 + 1);
  uVar3 = (ushort)bVar1;
  if (bVar1 != 3) {
    uVar3 = 0;
  }
  *(ushort *)(iVar2 + 4) = uVar3;
  *DAT_0301ace8 = 2;
  FUN_03008eb4(0x23);
  *DAT_0301acf0 = *DAT_0301acec;
  return 1;
}


