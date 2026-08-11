/**
 * FUN_030c6a2a @ 0x030c6a2a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_030c6a2a(int *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte local_14 [8];
  
  if (param_2 < param_1[3]) {
    piVar2 = (int *)*param_1;
    param_1[3] = 0;
    param_1[1] = (int)piVar2;
    param_1[4] = piVar2[2];
    param_1[2] = piVar2[1] + *piVar2;
  }
  iVar5 = 0;
  do {
    iVar3 = param_1[4];
    while (iVar3 <= param_2) {
      iVar3 = *(int *)(param_1[1] + 8) + param_1[3];
      param_1[3] = iVar3;
      piVar2 = *(int **)(param_1[1] + 0xc);
      param_1[1] = (int)piVar2;
      iVar3 = piVar2[2] + iVar3;
      param_1[4] = iVar3;
      param_1[2] = piVar2[1] + *piVar2;
    }
    iVar3 = param_2 - param_1[3];
    param_2 = param_2 + 1;
    local_14[iVar5] = *(byte *)(param_1[2] + iVar3);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 7);
  FUN_030c68b8(param_1,param_2);
  bVar1 = *(byte *)(param_1[2] + (param_2 - param_1[3]));
  uVar4 = CONCAT31(CONCAT21(CONCAT11(bVar1,local_14[6]),local_14[5]),local_14[4]);
  return CONCAT44((((uint)bVar1 << 8 | (uVar4 & 0xffffff) >> 0x10) << 8 | (uVar4 & 0xffff) >> 8) <<
                  8 | (uint)local_14[4],
                  CONCAT31(CONCAT21(CONCAT11(local_14[3],local_14[2]),local_14[1]),local_14[0]));
}


