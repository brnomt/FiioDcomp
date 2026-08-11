/**
 * FUN_030af2f6 @ 0x030af2f6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030af2f6(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint local_20;
  
  local_20 = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  buffered_fseek(param_1,4,1);
  uVar2 = buffered_fread(&local_20,1,4,param_1);
  puVar4 = DAT_030af660;
  iVar1 = DAT_030af644;
  if (uVar2 < 4) {
    return 0xfffffffb;
  }
  local_20 = local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 | (local_20 >> 0x10 & 0xff) << 8 |
             local_20 >> 0x18;
  if (*(int *)(DAT_030af644 + 0x24) == 0) {
    *(uint *)(param_2 + 0x78) = local_20;
    iVar3 = (*(code *)*puVar4)(*(undefined4 *)(param_1 + 0x204));
    puVar4 = *(undefined4 **)(iVar1 + 0x38);
    iVar3 = iVar3 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200));
  }
  else {
    if (*(int *)(DAT_030af644 + 0x24) != 1) {
      buffered_fseek(param_1,param_3 + -0x10,1);
      return 0;
    }
    *(uint *)(param_2 + 0x74) = local_20;
    iVar3 = (*(code *)*puVar4)(*(undefined4 *)(param_1 + 0x204));
    puVar4 = *(undefined4 **)(iVar1 + 0x3c);
    iVar3 = iVar3 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200));
  }
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = iVar3;
    buffered_fseek(*puVar4,iVar3,0);
    puVar4[2] = 0;
  }
  buffered_fseek(param_1,local_20 << 2,1);
  return 0;
}


