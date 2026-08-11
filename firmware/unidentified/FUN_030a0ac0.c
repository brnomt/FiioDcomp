/**
 * FUN_030a0ac0 @ 0x030a0ac0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a0ac0(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_030a0b08;
  puVar1 = DAT_030a0b04;
  uVar3 = 0;
  if ((param_2 == *DAT_030a0b04 * (param_2 / *DAT_030a0b04)) && (param_1 != 0)) {
    if (param_2 != 0) {
      do {
        FUN_030a18ee(*(undefined4 *)(iVar2 + 4),param_1 + uVar3 * 2);
        uVar3 = uVar3 + *puVar1;
      } while (uVar3 != param_2);
    }
    return 1;
  }
  return 0;
}


