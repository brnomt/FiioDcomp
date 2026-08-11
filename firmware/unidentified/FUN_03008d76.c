/**
 * FUN_03008d76 @ 0x03008d76
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03008d76(void)

{
  ushort *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined2 *puVar8;
  
  puVar3 = DAT_03009054;
  puVar8 = DAT_03009050;
  uVar4 = *DAT_03009054;
  switch(*DAT_03009040) {
  case 0:
    iVar7 = FUN_02fe6440(uVar4,DAT_0300905c);
    if (iVar7 == 1) {
      FUN_03009ee4();
      *puVar8 = 1;
      FUN_02fe62c8(DAT_03009064);
      FUN_02ff73f6(0x21);
      FUN_02ff73b4(0x9c);
      return;
    }
    break;
  case 1:
    iVar7 = FUN_02fe6440(uVar4,DAT_0300905c);
    if (iVar7 == 1) {
      FUN_03009ee4();
      *puVar8 = 0;
      FUN_02fe62c8(DAT_03009064);
      FUN_02ff73f6(0x21);
      FUN_02ff73b4(0x9c);
      return;
    }
    break;
  case 2:
    iVar7 = FUN_02fe6440(uVar4,DAT_0300905c);
    if (iVar7 == 1) {
      FUN_03009ee4();
      *puVar8 = 2;
      FUN_02fe62c8(DAT_03009064);
      FUN_02ff73f6(0x21);
      FUN_02ff73b4(0x9c);
      return;
    }
    break;
  case 3:
    iVar7 = FUN_02fe6440(uVar4,DAT_03009058);
    if (iVar7 == 1) {
      FUN_02fe6398(DAT_03009054,DAT_03009058);
    }
    iVar7 = FUN_02fe6440(*puVar3,DAT_0300905c);
    if (iVar7 == 0) {
      FUN_0300981c(0);
    }
    *DAT_03009060 = 0;
    FUN_02ff73b4(0xa2);
    piVar2 = DAT_03009048;
    *(undefined2 *)(*DAT_03009048 + 0x52) = 0xff;
    FUN_02fe62c8(DAT_03009064);
    FUN_02ff73b4(0x82);
    FUN_02ff73b4(0x8b);
    iVar7 = FUN_03021a24();
    puVar1 = DAT_03009044;
    if (iVar7 == 1) {
      return;
    }
    puVar8 = (undefined2 *)*piVar2;
    puVar8[5] = 1;
    *puVar8 = 1;
    puVar8[9] = 0;
    *(uint *)(puVar8 + 6) = (uint)*puVar1;
    uVar5 = 0;
    do {
      uVar6 = uVar5 + 1 & 0xff;
      puVar8[uVar5 + 10] = 0;
      uVar5 = uVar6;
    } while (uVar6 < 0x1e);
    FUN_02ff73b4(0x92);
    FUN_02ff73b4(0xaf);
    return;
  case 4:
    FUN_02fe62c8(DAT_03009064);
    FUN_02ff73b4(0x9e);
    return;
  case 5:
    FUN_02fe62c8(DAT_03009064);
    FUN_02ff73f6(0x21);
    FUN_02ff73b4(0xaa);
    iVar7 = FUN_02fe6440(*puVar3,DAT_0300905c);
    if (iVar7 == 1) {
      FUN_02ff73b4(0xa3);
      return;
    }
    break;
  case 6:
    FUN_02fe62c8(DAT_03009064);
    FUN_02ff73f6(0x21);
    FUN_02ff73b4(0xaa);
    FUN_02ff73b4(0xa4);
    return;
  default:
    return;
  }
  FUN_02ff73b4(0xa6);
  return;
}


