/**
 * FUN_0304ee3a @ 0x0304ee3a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304ee3a(char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
    return 0xfffffffe;
  }
  if (-1 < param_2) {
    cVar1 = *param_1;
    switch(cVar1) {
    case '\0':
      return 0xfffffffd;
    case '\x01':
    case '\x02':
    case '\x03':
    case '\x04':
      goto switchD_0304ee5a_caseD_1;
    default:
      return 0xfffffffc;
    }
  }
  return 0xfffffffb;
switchD_0304ee5a_caseD_1:
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


