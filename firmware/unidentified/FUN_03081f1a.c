/**
 * FUN_03081f1a @ 0x03081f1a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03081f1a(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_21;
  undefined4 uStack_20;
  
  uVar2 = 0;
  uStack_20 = param_4;
  if (param_2 == 0) {
    return;
  }
  do {
    FUN_03081592(&DAT_030822a8);
    do {
      if (((uVar2 & 3) == 0) && (uVar2 != 0)) {
        FUN_03081592(&DAT_030822ac);
      }
      uStack_20 = *param_1;
      iVar1 = 4;
      do {
        FUN_03081592(s__02x_030822b0,(&uStack_21)[iVar1]);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      param_1 = param_1 + 1;
      uVar2 = uVar2 + 1;
      if (param_2 <= uVar2) {
        return;
      }
    } while (uVar2 != 0);
  } while( true );
}


