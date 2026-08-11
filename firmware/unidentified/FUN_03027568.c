/**
 * FUN_03027568 @ 0x03027568
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


char FUN_03027568(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  
  cVar2 = FUN_0302754a();
  if (cVar2 == -1) {
    cVar2 = FUN_0302754a();
    iVar1 = DAT_03027874;
    if (cVar2 != '\0') {
      iVar3 = *(int *)(DAT_03027874 + 0x5c);
      *(char *)(iVar3 + -1) = cVar2;
      puVar4 = (undefined1 *)(iVar3 + -2);
      *(undefined1 **)(iVar1 + 0x5c) = puVar4;
      *puVar4 = 0xff;
    }
    cVar2 = -1;
  }
  return cVar2;
}


