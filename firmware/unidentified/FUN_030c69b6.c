/**
 * FUN_030c69b6 @ 0x030c69b6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c69b6(int *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int *piVar4;
  
  if (param_2 < param_1[3]) {
    piVar4 = (int *)*param_1;
    param_1[3] = 0;
    param_1[1] = (int)piVar4;
    param_1[4] = piVar4[2];
    param_1[2] = piVar4[1] + *piVar4;
  }
  FUN_030c68b8(param_1,param_2);
  uVar1 = *(undefined1 *)(param_1[2] + (param_2 - param_1[3]));
  FUN_030c68b8(param_1,param_2 + 1);
  uVar2 = *(undefined1 *)(param_1[2] + ((param_2 + 1) - param_1[3]));
  FUN_030c68b8(param_1,param_2 + 2);
  uVar3 = *(undefined1 *)(param_1[2] + ((param_2 + 2) - param_1[3]));
  FUN_030c68b8(param_1,param_2 + 3);
  return CONCAT13(*(undefined1 *)(param_1[2] + ((param_2 + 3) - param_1[3])),
                  CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
}


