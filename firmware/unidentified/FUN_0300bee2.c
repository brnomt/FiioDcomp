/**
 * FUN_0300bee2 @ 0x0300bee2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300bee2(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = FUN_02ff5df4(2);
  iVar2 = DAT_0300c100;
  puVar1 = DAT_0300c0f0;
  *DAT_0300c0f0 = *DAT_0300c108;
  if (*(char *)(iVar2 + 2) == '\x01') {
    uVar4 = 0x17a;
  }
  else if (*(char *)(iVar2 + 2) == '\x02') {
    uVar4 = 0x17b;
  }
  else {
    uVar4 = 0x17c;
  }
  FUN_02ff5ec4(0,3,0x140,0x10,0,uVar4);
  *puVar1 = 0xffff;
  FUN_02ff5df4(uVar3);
  return;
}


