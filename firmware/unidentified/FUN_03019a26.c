/**
 * FUN_03019a26 @ 0x03019a26
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03019a26(void)

{
  char *pcVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  
  iVar5 = FUN_03008820(0xe3);
  puVar3 = DAT_03019dd0;
  iVar2 = DAT_03019dcc;
  pcVar1 = DAT_03019dc8;
  if (iVar5 == 0) {
    iVar5 = FUN_03008864(0x26);
    if (iVar5 != 0) {
      func_0x03008846(0x26);
      func_0x03008846(0xe8);
      *pcVar1 = '\0';
      func_0x0301eabe(0x163,0);
      func_0x0301eabe(0x165,1);
      func_0x0301eabe(0x165,0);
      FUN_03008804(0x15f);
    }
    iVar5 = FUN_03008820(0x167);
    if (iVar5 != 0) {
      FUN_02ff77e8(DAT_03019de4,DAT_03019de0);
      local_48 = 0x460038;
      local_44 = 3;
      local_42 = 0;
      local_40 = 1;
      FUN_02ff7700(DAT_03019dec,DAT_03019de8,&local_48);
      func_0x03005554();
      FUN_03003f92(1);
      FUN_03008804(0x134);
      return 0;
    }
    iVar5 = FUN_03008820(0x168);
    uVar4 = DAT_03019de0;
    if (iVar5 != 0) {
      *puVar3 = *puVar3 + 1;
      FUN_02ff77e8(DAT_03019de4,uVar4);
      local_44 = 3;
      local_48 = 0x440038;
      local_42 = 0;
      local_40 = 1;
      FUN_02ff7700(DAT_03019dec,DAT_03019de8,&local_48);
      func_0x03005554();
      FUN_03003f92(1);
      FUN_03008804(0x134);
      return 0;
    }
    iVar5 = FUN_03008820(0x16c);
    if ((iVar5 != 0) || (iVar5 = FUN_03008820(0x16a), iVar5 != 0)) {
      *puVar3 = *puVar3 + 1;
      local_44 = 3;
      local_48 = 0x440038;
      local_42 = 0;
      local_40 = 1;
      func_0x03005554();
      FUN_03003f92(1);
      FUN_03008804(0x134);
      FUN_02ff7700(DAT_03019dec,DAT_03019de8,&local_48);
      return 0;
    }
    iVar5 = FUN_03008820(0x169);
    if (iVar5 != 0) {
      FUN_03008804(0x160);
      return 0;
    }
    if (*(char *)(iVar2 + 0x224) != '\x01') {
      return 0;
    }
    iVar5 = FUN_0301ece6();
    if (iVar5 == 0) {
      return 0;
    }
    if ((uint)(*DAT_03019dd4 - *DAT_03019dd8) < (*(byte *)(iVar2 + 0x225) + 1) * 200) {
      return 0;
    }
  }
  else {
    if (*DAT_03019ddc <= *DAT_03019dd0) {
      FUN_02ff77e8(DAT_03019de4,DAT_03019de0);
      local_48 = (uint)CONCAT21(*(undefined2 *)(iVar2 + 0x221),4);
      func_0x03008a2e(9,&local_48);
      return 1;
    }
    if (*DAT_03019dc8 != '\0') {
      func_0x0301eabe(0x163,0);
      func_0x0301eabe(0x165,0);
      FUN_03008804(0x15f);
      return 0;
    }
    func_0x0301eabe(0x163,0);
  }
  func_0x0301eabe(0x165,1);
  FUN_03008804(0x15f);
  return 0;
}


