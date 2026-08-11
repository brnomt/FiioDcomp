/**
 * FUN_030c0742 @ 0x030c0742
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c0742(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_030bfd16(&DAT_030c0ad0);
    do {
      if (((uVar2 & 3) == 0) && (uVar2 != 0)) {
        FUN_030bfd16(&DAT_030c0ad4);
      }
      uStack_20 = *param_1;
      iVar1 = 4;
      do {
        FUN_030bfd16(s__02x_030c0ad8,(&uStack_21)[iVar1]);
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


