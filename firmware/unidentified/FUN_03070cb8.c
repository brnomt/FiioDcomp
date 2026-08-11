/**
 * FUN_03070cb8 @ 0x03070cb8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03070cb8(uint param_1,int param_2)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = DAT_03071080;
  if (0x180e < param_1) {
    iVar4 = DAT_03071084;
  }
  puVar2 = (uint *)(iVar4 + param_1 * 4);
  if (0x180e < param_1) {
    puVar2 = puVar2 + -0x180f;
  }
  uVar3 = ((int)(param_2 + ((uint)(param_2 >> 0x1f) >> 0x1e)) >> 2) +
          (uint)(*(ushort *)((int)puVar2 + 2) >> 0xb);
  if ((int)uVar3 < 0) {
    if (-uVar3 < 0x20) {
      uVar3 = (int)((1 << (~uVar3 & 0xff)) + (*puVar2 & 0x7ffffff)) >> (-uVar3 & 0xff);
    }
    else {
      uVar3 = 0;
    }
  }
  else if ((int)uVar3 < 5) {
    uVar3 = (*puVar2 & 0x7ffffff) << (uVar3 & 0xff);
  }
  else {
    uVar3 = 0x7fffffff;
  }
  lVar1 = (longlong)(int)uVar3 * (longlong)*(int *)(DAT_03071088 + (param_2 % 4) * 4 + 0xc) + 0x800;
  if (param_2 % 4 == 0) {
    return uVar3;
  }
  return (int)((ulonglong)lVar1 >> 0x20) * 0x100000 | (uint)lVar1 >> 0xc;
}


