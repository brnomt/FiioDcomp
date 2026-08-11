/**
 * FUN_03008f3e @ 0x03008f3e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03008f3e(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(byte *)(DAT_03009068 + 0x12) < *(byte *)(DAT_03009068 + 0x1e)) {
    *(byte *)(DAT_03009068 + 0x12) = *(byte *)(DAT_03009068 + 0x12) + 1;
  }
  puVar1 = DAT_03009054;
  iVar2 = FUN_02fe6440(*DAT_03009054,DAT_03009058);
  if (iVar2 == 1) {
    FUN_030147fc(0xff,0);
  }
  iVar2 = FUN_02fe6440(*puVar1,DAT_0300905c);
  if (iVar2 == 1) {
    FUN_03021672(0xb6,0);
  }
  FUN_02ff73b4(0x33);
  return 1;
}


