/**
 * FUN_0301a7ac @ 0x0301a7ac
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301a7ac(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  
  FUN_0301ded2(DAT_0301a870,DAT_0301a86c,DAT_0301a868,DAT_0301a864,param_1,0x140);
  uVar2 = *DAT_0301a874;
  if (uVar2 == 0) {
    cVar1 = *DAT_0301a878;
  }
  else {
    if ((int)uVar2 < 0xd) goto LAB_0301a7e0;
    cVar1 = *DAT_0301a878;
  }
  if (cVar1 != '\0') {
    return 0;
  }
LAB_0301a7e0:
  FUN_0301ae28(0,(uVar2 & 0xfff) << 4,0x13f,uVar2 * 0x10 + 0xf & 0xffff,0x10,DAT_0301a864,0x140);
  return 0;
}


