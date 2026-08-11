/**
 * FUN_0301223a @ 0x0301223a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301223a(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_0301260c;
  iVar3 = DAT_03012608;
  iVar4 = *DAT_0301260c;
  *(undefined2 *)((int)DAT_0301260c + 0x1ee) = 0;
  if (*(short *)(iVar3 + 10) == 4) {
    *(undefined2 *)((int)piVar1 + 0x1ee) = 1;
  }
  iVar3 = DAT_03012610;
  *(undefined2 *)(piVar1 + 0x7c) = *(undefined2 *)((int)piVar1 + 0x1ee);
  *(undefined2 *)(piVar1 + 2) = 1;
  if ((*(char *)(iVar3 + 0x1f) != '\0') && (iVar2 = FUN_02fec170(), iVar2 != 0)) {
    *(short *)(piVar1 + 2) = (short)piVar1[2] + 1;
  }
  *(undefined1 *)(iVar4 + 0x4e) = 0;
  FUN_02ffc66a(0x50,iVar4 + 0x70,0x80);
  if (*(char *)(iVar3 + 0x1f) == '\0') {
    return;
  }
  iVar3 = *(int *)(iVar4 + 4);
  *(undefined1 *)(iVar3 + 0x4e) = 0;
  FUN_02ffc66a(0x52,iVar3 + 0x70,0x80);
  return;
}


