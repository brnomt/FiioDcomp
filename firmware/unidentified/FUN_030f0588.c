/**
 * FUN_030f0588 @ 0x030f0588
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f0588(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((int)param_1[3] < param_2) {
    iVar1 = FUN_030f050c(param_1,param_1[3] & 0xff);
    uVar3 = param_2 - (uint)*(byte *)(param_1 + 3) & 0xff;
    (*(code *)*DAT_030f0894)(*param_1,0x200,*DAT_030f0890);
    param_1[1] = 0;
    param_1[2] = 8;
    param_1[3] = 0x1000;
    iVar2 = FUN_030f050c(param_1,uVar3);
    return iVar2 + (iVar1 << uVar3) & 0xff;
  }
  uVar3 = FUN_030f050c(param_1);
  return uVar3;
}


