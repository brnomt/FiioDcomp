/**
 * FUN_0302cd22 @ 0x0302cd22
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302cd22(uint *param_1,int param_2,int param_3)

{
  short sVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = DAT_0302ce58;
  switch(*DAT_0302ce58) {
  case 0:
    return;
  case 1:
    param_2 = param_2 + -1;
    if (param_2 != -1) {
      do {
        *param_1 = (uint)((longlong)(int)*param_1 * 0x15) >> 5 |
                   (int)((ulonglong)((longlong)(int)*param_1 * 0x15) >> 0x20) << 0x1b;
        param_1 = param_1 + param_3;
        bVar5 = param_2 != 0;
        param_2 = param_2 + -1;
      } while (bVar5);
      return;
    }
    return;
  case 2:
    if (param_2 == 0) {
      return;
    }
    break;
  case 3:
  case 4:
    param_2 = param_2 + -1;
    if (param_2 != -1) {
      do {
        *param_1 = (uint)((longlong)(int)*param_1 * 5) >> 3 |
                   (int)((ulonglong)((longlong)(int)*param_1 * 5) >> 0x20) << 0x1d;
        param_1 = param_1 + param_3;
        bVar5 = param_2 != 0;
        param_2 = param_2 + -1;
      } while (bVar5);
      return;
    }
    return;
  case 5:
  case 6:
    if (param_2 == 0) {
      return;
    }
    do {
      param_2 = param_2 + -1;
      *param_1 = (uint)((longlong)(int)*param_1 * 7) >> 4 |
                 (int)((ulonglong)((longlong)(int)*param_1 * 7) >> 0x20) << 0x1c;
      param_1 = param_1 + param_3;
    } while (param_2 != 0);
    return;
  case 7:
    if (param_2 == 0) {
      return;
    }
    do {
      param_2 = param_2 + -1;
      *param_1 = (uint)((longlong)(int)*param_1 * 3) >> 3 |
                 (int)((ulonglong)((longlong)(int)*param_1 * 3) >> 0x20) << 0x1d;
      param_1 = param_1 + param_3;
    } while (param_2 != 0);
    return;
  default:
    return;
  }
  do {
    param_2 = param_2 + -1;
    sVar1 = *(short *)(puVar2 + 1);
    if (sVar1 == 0xc || sVar1 == 10) {
      *param_1 = (uint)((longlong)(int)*param_1 * 7) >> 4 |
                 (int)((ulonglong)((longlong)(int)*param_1 * 7) >> 0x20) << 0x1c;
    }
    else {
      if (sVar1 == 8) {
        uVar4 = (uint)((longlong)(int)*param_1 * 3) >> 3 |
                (int)((ulonglong)((longlong)(int)*param_1 * 3) >> 0x20) << 0x1d;
      }
      else if (sVar1 == 6) {
        uVar4 = (uint)(((int)*param_1 >> 0x1f & 1U) != 0) << 0x1f | *param_1 >> 1;
      }
      else {
        if (sVar1 == 4) {
          iVar3 = *param_1 * 0xa000;
        }
        else {
          if (sVar1 != 2) goto LAB_0302ce32;
          iVar3 = *param_1 * 0xc000;
        }
        uVar4 = iVar3 >> 0x10;
      }
      *param_1 = uVar4;
    }
LAB_0302ce32:
    param_1 = param_1 + param_3;
    if (param_2 == 0) {
      return;
    }
  } while( true );
}


