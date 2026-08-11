/**
 * FUN_0304f104 @ 0x0304f104
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0304f104(int param_1,int param_2,byte *param_3,uint param_4,uint param_5)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if ((param_1 == 0 || param_2 == 0) || param_3 == (byte *)0x0) {
    return 0;
  }
  bVar2 = *param_3;
  uVar8 = (uint)bVar2;
  if (uVar8 != 0) {
    if (param_5 == 0) {
      param_5 = 0;
    }
    else {
      uVar3 = (param_5 & 0x1ffff) >> 9;
      uVar7 = (param_5 & 0x1ff) >> 1;
      bVar5 = (byte)((param_5 << 0x17) >> 0x18);
      if (uVar3 - 1 < 0x1e) {
        bVar2 = param_3[4] + bVar2 + param_3[8] + param_3[0xc];
LAB_0304f160:
        bVar2 = bVar2 ^ bVar5;
      }
      else {
        bVar1 = (byte)((param_5 << 0xf) >> 0x18);
        if (uVar3 - 0x29 < 0x1e) {
          bVar2 = bVar1 + bVar5 ^ param_3[4] + bVar2;
          bVar5 = param_3[8] + param_3[0xc];
          goto LAB_0304f160;
        }
        if (0x1d < uVar3 - 0x51) {
          if (uVar3 - 0x79 < 0x1e) {
            param_5 = (uVar8 + param_3[8] ^ uVar3 ^ uVar7 ^
                      (uint)param_3[4] + (uint)param_3[8] + (uint)param_3[0xc]) & 0xff;
          }
          else {
            if (0x1d < uVar3 - 0xa1) {
              bVar2 = param_3[8] ^ bVar2 + bVar1 + bVar5 ^ param_3[4] + param_3[8] + param_3[0xc];
              goto LAB_0304f1d8;
            }
            param_5 = (uVar3 + uVar8 ^ (uint)param_3[8] ^
                      uVar7 ^ (uint)param_3[8] + (uint)param_3[4] + (uint)param_3[0xc]) & 0xff;
          }
          goto LAB_0304f1da;
        }
        bVar2 = bVar1 ^ bVar5 ^ param_3[4] + bVar2 ^ param_3[8];
      }
LAB_0304f1d8:
      param_5 = (uint)bVar2;
    }
  }
LAB_0304f1da:
  bVar2 = (byte)param_5;
  if (uVar8 == 3) {
    if (param_3[4] == 3) {
      uVar8 = *(uint *)(param_3 + 8) & 0xff;
      if (uVar8 < 2) {
        bVar5 = *(byte *)(DAT_0304f570 + uVar8 * 0x100 + -0x100 +
                         (((*(uint *)(param_3 + 8) & 0xffff) >> 8 ^
                          ~(uint)(*(ushort *)(param_3 + 0xc) >> 3)) & 0xff));
        uVar8 = (uint)(bVar5 >> 4);
        bVar5 = (byte)((uVar8 & 3) << 6) | (byte)(((bVar5 & 0xf) << 4 | uVar8) >> 2);
LAB_0304f264:
        iVar9 = 0;
        if (param_2 < 1) {
          return param_2;
        }
        do {
          *(byte *)(param_1 + iVar9) = *(byte *)(param_1 + iVar9) ^ bVar5 ^ bVar2;
          iVar9 = iVar9 + 1;
        } while (iVar9 < param_2);
        return param_2;
      }
    }
    else if (param_3[4] == 4) {
      uVar8 = *(uint *)(param_3 + 8) & 0xff;
      if (uVar8 < 2) {
        bVar5 = *(byte *)(DAT_0304f570 + uVar8 * 0x100 + -0x100 +
                         ((((uint)param_3[0xc] << 4 | (uint)(param_3[0xc] >> 4)) ^
                          (*(uint *)(param_3 + 8) & 0xffff) >> 8) & 0xff));
        uVar8 = (uint)(bVar5 >> 4);
        bVar5 = (byte)((uVar8 & 3) << 6) | (byte)(((bVar5 & 0xf) << 4 | uVar8) >> 2);
        goto LAB_0304f264;
      }
    }
  }
  else if (uVar8 == 5) {
    if (param_3[4] < 2) {
      iVar9 = DAT_0304f570 + (uint)param_3[4] * 0x100;
      bVar5 = param_3[8];
      iVar4 = 0;
      if (param_2 < 1) {
        return param_2;
      }
      do {
        uVar8 = param_4 & 0xff;
        param_4 = param_4 + 1;
        bVar1 = *(byte *)(iVar9 + -0x100 + (((uVar8 << 4 | uVar8 >> 4) ^ (uint)bVar5) & 0xff));
        uVar8 = (bVar1 & 0xf) << 4 | (uint)(bVar1 >> 4);
        *(byte *)(param_1 + iVar4) =
             ((byte)(uVar8 << 6) | (byte)(uVar8 >> 2)) ^ bVar2 ^ *(byte *)(param_1 + iVar4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_2);
      return param_2;
    }
  }
  else {
    if (uVar8 != 6) {
      return param_2;
    }
    if (param_3[4] < 2) {
      uVar8 = *(uint *)(param_3 + 0xc);
      uVar3 = (uint)param_3[8];
      iVar9 = DAT_0304f570 + (uint)param_3[4] * 0x100 + -0x100;
      if ((int)uVar8 <= (int)param_4) {
        iVar4 = 0;
        if (param_2 < 1) {
          return param_2;
        }
        do {
          iVar6 = (int)((param_4 - uVar8 & 3) + iVar4) % 4;
          if (iVar6 == 0) {
            uVar7 = (uint)*(byte *)(iVar9 + ((uVar3 ^ uVar8 >> 2) & 0xff));
          }
          else if (iVar6 == 1) {
            uVar7 = (uint)*(byte *)(iVar9 + ((uVar3 ^ uVar8 >> 1) & 0xff));
          }
          else if (iVar6 == 2) {
            uVar7 = (uint)*(byte *)(iVar9 + ((~uVar8 ^ uVar3) & 0xff));
          }
          else {
            uVar7 = (uint)*(byte *)(iVar9 + ((uVar8 ^ uVar3) & 0xff));
          }
          uVar7 = (uVar7 & 0xf) << 4 | uVar7 >> 4;
          *(byte *)(param_1 + iVar4) =
               ((byte)(uVar7 << 6) | (byte)(uVar7 >> 2)) ^ bVar2 ^ *(byte *)(param_1 + iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_2);
        return param_2;
      }
    }
  }
  return 0;
}


