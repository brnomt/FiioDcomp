/**
 * FUN_0304ee4e @ 0x0304ee4e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304ee4e(char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = *param_1;
  switch(cVar1) {
  case '\0':
    return 0xfffffffd;
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
    break;
  default:
    return 0xfffffffc;
  }
  if (*(int *)(param_1 + 0x14) < *(int *)(param_1 + 0xc) + param_2) {
    if ((cVar1 == '\x01' || cVar1 == '\x02') && (*(int *)(param_1 + 0x20) != 0)) {
      uVar2 = FUN_030198e4(*(undefined4 *)(param_1 + 0x1c),0,1);
      iVar3 = FUN_030198e4(*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0xc) + param_2,0);
      if (*(int *)(param_1 + 0x14) < iVar3) {
        *(int *)(param_1 + 0x14) = iVar3;
        *(int *)(param_1 + 0x10) = iVar3 - *(int *)(param_1 + 0xc);
      }
      FUN_030198e4(*(undefined4 *)(param_1 + 0x1c),uVar2,0);
    }
    else {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc);
    }
  }
  else {
    *(int *)(param_1 + 0x10) = param_2;
  }
  return 0;
}


