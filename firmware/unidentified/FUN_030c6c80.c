/**
 * FUN_030c6c80 @ 0x030c6c80
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c6c80(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_030c673e(param_1[2]);
    param_1[2] = 0;
    param_1[1] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    piVar4 = (int *)*param_1;
    piVar4[3] = 1;
    iVar3 = piVar4[1];
    iVar1 = *piVar4;
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x408);
      memset_byte(iVar1,0,0x400);
      iVar1 = iVar2;
    }
    *piVar4 = 0;
    for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
    }
    piVar4[1] = 0;
    if (piVar4[2] == 0) {
      memset_byte(DAT_030c7020,0,0x10);
    }
    memset_byte(param_1,0,0x1c);
    memset_byte(DAT_030c701c,0,0x1c);
  }
  return 0;
}


