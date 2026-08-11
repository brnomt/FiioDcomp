/**
 * FUN_03085c50 @ 0x03085c50
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03085c50(int param_1,int *param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short local_2c [2];
  undefined1 auStack_28 [4];
  
  iVar6 = 0;
  iVar5 = 0x7fff;
  if (*(short *)(param_1 + 0x26) != 0) {
    do {
      psVar2 = *(short **)(*(int *)(param_1 + 0xd8) + iVar6 * 0xfc + 0xc0);
      iVar1 = (int)*psVar2;
      iVar3 = *(int *)(psVar2 + 4);
      iVar4 = (int)*(short *)(iVar3 + iVar1 * 2 + -2);
      FUN_03087f9c(param_1,1,iVar4,(int)*(short *)(iVar3 + iVar1 * 2),iVar4,local_2c,auStack_28);
      iVar1 = (((int)local_2c[0] + *(int *)(param_1 + 0x154)) - (iVar4 * 3) / 2) +
              *(int *)(param_1 + 0x154) / 2;
      if (iVar1 < iVar5) {
        iVar5 = iVar1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x26));
  }
  *param_2 = iVar5 - *(int *)(param_1 + 0x118);
  return;
}


