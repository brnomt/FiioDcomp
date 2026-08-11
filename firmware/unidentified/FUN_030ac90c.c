/**
 * FUN_030ac90c @ 0x030ac90c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


char * FUN_030ac90c(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  pcVar3 = param_1;
  while (bVar4 = param_3 != 0, param_3 = param_3 + -1, bVar4) {
    cVar1 = *param_2;
    pcVar2 = pcVar3 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar2;
    if (cVar1 != '\0') {
      param_2 = param_2 + 1;
    }
  }
  return param_1;
}


