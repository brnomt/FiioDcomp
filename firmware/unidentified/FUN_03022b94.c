/**
 * FUN_03022b94 @ 0x03022b94
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03022b94(char param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  
  local_2c = DAT_03022f98[1];
  uStack_28 = DAT_03022f98[2];
  local_24 = *DAT_03022f98;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar1 = FUN_02ffc9d6(&local_38,10,(int)param_1);
  if (0 < iVar1) {
    iVar1 = param_3 - iVar1;
  }
  if (iVar1 < 1) {
    return 0;
  }
  uVar2 = FUN_02ff89ce(&local_38,&LAB_03022f9c,4);
  return uVar2;
}


