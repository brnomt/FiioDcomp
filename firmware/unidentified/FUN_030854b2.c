/**
 * FUN_030854b2 @ 0x030854b2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030854b2(int param_1,uint param_2,uint param_3,uint param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uStack_10;
  
  if (*(char *)(param_1 + 0x1b0) == '\x03') {
    piVar5 = *(int **)(param_1 + 0x1ac);
    *(undefined1 *)(piVar5 + 0x72) = 0;
    cVar1 = *(char *)((int)piVar5 + 0x1e);
    uStack_10 = param_4;
    if ((cVar1 == '\x02' || cVar1 == '\x04') || cVar1 == '\b') {
      uVar4 = (param_3 * *(ushort *)(*piVar5 + 0x26)) / (uint)piVar5[0x42];
      if (uVar4 <= param_3) {
        param_3 = uVar4;
      }
      FUN_03085d5e(*piVar5,&uStack_10,param_2,param_3);
      param_2 = uStack_10 & 0xffff;
    }
    iVar3 = piVar5[0x74];
    piVar5[0x74] = iVar3 - param_2;
    if (iVar3 - param_2 == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 3;
    }
    *(undefined1 *)(piVar5 + 0x72) = uVar2;
    *(char *)(param_1 + 0x1b0) = (char)piVar5[0x72];
    return uStack_10 & 0xffff;
  }
  return 0;
}


