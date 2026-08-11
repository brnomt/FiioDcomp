/**
 * FUN_0306caaa @ 0x0306caaa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306caaa(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

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
    hifi_debug_printf(&DAT_0306ce38);
    do {
      if (((uVar2 & 3) == 0) && (uVar2 != 0)) {
        hifi_debug_printf(&DAT_0306ce3c);
      }
      uStack_20 = *param_1;
      iVar1 = 4;
      do {
        hifi_debug_printf(s__02x_0306ce40,(&uStack_21)[iVar1]);
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


