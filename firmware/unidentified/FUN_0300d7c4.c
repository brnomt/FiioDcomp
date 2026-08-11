/**
 * FUN_0300d7c4 @ 0x0300d7c4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300d7c4(void)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  local_20 = 6;
  local_1e = 0x22;
  local_1c = 0xed;
  local_1a = 0x140;
  iVar7 = *(int *)(DAT_0300d850 + 0xc);
  uVar6 = FUN_02ff5df4(2);
  puVar3 = DAT_0300d854;
  cVar2 = *(char *)(DAT_0300d858 + 0x1be);
  uVar1 = *DAT_0300d854;
  if (cVar2 == '\x01') {
    uVar4 = 0xffff;
  }
  else if (cVar2 == '\x02') {
    uVar4 = 0xfb63;
  }
  else if (cVar2 == '\x03') {
    uVar4 = 0xf88d;
  }
  else {
    uVar4 = 0xd69a;
  }
  *DAT_0300d854 = uVar4;
  uVar5 = 0;
  do {
    FUN_02ff52c8(&local_20,&local_20,iVar7 + 2,0);
    iVar7 = *(int *)(iVar7 + 0xa8);
    local_1e = local_1e + 0x17;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0xc);
  *puVar3 = uVar1;
  FUN_02ff5df4(uVar6);
  return;
}


