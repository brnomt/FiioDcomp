/**
 * FUN_0300862e @ 0x0300862e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300862e(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_b0 [128];
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar2 = DAT_03008980;
  uVar4 = *DAT_0300897c;
  uVar1 = *DAT_03008980;
  local_2c = FUN_02ff2b38(1);
  local_30 = FUN_02ff2b14(2);
  iVar5 = FUN_02ff73d0(0x97);
  if ((iVar5 == 1) || (iVar5 = FUN_02ff73d0(0x26), iVar5 == 1)) {
    *puVar2 = *DAT_03008984;
    FUN_02ff33e6(0x7a);
    FUN_02ff2be4(0,3,0x140,0x10,0,9);
    *puVar2 = 0xffff;
    FUN_02ff73b4(0x98);
    FUN_02ff73b4(0x21);
    FUN_02ff2eda(1);
  }
  FUN_02ff2eda(0);
  iVar5 = FUN_02ff73d0(0x98);
  if (iVar5 == 1) {
    FUN_02ff407e(0,0x41,0xf0,0x115);
    uVar3 = DAT_03008988;
    FUN_02ff3130(0,0x41,0x140,1,0x10,DAT_03008988);
    FUN_02ff3130(0,0x6b,0x140,1,0x10,uVar3);
    FUN_02ff3130(0,0x95,0x140,1,0x10,uVar3);
    FUN_02ff3130(0,0xbf,0x140,1,0x10,uVar3);
    FUN_02ff3130(0,0xe9,0x140,1,0x10,uVar3);
    FUN_02ff3130(0,0x113,0x140,1,0x10,uVar3);
    uVar8 = (uVar4 / 5) * 5 & 0xffff;
    uVar6 = 0;
    puVar7 = (undefined2 *)(*DAT_0300898c + uVar8 * 2 + 0x14);
    do {
      uVar9 = uVar6 + uVar8;
      FUN_0300856a(uVar9 & 0xffff,*puVar7,auStack_b0);
      if ((uVar9 == uVar4) && (iVar5 = FUN_02ff73d0(0xce), iVar5 != 0)) {
        *puVar2 = 0xf800;
      }
      else {
        *puVar2 = 0xffff;
      }
      FUN_02ff1ed8(0x1c,uVar6 * 0x18 + 0x1c,auStack_b0);
      uVar6 = uVar6 + 1 & 0xffff;
      puVar7 = puVar7 + 1;
      *puVar2 = 0xffff;
    } while (uVar6 < 5);
    FUN_02ff73b4(0x9b);
    FUN_02ff73b4(0x1a9);
  }
  iVar5 = FUN_02ff73d0(0x9b);
  if (iVar5 != 0) {
    uVar4 = *DAT_0300897c + 1;
    if (0x1d < uVar4) {
      uVar4 = 0x1e;
    }
    FUN_02ff2d04(uVar4);
  }
  FUN_02ff2b38(local_2c);
  *puVar2 = uVar1;
  FUN_02ff2b14(local_30);
  return;
}


