/**
 * FUN_030dcf5e @ 0x030dcf5e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030dcf5e(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_030e0798(0,2);
  iVar2 = FUN_030e083c(0,1);
  uVar3 = FUN_030e0810(0,1);
  puVar1 = DAT_030dd290;
  if (iVar2 == 0xb) {
    uVar4 = 3;
  }
  else {
    if (iVar2 < 0xc) {
      if (iVar2 == 1) {
        uVar3 = 1;
      }
      else if (iVar2 == 4) {
        uVar3 = 2;
      }
      else if (iVar2 == 7) {
        uVar3 = 4;
      }
      else {
        if (iVar2 != 9) {
          return;
        }
        uVar3 = 5;
      }
      *DAT_030dd290 = uVar3;
      return;
    }
    if (iVar2 == 0xd) {
      uVar4 = 6;
    }
    else if (iVar2 == 0xcb) {
      uVar4 = 0xe;
    }
    else {
      if (iVar2 != 0xcd) {
        return;
      }
      uVar4 = 0xd;
    }
  }
  *DAT_030dd290 = uVar4;
  puVar1[1] = uVar3;
  return;
}


