/**
 * FUN_0308c2bc @ 0x0308c2bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308c2bc(int param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [28];
  
  FUN_0308c40c();
  FUN_0308c580();
  puVar1 = DAT_0308c3a8;
  puVar1[8] = 0x800;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 4);
  wma_memclr(DAT_0308c3ac,0xf0);
  iVar2 = DAT_0308c3b0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  wma_memclr(iVar2,0x50);
  iVar4 = FUN_0308c590(puVar1 + 6);
  iVar2 = DAT_0308c3b0;
  if (iVar4 == 0) {
    *(undefined2 *)(DAT_0308c3b0 + -8) = 1;
    iVar4 = FUN_0308c5ac(*(undefined4 *)(puVar1 + 6),0,0,0,0,0,auStack_40,1);
    if ((((iVar4 == 0) && (iVar4 = FUN_0308c764(*(undefined4 *)(puVar1 + 6),iVar2), iVar4 == 0)) &&
        (iVar4 = FUN_0308c7d4(*(undefined4 *)(puVar1 + 6),DAT_0308c3b4), iVar4 == 0)) &&
       (iVar4 = FUN_0308c7e4(*(undefined4 *)(puVar1 + 6),auStack_44), puVar3 = DAT_0308c3bc,
       iVar4 == 0)) {
      if (*(int *)(iVar2 + 0x28) != 0) {
        if (*puVar1 == 0) {
          iVar4 = 0xe;
          goto LAB_0308c370;
        }
        *DAT_0308c3bc = DAT_0308c3b8;
        puVar3[1] = 0x10;
        iVar4 = FUN_0308c822(*(undefined4 *)(puVar1 + 6),puVar3,0x10,0);
        if (iVar4 != 0) goto LAB_0308c370;
      }
      if (*(uint *)(iVar2 + 4) < 32000) {
        if (*(uint *)(iVar2 + 4) < 0x5622) {
          uVar5 = 0x200;
        }
        else {
          uVar5 = 0x400;
        }
        *(undefined4 *)(puVar1 + 8) = uVar5;
      }
      else {
        puVar1[8] = 0x800;
        puVar1[9] = 0;
      }
    }
  }
LAB_0308c370:
  uVar5 = *(undefined4 *)(puVar1 + 8);
  *(int *)(param_1 + 0x18) = iVar2;
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  *(undefined4 *)(param_1 + 0x1c) = *DAT_0308c3b4;
  *(uint *)(param_1 + 0x10) = (uint)*puVar1;
  return iVar4;
}


