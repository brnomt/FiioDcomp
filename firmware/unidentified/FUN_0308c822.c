/**
 * FUN_0308c822 @ 0x0308c822
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308c822(int param_1,undefined4 *param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [41];
  undefined4 uStack_2f;
  undefined4 uStack_2b;
  uint uStack_27;
  undefined4 uStack_18;
  
  if (param_1 == 0 || param_2 == (undefined4 *)0x0) {
    return 2;
  }
  if (*(int *)(param_1 + 0x18c) != 0) {
    wma_memclr(auStack_60,0x48);
    iVar2 = FUN_0308282e(param_1 + 0xa8);
    wma_memmove(auStack_58,param_1 + 0xa8,iVar2 + 1);
    if (param_4 >> 0x18 == 0) {
      uStack_2b = DAT_0308c8f4[1];
      uStack_27 = 0;
    }
    else {
      uVar3 = param_4 & 0xffff;
      uStack_27 = uVar3 * 0xa3d7 + 0xa3d7 >> 0x16 & 0xff |
                  (uVar3 + (uint)((ulonglong)DAT_0308c8f0 * (ulonglong)uVar3 >> 0x25) * -100 & 0xff)
                  << 8 | param_4 & 0xff0000 | param_4 & 0xff000000;
      uStack_2b = *DAT_0308c8f4;
    }
    uStack_2f = 3;
    uStack_18 = *(undefined4 *)(param_1 + 0xd8);
    cVar1 = FUN_0308eaf2(*(undefined4 *)(param_1 + 0x1b4),auStack_60,*param_2,
                         (int)*(short *)(param_2 + 1));
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 0xd;
}


