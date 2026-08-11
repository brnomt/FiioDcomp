/**
 * FUN_030a513e @ 0x030a513e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a513e(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = DAT_030a5358;
  iVar2 = *(int *)(param_1 + 0x848);
  if (*(int *)(param_1 + 0x834) == 0x20) {
    param_3 = ((iVar2 * -7 + param_2) * 2) / iVar2 + 2;
  }
  *(undefined4 **)(param_1 + 0x91c) = DAT_030a5358;
  FUN_0309f6c4(puVar1,iVar2 * param_3 * 3 + param_2 + 0x28);
  puVar1[8] = puVar1 + 9;
  iVar2 = (int)puVar1 + param_2 + 0x24;
  puVar1[7] = iVar2;
  uVar3 = *(undefined4 *)(param_1 + 0x848);
  puVar1[2] = param_3;
  *puVar1 = uVar3;
  puVar1[1] = param_2;
  if (*(int *)(param_1 + 0x834) == 0x10) {
    puVar1[4] = *(undefined4 *)(param_1 + 0x8f8);
    iVar4 = *(int *)(param_1 + 0x8f8) / param_2;
    if (*(int *)(param_1 + 0x8f8) != param_2 * iVar4) {
      iVar4 = iVar4 + 1;
    }
    puVar1[3] = iVar4;
    *(int *)(param_1 + 0x840) = param_3 * (*(int *)(param_1 + 0x8f8) / param_2);
    FUN_030a4fa8(param_1,puVar1);
  }
  if (*(int *)(param_1 + 0x834) == 0x20) {
    puVar1[6] = 0;
    puVar1[7] = iVar2;
  }
  return 0;
}


