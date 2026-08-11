/**
 * FUN_0308e58a @ 0x0308e58a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
FUN_0308e58a(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)

{
  short sVar1;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  int iStack_34;
  int iStack_30;
  undefined4 local_2c;
  int iStack_28;
  
  local_44 = *DAT_0308e9a0;
  local_40 = *DAT_0308e9a4;
  uStack_3c = DAT_0308e9a4[1];
  if ((param_4 != 0 && param_5 != 0) && (param_6 != 0 && param_1 != 0)) {
    iStack_34 = param_1;
    iStack_30 = param_2;
    local_2c = param_3;
    iStack_28 = param_4;
    sVar1 = FUN_0308282e(param_6);
    if ((sVar1 + 1 < 0x1a) && ((param_7 != 0 && param_8 != 0 && (param_8 < 0x15)))) {
      FUN_030900a2(local_2c,&local_44,4);
      if (param_2 == 0) {
        FUN_030900a2(local_2c,&local_40,8);
        wma_memmove(param_1 + 0x240,local_2c,0x74);
        FUN_030900a2(param_1 + 0x240,param_4,param_5);
        FUN_030900a2(param_1 + 0x240,param_6,(int)sVar1);
        FUN_030900ac(param_1 + 0x240,param_1 + 0x80);
        wma_memmove(param_7,param_1 + 0x80,param_8);
        return 0;
      }
      return 10;
    }
  }
  return 1;
}


