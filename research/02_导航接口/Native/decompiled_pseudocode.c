/* BASELINE ANALYSIS ONLY; runtime test-gate patch is described in NATIVE_PATCHES.json. */
/* Package-Date: 2026-10-24. Offline reconstructed code. */
/* GHIDRA RECOVERED PSEUDOCODE - NOT ORIGINAL C SOURCE. */
/* Program: 02_libcarplay_rgi_hook.so */
/* SHA256: f6f574c3c2632f6d80a09fccb4c3fa135ea76df83f1e0c937ed43ad651af476f */
/* Verify types, calling conventions, and inferred control flow against disassembly. */

/* Address 00010ab8 | _init | bytes 8 */

int _init(EVP_PKEY_CTX *ctx)

{
  return (int)ctx;
}



/* Address 00010ad4 | __cxa_finalize | bytes 12 */

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_0001600c)();
  return;
}



/* Address 00010ae0 | pthread_mutex_lock | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_lock_00016010)(__mutex);
  return iVar1;
}



/* Address 00010aec | close | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00016014)(__fd);
  return iVar1;
}



/* Address 00010af8 | calloc | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_calloc_00016018)(__nmemb);
  return pvVar1;
}



/* Address 00010b04 | __get_errno_ptr | bytes 12 */

void __get_errno_ptr(void)

{
  (*(code *)PTR___get_errno_ptr_0001601c)();
  return;
}



/* Address 00010b10 | free | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_00016020)(__ptr);
  return;
}



/* Address 00010b1c | unlink | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_unlink_00016024)(__name);
  return iVar1;
}



/* Address 00010b28 | memcpy | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00016028)(__dest);
  return pvVar1;
}



/* Address 00010b34 | __stack_chk_fail | bytes 12 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_0001602c)();
  return;
}



/* Address 00010b44 | pthread_mutex_unlock | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_unlock_00016030)(__mutex);
  return iVar1;
}



/* Address 00010b50 | lstat | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int lstat(char *__file,stat *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_lstat_00016034)(__file);
  return iVar1;
}



/* Address 00010b5c | fstat | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fstat(int __fd,stat *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fstat_00016038)(__fd);
  return iVar1;
}



/* Address 00010b68 | SHA256_Init | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Init(SHA256_CTX *c)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_SHA256_Init_0001603c)(c);
  return iVar1;
}



/* Address 00010b74 | memset | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00016040)(__s);
  return pvVar1;
}



/* Address 00010b80 | getenv | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_getenv_00016044)(__name);
  return pcVar1;
}



/* Address 00010b8c | read | bytes 12 */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_00016048)(__fd);
  return sVar1;
}



/* Address 00010b98 | vsnprintf | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_vsnprintf_0001604c)(__s);
  return iVar1;
}



/* Address 00010ba4 | __deregister_frame_info | bytes 12 */

void __deregister_frame_info(void)

{
  (*(code *)PTR___deregister_frame_info_00016050)();
  return;
}



/* Address 00010bb0 | __register_frame_info | bytes 12 */

void __register_frame_info(void)

{
  (*(code *)PTR___register_frame_info_00016054)();
  return;
}



/* Address 00010bbc | dlsym | bytes 12 */

void dlsym(void)

{
  (*(code *)PTR_dlsym_00016058)();
  return;
}



/* Address 00010bc8 | write | bytes 12 */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_0001605c)(__fd);
  return sVar1;
}



/* Address 00010bd4 | SHA256_Final | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Final(uchar *md,SHA256_CTX *c)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_SHA256_Final_00016060)(md);
  return iVar1;
}



/* Address 00010be0 | time | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = (*(code *)PTR_time_00016064)(__timer);
  return tVar1;
}



/* Address 00010bec | SHA256_Update | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Update(SHA256_CTX *c,void *data,size_t len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_SHA256_Update_00016068)(c);
  return iVar1;
}



/* Address 00010bf8 | fsync | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fsync(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fsync_0001606c)(__fd);
  return iVar1;
}



/* Address 00010c04 | open | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_00016070)(__file);
  return iVar1;
}



/* Address 00010c10 | rename | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rename(char *__old,char *__new)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_rename_00016074)(__old);
  return iVar1;
}



/* Address 00010c1c | malloc | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00016078)(__size);
  return pvVar1;
}



/* Address 00010c28 | strcmp | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_0001607c)(__s1);
  return iVar1;
}



/* Address 00010c34 | env_enabled | bytes 64 */

undefined4 processEntry env_enabled(char *param_1)

{
  char *__s1;
  int iVar1;
  undefined4 in_r1;
  
  __s1 = getenv(param_1);
  if ((__s1 != (char *)0x0) && (*__s1 != '\0')) {
    iVar1 = strcmp(__s1,(char *)(DAT_00010c74 + 0x10c4c));
    if ((iVar1 == 0) || (iVar1 = strcmp(__s1,(char *)(DAT_00010c78 + 0x10c58)), iVar1 == 0)) {
      in_r1 = 0;
    }
    else {
      iVar1 = strcmp(__s1,(char *)(DAT_00010c7c + 0x10c64));
      in_r1 = 0;
      if (iVar1 != 0) {
        in_r1 = 1;
      }
    }
  }
  return in_r1;
}



/* Address 00010c80 | carplay_rgi_init | bytes 114 */

void carplay_rgi_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  pthread_mutex_t *__mutex;
  
  iVar1 = audi_device_binding_authorized();
  iVar3 = DAT_00010cf0 + 0x10c8c;
  *(int *)(DAT_00010cf0 + 0x11164) = iVar1;
  if (iVar1 == 0) {
    return;
  }
  iVar1 = DAT_00010cf8;
  uVar2 = env_enabled(DAT_00010cf4 + 0x10c9c);
  __mutex = (pthread_mutex_t *)(iVar1 + 0x10ca4);
  *(undefined4 *)(iVar3 + 0x488) = uVar2;
  uVar2 = env_enabled(DAT_00010cfc + 0x10cac);
  *(undefined4 *)(iVar3 + 0x49c) = uVar2;
  uVar2 = env_enabled(DAT_00010d00 + 0x10cba);
  *(undefined4 *)(iVar3 + 0x494) = uVar2;
  uVar2 = env_enabled(DAT_00010d04 + 0x10cc8);
  *(undefined4 *)((int)&DAT_00010d34 + DAT_00010d08) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x498) = uVar2;
  resolve_symbols();
  pthread_mutex_lock(__mutex);
  publish_state_locked();
  (*(code *)PTR_pthread_mutex_unlock_00016030)(__mutex);
  return;
}



/* Address 00010d0c | deregister_tm_clones | bytes 38 */

void deregister_tm_clones(void)

{
  code *pcVar1;
  
  if (6 < (uint)((DAT_00010d34 + 0x10d17) - (DAT_00010d38 + 0x10d1a))) {
    pcVar1 = *(code **)(DAT_00010d3c + 0x10d1e + DAT_00010d40);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
    }
  }
  return;
}



/* Address 00010d44 | register_tm_clones | bytes 44 */

void register_tm_clones(void)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (DAT_00010d74 + 0x10d50) - (DAT_00010d70 + 0x10d4c);
  iVar2 = (iVar2 >> 2) - (iVar2 >> 0x1f) >> 1;
  if ((iVar2 != 0) &&
     (pcVar1 = *(code **)(DAT_00010d78 + 0x10d54 + DAT_00010d7c), pcVar1 != (code *)0x0)) {
    (*pcVar1)(DAT_00010d70 + 0x10d4c,iVar2);
  }
  return;
}



/* Address 00010d80 | __do_global_dtors_aux | bytes 60 */

void __do_global_dtors_aux(void)

{
  int iVar1;
  
  iVar1 = DAT_00010dc0 + 0x10d8e;
  if (*(char *)(DAT_00010dbc + 0x10d8c) == '\0') {
    if (*(int *)(iVar1 + DAT_00010dc4) != 0) {
      __cxa_finalize(*(undefined4 *)(DAT_00010dc8 + 0x10d9c));
    }
    deregister_tm_clones();
    if (*(int *)(iVar1 + DAT_00010dcc) != 0) {
      __deregister_frame_info(DAT_00010dd0 + 0x10db0);
    }
    *(undefined1 *)(DAT_00010dd4 + 0x10dba) = 1;
  }
  return;
}



/* Address 00010dd8 | frame_dummy | bytes 48 */

void frame_dummy(void)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = DAT_00010e08 + 0x10de4;
  if (*(int *)(iVar2 + DAT_00010e0c) != 0) {
    __register_frame_info(DAT_00010e10 + 0x10dee,DAT_00010e14 + 0x10df0);
  }
  if ((*(int *)(DAT_00010e18 + 0x10df8) != 0) &&
     (pcVar1 = *(code **)(iVar2 + DAT_00010e1c), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  register_tm_clones();
  return;
}



/* Address 00010e20 | be64 | bytes 58 */

undefined8 be64(byte *param_1)

{
  return CONCAT44((uint)param_1[1] << 0x10 | (uint)*param_1 << 0x18 | (uint)param_1[3] |
                  (uint)param_1[2] << 8,
                  (uint)param_1[5] << 0x10 | (uint)param_1[4] << 0x18 | (uint)param_1[7] |
                  (uint)param_1[6] << 8);
}



/* Address 00010e5c | tlv_value | bytes 76 */

undefined4
tlv_value(int param_1,uint param_2,int *param_3,undefined2 *param_4,int *param_5,int *param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_3;
  if (((param_2 < iVar2 + 4U) ||
      (uVar3 = (uint)CONCAT11(*(undefined1 *)(param_1 + iVar2),*(undefined1 *)(param_1 + iVar2 + 1))
      , uVar3 < 4)) || (param_2 < uVar3 + iVar2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    *param_4 = CONCAT11(*(undefined1 *)(param_1 + iVar2 + 2),
                        *(undefined1 *)(param_1 + iVar2 + 2 + 1));
    *param_5 = param_1 + iVar2 + 4U;
    *param_6 = uVar3 - 4;
    *param_3 = *param_3 + uVar3;
  }
  return uVar1;
}



/* Address 00010ea8 | message_list_extra | bytes 86 */

int message_list_extra(undefined1 *param_1,undefined1 *param_2,short *param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined1 *puVar6;
  
  if (param_4 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    psVar4 = param_3;
    do {
      psVar5 = psVar4 + 1;
      if (param_2 < (undefined1 *)0x2) {
LAB_00010eee:
        iVar3 = iVar3 + 2;
      }
      else if (*psVar4 != CONCAT11(*param_1,param_1[1])) {
        puVar6 = param_1;
        do {
          if (param_2 <= puVar6 + (3 - (int)param_1)) goto LAB_00010eee;
          puVar1 = puVar6 + 2;
          puVar2 = puVar6 + 3;
          puVar6 = puVar6 + 2;
        } while (*psVar4 != CONCAT11(*puVar1,*puVar2));
      }
      psVar4 = psVar5;
    } while (psVar5 != param_3 + param_4);
  }
  return iVar3;
}



/* Address 00010f00 | resolve_symbols | bytes 616 */

void resolve_symbols(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(DAT_00011168 + 0x10f08);
  if (*piVar3 == 0) {
    iVar2 = dlsym(0xfffffffd,DAT_000111c4 + 0x11022);
    *piVar3 = iVar2;
  }
  iVar2 = DAT_0001116c;
  if (*(int *)(DAT_0001116c + 0x10f18) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111c8 + 0x11032);
    *(undefined4 *)(iVar2 + 0x10f18) = uVar1;
  }
  iVar2 = DAT_00011170;
  if (*(int *)(DAT_00011170 + 0x10f28) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111cc + 0x11042);
    *(undefined4 *)(iVar2 + 0x10f28) = uVar1;
  }
  iVar2 = DAT_00011174;
  if (*(int *)(DAT_00011174 + 0x10f38) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111d0 + 0x11052);
    *(undefined4 *)(iVar2 + 0x10f38) = uVar1;
  }
  iVar2 = DAT_00011178;
  if (*(int *)(DAT_00011178 + 0x10f48) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111d4 + 0x11062);
    *(undefined4 *)(iVar2 + 0x10f48) = uVar1;
  }
  iVar2 = DAT_0001117c;
  if (*(int *)(DAT_0001117c + 0x10f58) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111d8 + 0x11072);
    *(undefined4 *)(iVar2 + 0x10f58) = uVar1;
  }
  iVar2 = DAT_00011180;
  if (*(int *)(DAT_00011180 + 0x10f68) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111dc + 0x11082);
    *(undefined4 *)(iVar2 + 0x10f68) = uVar1;
  }
  iVar2 = DAT_00011184;
  if (*(int *)(DAT_00011184 + 0x10f78) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111e0 + 0x11092);
    *(undefined4 *)(iVar2 + 0x10f78) = uVar1;
  }
  iVar2 = DAT_00011188;
  if (*(int *)(DAT_00011188 + 0x10f88) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111e4 + 0x110a2);
    *(undefined4 *)(iVar2 + 0x10f88) = uVar1;
  }
  iVar2 = DAT_0001118c;
  if (*(int *)(DAT_0001118c + 0x10f98) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111e8 + 0x110b2);
    *(undefined4 *)(iVar2 + 0x10f98) = uVar1;
  }
  iVar2 = DAT_00011190;
  if (*(int *)(DAT_00011190 + 0x10fa8) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111ec + 0x110c2);
    *(undefined4 *)(iVar2 + 0x10fa8) = uVar1;
  }
  iVar2 = DAT_00011194;
  if (*(int *)(DAT_00011194 + 0x10fb8) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111f0 + 0x110d2);
    *(undefined4 *)(iVar2 + 0x10fb8) = uVar1;
  }
  iVar2 = DAT_00011198;
  if (*(int *)(DAT_00011198 + 0x10fc8) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111f4 + 0x110e2);
    *(undefined4 *)(iVar2 + 0x10fc8) = uVar1;
  }
  iVar2 = DAT_0001119c;
  if (*(int *)(DAT_0001119c + 0x10fd8) == 0) {
    uVar1 = dlsym(0xfffffffe,DAT_000111f8 + 0x110f2);
    *(undefined4 *)(iVar2 + 0x10fd8) = uVar1;
  }
  iVar2 = DAT_000111a0;
  if (*(int *)(DAT_000111a0 + 0x10fe8) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111fc + 0x11102);
    *(undefined4 *)(iVar2 + 0x10fe8) = uVar1;
  }
  iVar2 = DAT_000111a4;
  if (*(int *)(DAT_000111a4 + 0x10ff8) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_00011200 + 0x11112);
    *(undefined4 *)(iVar2 + 0x10ff8) = uVar1;
  }
  iVar2 = DAT_000111a8;
  if (*(int *)(DAT_000111a8 + 0x11008) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_00011204 + 0x11122);
    *(undefined4 *)(iVar2 + 0x11008) = uVar1;
  }
  iVar2 = DAT_000111ac;
  if (*(int *)(DAT_000111ac + 0x11018) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_00011208 + 0x11132);
    *(undefined4 *)(iVar2 + 0x11018) = uVar1;
  }
  iVar2 = DAT_000111b0;
  if (*(int *)(DAT_000111b0 + 0x11028) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_0001120c + 0x11142);
    *(undefined4 *)(iVar2 + 0x11028) = uVar1;
  }
  iVar2 = DAT_000111b4;
  if (*(int *)(DAT_000111b4 + 0x11038) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_00011210 + 0x11152);
    *(undefined4 *)(iVar2 + 0x11038) = uVar1;
  }
  iVar2 = DAT_000111b8;
  if (*(int *)(DAT_000111b8 + 0x11048) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_00011214 + 0x11162);
    *(undefined4 *)(iVar2 + 0x11048) = uVar1;
  }
  iVar2 = DAT_000111bc;
  if (*(int *)(DAT_000111bc + 0x11058) == 0) {
    uVar1 = dlsym(0xfffffffd,DAT_000111c0 + 0x11012);
    *(undefined4 *)(iVar2 + 0x11058) = uVar1;
    return;
  }
  return;
}



