/**
 * FUN_0300c558 @ 0x0300c558
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0300c558(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint unaff_r4;
  short *unaff_r5;
  
  uVar3 = FUN_0300c470();
  sVar1 = (short)unaff_r4;
  if (((uVar3 & 3) != 0) && (uVar3 = FUN_0300c470(unaff_r5[-1]), (uVar3 & 3) != 0)) {
    uVar3 = 0;
    if (unaff_r4 != 0) {
      do {
        unaff_r5 = unaff_r5 + -1;
        iVar4 = FUN_0300c470(*unaff_r5);
        if (iVar4 == 0x8000) break;
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < unaff_r4);
    }
    if (uVar3 == unaff_r4) {
      return unaff_r4;
    }
    return (uint)(ushort)(sVar1 - (short)uVar3);
  }
  if (*unaff_r5 == 0xd) {
    if (unaff_r5[1] == 10) {
      uVar2 = sVar1 + 2;
      goto LAB_0300c5b0;
    }
  }
  else if (*unaff_r5 != 10) {
    return unaff_r4;
  }
  uVar2 = sVar1 + 1;
LAB_0300c5b0:
  return (uint)uVar2;
}


