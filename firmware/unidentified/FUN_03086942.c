/**
 * FUN_03086942 @ 0x03086942
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03086942(int *param_1,uint *param_2,undefined1 *param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uStack_28;
  
  iVar3 = 0;
  if (param_1 == (int *)0x0) {
    return DAT_03086be4;
  }
  iVar6 = *param_1;
  iVar5 = DAT_03086be4;
  if (((iVar6 == 0 || param_2 == (uint *)0x0) || param_3 == (undefined1 *)0x0) ||
     (iVar5 = DAT_03086be8, (char)param_1[0x72] != '\x02')) {
LAB_03086a58:
    iVar3 = iVar5;
    *(undefined1 *)(param_1 + 0x72) = 0;
    goto LAB_03086a66;
  }
  *(undefined1 *)(param_1 + 0x72) = 0;
  *param_2 = 0;
  iVar2 = DAT_03086bf0;
  iVar5 = DAT_03086bec;
  if (*(char *)(iVar6 + 0x48) == '\x02') goto LAB_03086a66;
  uStack_28 = param_4;
  if (param_1[0x73] == 0) {
LAB_030869e2:
    uStack_28 = uStack_28 & 0xffff0000;
    iVar3 = FUN_03086358(param_1,&uStack_28,0);
    *param_2 = uStack_28 & 0xffff;
    if (iVar3 == -0xf || iVar3 == -0xe) {
LAB_03086a50:
      iVar5 = iVar3;
      if (param_1 == (int *)0x0) {
        return iVar3;
      }
      goto LAB_03086a58;
    }
    if (iVar3 == iVar5) {
      FUN_03086140(param_1);
      goto LAB_03086a0e;
    }
    if (iVar3 == 4) {
      param_1[0x73] = 1;
      *(undefined1 *)(iVar6 + 0x48) = 6;
    }
    else {
      if (iVar3 == DAT_03086bdc) {
        if ((param_1[0x34] == 0) || (uVar4 = 0, param_1[0x75] != 0)) {
          iVar3 = param_1[0x21];
          goto joined_r0x030869ce;
        }
        goto LAB_030869d2;
      }
      *(undefined1 *)(iVar6 + 0x48) = 7;
      if (iVar3 < 0) goto LAB_03086a50;
    }
  }
  else {
    iVar7 = 0;
    do {
      iVar3 = FUN_03086780(param_1);
      if (iVar3 != iVar5) {
        if (iVar3 != DAT_03086bdc) {
          if (iVar3 < 0) goto LAB_03086a50;
          param_1[0x73] = 0;
          goto LAB_030869e2;
        }
        break;
      }
      FUN_03086140(param_1);
      bVar1 = iVar7 <= iVar2;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    if ((param_1[0x34] == 0) || (uVar4 = 0, param_1[0x75] != 0)) {
      iVar3 = param_1[0x21];
joined_r0x030869ce:
      if (iVar3 == 0) {
        uVar4 = 1;
      }
      else {
        uVar4 = 2;
      }
    }
LAB_030869d2:
    *(undefined1 *)(param_1 + 0x72) = uVar4;
LAB_03086a0e:
    iVar3 = 0;
  }
  if (param_1 == (int *)0x0) {
    return iVar3;
  }
LAB_03086a66:
  iVar5 = 0;
  if (param_1[0x75] != 0) {
    iVar5 = param_1[0x73];
  }
  if ((param_1[0x75] != 0 && iVar5 != 0) && ((char)param_1[0x72] == '\x02')) {
    if (param_1[0x21] == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    *(undefined1 *)(param_1 + 0x72) = uVar4;
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = (char)param_1[0x72];
  }
  return iVar3;
}


