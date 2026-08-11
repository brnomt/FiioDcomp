/**
 * FUN_03082c0c @ 0x03082c0c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x03082d76) */
/* WARNING: Removing unreachable block (ram,0x03082d84) */
/* WARNING: Removing unreachable block (ram,0x03082d86) */

uint FUN_03082c0c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  iVar3 = 0x9d - LZCOUNT(param_1);
  if (-1 < iVar3) {
    uVar2 = (uVar1 >> 8) + iVar3 * 0x800000;
    if ((int)(uVar1 * 0x1000000) < 0) {
      uVar2 = uVar2 + 1;
      if ((uVar1 & 0x7f) == 0) {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return uVar2;
    }
    return uVar2;
  }
  return 0;
}


