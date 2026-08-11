/**
 * FUN_03001348 @ 0x03001348
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001348(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = DAT_0300164c;
  piVar1 = DAT_03001644;
  uVar5 = *(uint *)(param_1 + 0xc);
  iVar6 = ((uVar5 & 0xfffffff) >> 5) + *DAT_03001644 + 0x44000;
  FUN_02ff0732(DAT_0300164c,iVar6,1,DAT_03001648);
  iVar2 = DAT_03001648;
  *(undefined4 *)(DAT_03001648 + (uVar5 & 0x1f) * 0x10 + 0xc) = 3;
  FUN_02ff077a(uVar3,iVar6,1,iVar2);
  FUN_02ff0732(uVar3,*piVar1 + 0x54000,4,iVar2);
  uVar5 = *(uint *)(param_1 + 4);
  if (uVar5 < *(uint *)(param_1 + 8)) {
    do {
      *(undefined2 *)(iVar2 + uVar5 * 2 + -2) = *(undefined2 *)(iVar2 + uVar5 * 2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
  FUN_02ff077a(uVar3,*piVar1 + 0x54000,4,DAT_03001648);
  puVar4 = DAT_03001650;
  *DAT_03001650 = 0xffffffff;
  puVar4[1] = 0xffffffff;
  puVar4[2] = 0xffffffff;
  *(short *)(DAT_03001624 + 0x3a) = *(short *)(DAT_03001624 + 0x3a) + -1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  FUN_02ff57d0(1);
  return;
}


