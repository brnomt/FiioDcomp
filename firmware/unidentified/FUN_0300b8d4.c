/**
 * FUN_0300b8d4 @ 0x0300b8d4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300b8d4(int param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_998 [2048];
  undefined1 local_198 [4];
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined1 auStack_178 [102];
  undefined4 uStack_112;
  undefined4 uStack_10e;
  undefined4 uStack_10a;
  undefined1 auStack_106 [40];
  undefined2 local_de;
  undefined4 local_dc [51];
  
  FUN_02fe755c(auStack_998,0x800);
  FUN_02fffd02(1,auStack_998,0x800);
  iVar1 = DAT_0300bc2c;
  uVar2 = 0;
  do {
    local_dc[uVar2] = *(undefined4 *)(DAT_0300bc30 + uVar2 * 4);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x32);
  local_194 = *(undefined4 *)(DAT_0300bc2c + 4);
  local_190 = *DAT_0300bc34;
  local_180 = *DAT_0300bc38;
  local_188 = *DAT_0300bc3c;
  local_184 = *DAT_0300bc40;
  local_17c = *DAT_0300bc44;
  local_18c = *DAT_0300bc48;
  local_de = *(undefined2 *)(DAT_0300bc4c + 0x21d);
  local_198[0] = param_2;
  FUN_02fe750e(auStack_178,DAT_0300bc2c + 0x10,0x66);
  uStack_112 = *(undefined4 *)(iVar1 + 0x76);
  uStack_10e = *(undefined4 *)(iVar1 + 0x7a);
  uStack_10a = *(undefined4 *)(iVar1 + 0x7e);
  FUN_02fe750e(auStack_106,iVar1 + 0x82,0x28);
  FUN_02fe750e(auStack_998 + param_1 * 0x188,local_198,0x188);
  FUN_02fface0(2,7);
  FUN_02fffd74(1,auStack_998,0x800);
  return;
}


