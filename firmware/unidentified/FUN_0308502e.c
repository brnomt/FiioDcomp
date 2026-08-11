/**
 * FUN_0308502e @ 0x0308502e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030850b0) */
/* WARNING: Removing unreachable block (ram,0x030850da) */
/* WARNING: Removing unreachable block (ram,0x030850e0) */
/* WARNING: Removing unreachable block (ram,0x030850e8) */
/* WARNING: Removing unreachable block (ram,0x030850ea) */
/* WARNING: Removing unreachable block (ram,0x030850ec) */
/* WARNING: Removing unreachable block (ram,0x030850f0) */
/* WARNING: Removing unreachable block (ram,0x0308520e) */
/* WARNING: Removing unreachable block (ram,0x03085238) */
/* WARNING: Removing unreachable block (ram,0x0308523e) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0308502e(int param_1,uint *param_2,uint *param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  *(undefined4 *)(param_4 + 4) = 0;
  *param_2 = 0;
  uVar8 = 0x200;
  *param_3 = 0;
  puVar6 = param_2;
LAB_03085058:
  do {
    if (*(char *)(param_1 + 0x175) == '\x01') break;
    if (*(int *)(param_1 + 0x10c) == 0) {
      if (*(int *)(param_1 + 0x100) == 0 && *(int *)(param_1 + 0x104) == 0) {
        uVar3 = *(undefined1 *)(param_1 + 0xf0);
        *(undefined1 *)(param_1 + 0xf0) = 7;
        iVar5 = FUN_03084c3c(param_1);
        if (iVar5 == 0x12) goto LAB_030852bc;
        *(undefined1 *)(param_1 + 0xf0) = uVar3;
        puVar6 = (uint *)(uint)*(byte *)(param_1 + 0x175);
        if (puVar6 == (uint *)0x1) goto LAB_03085058;
        if (iVar5 == 6) {
          *param_3 = 0;
          return DAT_030853cc;
        }
        if (iVar5 != 0) {
          return 3;
        }
        if (*(int *)(param_1 + 0x10c) != 0) goto LAB_030852f2;
      }
      uVar4 = *(uint *)(param_1 + 0x100);
      if (uVar4 == 0 && *(int *)(param_1 + 0x104) == 0) {
        return 3;
      }
      uVar7 = *(uint *)(param_1 + 0x48);
      puVar6 = (uint *)(uVar4 - uVar7);
      *(uint **)(param_1 + 0x100) = puVar6;
      *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) - (uint)(uVar4 < uVar7);
      *(undefined4 *)(param_1 + 0x108) = 1;
      *(uint *)(param_1 + 0x10c) = uVar7;
    }
LAB_030852f2:
    if (*(uint *)(param_1 + 0x10c) < uVar8) {
      uVar8 = *(uint *)(param_1 + 0x10c);
    }
    uVar4 = wma_input_cache_read
                      (param_1,puVar6,*(undefined4 *)(param_1 + 0xf8),
                       *(undefined4 *)(param_1 + 0xfc));
    *param_3 = uVar4;
    if (uVar4 != uVar8) {
      return DAT_030853cc;
    }
    if (0x400 < uVar4) {
      *param_2 = 0;
      return 3;
    }
    *(undefined4 *)(param_1 + 0x1b8) = DAT_030853c8;
    uVar4 = *(uint *)(param_1 + 0xf8);
    uVar7 = *param_3;
    *(uint *)(param_1 + 0xf8) = uVar4 + uVar7;
    *(uint *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + (uint)CARRY4(uVar4,uVar7);
    *(uint *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) - *param_3;
    if ((*(int *)(param_1 + 0x18c) != 0) &&
       (iVar5 = FUN_03088466(*(undefined4 *)(param_1 + 0x1b4),*param_2,(int)(short)*param_3),
       iVar5 != 0)) goto LAB_03085356;
    if (*(int *)(param_1 + 0x108) == 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x108) = 0;
    if ((uint)*(ushort *)(param_1 + 0x16e) - *(int *)(param_1 + 0x48) == *(int *)(param_1 + 0x100)
        && *(int *)(param_1 + 0x104) == 0) {
      *(undefined4 *)(param_4 + 4) = 1;
      *(ulonglong *)(param_4 + 8) =
           (ulonglong)(uint)(*(int *)(param_1 + 0x168) - *(int *)(param_1 + 0x24)) * 10000;
    }
    if (*(short *)(param_1 + 0x16e) != 0xef) {
      return 3;
    }
    puVar6 = *(uint **)(param_1 + 0x48);
    iVar5 = (int)puVar6 + -0xd55;
    bVar9 = iVar5 == 0;
    if (bVar9) {
      iVar5 = *(int *)(param_1 + 0x14);
    }
    if (!bVar9 || iVar5 != 0xc80) {
      return 3;
    }
  } while( true );
LAB_0308507c:
  cVar1 = *(char *)(param_1 + 0x174);
  if (cVar1 == '\x01') {
    wma_input_cache_read
              (param_1,puVar6,*(undefined4 *)(param_1 + 0xf8),*(undefined4 *)(param_1 + 0xfc));
    return DAT_030853cc;
  }
  if (cVar1 == '\x02') {
    uVar4 = *(uint *)(param_1 + 0x10c);
    if (uVar4 != 0) {
LAB_0308511a:
      if (uVar4 < uVar8) {
        uVar8 = uVar4;
      }
      uVar4 = wma_input_cache_read
                        (param_1,puVar6,*(undefined4 *)(param_1 + 0xf8),
                         *(undefined4 *)(param_1 + 0xfc));
      *param_3 = uVar4;
      if (uVar4 != uVar8) {
        return DAT_030853cc;
      }
      if (uVar4 < 0x401) {
        if (param_2 != (uint *)0x0) {
          uVar4 = *param_2;
        }
        if (param_2 != (uint *)0x0 && uVar4 != 0) {
          *(undefined4 *)(param_1 + 0x1b8) = DAT_030853c8;
          uVar4 = *(uint *)(param_1 + 0xf8);
          uVar8 = *param_3;
          *(uint *)(param_1 + 0xf8) = uVar4 + uVar8;
          *(uint *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + (uint)CARRY4(uVar4,uVar8);
          *(uint *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) - *param_3;
          if ((*(int *)(param_1 + 0x18c) == 0) ||
             (iVar5 = FUN_03088466(*(undefined4 *)(param_1 + 0x1b4),*param_2,(int)(short)*param_3),
             iVar5 == 0)) {
            if (*(int *)(param_1 + 0x108) != 0) {
              if ((uint)*(byte *)(param_1 + 0x176) - *(int *)(param_1 + 0x48) ==
                  (uint)*(ushort *)(param_1 + 0x178)) {
                *(undefined4 *)(param_4 + 4) = 1;
                *(ulonglong *)(param_4 + 8) =
                     (ulonglong)
                     (*(int *)(param_1 + 0x17c) * (uint)*(ushort *)(param_1 + 0x180) +
                     (*(int *)(param_1 + 0x168) - *(int *)(param_1 + 0x24))) * 10000;
                *(short *)(param_1 + 0x180) = *(short *)(param_1 + 0x180) + 1;
              }
              *(undefined4 *)(param_1 + 0x108) = 0;
              return 3;
            }
            return 0;
          }
LAB_03085356:
          *param_2 = 0;
          *param_3 = 0;
          return 3;
        }
      }
      *param_2 = 0;
      return 3;
    }
    if (*(ushort *)(param_1 + 0x178) != 0) {
      uVar4 = *(uint *)(param_1 + 0x48);
      puVar6 = (uint *)(*(ushort *)(param_1 + 0x178) - uVar4);
      *(short *)(param_1 + 0x178) = (short)puVar6;
      *(undefined4 *)(param_1 + 0x108) = 1;
      *(uint *)(param_1 + 0x10c) = uVar4;
      goto LAB_0308511a;
    }
    uVar3 = 3;
LAB_030850f4:
    *(undefined1 *)(param_1 + 0x174) = uVar3;
    goto LAB_0308507c;
  }
  if (cVar1 == '\x03') {
    puVar6 = (uint *)(uint)*(ushort *)(param_1 + 0x172);
    if ((uint *)(uint)*(ushort *)(param_1 + 0x170) < puVar6) {
      wma_input_cache_read
                (param_1,puVar6,*(undefined4 *)(param_1 + 0xf8),*(undefined4 *)(param_1 + 0xfc));
      return DAT_030853cc;
    }
    uVar3 = 4;
    goto LAB_030850f4;
  }
  if (cVar1 != '\x04') {
    return 3;
  }
  bVar2 = *(byte *)(param_1 + 0xf0);
  puVar6 = (uint *)(uint)bVar2;
  *(undefined1 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined1 *)(param_1 + 0x175) = 0;
  *(undefined1 *)(param_1 + 0xf0) = 7;
  iVar5 = FUN_03084c3c(param_1);
  if (iVar5 == 0x12) {
LAB_030852bc:
    *param_3 = 0;
    return 0;
  }
  *(byte *)(param_1 + 0xf0) = bVar2;
  if (iVar5 != 0) {
    return 3;
  }
  goto LAB_0308507c;
}


