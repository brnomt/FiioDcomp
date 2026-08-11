/**
 * FUN_030c1ca4 @ 0x030c1ca4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c1ca4(int *param_1,code *param_2)

{
  code *pcVar1;
  int iVar2;
  uint extraout_r2;
  uint uVar3;
  uint extraout_r2_00;
  uint extraout_r2_01;
  
  (*(code *)param_1[4])();
  param_1 = (int *)*param_1;
  uVar3 = extraout_r2;
  if (param_1 != (int *)0x0) {
    do {
      pcVar1 = (code *)param_1[4];
      if (pcVar1 != (code *)0x0) {
        uVar3 = param_1[2];
      }
      if ((pcVar1 != (code *)0x0 && uVar3 != 0) &&
         (iVar2 = param_1[1], param_1[1] = iVar2 + 1U, uVar3 <= iVar2 + 1U)) {
        (*pcVar1)();
        param_1[1] = 0;
        uVar3 = extraout_r2_00;
        if ((param_1[3] != 0) && (iVar2 = param_1[3] + -1, param_1[3] = iVar2, iVar2 == 0)) {
          (*param_2)(param_1);
          uVar3 = extraout_r2_01;
        }
      }
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    return;
  }
  return;
}


