/**
 * FUN_030155ae @ 0x030155ae
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030155ae(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  char cVar7;
  
  cVar3 = '\0';
  cVar7 = '\0';
  bVar1 = *(byte *)(DAT_030159b4 + 0x35d);
  if (bVar1 < 0xd) {
    cVar3 = '\f' - bVar1;
  }
  else {
    cVar7 = bVar1 - 0xc;
  }
  FUN_02fffc76(0x158,0x89,0x17);
  FUN_02ffefd8(0x89,0x2a,0xb4,0x10,2,0x112);
  if (cVar7 != '\0') {
    FUN_02fffc76(0x157,0xd7,0x45);
  }
  if (cVar3 != '\0') {
    FUN_02fffc76(0x156,0xd7,0x45);
  }
  uVar4 = DAT_030159b8;
  uVar6 = (uint)(byte)(cVar7 + cVar3);
  if (uVar6 == 0) {
    FUN_02fffc76(0x14c,0xdc,0x45);
    uVar4 = 0x14c;
    uVar5 = 0xe3;
  }
  else {
    FUN_02fffc76(uVar6 / 10 + 0x14c,0xde,0x45);
    uVar4 = uVar6 + (uint)((ulonglong)uVar4 * (ulonglong)uVar6 >> 0x23) * -10 + 0x14c & 0xffff;
    uVar5 = 0xe5;
  }
  FUN_02fffc76(uVar4,uVar5,0x45);
  uVar4 = 0;
  if (uVar6 != 0) {
    do {
      if (cVar7 == '\0') {
        if (cVar3 != '\0') {
          iVar2 = uVar4 * -5;
          FUN_02fffc76(0x15b,iVar2 + 0xe2,0x5a);
          FUN_02fffc76(0x15b,iVar2 + 0xe1,0x5a);
          FUN_02fffc76(0x15b,iVar2 + 0xe0,0x5a);
          FUN_02fffc76(0x15b,iVar2 + 0xdf,0x5a);
          FUN_02fffc76(0x15b,iVar2 + 0xde,0x5a);
        }
      }
      else {
        iVar2 = uVar4 * 5;
        FUN_02fffc76(0x15b,iVar2 + 0xe2,0x5a);
        FUN_02fffc76(0x15b,iVar2 + 0xe3,0x5a);
        FUN_02fffc76(0x15b,iVar2 + 0xe4,0x5a);
        FUN_02fffc76(0x15b,iVar2 + 0xe5,0x5a);
        FUN_02fffc76(0x15b,iVar2 + 0xe6,0x5a);
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < uVar6);
  }
  if (cVar7 == '\0') {
    if (cVar3 == '\0') {
      FUN_02fffc76(0x159,0xdf,0x56);
      return;
    }
    FUN_02fffc76(0x159,uVar4 * -5 + 0xdf,0x56);
    return;
  }
  FUN_02fffc76(0x159,uVar4 * 5 + 0xdf,0x56);
  return;
}


