/**
 * FUN_030b12f6 @ 0x030b12f6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030b12f6(char *param_1)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  
  if ((*param_1 == -1) && ((param_1[1] & 0x10U) != 0)) {
    return 0;
  }
  cVar2 = param_1[4];
  bVar3 = cVar2 == 'f';
  if (bVar3) {
    cVar2 = param_1[5];
  }
  if (bVar3 && cVar2 == 't') {
    pcVar1 = param_1 + 6;
    if (*pcVar1 == 'y') {
      param_1 = (char *)(uint)(byte)param_1[7];
    }
    if (*pcVar1 == 'y' && param_1 == (char *)0x70) {
      return 1;
    }
  }
  return 0xffffffff;
}