/* Address 00011218 | find_maneuver | bytes 154 */

undefined4 * find_maneuver(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *__s;
  
  __s = (undefined4 *)0x0;
  iVar2 = DAT_000112b4 + 0x11282;
  iVar1 = 0;
  do {
    if (*(int *)(iVar2 + 0x28c) == 0) {
      if (__s == (undefined4 *)0x0) {
        __s = (undefined4 *)(iVar1 * 0x334 + DAT_000112b8 + 0x11510);
      }
    }
    else if (*(ushort *)(iVar2 + 0x290) == param_1) {
      return (undefined4 *)(iVar1 * 0x334 + DAT_000112bc + 0x11572);
    }
    iVar2 = iVar2 + 0x334;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x10);
  if (param_2 == 0) {
    __s = (undefined4 *)0x0;
  }
  else {
    if (__s == (undefined4 *)0x0) {
      __s = (undefined4 *)((param_1 & 0xf) * 0x334 + DAT_000112c0 + 0x1158a);
    }
    memset(__s,0,0x334);
    *(short *)(__s + 1) = (short)param_1;
    *__s = 1;
    *(undefined2 *)((int)__s + 10) = 1000;
  }
  return __s;
}



/* Address 000112c4 | copy_message_list | bytes 162 */

size_t copy_message_list(undefined1 *param_1,void *param_2,size_t param_3,short *param_4,int param_5
                        )

{
  undefined1 *puVar1;
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  undefined1 *puVar8;
  uint uVar9;
  
  uVar9 = param_3 - 4;
  iVar4 = message_list_extra((undefined1 *)((int)param_2 + 4),uVar9,param_4,param_5,param_4);
  memcpy(param_1,param_2,param_3);
  uVar5 = iVar4 + param_3 & 0xffff;
  param_1[1] = (char)uVar5;
  *param_1 = (char)(uVar5 >> 8);
  if (param_5 == 0) {
    return param_3;
  }
  uVar5 = param_3 - 6;
  psVar6 = param_4;
  do {
    psVar7 = psVar6 + 1;
    sVar3 = *psVar6;
    if (uVar9 < 2) {
LAB_0001134a:
      param_1[param_3] = (char)((ushort)sVar3 >> 8);
      param_1[param_3 + 1] = (char)sVar3;
      param_3 = param_3 + 2;
    }
    else if (sVar3 != CONCAT11(*(undefined1 *)((int)param_2 + 4),*(undefined1 *)((int)param_2 + 5)))
    {
      puVar8 = (undefined1 *)((int)param_2 + 6);
      do {
        if (puVar8 == (undefined1 *)((int)param_2 + 6) + (uVar5 & 0xfffffffe)) goto LAB_0001134a;
        uVar2 = *puVar8;
        puVar1 = puVar8 + 1;
        puVar8 = puVar8 + 2;
      } while (sVar3 != CONCAT11(uVar2,*puVar1));
    }
    psVar6 = psVar7;
    if (psVar7 == param_4 + param_5) {
      return param_3;
    }
  } while( true );
}



/* Address 00011368 | clean_string.part.0 | bytes 112 */

void clean_string_part_0(int param_1,uint param_2,byte *param_3,int param_4)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_2 < 2) {
      uVar1 = 0;
    }
    else {
      bVar2 = *param_3;
      if (bVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar3 = 1;
        pbVar4 = param_3 + param_4 + -1;
        uVar1 = 0;
        do {
          if (bVar2 < 0x20) {
            if (((uVar1 != 0) && (*(char *)(param_1 + uVar1 + -1) != ' ')) && (uVar1 + 3 < param_2))
            {
              *(undefined1 *)(param_1 + uVar1) = 0x20;
              *(undefined1 *)(param_1 + uVar3) = 0x2f;
              *(undefined1 *)(param_1 + uVar1 + 2) = 0x20;
              uVar1 = uVar1 + 3;
            }
          }
          else {
            *(byte *)(param_1 + uVar1) = bVar2;
            uVar1 = uVar3;
          }
          uVar3 = uVar1 + 1;
          if ((param_3 == pbVar4) || (param_2 <= uVar3)) break;
          param_3 = param_3 + 1;
          bVar2 = *param_3;
        } while (bVar2 != 0);
      }
    }
  }
  *(undefined1 *)(param_1 + uVar1) = 0;
  return;
}



/* Address 000113d8 | transport_write_raw.part.1 | bytes 26 */

undefined4 transport_write_raw_part_1(undefined4 *param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (((*(int **)*param_1 == (int *)0x0) || (iVar1 = **(int **)*param_1, iVar1 == 0)) ||
     (pcVar2 = *(code **)(iVar1 + 0x10), pcVar2 == (code *)0x0)) {
    return 0;
  }
  (*pcVar2)();
  return 1;
}



/* Address 000113f4 | build_start_frame.part.2 | bytes 78 */

undefined4 build_start_frame_part_2(undefined1 *param_1)

{
  param_1[2] = 0;
  *param_1 = 0x40;
  param_1[1] = 0x40;
  param_1[3] = 0x18;
  param_1[5] = 0;
  param_1[4] = 0x52;
  param_1[6] = 0;
  param_1[7] = 6;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0x10;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 1;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0xd] = 4;
  param_1[0x11] = 4;
  param_1[0x13] = 2;
  param_1[0x15] = 4;
  param_1[0x17] = 3;
  return 0x18;
}



/* Address 00011444 | wire_control_message_id.part.3 | bytes 82 */

undefined2 wire_control_message_id_part_3(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (5 < param_2) {
    iVar1 = 0;
    iVar2 = param_1 + -1;
    do {
      iVar3 = iVar2 + 8;
      if ((((*(char *)(iVar2 + 1) == '@') && (*(char *)(iVar2 + 2) == '@')) &&
          (uVar4 = (uint)CONCAT11(*(undefined1 *)(iVar2 + 3),*(undefined1 *)(iVar2 + 4)), 5 < uVar4)
          ) && (iVar1 + uVar4 <= param_2)) {
        return CONCAT11(*(undefined1 *)(param_1 + iVar1 + 4),
                        *(undefined1 *)(param_1 + iVar1 + 4 + 1));
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 1;
    } while ((uint)(iVar3 - param_1) <= param_2);
  }
  return 0;
}



/* Address 00011498 | append_text.constprop.8 | bytes 94 */

void append_text_constprop_8
               (int param_1,undefined4 param_2,uint *param_3,char *param_4,undefined1 param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined1 uStack00000000;
  
  uVar1 = *param_3;
  piVar3 = *(int **)(DAT_000114f8 + 0x114a2 + DAT_000114fc);
  iVar2 = *piVar3;
  if ((uVar1 < 0x8000) &&
     (uVar1 = vsnprintf((char *)(param_1 + uVar1),0x8000 - uVar1,param_4,&param_5), -1 < (int)uVar1)
     ) {
    if (uVar1 < 0x8000 - *param_3) {
      *param_3 = uVar1 + *param_3;
    }
    else {
      *param_3 = 0x8000;
    }
  }
  if (iVar2 != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 00011500 | carplay_rgi_is_wireless_session | bytes 66 */

bool carplay_rgi_is_wireless_session(int param_1)

{
  bool bVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00011544 + 0x1150a));
  if (*(int *)(DAT_00011548 + 0x1199a) == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = false;
    if (param_1 != 0) {
      if (*(int *)(DAT_00011548 + 0x1199e) == param_1) {
        bVar1 = *(int *)(DAT_00011548 + 0x119a2) - 1U < 2;
      }
      else {
        bVar1 = false;
      }
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_0001154c + 0x11528));
  return bVar1;
}



/* Address 00011550 | write | bytes 556 */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  short sVar1;
  void *__ptr;
  uint uVar2;
  uint uVar3;
  pthread_mutex_t *__mutex;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int *piVar10;
  uint local_4c;
  uint3 local_48;
  undefined1 uStack_45;
  undefined1 uStack_44;
  char local_43;
  undefined2 uStack_42;
  char local_40;
  char local_3f [27];
  int local_24;
  
  iVar9 = DAT_00011784;
  piVar10 = *(int **)(DAT_0001177c + 0x1155e + DAT_00011780);
  local_24 = *piVar10;
  resolve_symbols();
  if (*(int *)(iVar9 + 0x11570) == 0) {
    puVar4 = (undefined4 *)__get_errno_ptr();
    uVar2 = 0xffffffff;
    *puVar4 = 5;
  }
  else {
    __ptr = (void *)make_identify_patch(__buf,__n,&local_4c);
    if (__ptr == (void *)0x0) {
      uVar2 = (**(code **)(iVar9 + 0x11570))(__fd,__buf,__n);
      if ((((((uVar2 == __n) && (uVar3 = time((time_t *)0x0), *(int *)(iVar9 + 0x11570) != 0)) &&
            (*(int *)(DAT_00011788 + 0x11a70) == 0)) &&
           ((*(int *)(DAT_00011788 + 0x11a74) == 0 && (*(int *)(DAT_00011788 + 0x11a78) != 0)))) &&
          ((9 < uVar2 && ((*(char *)__buf == -1 && (*(char *)((int)__buf + 1) == 'Z')))))) &&
         (__n == CONCAT11(*(undefined1 *)((int)__buf + 2),*(undefined1 *)((int)__buf + 3)))) {
        pcVar5 = (char *)((int)__buf + 8);
        for (iVar9 = 9; iVar9 + 6U <= __n; iVar9 = iVar9 + 1) {
          if ((((pcVar5[1] == '@') && (pcVar5[2] == '@')) && (5 < CONCAT11(pcVar5[3],pcVar5[4]))) &&
             (iVar9 + (uint)CONCAT11(pcVar5[3],pcVar5[4]) <= __n)) {
            sVar1 = CONCAT11(*(undefined1 *)((int)__buf + iVar9 + 4),
                             *(undefined1 *)((int)__buf + iVar9 + 5));
            if (((sVar1 != 0x1d01) && (sVar1 != 0)) && (sVar1 != 0x5200)) {
              pthread_mutex_lock((pthread_mutex_t *)(DAT_0001178c + 0x1166e));
              if (((*(int *)(DAT_00011790 + 0x11b16) == 0) &&
                  (iVar9 = *(int *)(DAT_00011790 + 0x11b1a), iVar9 < 5)) &&
                 ((*(int *)(DAT_00011794 + 0x11b32) != 0 && (*(int *)(DAT_00011794 + 0x11b36) != 0))
                 )) {
                if (*(int *)(DAT_00011794 + 0x11b3a) == 0) {
                  *(uint *)(DAT_00011794 + 0x11b3a) = uVar3 + 2;
                }
                iVar6 = DAT_0001179c;
                if ((*(uint *)(DAT_00011798 + 0x11b5a) <= uVar3) &&
                   ((*(int *)(DAT_00011798 + 0x11b5e) == 0 ||
                    (1 < uVar3 - *(int *)(DAT_00011798 + 0x11b5e))))) {
                  __mutex = (pthread_mutex_t *)(DAT_000117a0 + 0x116cc);
                  *(uint *)(DAT_0001179c + 0x11b7c) = uVar3;
                  *(int *)(iVar6 + 0x11b6c) = iVar9 + 1;
                  pthread_mutex_unlock(__mutex);
                  memset(&local_48,0,0x22);
                  local_40 = '\0';
                  iVar9 = 0;
                  _local_48 = CONCAT13(0x22,(uint3)*(undefined4 *)__buf & 0xffff);
                  uStack_42 = (undefined2)((uint)*(undefined4 *)((int)__buf + 4) >> 0x10);
                  _uStack_44 = CONCAT11(*(char *)((int)__buf + 5) + '\x01',
                                        (char)*(undefined4 *)((int)__buf + 4));
                  do {
                    pcVar5 = (char *)((int)&local_48 + iVar9);
                    iVar9 = iVar9 + 1;
                    local_40 = local_40 + *pcVar5;
                  } while (iVar9 != 8);
                  local_40 = -local_40;
                  iVar9 = build_start_frame_part_2(local_3f);
                  if (iVar9 != 0) {
                    cVar8 = '\0';
                    iVar6 = 0;
                    do {
                      iVar7 = iVar6 + 1;
                      cVar8 = cVar8 + local_3f[iVar6];
                      iVar6 = iVar7;
                    } while (iVar7 != iVar9);
                    local_3f[iVar9] = -cVar8;
                    (**(code **)(DAT_000117a4 + 0x11760))(__fd,&local_48,0x22);
                  }
                  break;
                }
              }
              pthread_mutex_unlock((pthread_mutex_t *)(DAT_000117a8 + 0x11778));
            }
            break;
          }
          pcVar5 = pcVar5 + 1;
        }
      }
    }
    else {
      uVar2 = (**(code **)(iVar9 + 0x11570))(__fd,__ptr,local_4c);
      free(__ptr);
      if (local_4c == uVar2) {
        uVar2 = __n;
      }
    }
  }
  if (local_24 != *piVar10) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



/* Address 000117ac | publish_state_locked | bytes 1988 */

void publish_state_locked(void)

{
  uint uVar1;
  size_t sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *__file;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  int local_8054;
  uint local_8030;
  undefined1 auStack_802c [32768];
  int local_2c;
  
  iVar7 = DAT_00011f80;
  piVar3 = *(int **)(DAT_00011f70 + 0x117b8 + DAT_00011f74);
  local_8030 = 0;
  local_2c = *piVar3;
  uVar17 = (uint)*(byte *)(DAT_00011f78 + 0x11aaa);
  if (uVar17 == 0) {
    iVar5 = DAT_00011f78 + 0x11822;
    do {
      if (*(int *)(iVar5 + 0x28c) != 0) {
        uVar17 = uVar17 + 1 & 0xff;
      }
      iVar5 = iVar5 + 0x334;
    } while (iVar5 != DAT_00011f78 + 0x14b62);
  }
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011f7c + 0x1180e);
  iVar5 = DAT_00011f8c;
  iVar7 = iVar7 + 0x1181c;
  if (*(int *)(DAT_00011f84 + 0x11876) == 0) {
    iVar7 = DAT_00011f88 + 0x11828;
  }
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011f90 + 0x1183c,iVar7);
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_00011f94 + 0x11852,*(undefined4 *)(iVar5 + 0x11894)
            );
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011f98 + 0x11866,iVar5 + 0x119b8);
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011f9c + 0x1187e,iVar5 + 0x118b8);
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_00011fa0 + 0x11898,*(undefined4 *)(iVar5 + 0x118a0)
            );
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_00011fa4 + 0x118b0,*(undefined4 *)(iVar5 + 0x118a8)
             ,*(undefined4 *)(iVar5 + 0x118ac));
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_00011fa8 + 0x118ca,*(undefined4 *)(iVar5 + 0x118b0)
             ,*(undefined4 *)(iVar5 + 0x118b4));
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011fac + 0x118e0,iVar5 + 0x11ab8);
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_00011fb0 + 0x118fa,*(undefined4 *)(iVar5 + 0x11898)
            );
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_00011fb4 + 0x11910,*(undefined4 *)(iVar5 + 0x118a4)
            );
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_00011fb8 + 0x11926,*(undefined4 *)(iVar5 + 0x1189c)
            );
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011fbc + 0x11938,uVar17);
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011fc0 + 0x11950);
  iVar9 = DAT_00011fd0;
  iVar7 = DAT_00011fc4;
  if (uVar17 != 0) {
    uVar10 = 0;
    iVar8 = DAT_00011fc8 + 0x11974;
    iVar12 = DAT_00011fcc + 0x11976;
    do {
      uVar1 = (uint)*(byte *)(iVar5 + 0x11b18);
      iVar6 = iVar5 + 0x11890;
      iVar4 = 0;
      if (uVar1 == 0) {
        do {
          if ((*(int *)(iVar6 + 0x28c) != 0) &&
             (bVar19 = uVar10 == uVar1, uVar1 = uVar1 + 1 & 0xff, bVar19)) {
            iVar4 = iVar4 * 0x334 + iVar7 + 0x11c52;
            goto LAB_00011d4a;
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0x334;
        } while (iVar4 != 0x10);
LAB_000119b4:
        iVar6 = DAT_00011fdc;
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_00011fd8 + 0x119d6,uVar10,
                   *(undefined2 *)(DAT_00011fd4 + (uVar10 + 0x134) * 2 + 0x11a1c));
        iVar6 = iVar6 + 0x119f6;
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011fe0 + 0x119f2,uVar10,0);
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011fe4 + 0x11a0a,uVar10,0);
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011fe8 + 0x11a20,uVar10,0);
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011fec + 0x11a36,uVar10,1000);
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011ff0 + 0x11a4c,uVar10,0);
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011ff4 + 0x11a62,uVar10,iVar6)
        ;
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011ff8 + 0x11a78,uVar10,iVar6)
        ;
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00011ffc + 0x11a8e,uVar10,iVar6)
        ;
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012000 + 0x11aa2,uVar10);
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012004 + 0x11ab8);
        if (uVar10 == 0) {
LAB_00011abe:
          append_text_constprop_8(auStack_802c,0x8000,&local_8030,iVar8,0,iVar6);
          iVar13 = DAT_00012008 + 0x11ae8;
          append_text_constprop_8
                    (auStack_802c,0x8000,&local_8030,iVar12,*(undefined4 *)(iVar9 + 0x119e6));
          append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_0001200c + 0x11afa,iVar13);
          append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012010 + 0x11b0a,iVar13);
