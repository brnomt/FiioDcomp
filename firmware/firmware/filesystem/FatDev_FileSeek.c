/**
 * FatDev_FileSeek @ 0x0304ed3e
 * Tags: fs, fat
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304ed3e(char *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  
  uVar8 = 0xfffffffe;
  if (param_1 != (char *)0x0) {
    switch(*param_1) {
    case '\0':
      return 0xfffffffd;
    case '\x01':
    case '\x02':
    case '\x03':
    case '\x04':
      goto switchD_0304ed5c_caseD_1;
    default:
      return 0xfffffffc;
    }
  }
  return 0xfffffffe;
switchD_0304ed5c_caseD_1:
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar7 = *(int *)(param_1 + 0x14);
  }
  else {
    iVar7 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10);
  }
  if (param_2 == 0) {
    iVar3 = *(int *)(param_1 + 0xc);
  }
  else {
    if (param_2 == 1) {
      iVar3 = *(int *)(param_1 + 0x18) + param_3;
      *(int *)(param_1 + 0x18) = iVar3;
      goto LAB_0304eda8;
    }
    iVar3 = iVar7;
    if (param_2 != 2) {
      return 0xfffffffc;
    }
  }
  iVar3 = iVar3 + param_3;
  *(int *)(param_1 + 0x18) = iVar3;
LAB_0304eda8:
  if (iVar3 < *(int *)(param_1 + 0xc)) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0xc);
  }
  else if (iVar7 < iVar3) {
    *(int *)(param_1 + 0x18) = iVar7;
  }
  cVar2 = *param_1;
  if ((cVar2 != '\x04' && cVar2 != '\x03') && (-1 < *(int *)(param_1 + 0x18))) {
    if (cVar2 == '\x01' || cVar2 == '\x02') {
      iVar3 = FUN_030198e4(*(undefined4 *)(param_1 + 0x1c),0,1);
      if (param_2 == 1) {
        if (iVar3 + param_3 < *(int *)(param_1 + 0xc)) {
          param_3 = *(int *)(param_1 + 0xc) - iVar3;
        }
        else if (iVar7 < iVar3 + param_3) {
          param_3 = iVar7 - iVar3;
        }
        uVar6 = 1;
        uVar8 = *(undefined4 *)(param_1 + 0x1c);
      }
      else {
        uVar6 = 0;
        param_3 = *(int *)(param_1 + 0x18);
        uVar8 = *(undefined4 *)(param_1 + 0x1c);
      }
      iVar4 = FUN_030198e4(uVar8,param_3,uVar6);
      if (-1 < iVar4) {
        *(int *)(param_1 + 0x18) = iVar4;
        iVar5 = *(int *)(param_1 + 0xc);
        bVar9 = SBORROW4(iVar4,iVar5);
        iVar1 = iVar4 - iVar5;
        if (iVar5 <= iVar4) {
          bVar9 = SBORROW4(iVar7,iVar4);
          iVar1 = iVar7 - iVar4;
        }
        if (iVar1 < 0 == bVar9) {
          return 0;
        }
      }
      uVar8 = 0xfffffffb;
      uVar6 = FUN_030198e4(*(undefined4 *)(param_1 + 0x1c),iVar3,0);
      *(undefined4 *)(param_1 + 0x18) = uVar6;
    }
    return uVar8;
  }
  return 0;
}


