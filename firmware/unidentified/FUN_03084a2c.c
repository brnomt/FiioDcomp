/**
 * FUN_03084a2c @ 0x03084a2c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03084a2c(int param_1,undefined4 param_2,uint *param_3,uint *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  uint *local_18;
  
  local_18 = param_4;
  iVar1 = wma_bitreader_getbits_copy(param_2,0x17,&local_18);
  if (-1 < iVar1) {
    puVar3 = (ushort *)(param_1 + ((uint)local_18 >> 0x1e) * 2);
    uVar2 = (uint)*puVar3;
    if ((*puVar3 & 0x8000) == 0) {
      puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0x3fffffff) >> 0x1c);
      uVar2 = (uint)*puVar3;
      if ((*puVar3 & 0x8000) == 0) {
        puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0xfffffff) >> 0x1a);
        uVar2 = (uint)*puVar3;
        if ((*puVar3 & 0x8000) == 0) {
          puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0x3ffffff) >> 0x18);
          uVar2 = (uint)*puVar3;
          if ((*puVar3 & 0x8000) == 0) {
            puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0xffffff) >> 0x16);
            uVar2 = (uint)*puVar3;
            if ((*puVar3 & 0x8000) == 0) {
              puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0x3fffff) >> 0x14);
              uVar2 = (uint)*puVar3;
              if ((*puVar3 & 0x8000) == 0) {
                puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0xfffff) >> 0x12);
                uVar2 = (uint)*puVar3;
                if ((*puVar3 & 0x8000) == 0) {
                  puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0x3ffff) >> 0x10);
                  uVar2 = (uint)*puVar3;
                  if ((*puVar3 & 0x8000) == 0) {
                    puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0xffff) >> 0xf);
                    uVar2 = (uint)*puVar3;
                    if ((*puVar3 & 0x8000) == 0) {
                      puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0x7fff) >> 0xe);
                      uVar2 = (uint)*puVar3;
                      if ((*puVar3 & 0x8000) == 0) {
                        puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0x3fff) >> 0xd);
                        uVar2 = (uint)*puVar3;
                        if ((*puVar3 & 0x8000) == 0) {
                          puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0x1fff) >> 0xc);
                          uVar2 = (uint)*puVar3;
                          if ((*puVar3 & 0x8000) == 0) {
                            puVar3 = puVar3 + uVar2 + (((uint)local_18 & 0xfff) >> 0xb);
                            uVar2 = (uint)*puVar3;
                            if ((*puVar3 & 0x8000) == 0) {
                              puVar3 = puVar3 + (uVar2 - (((int)local_18 << 0x15) >> 0x1f));
                              uVar2 = (uint)*puVar3;
                              if ((*puVar3 & 0x8000) == 0) {
                                puVar3 = puVar3 + uVar2;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    *param_3 = (uVar2 & 0x7fff) >> 10;
    *param_4 = uVar2 & 0x3ff;
    if (0x3fb < (uVar2 & 0x3ff)) {
      *param_4 = (uint)puVar3[(uVar2 & 3) + 1];
    }
    if (param_5 != (int *)0x0) {
      *param_5 = (int)local_18 << (sbyte)*param_3;
    }
  }
  return iVar1;
}