LAB_00011b14:
          append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012014 + 0x11b26,iVar13);
        }
      }
      else {
        iVar4 = find_maneuver(*(undefined2 *)(iVar5 + (uVar10 + 0x134) * 2 + 0x11890),0);
        if (iVar4 == 0) goto LAB_000119b4;
LAB_00011d4a:
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_0001205c + 0x11d62,uVar10,
                   *(undefined2 *)(iVar4 + 4));
        iVar13 = iVar4 + 0x210;
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_00012060 + 0x11d82,uVar10,
                   *(undefined1 *)(iVar4 + 6));
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_00012064 + 0x11d98,uVar10,
                   *(undefined1 *)(iVar4 + 7));
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_00012068 + 0x11dae,uVar10,
                   *(undefined1 *)(iVar4 + 8));
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_0001206c + 0x11dc6,uVar10,
                   (int)*(short *)(iVar4 + 10));
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_00012070 + 0x11ddc,uVar10,
                   *(undefined4 *)(iVar4 + 0xc));
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_00012074 + 0x11df0,uVar10,iVar4 + 0x10);
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_00012078 + 0x11e04,uVar10,iVar4 + 0x110);
        iVar6 = iVar13;
        append_text_constprop_8
                  (auStack_802c,0x8000,&local_8030,DAT_0001207c + 0x11e18,uVar10,iVar13);
        uVar1 = uVar10;
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012080 + 0x11e28,uVar10);
        if (*(char *)(iVar4 + 0x330) != '\0') {
          uVar16 = 0;
          iVar14 = DAT_00012088 + 0x11e4a;
          uVar15 = DAT_0001208c + 0x11e4c;
          uVar11 = DAT_00012090 + 0x11e50;
          uVar1 = DAT_00012084 + 0x11e46;
          while( true ) {
            iVar6 = (int)*(short *)(iVar4 + (uVar16 + 0x188) * 2);
            uVar16 = uVar16 + 1 & 0xff;
            append_text_constprop_8(auStack_802c,0x8000,&local_8030,iVar14,uVar1,iVar6);
            if (*(byte *)(iVar4 + 0x330) <= uVar16) break;
            if (uVar16 == 0) {
              uVar1 = uVar11;
            }
            else {
              uVar1 = uVar15;
            }
          }
        }
        append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012094 + 0x11e94,uVar1,iVar6);
        if (uVar10 == 0) {
          if (iVar4 == 0) goto LAB_00011abe;
          append_text_constprop_8
                    (auStack_802c,0x8000,&local_8030,DAT_00012098 + 0x11eb2,
                     *(undefined1 *)(iVar4 + 6),iVar6);
          append_text_constprop_8
                    (auStack_802c,0x8000,&local_8030,DAT_0001209c + 0x11ec6,
                     *(undefined4 *)(iVar4 + 0xc));
          append_text_constprop_8
                    (auStack_802c,0x8000,&local_8030,DAT_000120a0 + 0x11eda,iVar4 + 0x10);
          append_text_constprop_8
                    (auStack_802c,0x8000,&local_8030,DAT_000120a4 + 0x11eee,iVar4 + 0x110);
          goto LAB_00011b14;
        }
      }
      uVar10 = uVar10 + 1 & 0xff;
    } while (uVar10 < uVar17 && uVar10 < 0x10);
  }
  iVar7 = DAT_00012024;
  iVar5 = DAT_0001201c + 0x11b50;
  if (((*(int *)(DAT_00012018 + 0x11bb2) != 0) &&
      (iVar5 = DAT_00012020 + 0x11b62, *(char *)(DAT_00012018 + 0x152b6) != '\0')) &&
     (iVar5 = DAT_000120a8 + 0x11f12,
     *(short *)(DAT_00012018 + 0x15172) != *(short *)(DAT_00012018 + 0x15174))) {
    iVar5 = DAT_000120ac + 0x11f1e;
  }
  append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012028 + 0x11b80,iVar5);
  append_text_constprop_8
            (auStack_802c,0x8000,&local_8030,DAT_0001202c + 0x11b98,*(undefined1 *)(iVar7 + 0x152e0)
            );
  if (*(char *)(iVar7 + 0x152e0) != '\0') {
    uVar10 = 0;
    iVar12 = DAT_00012030 + 0x11bba;
    iVar8 = DAT_00012034 + 0x11bc0;
    iVar5 = DAT_00012038 + 0x11bc6;
    iVar4 = DAT_0001203c + 0x11bd2;
    iVar9 = iVar7 + 0x151a0;
    uVar17 = DAT_00012040 + 0x11bd8;
    local_8054 = iVar7 + 0x151c6;
    do {
      append_text_constprop_8
                (auStack_802c,0x8000,&local_8030,iVar12,uVar10,*(undefined2 *)(local_8054 + -0x26));
      append_text_constprop_8
                (auStack_802c,0x8000,&local_8030,iVar5,uVar10,(int)*(short *)(local_8054 + -0x24));
      uVar11 = (uint)*(byte *)(local_8054 + -0x22);
      append_text_constprop_8(auStack_802c,0x8000,&local_8030,iVar8,uVar10,uVar11);
      uVar1 = uVar10;
      append_text_constprop_8(auStack_802c,0x8000,&local_8030,iVar4,uVar10);
      iVar6 = DAT_00012048;
      if (*(char *)(iVar9 + 0x26) != '\0') {
        uVar18 = 0;
        iVar13 = DAT_00012044 + 0x11c5a;
        uVar16 = DAT_0001204c + 0x11c62;
        uVar15 = DAT_00012050 + 0x11c66;
        uVar1 = uVar17;
        while( true ) {
          uVar11 = (uint)*(short *)(iVar6 + (uVar10 * 0x14 + uVar18 + 0x1ae8) * 2 + 0x11cbe);
          uVar18 = uVar18 + 1 & 0xff;
          append_text_constprop_8(auStack_802c,0x8000,&local_8030,iVar13,uVar1,uVar11);
          if (*(byte *)(iVar9 + 0x26) <= uVar18) break;
          if (uVar18 == 0) {
            uVar1 = uVar15;
          }
          else {
            uVar1 = uVar16;
          }
        }
      }
      uVar10 = uVar10 + 1;
      append_text_constprop_8(auStack_802c,0x8000,&local_8030,DAT_00012054 + 0x11cb8,uVar1,uVar11);
      if ((uint)*(byte *)(iVar7 + 0x152e0) <= (uVar10 & 0xff)) break;
      iVar9 = iVar9 + 0x28;
      local_8054 = local_8054 + 0x28;
    } while (uVar10 != 8);
  }
  __file = (char *)(DAT_00012058 + 0x11cea);
  if (0x8000 < local_8030) {
    local_8030 = 0x8000;
  }
  iVar7 = open(__file,0x301,0x1b6);
  if (-1 < iVar7) {
    sVar2 = write(iVar7,auStack_802c,local_8030);
    iVar5 = DAT_000120b0;
    if (sVar2 == local_8030) {
      fsync(iVar7);
      close(iVar7);
      iVar7 = rename(__file,(char *)(iVar5 + 0x11f2c));
      if (iVar7 != 0) {
        iVar7 = open((char *)(iVar5 + 0x11f2c),0x301,0x1b6);
        if (-1 < iVar7) {
          write(iVar7,auStack_802c,local_8030);
          fsync(iVar7);
          close(iVar7);
        }
        unlink((char *)(DAT_000120b4 + 0x11f68));
      }
    }
    else {
      close(iVar7);
    }
  }
  if (local_2c != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 000120b8 | observe_frame | bytes 1898 */

void observe_frame(char *param_1,uint param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  undefined2 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  void *pvVar18;
  uint uVar19;
  char cVar20;
  int *piVar21;
  int iVar22;
  uint uVar23;
  bool bVar24;
  undefined8 uVar25;
  short local_48;
  ushort local_46;
  undefined4 local_44;
  byte *local_40;
  uint local_3c [2];
  byte *local_34;
  byte *local_30;
  int local_2c;
  
  piVar21 = *(int **)(DAT_000128a8 + 0x120ca + DAT_000128ac);
  local_2c = *piVar21;
  if ((((param_1 == (char *)0x0 || param_2 < 6) || (*param_1 != '@')) || (param_1[1] != '@')) ||
     (uVar23 = (uint)CONCAT11(param_1[2],param_1[3]), uVar23 != param_2)) goto LAB_000120e2;
  sVar3 = CONCAT11(param_1[4],param_1[5]);
  pthread_mutex_lock((pthread_mutex_t *)(DAT_000128b0 + 0x1211a));
  iVar8 = DAT_000128f0;
  iVar4 = DAT_000128ec;
  iVar13 = DAT_000128c8;
  iVar11 = DAT_000128c4;
  iVar10 = DAT_000128c0;
  bVar24 = param_3 != 0;
  if (sVar3 == 0x1d02 && bVar24) {
    *(undefined4 *)(DAT_000128b4 + 0x125ec) = 1;
LAB_00012146:
    publish_state_locked();
  }
  else {
    if (sVar3 == -0x55fb && bVar24) {
      *(undefined4 *)(DAT_000128bc + 0x1261c) = 1;
      goto LAB_00012146;
    }
    if (sVar3 == 0x5201 && bVar24) {
      *(undefined4 *)(DAT_000128e8 + 0x127f2) = 1;
      local_3c[1] = 6;
      *(undefined4 *)((int)&UINT_000123cc + DAT_000128f4) = 1;
      iVar11 = DAT_000128fc;
      iVar10 = DAT_000128f8;
      bVar24 = false;
switchD_000123bc_caseD_2:
      iVar16 = tlv_value(param_1,uVar23,local_3c + 1,&local_46,&local_34,&local_30);
      iVar13 = DAT_00012904;
      if (iVar16 != 0) {
        switch(local_46) {
        case 1:
          if (local_30 != (byte *)0x0) {
            bVar24 = true;
            *(uint *)(DAT_00012920 + 0x125ce) = (uint)*local_34;
          }
          break;
        case 3:
          clean_string_part_0(DAT_0001291c + 0x125d4,0x100,local_34,local_30);
          break;
        case 4:
          clean_string_part_0(DAT_00012918 + 0x126be,0x100,local_34,local_30);
          break;
        case 5:
          if ((byte *)0x7 < local_30) {
            uVar25 = be64(local_34);
            *(undefined8 *)(DAT_00012914 + 0x1259e) = uVar25;
          }
          break;
        case 6:
          if ((byte *)0x7 < local_30) {
            uVar25 = be64(local_34);
            *(undefined8 *)(DAT_00012910 + 0x1258e) = uVar25;
          }
          break;
        case 7:
          if ((byte *)0x3 < local_30) {
            *(uint *)(DAT_0001290c + 0x12568) =
                 (uint)local_34[1] << 0x10 | (uint)*local_34 << 0x18 | (uint)local_34[3] |
                 (uint)local_34[2] << 8;
          }
          break;
        case 10:
          if ((byte *)0x3 < local_30) {
            *(uint *)(DAT_00012908 + 0x12544) =
                 (uint)local_34[1] << 0x10 | (uint)*local_34 << 0x18 | (uint)local_34[3] |
                 (uint)local_34[2] << 8;
          }
          break;
        case 0xd:
          *(undefined1 *)(DAT_00012904 + 0x1274a) = 0;
          if (&BUILDENV_qss < local_30) {
            cVar20 = '\x01';
            iVar16 = 0;
            do {
              iVar14 = iVar16 + 2;
              *(ushort *)(iVar13 + iVar16 + 0x1272a) =
                   CONCAT11(local_34[iVar16],local_34[iVar16 + 1]);
              *(char *)(iVar13 + 0x1274a) = cVar20;
              if (iVar14 == ((uint)(local_30 + -2) & 0xfffffffe) + 2) break;
              cVar20 = cVar20 + '\x01';
              iVar16 = iVar14;
            } while (iVar14 != 0x20);
          }
          break;
        case 0x10:
          if (local_30 < (byte *)0x2) {
            if (local_30 != (byte *)0x0) {
              *(ushort *)(iVar10 + 0x159a4) = (ushort)*local_34;
            }
          }
          else {
            *(ushort *)(iVar11 + 0x159b0) = CONCAT11(*local_34,local_34[1]);
          }
          break;
        case 0x12:
          if (local_30 != (byte *)0x0) {
            *(uint *)((int)&UINT_000123d4 + iVar8) = (uint)*local_34;
          }
          break;
        case 0x13:
          clean_string_part_0(DAT_00012900 + 0x126ac,0x40,local_34,local_30);
          break;
        case 0x14:
          if (local_30 != (byte *)0x0) {
            *(uint *)((int)&UINT_000123c8 + iVar4 + 2) = (uint)*local_34;
          }
        }
        goto switchD_000123bc_caseD_2;
      }
      if ((bVar24) && (*(int *)(DAT_00012924 + 0x125e0) == 0)) {
        *(undefined1 *)(DAT_00012924 + 0x12804) = 0;
      }
      goto LAB_00012146;
    }
    if (sVar3 == 0x5202 && bVar24) {
      local_3c[0] = 6;
      *(undefined4 *)(DAT_00012928 + 0x12a40) = 1;
      local_3c[1] = 6;
      do {
        iVar10 = tlv_value(param_1,uVar23,local_3c + 1,&local_46,&local_34,&local_30);
        uVar7 = 0;
        if (iVar10 == 0) goto LAB_000125de;
      } while ((local_46 != 1) || (local_30 < (byte *)0x2));
      uVar7 = CONCAT11(*local_34,local_34[1]);
LAB_000125de:
      iVar10 = find_maneuver(uVar7,1);
      if (iVar10 != 0) {
        *(undefined4 *)((int)&UINT_00012654 + DAT_0001292c) = 1;
switchD_00012636_caseD_6:
        iVar11 = tlv_value(param_1,uVar23,local_3c,&local_46,&local_34,&local_30);
        if (iVar11 != 0) {
          switch(local_46) {
          case 1:
            if (&BUILDENV_qss < local_30) {
              *(ushort *)(iVar10 + 4) = CONCAT11(*local_34,local_34[1]);
            }
            break;
          case 2:
            clean_string_part_0(iVar10 + 0x10,0x100,local_34,local_30);
            break;
          case 3:
            if (local_30 != (byte *)0x0) {
              *(byte *)(iVar10 + 6) = *local_34;
            }
            break;
          case 4:
            clean_string_part_0(iVar10 + 0x110,0x100,local_34,local_30);
            break;
          case 5:
            if ((byte *)0x3 < local_30) {
              *(uint *)(iVar10 + 0xc) =
                   (uint)local_34[1] << 0x10 | (uint)*local_34 << 0x18 | (uint)local_34[3] |
                   (uint)local_34[2] << 8;
            }
            break;
          case 8:
            if (local_30 != (byte *)0x0) {
              *(byte *)(iVar10 + 7) = *local_34;
            }
            break;
          case 9:
            if (local_30 != (byte *)0x0) {
              *(byte *)(iVar10 + 8) = *local_34;
            }
            break;
          case 10:
            *(undefined1 *)(iVar10 + 0x330) = 0;
            if (&BUILDENV_qss < local_30) {
              cVar20 = '\x01';
              iVar11 = 0;
              do {
                iVar13 = iVar11 + 2;
                *(ushort *)(iVar10 + iVar11 + 0x310) =
                     CONCAT11(local_34[iVar11],local_34[iVar11 + 1]);
                *(char *)(iVar10 + 0x330) = cVar20;
                if (iVar13 == ((uint)(local_30 + -2) & 0xfffffffe) + 2) break;
                cVar20 = cVar20 + '\x01';
                iVar11 = iVar13;
              } while (iVar13 != 0x20);
            }
            break;
          case 0xb:
            if (&BUILDENV_qss < local_30) {
              *(ushort *)(iVar10 + 10) = CONCAT11(*local_34,local_34[1]);
            }
            break;
          case 0xd:
            clean_string_part_0(iVar10 + 0x210,0x100,local_34,local_30);
          }
          goto switchD_00012636_caseD_6;
        }
      }
      goto LAB_00012146;
    }
    if (sVar3 == 0x5204 && bVar24) {
      *(undefined4 *)(DAT_000128c4 + 0x12220) = 1;
      *(undefined1 *)(iVar11 + 0x15930) = 0;
      *(undefined4 *)(iVar13 + 0x12670) = 1;
      iVar13 = DAT_000128d0;
      iVar11 = DAT_000128cc;
      local_44 = 6;
      while (iVar8 = tlv_value(param_1,uVar23,&local_44,&local_48,&local_40,local_3c),
            uVar6 = local_3c[0], pbVar5 = local_40, iVar4 = DAT_000128d4, iVar8 != 0) {
        if (local_48 == 1) {
          if (local_3c[0] < 2) {
            if (local_3c[0] != 0) {
              *(ushort *)(iVar11 + 0x15816) = (ushort)*local_40;
            }
          }
          else {
            *(ushort *)(DAT_000128e4 + 0x15956) = CONCAT11(*local_40,local_40[1]);
          }
        }
        else if (local_48 == 2) {
          local_3c[1] = 0;
          iVar8 = DAT_000128d8 + 0x12250;
          iVar16 = DAT_000128dc + 0x12258;
          uVar19 = 0xffffffff;
LAB_00012258:
          iVar9 = tlv_value(pbVar5,uVar6,local_3c + 1,&local_46,&local_34,&local_30);
          iVar14 = DAT_000128e0;
          if (iVar9 != 0) {
            uVar17 = (uint)local_46;
            if (uVar17 != 0) {
              if (uVar17 - 1 < 3) {
                if (uVar19 == 0xffffffff) {
                  bVar2 = *(byte *)(iVar10 + 0x15924);
                  uVar15 = (uint)bVar2;
                  if (7 < uVar15) goto LAB_00012258;
                  *(byte *)(iVar10 + 0x15924) = bVar2 + 1;
                  iVar14 = uVar15 * 0x28 + 0x35d0;
                  pvVar18 = (void *)(iVar10 + 0x12214 + iVar14);
                  memset(pvVar18,0,0x28);
                  *(ushort *)(iVar10 + 0x12214 + iVar14) = (ushort)bVar2;
                  *(undefined2 *)((int)pvVar18 + 2) = 1000;
                  uVar19 = uVar15;
                }
              }
              else if (uVar19 == 0xffffffff) goto LAB_00012258;
              if (uVar17 == 1) {
                if (local_30 != (byte *)0x0) {
                  *(byte *)(uVar19 * 0x28 + DAT_00012930 + 0x15d92) = *local_34;
                }
              }
              else if (uVar17 == 2) {
                if ((&BUILDENV_qss < local_30) &&
                   (uVar17 = (uint)*(byte *)(uVar19 * 0x28 + DAT_00012934 + 0x15dda), uVar17 < 0x10)
                   ) {
                  pbVar12 = local_34;
                  do {
                    iVar14 = uVar19 * 0x14 + uVar17;
                    bVar2 = *pbVar12;
                    bVar1 = pbVar12[1];
                    uVar15 = uVar17 + 1;
                    uVar17 = uVar15 & 0xff;
                    *(char *)(iVar8 + uVar19 * 0x28 + 0x364e) = (char)uVar15;
                    *(ushort *)(iVar8 + (iVar14 + 0x1ae8) * 2 + 0x5e) = CONCAT11(bVar2,bVar1);
                    if (local_30 <= pbVar12 + (3 - (int)local_34)) break;
                    pbVar12 = pbVar12 + 2;
                  } while (uVar17 != 0x10);
                }
                iVar14 = uVar19 * 0x28 + iVar16;
                if ((*(char *)(iVar14 + 0x364e) != '\0') && (*(short *)(iVar14 + 0x362a) == 1000)) {
                  *(undefined2 *)(iVar14 + 0x362a) = *(undefined2 *)(iVar14 + 0x362e);
                }
              }
              else if (uVar17 == 3) {
                if (local_30 < (byte *)0x2) {
                  if (local_30 != (byte *)0x0) {
                    *(ushort *)(uVar19 * 0x28 + iVar13 + 0x15822) = (ushort)*local_34;
                  }
                }
                else {
                  *(ushort *)(uVar19 * 0x28 + iVar4 + 0x15872) = CONCAT11(*local_34,local_34[1]);
                }
              }
              goto LAB_00012258;
            }
            iVar9 = DAT_000128e0 + 0x1227e;
            bVar2 = *(byte *)(DAT_000128e0 + 0x159e6);
            uVar17 = (uint)bVar2;
            if (uVar17 < 8) {
              *(byte *)(DAT_000128e0 + 0x159e6) = bVar2 + 1;
              iVar22 = uVar17 * 0x28;
              pvVar18 = (void *)(iVar14 + 0x122d6 + iVar22 + 0x35d0);
              memset(pvVar18,0,0x28);
              *(ushort *)(iVar14 + 0x122d6 + iVar22 + 0x35d0) = (ushort)bVar2;
              *(undefined2 *)((int)pvVar18 + 2) = 1000;
              uVar19 = uVar17;
              if (local_30 < (byte *)0x2) {
                if (local_30 != (byte *)0x0) {
                  *(ushort *)(iVar9 + iVar22 + 0x3628) = (ushort)*local_34;
                }
              }
              else {
                *(ushort *)(iVar9 + iVar22 + 0x3628) = CONCAT11(*local_34,local_34[1]);
              }
            }
            goto LAB_00012258;
          }
        }
      }
      goto LAB_00012146;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_000128b8 + 0x12152));
LAB_000120e2:
  if (local_2c != *piVar21) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 00012938 | scan_frames | bytes 114 */

void scan_frames(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (((*(int *)(DAT_000129ac + 0x12dd0) != 0) && (param_1 != 0)) && (5 < param_2)) {
    uVar3 = 0;
    do {
      while (iVar1 = param_1 + uVar3, *(char *)(param_1 + uVar3) == '@') {
        uVar4 = uVar3 + 1;
        if (*(char *)(param_1 + uVar4) == '@') {
          uVar2 = (uint)CONCAT11(*(undefined1 *)(param_1 + uVar3 + 2),
                                 *(undefined1 *)(param_1 + uVar3 + 2 + 1));
          uVar5 = uVar2 + uVar3;
          if (5 < uVar2) {
            if (uVar5 <= param_2) {
              uVar3 = uVar5 - 1;
              observe_frame(iVar1,uVar2,param_3,uVar4,param_4);
              uVar4 = uVar5;
            }
            goto LAB_00012958;
          }
        }
        uVar2 = uVar3 + 7;
        uVar3 = uVar4;
        if (param_2 < uVar2) {
          return;
        }
      }
      uVar4 = uVar3 + 1;
LAB_00012958:
      uVar2 = uVar3 + 7;
      uVar3 = uVar4;
    } while (uVar2 <= param_2);
  }
  return;
}



/* Address 000129b0 | scan_airplay_data | bytes 52 */

void scan_airplay_data(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_000129e4;
  if (((param_1 != 0) && (*(code **)(DAT_000129e4 + 0x129fe) != (code *)0x0)) &&
     (*(int *)(DAT_000129e4 + 0x12a02) != 0)) {
    iVar1 = (**(code **)(DAT_000129e4 + 0x129fe))();
    iVar2 = (**(code **)(iVar2 + 0x12a02))(param_1);
    if (iVar2 != 0 && iVar1 != 0) {
      scan_frames(iVar1,iVar2,param_2,param_4);
      return;
    }
  }
  return;
}



/* Address 000129e8 | make_identify_patch | bytes 1360 */

void make_identify_patch(char *param_1,uint param_2,uint *param_3)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  uint uVar9;
  char *pcVar10;
  int *piVar11;
  char cVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  pthread_mutex_t *__mutex;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  void *__dest;
  size_t local_dc;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa;
  undefined1 local_a9;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined4 local_9e;
  undefined4 local_9a;
  undefined4 local_96;
  undefined4 local_92;
  undefined4 local_8e;
  undefined4 local_8a;
  undefined4 local_86;
  undefined2 local_82;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined1 local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined1 local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58;
  undefined1 local_57;
  int local_2c;
  
  piVar11 = *(int **)(DAT_00012f38 + 0x129fe + DAT_00012f3c);
  local_2c = *piVar11;
  if ((((param_3 != (uint *)0x0) && (*param_3 = 0, *(int *)(DAT_00012f40 + 0x12eb6) != 0)) &&
      (param_2 - 0x10 < 0x1ff1)) &&
     (((*param_1 == -1 && (param_1[1] == 'Z')) &&
      (uVar17 = (uint)CONCAT11(param_1[2],param_1[3]), uVar17 == param_2)))) {
    iVar13 = 10;
    uVar16 = 0xf;
    pcVar10 = param_1 + 8;
    do {
      if (((pcVar10[1] == '@') && (pcVar10[2] == '@')) &&
         (CONCAT11(pcVar10[5],pcVar10[6]) == 0x1d01)) {
        if (uVar16 <= uVar17) {
          uVar14 = (uint)CONCAT11(param_1[iVar13 + 1],param_1[iVar13 + 2]);
          if ((5 < uVar14) && (uVar18 = iVar13 + -1 + uVar14, uVar18 + 1 <= uVar17)) {
            bVar4 = false;
            iVar19 = DAT_00012f44 + 0x12ab0;
            bVar2 = false;
            iVar21 = 0;
            bVar3 = false;
            iVar20 = DAT_00012f48 + 0x12ac2;
            uVar15 = uVar16;
            goto LAB_00012ac0;
          }
        }
        break;
      }
      uVar16 = iVar13 + 6;
      iVar13 = iVar13 + 1;
      pcVar10 = pcVar10 + 1;
    } while (uVar16 <= uVar17);
  }
  goto LAB_00012b0e;
LAB_00012ac0:
  iVar5 = DAT_00012f54;
  iVar7 = DAT_00012f50;
  uVar6 = uVar15 + 4;
  if (uVar6 <= uVar18) {
    uVar9 = (uint)CONCAT11(param_1[uVar15],param_1[uVar15 + 1]);
    sVar1 = CONCAT11(param_1[uVar15 + 2],param_1[uVar15 + 3]);
    if ((uVar9 < 4) || (uVar15 = uVar15 + uVar9, uVar18 < uVar15)) goto LAB_00012b0e;
    if (sVar1 == 0x1e) {
      bVar2 = true;
    }
    else if (sVar1 == 6) {
      iVar7 = message_list_extra(param_1 + uVar6,uVar9 - 4,iVar20,2);
      bVar3 = true;
      iVar21 = iVar21 + iVar7;
    }
    else if (sVar1 == 7) {
      iVar7 = message_list_extra(param_1 + uVar6,uVar9 - 4,iVar19,3);
      bVar4 = true;
      iVar21 = iVar21 + iVar7;
    }
    goto LAB_00012ac0;
  }
  if (uVar18 == uVar15) {
    if (bVar2) {
      local_dc = 0;
    }
    else {
      local_9e = *(undefined4 *)(DAT_00012f68 + 0x12dcc);
      local_9a = *(undefined4 *)(DAT_00012f68 + 0x12dd0);
      local_96 = *(undefined4 *)(DAT_00012f68 + 0x12dd4);
      local_92 = *(undefined4 *)(DAT_00012f68 + 0x12dd8);
      local_a7 = 6;
      local_ab = 0x56;
      local_8e = *(undefined4 *)(DAT_00012f68 + 0x12ddc);
      local_8a = *(undefined4 *)(DAT_00012f68 + 0x12de0);
      local_86 = *(undefined4 *)(DAT_00012f68 + 0x12de4);
      local_a9 = 0x1e;
      local_82 = (undefined2)*(undefined4 *)(DAT_00012f68 + 0x12de8);
      local_dc = 0x56;
      local_a3 = 0x10;
      local_a1 = 0x22;
      local_9f = 1;
      local_7d = 2;
      local_77 = 3;
      local_71 = 4;
      local_7f = 6;
      local_7c = 1;
      local_79 = 6;
      local_76 = 1;
      local_73 = 6;
      local_70 = 1;
      local_6b = 5;
      local_6d = 6;
      local_5f = 7;
      local_6a = 1;
      local_67 = 6;
      local_65 = 6;
      local_63 = 6;
      local_61 = 6;
      local_5e = 1;
      local_5b = 6;
      local_59 = 8;
      local_57 = 6;
      local_ac = bVar2;
      local_aa = bVar2;
      local_a8 = bVar2;
      local_a6 = bVar2;
      local_a5 = bVar2;
      local_a4 = bVar2;
      local_a2 = bVar2;
      local_a0 = bVar2;
      local_80 = bVar2;
      local_7e = bVar2;
      local_7b = bVar2;
      local_7a = bVar2;
      local_78 = bVar2;
      local_75 = bVar2;
      local_74 = bVar2;
      local_72 = bVar2;
      local_6f = bVar2;
      local_6e = bVar2;
      local_6c = bVar2;
      local_69 = bVar2;
      local_68 = bVar2;
      local_66 = bVar2;
      local_64 = bVar2;
      local_62 = bVar2;
      local_60 = bVar2;
      local_5d = bVar2;
      local_5c = bVar2;
      local_5a = bVar2;
      local_58 = bVar2;
    }
    if (!bVar3) {
      iVar21 = iVar21 + 8;
    }
    if (!bVar4) {
      iVar21 = iVar21 + 10;
    }
    __mutex = (pthread_mutex_t *)(DAT_00012f4c + 0x12b62);
    iVar21 = iVar21 + local_dc;
    pthread_mutex_lock(__mutex);
    memset((void *)(iVar5 + 0x12bca),0,0x3718);
    *(undefined4 *)(iVar7 + 0x13016) = 0;
    *(undefined4 *)(iVar5 + 0x12bd2) = 0xffffffff;
    *(undefined4 *)(iVar7 + 0x1301a) = 0;
    *(undefined4 *)(iVar7 + 0x13026) = 0;
    *(undefined4 *)(iVar7 + 0x13012) = 0;
    *(undefined4 *)(iVar7 + 0x1300e) = 0;
    *(undefined4 *)(iVar7 + 0x1302a) = 0;
    *(undefined4 *)(iVar7 + 0x1302e) = 0;
    *(undefined4 *)(iVar7 + 0x13032) = 0;
    *(undefined4 *)(iVar7 + 0x13036) = 0;
    *(undefined4 *)(iVar7 + 0x1303a) = 0;
    *(undefined4 *)(iVar7 + 0x1301e) = 0;
    *(undefined4 *)(iVar7 + 0x13022) = 0;
    *(undefined4 *)(iVar7 + 0x12ffa) = 0;
    *(undefined4 *)(iVar7 + 0x12ffe) = 0;
    *(undefined4 *)(iVar7 + 0x1303e) = 0;
    *(undefined4 *)(iVar7 + 0x13042) = 0;
    publish_state_locked();
    pthread_mutex_unlock(__mutex);
    if (iVar21 == 0) {
      pthread_mutex_lock(__mutex);
      *(undefined4 *)(iVar7 + 0x13026) = 1;
      publish_state_locked();
      pthread_mutex_unlock(__mutex);
      __dest = (void *)0x0;
      goto LAB_00012b12;
    }
    uVar15 = iVar21 + uVar17;
    if (((uVar15 < 0x10000) && (iVar21 + uVar14 < 0x10000)) &&
       (__dest = malloc(uVar15), __dest != (void *)0x0)) {
      memcpy(__dest,param_1,uVar16);
      uVar6 = uVar16;
      if (uVar16 < uVar18) {
        iVar19 = DAT_00012f5c + 0x12c1a;
        iVar20 = DAT_00012f58 + 0x12c1c;
        do {
          pcVar10 = param_1 + uVar16;
          pvVar8 = (void *)((int)__dest + uVar6);
          uVar9 = (uint)CONCAT11(param_1[uVar16],pcVar10[1]);
          if (CONCAT11(param_1[uVar16 + 2],param_1[uVar16 + 3]) == 6) {
            iVar7 = copy_message_list(pvVar8,pcVar10,uVar9,iVar19,2);
            uVar6 = uVar6 + iVar7;
          }
          else if (CONCAT11(param_1[uVar16 + 2],param_1[uVar16 + 3]) == 7) {
            iVar7 = copy_message_list(pvVar8,pcVar10,uVar9,iVar20,3);
            uVar6 = uVar6 + iVar7;
          }
          else {
            uVar6 = uVar6 + uVar9;
            memcpy(pvVar8,pcVar10,uVar9);
          }
          uVar16 = uVar16 + uVar9;
        } while (uVar16 < uVar18);
      }
      uVar16 = uVar6;
      if (!bVar3) {
        *(undefined1 *)((int)__dest + uVar6) = 0;
        *(undefined1 *)((int)__dest + uVar6 + 1) = 8;
        uVar16 = uVar6 + 8;
        *(undefined1 *)((int)__dest + uVar6 + 2) = 0;
        *(undefined1 *)((int)__dest + uVar6 + 3) = 6;
        *(undefined1 *)((int)__dest + uVar6 + 4) = 0x52;
        *(undefined1 *)((int)__dest + uVar6 + 5) = 0;
        *(undefined1 *)((int)__dest + uVar6 + 6) = 0x52;
        *(undefined1 *)((int)__dest + uVar6 + 7) = 3;
      }
      uVar6 = uVar16;
      if (!bVar4) {
        *(undefined1 *)((int)__dest + uVar16) = 0;
        *(undefined1 *)((int)__dest + uVar16 + 1) = 10;
        *(undefined1 *)((int)__dest + uVar16 + 2) = 0;
        *(undefined1 *)((int)__dest + uVar16 + 3) = 7;
        uVar6 = uVar16 + 10;
        *(undefined1 *)((int)__dest + uVar16 + 4) = 0x52;
        *(undefined1 *)((int)__dest + uVar16 + 5) = 1;
        *(undefined1 *)((int)__dest + uVar16 + 6) = 0x52;
        *(undefined1 *)((int)__dest + uVar16 + 7) = 2;
        *(undefined1 *)((int)__dest + uVar16 + 8) = 0x52;
        *(undefined1 *)((int)__dest + uVar16 + 9) = 4;
      }
      if (local_dc != 0) {
        pvVar8 = (void *)((int)__dest + uVar6);
        uVar6 = uVar6 + local_dc;
        memcpy(pvVar8,&local_ac,local_dc);
      }
      memcpy((void *)((int)__dest + uVar6),param_1 + uVar18,uVar17 - uVar18);
      cVar12 = '\0';
      uVar17 = iVar21 + uVar14 & 0xffff;
      iVar19 = 0;
      *(char *)((int)__dest + iVar13 + 1) = (char)(uVar17 >> 8);
      *(char *)((int)__dest + iVar13 + 2) = (char)uVar17;
      *(char *)((int)__dest + 2) = (char)(uVar15 >> 8);
      *(char *)((int)__dest + 3) = (char)uVar15;
      do {
        pcVar10 = (char *)((int)__dest + iVar19);
        iVar19 = iVar19 + 1;
        cVar12 = cVar12 + *pcVar10;
      } while (iVar19 != 8);
      *(char *)((int)__dest + 8) = -cVar12;
      iVar13 = DAT_00012f60;
      if (uVar15 == 10) {
        cVar12 = '\0';
      }
      else {
        pcVar10 = (char *)((int)__dest + 8);
        cVar12 = '\0';
        do {
          pcVar10 = pcVar10 + 1;
          cVar12 = cVar12 + *pcVar10;
        } while (pcVar10 != (char *)((uVar15 - 2) + (int)__dest));
        cVar12 = -cVar12;
      }
      *(char *)((uVar15 - 1) + (int)__dest) = cVar12;
      pthread_mutex_lock((pthread_mutex_t *)(iVar13 + 0x12d9a));
      *(undefined4 *)(DAT_00012f64 + 0x1325e) = 1;
      publish_state_locked();
      pthread_mutex_unlock((pthread_mutex_t *)(iVar13 + 0x12d9a));
      *param_3 = uVar15;
      goto LAB_00012b12;
    }
  }
LAB_00012b0e:
  __dest = (void *)0x0;
LAB_00012b12:
  if (local_2c != *piVar11) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__dest);
  }
  return;
}



