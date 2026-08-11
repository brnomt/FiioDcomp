/**
 * FUN_030cd3e4 @ 0x030cd3e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030cd3e4(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x68) < 2) {
    return 0xffffff7d;
  }
  while( true ) {
    if (*(int *)(param_1 + 0x68) == 5) {
      iVar3 = *(int *)(param_1 + 0x34);
      uVar1 = FUN_030c4012(*(undefined4 *)(param_1 + 0x8c),param_2,(param_3 >> 1) / iVar3);
      if (uVar1 != 0) {
        if (0 < (int)uVar1) {
          FUN_030c4142(*(undefined4 *)(param_1 + 0x8c),uVar1);
          uVar2 = *(uint *)(param_1 + 0x60);
          *(uint *)(param_1 + 0x60) = uVar2 + uVar1;
          *(uint *)(param_1 + 100) =
               *(int *)(param_1 + 100) + ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar2,uVar1);
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = *(undefined4 *)(param_1 + 0x70);
          }
          return uVar1 * iVar3 * 2;
        }
        return uVar1;
      }
    }
    uVar1 = FUN_030cc462(param_1,1);
    if (uVar1 == 0xfffffffe) break;
    if ((int)uVar1 < 1) {
      return uVar1;
    }
  }
  return 0;
}


