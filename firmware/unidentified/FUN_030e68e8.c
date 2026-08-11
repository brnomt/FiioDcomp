/**
 * FUN_030e68e8 @ 0x030e68e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030e68e8(int param_1,int param_2,int param_3)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  undefined1 auStack_2c [8];
  
  if (*(int *)(DAT_030e6cb8 + 0x18) == 2) {
    buffered_fseek_ovl_0e64(param_1,param_3 + -8,1);
  }
  else {
    local_30 = 0;
    buffered_fseek_ovl_0e64(param_1,4,1);
    uVar6 = buffered_fread_ovl_0e65(&local_34,1,4,param_1);
    iVar4 = DAT_030e6cbc;
    if (uVar6 < 4) {
      return -5;
    }
    local_34 = (int)local_34 >> 8 & 0xff00U | local_34 >> 0x18 | (local_34 & 0xff00) << 8 |
               local_34 << 0x18;
    iVar9 = 0;
    if (0 < (int)local_34) {
      do {
        uVar6 = buffered_fread_ovl_0e65(&local_38,1,4,param_1);
        if (uVar6 < 4) {
          return -5;
        }
        local_38 = (local_38 & 0xff00) << 8 | (int)local_38 >> 8 & 0xff00U | local_38 >> 0x18 |
                   local_38 << 0x18;
        uVar6 = buffered_fread_ovl_0e65(&local_30,1,4,param_1);
        iVar7 = DAT_030e6cd8;
        if (uVar6 < 4) {
          return -5;
        }
        if (*(int *)(DAT_030e6cb8 + 0x18) == 0) {
          if (local_30 + DAT_030e6cd0 == 0) {
            *(undefined2 *)(param_2 + 0xce) = 3;
            FUN_030e5abc(iVar4 + 0x4f4,&DAT_030e6ce4,4);
          }
          else {
            iVar8 = local_30 + DAT_030e6cd0 + DAT_030e6cd4;
            if (iVar8 == 0 || iVar8 == 0xb) {
              *(undefined2 *)(param_2 + 0xce) = 2;
              FUN_030e5abc(iVar4 + 0x4f4,&DAT_030e6ce0,4);
            }
            else {
              if (iVar8 + DAT_030e6cd8 != 0) {
                *(undefined2 *)(param_2 + 0xce) = 0;
                return iVar7 >> 0x1d;
              }
              *(undefined2 *)(param_2 + 0xce) = 1;
              FUN_030e5abc(iVar4 + 0x4f4,&DAT_030e6cdc,4);
            }
          }
          buffered_fseek_ovl_0e64(param_1,0x18,1);
          uVar6 = buffered_fread_ovl_0e65(param_2 + 200,1,2,param_1);
          if (uVar6 < 2) {
            return -5;
          }
          *(ushort *)(param_2 + 200) =
               *(ushort *)(param_2 + 200) >> 8 | *(ushort *)(param_2 + 200) << 8;
          uVar6 = buffered_fread_ovl_0e65(param_2 + 0xca,1,2,param_1);
          if (uVar6 < 2) {
            return -5;
          }
          uVar3 = *(ushort *)(param_2 + 0xca) >> 8 | *(ushort *)(param_2 + 0xca) << 8;
          iVar7 = (int)(short)uVar3;
          *(ushort *)(param_2 + 0xca) = uVar3;
          sVar2 = *(short *)(param_2 + 0xce);
          iVar8 = (int)*(short *)(param_2 + 200);
          if (sVar2 == 3) {
            bVar11 = SBORROW4(iVar8,0x780);
            iVar1 = iVar8 + -0x780;
            bVar10 = iVar8 == 0x780;
            if (iVar8 < 0x781) {
              bVar11 = SBORROW4(iVar7,0x438);
              iVar1 = iVar7 + -0x438;
              bVar10 = iVar7 == 0x438;
            }
            if (!bVar10 && iVar1 < 0 == bVar11) {
              return -4;
            }
          }
          else {
            bVar11 = SBORROW4(iVar8,0x500);
            iVar1 = iVar8 + -0x500;
            bVar10 = iVar8 == 0x500;
            if (iVar8 < 0x501) {
              bVar11 = SBORROW4(iVar7,0x2d0);
              iVar1 = iVar7 + -0x2d0;
              bVar10 = iVar7 == 0x2d0;
            }
            if (!bVar10 && iVar1 < 0 == bVar11) {
              return -4;
            }
          }
          if (sVar2 != 1 && sVar2 != 3) goto LAB_030e6c28;
          local_40 = 0;
          local_3c = 0;
          buffered_fseek_ovl_0e64(param_1,0x32,1);
          uVar6 = buffered_fread_ovl_0e65(&local_40,1,4,param_1);
          if (uVar6 < 4) {
            return -5;
          }
          local_40 = local_40 << 0x18 | (local_40 >> 8 & 0xff) << 0x10 |
                     (local_40 >> 0x10 & 0xff) << 8 | local_40 >> 0x18;
          uVar6 = buffered_fread_ovl_0e65(&local_3c,1,4,param_1);
          if (uVar6 < 4) {
            return -5;
          }
          if (local_3c == DAT_030e6ce8) {
            buffered_fseek_ovl_0e64(param_1,4,1);
            puVar5 = DAT_030e6cec;
            *(uint *)(param_2 + 0x50) = local_40 - 0xc;
            iVar7 = (*(code *)*puVar5)(*(undefined4 *)(param_1 + 0x204));
            *(uint *)(param_2 + 0x4c) =
                 iVar7 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200));
            buffered_fseek_ovl_0e64(param_1,local_38 - 0x62,1);
          }
          else if (local_3c == DAT_030e6cf0) {
            buffered_fseek_ovl_0e64(param_1,4,1);
            puVar5 = DAT_030e6cec;
            *(uint *)(param_2 + 0x5c) = local_40 - 0xc;
            iVar7 = (*(code *)*puVar5)(*(undefined4 *)(param_1 + 0x204));
            *(uint *)(param_2 + 0x58) =
                 iVar7 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200));
            buffered_fseek_ovl_0e64(param_1,5,1);
            iVar7 = buffered_fread_ovl_0e65(auStack_2c,1,1,param_1);
            if (iVar7 == 0) {
              return -5;
            }
            buffered_fseek_ovl_0e64(param_1,local_38 - 0x68,1);
          }
          else {
            buffered_fseek_ovl_0e64(param_1,local_38 - 0x5e,1);
          }
        }
        else {
          if (local_30 + DAT_030e6cc0 == 0) {
            *(undefined2 *)(param_2 + 0xcc) = 3;
            FUN_030e5abc(iVar4 + 0x4e4,&DAT_030e6cfc,0x10);
          }
          else {
            iVar7 = local_30 + DAT_030e6cc0 + DAT_030e6cc4;
            if (iVar7 == 0) {
              *(undefined2 *)(param_2 + 0xcc) = 2;
              FUN_030e5abc(iVar4 + 0x4e4,&DAT_030e6cf8,0x10);
            }
            else {
              iVar7 = iVar7 + DAT_030e6cc8;
              if (iVar7 == 0) {
                *(undefined2 *)(param_2 + 0xcc) = 4;
                FUN_030e5abc(iVar4 + 0x4e4,&DAT_030e6cf8,0x10);
              }
              else if (iVar7 + DAT_030e6ccc == 0) {
                *(undefined2 *)(param_2 + 0xcc) = 1;
                FUN_030e5abc(iVar4 + 0x4e4,&DAT_030e6cf4,0x10);
              }
              else {
                *(undefined2 *)(param_2 + 0xcc) = 0;
              }
            }
          }
          buffered_fseek_ovl_0e64(param_1,0x10,1);
          uVar6 = buffered_fread_ovl_0e65(param_2 + 0xc0,1,2,param_1);
          if (uVar6 < 2) {
            return -5;
          }
          *(ushort *)(param_2 + 0xc0) =
               *(ushort *)(param_2 + 0xc0) >> 8 | *(ushort *)(param_2 + 0xc0) << 8;
          buffered_fseek_ovl_0e64(param_1,6,1);
          uVar6 = buffered_fread_ovl_0e65(param_2 + 0xc4,1,4,param_1);
          if (uVar6 < 4) {
            return -5;
          }
          *(uint *)(param_2 + 0xc4) =
               (*(uint *)(param_2 + 0xc4) << 0x18 | (*(uint *)(param_2 + 0xc4) >> 8 & 0xff) << 0x10)
               >> 0x10;
          local_40 = 0;
          local_3c = 0;
          uVar6 = buffered_fread_ovl_0e65(&local_40,1,4,param_1);
          if (uVar6 < 4) {
            return -5;
          }
          local_40 = local_40 << 0x18 | (local_40 >> 8 & 0xff) << 0x10 |
                     (local_40 >> 0x10 & 0xff) << 8 | local_40 >> 0x18;
          uVar6 = buffered_fread_ovl_0e65(&local_3c,1,4,param_1);
          if (uVar6 < 4) {
            return -5;
          }
          if (local_3c == DAT_030e6d00) {
            buffered_fseek_ovl_0e64(param_1,0xfffffff8,1);
            buffered_fread_ovl_0e65(DAT_030e6d04,1,local_40,param_1);
            buffered_fseek_ovl_0e64(param_1,-local_40,1);
LAB_030e6c28:
            buffered_fseek_ovl_0e64(param_1,local_38 - 0x24,1);
          }
          else {
            buffered_fseek_ovl_0e64(param_1,local_38 - 0x2c,1);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)local_34);
    }
  }
  return 0;
}


