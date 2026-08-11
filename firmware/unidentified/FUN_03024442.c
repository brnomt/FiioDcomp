/**
 * FUN_03024442 @ 0x03024442
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_03024442(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = -1;
  if ((param_1 < 9) && (param_1 != -1)) {
    if (*(int *)(DAT_030245d8 + 4) == 0) {
      iVar2 = VorbisOGG_Parser(param_1,&local_14);
    }
    else {
      if (*(int *)(DAT_030245d8 + 4) != 1) {
        return 0;
      }
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      thunk_FUN_0302285e(param_1);
      iVar1 = thunk_FUN_0302274c();
      iVar2 = 0;
      if (iVar1 != 0) {
        iVar2 = FUN_03022b7a(&local_40);
        if (iVar2 < 1) {
          iVar2 = 0;
        }
        else {
          FUN_02ffcece(local_30,0,(int)(char)param_1);
          iVar2 = 1;
        }
      }
    }
    if (local_14 != -1) {
      if (iVar2 != 0) {
        iVar2 = FUN_030241f8(param_1);
        if (iVar2 != 0) {
          FUN_030242ec(local_14);
        }
        FUN_02ffcece(0,0,(int)(char)param_1);
        return iVar2;
      }
      return 0;
    }
  }
  return 0;
}


