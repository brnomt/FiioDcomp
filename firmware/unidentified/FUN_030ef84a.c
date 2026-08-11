/**
 * FUN_030ef84a @ 0x030ef84a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ef84a(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  FUN_030ef7b0();
  puVar2 = (uint *)(param_1 + 0x8964);
  uVar6 = *puVar2 >> 0x10;
  puVar5 = (uint *)(param_1 + 0x8960);
  *puVar2 = uVar6;
  uVar4 = *puVar5;
  uVar3 = uVar4 / uVar6;
  if ((int)uVar3 < 0xffd5) {
    iVar1 = 0;
    while ((int)(uint)*(ushort *)(param_2 + iVar1 * 2 + 2) <= (int)uVar3) {
      iVar1 = iVar1 + 1;
    }
    *puVar5 = uVar4 - uVar6 * *(ushort *)(param_2 + iVar1 * 2);
    *puVar2 = uVar6 * *(ushort *)(param_3 + iVar1 * 2);
    return iVar1;
  }
  *puVar5 = uVar4 - uVar6 * uVar3;
  if (0xffff < (int)uVar3) {
    *(undefined4 *)(param_1 + 0x8a00) = 1;
    return uVar3 - 0xffc0;
  }
  return uVar3 - 0xffc0;
}


