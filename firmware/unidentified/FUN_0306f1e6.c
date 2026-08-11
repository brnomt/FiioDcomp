/**
 * FUN_0306f1e6 @ 0x0306f1e6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306f1e6(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_28;
  
  puVar5 = &local_28;
  local_28 = 0;
  uVar6 = 0;
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  pcVar1 = DAT_0306f338;
  if (*(code **)(param_1 + 0x2c) != (code *)0x0) {
    puVar5 = *(undefined4 **)(param_1 + 0x18);
    pcVar1 = *(code **)(param_1 + 0x2c);
  }
  iVar3 = *(int *)(param_1 + 0x14);
  iVar4 = iVar3 + 0x40;
  FUN_030706e8(iVar3);
  FUN_0306f392(iVar4);
  FUN_03070ab2(iVar3 + 0x84);
  *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(param_1 + 4);
  do {
    iVar2 = (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x18),iVar3);
    if (iVar2 == 0) {
LAB_0306f240:
      if (*(int *)(param_1 + 0x20) != 0) {
        iVar2 = FUN_0306f5b8(iVar4,iVar3);
        if (iVar2 == -1) {
          if ((*(ushort *)(iVar3 + 0x3c) & 0xff00) != 0) goto code_r0x0306f2be;
          goto LAB_0306f2f2;
        }
        iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x18),iVar4);
        if (iVar2 != 0) {
          if (iVar2 == 0x10) goto LAB_0306f2fc;
          if (iVar2 == 0x11) break;
          if (iVar2 != 0x20) goto LAB_0306f266;
          goto LAB_0306f240;
        }
      }
LAB_0306f266:
      iVar2 = FUN_0306f87e(iVar4,iVar3);
      if (iVar2 == -1) {
        if ((*(ushort *)(iVar3 + 0x3c) & 0xff00) == 0) goto LAB_0306f2f2;
        iVar2 = (*pcVar1)(puVar5,iVar3,iVar4);
        if (iVar2 == 0x10) goto LAB_0306f2fc;
        if (iVar2 == 0x11) break;
        if (iVar2 != 0x20) goto LAB_0306f240;
      }
      else {
        local_28 = 0;
      }
      if ((*(code **)(param_1 + 0x24) != (code *)0x0) &&
         (iVar2 = (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x18),iVar3,iVar4),
         iVar2 != 0)) {
        if (iVar2 == 0x10) goto LAB_0306f2fc;
        if (iVar2 == 0x11) break;
        if (iVar2 == 0x20) goto LAB_0306f240;
      }
      FUN_03070abe(iVar3 + 0x84,iVar4);
      if ((*(code **)(param_1 + 0x28) != (code *)0x0) &&
         (iVar2 = (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x18),iVar4,iVar3 + 0x88),
         iVar2 != 0)) {
        if (iVar2 != 0x10) goto joined_r0x0306f2d0;
        goto LAB_0306f2fc;
      }
      goto LAB_0306f240;
    }
    if (iVar2 == 0x10) goto LAB_0306f2fc;
    if (iVar2 == 0x11) break;
    if (iVar2 != 0x20) goto LAB_0306f240;
LAB_0306f2f2:
  } while (*(short *)(iVar3 + 0x3c) == 1);
LAB_0306f2f8:
  uVar6 = 0xffffffff;
LAB_0306f2fc:
  FUN_0306f3dc(iVar4);
  FUN_0307071a(iVar3);
  return uVar6;
code_r0x0306f2be:
  iVar2 = (*pcVar1)(puVar5,iVar3,iVar4);
  if (iVar2 != 0) {
    if (iVar2 == 0x10) goto LAB_0306f2fc;
joined_r0x0306f2d0:
    if (iVar2 == 0x11) goto LAB_0306f2f8;
  }
  goto LAB_0306f240;
}


