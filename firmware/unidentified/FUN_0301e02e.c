/**
 * FUN_0301e02e @ 0x0301e02e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301e02e(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  puVar1 = DAT_0301e31c;
  sVar2 = 1;
  DAT_0301e31c[2] = 0;
  param_2 = param_2 & 0xffff;
  *param_3 = 0;
  while( true ) {
    if (puVar1[4] == 0) {
      sVar2 = ape_scan_cuesheet(puVar1);
      ape_rom_seek_thunk(puVar1[3],1,*puVar1);
    }
    if (sVar2 == 3) {
      return 0xffffffff;
    }
    if (sVar2 != 1) goto LAB_0301e0a8;
    uVar5 = param_2 - puVar1[2];
    iVar4 = puVar1[2] + param_1;
    if (uVar5 < (uint)puVar1[4]) {
      uVar3 = ape_rom_read_thunk(iVar4,uVar5,*puVar1);
      uVar5 = (uint)uVar3;
      if (uVar5 < param_2 - puVar1[2]) goto LAB_0301e0a8;
    }
    else {
      uVar3 = ape_rom_read_thunk(iVar4,puVar1[4],*puVar1);
      uVar5 = (uint)uVar3;
      if (uVar5 < (uint)puVar1[4]) goto LAB_0301e0a8;
    }
    iVar4 = puVar1[4];
    puVar1[4] = iVar4 - uVar5;
    iVar6 = puVar1[2];
    puVar1[2] = uVar5 + iVar6;
    if (iVar4 - uVar5 == 0) break;
    if (uVar5 + iVar6 == param_2) {
LAB_0301e0a8:
      return puVar1[2];
    }
  }
  *param_3 = 1;
  goto LAB_0301e0a8;
}


