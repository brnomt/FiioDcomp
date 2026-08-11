/**
 * FUN_0301c2de @ 0x0301c2de
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301c2de(char *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x38);
  uStack_18 = param_3;
  uStack_14 = param_4;
  if (((param_1[0x18] & 8U) != 0) || (iVar1 = FUN_0301c138(param_1,param_2), iVar1 != -1)) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
    iVar1 = FUN_0301ca0c(param_2,param_1);
    if (iVar1 != -1) {
      if (*param_1 != '\x03') {
        FUN_0301c834(&uStack_18,*(undefined4 *)(param_2 + 0x18));
        *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_2 + 0x1c);
        *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_2 + 0x20);
        uVar2 = FUN_0301c842(param_2 + 0x1c,&uStack_18);
        *(undefined4 *)(param_2 + 0x2c) = uVar2;
      }
      if (*DAT_0301c36c == 0) {
        *DAT_0301c36c = 0x480;
      }
      return 0;
    }
    if ((*(ushort *)(param_2 + 0x3c) & 0xff00) == 0) {
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
    }
  }
  *(undefined4 *)(param_2 + 0x2c) = 0;
  return 0xffffffff;
}


