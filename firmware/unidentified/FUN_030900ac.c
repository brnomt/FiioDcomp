/**
 * FUN_030900ac @ 0x030900ac
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030900ac(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_68 [7];
  undefined1 uStack_61;
  undefined1 local_60 [72];
  uint local_18 [2];
  
  iVar1 = -(*(byte *)(param_1 + 0x30) & 0x3f);
  uVar3 = iVar1 + 0x40;
  if (uVar3 < 9) {
    uVar3 = iVar1 + 0x80;
  }
  if (uVar3 != 6) {
    puVar6 = &uStack_61;
    if ((uVar3 & 1) != 0) {
      puVar6 = local_60;
    }
    for (uVar4 = (uVar3 - 6 & 0x1ff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1 & 0xff) {
      puVar6[1] = 0;
      puVar6 = puVar6 + 2;
      *puVar6 = 0;
    }
  }
  local_18[1] = *(int *)(param_1 + 0x30) << 3;
  local_18[0] = *(int *)(param_1 + 0x2c) << 3 | *(uint *)(param_1 + 0x30) >> 0x1d;
  local_60[0] = 0x80;
  iVar1 = 2;
  puVar6 = auStack_68 + uVar3;
  puVar5 = local_18;
  do {
    *puVar6 = (char)(*puVar5 >> 0x18);
    puVar6[1] = (char)(*puVar5 >> 0x10);
    puVar6[2] = (char)((ushort)(short)*puVar5 >> 8);
    puVar6[3] = (char)*puVar5;
    puVar6 = puVar6 + 4;
    iVar1 = iVar1 + -1;
    puVar5 = puVar5 + 1;
  } while (iVar1 != 0);
  FUN_0308fee4(local_60,0,uVar3,param_1);
  iVar1 = 5;
  puVar2 = (undefined4 *)(param_1 + 0x18);
  do {
    *param_2 = (char)((uint)*puVar2 >> 0x18);
    param_2[1] = (char)((uint)*puVar2 >> 0x10);
    param_2[2] = (char)((ushort)*(undefined2 *)puVar2 >> 8);
    param_2[3] = *(undefined1 *)puVar2;
    param_2 = param_2 + 4;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != 0);
  return;
}


