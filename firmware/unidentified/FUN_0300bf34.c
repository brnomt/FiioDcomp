/**
 * FUN_0300bf34 @ 0x0300bf34
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300bf34(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  puVar3 = DAT_0300c0f0;
  uVar1 = *DAT_0300c0f0;
  uVar2 = DAT_0300c0f0[1];
  uVar6 = FUN_02ff5e18(1);
  uVar7 = FUN_02ff5df4(2);
  puVar4 = DAT_0300c0f4;
  *puVar3 = 0xffff;
  puVar3[1] = *puVar4;
  iVar8 = FUN_02ffa6f4(0x26);
  iVar5 = DAT_0300c100;
  if ((iVar8 != 0) || (iVar8 = FUN_02ffa6b0(0x143), iVar8 != 0)) {
    FUN_02ffa694(0x146);
    FUN_02ffa694(0x147);
    FUN_02ffa694(0x149);
    FUN_02ffa694(0x21);
    *(undefined1 *)(iVar5 + 5) = 0;
  }
  iVar8 = FUN_02ffa6b0(0x146);
  if (iVar8 == 1) {
    FUN_02ff66c6(0x7a);
  }
  iVar8 = FUN_02ffa6b0(0x147);
  if (iVar8 == 1) {
    *puVar3 = 0xffff;
    puVar3[1] = *puVar4;
    uVar9 = FUN_02ff5df4(2);
    *puVar3 = *DAT_0300c108;
    if (*(char *)(iVar5 + 2) == '\x01') {
      uVar10 = 0x17a;
    }
    else if (*(char *)(iVar5 + 2) == '\x02') {
      uVar10 = 0x17b;
    }
    else {
      uVar10 = 0x17c;
    }
    FUN_02ff5ec4(0,3,0x140,0x10,0,uVar10);
    *puVar3 = 0xffff;
    FUN_02ff5df4(uVar9);
    FUN_02ff61ba(1);
  }
  iVar8 = FUN_02ffa6b0(0x149);
  if (iVar8 == 1) {
    FUN_0300bc92(*(undefined1 *)(iVar5 + 3));
  }
  FUN_02ff61ba(0);
  FUN_02ff5e18(uVar6);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ff5df4(uVar7);
  return;
}


