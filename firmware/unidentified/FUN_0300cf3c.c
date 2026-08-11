/**
 * FUN_0300cf3c @ 0x0300cf3c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300cf3c(void)

{
  ulonglong uVar1;
  int iVar2;
  char *pcVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_b8 [160];
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  iVar2 = DAT_0300d340;
  local_18 = 6;
  local_16 = 0x22;
  local_14 = 0xed;
  local_12 = 0x140;
  uVar5 = *(uint *)(DAT_0300d340 + 0x18);
  if ((uVar5 < 0x4e21) && (uVar5 == (uVar5 / 400) * 400)) {
    *(undefined4 *)(DAT_0300d340 + 0x24 + (uVar5 / 400) * 4) = *(undefined4 *)(DAT_0300d340 + 0x14);
  }
  pcVar3 = DAT_0300d344;
  uVar4 = 0;
  do {
    iVar6 = FUN_0300c5b8(auStack_b8,*(undefined4 *)(iVar2 + 0x14),&local_18,(int)*pcVar3);
    if (iVar6 != 0) {
      *(int *)(iVar2 + 0x14) = iVar6 + *(int *)(iVar2 + 0x14);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0xc);
  uVar5 = *(int *)(iVar2 + 0x18) + 1;
  uVar1 = (ulonglong)DAT_0300d348;
  *(uint *)(iVar2 + 0x18) = uVar5;
  if ((uVar5 + (uint)(uVar1 * uVar5 >> 0x24) * -0x32 != 0) &&
     (*(uint *)(iVar2 + 0x14) < *(uint *)(DAT_0300d34c + 4))) {
    return;
  }
  FUN_02ffa694(0x13a);
  return;
}


