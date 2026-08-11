/**
 * FUN_03029c74 @ 0x03029c74
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03029c74(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  iVar2 = DAT_03029f24;
  iVar1 = DAT_03029f20;
  iVar4 = DAT_03029f04;
  uVar3 = (uint)*(byte *)(DAT_03029f20 + 0x6c);
  bVar6 = uVar3 == 1;
  if (bVar6) {
    uVar3 = *(uint *)(DAT_03029f24 + 0x44);
  }
  if (bVar6 && uVar3 == 0) {
    shared_frame_epilogue_c6b4(0x12d);
    uVar3 = *(uint *)(iVar1 + 0x68);
    if (uVar3 != 0) {
      *(uint *)(*(int *)(iVar4 + 0xc) + 4) = uVar3;
      FUN_0302c950((uVar3 / 1000 + 1) * 1000,0);
    }
    *(undefined1 *)(iVar1 + 0x6c) = 0;
  }
  else {
    shared_mid_entry_c6f6();
  }
  if (*(int *)(iVar2 + 0x44) == 1) {
    if (*(int *)(iVar2 + 0x4c) == 0) {
      *(undefined4 *)(iVar2 + 0x4c) = **(undefined4 **)(iVar4 + 0xc);
    }
    if (*(char *)(iVar1 + 0x6c) == '\x01') {
      iVar5 = *(int *)(iVar1 + 0x68);
      if (iVar5 == 0) {
        iVar5 = *(int *)(iVar2 + 0x48);
      }
      *(int *)(*(int *)(iVar4 + 0xc) + 4) = iVar5 + 0x5dc;
      *(undefined1 *)(iVar1 + 0x6c) = 0;
    }
    else {
      *(int *)(*(int *)(iVar4 + 0xc) + 4) = *(int *)(iVar2 + 0x48) + 0x5dc;
    }
    iVar4 = *(int *)(*(int *)(iVar4 + 0xc) + 4);
    if (iVar4 != 0) {
      FUN_0302c950(iVar4,0);
      return;
    }
    return;
  }
  return;
}


