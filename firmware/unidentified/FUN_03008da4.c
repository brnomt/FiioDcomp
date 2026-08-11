/**
 * FUN_03008da4 @ 0x03008da4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03008da4(void)

{
  ushort *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 unaff_r4;
  undefined4 *unaff_r5;
  undefined2 unaff_r6;
  char in_ZR;
  
  if (in_ZR != '\0') {
    FUN_02fe6398(DAT_03009054,DAT_03009058);
  }
  iVar3 = FUN_02fe6440(*unaff_r5,DAT_0300905c);
  if (iVar3 == 0) {
    FUN_0300981c(0);
  }
  *DAT_03009060 = (char)unaff_r4;
  FUN_02ff73b4(0xa2);
  piVar2 = DAT_03009048;
  *(undefined2 *)(*DAT_03009048 + 0x52) = 0xff;
  FUN_02fe62c8(DAT_03009064);
  FUN_02ff73b4(0x82);
  FUN_02ff73b4(0x8b);
  iVar3 = FUN_03021a24();
  puVar1 = DAT_03009044;
  if (iVar3 != 1) {
    puVar6 = (undefined2 *)*piVar2;
    puVar6[5] = unaff_r6;
    *puVar6 = unaff_r6;
    puVar6[9] = unaff_r4;
    *(uint *)(puVar6 + 6) = (uint)*puVar1;
    uVar4 = 0;
    do {
      uVar5 = uVar4 + 1 & 0xff;
      puVar6[uVar4 + 10] = unaff_r4;
      uVar4 = uVar5;
    } while (uVar5 < 0x1e);
    FUN_02ff73b4(0x92);
    FUN_02ff73b4(0xaf);
    return;
  }
  return;
}