/* Address 00012f6c | maybe_send_start_wireless | bytes 356 */

void maybe_send_start_wireless(void)

{
  int iVar1;
  time_t tVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  pthread_mutex_t *__mutex;
  int iVar6;
  undefined1 auStack_44 [24];
  int local_2c;
  
  iVar6 = DAT_000130d8;
  piVar4 = *(int **)(DAT_000130d0 + 0x12f76 + DAT_000130d4);
  local_2c = *piVar4;
  tVar2 = time((time_t *)0x0);
  if (((*(int *)(iVar6 + 0x13418) == 0) || (*(int *)(iVar6 + 0x1341c) != 0)) ||
     (*(int *)(iVar6 + 0x13420) == 0)) goto LAB_00012f96;
  resolve_symbols();
  pthread_mutex_lock((pthread_mutex_t *)(DAT_000130dc + 0x12fb6));
  iVar1 = DAT_000130e8;
  if ((((*(int *)(iVar6 + 0x13424) == 0) && (*(int *)(iVar6 + 0x13440) == 0)) &&
      ((iVar5 = *(int *)(iVar6 + 0x13428), iVar5 < 5 &&
       ((*(int *)(iVar6 + 0x13458) == 0 && (*(int *)(iVar6 + 0x1343c) != 0)))))) &&
     ((*(int *)(iVar6 + 0x1342c) != 0 && (*(int *)(iVar6 + 0x13430) != 0)))) {
    iVar6 = *(int *)(DAT_000130e0 + 0x13482);
    if (((((iVar6 != 0) && (*(int *)(DAT_000130e0 + 0x13486) == 1)) &&
         (*(int *)(DAT_000130e4 + 0x13044) != 0)) &&
        ((*(int *)(DAT_000130e4 + 0x13054) != 0 && (*(int *)(DAT_000130e4 + 0x13060) != 0)))) &&
       ((iVar3 = *(int *)((int)&DAT_000134a8 + DAT_000130e0 + 2), iVar3 == 0 ||
        (1 < (uint)(tVar2 - iVar3))))) {
      __mutex = (pthread_mutex_t *)(DAT_000130ec + 0x13036);
      memset(auStack_44,0,0x18);
      *(time_t *)(iVar1 + 0x134e6) = tVar2;
      *(undefined4 *)(iVar1 + 0x13506) = 1;
      *(int *)(iVar1 + 0x134d6) = iVar5 + 1;
      publish_state_locked();
      pthread_mutex_unlock(__mutex);
      iVar3 = build_start_frame_part_2(auStack_44);
      iVar5 = DAT_00013100;
      if (iVar3 == 0) {
LAB_0001305e:
        pthread_mutex_lock((pthread_mutex_t *)(DAT_000130f0 + 0x13064));
        *(undefined4 *)(DAT_000130f4 + 0x13542) = 0;
      }
      else {
        iVar3 = (**(code **)((int)&DAT_000130e0 + DAT_00013100))(0,auStack_44,iVar3);
        if (iVar3 == 0) goto LAB_0001305e;
        iVar6 = (**(code **)((int)&DAT_000130d0 + iVar5))(iVar6,iVar3,0,0);
        (**(code **)((int)&DAT_000130ec + iVar5))(iVar3);
        pthread_mutex_lock(__mutex);
        *(undefined4 *)(iVar1 + 0x13506) = 0;
        if (iVar6 == 0) {
          *(undefined4 *)(iVar1 + 0x134ee) = 1;
        }
      }
      publish_state_locked();
      pthread_mutex_unlock((pthread_mutex_t *)(DAT_000130f8 + 0x1307a));
      goto LAB_00012f96;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_000130fc + 0x13084));
LAB_00012f96:
  if (local_2c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 00013104 | read | bytes 60 */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  int iVar1;
  undefined4 *puVar2;
  
  resolve_symbols();
  if (*(code **)(DAT_00013140 + 0x13116) == (code *)0x0) {
    puVar2 = (undefined4 *)__get_errno_ptr();
    iVar1 = -1;
    *puVar2 = 5;
  }
  else {
    iVar1 = (**(code **)(DAT_00013140 + 0x13116))(__fd,__buf,__nbytes);
    if (0 < iVar1) {
      scan_frames(__buf,iVar1,1);
    }
  }
  return iVar1;
}



/* Address 00013144 | recv | bytes 68 */

ssize_t recv(int __fd,void *__buf,size_t __n,int __flags)

{
  int iVar1;
  undefined4 *puVar2;
  
  resolve_symbols();
  if (*(code **)(DAT_00013188 + 0x13162) == (code *)0x0) {
    puVar2 = (undefined4 *)__get_errno_ptr();
    iVar1 = -1;
    *puVar2 = 5;
  }
  else {
    iVar1 = (**(code **)(DAT_00013188 + 0x13162))(__fd,__buf,__n,__flags);
    if (0 < iVar1) {
      scan_frames(__buf,iVar1,1);
    }
  }
  return iVar1;
}



/* Address 0001318c | recvfrom | bytes 80 */

ssize_t recvfrom(int __fd,void *__buf,size_t __n,int __flags,sockaddr *__addr,socklen_t *__addr_len)

{
  int iVar1;
  undefined4 *puVar2;
  
  resolve_symbols();
  if (*(code **)(DAT_000131dc + 0x131b0) == (code *)0x0) {
    puVar2 = (undefined4 *)__get_errno_ptr();
    iVar1 = -1;
    *puVar2 = 5;
  }
  else {
    iVar1 = (**(code **)(DAT_000131dc + 0x131b0))(__fd,__buf,__n,__flags,__addr,__addr_len);
    if (0 < iVar1) {
      scan_frames(__buf,iVar1,1);
    }
  }
  return iVar1;
}



/* Address 000131e0 | recvmsg | bytes 112 */

ssize_t recvmsg(int __fd,msghdr *__message,int __flags)

{
  iovec *piVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  iovec *piVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  
  resolve_symbols();
  if (*(code **)(DAT_00013250 + 0x13202) == (code *)0x0) {
    puVar4 = (undefined4 *)__get_errno_ptr();
    uVar3 = 0xffffffff;
    *puVar4 = 5;
  }
  else {
    uVar3 = (**(code **)(DAT_00013250 + 0x13202))(__fd,__message,__flags);
    bVar8 = __message == (msghdr *)0x0;
    uVar7 = 0;
    if (!bVar8) {
      uVar7 = uVar3;
    }
    bVar2 = (int)uVar7 < 0;
    bVar9 = uVar3 == 0;
    if ((!bVar8 && !bVar9) && !bVar2) {
      __flags = 0;
    }
    if ((bVar8 || bVar9) || bVar2) {
      __flags = 1;
    }
    if ((((!bVar8 && !bVar9) && !bVar2) && (piVar6 = __message->msg_iov, piVar6 != (iovec *)0x0)) &&
       (uVar7 = uVar3, 0 < (int)__message->msg_iovlen)) {
      while( true ) {
        piVar1 = piVar6 + __flags;
        piVar6 = piVar6 + __flags;
        __flags = __flags + 1;
        uVar5 = piVar6->iov_len;
        if (uVar7 < piVar6->iov_len) {
          uVar5 = uVar7;
        }
        uVar7 = uVar7 - uVar5;
        scan_frames(piVar1->iov_base);
        if (((int)__message->msg_iovlen <= __flags) || (uVar7 == 0)) break;
        piVar6 = __message->msg_iov;
      }
    }
  }
  return uVar3;
}



/* Address 00013254 | Send | bytes 132 */

/* NmeTransport::Send(unsigned char const*, unsigned int, unsigned int*) */

int __thiscall NmeTransport::Send(NmeTransport *this,uchar *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  pthread_mutex_t *__mutex;
  code *pcVar3;
  
  resolve_symbols();
  pcVar3 = *(code **)(DAT_000132d8 + 0x1328a);
  if (pcVar3 == (code *)0x0) {
    return -1;
  }
  if (param_1 == (uchar *)0x0 || param_2 < 6) {
    iVar1 = (*pcVar3)(this,param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = wire_control_message_id_part_3(param_1,param_2);
  iVar2 = (*pcVar3)(this,param_1,param_2,param_3);
  if (iVar1 == 0x5000 && iVar2 == 0) {
    __mutex = (pthread_mutex_t *)(DAT_000132dc + 0x132a8);
    pthread_mutex_lock(__mutex);
    *(undefined4 *)(DAT_000132e0 + 0x13776) = 1;
    pthread_mutex_unlock(__mutex);
    return 0;
  }
  return iVar2;
}



/* Address 000132e4 | Decode | bytes 436 */

/* NmeIAP2Message::Decode(unsigned char const*, int) */

void __thiscall NmeIAP2Message::Decode(NmeIAP2Message *this,uchar *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  time_t tVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  pthread_mutex_t *ppVar8;
  uint uVar9;
  int iVar10;
  undefined2 local_26;
  int local_24;
  
  piVar7 = *(int **)(DAT_00013498 + 0x132f2 + DAT_0001349c);
  local_24 = *piVar7;
  resolve_symbols();
  if (*(code **)(DAT_000134a0 + 0x1332a) == (code *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (**(code **)(DAT_000134a0 + 0x1332a))(this,param_1,param_2);
    uVar9 = 1 - uVar2;
    if (1 < uVar2) {
      uVar9 = 0;
    }
    if (*(int *)(DAT_000134a4 + 0x137f2) != 0) {
      if (param_1 == (uchar *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar9 & 1;
      }
      if (uVar6 != 0) {
        if ((((param_2 < 6) || (*param_1 != '@')) || (param_1[1] != '@')) ||
           ((CONCAT11(param_1[2],param_1[3]) < 6 ||
            ((param_2 & 0xffffU) < (uint)CONCAT11(param_1[2],param_1[3]))))) {
          uVar9 = 1;
        }
        else {
          uVar9 = 1;
          observe_frame(param_1);
        }
      }
    }
    iVar4 = DAT_000134ac;
    ppVar8 = (pthread_mutex_t *)(DAT_000134a8 + 0x13332);
    pthread_mutex_lock(ppVar8);
    if (*(int *)(iVar4 + 0x137f4) == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = uVar9 & 1;
    }
    pthread_mutex_unlock(ppVar8);
    if (uVar9 != 0) {
      local_26 = 0x10;
      tVar3 = time((time_t *)0x0);
      if (((*(int *)(iVar4 + 0x137c8) == 0) || (*(int *)(iVar4 + 0x137cc) != 0)) ||
         (*(int *)(iVar4 + 0x137d0) == 0)) {
        uVar2 = 0;
      }
      else {
        resolve_symbols();
        pthread_mutex_lock(ppVar8);
        iVar1 = DAT_000134b8;
        if ((((((*(int *)(iVar4 + 0x137d4) == 0) && (*(int *)(iVar4 + 0x13800) == 0)) &&
              (*(int *)(iVar4 + 0x137fc) < 5)) &&
             ((*(int *)(iVar4 + 0x137f8) == 0 && (*(int *)(iVar4 + 0x137ec) != 0)))) &&
            ((iVar10 = *(int *)(iVar4 + 0x13810), iVar10 != 0 &&
             (*(int *)(DAT_000134b0 + 0x13438) != 0)))) &&
           ((*(int *)(DAT_000134b4 + 0x138ca) == 0 ||
            (1 < (uint)(tVar3 - *(int *)(DAT_000134b4 + 0x138ca)))))) {
          ppVar8 = (pthread_mutex_t *)(DAT_000134bc + 0x13430);
          iVar5 = *(int *)(DAT_000134b8 + 0x138d2);
          *(int *)(DAT_000134b8 + 0x138f6) = *(int *)(iVar4 + 0x137fc) + 1;
          *(time_t *)(iVar1 + 0x138e2) = tVar3;
          *(int *)(iVar1 + 0x138d2) = iVar5 + 1;
          *(undefined4 *)(iVar1 + 0x138f2) = 1;
          pthread_mutex_unlock(ppVar8);
          iVar4 = (**(code **)(DAT_000134c0 + 0x13484))(iVar10,1,&local_26);
          pthread_mutex_lock(ppVar8);
          *(undefined4 *)(iVar1 + 0x138f2) = 0;
          if (iVar4 == 0) {
            *(undefined4 *)(iVar1 + 0x138fa) = 1;
            *(undefined4 *)(iVar1 + 0x138ea) = 1;
            *(undefined4 *)(iVar1 + 0x138ee) = 0;
          }
          uVar2 = 0;
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_000134c4 + 0x1347e));
        }
        else {
          uVar2 = 0;
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_000134c8 + 0x1348a));
        }
      }
    }
  }
  if (local_24 != *piVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



/* Address 000134cc | AirPlayReceiverSessionSendiAPMessage | bytes 1444 */

void AirPlayReceiverSessionSendiAPMessage
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  uint __n;
  undefined1 *__ptr;
  void *__ptr_00;
  char *pcVar5;
  time_t tVar6;
  int iVar7;
  char *__dest;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char cVar11;
  uint uVar12;
  uint uVar13;
  undefined1 *puVar14;
  pthread_mutex_t *__mutex;
  code *pcVar15;
  undefined4 *puVar16;
  int *piVar17;
  size_t sVar18;
  bool bVar19;
  uint local_50;
  undefined1 *local_48;
  uint local_34;
  uint local_30;
  int local_2c;
  
  iVar8 = DAT_00013a78;
  piVar17 = *(int **)(DAT_00013a70 + 0x134e2 + DAT_00013a74);
  local_34 = 0;
  local_2c = *piVar17;
  resolve_symbols();
  if (*(code **)(iVar8 + 0x1352a) == (code *)0x0) {
    iVar8 = -1;
    goto LAB_0001368a;
  }
  if (*(int *)(DAT_00013a7c + 0x139e4) == 0) {
    iVar8 = (**(code **)(iVar8 + 0x1352a))(param_1,param_2,param_3,param_4);
    goto LAB_0001368a;
  }
  if (param_2 == 0) {
    pcVar5 = (char *)0x0;
LAB_00013666:
    scan_airplay_data(param_2,0);
    iVar8 = (**(code **)(DAT_00013a80 + 0x136b6))(param_1,param_2,param_3,param_4);
    free(pcVar5);
  }
  else {
    if ((*(code **)(iVar8 + 0x13532) == (code *)0x0) || (*(int *)(iVar8 + 0x13536) == 0)) {
LAB_00013664:
      pcVar5 = (char *)0x0;
      goto LAB_00013666;
    }
    pcVar4 = (char *)(**(code **)(iVar8 + 0x13532))(param_2);
    __n = (**(code **)(iVar8 + 0x13536))(param_2);
    if (__n == 0 || pcVar4 == (char *)0x0) goto LAB_00013664;
    if ((((__n < 10) || (*pcVar4 != -1)) || (pcVar4[1] != 'Z')) ||
       (CONCAT11(pcVar4[2],pcVar4[3]) != __n)) {
      local_30 = 0;
      local_34 = 0;
      if (((__n - 6 < 0x1ff1) && (*pcVar4 == '@')) &&
         ((pcVar4[1] == '@' &&
          ((__n == CONCAT11(pcVar4[2],pcVar4[3]) && (CONCAT11(pcVar4[4],pcVar4[5]) == 0x1d01)))))) {
        sVar18 = __n + 10;
        local_50 = 0;
        __ptr = calloc(1,sVar18);
        if (__ptr == (undefined1 *)0x0) goto LAB_000136b6;
        *__ptr = 0xff;
        __ptr[2] = (char)(sVar18 >> 8);
        __ptr[3] = (char)sVar18;
        __ptr[1] = 0x5a;
        uVar13 = local_50;
        do {
          pbVar1 = __ptr + uVar13;
          uVar13 = uVar13 + 1;
          uVar12 = local_50 + *pbVar1;
          local_50 = uVar12 & 0xff;
        } while (uVar13 != 8);
        __ptr[8] = -(char)uVar12;
        memcpy(__ptr + 9,pcVar4,__n);
        cVar11 = '\0';
        puVar14 = __ptr;
        do {
          pcVar5 = puVar14 + 9;
          puVar14 = puVar14 + 1;
          cVar11 = cVar11 + *pcVar5;
        } while (puVar14 != __ptr + __n);
        __ptr[__n + 9] = -cVar11;
        __ptr_00 = (void *)make_identify_patch(__ptr,sVar18,&local_30);
        free(__ptr);
        if (__ptr_00 == (void *)0x0) goto LAB_000136b6;
        if (local_30 < 0x10) {
LAB_000136b0:
          free(__ptr_00);
          goto LAB_000136b6;
        }
        sVar18 = local_30 - 10;
        pcVar5 = malloc(sVar18);
        if (pcVar5 == (char *)0x0) goto LAB_000136b0;
        memcpy(pcVar5,(void *)((int)__ptr_00 + 9),sVar18);
        bVar19 = true;
        free(__ptr_00);
        local_34 = sVar18;
      }
      else {
LAB_000136b6:
        bVar19 = false;
        pcVar5 = (char *)0x0;
      }
      pthread_mutex_lock((pthread_mutex_t *)(DAT_00013a84 + 0x136c2));
      *(undefined4 *)(DAT_00013a88 + 0x13b5a) = param_1;
      if (9 < __n) goto LAB_000136d4;
      if (5 < __n) {
        cVar11 = *pcVar4;
        goto LAB_000136de;
      }
    }
    else {
      pcVar5 = (char *)make_identify_patch(pcVar4,(uint)CONCAT11(pcVar4[2],pcVar4[3]),&local_34);
      bVar19 = pcVar5 != (char *)0x0;
      pthread_mutex_lock((pthread_mutex_t *)(DAT_00013acc + 0x139d8));
      *(undefined4 *)(DAT_00013ad0 + 0x13e72) = param_1;
LAB_000136d4:
      iVar8 = DAT_00013ad4;
      cVar11 = *pcVar4;
      if (cVar11 == -1) {
        if ((pcVar4[1] == 'Z') && (CONCAT11(pcVar4[2],pcVar4[3]) == __n)) {
          uVar10 = *(undefined4 *)(pcVar4 + 4);
          uVar9 = *(undefined4 *)pcVar4;
          cVar11 = pcVar4[8];
          puVar16 = (undefined4 *)(DAT_00013ad4 + 0x13ef4);
          *(undefined4 *)(DAT_00013ad4 + 0x13ea4) = 2;
          *puVar16 = uVar9;
          *(undefined4 *)(iVar8 + 0x13ef8) = uVar10;
          *(char *)(iVar8 + 0x13efc) = cVar11;
          *(undefined4 *)(iVar8 + 0x13ee4) = 1;
        }
      }
      else {
LAB_000136de:
        iVar8 = DAT_00013ab8;
        if (((cVar11 == '@') && (pcVar4[1] == '@')) && (CONCAT11(pcVar4[2],pcVar4[3]) <= __n)) {
          *(undefined4 *)(DAT_00013ab8 + 0x13dfe) = 1;
          *(undefined4 *)(iVar8 + 0x13e3e) = 0;
        }
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013a8c + 0x136ea));
    iVar8 = DAT_00013a90;
    if (pcVar5 != (char *)0x0) {
      pcVar4 = pcVar5;
      __n = local_34;
    }
    tVar6 = time((time_t *)0x0);
    if (((((*(int *)((int)&DAT_00013bd4 + iVar8) == 0) || (0xffdd < __n - 10)) ||
         ((*pcVar4 != -1 || ((pcVar4[1] != 'Z' || (__n != CONCAT11(pcVar4[2],pcVar4[3]))))))) ||
        (iVar7 = wire_control_message_id_part_3(pcVar4,__n), iVar7 == 0 || iVar7 == 0x1d01)) ||
       (iVar7 == 0x5200)) {
joined_r0x000138b2:
      if (pcVar5 != (char *)0x0) {
        local_48 = (undefined1 *)0x0;
        goto LAB_000138b8;
      }
      iVar7 = 0;
      local_48 = (undefined1 *)0x0;
    }
    else {
      pthread_mutex_lock((pthread_mutex_t *)(DAT_00013a94 + 0x13768));
      iVar7 = DAT_00013a9c;
      if (((((*(int *)(iVar8 + 0x13b9c) != 0) || (*(int *)(iVar8 + 0x13bb8) != 0)) ||
           (4 < *(int *)(iVar8 + 0x13ba0))) ||
          ((*(int *)(DAT_00013a98 + 0x13c64) != 0 || (*(int *)(DAT_00013a98 + 0x13c48) == 0)))) ||
         (((*(int *)(DAT_00013a98 + 0x13c38) == 0 ||
           ((*(int *)(DAT_00013a98 + 0x13c3c) == 0 || (*(int *)(DAT_00013a98 + 0x13c20) != 2)))) ||
          ((*(int *)(DAT_00013a98 + 0x13c44) != 0 &&
           ((uint)(tVar6 - *(int *)(DAT_00013a98 + 0x13c44)) < 2)))))) {
        pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013ad8 + 0x13a36));
        goto joined_r0x000138b2;
      }
      sVar18 = __n + 0x18;
      __mutex = (pthread_mutex_t *)(DAT_00013aa0 + 0x137e6);
      *(int *)(DAT_00013a9c + 0x13c7e) = *(int *)(iVar8 + 0x13ba0) + 1;
      *(undefined4 *)(iVar7 + 0x13cae) = 1;
      *(time_t *)(iVar7 + 0x13c8e) = tVar6;
      publish_state_locked();
      pthread_mutex_unlock(__mutex);
      __dest = malloc(sVar18);
      if (__dest == (char *)0x0) {
        pthread_mutex_lock(__mutex);
        *(undefined4 *)(iVar7 + 0x13cae) = 0;
        publish_state_locked();
        pthread_mutex_unlock(__mutex);
        goto joined_r0x000138b2;
      }
      memcpy(__dest,pcVar4,__n - 1);
      iVar8 = build_start_frame_part_2(__dest + (__n - 1));
      if (iVar8 != 0x18) {
        free(__dest);
        pthread_mutex_lock(__mutex);
        *(undefined4 *)(iVar7 + 0x13cae) = 0;
        publish_state_locked();
        pthread_mutex_unlock(__mutex);
        goto joined_r0x000138b2;
      }
      cVar11 = '\0';
      __dest[2] = (char)(sVar18 >> 8);
      iVar8 = 0;
      __dest[3] = (char)sVar18;
      do {
        pcVar4 = __dest + iVar8;
        iVar8 = iVar8 + 1;
        cVar11 = cVar11 + *pcVar4;
      } while (iVar8 != 8);
      cVar3 = '\0';
      __dest[8] = -cVar11;
      uVar13 = 0;
      do {
        uVar12 = uVar13 + 1;
        cVar3 = cVar3 + __dest[uVar13 + 9];
        uVar13 = uVar12;
      } while (uVar12 < __n + 0xe);
      __dest[__n + 0x17] = -cVar3;
      free(pcVar5);
      local_48 = &BUILDENV_qss;
      pcVar5 = __dest;
      local_34 = sVar18;
LAB_000138b8:
      if ((*(code **)(DAT_00013aa4 + 0x13906) == (code *)0x0) ||
         (iVar7 = (**(code **)(DAT_00013aa4 + 0x13906))(0,pcVar5,local_34), iVar7 == 0)) {
        pthread_mutex_lock((pthread_mutex_t *)(DAT_00013abc + 0x1397e));
        if (bVar19) {
          *(undefined4 *)(DAT_00013ac0 + 0x13e44) = 0;
        }
        if (local_48 != (undefined1 *)0x0) {
          *(undefined4 *)(DAT_00013ac4 + 0x13e6e) = 0;
        }
        publish_state_locked();
        pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013ac8 + 0x139a6));
        goto LAB_00013666;
      }
      param_2 = iVar7;
    }
    iVar2 = DAT_00013aa8;
    scan_airplay_data(param_2,0);
    iVar8 = (**(code **)(iVar2 + 0x13914))(param_1,param_2,param_3,param_4);
    if ((iVar7 != 0) && (pcVar15 = *(code **)(iVar2 + 0x13930), pcVar15 != (code *)0x0)) {
      (*pcVar15)(iVar7);
    }
    free(pcVar5);
    if (local_48 != (undefined1 *)0x0) {
      pthread_mutex_lock((pthread_mutex_t *)(DAT_00013aac + 0x1390e));
      iVar7 = DAT_00013ab0;
      *(undefined4 *)(DAT_00013ab0 + 0x13dec) = 0;
      if (iVar8 == 0) {
        *(undefined4 *)(iVar7 + 0x13dd4) = 1;
      }
      publish_state_locked();
      pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013ab4 + 0x1392c));
    }
  }
  if (iVar8 == 0) {
    maybe_send_start_wireless();
  }
