/**
 * FUN_03085524 @ 0x03085524
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_03085524(uint *param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  iVar4 = wma_input_cache_read(param_1,param_2,*param_1,param_1[1]);
  if (iVar4 != 1) {
    return 3;
  }
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  uVar3 = _MasterStackPointer;
  uVar5 = (uint)MasterStackPointer;
  bVar2 = MasterStackPointer >> 7;
  param_1[0x46] = (uint)bVar2;
  *(undefined1 *)(param_1 + 0x47) = 0;
  if (bVar2 != 0) {
    if ((uVar3 & 0x10) != 0) {
      param_1[0x44] = 1;
      return 0;
    }
    if ((uVar3 & 0x60) != 0) {
      return 1;
    }
    *(char *)(param_1 + 0x47) = (char)(uVar5 & 0xf);
    if ((uVar5 & 0xf) != 2) {
      return 1;
    }
    param_1[0x45] = 3;
    iVar4 = wma_input_cache_read
                      (param_1,param_1[1],*param_1 + 3,param_1[1] + (uint)(0xfffffffc < *param_1));
    if (iVar4 != 1) {
      return 3;
    }
    uVar5 = (uint)MasterStackPointer;
  }
  param_1[0x48] = param_1[0x45];
  *(byte *)((int)param_1 + 0x11d) = (byte)((uVar5 << 0x19) >> 0x1e);
  *(byte *)(param_1 + 0x49) = (byte)((uVar5 << 0x1b) >> 0x1e);
  *(byte *)((int)param_1 + 0x125) = (byte)((uVar5 << 0x1d) >> 0x1e);
  param_1[0x4a] = uVar5 & 1;
  uVar5 = param_1[0x45] + 1;
  param_1[0x45] = uVar5;
  iVar4 = wma_input_cache_read
                    (param_1,param_1[1],*param_1 + uVar5,param_1[1] + (uint)CARRY4(*param_1,uVar5));
  if (iVar4 != 1) {
    return 3;
  }
  uVar5 = (uint)MasterStackPointer;
  *(undefined1 *)(param_1 + 0x4b) = 4;
  *(undefined1 *)((int)param_1 + 0x12d) = 3;
  if (uVar5 != 0x5d) {
    uVar6 = uVar5 & 0xc0;
    bVar7 = uVar6 != 0x40;
    if (!bVar7) {
      uVar6 = uVar5 & 0x30;
    }
    if (bVar7 || uVar6 != 0x10) {
      return 1;
    }
    uVar6 = (uVar5 & 0xf) >> 2;
    bVar2 = (byte)((uVar5 << 0x1c) >> 0x1e);
    *(byte *)((int)param_1 + 0x12d) = bVar2;
    if (uVar6 == 0) {
      return 1;
    }
    if (uVar6 < 3) {
      *(byte *)(param_1 + 0x4b) = bVar2;
    }
    if ((uVar5 & 3) != 1) {
      return 1;
    }
  }
  uVar5 = param_1[0x45];
  param_1[0x45] = uVar5 + 1;
  param_1[0x4c] = uVar5 + 1;
  cVar1 = *(char *)((int)param_1 + 0x11d);
  if (cVar1 == '\x01') {
    iVar4 = wma_input_cache_read
                      (param_1,param_1[1],*param_1 + param_1[0x45],
                       param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
    if (iVar4 != 1) {
      return 3;
    }
    param_1[0x4d] = (uint)MasterStackPointer;
    uVar5 = param_1[0x45] + 1;
LAB_030856f6:
    param_1[0x45] = uVar5;
  }
  else {
    if (cVar1 == '\x02') {
      iVar4 = wma_input_cache_read
                        (param_1,param_1[1],*param_1 + param_1[0x45],
                         param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
      if (iVar4 != 2) {
        return 3;
      }
      param_1[0x4d] = (uint)_MasterStackPointer;
      uVar5 = param_1[0x45] + 2;
      goto LAB_030856f6;
    }
    if (cVar1 == '\x03') {
      iVar4 = wma_input_cache_read
                        (param_1,param_1[1],*param_1 + param_1[0x45],
                         param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
      if (iVar4 != 4) {
        return 3;
      }
      param_1[0x4d] =
           (uint)bRam00000002 * 0x10000 + (uint)MasterStackPointer_1 * 0x100 +
           (uint)MasterStackPointer + (uint)bRam00000003 * 0x1000000;
      param_1[0x45] = param_1[0x45] + 4;
    }
    else {
      param_1[0x4d] = 0;
    }
  }
  param_1[0x4e] = param_1[0x45];
  cVar1 = *(char *)((int)param_1 + 0x125);
  if (cVar1 == '\x01') {
    iVar4 = wma_input_cache_read
                      (param_1,param_1[1],*param_1 + param_1[0x45],
                       param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
    if (iVar4 != 1) {
      return 3;
    }
    param_1[0x4f] = (uint)MasterStackPointer;
    uVar5 = param_1[0x45] + 1;
LAB_03085790:
    param_1[0x45] = uVar5;
  }
  else {
    if (cVar1 == '\x02') {
      iVar4 = wma_input_cache_read
                        (param_1,param_1[1],*param_1 + param_1[0x45],
                         param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
      if (iVar4 != 2) {
        return 3;
      }
      param_1[0x4f] = (uint)_MasterStackPointer;
      uVar5 = param_1[0x45] + 2;
      goto LAB_03085790;
    }
    if (cVar1 == '\x03') {
      iVar4 = wma_input_cache_read
                        (param_1,param_1[1],*param_1 + param_1[0x45],
                         param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
      if (iVar4 != 4) {
        return 3;
      }
      param_1[0x4f] =
           (uint)bRam00000002 * 0x10000 + (uint)MasterStackPointer_1 * 0x100 +
           (uint)MasterStackPointer + (uint)bRam00000003 * 0x1000000;
      param_1[0x45] = param_1[0x45] + 4;
    }
    else {
      param_1[0x4f] = 0;
    }
  }
  param_1[0x50] = param_1[0x45];
  cVar1 = (char)param_1[0x49];
  if (cVar1 == '\x01') {
    uVar5 = *param_1;
    iVar4 = wma_input_cache_read
                      (param_1,uVar5,uVar5 + param_1[0x45],
                       param_1[1] + (uint)CARRY4(uVar5,param_1[0x45]));
    if (iVar4 != 1) {
      return 3;
    }
    param_1[0x51] = (uint)MasterStackPointer;
    uVar5 = param_1[0x45] + 1;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        uVar5 = *param_1;
        iVar4 = wma_input_cache_read
                          (param_1,uVar5,uVar5 + param_1[0x45],
                           param_1[1] + (uint)CARRY4(uVar5,param_1[0x45]));
        if (iVar4 != 4) {
          return 3;
        }
        param_1[0x51] =
             (uint)bRam00000002 * 0x10000 + (uint)MasterStackPointer_1 * 0x100 +
             (uint)MasterStackPointer + (uint)bRam00000003 * 0x1000000;
        param_1[0x45] = param_1[0x45] + 4;
      }
      else {
        param_1[0x51] = 0;
      }
      goto LAB_0308567e;
    }
    uVar5 = *param_1;
    iVar4 = wma_input_cache_read
                      (param_1,uVar5,uVar5 + param_1[0x45],
                       param_1[1] + (uint)CARRY4(uVar5,param_1[0x45]));
    if (iVar4 != 2) {
      return 3;
    }
    param_1[0x51] = (uint)_MasterStackPointer;
    uVar5 = param_1[0x45] + 2;
  }
  param_1[0x45] = uVar5;
LAB_0308567e:
  iVar4 = wma_input_cache_read
                    (param_1,param_1[1],*param_1 + param_1[0x45],
                     param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
  if (iVar4 != 6) {
    return 3;
  }
  param_1[0x52] =
       (uint)MasterStackPointer + (uint)bRam00000003 * 0x1000000 +
       (uint)bRam00000002 * 0x10000 + (uint)MasterStackPointer_1 * 0x100;
  param_1[0x45] = param_1[0x45] + 4;
  *(ushort *)(param_1 + 0x53) = (ushort)Reset + (ushort)bRam00000005 * 0x100;
  param_1[0x54] = 0;
  param_1[0x45] = param_1[0x45] + 2;
  *(undefined1 *)((int)param_1 + 0x14e) = 0;
  *(undefined1 *)((int)param_1 + 0x14f) = 0;
  param_1[0x55] = 1;
  if (param_1[0x4a] != 0) {
    iVar4 = wma_input_cache_read
                      (param_1,param_1[1],*param_1 + param_1[0x45],
                       param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
    uVar3 = _MasterStackPointer;
    if (iVar4 != 1) {
      return 3;
    }
    uVar5 = (uint)MasterStackPointer;
    bVar2 = MasterStackPointer >> 6;
    param_1[0x54] = param_1[0x45];
    *(byte *)((int)param_1 + 0x14e) = bVar2;
    if ((bVar2 != 3 && bVar2 != 2) && bVar2 != 1) {
      FUN_030910d0(s_b__0x_x_b>>6____d_03085c38);
      return 1;
    }
    *(byte *)((int)param_1 + 0x14f) = bVar2;
    param_1[0x55] = uVar5 & 0x3f;
    if ((uVar3 & 0x3f) == 0) {
      return 1;
    }
    param_1[0x45] = param_1[0x45] + 1;
  }
  return 0;
}


