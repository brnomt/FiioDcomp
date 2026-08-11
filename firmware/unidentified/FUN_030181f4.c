/**
 * FUN_030181f4 @ 0x030181f4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030181f4(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint *puStack_24;
  
  uVar2 = *param_4;
  if (0x80 < uVar2) {
    return;
  }
  if (param_1 == 2) {
    if (param_2 != 0) {
      puStack_24 = param_4;
      iVar1 = SDDecodeCSD(param_3 + uVar2 * 2,DAT_0301848c);
      iVar1 = iVar1 + uVar2;
      *(undefined2 *)(param_3 + iVar1 * 2) = 0x47;
      uVar2 = iVar1 + 2;
      *(undefined2 *)(param_3 + (iVar1 + 1) * 2) = 0x42;
      *(undefined2 *)(param_3 + uVar2 * 2) = 0;
      goto LAB_0301826a;
    }
    puStack_24 = (uint *)*DAT_03018490;
  }
  else {
    if (param_1 != 4) goto LAB_0301826a;
    puStack_24 = (uint *)*DAT_03018494;
    if (param_2 != 0) {
      iVar1 = SDDecodeCSD(param_3 + uVar2 * 2,DAT_03018498);
      iVar1 = iVar1 + uVar2;
      *(undefined2 *)(param_3 + iVar1 * 2) = 0x47;
      uVar2 = iVar1 + 2;
      *(undefined2 *)(param_3 + (iVar1 + 1) * 2) = 0x42;
      *(undefined2 *)(param_3 + uVar2 * 2) = 0;
      goto LAB_0301826a;
    }
  }
  iVar1 = SDDecodeCSD(param_3 + uVar2 * 2,&puStack_24);
  iVar1 = iVar1 + uVar2;
  *(undefined2 *)(param_3 + iVar1 * 2) = 0x47;
  *(undefined2 *)(param_3 + (iVar1 + 1) * 2) = 0x42;
  uVar2 = iVar1 + 3;
  *(undefined2 *)(param_3 + (iVar1 + 2) * 2) = 0x2f;
LAB_0301826a:
  *param_4 = uVar2;
  return;
}