LAB_0001368a:
  if (local_2c != *piVar17) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar8);
  }
  return;
}



/* Address 00013adc | AirPlayReceiverSessionControl | bytes 234 */

void AirPlayReceiverSessionControl
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  pthread_mutex_t *__mutex;
  int *piVar4;
  int local_30;
  int local_2c;
  
  iVar3 = DAT_00013bd0;
  piVar4 = *(int **)(DAT_00013bc8 + 0x13aee + DAT_00013bcc);
  local_2c = *piVar4;
  local_30 = 0;
  resolve_symbols();
  iVar1 = DAT_00013bd4;
  if (*(code **)(iVar3 + 0x13b34) == (code *)0x0) {
    iVar3 = -1;
  }
  else if (*(int *)(DAT_00013bd4 + 0x13ff2) == 0) {
    iVar3 = (**(code **)(iVar3 + 0x13b34))(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    __mutex = (pthread_mutex_t *)(DAT_00013bd8 + 0x13b28);
    pthread_mutex_lock(__mutex);
    *(undefined4 *)(iVar1 + 0x13fa6) = param_1;
    pthread_mutex_unlock(__mutex);
    if ((((param_5 != 0) && (*(code **)(iVar3 + 0x13b48) != (code *)0x0)) &&
        (*(int *)(iVar3 + 0x13b44) != 0)) &&
       (((*(int *)(iVar3 + 0x13b4c) != 0 &&
         (iVar1 = (**(code **)(iVar3 + 0x13b48))(0,DAT_00013bdc + 0x13b5c,4,&local_30), iVar1 == 0))
        && (local_30 != 0)))) {
      uVar2 = (**(code **)(iVar3 + 0x13b44))(param_5);
      (**(code **)(iVar3 + 0x13b4c))(local_30);
      scan_airplay_data(uVar2,1);
    }
    iVar3 = (**(code **)(DAT_00013be0 + 0x13bc0))(param_1,param_2,param_3,param_4,param_5,param_6);
    if (iVar3 == 0) {
      maybe_send_start_wireless();
    }
  }
  if (local_2c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar3);
  }
  return;
}



