/**
 * FUN_030ee920 @ 0x030ee920
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ee920(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = param_1;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return (int)pcVar2 - (int)(param_1 + 1);
}


