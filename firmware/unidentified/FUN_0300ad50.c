/**
 * FUN_0300ad50 @ 0x0300ad50
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300ad50(uint param_1,uint param_2,uint param_3,int param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  short local_50;
  short local_4e;
  short local_4c;
  short local_4a;
  short local_48;
  short local_46;
  short local_44;
  short local_42;
  short local_40;
  undefined2 local_3e;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  int local_28;
  
  uStack_34 = param_1;
  uStack_30 = param_2;
  uStack_2c = param_3;
  local_28 = param_4;
  FUN_02ff4e84(2);
                    /* WARNING: Read-only address (ram,0x0301d752) is written */
  uRam0301d752 = 0xffff;
                    /* WARNING: Read-only address (ram,0x0301d750) is written */
  uRam0301d750 = 0x2945;
  local_4e = (short)((param_1 * 0xcccd >> 0x13) % 10) + 0x30;
  sVar2 = (short)param_1 + (short)(param_1 / 10) * -10 + 0x30;
  sVar1 = (short)param_2 + (short)(param_2 / 10) * -10 + 0x30;
  sVar3 = (short)param_3 + (short)(param_3 / 10) * -10 + 0x30;
  local_48 = (ushort)(param_2 * 0xcccd >> 0x13) + 0x30;
  local_42 = (ushort)(param_3 * 0xcccd >> 0x13) + 0x30;
  if (param_1 < 100) {
    local_4c = 0x3a;
    local_46 = 0x3a;
    local_40 = 0;
    local_50 = local_4e;
    local_4e = sVar2;
    local_4a = local_48;
    local_48 = sVar1;
    local_44 = local_42;
    local_42 = sVar3;
  }
  else {
    uVar5 = param_1 * 0xa3d7 + 0xa3d7;
    local_50 = (ushort)(uVar5 >> 0x16) + (short)(uVar5 / 0x2800000) * -10 + 0x30;
    local_44 = 0x3a;
    local_4a = 0x3a;
    local_4c = sVar2;
    local_46 = sVar1;
    local_40 = sVar3;
  }
  local_3e = 0;
  if (local_28 == 0) {
    uVar4 = 0xc;
  }
  else {
    uVar4 = 0xaa;
  }
  FUN_02ff4224(uVar4,0x102,&local_50);
  FUN_02ff4e84(1);
                    /* WARNING: Read-only address (ram,0x0301d750) is written */
  uRam0301d750 = 0xffff;
                    /* WARNING: Read-only address (ram,0x0301d752) is written */
  uRam0301d752 = 0x2945;
  return;
}