/* Address 00013be4 | deployMessage | bytes 348 */

/* iap2::CIAP2ControlSession::deployMessage(iap2::CIAP2ControlSessionMessageView const&) */

void __thiscall
iap2::CIAP2ControlSession::deployMessage
          (CIAP2ControlSession *this,CIAP2ControlSessionMessageView *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  pthread_mutex_t *__mutex;
  short sVar7;
  int iVar8;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [24];
  int local_24;
  
  piVar6 = *(int **)(DAT_00013d40 + 0x13bec + DAT_00013d44);
  local_24 = *piVar6;
  resolve_symbols();
  if (*(int *)(DAT_00013d48 + 0x13c34) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_1 == (CIAP2ControlSessionMessageView *)0x0) {
      sVar7 = 0;
    }
    else {
      pcVar5 = *(char **)(param_1 + 4);
      pcVar4 = *(char **)(param_1 + 8);
      if (pcVar5 == (char *)0x0 || pcVar4 == (char *)0x0) {
        sVar7 = 0;
      }
      else {
        sVar7 = 0;
        if ((((pcVar5 <= pcVar4) && (5 < (uint)((int)pcVar4 - (int)pcVar5))) && (*pcVar5 == '@')) &&
           (((pcVar5[1] == '@' && (5 < CONCAT11(pcVar5[2],pcVar5[3]))) &&
            ((uint)CONCAT11(pcVar5[2],pcVar5[3]) <= (uint)((int)pcVar4 - (int)pcVar5))))) {
          sVar7 = CONCAT11(pcVar5[4],pcVar5[5]);
        }
      }
    }
    pthread_mutex_lock((pthread_mutex_t *)(DAT_00013d4c + 0x13c3e));
    if (this != (CIAP2ControlSession *)0x0) {
      *(CIAP2ControlSession **)(DAT_00013d50 + 0x14134) = this;
    }
    iVar1 = DAT_00013d58;
    __mutex = (pthread_mutex_t *)(DAT_00013d54 + 0x13c54);
    pthread_mutex_unlock(__mutex);
    uVar2 = (**(code **)(iVar1 + 0x13c86))(this,param_1);
    iVar3 = DAT_00013d5c;
    if (((sVar7 == -5) && (*(int *)(DAT_00013d5c + 0x1413e) != 0)) &&
       (*(int *)(DAT_00013d5c + 0x14142) != 0)) {
      resolve_symbols();
      pthread_mutex_lock(__mutex);
      if (((((*(int *)(iVar3 + 0x14146) == 0) && (*(int *)(iVar3 + 0x1414a) < 1)) &&
           (*(int *)(iVar3 + 0x1414e) != 0)) &&
          ((iVar8 = *(int *)((int)&DAT_00014190 + iVar3 + 2), iVar8 != 0 &&
           (*(int *)(iVar1 + 0x13c86) != 0)))) && (*(int *)(iVar1 + 0x13c8a) != 0)) {
        *(int *)(iVar3 + 0x1414a) = *(int *)(iVar3 + 0x1414a) + 1;
        pthread_mutex_unlock(__mutex);
        iVar3 = build_start_frame_part_2(auStack_3c);
        iVar1 = DAT_00013d64;
        if (iVar3 != 0) {
          memset(auStack_4c,0,0x10);
          (**(code **)((int)&DAT_00013d58 + iVar1 + 2))(auStack_4c,auStack_3c,auStack_3c + iVar3);
          (**(code **)((int)&DAT_00013d54 + iVar1 + 2))(iVar8,auStack_4c);
        }
      }
      else {
        pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013d60 + 0x13cd2));
      }
    }
  }
  if (local_24 != *piVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



/* Address 00013d68 | CinemoCreateIAP | bytes 76 */

uint CinemoCreateIAP(int *param_1)

{
  uint uVar1;
  int iVar2;
  pthread_mutex_t *__mutex;
  
  resolve_symbols();
  if (*(code **)(DAT_00013db4 + 0x13d9e) == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (**(code **)(DAT_00013db4 + 0x13d9e))(param_1);
    iVar2 = 1 - uVar1;
    if (1 < uVar1) {
      iVar2 = 0;
    }
    if (param_1 == (int *)0x0) {
      iVar2 = 0;
    }
    if ((iVar2 != 0) && (uVar1 = 0, *param_1 != 0)) {
      __mutex = (pthread_mutex_t *)(DAT_00013db8 + 0x13d96);
      pthread_mutex_lock(__mutex);
      *(int *)(DAT_00013dbc + 0x14280) = *param_1;
      pthread_mutex_unlock(__mutex);
      return 0;
    }
  }
  return uVar1;
}



/* Address 00013dc0 | writeToTransport | bytes 620 */

/* iap2::CIAP2LinkPacketDeployer::writeToTransport(iap2::CIAP2PacketView const&) */

void __thiscall
iap2::CIAP2LinkPacketDeployer::writeToTransport
          (CIAP2LinkPacketDeployer *this,CIAP2PacketView *param_1)

{
  short sVar1;
  char *pcVar2;
  char *pcVar3;
  void *__ptr;
  int iVar4;
  uint uVar5;
  pthread_mutex_t *__mutex;
  uint uVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  code *pcVar10;
  undefined4 uVar11;
  int *piVar12;
  uint uVar13;
  undefined4 local_4c;
  uint3 local_48;
  undefined1 uStack_45;
  undefined1 uStack_44;
  char local_43;
  undefined2 uStack_42;
  char local_40;
  char local_3f [27];
  int local_24;
  
  iVar4 = DAT_00014034;
  piVar12 = *(int **)(DAT_0001402c + 0x13dc8 + DAT_00014030);
  local_24 = *piVar12;
  resolve_symbols();
  pcVar10 = *(code **)(iVar4 + 0x13dee);
  if (pcVar10 == (code *)0x0) {
    uVar11 = 0;
  }
  else {
    if ((((*(int *)(DAT_00014038 + 0x142c4) != 0) && (param_1 != (CIAP2PacketView *)0x0)) &&
        (*(code **)(iVar4 + 0x13df2) != (code *)0x0)) && (*(int *)(iVar4 + 0x13df6) != 0)) {
      pcVar2 = (char *)(**(code **)(iVar4 + 0x13df2))(param_1);
      pcVar3 = (char *)(**(code **)(iVar4 + 0x13df6))(param_1);
      if (((pcVar3 != (char *)0x0 && pcVar2 != (char *)0x0) && (pcVar2 <= pcVar3)) &&
         (uVar13 = (int)pcVar3 - (int)pcVar2, uVar13 != 0)) {
        scan_frames(pcVar2,uVar13,0);
        __ptr = (void *)make_identify_patch(pcVar2,uVar13,&local_4c);
        if (__ptr != (void *)0x0) {
          if ((this != (CIAP2LinkPacketDeployer *)0x0) &&
             (iVar4 = transport_write_raw_part_1(this,__ptr,local_4c), iVar4 != 0)) {
            uVar11 = 1;
            free(__ptr);
            goto LAB_00013e56;
          }
          free(__ptr);
        }
        uVar11 = (**(code **)(DAT_0001403c + 0x13e8c))(this,param_1);
        uVar5 = time((time_t *)0x0);
        if ((((*(int *)(DAT_00014040 + 0x1431c) == 0) && (*(int *)(DAT_00014040 + 0x14320) == 0)) &&
            (*(int *)(DAT_00014040 + 0x14324) != 0)) &&
           (((9 < uVar13 && (*pcVar2 == -1)) &&
            ((pcVar2[1] == 'Z' && ((uVar13 == CONCAT11(pcVar2[2],pcVar2[3]) && (0xe < uVar13))))))))
        {
          iVar4 = 9;
          pcVar3 = pcVar2 + 8;
          do {
            if ((((pcVar3[1] == '@') && (pcVar3[2] == '@')) && (5 < CONCAT11(pcVar3[3],pcVar3[4])))
               && (iVar4 + (uint)CONCAT11(pcVar3[3],pcVar3[4]) <= uVar13)) {
              sVar1 = CONCAT11(pcVar2[iVar4 + 4],pcVar2[iVar4 + 5]);
              if (((sVar1 != 0x1d01) && (sVar1 != 0)) && (sVar1 != 0x5200)) {
                pthread_mutex_lock((pthread_mutex_t *)(DAT_00014044 + 0x13f24));
                if (((*(int *)(DAT_00014048 + 0x143cc) == 0) &&
                    (iVar4 = *(int *)(DAT_00014048 + 0x143d0), iVar4 < 5)) &&
                   ((*(int *)(DAT_00014048 + 0x143d4) != 0 &&
                    (*(int *)(DAT_0001404c + 0x143f4) != 0)))) {
                  if (*(int *)(DAT_0001404c + 0x143f8) == 0) {
                    *(uint *)(DAT_0001404c + 0x143f8) = uVar5 + 2;
                  }
                  iVar7 = DAT_00014054;
                  if ((*(uint *)(DAT_00014050 + 0x14410) <= uVar5) &&
                     ((*(int *)(DAT_00014050 + 0x14414) == 0 ||
                      (1 < uVar5 - *(int *)(DAT_00014050 + 0x14414))))) {
                    __mutex = (pthread_mutex_t *)(DAT_00014058 + 0x13f86);
                    *(uint *)(DAT_00014054 + 0x14436) = uVar5;
                    *(int *)(iVar7 + 0x14426) = iVar4 + 1;
                    pthread_mutex_unlock(__mutex);
                    memset(&local_48,0,0x22);
                    local_40 = '\0';
                    iVar4 = 0;
                    _local_48 = CONCAT13(0x22,(uint3)*(undefined4 *)pcVar2 & 0xffff);
                    uStack_42 = (undefined2)((uint)*(undefined4 *)(pcVar2 + 4) >> 0x10);
                    _uStack_44 = CONCAT11(pcVar2[5] + '\x01',(char)*(undefined4 *)(pcVar2 + 4));
                    do {
                      pcVar2 = (char *)((int)&local_48 + iVar4);
                      iVar4 = iVar4 + 1;
                      local_40 = local_40 + *pcVar2;
                    } while (iVar4 != 8);
                    local_40 = -local_40;
                    iVar4 = build_start_frame_part_2(local_3f);
                    if (iVar4 != 0) {
                      cVar9 = '\0';
                      iVar7 = 0;
                      do {
                        iVar8 = iVar7 + 1;
                        cVar9 = cVar9 + local_3f[iVar7];
                        iVar7 = iVar8;
                      } while (iVar8 != iVar4);
                      local_3f[iVar4] = -cVar9;
                      if (this != (CIAP2LinkPacketDeployer *)0x0) {
                        transport_write_raw_part_1(this,&local_48,0x22);
                      }
                    }
                    break;
                  }
                }
                pthread_mutex_unlock((pthread_mutex_t *)(DAT_0001405c + 0x14028));
              }
              break;
            }
            uVar6 = iVar4 + 7;
            iVar4 = iVar4 + 1;
            pcVar3 = pcVar3 + 1;
          } while (uVar6 <= uVar13);
        }
        goto LAB_00013e56;
      }
      pcVar10 = *(code **)(iVar4 + 0x13dee);
    }
    uVar11 = (*pcVar10)(this,param_1);
  }
LAB_00013e56:
  if (local_24 != *piVar12) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



/* Address 00014060 | read_identity | bytes 298 */

void read_identity(char *param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  undefined1 uStack_10bd;
  undefined1 auStack_10bc [144];
  int local_102c [1024];
  int local_2c [2];
  
  piVar10 = *(int **)(DAT_0001418c + 0x1406e + DAT_00014190);
  local_2c[0] = *piVar10;
  iVar2 = lstat(param_1,(stat *)auStack_10bc);
  if ((iVar2 == 0) && ((auStack_10bc._44_4_ & 0xf000) != 0xa000)) {
    iVar2 = open(param_1,0x1000);
    if (-1 < iVar2) {
      iVar3 = fstat(iVar2,(stat *)(auStack_10bc + 0x48));
      if (iVar3 == 0) {
        uVar9 = 0;
        do {
          sVar4 = read(iVar2,(undefined1 *)((int)local_102c + uVar9),0x1000 - uVar9);
          if (sVar4 < 0) goto LAB_000140f6;
          if (sVar4 == 0) {
            close(iVar2);
            if (uVar9 != 0) goto LAB_00014130;
            iVar2 = *param_3;
            goto LAB_0001415a;
          }
          uVar9 = uVar9 + sVar4;
        } while (uVar9 < 0x1000);
        if ((uVar9 != 0x1000) || (sVar4 = read(iVar2,&uStack_10bd,1), sVar4 == 0)) {
          close(iVar2);
LAB_00014130:
          iVar2 = *param_3;
          uVar8 = 0;
          do {
            cVar1 = *(char *)((int)local_102c + uVar8);
            uVar8 = uVar8 + 1;
            if ((cVar1 != '\t' && cVar1 != ' ') && (cVar1 != '\n' && cVar1 != '\r')) {
              *(char *)(param_2 + iVar2) = cVar1;
              iVar2 = iVar2 + 1;
              *param_3 = iVar2;
            }
          } while (uVar8 < uVar9);
LAB_0001415a:
          piVar7 = local_102c;
          do {
            piVar6 = (int *)((int)piVar7 + 1);
            *(undefined1 *)piVar7 = 0;
            piVar7 = piVar6;
          } while (piVar6 != local_2c);
          if (iVar2 == 0) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = 0;
          }
          goto LAB_00014110;
        }
      }
LAB_000140f6:
      close(iVar2);
    }
    piVar7 = local_102c;
    do {
      piVar6 = (int *)((int)piVar7 + 1);
      *(undefined1 *)piVar7 = 0;
      piVar7 = piVar6;
    } while (piVar6 != local_2c);
  }
  uVar5 = 0xffffffff;
LAB_00014110:
  if (local_2c[0] != *piVar10) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



/* Address 00014194 | audi_device_binding_authorized | bytes 682 */

void audi_device_binding_authorized(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  byte *pbVar7;
  uint *puVar8;
  byte *pbVar9;
  void *data;
  int iVar10;
  int iVar11;
  SHA256_CTX *pSVar13;
  SHA256_CTX *pSVar12;
  size_t local_2178;
  size_t local_2174;
  int local_2170 [4];
  SHA256_CTX SStack_2160;
  SHA256_CTX SStack_20f0;
  byte abStack_207c [80];
  byte abStack_202c [4096];
  byte abStack_102c [4096];
  int local_2c [2];
  
  iVar1 = DAT_00014450;
  piVar4 = *(int **)(DAT_00014440 + 0x1419e + DAT_00014444);
  local_2178 = 0;
  local_2174 = 0;
  local_2c[0] = *piVar4;
  if (*(int *)(DAT_00014448 + 0x141b0) < 0) {
    puVar8 = SStack_20f0.data + 7;
    do {
      puVar6 = (uint *)((int)puVar8 + 1);
      *(byte *)puVar8 = 0;
      puVar8 = puVar6;
    } while (puVar6 != (uint *)abStack_202c);
    pbVar9 = abStack_202c;
    do {
      pbVar7 = pbVar9 + 1;
      *pbVar9 = 0;
      pbVar9 = pbVar7;
    } while (pbVar7 != abStack_102c);
    pbVar9 = abStack_102c;
    do {
      pbVar7 = pbVar9 + 1;
      *pbVar9 = 0;
      pbVar9 = pbVar7;
    } while (pbVar7 != (byte *)local_2c);
    iVar11 = 0;
    local_2170[0] = *(int *)(DAT_0001444c + 0x14222);
    local_2170[1] = *(undefined4 *)(DAT_0001444c + 0x14226);
    local_2170[2] = *(undefined4 *)(DAT_0001444c + 0x1422a);
    local_2170[3] = *(undefined4 *)(DAT_0001444c + 0x1422e);
    do {
      iVar2 = *(int *)((int)local_2170 + iVar11);
      iVar10 = 0;
      do {
        *(undefined1 *)((int)SStack_20f0.data + iVar10 + iVar11 * 8 + 0x1c) =
             *(undefined1 *)(iVar2 + iVar10);
        iVar10 = iVar10 + 1;
      } while (iVar10 != 0x20);
      iVar11 = iVar11 + 4;
    } while (iVar11 != 0x10);
    iVar11 = read_identity(DAT_00014450 + 0x1424a,abStack_202c,&local_2178);
    if ((iVar11 == 0) &&
       (iVar11 = read_identity(iVar1 + 0x1425e,abStack_102c,&local_2174), iVar11 == 0)) {
      data = (void *)(DAT_00014458 + 0x14308);
      SHA256_Init(&SStack_2160);
      SHA256_Update(&SStack_2160,data,0xe);
      SHA256_Update(&SStack_2160,SStack_20f0.data + 7,0x10);
      puVar8 = SStack_20f0.h + 1;
      SStack_20f0.h[0]._3_1_ = (undefined1)local_2178;
      SStack_20f0.h[0]._0_1_ = (undefined1)(local_2178 >> 0x18);
      SStack_20f0.h[0]._1_1_ = (undefined1)(local_2178 >> 0x10);
      SStack_20f0.h[0]._2_1_ = (undefined1)(local_2178 >> 8);
      SHA256_Update(&SStack_2160,&SStack_20f0,4);
      SHA256_Update(&SStack_2160,abStack_202c,local_2178);
      SStack_20f0.h[0]._3_1_ = (undefined1)local_2174;
      SStack_20f0.h[0]._0_1_ = (undefined1)(local_2174 >> 0x18);
      SStack_20f0.h[0]._1_1_ = (undefined1)(local_2174 >> 0x10);
      SStack_20f0.h[0]._2_1_ = (undefined1)(local_2174 >> 8);
      SHA256_Update(&SStack_2160,&SStack_20f0,4);
      SHA256_Update(&SStack_2160,abStack_102c,local_2174);
      SHA256_Final((uchar *)puVar8,&SStack_2160);
      SHA256_Init(&SStack_2160);
      SHA256_Update(&SStack_2160,(void *)(iVar1 + 0x1426e),0xc);
      SHA256_Update(&SStack_2160,data,0xe);
      SHA256_Update(&SStack_2160,SStack_20f0.data + 7,0x10);
      SHA256_Update(&SStack_2160,puVar8,0x20);
      SHA256_Final((uchar *)&SStack_20f0.Nh,&SStack_2160);
      bVar3 = 0;
      iVar1 = 0;
      do {
        iVar11 = iVar1 + 1;
        bVar3 = bVar3 | *(byte *)((int)SStack_20f0.data + iVar1 + 0x2c) ^
                        *(byte *)((int)puVar8 + iVar1);
        iVar1 = iVar11;
      } while (iVar11 != 0x20);
      iVar1 = 0;
      if (bVar3 == 0) {
        uVar5 = 0;
        iVar1 = 0;
        do {
          iVar11 = iVar1 + 1;
          uVar5 = uVar5 | abStack_207c[iVar1] ^ *(byte *)((int)&SStack_20f0.Nh + iVar1);
          iVar1 = iVar11;
        } while (iVar11 != 0x20);
        iVar1 = 1 - uVar5;
        if (1 < uVar5) {
          iVar1 = 0;
        }
      }
    }
    else {
      iVar1 = 0;
    }
    puVar8 = SStack_20f0.data + 7;
    do {
      puVar6 = (uint *)((int)puVar8 + 1);
      *(byte *)puVar8 = 0;
      puVar8 = puVar6;
    } while (puVar6 != (uint *)abStack_202c);
    pbVar9 = abStack_202c;
    do {
      pbVar7 = pbVar9 + 1;
      *pbVar9 = 0;
      pbVar9 = pbVar7;
    } while (pbVar7 != abStack_102c);
    pbVar9 = abStack_102c;
    do {
      pbVar7 = pbVar9 + 1;
      *pbVar9 = 0;
      pbVar9 = pbVar7;
    } while (pbVar7 != (byte *)local_2c);
    SStack_20f0.h[0]._0_1_ = 0;
    SStack_20f0.h[0]._1_1_ = 0;
    SStack_20f0.h[0]._2_1_ = 0;
    SStack_20f0.h[0]._3_1_ = 0;
    puVar8 = SStack_20f0.h + 1;
    do {
      puVar6 = (uint *)((int)puVar8 + 1);
      *(undefined1 *)puVar8 = 0;
      puVar8 = puVar6;
    } while (puVar6 != &SStack_20f0.Nh);
    puVar8 = &SStack_20f0.Nh;
    do {
      puVar6 = (uint *)((int)puVar8 + 1);
      *(undefined1 *)puVar8 = 0;
      puVar8 = puVar6;
    } while (puVar6 != SStack_20f0.data + 7);
    pSVar12 = &SStack_2160;
    do {
      pSVar13 = (SHA256_CTX *)((int)pSVar12->h + 1);
      *(undefined1 *)pSVar12->h = 0;
      pSVar12 = pSVar13;
    } while (pSVar13 != &SStack_20f0);
    *(int *)(DAT_00014454 + 0x142dc) = iVar1;
  }
  if (local_2c[0] != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 0001445c | _fini | bytes 8 */

void _fini(void)

{
  return;
}



/* Address 0001a000 | __cxa_finalize | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a004 | pthread_mutex_lock | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a008 | _ITM_deregisterTMCloneTable | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a00c | close | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a010 | calloc | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a014 | __get_errno_ptr | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __get_errno_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a018 | free | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a01c | unlink | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a020 | memcpy | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a024 | __stack_chk_fail | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a028 | pthread_mutex_unlock | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a02c | lstat | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int lstat(char *__file,stat *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a030 | fstat | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fstat(int __fd,stat *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a034 | SHA256_Init | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Init(SHA256_CTX *c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a038 | memset | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a03c | getenv | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a044 | vsnprintf | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a048 | __deregister_frame_info | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __deregister_frame_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a04c | __register_frame_info | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __register_frame_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a050 | dlsym | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void dlsym(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a054 | SHA256_Final | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Final(uchar *md,SHA256_CTX *c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a058 | time | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a05c | _Jv_RegisterClasses | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void _Jv_RegisterClasses(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a060 | SHA256_Update | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Update(SHA256_CTX *c,void *data,size_t len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a064 | fsync | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fsync(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a068 | open | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a06c | _ITM_registerTMCloneTable | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a070 | rename | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rename(char *__old,char *__new)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a074 | malloc | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a078 | strcmp | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


