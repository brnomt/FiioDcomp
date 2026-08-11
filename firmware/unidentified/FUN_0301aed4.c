/**
 * FUN_0301aed4 @ 0x0301aed4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301aed4(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar1 = DAT_0301af48;
  *(undefined1 *)(DAT_0301af48 + 2) = 1;
  uVar4 = FUN_02ffabf4(*(undefined2 *)(param_1 + 2),param_1 + 0x34,*(undefined4 *)(param_1 + 0x10),3
                      );
  *(undefined2 *)(param_1 + 2) = uVar4;
  uVar5 = FUN_02ff9490(param_1 + 0x9a);
  uVar5 = FUN_02ffc110(*(undefined2 *)(param_1 + 2),uVar5,*(undefined4 *)(param_1 + 0x10),3);
  iVar2 = DAT_0301af4c;
  *(short *)(param_1 + 2) = (short)uVar5;
  *puVar1 = uVar5;
  iVar3 = DAT_0301af50;
  uVar6 = *(undefined4 *)(iVar2 + 0x14);
  puVar1[1] = uVar6;
  *(short *)(iVar3 + 0x1b1) = (short)uVar5;
  *(undefined4 *)(iVar3 + 0x1b3) = uVar6;
  return;
}


