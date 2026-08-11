/**
 * FUN_030ad412 @ 0x030ad412
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030ad412(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((int)param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = ~param_2 & 1;
    uVar2 = 0;
    if (uVar1 != 0) {
      do {
        if ((*(char *)(param_1 + uVar2) == -1) && ((~*(byte *)(param_1 + uVar2 + 1) & 0xf0) == 0)) {
          return uVar2;
        }
        uVar2 = uVar2 + 1;
      } while ((int)uVar2 < (int)uVar1);
    }
  }
  while( true ) {
    if ((int)(param_2 - 1) <= (int)uVar1) {
      return 0xffffffff;
    }
    if ((*(char *)(param_1 + uVar1) == -1) && ((~*(byte *)(param_1 + uVar1 + 1) & 0xf0) == 0))
    break;
    if ((*(char *)(param_1 + uVar1 + 1) == -1) && ((~*(byte *)(param_1 + uVar1 + 2) & 0xf0) == 0)) {
      return uVar1 + 1;
    }
    uVar1 = uVar1 + 2;
  }
  return uVar1;
}


