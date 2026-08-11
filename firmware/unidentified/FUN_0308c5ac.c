/**
 * FUN_0308c5ac @ 0x0308c5ac
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 *
FUN_0308c5ac(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined4 param_5,undefined4 param_6,int *param_7,int param_8)

{
  short sVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *unaff_r4;
  int *piVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined1 auStack_50 [60];
  
  bVar9 = param_7 != (int *)0x0;
  bVar10 = param_8 != 0;
  if (bVar9 && bVar10) {
    unaff_r4 = param_1;
  }
  bVar11 = param_1 == (undefined4 *)0x0;
  if ((!bVar9 || !bVar10) || bVar11) {
    param_1 = (undefined4 *)0x2;
  }
  piVar8 = (int *)auStack_50;
  if ((!bVar9 || !bVar10) || bVar11) {
    piVar8 = (int *)&stack0xffffffec;
  }
  if ((!bVar9 || !bVar10) || bVar11) {
    return param_1;
  }
  *(short *)(unaff_r4 + 0x3a) = (short)param_8;
  iVar4 = FUN_0308dc34(param_1,1);
  if (iVar4 == 0) {
    sVar1 = 0;
    if (unaff_r4[0x10] != 0) {
      sVar1 = *(short *)(unaff_r4 + 0x13);
    }
    if (unaff_r4[0x10] != 0 && sVar1 != 0) {
      iVar4 = 0;
      if (unaff_r4[0x12] != 0) {
        iVar4 = unaff_r4[0x11];
      }
      if (unaff_r4[0x12] != 0 && iVar4 != 0) {
        iVar4 = FUN_0308f29c(0);
        unaff_r4[0x6b] = iVar4;
        if (iVar4 != 0) {
          piVar8[8] = 0;
          piVar8[9] = 0;
          piVar8[0xd] = 0;
          piVar8[10] = 0;
          piVar8[0xb] = 0;
          piVar8[0xc] = 0;
          piVar8[0xe] = 0;
          *(undefined2 *)(piVar8 + 8) = 0;
          *(undefined2 *)(piVar8 + 2) = *(undefined2 *)((int)unaff_r4 + 0x3e);
          *(undefined2 *)((int)piVar8 + 10) = *(undefined2 *)(unaff_r4 + 0x13);
          piVar8[3] = unaff_r4[0x10];
          piVar8[4] = unaff_r4[0x11];
          *(undefined2 *)(piVar8 + 5) = *(undefined2 *)(unaff_r4 + 0x12);
          *(undefined2 *)((int)piVar8 + 0x16) = *(undefined2 *)((int)unaff_r4 + 0x5a);
          piVar8[6] = unaff_r4[0x17];
          *(undefined2 *)(piVar8 + 7) = *(undefined2 *)(unaff_r4 + 0x15);
          param_7[4] = (uint)(*(ushort *)(unaff_r4 + 0x16) >> 3);
          *param_7 = unaff_r4[0x10];
          param_7[3] = (uint)*(ushort *)((int)unaff_r4 + 0x5a);
          *param_7 = piVar8[3];
          param_7[1] = (uint)*(ushort *)((int)piVar8 + 10);
          param_7[2] = piVar8[6];
          param_7[3] = (uint)*(ushort *)((int)piVar8 + 0x16);
          param_7[4] = *(ushort *)((int)piVar8 + 0x16) + 7 >> 3;
          *(undefined1 *)(param_7 + 5) = 0;
          *piVar8 = (int)(unaff_r4 + 0x6c);
          piVar8[1] = 0;
          uVar5 = FUN_0308f6f6(unaff_r4[0x6b],piVar8 + 2,param_7,piVar8 + 8);
          if ((int)uVar5 < 0) {
            return (undefined4 *)(uVar5 & 0xff);
          }
          if (uVar5 == 0) {
            unaff_r4[99] = 0;
            if (unaff_r4[0x25] == 0) {
LAB_0308c6f4:
              unaff_r4[0xc] = unaff_r4[10];
              unaff_r4[0xd] = unaff_r4[0xb];
              iVar4 = unaff_r4[7];
              if (iVar4 != 0) {
                if (param_4 != 0) {
                  iVar4 = iVar4 + -1;
                  unaff_r4[7] = iVar4;
                }
                lVar2 = (ulonglong)(iVar4 - 1) * (ulonglong)(uint)unaff_r4[5];
                uVar7 = (uint)lVar2;
                uVar5 = unaff_r4[0xc];
                unaff_r4[0xc] = uVar7 + uVar5;
                unaff_r4[0xd] =
                     unaff_r4[0xd] +
                     ((iVar4 != 0) - 1) * unaff_r4[5] + (int)((ulonglong)lVar2 >> 0x20) +
                     (uint)CARRY4(uVar7,uVar5);
              }
              if ((*(byte *)(unaff_r4 + 0xe) & 1) != 0) {
                unaff_r4[0xc] = 0xffffffff;
                unaff_r4[0xd] = 0xffffffff;
                unaff_r4[0xc] = -1 - unaff_r4[5];
                unaff_r4[0xd] = 0xffffffff;
              }
              *unaff_r4 = unaff_r4[4];
              unaff_r4[1] = 0;
              unaff_r4[2] = unaff_r4[4];
              unaff_r4[3] = 0;
              *(undefined1 *)(unaff_r4 + 0x3c) = 3;
              return (undefined4 *)0x0;
            }
            cVar3 = *(char *)(unaff_r4 + 0x26);
            puVar6 = unaff_r4 + 0x26;
            bVar9 = cVar3 == 'D';
            if (bVar9) {
              cVar3 = *(char *)((int)unaff_r4 + 0x99);
            }
            if (bVar9 && cVar3 == 'R') {
              bVar9 = *(char *)((int)unaff_r4 + 0x9a) == 'M';
              if (bVar9) {
                puVar6 = (undefined4 *)(uint)*(byte *)((int)unaff_r4 + 0x9b);
              }
              if (bVar9 && puVar6 == (undefined4 *)0x0) {
                unaff_r4[99] = 1;
                unaff_r4[0x6d] = DAT_0308c8ec;
                cVar3 = FUN_0308e106();
                if (cVar3 != '\0') {
                  return (undefined4 *)&DAT_0000000d;
                }
                goto LAB_0308c6f4;
              }
            }
            return (undefined4 *)&HardFault;
          }
        }
        return (undefined4 *)0x1;
      }
    }
  }
  return (undefined4 *)0x3;
}


