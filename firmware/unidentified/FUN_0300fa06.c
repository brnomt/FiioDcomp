/**
 * FUN_0300fa06 @ 0x0300fa06
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300fa06(void)

{
  short sVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 auStack_860 [2048];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [2];
  
  iVar3 = DAT_0300fe04;
  *DAT_0300fe00 = 0xffff;
  iVar7 = *(int *)(iVar3 + 4);
  if (iVar7 != -1) {
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_02feb510(auStack_860,0x800);
    iVar5 = FUN_030208de(iVar7,*(undefined4 *)(DAT_0300fe08 + 8),&local_60,local_20);
    iVar4 = DAT_0300fe10;
    iVar7 = DAT_0300fe0c;
    if (iVar5 == 0 || iVar5 == 4) {
      if (0x800 < local_20[0]) {
        local_20[0] = 0x800;
      }
      *(short *)(DAT_0300fe0c + 6) = (short)local_20[0];
      uVar2 = *(undefined1 *)(iVar4 + 0x10);
      *(undefined1 *)(iVar4 + 0x10) = 0;
      FUN_030208b8(*(undefined4 *)(iVar3 + 4),0,auStack_860,local_20[0]);
      FUN_02ff8b68(auStack_860,iVar7 + 0x34,0x400);
      *(undefined1 *)(iVar4 + 0x10) = uVar2;
      uVar6 = 0;
      sVar1 = *(short *)(iVar7 + 0x34);
      while (sVar1 != 0) {
        uVar6 = uVar6 + 1 & 0xffff;
        sVar1 = ((short *)(iVar7 + 0x34))[uVar6];
      }
      *(short *)(iVar7 + 6) = (short)uVar6;
      rom_post_event(0x33);
    }
  }
  return 0;
}


