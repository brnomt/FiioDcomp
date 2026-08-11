/**
 * FUN_030ce7f0 @ 0x030ce7f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030ce7f0(uint *param_1,int param_2,uint param_3)

{
  int *piVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar4 = *param_1;
  iVar7 = uVar4 + param_2;
  pbVar2 = (byte *)param_1[1];
  uVar5 = param_1[2];
  if (iVar7 < (int)(uVar5 * 8)) {
    param_3 = (uint)(*pbVar2 >> (uVar4 & 0xff));
    if ((((8 < iVar7) && (param_3 = param_3 | (uint)pbVar2[1] << (8 - uVar4 & 0xff), 0x10 < iVar7))
        && (param_3 = param_3 | (uint)pbVar2[2] << (0x10 - uVar4 & 0xff), 0x18 < iVar7)) &&
       ((param_3 = param_3 | (uint)pbVar2[3] << (0x18 - uVar4 & 0xff), 0x20 < iVar7 && (uVar4 != 0))
       )) {
      param_3 = param_3 | (uint)pbVar2[4] << (0x20 - uVar4 & 0xff);
    }
  }
  else {
    piVar1 = (int *)param_1[3];
    if ((int)uVar5 < 0) {
      return 0xffffffff;
    }
    if (iVar7 != 0) {
      while (uVar5 == 0) {
        piVar1 = (int *)piVar1[3];
        if (piVar1 == (int *)0x0) {
          return 0xffffffff;
        }
        pbVar2 = (byte *)(*piVar1 + piVar1[1]);
        uVar5 = piVar1[2];
      }
      pbVar3 = pbVar2 + 1;
      param_3 = (uint)(*pbVar2 >> (uVar4 & 0xff));
      if (8 < iVar7) {
        iVar6 = uVar5 - 1;
        while (iVar6 == 0) {
          piVar1 = (int *)piVar1[3];
          if (piVar1 == (int *)0x0) {
            return 0xffffffff;
          }
          pbVar3 = (byte *)(*piVar1 + piVar1[1]);
          iVar6 = piVar1[2];
        }
        pbVar2 = pbVar3 + 1;
        param_3 = param_3 | (uint)*pbVar3 << (8 - uVar4 & 0xff);
        if (0x10 < iVar7) {
          iVar6 = iVar6 + -1;
          while (iVar6 == 0) {
            piVar1 = (int *)piVar1[3];
            if (piVar1 == (int *)0x0) {
              return 0xffffffff;
            }
            pbVar2 = (byte *)(*piVar1 + piVar1[1]);
            iVar6 = piVar1[2];
          }
          pbVar3 = pbVar2 + 1;
          param_3 = param_3 | (uint)*pbVar2 << (0x10 - uVar4 & 0xff);
          if (0x18 < iVar7) {
            iVar6 = iVar6 + -1;
            while (iVar6 == 0) {
              piVar1 = (int *)piVar1[3];
              if (piVar1 == (int *)0x0) {
                return 0xffffffff;
              }
              pbVar3 = (byte *)(*piVar1 + piVar1[1]);
              iVar6 = piVar1[2];
            }
            pbVar2 = pbVar3 + 1;
            param_3 = param_3 | (uint)*pbVar3 << (0x18 - uVar4 & 0xff);
            if ((0x20 < iVar7) && (uVar4 != 0)) {
              if (iVar6 == 1) {
                do {
                  piVar1 = (int *)piVar1[3];
                  if (piVar1 == (int *)0x0) {
                    return 0xffffffff;
                  }
                  pbVar2 = (byte *)(*piVar1 + piVar1[1]);
                } while (piVar1[2] == 0);
              }
              param_3 = param_3 | (uint)*pbVar2 << (0x20 - uVar4 & 0xff);
            }
          }
        }
      }
    }
  }
  return param_3 & *(uint *)(DAT_030ce92c + param_2 * 4);
}


