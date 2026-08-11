/**
 * FUN_030197ce @ 0x030197ce
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030197ce(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  undefined2 local_28 [16];
  
  iVar2 = FUN_02ffd29a();
  uVar5 = (uint)*(byte *)(DAT_030198f8 + 0x21);
  if (uVar5 == 5) {
    iVar3 = DAT_03019908;
    if ((iVar2 != 0x10000004) &&
       ((iVar2 == 0x10000008 ||
        ((iVar3 = DAT_03019908, iVar2 != 0x30000004 && (iVar3 = iVar2, iVar2 == 0x30000008)))))) {
      iVar3 = DAT_03019904;
    }
  }
  else {
    bVar6 = uVar5 == 6;
    if (bVar6) {
      uVar5 = iVar2 + 0xc0000000;
    }
    iVar3 = iVar2;
    if (bVar6 && uVar5 == 8) {
      iVar3 = DAT_03019900;
    }
  }
  iVar2 = iVar3 - DAT_0301990c;
  if (iVar3 == DAT_0301990c) {
LAB_03019886:
    bVar1 = *DAT_030198fc;
    if (bVar1 != 0) {
      bVar1 = bVar1 - 1;
LAB_03019876:
      *DAT_030198fc = bVar1;
    }
  }
  else {
    if (DAT_0301990c <= iVar3) {
      if (iVar2 == 0x38) {
LAB_030198a2:
        *(byte *)(DAT_030198f8 + 0x17) = *DAT_030198fc;
        func_0x030009f8();
        FUN_02ff26bc(DAT_0301991c);
        func_0x030037a8(199);
        return 0;
      }
      if (iVar2 != 0xff8) {
        if (iVar2 == 0xfffff8) {
          local_28[0] = 0;
          FUN_02ff26a4(DAT_0301991c,DAT_03019920,local_28);
          return 0;
        }
        if (iVar2 != 0x1fffff8) {
          return 0;
        }
        local_28[0] = 1;
        FUN_02ff26a4(DAT_0301991c,DAT_03019920,local_28);
        return 0;
      }
      func_0x030009f8(*(undefined1 *)(DAT_030198f8 + 0x17));
      FUN_02ff26bc(DAT_0301991c);
      uVar4 = 199;
      goto LAB_03019880;
    }
    if (iVar3 == DAT_03019910) goto LAB_03019886;
    if (iVar3 < DAT_03019910) {
      if (iVar3 + -0x20001000 == 0) {
        func_0x030009f8(*(undefined1 *)(DAT_030198f8 + 0x17));
        FUN_02ff26bc(DAT_0301991c);
        func_0x030037a8(199);
        return 0;
      }
      if (iVar3 + -0x20001000 + DAT_03019914 != 0) {
        return 0;
      }
    }
    else {
      iVar2 = (iVar3 - DAT_03019910) + DAT_03019918;
      if (iVar2 == 0) goto LAB_030198a2;
      if (iVar2 != 3) {
        return 0;
      }
    }
    bVar1 = *DAT_030198fc;
    if (bVar1 < 4) {
      bVar1 = bVar1 + 1;
      goto LAB_03019876;
    }
  }
  func_0x030009f8(bVar1);
  uVar4 = 0xd5;
LAB_03019880:
  func_0x030037a8(uVar4);
  return 0;
}


