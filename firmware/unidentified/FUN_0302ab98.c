/**
 * FUN_0302ab98 @ 0x0302ab98
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0302ab98(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  uVar5 = FUN_03012368(0,1);
  puVar6 = (undefined4 *)func_0x03012394(0,1);
  iVar7 = DAT_0302ac84;
  *(undefined4 *)(DAT_0302ac84 + 0x58) = uVar5;
  *(undefined4 **)(iVar7 + 0x5c) = puVar6;
  FUN_03012358(0,2);
  iVar4 = DAT_0302b0e0;
  piVar3 = DAT_0302acf0;
  iVar2 = DAT_0302acec;
  iVar1 = DAT_0302ace8;
  iVar7 = DAT_0302ac84;
  switch(uVar5) {
  case 2:
    *(undefined4 *)(DAT_0302ac84 + 0x78) = 1;
    *(undefined4 *)(iVar7 + 0x68) = 1;
    return;
  case 3:
    uVar5 = puVar6[1];
    uVar9 = puVar6[2];
    uVar10 = puVar6[3];
    *(undefined4 *)(DAT_0302ace8 + 0x318) = *puVar6;
    *(undefined4 *)(iVar1 + 0x31c) = uVar5;
    *(undefined4 *)(iVar1 + 800) = uVar9;
    *(undefined4 *)(iVar1 + 0x324) = uVar10;
    uVar5 = puVar6[5];
    uVar9 = puVar6[6];
    uVar10 = puVar6[7];
    *(undefined4 *)(iVar1 + 0x328) = puVar6[4];
    *(undefined4 *)(iVar1 + 0x32c) = uVar5;
    *(undefined4 *)(iVar1 + 0x330) = uVar9;
    *(undefined4 *)(iVar1 + 0x334) = uVar10;
    uVar5 = puVar6[10];
    uVar9 = puVar6[0xb];
    *(undefined4 *)(iVar1 + 0x338) = puVar6[8];
    iVar7 = DAT_0302acec;
    *(undefined4 *)(iVar1 + 0x340) = uVar5;
    *(undefined4 *)(iVar1 + 0x344) = uVar9;
    *(undefined4 *)(iVar7 + 0x24) = 1;
    *(undefined4 *)(iVar7 + -0x6a0) = 0;
    *(undefined4 *)(iVar7 + -0x6b0) = 1;
    return;
  case 4:
  case 7:
  case 9:
  case 0xb:
  case 0xd:
  case 0x10:
    return;
  case 5:
    uVar5 = puVar6[1];
    uVar9 = puVar6[2];
    uVar10 = puVar6[3];
    *(undefined4 *)(DAT_0302ace8 + 0x318) = *puVar6;
    *(undefined4 *)(iVar1 + 0x31c) = uVar5;
    *(undefined4 *)(iVar1 + 800) = uVar9;
    *(undefined4 *)(iVar1 + 0x324) = uVar10;
    uVar5 = puVar6[5];
    uVar9 = puVar6[6];
    uVar10 = puVar6[7];
    *(undefined4 *)(iVar1 + 0x328) = puVar6[4];
    *(undefined4 *)(iVar1 + 0x32c) = uVar5;
    *(undefined4 *)(iVar1 + 0x330) = uVar9;
    *(undefined4 *)(iVar1 + 0x334) = uVar10;
    uVar5 = puVar6[8];
    *(undefined4 *)(iVar1 + 0x344) = puVar6[0xb];
    *(undefined4 *)(iVar1 + 0x338) = uVar5;
    *(undefined4 *)(iVar1 + 0x33c) = 1;
    *(undefined4 *)(iVar1 + 0x340) = 0;
    if (*piVar3 == 1) {
      FUN_0300bb32();
    }
    iVar7 = DAT_0302ac84;
    *piVar3 = 0;
    *(undefined4 *)(iVar7 + 0x60) = 1;
    return;
  case 6:
    *(undefined4 *)(DAT_0302acec + 0x24) = 1;
    *(undefined4 *)(iVar2 + 0x2c) = 1;
    if (*piVar3 == 1) {
      FUN_0300bb32();
    }
    *piVar3 = 0;
    *(undefined4 *)(DAT_0302ac84 + 0x60) = 1;
    return;
  case 8:
    uVar5 = puVar6[1];
    uVar9 = puVar6[2];
    uVar10 = puVar6[3];
    puVar8 = (undefined4 *)(DAT_0302b0e0 + 0x338);
    *(undefined4 *)(DAT_0302b0e0 + 0x318) = *puVar6;
    *(undefined4 *)(iVar4 + 0x31c) = uVar5;
    *(undefined4 *)(iVar4 + 800) = uVar9;
    *(undefined4 *)(iVar4 + 0x324) = uVar10;
    uVar5 = puVar6[5];
    uVar9 = puVar6[6];
    uVar10 = puVar6[7];
    *(undefined4 *)(iVar4 + 0x328) = puVar6[4];
    *(undefined4 *)(iVar4 + 0x32c) = uVar5;
    *(undefined4 *)(iVar4 + 0x330) = uVar9;
    *(undefined4 *)(iVar4 + 0x334) = uVar10;
    uVar5 = puVar6[9];
    uVar9 = puVar6[10];
    uVar10 = puVar6[0xb];
    *puVar8 = puVar6[8];
    *(undefined4 *)(iVar4 + 0x33c) = uVar5;
    *(undefined4 *)(iVar4 + 0x340) = uVar9;
    *(undefined4 *)(iVar4 + 0x344) = uVar10;
    *(undefined4 *)(DAT_0302b0dc + 0x6c) = 1;
    return;
  case 10:
    uVar5 = puVar6[1];
    uVar9 = puVar6[2];
    uVar10 = puVar6[3];
    puVar8 = (undefined4 *)(DAT_0302b0e0 + 0x338);
    *(undefined4 *)(DAT_0302b0e0 + 0x318) = *puVar6;
    *(undefined4 *)(iVar4 + 0x31c) = uVar5;
    *(undefined4 *)(iVar4 + 800) = uVar9;
    *(undefined4 *)(iVar4 + 0x324) = uVar10;
    uVar5 = puVar6[5];
    uVar9 = puVar6[6];
    uVar10 = puVar6[7];
    *(undefined4 *)(iVar4 + 0x328) = puVar6[4];
    *(undefined4 *)(iVar4 + 0x32c) = uVar5;
    *(undefined4 *)(iVar4 + 0x330) = uVar9;
    *(undefined4 *)(iVar4 + 0x334) = uVar10;
    uVar5 = puVar6[9];
    uVar9 = puVar6[10];
    uVar10 = puVar6[0xb];
    *puVar8 = puVar6[8];
    *(undefined4 *)(iVar4 + 0x33c) = uVar5;
    *(undefined4 *)(iVar4 + 0x340) = uVar9;
    *(undefined4 *)(iVar4 + 0x344) = uVar10;
    *(undefined4 *)(DAT_0302b0dc + 0x70) = 1;
    return;
  case 0xc:
    *(undefined4 *)(DAT_0302b0dc + 100) = 1;
    return;
  case 0xe:
    *(undefined4 *)(DAT_0302b0dc + 0x74) = 1;
    return;
  case 0xf:
    *(undefined4 **)(DAT_0302b0dc + 0x8c) = puVar6;
    iVar7 = DAT_0302b0e4 + puVar6[2] * 0x27e;
    *(undefined4 *)(iVar7 + 0x20) = *puVar6;
    *(undefined4 *)(iVar7 + 0x18) = puVar6[1];
    func_0x030124a0(0x10,0,2);
    break;
  case 0x11:
    iVar7 = DAT_0302b0e4 + (int)puVar6 * 0x27e;
    puVar6 = *(undefined4 **)(DAT_0302b0dc + 0x8c);
    puVar6[1] = *(undefined4 *)(iVar7 + 0x18);
    *puVar6 = *(undefined4 *)(iVar7 + 0x20);
    func_0x030124a0(0x12,0,2);
    break;
  default:
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


