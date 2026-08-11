/**
 * FUN_0300ca34 @ 0x0300ca34
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300ca34(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char local_1028 [2048];
  undefined1 local_828 [392];
  undefined1 auStack_6a0 [1660];
  
  iVar1 = DAT_0300cafc;
  uVar5 = 0;
  iVar4 = 0;
  do {
    FUN_02fffd02(1,local_1028,0x800);
    iVar2 = iVar4 * 0x188;
    if (local_1028[iVar2] == '\0') {
      if (iVar4 < 1) {
        iVar3 = FUN_02fe75ce(iVar1 + 0x10,local_1028 + iVar2 + 0x20,0x66);
        if (((iVar3 == 0) &&
            (iVar2 = FUN_02fe75ce(iVar1 + 0x76,local_1028 + iVar2 + 0x86,0xc), iVar2 == 0)) &&
           (iVar2 = FUN_0300ba2c(iVar4), iVar2 != 0)) {
          uVar5 = 1;
        }
      }
      else {
        iVar2 = FUN_02feb2f6(local_1028 + iVar2 + 0x20,local_1028 + iVar2 + 0x86,&DAT_0300cb00);
        if (iVar2 == -1) {
          FUN_02fffd02(1,local_828,0x800);
          local_828[iVar4 * 0x188] = 1;
          FUN_02fface0(2,7);
          FUN_02fffd74(1,local_828,0x800);
          FUN_02feb4bc(0xffffffff);
        }
        else {
          FUN_02feb4bc(iVar2);
        }
      }
    }
    iVar4 = (int)(short)((short)iVar4 + 1);
  } while (iVar4 < 4);
  return uVar5;
}


