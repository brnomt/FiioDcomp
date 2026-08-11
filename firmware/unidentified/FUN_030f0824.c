/**
 * FUN_030f0824 @ 0x030f0824
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030f0824(int param_1,int param_2,undefined4 *param_3,int param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_6 == 0x18) {
    if (0 < param_4) {
      do {
        puVar1 = (undefined4 *)((int)param_3 + 3);
        *param_3 = *(undefined4 *)(param_1 + iVar3 * 4);
        if (param_5 == 2) {
          uVar2 = *(undefined4 *)(param_2 + iVar3 * 4);
        }
        else {
          uVar2 = *(undefined4 *)(param_1 + iVar3 * 4);
        }
        param_3 = (undefined4 *)((int)param_3 + 6);
        *puVar1 = uVar2;
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_4);
    }
    return param_4 * 6;
  }
  if (0 < param_4) {
    do {
      puVar1 = (undefined4 *)((int)param_3 + 2);
      *param_3 = *(undefined4 *)(param_1 + iVar3 * 4);
      if (param_5 == 2) {
        uVar2 = *(undefined4 *)(param_2 + iVar3 * 4);
      }
      else {
        uVar2 = *(undefined4 *)(param_1 + iVar3 * 4);
      }
      param_3 = param_3 + 1;
      *puVar1 = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  return param_4 << 2;
}


