/**
 * FUN_030014c8 @ 0x030014c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030014c8(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  piVar1 = DAT_03001664;
  uVar3 = 0;
  do {
    func_0x02fdcf54(piVar1 + uVar3 * 0x43 + 3,0x100);
    uVar4 = uVar3 + 1;
    *(undefined2 *)((int)piVar1 + uVar3 * 0x10c + 10) = 0xffff;
    uVar3 = uVar4;
  } while (uVar4 < 6);
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1;
    piVar1[uVar3 * 0x43 + 1] = (int)(piVar1 + uVar3 * 0x43 + 0x43);
    uVar3 = uVar4;
  } while (uVar4 < 5);
  uVar3 = 1;
  do {
    uVar4 = uVar3 + 1;
    piVar1[uVar3 * 0x43] = (int)(piVar1 + uVar3 * 0x43 + -0x43);
    iVar2 = DAT_03001668;
    uVar3 = uVar4;
  } while (uVar4 < 6);
  *piVar1 = DAT_03001668;
  *(int **)(iVar2 + 4) = piVar1;
  *(undefined2 *)(iVar2 + 0x124) = 0;
  *(int **)(iVar2 + 0x128) = piVar1;
  *(undefined2 *)(iVar2 + 0x118) = 0;
  *(undefined2 *)(iVar2 + 0x11a) = 0;
  *(undefined2 *)(iVar2 + 0x11c) = 0;
  *(undefined2 *)(iVar2 + 0x11e) = 0;
  *(undefined2 *)(iVar2 + 0x116) = 0;
  *(undefined2 *)(iVar2 + 0x10c) = 0;
  *(undefined2 *)(iVar2 + 0x122) = 0;
  *(undefined2 *)(iVar2 + 0x120) = 0;
  *(undefined2 *)(iVar2 + 0x10e) = 0;
  *(undefined2 *)(iVar2 + 0x110) = 0;
  *(undefined2 *)(iVar2 + 0x112) = 0;
  *(undefined2 *)(iVar2 + 0x114) = 0;
  return;
}


