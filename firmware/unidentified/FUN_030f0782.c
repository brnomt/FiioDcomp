/**
 * FUN_030f0782 @ 0x030f0782
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f0782(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  code *pcVar4;
  
  bVar1 = (byte)param_1[1];
  pcVar4 = (code *)*DAT_030f0894;
  if (bVar1 != 0) {
    if (bVar1 == 8) {
      uVar2 = *param_1;
      *(byte *)(param_1 + 1) = 0x18;
      (*pcVar4)(param_1,4);
      uVar3 = (ushort)(byte)uVar2 * 0x100 + (ushort)(byte)(*param_1 >> 0x18);
    }
    else {
      *(byte *)(param_1 + 1) = bVar1 - 0x10;
      uVar3 = (ushort)(*param_1 >> (uint)(byte)(bVar1 - 0x10));
    }
    return (uint)uVar3;
  }
  (*pcVar4)(param_1,4,*DAT_030f0890);
  *(byte *)(param_1 + 1) = 0x10;
  return *param_1 >> 0x10;
}


