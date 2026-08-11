/**
 * FUN_030036a8 @ 0x030036a8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030036a8(void)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  short sVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined2 local_38 [16];
  
  iVar7 = FUN_02fea0e2();
  iVar9 = DAT_03003aa4;
  puVar4 = SUB_03003a94;
  puVar3 = DAT_03003a90;
  iVar8 = DAT_03003a78;
  iVar11 = iVar7 - DAT_03003a7c;
  if (iVar7 != DAT_03003a7c) {
    if (iVar7 < DAT_03003a7c) {
      iVar11 = iVar7 - DAT_03003a80;
      if (iVar7 == DAT_03003a80) {
LAB_03003760:
        if (*(char *)(DAT_03003a78 + 3) == '\0') {
          uVar2 = *DAT_03003a9c;
          if (uVar2 != 4) {
            if (uVar2 < 5) {
              if (uVar2 == 1) {
LAB_0300378e:
                func_0x02fdf67c(*DAT_03003aa0,DAT_03003aa8);
                FUN_03003ac8(iVar9 + -0x654,*(undefined4 *)(iVar9 + -0x658),
                             *(undefined2 *)(iVar9 + (uint)*(ushort *)(iVar9 + 10) * 2 + 0xc),1);
                goto LAB_030037dc;
              }
              if (uVar2 != 3) goto LAB_030037dc;
            }
            else if (uVar2 != 5) {
              if (uVar2 != 100) goto LAB_030037dc;
              goto LAB_0300378e;
            }
          }
          iVar8 = func_0x02fdf67c(*DAT_03003aa0,DAT_03003aa8);
          if (iVar8 == 1) {
            *(undefined1 *)(DAT_03003aac + 0x6c) = 1;
          }
          if (*(ushort *)(iVar9 + 10) == 0) {
            sVar5 = FUN_0300248c(iVar9 + -0x654,*(undefined2 *)(iVar9 + 0xc),1);
            uVar6 = FUN_0300248c(iVar9 + -0x654,
                                 *(undefined2 *)(iVar9 + (uint)*(ushort *)(iVar9 + 10) * 2 + 0xc),2)
            ;
          }
          else {
            iVar8 = iVar9 + (uint)*(ushort *)(iVar9 + 10) * 2;
            uVar6 = 1;
            sVar5 = *(short *)(iVar8 + 0xc) + *(short *)(iVar8 + 2);
          }
          FUN_03003ac8(iVar9 + -0x654,*(undefined4 *)(iVar9 + -0x658),sVar5,uVar6);
        }
        else if (*(char *)(DAT_03003a78 + 3) != '\x01') {
          return 0;
        }
LAB_030037dc:
        func_0x02fdf504(DAT_03003ab0);
        uVar10 = 0x172;
        goto LAB_0300386c;
      }
      if (iVar7 < DAT_03003a80) {
        if (iVar7 != DAT_03003a84) {
          if (iVar7 < DAT_03003a84) {
            if (iVar7 != 0x10000004) {
              if (iVar7 != 0x10000008) {
                return 0;
              }
              goto LAB_03003854;
            }
LAB_03003872:
            iVar9 = FUN_02ff060c(1);
            if (iVar9 == 0) {
              cVar1 = *(char *)(iVar8 + 3);
              *(char *)(iVar8 + 4) = cVar1;
              goto joined_r0x03003880;
            }
          }
          else {
            iVar9 = (iVar7 - DAT_03003a84) + DAT_03003a88;
            if (iVar9 == 0) goto LAB_03003872;
            if (iVar9 != 4) {
              return 0;
            }
LAB_03003854:
            iVar9 = FUN_02ff060c(1);
            if (iVar9 == 0) {
              cVar1 = *(char *)(iVar8 + 3);
              *(char *)(iVar8 + 4) = cVar1;
joined_r0x03003880:
              if (cVar1 == '\0') {
                *(undefined1 *)(iVar8 + 3) = 1;
              }
              else {
                *(undefined1 *)(iVar8 + 3) = 0;
              }
              uVar10 = 0x187;
              goto LAB_0300386c;
            }
          }
          uVar10 = 0x2f;
          goto LAB_0300386c;
        }
      }
      else {
        if (iVar11 == 0x3e) goto LAB_03003760;
        if (iVar11 != 0x1fe) {
          if (iVar11 == 0x3fe) goto LAB_03003872;
          if (iVar11 != 0x7fe) {
            return 0;
          }
          goto LAB_03003854;
        }
      }
    }
    else {
      iVar9 = iVar11 - DAT_03003a8c;
      if (iVar11 == DAT_03003a8c) {
        local_38[0] = 1;
        func_0x02fdf4ec(DAT_03003a98,DAT_03003ab4,local_38);
        return 0;
      }
      if (iVar11 < DAT_03003a8c) {
        if (iVar11 == 0x3000) {
          FUN_02ff0632(0x11c);
          *puVar4 = *puVar3;
          iVar8 = FUN_02ff0650(1);
          if (iVar8 != 0) {
            func_0x03002368();
            return 0;
          }
        }
        else {
          if (iVar11 != 0x7000) {
            if (iVar11 != 0xf000) {
              if (iVar9 != -0x1000000) {
                return 0;
              }
              local_38[0] = 0;
              func_0x02fdf4ec(DAT_03003a98,DAT_03003ab4,local_38);
              return 0;
            }
            goto LAB_03003754;
          }
          FUN_02ff0632(0x11c);
          *puVar4 = *puVar3;
          iVar8 = FUN_02ff0650(1);
          if (iVar8 != 0) {
            FUN_03002324();
            return 0;
          }
        }
        uVar10 = 1;
        goto LAB_0300386c;
      }
      if (iVar9 != 0xe000200) {
        if (iVar9 == 0xe000400) goto LAB_03003872;
        if (iVar9 == 0xe000800) goto LAB_03003854;
        if (iVar9 != 0xe010000) {
          return 0;
        }
      }
    }
  }
LAB_03003754:
  func_0x02fdf504(DAT_03003a98);
  uVar10 = 0x172;
LAB_0300386c:
  FUN_02ff05f0(uVar10);
  return 0;
}


