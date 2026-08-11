/**
 * FUN_0301c138 @ 0x0301c138
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301c138(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar4 = *(char **)(param_2 + 0x18);
  iVar5 = *(int *)(param_2 + 4);
  if (pcVar4 == (char *)0x0) {
    *(undefined2 *)(param_2 + 0x3c) = 2;
LAB_0301c2d6:
    *(undefined4 *)(param_2 + 0xc) = 0;
    uVar2 = 0xffffffff;
  }
  else {
    if (*(int *)(param_2 + 8) != 0) {
      if (*(int *)(param_2 + 0xc) == 0) {
        pcVar4 = *(char **)(param_2 + 0x14);
      }
      if (iVar5 - (int)pcVar4 < *(int *)(param_2 + 8)) {
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) - (iVar5 - (int)pcVar4);
        *(int *)(param_2 + 0x18) = iVar5;
        *(undefined2 *)(param_2 + 0x3c) = 1;
        goto LAB_0301c2d6;
      }
      pcVar4 = pcVar4 + *(int *)(param_2 + 8);
      *(undefined4 *)(param_2 + 8) = 0;
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
    while( true ) {
      if (*(int *)(param_2 + 0xc) == 0) {
        FUN_0301c834(param_2 + 0x1c,pcVar4);
        iVar1 = FUN_0301c3de(param_2);
        if (iVar1 == -1) {
          if (7 < iVar5 - *(int *)(param_2 + 0x18)) {
            *(int *)(param_2 + 0x18) = iVar5 + -8;
          }
          *(undefined2 *)(param_2 + 0x3c) = 1;
          goto LAB_0301c2d6;
        }
        pcVar4 = (char *)FUN_0301c85a(param_2 + 0x1c);
      }
      else {
        if (iVar5 - (int)pcVar4 < 8) {
          *(char **)(param_2 + 0x18) = pcVar4;
          *(undefined2 *)(param_2 + 0x3c) = 1;
          goto LAB_0301c2d6;
        }
        if ((*pcVar4 != -1) || ((pcVar4[1] & 0xe0U) != 0xe0)) {
          *(char **)(param_2 + 0x14) = pcVar4;
          *(char **)(param_2 + 0x18) = pcVar4 + 1;
          *(undefined2 *)(param_2 + 0x3c) = 0x101;
          goto LAB_0301c2d6;
        }
      }
      *(char **)(param_2 + 0x14) = pcVar4;
      *(char **)(param_2 + 0x18) = pcVar4 + 1;
      FUN_0301c834(param_2 + 0x1c,*(undefined4 *)(param_2 + 0x14));
      iVar1 = FUN_0301be76(param_1,param_2);
      if (iVar1 == -1) goto LAB_0301c2d6;
      if (*(int *)(param_1 + 0xc) == 0) {
        if ((((*(int *)(param_2 + 0x10) == 0) || (*(int *)(param_2 + 0xc) == 0)) ||
            ((*param_1 == '\x03' && (DAT_0301c230 < *(uint *)(param_2 + 0x10))))) &&
           (iVar1 = FUN_0301c036(param_2,param_1), iVar1 == -1)) goto LAB_0301c2d6;
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0x10);
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x400;
      }
      iVar1 = -((int)((uint)(byte)param_1[0x18] << 0x18) >> 0x1f);
      if (*param_1 == '\x01') {
        iVar1 = ((uint)(*(int *)(param_1 + 0xc) * 0xc) / *(uint *)(param_1 + 0x10) + iVar1) * 4;
      }
      else {
        if ((*param_1 == '\x03') && ((*(ushort *)(param_1 + 0x18) & 0x1000) != 0)) {
          iVar3 = 0x48;
        }
        else {
          iVar3 = 0x90;
        }
        iVar1 = (uint)(iVar3 * *(int *)(param_1 + 0xc)) / *(uint *)(param_1 + 0x10) + iVar1;
      }
      if (iVar5 - *(int *)(param_2 + 0x14) < iVar1 + 8) {
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
        *(undefined2 *)(param_2 + 0x3c) = 1;
        goto LAB_0301c2d6;
      }
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x14) + iVar1;
      if (*(int *)(param_2 + 0xc) != 0) goto LAB_0301c2c8;
      if ((**(char **)(param_2 + 0x18) == -1) && (((*(char **)(param_2 + 0x18))[1] & 0xe0U) == 0xe0)
         ) break;
      pcVar4 = (char *)(*(int *)(param_2 + 0x14) + 1);
      *(char **)(param_2 + 0x18) = pcVar4;
    }
    *(undefined4 *)(param_2 + 0xc) = 1;
LAB_0301c2c8:
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
    uVar2 = 0;
  }
  return uVar2;
}


