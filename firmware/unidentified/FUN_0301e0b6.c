/**
 * FUN_0301e0b6 @ 0x0301e0b6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301e0b6(int param_1,uint param_2)

{
  undefined4 *puVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = DAT_0301e320;
  sVar2 = 1;
  param_2 = param_2 & 0xffff;
  DAT_0301e320[2] = 0;
  do {
    if (puVar1[4] == 0) {
      sVar2 = FUN_0301de88(puVar1);
      ape_rom_seek_thunk(puVar1[3],1,*puVar1);
    }
    if (sVar2 != 1) break;
    uVar5 = param_2 - puVar1[2];
    iVar4 = puVar1[2] + param_1;
    if (uVar5 < (uint)puVar1[4]) {
      uVar3 = ape_rom_read_thunk(iVar4,uVar5,*puVar1);
      uVar5 = (uint)uVar3;
      if (uVar5 < param_2 - puVar1[2]) break;
    }
    else {
      uVar3 = ape_rom_read_thunk(iVar4,puVar1[4],*puVar1);
      uVar5 = (uint)uVar3;
      if (uVar5 < (uint)puVar1[4]) break;
    }
    puVar1[4] = puVar1[4] - uVar5;
    iVar4 = puVar1[2];
    puVar1[2] = uVar5 + iVar4;
  } while (uVar5 + iVar4 != param_2);
  return puVar1[2];
}


