/**
 * FUN_0309da8e @ 0x0309da8e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0309da8e(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 *puVar8;
  
  FUN_030a0842();
  iVar2 = DAT_0309dbf0;
  *(uint *)(DAT_0309dbf0 + 0x848) = (uint)*(byte *)(param_1 + 0x228);
  *(undefined4 *)(iVar2 + 0x844) = *(undefined4 *)(param_1 + 0x224);
  *(undefined4 *)(iVar2 + 0x84c) = DAT_0309dbf4;
  uVar4 = (uint)*(ushort *)(param_1 + 0x230);
  if (uVar4 == 2) {
    *(undefined4 *)(DAT_0309dbf0 + 0x834) = 0x20;
    *(undefined4 *)(DAT_0309dbf0 + 0x8f8) = *(undefined4 *)(param_1 + 0x218);
    puVar3 = DAT_030a0814;
    iVar2 = DAT_0309dbf0;
    uVar1 = *(ushort *)(param_1 + 0x22c);
    uVar7 = (uint)*(ushort *)(param_1 + 0x22a);
    puVar8 = (undefined4 *)(DAT_0309dbf0 + 0x848);
    iVar5 = *(int *)(DAT_0309dbf0 + 0x848);
    uVar4 = (uint)uVar1;
    if (*(int *)(DAT_0309dbf0 + 0x834) == 0x20) {
      uVar4 = (int)((iVar5 * -7 + uVar7) * 2) / iVar5 + 2;
    }
    *(undefined4 **)(DAT_0309dbf0 + 0x91c) = DAT_030a0814;
    FUN_0309f6c4(puVar3,iVar5 * uVar4 * 3 + uVar7 + 0x28,(uint)uVar1,extraout_r3,unaff_r4);
    puVar3[8] = puVar3 + 9;
    puVar3[7] = (int)puVar3 + uVar7 + 0x24;
    uVar6 = *puVar8;
    puVar3[2] = uVar4;
    *puVar3 = uVar6;
    puVar3[1] = uVar7;
    if (*(int *)(iVar2 + 0x834) == 0x20) {
      puVar3[6] = 0;
    }
    return 0;
  }
  if (uVar4 == 1) {
    *(undefined4 *)(DAT_0309dbf0 + 0x834) = 0x20;
    uVar4 = *(uint *)(param_1 + 0x218);
    *(uint *)(DAT_0309dbf0 + 0x8f8) = uVar4;
    return uVar4;
  }
  return uVar4;
}


