/**
 * FUN_0309f6da @ 0x0309f6da
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0309f6da(char *param_1)

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


