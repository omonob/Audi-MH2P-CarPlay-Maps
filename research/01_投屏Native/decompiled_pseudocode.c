/* BASELINE ANALYSIS ONLY; runtime test-gate patch is described in NATIVE_PATCHES.json. */
/* Package-Date: 2026-10-24. Offline reconstructed code. */
/* GHIDRA RECOVERED PSEUDOCODE - NOT ORIGINAL C SOURCE. */
/* Program: 01_libcarplay_altscreen_hook.so */
/* SHA256: ab20bb0316c71971a6f591ef090dce1e13c1422c082ceb03209d22ebd9cda17a */
/* Verify types, calling conventions, and inferred control flow against disassembly. */

/* Address 00011760 | _init | bytes 8 */

int _init(EVP_PKEY_CTX *ctx)

{
  return (int)ctx;
}



/* Address 0001177c | realloc | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_realloc_0001900c)(__ptr);
  return pvVar1;
}



/* Address 00011788 | __gnu_Unwind_Save_VFP_D_16_to_31 | bytes 12 */

void __gnu_Unwind_Save_VFP_D_16_to_31(void)

{
  (*(code *)PTR___gnu_Unwind_Save_VFP_D_16_to_31_00019010)();
  return;
}



/* Address 00011794 | __cxa_finalize | bytes 12 */

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_00019014)();
  return;
}



/* Address 000117a0 | pthread_mutex_lock | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_lock_00019018)(__mutex);
  return iVar1;
}



/* Address 000117ac | strstr | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strstr_0001901c)(__haystack);
  return pcVar1;
}



/* Address 000117b8 | __gnu_Unwind_Resume_or_Rethrow | bytes 12 */

void __gnu_Unwind_Resume_or_Rethrow(void)

{
  (*(code *)PTR___gnu_Unwind_Resume_or_Rethrow_00019020)();
  return;
}



/* Address 000117c4 | close | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00019024)(__fd);
  return iVar1;
}



/* Address 000117d0 | strchr | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strchr_00019028)(__s);
  return pcVar1;
}



/* Address 000117dc | calloc | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_calloc_0001902c)(__nmemb);
  return pvVar1;
}



/* Address 000117e8 | strncmp | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncmp_00019030)(__s1);
  return iVar1;
}



/* Address 000117f4 | __get_errno_ptr | bytes 12 */

void __get_errno_ptr(void)

{
  (*(code *)PTR___get_errno_ptr_00019034)();
  return;
}



/* Address 00011800 | free | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_00019038)(__ptr);
  return;
}



/* Address 0001180c | abort | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_0001903c)();
  return;
}



/* Address 00011818 | unlink | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_unlink_00019040)(__name);
  return iVar1;
}



/* Address 00011824 | pthread_getspecific | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_pthread_getspecific_00019044)(__key);
  return pvVar1;
}



/* Address 00011830 | memcpy | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00019048)(__dest);
  return pvVar1;
}



/* Address 0001183c | __stack_chk_fail | bytes 12 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_0001904c)();
  return;
}



/* Address 0001184c | pthread_mutex_unlock | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_unlock_00019050)(__mutex);
  return iVar1;
}



/* Address 00011858 | lstat | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int lstat(char *__file,stat *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_lstat_00019054)(__file);
  return iVar1;
}



/* Address 00011864 | fstat | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fstat(int __fd,stat *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fstat_00019058)(__fd);
  return iVar1;
}



/* Address 00011870 | __gnu_Unwind_Restore_VFP_D_16_to_31 | bytes 12 */

void __gnu_Unwind_Restore_VFP_D_16_to_31(void)

{
  (*(code *)PTR___gnu_Unwind_Restore_VFP_D_16_to_31_0001905c)();
  return;
}



/* Address 0001187c | SHA256_Init | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Init(SHA256_CTX *c)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_SHA256_Init_00019060)(c);
  return iVar1;
}



/* Address 00011888 | __gnu_Unwind_Save_VFP_D | bytes 12 */

void __gnu_Unwind_Save_VFP_D(void)

{
  (*(code *)PTR___gnu_Unwind_Save_VFP_D_00019064)();
  return;
}



/* Address 00011894 | memset | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00019068)(__s);
  return pvVar1;
}



/* Address 000118a0 | __gnu_Unwind_Backtrace | bytes 12 */

void __gnu_Unwind_Backtrace(void)

{
  (*(code *)PTR___gnu_Unwind_Backtrace_0001906c)();
  return;
}



/* Address 000118ac | __gnu_Unwind_Save_WMMXC | bytes 12 */

void __gnu_Unwind_Save_WMMXC(void)

{
  (*(code *)PTR___gnu_Unwind_Save_WMMXC_00019070)();
  return;
}



/* Address 000118b8 | __cxa_begin_cleanup | bytes 12 */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_00019074)();
  return;
}



/* Address 000118c4 | pthread_key_create | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_key_create_00019078)(__key);
  return iVar1;
}



/* Address 000118d0 | __gnu_Unwind_Find_exidx | bytes 12 */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_0001907c)();
  return;
}



/* Address 000118dc | pthread_cond_wait | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_wait_00019080)(__cond);
  return iVar1;
}



/* Address 000118e8 | _Unwind_VRS_Set | bytes 12 */

void _Unwind_VRS_Set(void)

{
  (*(code *)PTR__Unwind_VRS_Set_00019084)();
  return;
}



/* Address 000118f4 | __gnu_unwind_execute | bytes 12 */

void __gnu_unwind_execute(void)

{
  (*(code *)PTR___gnu_unwind_execute_00019088)();
  return;
}



/* Address 00011900 | __cxa_type_match | bytes 12 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_0001908c)();
  return;
}



/* Address 0001190c | __gnu_Unwind_Restore_WMMXC | bytes 12 */

void __gnu_Unwind_Restore_WMMXC(void)

{
                    /* WARNING: Could not recover jumptable at 0x00011914. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR___gnu_Unwind_Restore_WMMXC_00019090)();
  return;
}



/* Address 00011918 | read | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_00019094)(__fd);
  return sVar1;
}



/* Address 00011924 | shutdown | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int shutdown(int __fd,int __how)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_shutdown_00019098)(__fd);
  return iVar1;
}



/* Address 00011930 | _Unwind_VRS_Get | bytes 12 */

void _Unwind_VRS_Get(void)

{
  (*(code *)PTR__Unwind_VRS_Get_0001909c)();
  return;
}



/* Address 0001193c | pthread_once | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_once(pthread_once_t *__once_control,__init_routine *__init_routine)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_once_000190a0)(__once_control);
  return iVar1;
}



/* Address 00011948 | __gnu_Unwind_Restore_VFP_D | bytes 12 */

void __gnu_Unwind_Restore_VFP_D(void)

{
  (*(code *)PTR___gnu_Unwind_Restore_VFP_D_000190a4)();
  return;
}



/* Address 00011954 | pthread_cond_broadcast | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_broadcast(pthread_cond_t *__cond)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_broadcast_000190a8)(__cond);
  return iVar1;
}



/* Address 00011960 | pthread_setspecific | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_setspecific_000190ac)(__key);
  return iVar1;
}



/* Address 0001196c | __gnu_Unwind_Restore_VFP | bytes 12 */

void __gnu_Unwind_Restore_VFP(void)

{
  (*(code *)PTR___gnu_Unwind_Restore_VFP_000190b0)();
  return;
}



/* Address 00011978 | __deregister_frame_info | bytes 12 */

void __deregister_frame_info(void)

{
  (*(code *)PTR___deregister_frame_info_000190b4)();
  return;
}



/* Address 00011984 | snprintf | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_000190b8)(__s);
  return iVar1;
}



/* Address 00011990 | __register_frame_info | bytes 12 */

void __register_frame_info(void)

{
  (*(code *)PTR___register_frame_info_000190bc)();
  return;
}



/* Address 0001199c | __gnu_Unwind_Resume | bytes 12 */

void __gnu_Unwind_Resume(void)

{
  (*(code *)PTR___gnu_Unwind_Resume_000190c0)();
  return;
}



/* Address 000119a8 | getpid | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_getpid_000190c4)();
  return _Var1;
}



/* Address 000119c4 | dup | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_dup_000190cc)(__fd);
  return iVar1;
}



/* Address 000119d0 | __gnu_Unwind_ForcedUnwind | bytes 12 */

void __gnu_Unwind_ForcedUnwind(void)

{
  (*(code *)PTR___gnu_Unwind_ForcedUnwind_000190d0)();
  return;
}



/* Address 000119dc | write | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_000190d4)(__fd);
  return sVar1;
}



/* Address 000119e8 | SHA256_Final | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Final(uchar *md,SHA256_CTX *c)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_SHA256_Final_000190d8)(md);
  return iVar1;
}



/* Address 000119f4 | pthread_join | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_join_000190dc)(__th);
  return iVar1;
}



/* Address 00011a00 | pthread_create | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_000190e0)(__newthread);
  return iVar1;
}



/* Address 00011a0c | __gnu_Unwind_Save_VFP | bytes 12 */

void __gnu_Unwind_Save_VFP(void)

{
  (*(code *)PTR___gnu_Unwind_Save_VFP_000190e4)();
  return;
}



/* Address 00011a18 | memcmp | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_000190e8)(__s1);
  return iVar1;
}



/* Address 00011a24 | SHA256_Update | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Update(SHA256_CTX *c,void *data,size_t len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_SHA256_Update_000190ec)(c);
  return iVar1;
}



/* Address 00011a30 | __gnu_Unwind_RaiseException | bytes 12 */

void __gnu_Unwind_RaiseException(void)

{
  (*(code *)PTR___gnu_Unwind_RaiseException_000190f0)();
  return;
}



/* Address 00011a3c | _Unwind_VRS_Pop | bytes 12 */

void _Unwind_VRS_Pop(void)

{
  (*(code *)PTR__Unwind_VRS_Pop_000190f4)();
  return;
}



/* Address 00011a48 | restore_core_regs | bytes 12 */

void restore_core_regs(void)

{
  (*(code *)PTR_restore_core_regs_000190f8)();
  return;
}



/* Address 00011a54 | __emutls_get_address | bytes 12 */

void __emutls_get_address(void)

{
  (*(code *)PTR___emutls_get_address_000190fc)();
  return;
}



/* Address 00011a60 | open | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_00019100)(__file);
  return iVar1;
}



/* Address 00011a6c | strlen | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00019104)(__s);
  return sVar1;
}



/* Address 00011a78 | strtol | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_strtol_00019108)(__nptr);
  return lVar1;
}



/* Address 00011a84 | nanosleep | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int nanosleep(timespec *__requested_time,timespec *__remaining)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_nanosleep_0001910c)(__requested_time);
  return iVar1;
}



/* Address 00011a90 | rename | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rename(char *__old,char *__new)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_rename_00019110)(__old);
  return iVar1;
}



/* Address 00011a9c | malloc | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00019114)(__size);
  return pvVar1;
}



/* Address 00011aa8 | strcmp | bytes 12 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00019118)(__s1);
  return iVar1;
}



/* Address 00011ab4 | __gnu_Unwind_Restore_WMMXD | bytes 12 */

void __gnu_Unwind_Restore_WMMXD(void)

{
  (*(code *)PTR___gnu_Unwind_Restore_WMMXD_0001911c)();
  return;
}



/* Address 00011ac0 | __gnu_Unwind_Save_WMMXD | bytes 12 */

void __gnu_Unwind_Save_WMMXD(void)

{
  (*(code *)PTR___gnu_Unwind_Save_WMMXD_00019120)();
  return;
}



/* Address 00011acc | ctl_preload_constructor | bytes 24 */

void processEntry ctl_preload_constructor(void)

{
  int iVar1;
  
  iVar1 = audi_device_binding_authorized();
  *(int *)(DAT_00011ae4 + 0x11b04) = iVar1;
  if (iVar1 == 0) {
    return;
  }
  ctl_start();
  return;
}



/* Address 00011ae8 | deregister_tm_clones | bytes 38 */

void deregister_tm_clones(void)

{
  code *pcVar1;
  
  if (6 < (uint)((DAT_00011b10 + 0x11af3) - (DAT_00011b14 + 0x11af6))) {
    pcVar1 = *(code **)(DAT_00011b18 + 0x11afa + DAT_00011b1c);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
    }
  }
  return;
}



/* Address 00011b20 | register_tm_clones | bytes 44 */

void register_tm_clones(void)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (DAT_00011b50 + 0x11b2c) - (DAT_00011b4c + 0x11b28);
  iVar2 = (iVar2 >> 2) - (iVar2 >> 0x1f) >> 1;
  if ((iVar2 != 0) &&
     (pcVar1 = *(code **)(DAT_00011b54 + 0x11b30 + DAT_00011b58), pcVar1 != (code *)0x0)) {
    (*pcVar1)(DAT_00011b4c + 0x11b28,iVar2);
  }
  return;
}



/* Address 00011b5c | __do_global_dtors_aux | bytes 60 */

void __do_global_dtors_aux(void)

{
  int iVar1;
  
  iVar1 = DAT_00011b9c + 0x11b6a;
  if (*(char *)(DAT_00011b98 + 0x11b68) == '\0') {
    if (*(int *)(iVar1 + DAT_00011ba0) != 0) {
      __cxa_finalize(*(undefined4 *)(DAT_00011ba4 + 0x11b78));
    }
    deregister_tm_clones();
    if (*(int *)(iVar1 + DAT_00011ba8) != 0) {
      __deregister_frame_info(DAT_00011bac + 0x11b8c);
    }
    *(undefined1 *)(DAT_00011bb0 + 0x11b96) = 1;
  }
  return;
}



/* Address 00011bb4 | frame_dummy | bytes 48 */

void frame_dummy(void)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = DAT_00011be4 + 0x11bc0;
  if (*(int *)(iVar2 + DAT_00011be8) != 0) {
    __register_frame_info(DAT_00011bec + 0x11bca,DAT_00011bf0 + 0x11bcc);
  }
  if ((*(int *)(DAT_00011bf4 + 0x11bd4) != 0) &&
     (pcVar1 = *(code **)(iVar2 + DAT_00011bf8), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  register_tm_clones();
  return;
}



/* Address 00011bfc | show_ui_completion | bytes 2 */

void show_ui_completion(void)

{
  return;
}



/* Address 00011c00 | zoom_completion | bytes 2 */

void zoom_completion(void)

{
  return;
}



/* Address 00011c04 | view_area_completion | bytes 2 */

void view_area_completion(void)

{
  return;
}



/* Address 00011c08 | alt_clock_get_ntp | bytes 38 */

undefined8 alt_clock_get_ntp(int param_1)

{
  undefined8 uVar1;
  
  if (((param_1 == 0) || (*(code **)(DAT_00011c30 + 0x11c12) == (code *)0x0)) ||
     (*(int *)(param_1 + 0x15ac) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_00011c30 + 0x11c12))();
  }
  return uVar1;
}



/* Address 00011c34 | alt_clock_get_ticks_near_ntp | bytes 38 */

undefined8 alt_clock_get_ticks_near_ntp(int param_1)

{
  undefined8 uVar1;
  
  if (((param_1 == 0) || (*(code **)(DAT_00011c5c + 0x11c42) == (code *)0x0)) ||
     (*(int *)(param_1 + 0x15ac) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_00011c5c + 0x11c42))();
  }
  return uVar1;
}



/* Address 00011c60 | must_sym | bytes 12 */

void must_sym(undefined4 param_1)

{
  (*(code *)&LAB_000119b8)(0xfffffffd,param_1);
  return;
}



/* Address 00011c6c | close_fd | bytes 22 */

void close_fd(int *param_1)

{
  if (-1 < *param_1) {
    close(*param_1);
    *param_1 = -1;
  }
  return;
}



/* Address 00011c84 | abort_alt_stream | bytes 30 */

void abort_alt_stream(int *param_1)

{
  close_fd(param_1 + 1);
  if ((*param_1 != 0) && (*(code **)(DAT_00011ca4 + 0x11ca0) != (code *)0x0)) {
    (**(code **)(DAT_00011ca4 + 0x11ca0))();
  }
  *param_1 = 0;
  return;
}



/* Address 00011ca8 | idle_read_set_matches_session | bytes 134 */

void idle_read_set_matches_session(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(DAT_00011d30 + 0x11cbe + DAT_00011d34);
  if ((param_1 != 0 && param_3 != 0) && (0 < param_2)) {
    uVar1 = *(uint *)(param_1 + 0x15ec);
    uVar2 = *(uint *)(param_1 + 0x15f4);
    if (((-1 < (int)uVar1) &&
        ((((int)uVar1 < param_2 && ((int)uVar1 < 0x100)) &&
         ((*(int *)(param_3 + ((int)uVar1 >> 5) * 4) >> (uVar1 & 0x1f)) << 0x1f < 0)))) ||
       ((((-1 < (int)uVar2 && ((int)uVar2 < param_2)) && ((int)uVar2 < 0x100)) &&
        ((*(int *)(param_3 + ((int)uVar2 >> 5) * 4) >> (uVar2 & 0x1f)) << 0x1f < 0)))) {
      uVar3 = 1;
      goto LAB_00011d04;
    }
  }
  uVar3 = 0;
LAB_00011d04:
  if (*piVar4 != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Address 00011d38 | ctl_write_state | bytes 180 */

void ctl_write_state(char *param_1,char *param_2)

{
  __pid_t param5;
  size_t __n;
  int iVar1;
  size_t sVar2;
  int *piVar3;
  char *__file;
  char acStack_bc [160];
  int local_1c;
  
  piVar3 = *(int **)(DAT_00011dec + 0x11d40 + DAT_00011df0);
  local_1c = *piVar3;
  param5 = getpid();
  __n = snprintf(acStack_bc,0xa0,(char *)(DAT_00011df8 + 0x11d62),param_1,param_2,param5,
                 *(ulong *)(DAT_00011df4 + 0x11d6c));
  if (__n - 1 < 0x9f) {
    __file = (char *)(DAT_00011dfc + 0x11d90);
    iVar1 = open(__file,0x301,0x1b6);
    if (-1 < iVar1) {
      sVar2 = write(iVar1,acStack_bc,__n);
      close(iVar1);
      if ((sVar2 == __n) && (iVar1 = rename(__file,(char *)(DAT_00011e08 + 0x11de0)), iVar1 == 0))
      goto LAB_00011d74;
      unlink((char *)(DAT_00011e00 + 0x11db2));
    }
    iVar1 = open((char *)(DAT_00011e04 + 0x11dc2),0x301,0x1b6);
    if (-1 < iVar1) {
      write(iVar1,acStack_bc,__n);
      close(iVar1);
    }
  }
LAB_00011d74:
  if (local_1c != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 00011e0c | ctl_read_path_command | bytes 68 */

bool ctl_read_path_command(char *param_1,char *param_2,int param_3)

{
  int __fd;
  ssize_t sVar1;
  char *pcVar2;
  
  __fd = open(param_1,0);
  if (-1 < __fd) {
    sVar1 = read(__fd,param_2,param_3 - 1);
    close(__fd);
    if (0 < sVar1) {
      param_2[sVar1] = '\0';
      pcVar2 = strchr(param_2,10);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      return *param_2 != '\0';
    }
  }
  return false;
}



/* Address 00011e50 | cfl_string | bytes 42 */

undefined4 cfl_string(char *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar1 = DAT_00011e7c;
  *param_2 = 0;
  pcVar4 = *(code **)(iVar1 + 0x11e70);
  if ((pcVar4 == (code *)0x0) || (param_1 == (char *)0x0)) {
    return 0xffffffff;
  }
  sVar2 = strlen(param_1);
  uVar3 = (*pcVar4)(0,param_1,sVar2,param_2,param_4);
  return uVar3;
}



/* Address 00011e80 | dict_set_text | bytes 126 */

void dict_set_text(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_24;
  int local_20;
  int local_1c;
  
  piVar4 = *(int **)(DAT_00011f00 + 0x11e90 + DAT_00011f04);
  local_24 = 0;
  local_20 = 0;
  local_1c = *piVar4;
  iVar1 = cfl_string(param_2,&local_24);
  if ((iVar1 == 0) && (local_24 != 0)) {
    iVar2 = cfl_string(param_3,&local_20);
    iVar1 = DAT_00011f08;
    if ((iVar2 == 0) && (local_20 != 0)) {
      uVar3 = (**(code **)(DAT_00011f08 + 0x11edc))(param_1,local_24);
      (**(code **)(iVar1 + 0x11ed8))(local_24);
      (**(code **)(iVar1 + 0x11ed8))(local_20);
      goto LAB_00011ed4;
    }
    if (local_24 != 0) {
      uVar3 = 0xffffffff;
      (**(code **)((int)&DAT_00011f04 + DAT_00011f0c))();
      goto LAB_00011ed4;
    }
  }
  uVar3 = 0xffffffff;
LAB_00011ed4:
  if (local_1c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Address 00011f10 | dict_set_i64 | bytes 136 */

void dict_set_i64(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  
  piVar4 = *(int **)(DAT_00011f98 + 0x11f22 + DAT_00011f9c);
  local_20 = 0;
  local_1c = *piVar4;
  iVar2 = cfl_string(param_2,&local_20);
  iVar1 = DAT_00011fa0;
  if ((iVar2 == 0) && (local_20 != 0)) {
    if ((*(code **)(DAT_00011fa0 + 0x11f64) == (code *)0x0) ||
       (iVar2 = (**(code **)(DAT_00011fa0 + 0x11f64))(param_3,param_4), iVar2 == 0)) {
      uVar3 = 0xffffffff;
      (**(code **)((int)&DAT_00011fa4 + DAT_00011fa4))(local_20);
    }
    else {
      uVar3 = (**(code **)(iVar1 + 0x11f60))(param_1,local_20,iVar2);
      (**(code **)(iVar1 + 0x11f5c))(local_20);
      (**(code **)(iVar1 + 0x11f5c))(iVar2);
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  if (local_1c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Address 00011fa8 | create_alt_surface_dict | bytes 186 */

void create_alt_surface_dict(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_30;
  int local_2c;
  
  iVar1 = DAT_0001206c;
  piVar2 = *(int **)(DAT_00012064 + 0x11fbc + DAT_00012068);
  uVar3 = *(undefined4 *)(DAT_0001206c + 0x11fec);
  local_2c = *piVar2;
  uVar4 = *(undefined4 *)(DAT_0001206c + 0x11ff0);
  local_30 = 0;
  *param_5 = 0;
  iVar1 = (**(code **)(iVar1 + 0x11fe8))(0,4,uVar3,uVar4,&local_30);
  if ((iVar1 == 0) && (local_30 != 0)) {
    iVar1 = dict_set_i64(local_30,DAT_00012070 + 0x11ffe,param_3,param_3 >> 0x1f);
    if ((((iVar1 == 0) &&
         (iVar1 = dict_set_i64(local_30,DAT_00012074 + 0x12010,param_4,param_4 >> 0x1f), iVar1 == 0)
         ) && (iVar1 = dict_set_i64(local_30,DAT_00012078 + 0x12020,param_1,param_1 >> 0x1f),
              iVar1 == 0)) &&
       (iVar1 = dict_set_i64(local_30,DAT_0001207c + 0x12030,param_2,param_2 >> 0x1f), iVar1 == 0))
    {
      *param_5 = local_30;
      uVar3 = 0;
    }
    else {
      (**(code **)((int)&DAT_00012064 + DAT_00012080))(local_30);
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  if (local_2c != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Address 00012084 | dict_set_object | bytes 90 */

void dict_set_object(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  
  piVar4 = *(int **)(DAT_000120e0 + 0x12090 + DAT_000120e4);
  local_20 = 0;
  local_1c = *piVar4;
  if (((param_1 == 0 || param_3 == 0) ||
      (iVar2 = cfl_string(param_2,&local_20), iVar1 = DAT_000120e8, iVar2 != 0)) || (local_20 == 0))
  {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (**(code **)(DAT_000120e8 + 0x120d4))(param_1,local_20,param_3);
    (**(code **)(iVar1 + 0x120d0))(local_20);
  }
  if (local_1c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Address 000120ec | ctl_poll_view_area_update | bytes 502 */

void ctl_poll_view_area_update(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  pthread_mutex_t *__mutex;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  iVar2 = DAT_000122f0;
  iVar1 = DAT_000122ec;
  piVar3 = *(int **)(DAT_000122e4 + 0x120f4 + DAT_000122e8);
  local_24 = *piVar3;
  __mutex = (pthread_mutex_t *)(DAT_000122ec + 0x1210c);
  pthread_mutex_lock((pthread_mutex_t *)(DAT_000122ec + 0x12104));
  pthread_mutex_lock(__mutex);
  if (((((*(int *)(iVar2 + 0x12136) == 0) || (*(int *)(iVar2 + 0x1213a) == 0)) ||
       (*(int *)(iVar2 + 0x1213e) == 0)) ||
      ((iVar4 = *(int *)(iVar2 + 0x12142), iVar4 == 0 ||
       (iVar6 = *(int *)(iVar2 + 0x12146), iVar6 != 0)))) ||
     ((*(int *)(iVar2 + 0x1214a) == 0 || (iVar5 = *(int *)(iVar1 + 0x12114), iVar5 < 0)))) {
    pthread_mutex_unlock((pthread_mutex_t *)(DAT_000122f4 + 0x1212c));
    goto LAB_00012128;
  }
  *(undefined4 *)(iVar1 + 0x12114) = 0xffffffff;
  pthread_mutex_unlock(__mutex);
  if (((*(int *)(iVar2 + 0x1214e) == 0) || (*(char *)(iVar4 + 0x3c6) == '\0')) ||
     ((local_30 = iVar6, local_2c = iVar6, local_28 = iVar6,
      iVar1 = (**(code **)(iVar2 + 0x1212a))
                        (0,2,*(undefined4 *)(iVar2 + 0x1212e),*(undefined4 *)(iVar2 + 0x12132),
                         &local_30), iVar1 != 0 || (local_30 == 0)))) {
LAB_000122aa:
    pthread_mutex_lock((pthread_mutex_t *)(DAT_0001233c + 0x122b8));
    if (iVar4 == *(int *)((int)&DAT_000122f0 + DAT_00012340 + 2)) {
LAB_000122be:
      if (*(int *)(DAT_00012344 + 0x122d4) < 0) {
        *(uint *)(DAT_00012344 + 0x122d4) =
             (uint)(*(int *)((int)&DAT_0001231c + DAT_00012348 + 2) != 0);
      }
    }
  }
  else {
    iVar2 = dict_set_text(local_30,DAT_000122fc + 0x121b4,DAT_00012300 + 0x121b6);
    iVar1 = DAT_00012304;
    if ((((((iVar2 != 0) ||
           (iVar2 = (**(code **)(DAT_00012304 + 0x121e8))
                              (0,4,*(undefined4 *)(DAT_00012304 + 0x121ec),
                               *(undefined4 *)(DAT_00012304 + 0x121f0),&local_2c), iVar2 != 0)) ||
          (local_2c == 0)) ||
         ((iVar2 = dict_set_text(local_2c,DAT_00012308 + 0x121e0,DAT_0001230c + 0x121e2), iVar2 != 0
          || (iVar2 = dict_set_i64(local_2c,DAT_00012310 + 0x121f4,0,0), iVar2 != 0)))) ||
        (iVar2 = dict_set_i64(local_2c,DAT_00012314 + 0x12206,iVar5,iVar5 >> 0x1f), iVar2 != 0)) ||
       (iVar1 = (**(code **)(iVar1 + 0x12210))(0,*(undefined4 *)(iVar1 + 0x12214),&local_28),
       iVar1 != 0)) {
LAB_00012288:
      if (local_28 != 0) {
        (**(code **)(DAT_00012330 + 0x122a6))();
      }
LAB_00012294:
      if (local_2c != 0) {
        (**(code **)(DAT_00012334 + 0x122b2))();
      }
      (**(code **)(DAT_00012338 + 0x122bc))(local_30);
      goto LAB_000122aa;
    }
    if (local_28 == 0) goto LAB_00012294;
    iVar1 = dict_set_object(local_2c,DAT_00012318 + 0x12226);
    if ((iVar1 != 0) ||
       (iVar2 = dict_set_object(local_30,DAT_0001231c + 0x12234,local_2c), iVar1 = DAT_00012320,
       iVar2 != 0)) goto LAB_00012288;
    (**(code **)(DAT_00012320 + 0x12258))(local_28);
    (**(code **)(iVar1 + 0x12258))(local_2c);
    iVar2 = local_30;
    if (local_30 == 0) goto LAB_000122aa;
    iVar6 = (**(code **)(iVar1 + 0x12288))(iVar4,local_30,DAT_00012324 + 0x12262,0);
    (**(code **)(iVar1 + 0x12258))(iVar2);
    pthread_mutex_lock((pthread_mutex_t *)(DAT_00012328 + 0x1227a));
    if ((iVar4 == *(int *)(iVar1 + 0x1227c)) && (iVar6 != 0)) goto LAB_000122be;
  }
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_0001232c + 0x1228a));
LAB_00012128:
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_000122f8 + 0x1212e));
  if (local_24 != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 0001234c | dict_get_key | bytes 88 */

void dict_get_key(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  
  piVar4 = *(int **)(DAT_000123a4 + 0x1235c + DAT_000123a8);
  local_20 = 0;
  local_1c = *piVar4;
  *param_3 = 0;
  iVar2 = cfl_string(param_2,&local_20);
  iVar1 = DAT_000123ac;
  if ((iVar2 == 0) && (local_20 != 0)) {
    uVar3 = (**(code **)(DAT_000123ac + 0x123d6))(param_1,local_20,param_3);
    (**(code **)(iVar1 + 0x12396))(local_20);
  }
  else {
    uVar3 = 0xffffffff;
  }
  if (local_1c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Address 000123b0 | set_info_url_array | bytes 190 */

void set_info_url_array(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  int local_2c;
  int local_28;
  int local_24;
  
  piVar7 = *(int **)(DAT_00012470 + 0x123be + DAT_00012474);
  local_2c = 0;
  local_24 = *piVar7;
  if (((*(code **)(DAT_00012478 + 0x12414) != (code *)0x0) &&
      (iVar2 = (**(code **)(DAT_00012478 + 0x12414))
                         (0,*(undefined4 *)(DAT_00012478 + 0x12418),&local_2c), iVar1 = DAT_00012480
      , iVar2 == 0)) && (local_2c != 0)) {
    puVar5 = (undefined4 *)(DAT_0001247c + 0x123f0);
    puVar6 = (undefined4 *)(DAT_0001247c + 0x123fc);
    do {
      puVar5 = puVar5 + 1;
      local_28 = iVar2;
      iVar3 = cfl_string(*puVar5,&local_28);
      if ((iVar3 != 0) || (local_28 == 0)) {
        uVar4 = 0xffffffff;
        (**(code **)((int)&DAT_00012478 + DAT_00012484 + 2))(local_2c);
        goto LAB_00012436;
      }
      iVar3 = (**(code **)(iVar1 + 0x12450))(local_2c);
      if (iVar3 != 0) {
        (**(code **)(iVar1 + 0x1240c))(local_28);
        (**(code **)(iVar1 + 0x1240c))(local_2c);
        goto LAB_00012454;
      }
      (**(code **)(iVar1 + 0x1240c))(local_28);
      iVar3 = local_2c;
    } while (puVar5 != puVar6);
    if (local_2c != 0) {
      uVar4 = dict_set_object(param_1,param_2,local_2c);
      (**(code **)(iVar1 + 0x1240c))(iVar3);
      goto LAB_00012436;
    }
  }
LAB_00012454:
  uVar4 = 0xffffffff;
LAB_00012436:
  if (local_24 != *piVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



/* Address 00012488 | parse_setup_request | bytes 408 */

void parse_setup_request(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  piVar8 = *(int **)(DAT_00012620 + 0x1249a + DAT_00012624);
  local_44 = 0;
  local_40 = 0;
  local_2c = *piVar8;
  memset(param_2,0,0x28);
  if ((((param_1 == 0) ||
       (iVar3 = dict_get_key(param_1,DAT_00012628 + 0x124bc,&local_44), iVar1 = DAT_0001262c,
       iVar3 != 0)) || (local_44 == 0)) ||
     (iVar3 = (**(code **)(DAT_0001262c + 0x1252c))(local_44,&local_40), iVar3 != 0)) {
    uVar5 = 0;
    goto LAB_0001257a;
  }
  param_2[4] = local_40;
  iVar2 = DAT_00012638;
  if (local_40 != 0) {
    iVar9 = DAT_00012630 + 0x124f2;
    iVar11 = DAT_00012634 + 0x124f4;
    uVar10 = 0;
    do {
      local_3c = iVar3;
      local_38 = iVar3;
      iVar4 = (**(code **)(iVar1 + 0x12530))(local_44,uVar10,&local_3c);
      if (((iVar4 == 0) && (local_3c != 0)) &&
         ((iVar4 = dict_get_key(local_3c,iVar9,&local_38), iVar4 == 0 && (local_38 != 0)))) {
        pcVar6 = *(code **)(iVar1 + 0x12534);
        local_30 = -1;
        if (pcVar6 == (code *)0x0) goto LAB_0001254c;
        lVar12 = (*pcVar6)(local_38,&local_30);
        if (local_30 != 0) goto LAB_0001254c;
        if ((int)((ulonglong)lVar12 >> 0x20) != 0 || ((uint)lVar12 & 0xfffffffd) != 100) {
          if (lVar12 == 0x65) {
            param_2[3] = param_2[3] | 2;
          }
          else {
            if (lVar12 != 0x6e) goto LAB_00012544;
            param_2[3] = param_2[3] | 4;
          }
          goto LAB_0001254c;
        }
        param_2[3] = param_2[3] | 1;
LAB_00012544:
        if (lVar12 != 0x6f) goto LAB_0001254c;
        iVar4 = param_2[7];
        param_2[1] = 1;
        param_2[5] = param_2[5] + 1;
        if (iVar4 == 0) {
          param_2[7] = local_3c;
          local_34 = iVar4;
          iVar4 = dict_get_key(local_3c,iVar11,&local_34);
          if ((iVar4 == 0) && (local_34 != 0)) {
            local_30 = -1;
            if ((*(code **)(iVar2 + 0x1255a) != (code *)0x0) &&
               ((lVar12 = (**(code **)(iVar2 + 0x1255a))(local_34,&local_30), local_30 == 0 &&
                (lVar12 != 0)))) {
              *(longlong *)(param_2 + 8) = lVar12;
            }
          }
        }
      }
      else {
LAB_0001254c:
        param_2[6] = param_2[6] + 1;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < local_40);
  }
  if (param_2[1] == 0) {
    param_2[2] = 0;
LAB_00012570:
    uVar7 = 0;
  }
  else {
    if (((param_2[5] == 1) && (param_2[7] != 0)) && (param_2[8] != 0 || param_2[9] != 0)) {
      param_2[2] = 1;
    }
    else {
      param_2[2] = 0;
    }
    if ((param_2[5] != param_2[4]) || (param_2[6] != 0)) goto LAB_00012570;
    uVar7 = 1;
  }
  uVar5 = 1;
  *param_2 = uVar7;
LAB_0001257a:
  if (local_2c != *piVar8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



/* Address 0001263c | string_equals | bytes 102 */

void string_equals(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  void *local_24;
  size_t local_20;
  int local_1c;
  
  piVar4 = *(int **)(DAT_000126a4 + 0x1264e + DAT_000126a8);
  local_24 = (void *)0x0;
  local_20 = 0;
  local_1c = *piVar4;
  sVar1 = strlen(param_2);
  if (((*(code **)(DAT_000126ac + 0x126ca) == (code *)0x0) ||
      (iVar2 = (**(code **)(DAT_000126ac + 0x126ca))(param_1,&local_24,&local_20), iVar2 != 0)) ||
     (local_24 == (void *)0x0)) {
    iVar2 = 0;
  }
  else if (local_20 == sVar1) {
    uVar3 = memcmp(local_24,param_2,local_20);
    iVar2 = 1 - uVar3;
    if (1 < uVar3) {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
  }
  if (local_1c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



/* Address 000126b0 | alt_worker_main | bytes 824 */

void alt_worker_main(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  pthread_mutex_t *ppVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  pthread_cond_t *__cond;
  int iVar10;
  int *piVar11;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar10 = DAT_000129f4;
  piVar4 = *(int **)(DAT_000129e8 + 0x126b8 + DAT_000129ec);
  ppVar5 = (pthread_mutex_t *)(DAT_000129f0 + 0x126cc);
  local_40 = -1;
  local_2c = *piVar4;
  local_3c = 0;
  local_44 = param_1;
  puVar1 = (undefined4 *)__emutls_get_address(DAT_000129f0 + 0x126d8);
  *puVar1 = 1;
  pthread_mutex_lock(ppVar5);
  *(undefined4 *)(iVar10 + 0x12718) = 0;
  pthread_mutex_unlock(ppVar5);
  pcVar3 = *(code **)(iVar10 + 0x12750);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(0x11);
  }
  iVar10 = DAT_000129f8;
  if (((*(code **)(DAT_000129f8 + 0x12774) != (code *)0x0) &&
      (iVar2 = (**(code **)(DAT_000129f8 + 0x12774))(local_44,0x1e,&local_40,0),
      iVar6 = DAT_00012a1c, iVar2 == 0)) && (-1 < local_40)) {
    close_fd(&local_44);
    pthread_mutex_lock((pthread_mutex_t *)(iVar6 + 0x127ca));
    *(undefined4 *)(iVar6 + 0x127e6) = 0xffffffff;
    iVar2 = dup(local_40);
    iVar7 = *(int *)(iVar10 + 0x1273c);
    iVar8 = *(int *)(iVar10 + 0x12778);
    *(int *)(iVar6 + 0x127ea) = iVar2;
    iVar6 = DAT_00012a34;
    iVar10 = 0;
    if (iVar7 != 0) {
      iVar10 = *(int *)(iVar7 + 0xc);
    }
    if ((*(int *)(DAT_00012a20 + 0x1282a) == 0) && (iVar10 != 0 && iVar7 != 0)) {
      local_58 = *(int *)(iVar7 + 0x18);
      iVar2 = iVar10 + 0x4c;
      local_5c = *(undefined4 *)(iVar10 + 0x60);
      local_34 = DAT_00012a24 + 0x12814;
      local_50 = *(int *)(iVar10 + 0x68);
      local_54 = *(int *)(iVar10 + 0x1b4);
      uVar9 = *(undefined4 *)(iVar10 + 100);
      local_30 = DAT_00012a28 + 0x12828;
      local_38 = iVar7;
    }
    else {
      local_38 = 0;
      local_34 = 0;
      iVar2 = 0;
      local_50 = 0;
      uVar9 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_30 = 0;
    }
    if (*(int *)(DAT_00012a2c + 0x1285e) != 0) {
      uVar9 = 0;
      local_5c = 0;
    }
    ppVar5 = (pthread_mutex_t *)(DAT_00012a30 + 0x1284c);
    piVar11 = (int *)(DAT_00012a34 + 0x1284a);
    pthread_mutex_unlock(ppVar5);
    if (((*(int *)(iVar6 + 0x12886) == 0) && (iVar8 != 0 && iVar7 != 0)) &&
       ((iVar10 != 0 &&
        (((*piVar11 != 0 && (*(int *)(iVar6 + 0x1284e) != 0)) && (local_58 != 0 && iVar2 != 0))))))
    {
      iVar10 = 0;
      if (local_50 != 0) {
        iVar10 = local_54;
      }
      if ((local_50 != 0 && local_54 != 0) && -1 < iVar10) {
        if (*(int *)(iVar6 + 0x12876) == 0) {
LAB_000128a4:
          iVar10 = DAT_00012a38;
          if (((*(code **)(DAT_00012a38 + 0x12926) != (code *)0x0) &&
              (iVar7 = (**(code **)(DAT_00012a38 + 0x12926))(&local_3c,local_40),
              iVar6 = DAT_00012a3c, iVar7 == 0)) && (local_3c != 0)) {
            local_40 = -1;
            (**(code **)(iVar10 + 0x1292a))(iVar8,&local_38);
            puVar1 = (undefined4 *)__emutls_get_address(iVar6 + 0x1290e);
            *puVar1 = 0;
            puVar1 = (undefined4 *)__emutls_get_address(iVar6 + 0x1291e);
            *puVar1 = 1;
            iVar6 = (**(code **)(iVar10 + 0x1292e))(iVar8,local_58,local_5c,uVar9,local_50,iVar2);
            *puVar1 = 0;
            if (iVar6 == 0) {
              (**(code **)(iVar10 + 0x12932))(iVar8,1);
              (**(code **)(iVar10 + 0x12936))(iVar8,local_3c,local_54);
            }
          }
        }
        else {
          pthread_mutex_lock(ppVar5);
          iVar10 = DAT_00012a48;
          if (*(int *)(iVar6 + 0x12886) == 0) {
            __cond = (pthread_cond_t *)(DAT_00012a44 + 0x129cc);
            ppVar5 = (pthread_mutex_t *)(DAT_00012a44 + 0x129a8);
            do {
              if ((*(int *)(iVar6 + 0x1287a) != 0) && (*(int *)(iVar6 + 0x128c2) == iVar7)) {
                pthread_mutex_unlock((pthread_mutex_t *)((int)&DAT_000129e8 + DAT_00012a50 + 2));
                goto LAB_000128a4;
              }
              pthread_cond_wait(__cond,ppVar5);
            } while (*(int *)(iVar10 + 0x129e0) == 0);
          }
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_00012a4c + 0x129d8));
        }
      }
    }
  }
  iVar10 = DAT_00012a00;
  ppVar5 = (pthread_mutex_t *)(DAT_000129fc + 0x12726);
  pthread_mutex_lock(ppVar5);
  iVar6 = *(int *)(iVar10 + 0x12796);
  pthread_mutex_unlock(ppVar5);
  if ((iVar6 != 0) && (pcVar3 = *(code **)(iVar10 + 0x127b2), pcVar3 != (code *)0x0)) {
    (*pcVar3)(iVar6);
  }
  if ((local_3c != 0) && (*(code **)(DAT_00012a04 + 0x127da) != (code *)0x0)) {
    (**(code **)(DAT_00012a04 + 0x127da))();
  }
  if ((iVar6 != 0) && (*(code **)(DAT_00012a08 + 0x127dc) != (code *)0x0)) {
    (**(code **)(DAT_00012a08 + 0x127dc))(iVar6,3);
  }
  iVar10 = DAT_00012a0c;
  close_fd(&local_40);
  pthread_mutex_lock((pthread_mutex_t *)(iVar10 + 0x12772));
  close_fd(iVar10 + 0x12792);
  iVar10 = DAT_00012a10;
  if ((*(int *)(DAT_00012a10 + 0x127ba) == 0) && (*(int *)(DAT_00012a10 + 0x127f2) == iVar6)) {
    iVar6 = *(int *)(DAT_00012a10 + 0x127aa);
    *(undefined4 *)(DAT_00012a10 + 0x127b2) = 0;
    *(undefined4 *)(iVar10 + 0x12816) = 1;
    *(undefined4 *)(iVar10 + 0x1281a) = 4;
    *(undefined4 *)(iVar10 + 0x1281e) = 1;
    if ((iVar6 != 0) && ((*(int *)(iVar10 + 0x127ae) != 0 && (*(char *)(iVar10 + 0x12822) != '\0')))
       ) {
      ctl_write_state(iVar10 + 0x12822,DAT_00012a40 + 0x12972);
    }
  }
  ppVar5 = (pthread_mutex_t *)(DAT_00012a14 + 0x1279a);
  *(undefined4 *)(DAT_00012a18 + 0x12898) = 0;
  pthread_mutex_unlock(ppVar5);
  if (local_2c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



/* Address 00012a54 | cleanup_alt | bytes 366 */

void cleanup_alt(void)

{
  int iVar1;
  int iVar2;
  pthread_mutex_t *ppVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  pthread_t __th;
  
  iVar1 = DAT_00012bc4;
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00012bc4 + 0x12a5c));
  pthread_mutex_lock((pthread_mutex_t *)(iVar1 + 0x12a64));
  iVar1 = DAT_00012bc8;
  iVar4 = *(int *)(DAT_00012bc8 + 0x12aa8);
  *(undefined4 *)(DAT_00012bc8 + 0x12aac) = 1;
  if (iVar4 == 0) {
    *(undefined4 *)(iVar1 + 0x12b08) = 0;
    *(undefined4 *)(iVar1 + 0x12b78) = 0;
    *(undefined4 *)(iVar1 + 0x12b7c) = 0;
    *(undefined4 *)(iVar1 + 0x12b80) = 0;
    *(undefined4 *)(iVar1 + 0x12ab0) = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x12b08) = 0;
    *(undefined4 *)(iVar1 + 0x12b0c) = 3;
    *(undefined4 *)(iVar1 + 0x12b78) = 0;
    *(undefined4 *)(iVar1 + 0x12b7c) = 0;
    *(undefined4 *)(iVar1 + 0x12b80) = 0;
    *(undefined4 *)(iVar1 + 0x12ab0) = 0;
    if (iVar4 == *(int *)(iVar1 + 0x12b84)) {
      *(undefined4 *)(iVar1 + 0x12b84) = 0;
    }
  }
  iVar4 = DAT_00012bd0;
  iVar1 = DAT_00012bcc;
  iVar5 = *(int *)(DAT_00012bcc + 0x12af8);
  iVar2 = *(int *)(DAT_00012bcc + 0x12b1c);
  *(undefined4 *)(DAT_00012bcc + 0x12ae0) = 0;
  *(undefined4 *)(iVar1 + 0x12ad8) = 0;
  *(undefined1 *)(iVar1 + 0x12b4c) = 0;
  *(uint *)(iVar4 + 0x12aba) = (uint)(iVar5 != 0);
  *(undefined4 *)(iVar1 + 0x12adc) = 0;
  iVar4 = DAT_00012bd4;
  if ((iVar2 != 0) &&
     ((iVar5 = *(int *)(iVar1 + 0x12bac), iVar5 != 0 || (*(int *)(iVar1 + 0x12b48) != 0)))) {
    pcVar6 = *(code **)((int)&DAT_00012be4 + DAT_00012bd4 + 2);
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)();
      iVar2 = *(int *)(iVar4 + 0x12b42);
      if (iVar2 == 0) goto LAB_00012af2;
      iVar5 = *(int *)((int)&DAT_00012bd0 + iVar4 + 2);
    }
    if (((iVar5 != 0) || (*(int *)(DAT_00012bfc + 0x12c3c) != 0)) &&
       (*(code **)(append_alt_view_area_constprop_3 + DAT_00012bd8 + 2) != (code *)0x0)) {
      (**(code **)(append_alt_view_area_constprop_3 + DAT_00012bd8 + 2))(iVar2,0x71,0,0);
    }
  }
LAB_00012af2:
  iVar1 = DAT_00012bdc;
  close_fd(DAT_00012bdc + 0x12b1c);
  iVar4 = *(int *)(iVar1 + 0x12b20);
  if (-1 < iVar4) {
    shutdown(iVar4,2);
    close_fd(iVar1 + 0x12b20);
  }
  iVar1 = DAT_00012be0;
  pthread_cond_broadcast((pthread_cond_t *)(DAT_00012be0 + 0x12b44));
  iVar4 = DAT_00012be8;
  if ((*(int *)(DAT_00012be4 + 0x12c28) == 0) && (*(int *)((int)&DAT_00012bc4 + DAT_00012be4) == 0))
  {
    pthread_mutex_unlock((pthread_mutex_t *)(iVar1 + 0x12b20));
  }
  else {
    __th = *(pthread_t *)(DAT_00012be8 + 0x12c5a);
    ppVar3 = (pthread_mutex_t *)(DAT_00012bec + 0x12b44);
    *(undefined4 *)(DAT_00012be8 + 0x12c3e) = 0;
    *(undefined4 *)((int)&DAT_00012bd8 + iVar4 + 2) = 0;
    pthread_mutex_unlock(ppVar3);
    pthread_join(__th,(void **)0x0);
  }
  iVar1 = DAT_00012bf4;
  ppVar3 = (pthread_mutex_t *)(DAT_00012bf0 + 0x12b64);
  pthread_mutex_lock(ppVar3);
  iVar4 = *(int *)((int)&DAT_00012bd4 + iVar1);
  *(undefined4 *)((int)&DAT_00012bd4 + iVar1) = 0;
  *(undefined4 *)(iVar1 + 0x12b9c) = 0;
  *(undefined4 *)((int)&DAT_00012bfc + iVar1) = 0;
  pthread_mutex_unlock(ppVar3);
  if ((iVar4 != 0) && (*(code **)(iVar1 + 0x12b68) != (code *)0x0)) {
    (**(code **)(iVar1 + 0x12b68))(iVar4);
  }
  (*(code *)PTR_pthread_mutex_unlock_00019050)(DAT_00012bf8 + 0x12b86);
  return;
}



/* Address 00012c00 | append_alt_view_area.constprop.3 | bytes 168 */

void append_alt_view_area_constprop_3(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_24;
  int local_20;
  int local_1c;
  
  piVar2 = *(int **)(DAT_00012ca8 + 0x12c12 + DAT_00012cac);
  local_24 = 0;
  local_1c = *piVar2;
  local_20 = 0;
  iVar1 = create_alt_surface_dict(param_2,0x9a,0x26c,0x1be,&local_24);
  if ((iVar1 == 0) && (local_24 != 0)) {
    iVar1 = create_alt_surface_dict(0,0,0x780,600,&local_20);
    if (iVar1 != 0) goto LAB_00012c98;
    if (local_20 == 0) {
      uVar3 = 0xffffffff;
      goto LAB_00012c7c;
    }
    iVar1 = dict_set_object(local_20,DAT_00012cb0 + 0x12c5c,local_24);
    if ((iVar1 != 0) ||
       (iVar1 = (**(code **)(ctl_read_idle_handoff_constprop_8 + DAT_00012cb4 + 2))
                          (param_1,local_20), iVar1 != 0)) goto LAB_00012c98;
    uVar3 = 0;
  }
  else {
LAB_00012c98:
    uVar3 = 0xffffffff;
  }
  if (local_20 != 0) {
    (**(code **)(DAT_00012cb8 + 0x12c8e))();
  }
LAB_00012c7c:
  if (local_24 != 0) {
    (**(code **)(DAT_00012cbc + 0x12c9a))();
  }
  if (local_1c != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Address 00012cc0 | ctl_read_idle_handoff.constprop.8 | bytes 278 */

void ctl_read_idle_handoff_constprop_8(char *param_1,void *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  ssize_t sVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  size_t __n;
  char *pcVar8;
  int *piVar9;
  uint uVar10;
  char acStack_c4 [160];
  int local_24;
  
  piVar9 = *(int **)(DAT_00012dd8 + 77000 + DAT_00012ddc);
  local_24 = *piVar9;
  iVar3 = open(param_1,0);
  if (-1 < iVar3) {
    sVar4 = read(iVar3,acStack_c4,0x9f);
    close(iVar3);
    if (0 < sVar4) {
      acStack_c4[sVar4] = '\0';
      pcVar5 = strstr(acStack_c4,(char *)(DAT_00012de0 + 0x12cfe));
      pcVar6 = strstr(acStack_c4,(char *)(DAT_00012de4 + 0x12d0c));
      if (pcVar5 != (char *)0x0 && pcVar6 != (char *)0x0) {
        __n = 0;
        cVar1 = pcVar5[8];
        if (cVar1 == '\0' || cVar1 == '\r') {
          __n = 0;
          uVar10 = 0xffffffff;
        }
        else if (cVar1 == '\n') {
          uVar10 = 0xffffffff;
        }
        else {
          pcVar2 = pcVar5 + 9;
          do {
            pcVar8 = pcVar2;
            cVar1 = *pcVar8;
            if (cVar1 == '\r' || cVar1 == '\0') break;
            pcVar2 = pcVar8 + 1;
          } while (cVar1 != '\n');
          __n = (int)pcVar8 - (int)(pcVar5 + 8);
          uVar10 = __n - 1;
        }
        cVar1 = pcVar6[6];
        if ((cVar1 != '\0' && cVar1 != '\r') && (cVar1 != '\n')) {
          pcVar2 = pcVar6 + 7;
          do {
            pcVar8 = pcVar2;
            cVar1 = *pcVar8;
            if (cVar1 == '\r' || cVar1 == '\0') break;
            pcVar2 = pcVar8 + 1;
          } while (cVar1 != '\n');
          if (((uVar10 < 0x5f) && ((int)pcVar8 - (int)(pcVar6 + 6) == 4)) &&
             (iVar3 = strncmp(pcVar6 + 6,(char *)(DAT_00012de8 + 0x12d9a),4), iVar3 == 0)) {
            memcpy(param_2,pcVar5 + 8,__n);
            uVar7 = 1;
            *(undefined1 *)((int)param_2 + __n) = 0;
            goto LAB_00012da2;
          }
        }
      }
    }
  }
  uVar7 = 0;
LAB_00012da2:
  if (local_24 != *piVar9) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



/* Address 00012dec | ctl_start | bytes 252 */

void ctl_start(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined1 auStack_7c [96];
  int local_1c;
  
  piVar6 = *(int **)(DAT_00012ee8 + 0x12df4 + DAT_00012eec);
  local_1c = *piVar6;
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00012ef0 + 0x12e54));
  if ((*(int *)(DAT_00012ef4 + 0x12e3a) != 0) &&
     (*(int *)((int)&DAT_00012f30 + DAT_00012ef4 + 2) == 0)) {
    iVar3 = ctl_read_idle_handoff_constprop_8(DAT_00012efc + 0x12e36,auStack_7c);
    if (iVar3 == 0) {
      iVar3 = ctl_read_idle_handoff_constprop_8(DAT_00012f24 + 0x12eb8,auStack_7c);
    }
    iVar1 = DAT_00012f04;
    unlink((char *)(DAT_00012f00 + 0x12e46));
    unlink((char *)(DAT_00012f08 + 0x12e50));
    iVar4 = open((char *)(iVar1 + 0x12e4e),0x101,0x1b6);
    iVar2 = DAT_00012f0c;
    if (-1 < iVar4) {
      close(iVar4);
      iVar4 = DAT_00012f10;
      unlink((char *)(iVar2 + 0x12e72));
      iVar5 = pthread_create((pthread_t *)(iVar4 + 0x12f9c),(pthread_attr_t *)0x0,
                             (__start_routine *)(DAT_00012f14 + 0x12e86),(void *)0x0);
      if (iVar5 == 0) {
        *(undefined4 *)(iVar4 + 0x12f98) = 1;
        if (iVar3 == 0) {
          ctl_write_state(DAT_00012f28 + 0x12ec6,DAT_00012f2c + 0x12ec8);
        }
        else {
          ctl_write_state(auStack_7c,DAT_00012f18 + 0x12e9a);
          unlink((char *)(DAT_00012f1c + 0x12ea2));
        }
        pthread_mutex_unlock((pthread_mutex_t *)((int)&DAT_00012efc + DAT_00012f20 + 2));
      }
      else {
        unlink((char *)(iVar1 + 0x12e4e));
        unlink((char *)(iVar2 + 0x12e72));
        pthread_mutex_unlock((pthread_mutex_t *)((int)&DAT_00012f30 + DAT_00012f30 + 2));
      }
      goto LAB_00012e20;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_00012ef8 + 0x12e70));
LAB_00012e20:
  if (local_1c != *piVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 00012f34 | lazy_init | bytes 768 */

void lazy_init(void)

{
  int iVar1;
  int *piVar2;
  pthread_mutex_t *__mutex;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  pthread_mutex_t *extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 in_r3;
  int iVar7;
  pthread_mutex_t *__mutex_00;
  undefined4 *puVar8;
  
  iVar6 = DAT_00013234;
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00013234 + 0x12f98));
  iVar1 = DAT_0001323c;
  iVar7 = *(int *)(DAT_00013238 + 0x13074);
  if (iVar7 == 1) {
    piVar2 = (int *)__emutls_get_address(iVar6 + 0x12fa0);
    iVar6 = DAT_00013240;
    __mutex_00 = (pthread_mutex_t *)(iVar1 + 0x12fba);
    uVar4 = extraout_r2;
    do {
      if (*piVar2 != 0) {
        __mutex = (pthread_mutex_t *)(DAT_00013244 + 0x12fe0);
        goto LAB_00011848;
      }
      pthread_cond_wait((pthread_cond_t *)(iVar1 + 0x12fd2),__mutex_00);
      iVar7 = *(int *)(iVar6 + 0x13090);
      uVar4 = extraout_r2_00;
    } while (iVar7 == 1);
  }
  iVar1 = DAT_0001324c;
  iVar6 = DAT_00013248;
  if (iVar7 == 2) {
    pthread_mutex_unlock((pthread_mutex_t *)((int)&DAT_00013284 + DAT_00013320));
    ctl_start();
    return;
  }
  iVar7 = DAT_0001324c + 0x13002;
  *(undefined4 *)(DAT_00013248 + 0x130c8) = 1;
  puVar3 = (undefined4 *)__emutls_get_address(iVar7);
  *puVar3 = 1;
  pthread_mutex_unlock((pthread_mutex_t *)(iVar1 + 0x12ffa));
  uVar4 = must_sym(DAT_00013250 + 0x12fba);
  *(undefined4 *)(iVar6 + 0x130cc) = uVar4;
  uVar4 = must_sym(DAT_00013254 + 0x12fc6);
  *(undefined4 *)(iVar6 + 0x130d0) = uVar4;
  uVar4 = must_sym(DAT_00013258 + 0x12fd2);
  *(undefined4 *)(iVar6 + 0x130d4) = uVar4;
  uVar4 = must_sym(DAT_0001325c + 0x12fde);
  *(undefined4 *)(iVar6 + 0x130d8) = uVar4;
  uVar4 = must_sym(DAT_00013260 + 0x12fea);
  *(undefined4 *)(iVar6 + 0x130dc) = uVar4;
  iVar5 = must_sym(DAT_00013264 + 0x12ff6);
  *(int *)(iVar6 + 0x130e0) = iVar5;
  iVar7 = DAT_00013270;
  iVar1 = DAT_00013268;
  uVar4 = 0;
  if ((*(int *)(iVar6 + 0x130dc) != 0) && (uVar4 = 0, iVar5 != 0)) {
    uVar4 = 1;
  }
  puVar8 = (undefined4 *)(DAT_00013268 + 0x13010);
  iVar6 = DAT_0001326c + 0x13014;
  *(undefined4 *)(DAT_00013268 + 0x13158) = uVar4;
  uVar4 = must_sym(iVar6);
  __mutex = (pthread_mutex_t *)(iVar7 + 0x1307a);
  *(undefined4 *)(iVar1 + 0x1315c) = uVar4;
  uVar4 = must_sym(DAT_00013274 + 0x1302a);
  *(undefined4 *)(iVar1 + 0x13018) = uVar4;
  uVar4 = must_sym(DAT_00013278 + 0x13034);
  *(undefined4 *)(iVar1 + 0x13160) = uVar4;
  uVar4 = must_sym(DAT_0001327c + 0x13040);
  *(undefined4 *)(iVar1 + 0x13164) = uVar4;
  uVar4 = must_sym(DAT_00013280 + 0x1304c);
  *(undefined4 *)(iVar1 + 0x13090) = uVar4;
  uVar4 = must_sym(DAT_00013284 + 0x13058);
  *(undefined4 *)(iVar1 + 0x13094) = uVar4;
  uVar4 = must_sym(DAT_00013288 + 0x13064);
  *(undefined4 *)(iVar1 + 0x1309c) = uVar4;
  uVar4 = must_sym(DAT_0001328c + 0x13070);
  *(undefined4 *)(iVar1 + 0x130a0) = uVar4;
  uVar4 = must_sym(DAT_00013290 + 0x1307c);
  *(undefined4 *)(iVar1 + 0x13098) = uVar4;
  uVar4 = must_sym(DAT_00013294 + 0x13088);
  *(undefined4 *)(iVar1 + 0x13128) = uVar4;
  uVar4 = must_sym(DAT_00013298 + 0x13094);
  *(undefined4 *)(iVar1 + 0x1312c) = uVar4;
  uVar4 = must_sym(DAT_0001329c + 0x130a0);
  *(undefined4 *)(iVar1 + 0x13168) = uVar4;
  uVar4 = must_sym(DAT_000132a0 + 0x130ac);
  *(undefined4 *)(iVar1 + 0x1316c) = uVar4;
  uVar4 = must_sym(DAT_000132a4 + 0x130b8);
  *(undefined4 *)(iVar1 + 0x13170) = uVar4;
  uVar4 = must_sym(DAT_000132a8 + 0x130c4);
  *(undefined4 *)(iVar1 + 0x13080) = uVar4;
  uVar4 = must_sym(DAT_000132ac + 0x130ce);
  *(undefined4 *)(iVar1 + 0x1308c) = uVar4;
  uVar4 = must_sym(DAT_000132b0 + 0x130d8);
  *(undefined4 *)(iVar1 + 0x130a4) = uVar4;
  uVar4 = must_sym(DAT_000132b4 + 0x130e4);
  *(undefined4 *)(iVar1 + 0x1307c) = uVar4;
  uVar4 = must_sym(DAT_000132b8 + 0x130ee);
  *puVar8 = uVar4;
  uVar4 = must_sym(DAT_000132bc + 0x130f8);
  *(undefined4 *)(iVar1 + 0x13014) = uVar4;
  uVar4 = must_sym(DAT_000132c0 + 0x13102);
  *(undefined4 *)(iVar1 + 0x13174) = uVar4;
  uVar4 = must_sym(DAT_000132c4 + 0x1310e);
  *(undefined4 *)(iVar1 + 0x13178) = uVar4;
  uVar4 = must_sym(DAT_000132c8 + 0x1311a);
  *(undefined4 *)(iVar1 + 0x1317c) = uVar4;
  uVar4 = must_sym(DAT_000132cc + 0x13126);
  *(undefined4 *)(iVar1 + 0x13054) = uVar4;
  uVar4 = must_sym(DAT_000132d0 + 0x13130);
  *(undefined4 *)(iVar1 + 0x13180) = uVar4;
  uVar4 = must_sym(DAT_000132d4 + 0x1313c);
  *(undefined4 *)(iVar1 + 0x13020) = uVar4;
  uVar4 = must_sym(DAT_000132d8 + 0x13146);
  *(undefined4 *)(iVar1 + 0x13078) = uVar4;
  uVar4 = must_sym(DAT_000132dc + 0x13150);
  *(undefined4 *)(iVar1 + 0x13058) = uVar4;
  uVar4 = must_sym(DAT_000132e0 + 0x1315a);
  *(undefined4 *)(iVar1 + 0x1306c) = uVar4;
  uVar4 = must_sym(DAT_000132e4 + 0x13164);
  *(undefined4 *)(iVar1 + 0x13070) = uVar4;
  uVar4 = must_sym(DAT_000132e8 + 0x1316e);
  *(undefined4 *)(iVar1 + 0x13068) = uVar4;
  uVar4 = must_sym(DAT_000132ec + 0x13178);
  *(undefined4 *)(iVar1 + 0x13030) = uVar4;
  uVar4 = must_sym(DAT_000132f0 + 0x13182);
  *(undefined4 *)(iVar1 + 0x13064) = uVar4;
  uVar4 = must_sym(DAT_000132f4 + 0x1318c);
  *(undefined4 *)(iVar1 + 0x13184) = uVar4;
  uVar4 = must_sym(DAT_000132f8 + 0x13198);
  *(undefined4 *)(iVar1 + 0x13028) = uVar4;
  uVar4 = must_sym(DAT_000132fc + 0x131a2);
  *(undefined4 *)(iVar1 + 0x13188) = uVar4;
  uVar4 = must_sym(DAT_00013300 + 0x131ae);
  *(undefined4 *)(iVar1 + 0x1318c) = uVar4;
  uVar4 = must_sym(DAT_00013304 + 0x131ba);
  *(undefined4 *)(iVar1 + 0x13074) = uVar4;
  uVar4 = must_sym(DAT_00013308 + 0x131c4);
  *(undefined4 *)(iVar1 + 0x13190) = uVar4;
  uVar4 = must_sym(DAT_0001330c + 0x131d0);
  *(undefined4 *)(iVar1 + 0x1302c) = uVar4;
  uVar4 = must_sym(DAT_00013310 + 0x131da);
  *(undefined4 *)(iVar1 + 0x13024) = uVar4;
  uVar4 = must_sym(DAT_00013314 + 0x131e4);
  *(undefined4 *)(iVar1 + 0x1305c) = uVar4;
  uVar4 = must_sym(DAT_00013318 + 0x131ee);
  *(undefined4 *)(iVar1 + 0x13034) = uVar4;
  uVar4 = must_sym(DAT_0001331c + 0x131f8);
  *(undefined4 *)(iVar1 + 0x13038) = uVar4;
  ctl_start();
  pthread_mutex_lock(__mutex);
  *puVar3 = 0;
  *(undefined4 *)(iVar1 + 0x1313c) = 2;
  pthread_cond_broadcast((pthread_cond_t *)(iVar7 + 0x13092));
  __mutex_00 = extraout_r1;
  uVar4 = extraout_r2_01;
LAB_00011848:
  (*(code *)PTR_pthread_mutex_unlock_00019050)(__mutex,__mutex_00,uVar4,in_r3);
  return;
}



/* Address 00013324 | ctl_token.constprop.10 | bytes 198 */

undefined4 ctl_token_constprop_10(byte *param_1,char *param_2,void *param_3)

{
  byte bVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  size_t __n_00;
  
  __n = strlen(param_2);
  bVar1 = *param_1;
  while( true ) {
    if (bVar1 == 0) {
      return 0;
    }
    if (bVar1 == 0x20 || bVar1 == 9) {
      do {
        param_1 = param_1 + 1;
        bVar1 = *param_1;
      } while (bVar1 == 0x20 || bVar1 == 9);
      if (bVar1 == 0) {
        return 0;
      }
    }
    iVar2 = strncmp((char *)param_1,param_2,__n);
    if ((iVar2 == 0) && (param_1[__n] == 0x3d)) break;
    bVar1 = *param_1;
    while (((bVar1 & 0xdf) != 0 && (bVar1 != 9))) {
      param_1 = param_1 + 1;
      bVar1 = *param_1;
    }
  }
  bVar1 = param_1[__n + 1];
  if ((bVar1 & 0xdf) == 0) {
    return 0;
  }
  if (bVar1 == 9) {
    return 0;
  }
  if (bVar1 == 0xd) {
    return 0;
  }
  if (bVar1 == 10) {
    return 0;
  }
  uVar3 = 0;
  pbVar4 = param_1 + __n + 1;
  while( true ) {
    pbVar4 = pbVar4 + 1;
    bVar1 = *pbVar4;
    __n_00 = uVar3 + 1;
    if (((((bVar1 & 0xdf) == 0) || (bVar1 == 9)) || (bVar1 == 0xd)) || (bVar1 == 10)) break;
    uVar3 = __n_00;
  }
  if (uVar3 < 0x5f) {
    memcpy(param_3,param_1 + __n + 1,__n_00);
    *(undefined1 *)((int)param_3 + __n_00) = 0;
    return 1;
  }
  return 0;
}



/* Address 000133ec | ctl_thread_main | bytes 1762 */

void ctl_thread_main(void)

{
  bool bVar1;
  bool bVar2;
  pthread_mutex_t *__mutex;
  pthread_mutex_t *__mutex_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *__format;
  pthread_mutex_t *__mutex_01;
  uint uVar8;
  pthread_mutex_t *__mutex_02;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  pthread_mutex_t *__mutex_03;
  pthread_mutex_t *ppVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int local_724;
  int local_6fc;
  int local_6f8;
  timespec local_6f4;
  char acStack_6ec [96];
  char acStack_68c [96];
  char acStack_62c [96];
  char local_5cc [96];
  char local_56c [96];
  char local_50c [96];
  char local_4ac [96];
  char acStack_44c [96];
  char acStack_3ec [96];
  char acStack_38c [96];
  char acStack_32c [256];
  undefined1 auStack_22c [512];
  undefined4 local_2c;
  
  bVar2 = false;
  __mutex_01 = (pthread_mutex_t *)(DAT_00013ad8 + 0x1340e);
  __mutex = (pthread_mutex_t *)(DAT_00013adc + 0x1341c);
  __mutex_02 = (pthread_mutex_t *)(DAT_00013ad8 + 0x13416);
  local_2c = **(undefined4 **)(DAT_00013ad0 + 0x133fe + DAT_00013ad4);
  local_724 = 0;
  __mutex_00 = (pthread_mutex_t *)(DAT_00013ae0 + 0x1342c);
  local_5cc[0] = '\0';
  local_56c[0] = '\0';
  local_50c[0] = '\0';
  local_4ac[0] = '\0';
LAB_0001343e:
  do {
    do {
      local_6f4.tv_sec = 0;
      local_6f4.tv_nsec = 100000000;
      nanosleep(&local_6f4,(timespec *)0x0);
      iVar3 = ctl_read_path_command(DAT_00013ae4 + 0x13464,acStack_32c,0x100);
      if ((((iVar3 != 0) &&
           (iVar3 = ctl_token_constprop_10(acStack_32c,DAT_00013b18 + 0x135a6,acStack_44c),
           iVar3 != 0)) &&
          (iVar3 = strcmp(acStack_44c,(char *)(DAT_00013b1c + 0x135b8)), iVar3 == 0)) &&
         (((iVar3 = ctl_token_constprop_10(acStack_32c,DAT_00013b20 + 0x135d0,acStack_3ec),
           iVar3 != 0 && (iVar3 = strcmp(acStack_3ec,local_50c), iVar3 != 0)) &&
          ((iVar3 = ctl_token_constprop_10(acStack_32c,DAT_00013b24 + 0x135f4,acStack_38c),
           iVar3 != 0 && (uVar7 = strtol(acStack_38c,(char **)0x0,10), uVar7 < 2)))))) {
        iVar3 = ctl_token_constprop_10(acStack_32c,DAT_00013b28 + 0x1361c,acStack_38c);
        if ((iVar3 == 0) || (uVar8 = strtol(acStack_38c,(char **)0x0,10), (int)uVar8 < 1)) {
          uVar8 = 1;
        }
        else if (7 < (int)uVar8) {
          uVar8 = 8;
        }
        iVar3 = DAT_00013b30;
        snprintf(local_50c,0x60,(char *)(DAT_00013b2c + 0x13636),acStack_3ec);
        pthread_mutex_lock(__mutex_01);
        pthread_mutex_lock(__mutex_02);
        if ((((*(int *)(iVar3 + 0x1366a) == 0) || (*(int *)(iVar3 + 0x1366e) == 0)) ||
            (*(int *)(iVar3 + 0x13672) == 0)) || (iVar15 = *(int *)(iVar3 + 0x13676), iVar15 == 0))
        {
          pthread_mutex_unlock(__mutex);
        }
        else {
          pthread_mutex_unlock(__mutex_02);
          if ((*(int *)(iVar3 + 0x13682) != 0) && (*(char *)(iVar15 + 0x3c6) != '\0')) {
            uVar14 = 0;
            iVar4 = DAT_00013b34 + 0x13694;
            iVar16 = DAT_00013b38 + 0x1369c;
            iVar10 = DAT_00013b3c + 0x136a0;
            iVar11 = DAT_00013b40 + 0x136a8;
            iVar12 = DAT_00013b44 + 0x136b0;
            while( true ) {
              local_6fc = 0;
              local_6f8 = 0;
              iVar6 = (**(code **)(iVar3 + 0x1365e))
                                (0,2,*(undefined4 *)(iVar3 + 0x13662),
                                 *(undefined4 *)(iVar3 + 0x13666),&local_6fc);
              if ((iVar6 != 0) || (local_6fc == 0)) goto LAB_0001377e;
              iVar6 = dict_set_text(local_6fc,iVar16,iVar4);
              if ((iVar6 != 0) ||
                 (iVar6 = (**(code **)(iVar3 + 0x1365e))
                                    (0,2,*(undefined4 *)(iVar3 + 0x13662),
                                     *(undefined4 *)(iVar3 + 0x13666),&local_6f8), iVar6 != 0))
              break;
              if (local_6f8 == 0) goto LAB_00013774;
              iVar6 = dict_set_text(local_6f8,iVar10,iVar11);
              if (((iVar6 != 0) || (iVar6 = dict_set_i64(local_6f8,iVar12,uVar7,0), iVar6 != 0)) ||
                 (iVar6 = dict_set_object(local_6fc,DAT_00013b48 + 0x136f6,local_6f8), iVar6 != 0))
              break;
              (**(code **)(iVar3 + 0x13652))(local_6f8);
              iVar6 = local_6fc;
              if (local_6fc == 0) goto LAB_0001377e;
              iVar5 = (**(code **)(iVar3 + 0x13682))(iVar15,local_6fc,DAT_00013b4c + 0x13722,0);
              (**(code **)(iVar3 + 0x13652))(iVar6);
              if ((iVar5 != 0) || (uVar14 = uVar14 + 1, uVar8 <= uVar14)) goto LAB_0001377e;
            }
            if (local_6f8 != 0) {
              (**(code **)(DAT_00013b50 + 0x13786))();
            }
LAB_00013774:
            (**(code **)(DAT_00013b54 + 0x13790))(local_6fc);
          }
        }
LAB_0001377e:
        pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013b58 + 0x13784));
      }
      iVar3 = ctl_read_path_command(DAT_00013ae8 + 0x1347c,acStack_32c,0x100);
      if (((iVar3 != 0) &&
          (iVar3 = ctl_token_constprop_10(acStack_32c,DAT_00013b5c + 0x137ac,acStack_44c),
          iVar3 != 0)) &&
         ((iVar3 = strcmp(acStack_44c,(char *)(DAT_00013b60 + 0x137bc)), iVar3 == 0 &&
          (((iVar3 = ctl_token_constprop_10(acStack_32c,DAT_00013b64 + 0x137d2,acStack_3ec),
            iVar3 != 0 &&
            (iVar3 = ctl_token_constprop_10(acStack_32c,DAT_00013b68 + 0x137e6,acStack_38c),
            iVar3 != 0)) && (uVar7 = strtol(acStack_38c,(char **)0x0,10), uVar7 < 2)))))) {
        pthread_mutex_lock(__mutex_00);
        iVar3 = strcmp(acStack_3ec,local_4ac);
        if ((iVar3 == 0) && (uVar7 == *(uint *)(DAT_00013b6c + 0x13866))) {
          pthread_mutex_unlock(__mutex_00);
        }
        else {
          snprintf(local_4ac,0x60,(char *)(DAT_00013b70 + 0x13828),acStack_3ec);
          ppVar13 = (pthread_mutex_t *)(DAT_00013b74 + 0x13838);
          *(uint *)(DAT_00013b74 + 0x13840) = uVar7;
          *(uint *)(DAT_00013b78 + 0x1388a) = uVar7;
          pthread_mutex_unlock(ppVar13);
        }
      }
      ctl_poll_view_area_update();
      iVar3 = ctl_read_path_command(DAT_00013aec + 79000,auStack_22c,0x200);
    } while (((iVar3 == 0) ||
             (iVar3 = ctl_token_constprop_10(auStack_22c,DAT_00013af0 + 0x134ac,acStack_6ec),
             iVar3 == 0)) ||
            ((iVar3 = strcmp(acStack_6ec,(char *)(DAT_00013af4 + 0x134bc)), iVar3 != 0 ||
             ((iVar3 = ctl_token_constprop_10(auStack_22c,DAT_00013af8 + 0x134d0,acStack_68c),
              iVar3 == 0 ||
              (iVar3 = ctl_token_constprop_10(auStack_22c,DAT_00013afc + 0x134e4,acStack_62c),
              iVar3 == 0))))));
    iVar3 = strcmp(acStack_68c,local_5cc);
    if ((iVar3 == 0) && (iVar3 = strcmp(acStack_62c,local_56c), iVar3 == 0)) {
      bVar1 = false;
    }
    else {
      pcVar9 = (char *)(DAT_00013b7c + 0x1384c);
      bVar1 = true;
      snprintf(local_5cc,0x60,pcVar9,acStack_68c);
      snprintf(local_56c,0x60,pcVar9,acStack_62c);
    }
    iVar3 = strcmp(acStack_62c,(char *)(DAT_00013b00 + 0x13512));
    if (iVar3 == 0) {
      ppVar13 = (pthread_mutex_t *)(DAT_00013b80 + 0x1386e);
      pthread_mutex_lock(ppVar13);
      iVar15 = DAT_00013bb4;
      iVar3 = DAT_00013b84;
      if (bVar1) {
        *(undefined4 *)(DAT_00013b84 + 0x13984) = 0;
        *(undefined4 *)(iVar3 + 0x13988) = 0;
        pthread_mutex_unlock(ppVar13);
LAB_00013882:
        iVar3 = ctl_token_constprop_10(auStack_22c,DAT_00013b88 + 0x13890,acStack_32c);
        if (iVar3 != 0) {
          strtol(acStack_32c,(char **)0x0,10);
        }
        iVar3 = ctl_token_constprop_10(auStack_22c,DAT_00013b8c + 0x138a4,acStack_32c);
        if (iVar3 != 0) {
          strtol(acStack_32c,(char **)0x0,10);
        }
        pthread_mutex_lock((pthread_mutex_t *)(DAT_00013b90 + 0x138ba));
        if ((bVar1) && (*(int *)(DAT_00013b94 + 0x138fe) != 0)) {
          *(undefined4 *)(DAT_00013b94 + 0x138fe) = 0;
        }
        iVar3 = DAT_00013b9c;
        pcVar9 = (char *)(DAT_00013b98 + 0x13976);
        __format = (char *)(DAT_00013ba0 + 0x138da);
        *(undefined4 *)(DAT_00013b98 + 0x13902) = 1;
        snprintf(pcVar9,0x60,__format,acStack_68c);
        bVar2 = true;
        pthread_cond_broadcast((pthread_cond_t *)(iVar3 + 0x13900));
        pthread_mutex_unlock((pthread_mutex_t *)(iVar3 + 0x138dc));
        local_724 = 0;
        ctl_write_state(acStack_68c,DAT_00013ba4 + 0x138fc);
      }
      else {
        if ((*(int *)(DAT_00013bb4 + 0x13a60) != 0) && (*(int *)(DAT_00013bb4 + 0x13a64) != 0)) {
          *(undefined4 *)(DAT_00013bb4 + 0x13a60) = 0;
          *(undefined4 *)(iVar15 + 0x13a64) = 0;
          pthread_mutex_unlock(ppVar13);
          goto LAB_00013882;
        }
        pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013bb8 + 0x1397c));
        if (!bVar2) goto LAB_0001343e;
      }
      iVar3 = DAT_00013bac;
      __mutex_03 = (pthread_mutex_t *)(DAT_00013ba8 + 0x13908);
      ppVar13 = (pthread_mutex_t *)(DAT_00013ba8 + 0x13910);
      pthread_mutex_lock(ppVar13);
      iVar15 = *(int *)(iVar3 + 0x13942);
      pthread_mutex_unlock(ppVar13);
      if (iVar15 == 0) {
        local_724 = local_724 + 1;
        if (99 < local_724) {
          pthread_mutex_lock(ppVar13);
          iVar15 = strcmp((char *)(iVar3 + 0x139b2),acStack_68c);
          if (iVar15 == 0) {
            *(undefined4 *)(iVar3 + 0x1393e) = 0;
          }
          bVar2 = false;
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013bb0 + 0x13950));
        }
      }
      else {
        if (*(int *)(iVar3 + 0x1393a) != 0) {
          pthread_mutex_lock(__mutex_03);
          pthread_mutex_lock(ppVar13);
          if (((*(int *)(iVar3 + 0x13942) == 0) || (iVar15 = *(int *)(iVar3 + 0x13946), iVar15 == 0)
              ) || (iVar4 = *(int *)(iVar3 + 0x1394e), iVar4 != 0)) {
            pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013bc4 + 0x13a0e));
          }
          else {
            *(undefined4 *)(iVar3 + 0x1394e) = 1;
            pthread_mutex_unlock(ppVar13);
            if (((*(int *)(iVar3 + 0x13952) != 0) && (*(char *)(iVar15 + 0x3c6) != '\0')) &&
               ((local_6fc = iVar4, local_6f8 = iVar4,
                iVar3 = (**(code **)(iVar3 + 0x1392e))
                                  (0,2,*(undefined4 *)(iVar3 + 0x13932),
                                   *(undefined4 *)(iVar3 + 0x13936),&local_6fc), iVar3 == 0 &&
                (local_6fc != 0)))) {
              iVar4 = dict_set_text(local_6fc,DAT_00013bc8 + 0x13a3a,DAT_00013bcc + 0x13a3c);
              iVar3 = DAT_00013bd0;
              if ((iVar4 == 0) &&
                 (iVar4 = (**(code **)(DAT_00013bd0 + 0x13a6e))
                                    (0,2,*(undefined4 *)(DAT_00013bd0 + 0x13a72),
                                     *(undefined4 *)(DAT_00013bd0 + 0x13a76),&local_6f8), iVar4 == 0
                 )) {
                if (local_6f8 != 0) {
                  iVar4 = dict_set_text(local_6f8,DAT_00013bd4 + 0x13a66,DAT_00013bd8 + 0x13a68);
                  if (((iVar4 == 0) &&
                      (iVar4 = dict_set_text(local_6f8,DAT_00013bdc + 0x13a76,DAT_00013be0 + 0x13a78
                                            ), iVar4 == 0)) &&
                     (iVar4 = dict_set_object(local_6fc,DAT_00013be4 + 0x13a84,local_6f8),
                     iVar4 == 0)) {
                    (**(code **)(iVar3 + 0x13a62))(local_6f8);
                    iVar4 = local_6fc;
                    if (local_6fc != 0) {
                      (**(code **)(iVar3 + 0x13a92))(iVar15,local_6fc,DAT_00013be8 + 0x13aa4,0);
                      (**(code **)(iVar3 + 0x13a62))(iVar4);
                    }
                    goto LAB_000139f6;
                  }
                  goto LAB_00013ab6;
                }
              }
              else {
LAB_00013ab6:
                if (local_6f8 != 0) {
                  (**(code **)((int)&DAT_00013ad4 + DAT_00013bec))();
                }
              }
              (**(code **)((int)&DAT_00013adc + DAT_00013bf0 + 2))(local_6fc);
            }
          }
LAB_000139f6:
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013bc0 + 0x139fc));
        }
        local_6f4.tv_sec = 0;
        local_6f4.tv_nsec = 250000000;
        nanosleep(&local_6f4,(timespec *)0x0);
        ctl_poll_view_area_update();
        bVar2 = false;
        ctl_write_state(acStack_68c,DAT_00013bbc + 0x139b8);
      }
      goto LAB_0001343e;
    }
    pcVar9 = (char *)(DAT_00013b04 + 0x13526);
    iVar4 = strcmp(acStack_62c,pcVar9);
    iVar15 = DAT_00013b0c;
    iVar3 = DAT_00013b08;
    if (iVar4 == 0) {
      ppVar13 = (pthread_mutex_t *)(DAT_00013b08 + 0x13544);
      pthread_mutex_lock(ppVar13);
      *(undefined4 *)(iVar15 + 0x1364e) = 0;
      *(undefined4 *)(iVar15 + 0x13652) = 0;
      pthread_mutex_unlock(ppVar13);
      if (bVar1) {
        pthread_mutex_lock(ppVar13);
        *(undefined4 *)(iVar15 + 0x13572) = 0;
        *(undefined1 *)(iVar15 + 0x135e6) = 0;
        pthread_cond_broadcast((pthread_cond_t *)(iVar3 + 0x13568));
        pthread_mutex_unlock(ppVar13);
        ctl_write_state(acStack_68c,pcVar9);
        ctl_write_state(acStack_68c,DAT_00013b10 + 0x1358a);
        unlink((char *)(DAT_00013b14 + 0x13594));
        bVar2 = false;
      }
    }
  } while( true );
}



/* Address 00013bf4 | pthread_setname_np | bytes 122 */

int pthread_setname_np(pthread_t __target_thread,char *__name)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  code *pcVar6;
  pthread_mutex_t *__mutex;
  
  iVar1 = DAT_00013c70;
  pcVar6 = *(code **)(DAT_00013c70 + 0x13d44);
  if (pcVar6 == (code *)0x0) {
    pcVar6 = (code *)must_sym(DAT_00013c7c + 0x13c2e);
    *(code **)(iVar1 + 0x13d44) = pcVar6;
    if (pcVar6 == (code *)0x0) {
      return 0x59;
    }
  }
  iVar3 = (*pcVar6)(__target_thread,__name);
  iVar1 = DAT_00013c74;
  if ((((iVar3 == 0) && (*(int *)(DAT_00013c74 + 0x13c40) != 0)) && (__name != (char *)0x0)) &&
     (iVar4 = strcmp(__name,(char *)(DAT_00013c78 + 0x13c20)), iVar2 = DAT_00013c80, iVar4 == 0)) {
    __mutex = (pthread_mutex_t *)(DAT_00013c80 + 0x13c4c);
    puVar5 = (undefined4 *)__emutls_get_address(DAT_00013c80 + 0x13cc0);
    *puVar5 = 1;
    pthread_mutex_lock(__mutex);
    puVar5 = (undefined4 *)__emutls_get_address(iVar2 + 0x13cd0);
    *puVar5 = *(undefined4 *)(iVar1 + 0x13d98);
    pthread_mutex_unlock(__mutex);
  }
  return iVar3;
}



/* Address 00013c84 | select | bytes 382 */

int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  code *pcVar6;
  int iVar7;
  __fd_mask local_4c;
  __fd_mask _Stack_48;
  __fd_mask _Stack_44;
  __fd_mask _Stack_40;
  __fd_mask local_3c;
  __fd_mask _Stack_38;
  __fd_mask _Stack_34;
  __fd_mask _Stack_30;
  int local_2c;
  
  iVar1 = DAT_00013e0c;
  piVar5 = *(int **)(DAT_00013e04 + 0x13c96 + DAT_00013e08);
  pcVar6 = *(code **)(DAT_00013e0c + 0x13de0);
  local_2c = *piVar5;
  if (pcVar6 == (code *)0x0) {
    pcVar6 = (code *)must_sym(DAT_00013e20 + 0x13d8a);
    *(code **)(iVar1 + 0x13de0) = pcVar6;
    if (pcVar6 == (code *)0x0) {
      puVar4 = (undefined4 *)__get_errno_ptr();
      iVar1 = -1;
      *puVar4 = 0x59;
      goto LAB_00013cc4;
    }
  }
  iVar3 = DAT_00013e14;
  iVar1 = DAT_00013e10;
  if (((*(int *)(DAT_00013e10 + 0x13ce0) != 0) &&
      (piVar2 = (int *)__emutls_get_address(DAT_00013e14 + 0x13d5a), *piVar2 != 0)) &&
     (*(int *)(iVar1 + 0x13dfc) != 0)) {
    piVar2 = (int *)__emutls_get_address(iVar3 + 0x13d6a);
    if (((*piVar2 != 0) && (__timeout != (timeval *)0x0 && __readfds != (fd_set *)0x0)) &&
       ((__timeout->tv_sec == 0x1e &&
        ((__timeout->tv_usec == 0 &&
         (iVar1 = idle_read_set_matches_session(*piVar2,__nfds,__readfds), iVar1 != 0)))))) {
      local_4c = __readfds->fds_bits[0];
      _Stack_48 = __readfds->fds_bits[1];
      _Stack_44 = __readfds->fds_bits[2];
      _Stack_40 = __readfds->fds_bits[3];
      local_3c = __readfds->fds_bits[4];
      _Stack_38 = __readfds->fds_bits[5];
      _Stack_34 = __readfds->fds_bits[6];
      _Stack_30 = __readfds->fds_bits[7];
      iVar1 = (*pcVar6)(__nfds,__readfds,__writefds,__exceptfds,__timeout);
      if (iVar1 == 0) {
        iVar7 = *piVar2;
        pthread_mutex_lock((pthread_mutex_t *)(iVar3 + 0x13ce6));
        if (((((((iVar7 == 0) || (iVar7 != *(int *)(DAT_00013e18 + 0x13dac))) ||
               (*(int *)(DAT_00013e18 + 0x13da0) == 0)) ||
              ((*(char *)(iVar7 + 0x16d4) != '\0' || (iVar7 != *(int *)(DAT_00013e18 + 0x13efc)))))
             || ((*(int *)(DAT_00013e18 + 0x13de8) == 0 ||
                 ((*(int *)((int)&DAT_00013e10 + DAT_00013e18) != 2 ||
                  (*(int *)(DAT_00013e18 + 0x13db0) != 0)))))) ||
            (*(int *)((int)&DAT_00013e0c + DAT_00013e18) != 0)) ||
           (iVar3 = idle_read_set_matches_session(iVar7,__nfds,&local_4c), iVar3 == 0)) {
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013e1c + 0x13d86));
        }
        else {
          iVar1 = -1;
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_00013e24 + 0x13df8));
          puVar4 = (undefined4 *)__get_errno_ptr();
          *puVar4 = 4;
        }
      }
      goto LAB_00013cc4;
    }
  }
  iVar1 = (*pcVar6)(__nfds,__readfds,__writefds,__exceptfds,__timeout);
LAB_00013cc4:
  if (local_2c != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



/* Address 00013e28 | AirPlayCopyServerInfo | bytes 84 */

int AirPlayCopyServerInfo
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = DAT_00013e7c;
  lazy_init();
  pcVar3 = *(code **)(iVar1 + 0x13faa);
  if (pcVar3 == (code *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*pcVar3)(param_1,param_2,param_3,pcVar3,param_4);
    if (((iVar2 != 0) && (*(int *)(iVar1 + 0x13e66) != 0)) && (*(int *)(iVar1 + 0x13f82) != 0)) {
      set_info_url_array(iVar2,DAT_00013e80 + 0x13e5e);
      set_info_url_array(iVar2,DAT_00013e84 + 0x13e68);
      set_info_url_array(iVar2,DAT_00013e88 + 0x13e72);
      return iVar2;
    }
  }
  return iVar2;
}



/* Address 00013e8c | AirPlayReceiverServerPlatformCopyProperty | bytes 632 */

void AirPlayReceiverServerPlatformCopyProperty
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  piVar5 = *(int **)(DAT_00014104 + 0x13e9e + DAT_00014108);
  local_24 = *piVar5;
  lazy_init();
  iVar2 = 0;
  if (*(code **)(DAT_0001410c + 0x13fe2) != (code *)0x0) {
    iVar2 = (**(code **)(DAT_0001410c + 0x13fe2))(param_1,param_2,param_3,param_4,param_5);
  }
  iVar4 = DAT_00014110;
  if ((((*(int *)(DAT_00014110 + 0x13ef6) == 0) || (*(int *)(DAT_00014110 + 0x14012) == 0)) ||
      (param_3 == 0)) || (iVar3 = string_equals(param_3,DAT_00014114 + 0x13edc), iVar3 == 0))
  goto LAB_00013ee0;
  local_34 = 0;
  local_30 = 0;
  if ((((iVar2 == 0) || (*(code **)(iVar4 + 0x13f26) == (code *)0x0)) ||
      ((iVar3 = (**(code **)(iVar4 + 0x13f26))(iVar2,&local_30), iVar3 != 0 ||
       ((local_30 != 1 ||
        (iVar3 = (**(code **)(iVar4 + 0x13f12))(0,*(undefined4 *)(iVar4 + 0x13f16),&local_34),
        iVar4 = DAT_00014118, iVar3 != 0)))))) || (local_34 == 0)) goto LAB_00013ee0;
  if (local_30 != 0) {
    uVar6 = 0;
    do {
      local_28 = 0;
      iVar3 = (**(code **)(iVar4 + 0x13f90))(iVar2,uVar6,&local_28);
      if (((iVar3 != 0) || (local_28 == 0)) ||
         (iVar3 = (**(code **)(iVar4 + 0x13f88))(local_34), iVar3 != 0)) {
        (**(code **)(DAT_0001411c + 0x13f74))(local_34);
        goto LAB_00013ee0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_30);
  }
  local_2c = 0;
  if (*(code **)(DAT_00014120 + 0x13f8e) != (code *)0x0) {
    iVar4 = (**(code **)(DAT_00014120 + 0x13f8e))
                      (0,9,*(undefined4 *)(DAT_00014120 + 0x13f92),
                       *(undefined4 *)(DAT_00014120 + 0x13f96),&local_2c);
    if ((iVar4 == 0) && (local_2c != 0)) {
      iVar4 = dict_set_text(local_2c,DAT_00014124 + 0x13f96,DAT_00014128 + 0x13f98);
      if ((((iVar4 == 0) &&
           ((iVar4 = dict_set_i64(local_2c,DAT_0001412c + 0x13fac,0x6f,0), iVar4 == 0 &&
            (iVar4 = dict_set_i64(local_2c,DAT_00014130 + 0x13fc2,0x780,0), iVar4 == 0)))) &&
          (iVar4 = dict_set_i64(local_2c,DAT_00014134 + 0x13fd8,600,0), iVar4 == 0)) &&
         (iVar4 = dict_set_i64(local_2c,DAT_00014138 + 0x13fea,0x3c,0), iVar4 == 0)) {
        iVar4 = dict_set_i64(local_2c,DAT_0001413c + 0x13ffe,0x125,0);
        if ((iVar4 == 0) &&
           (iVar3 = dict_set_i64(local_2c,DAT_00014140 + 0x14010,0x5c,0), iVar4 = local_2c,
           iVar3 == 0)) {
          local_28 = 0;
          iVar3 = (**(code **)(DAT_00014144 + 0x1406a))
                            (0,*(undefined4 *)(DAT_00014144 + 0x1406e),&local_28);
          if (iVar3 == 0) {
            if (local_28 != 0) {
              iVar3 = append_alt_view_area_constprop_3(local_28,0x28a);
              if (((((iVar3 != 0) ||
                    (iVar3 = append_alt_view_area_constprop_3(local_28,0x36), iVar3 != 0)) ||
                   (iVar3 = append_alt_view_area_constprop_3(local_28,0x28a), iVar3 != 0)) ||
                  ((iVar3 = append_alt_view_area_constprop_3(local_28,0x36), iVar3 != 0 ||
                   (iVar3 = dict_set_object(iVar4,DAT_00014148 + 0x14072,local_28), iVar3 != 0))))
                 || (iVar4 = dict_set_i64(iVar4,DAT_0001414c + 0x14084,0,0), iVar4 != 0))
              goto LAB_000140d8;
              iVar4 = 0;
              goto LAB_0001408c;
            }
          }
          else {
LAB_000140d8:
            iVar4 = -1;
LAB_0001408c:
            if (local_28 != 0) {
              (**(code **)(DAT_00014150 + 0x140aa))();
            }
            iVar1 = local_2c;
            iVar3 = DAT_00014154;
            if (iVar4 == 0) {
              if (local_2c != 0) {
                iVar4 = (**(code **)(DAT_00014154 + 0x14102))(local_34,local_2c);
                if (iVar4 == 0) {
                  (**(code **)(iVar3 + 0x140be))(iVar1);
                  (**(code **)(iVar3 + 0x140be))(iVar2);
                  iVar2 = local_34;
                }
                else {
                  (**(code **)(iVar3 + 0x140be))(iVar1);
                  (**(code **)(iVar3 + 0x140be))(local_34);
                }
                goto LAB_00013ee0;
              }
              goto LAB_000140cc;
            }
          }
          (**(code **)((int)&DAT_00014114 + DAT_00014164))(local_2c);
        }
        else {
          (**(code **)(DAT_00014158 + 0x140de))(local_2c);
        }
      }
      else {
        (**(code **)(DAT_00014160 + 0x140fa))(local_2c);
      }
    }
  }
LAB_000140cc:
  (**(code **)(DAT_0001415c + 0x140e8))(local_34);
LAB_00013ee0:
  if (local_24 != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



/* Address 00014168 | AirPlayReceiverSessionSetup | bytes 2292 */

void AirPlayReceiverSessionSetup(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  void *pvVar13;
  int iVar14;
  pthread_mutex_t *ppVar15;
  size_t sVar16;
  void *pvVar17;
  int *piVar18;
  code *pcVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int local_114;
  pthread_t local_110;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  int local_ec;
  int local_e8;
  undefined4 local_e4;
  int local_e0;
  uint local_dc;
  void *local_d8;
  void *local_d4;
  void *local_d0;
  void *local_cc;
  void *local_c8;
  int local_c4;
  void *local_c0;
  int local_bc;
  undefined1 auStack_b8 [4];
  int local_b4;
  int local_b0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined1 auStack_8c [32];
  char acStack_6c [64];
  int local_2c;
  
  iVar23 = DAT_00014a64;
  piVar18 = *(int **)(DAT_00014a5c + 0x1417a + DAT_00014a60);
  local_2c = *piVar18;
  lazy_init();
  if (*(int *)(iVar23 + 0x141b4) != 0) {
    pthread_mutex_lock((pthread_mutex_t *)(DAT_00014a98 + 0x1433c));
    if (*(int *)(iVar23 + 0x1430c) != param_1) {
      *(undefined4 *)(iVar23 + 0x14200) = 0;
    }
    ppVar15 = (pthread_mutex_t *)(DAT_00014a9c + 0x14358);
    *(int *)(DAT_00014aa0 + 0x144d6) = param_1;
    pthread_mutex_unlock(ppVar15);
  }
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00014a68 + 0x1423c));
  if (*(int *)(DAT_00014a6c + 0x14338) == param_1) {
    *(undefined4 *)(DAT_00014a6c + 0x14338) = 0;
  }
  iVar8 = DAT_00014a74;
  iVar23 = DAT_00014a70;
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014a70 + 0x1425c));
  iVar7 = parse_setup_request(param_2,auStack_b8);
  if ((*(int *)(iVar8 + 0x141f2) == 0) || (*(int *)(iVar8 + 0x1430e) == 0)) {
LAB_000141e0:
    bVar4 = false;
  }
  else if (iVar7 == 0) {
    bVar4 = false;
  }
  else {
    if (local_b4 == 0) goto LAB_000141e0;
    bVar4 = true;
    pthread_mutex_lock((pthread_mutex_t *)(iVar23 + 0x141c8));
    *(int *)(iVar8 + 0x142da) = param_1;
    pthread_mutex_unlock((pthread_mutex_t *)(iVar23 + 0x141c8));
  }
  iVar23 = DAT_00014a78;
  if (*(code **)(DAT_00014a78 + 0x1431e) == (code *)0x0) {
    iVar8 = -1;
    uVar20 = 0;
    bVar2 = false;
    iVar23 = 0;
  }
  else {
    iVar8 = (**(code **)(DAT_00014a78 + 0x1431e))(param_1,param_2,param_3);
    iVar9 = DAT_00014acc;
    if (iVar8 == 0) {
      if (((*(int *)(iVar23 + 0x14216) == 0) || (iVar7 == 0)) || (local_b4 == 0)) {
        bVar2 = true;
        uVar20 = 0;
        iVar23 = iVar8;
      }
      else {
        if (((param_3 != (int *)0x0) && (iVar7 = *param_3, iVar7 != 0)) &&
           (*(int *)(iVar23 + 0x14332) != 0)) {
          if (local_b0 == 0) {
            uVar20 = 1;
            iVar23 = -0x1a54;
            bVar2 = true;
            goto LAB_00014212;
          }
          local_c0 = (void *)0xffffffff;
          local_c4 = iVar8;
          local_bc = iVar8;
          pthread_mutex_lock((pthread_mutex_t *)(DAT_00014acc + 0x14544));
          pthread_mutex_lock((pthread_mutex_t *)(iVar9 + 0x1454c));
          iVar9 = DAT_00014ad0;
          if ((*(int *)(iVar23 + 0x14282) == 0) || (*(int *)(DAT_00014ad0 + 0x1466a) != 0)) {
            pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014b20 + 0x14870));
          }
          else {
            piVar1 = (int *)(DAT_00014ad0 + 0x14606);
            *(undefined4 *)(DAT_00014ad0 + 0x14602) = 3;
            bVar2 = *piVar1 != 0;
            if (bVar2) {
              local_110 = *(pthread_t *)(iVar9 + 0x14686);
              *(undefined4 *)(iVar9 + 0x14606) = 0;
            }
            iVar9 = DAT_00014ad8;
            iVar23 = DAT_00014ad4;
            iVar14 = DAT_00014ad8 + 0x145be;
            iVar21 = *(int *)(DAT_00014ad4 + 0x1460c);
            *(undefined4 *)(DAT_00014ad4 + 0x145d0) = 0;
            *(undefined4 *)(iVar23 + 0x1460c) = 0;
            *(undefined4 *)(iVar23 + 0x145cc) = 0;
            *(undefined4 *)(iVar23 + 0x145d4) = 0;
            *(undefined4 *)(iVar23 + 0x145d8) = 0;
            close_fd(iVar14);
            iVar23 = *(int *)(iVar9 + 0x145c2);
            if (-1 < iVar23) {
              shutdown(iVar23,2);
              close_fd(iVar9 + 0x145c2);
            }
            iVar23 = DAT_00014adc;
            ppVar15 = (pthread_mutex_t *)(DAT_00014ae0 + 0x145dc);
            *(undefined4 *)(DAT_00014adc + 0x1466a) = 0;
            *(undefined4 *)(iVar23 + 0x1466e) = 0;
            *(undefined4 *)(iVar23 + 0x146da) = 1;
            pthread_mutex_unlock(ppVar15);
            if (bVar2) {
              pthread_join(local_110,(void **)0x0);
            }
            if ((iVar21 != 0) && (*(code **)(DAT_00014ae4 + 0x14606) != (code *)0x0)) {
              (**(code **)(DAT_00014ae4 + 0x14606))(iVar21);
            }
          }
          ppVar15 = (pthread_mutex_t *)(DAT_00014ae8 + 0x14614);
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014ae8 + 0x1460c));
          pthread_mutex_lock(ppVar15);
          if (((*(int *)(DAT_00014aec + 0x14694) == 0) || (*(int *)(DAT_00014aec + 0x14658) == 0))
             || (param_1 == *(int *)(DAT_00014aec + 0x14658))) {
            pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014b28 + 0x1489e));
          }
          else {
            pthread_mutex_unlock(ppVar15);
            cleanup_alt();
          }
          if (param_1 == 0) {
            pthread_mutex_lock((pthread_mutex_t *)(DAT_00014b2c + 0x148aa));
          }
          else {
            cVar3 = *(char *)(param_1 + 0x85);
            iVar9 = *(int *)(param_1 + 0x3e4);
            ppVar15 = (pthread_mutex_t *)(DAT_00014af0 + 0x14658);
            pthread_mutex_lock(ppVar15);
            iVar23 = DAT_00014af4;
            if ((iVar9 != 0 && cVar3 != '\0') && (*(int *)(DAT_00014af4 + 0x146ea) == 0)) {
              pthread_mutex_unlock(ppVar15);
              if ((*(code **)(iVar23 + 0x147c2) == (code *)0x0) ||
                 ((iVar14 = (**(code **)(iVar23 + 0x147c2))(&local_c4), iVar14 != 0 ||
                  (local_c4 == 0)))) goto LAB_00014820;
              if ((*(code **)(iVar23 + 0x147c6) != (code *)0x0) &&
                 (iVar14 = (**(code **)(iVar23 + 0x147c6))(local_c4,local_9c,0), iVar14 == 0)) {
                snprintf(acStack_6c,0x40,(char *)(DAT_00014af8 + 0x146c6),
                         CONCAT44(uStack_94,local_98));
                sVar16 = strlen(acStack_6c);
                iVar9 = (**(code **)(iVar23 + 0x147ce))
                                  (iVar9,acStack_6c,sVar16,DAT_00014afc + 0x146e6,0x20,0x20,
                                   auStack_8c);
                if (((((iVar9 == 0) && (*(code **)(iVar23 + 0x147ca) != (code *)0x0)) &&
                     (iVar9 = (**(code **)(iVar23 + 0x147ca))(local_c4,auStack_8c,0x20),
                     iVar23 = DAT_00014b00, iVar9 == 0)) &&
                    ((iVar9 = (**(code **)(DAT_00014b00 + 0x14878))
                                        (cVar3,1,6,0xffffe82c,&local_bc,0xfffd4000,&local_c0),
                     iVar9 == 0 && (-1 < (int)local_c0)))) && (0 < local_bc)) {
                  if (*(code **)(iVar23 + 0x1487c) != (code *)0x0) {
                    (**(code **)(iVar23 + 0x1487c))(local_c0,0xc);
                  }
                  iVar23 = local_bc;
                  local_d8 = (void *)0x0;
                  local_d0 = (void *)0x0;
                  local_c8 = (void *)0x0;
                  iVar9 = dict_get_key(iVar7,DAT_00014b04 + 0x1476e,&local_d8);
                  if (iVar9 != 0) {
LAB_0001477a:
                    if (local_d8 == (void *)0x0) {
LAB_00014780:
                      iVar9 = (**(code **)(DAT_00014b08 + 0x147d2))
                                        (0,*(undefined4 *)(DAT_00014b08 + 0x147d6),&local_d0);
                      if ((iVar9 == 0) && (local_d0 != (void *)0x0)) {
                        bVar2 = true;
                        goto LAB_0001479c;
                      }
                    }
                    goto LAB_0001481a;
                  }
                  if (local_d8 == (void *)0x0) goto LAB_00014780;
                  if (*(code **)(DAT_00014b24 + 0x148d6) == (code *)0x0) goto LAB_0001481a;
                  iVar9 = (**(code **)(DAT_00014b24 + 0x148d6))(local_d8,&local_c8);
                  if (iVar9 != 0) goto LAB_0001477a;
                  local_d0 = local_d8;
                  bVar2 = false;
LAB_0001479c:
                  iVar9 = DAT_00014b0c;
                  local_cc = (void *)0x0;
                  iVar14 = (**(code **)(DAT_00014b0c + 0x147cc))
                                     (0,2,*(undefined4 *)(DAT_00014b0c + 0x147d0),
                                      *(undefined4 *)(DAT_00014b0c + 0x147d4),&local_cc);
                  if ((iVar14 == 0) && (local_cc != (void *)0x0)) {
                    iVar14 = dict_set_i64(local_cc,DAT_00014b10 + 0x147d8,0x6f,0);
                    if ((iVar14 != 0) ||
                       (iVar23 = dict_set_i64(local_cc,DAT_00014b14 + 0x147e8,iVar23,iVar23 >> 0x1f)
                       , pvVar13 = local_cc, iVar23 != 0)) {
                      (**(code **)(DAT_00014b34 + 0x148ce))(local_cc);
                      goto LAB_000148bc;
                    }
                    if (local_cc == (void *)0x0) goto LAB_000148bc;
                    pvVar17 = (void *)(**(code **)(iVar9 + 0x14804))(local_d0,local_cc);
                    if (pvVar17 == (void *)0x0) {
                      (**(code **)(iVar9 + 0x147c0))(pvVar13);
                      if (!bVar2) {
LAB_00014910:
                        iVar7 = DAT_00014b44;
                        iVar23 = DAT_00014b40;
                        pthread_mutex_lock((pthread_mutex_t *)(DAT_00014b40 + 0x14926));
                        iVar9 = *(int *)(iVar7 + 0x14970);
                        iVar14 = *(int *)(iVar7 + 0x14a24);
                        *(int *)(iVar7 + 0x14994) = local_c4;
                        *(int *)(iVar7 + 0x14958) = param_1;
                        *(undefined4 *)(iVar7 + 0x149bc) = 1;
                        *(void **)(iVar23 + 0x14942) = local_c0;
                        *(undefined4 *)(iVar7 + 0x1495c) = 0;
                        *(uint *)(iVar23 + 0x1492e) = (uint)(iVar9 != 0);
                        *(undefined4 *)(iVar7 + 0x149c0) = 0;
                        if (iVar14 == 0) {
                          if (((local_c4 == 0) || ((int)local_c0 < 0)) ||
                             (iVar23 = pthread_create((pthread_t *)(iVar7 + 0x14a40),
                                                      (pthread_attr_t *)0x0,
                                                      (__start_routine *)(DAT_00014b48 + 0x14968),
                                                      local_c0), iVar23 != 0)) {
                            iVar7 = DAT_00014b70;
                            iVar23 = DAT_00014b6c;
                            ppVar15 = (pthread_mutex_t *)(DAT_00014b70 + 0x14a2a);
                            *(undefined4 *)((int)&DAT_00014a94 + DAT_00014b6c) = 0;
                            *(undefined4 *)(iVar23 + 0x14a58) = 0;
                            *(undefined4 *)(iVar7 + 0x14a46) = 0xffffffff;
                            *(undefined4 *)((int)&DAT_00014abc + iVar23) = 0;
                            pthread_mutex_unlock(ppVar15);
                            goto LAB_0001481a;
                          }
                          *(undefined4 *)(iVar7 + 0x14a24) = 1;
                          *(undefined4 *)(iVar7 + 0x149c0) = 0;
                        }
                        iVar23 = DAT_00014b4c;
                        piVar1 = (int *)(DAT_00014b4c + 0x1498a);
                        *(undefined4 *)(DAT_00014b4c + 0x14a1a) = 2;
                        iVar7 = *piVar1 + 1;
                        if (iVar7 == 0) {
                          *(int *)(iVar23 + 0x1498a) = *piVar1 + 2;
                        }
                        else {
                          *(int *)(iVar23 + 0x1498a) = iVar7;
                        }
                        iVar23 = DAT_00014b50;
                        if (*(int *)(DAT_00014b50 + 0x149c0) != 0) {
                          if (*(int *)((int)&DAT_00014a9c + DAT_00014b50) == 0) {
                            *(undefined4 *)((int)&DAT_00014aa4 + DAT_00014b50) = 0;
                            *(undefined4 *)((int)&DAT_00014aa0 + iVar23) = 1;
                          }
                          *(undefined4 *)((int)&DAT_00014ab4 + DAT_00014b54 + 2) = 0;
                        }
                        iVar7 = DAT_00014b58;
                        uVar20 = 0;
                        bVar2 = true;
                        iVar23 = 0;
                        pthread_cond_broadcast((pthread_cond_t *)(DAT_00014b58 + 0x149e8));
                        pthread_mutex_unlock((pthread_mutex_t *)(iVar7 + 0x149c4));
                        ctl_write_state(DAT_00014b5c + 0x149d8,DAT_00014b60 + 0x149da);
                        goto LAB_00014212;
                      }
                      local_cc = pvVar17;
                      iVar23 = cfl_string(DAT_00014b64 + 0x149e8,&local_cc);
                      if ((iVar23 == 0) && (local_cc != (void *)0x0)) {
                        iVar9 = (**(code **)(iVar9 + 0x147c4))(iVar7,local_cc,local_d0);
                        iVar7 = DAT_00014b74;
                        iVar23 = DAT_00014b68;
                        if (iVar9 == 0) {
                          (**(code **)(DAT_00014b68 + 0x14a1c))(local_cc);
                          (**(code **)(iVar23 + 0x14a1c))(local_d0);
                          goto LAB_00014910;
                        }
                        (**(code **)(DAT_00014b74 + 0x14a5a))(local_cc);
                        (**(code **)(iVar7 + 0x14a5a))(local_d0);
                      }
                      else {
                        (**(code **)((int)&DAT_00014a6c + DAT_00014b78))(local_d0);
                      }
                    }
                    else {
                      (**(code **)(iVar9 + 0x147c0))(pvVar13);
                      if (bVar2) {
                        (**(code **)(iVar9 + 0x147c0))(local_d0);
                      }
                    }
                  }
                  else {
LAB_000148bc:
                    if (bVar2) {
                      (**(code **)(DAT_00014b38 + 0x148de))(local_d0);
                    }
                  }
LAB_0001481a:
                  abort_alt_stream(&local_c4);
                  goto LAB_00014820;
                }
              }
              close_fd(&local_c0);
              if ((local_c4 != 0) && (*(code **)(DAT_00014b3c + 0x148fa) != (code *)0x0)) {
                (**(code **)(DAT_00014b3c + 0x148fa))();
              }
              goto LAB_00014820;
            }
          }
          pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014b30 + 0x148b4));
        }
LAB_00014820:
        uVar20 = 1;
        iVar23 = -0x1a2c;
        bVar2 = true;
      }
    }
    else {
      uVar20 = 0;
      bVar2 = false;
      iVar23 = 0;
    }
  }
LAB_00014212:
  iVar7 = DAT_00014a7c;
  if (bVar4) {
    pthread_mutex_lock((pthread_mutex_t *)(DAT_00014a80 + 0x14270));
    if (*(int *)(DAT_00014a84 + 0x14388) == param_1) {
      *(undefined4 *)(DAT_00014a84 + 0x14388) = 0;
    }
    pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014a88 + 0x1428c));
    iVar7 = DAT_00014a7c;
  }
  DAT_00014a7c = iVar7;
  if (uVar20 == 0) {
    iVar23 = iVar8;
    if ((((bVar2) && (*(int *)(iVar7 + 0x14256) != 0)) &&
        ((param_3 != (int *)0x0 &&
         (((iVar8 = *param_3, iVar8 != 0 &&
           (local_fc = uVar20, local_f8 = uVar20, local_f4 = uVar20, local_f0 = uVar20, param_2 != 0
           )) && (iVar9 = dict_get_key(param_2,DAT_00014aa4 + 0x1436c,&local_fc), iVar9 == 0))))))
       && (((local_fc != 0 &&
            (iVar9 = (**(code **)(iVar7 + 0x14286))(local_fc,&local_f0), iVar9 == 0)) &&
           ((iVar10 = (**(code **)(iVar7 + 0x14272))(0,*(undefined4 *)(iVar7 + 0x14276),&local_f8),
            iVar5 = DAT_00014abc, iVar21 = DAT_00014ab8, iVar14 = DAT_00014ab4, iVar9 = DAT_00014ab0
            , iVar7 = DAT_00014aac, iVar10 == 0 && (local_f8 != 0)))))) {
      if (local_f0 != 0) {
        uVar20 = 0;
        iVar10 = DAT_00014aa8 + 0x143be;
        local_114 = 0;
        do {
          local_ec = 0;
          local_e8 = 0;
          local_e4 = 0;
          local_e0 = 0;
          iVar11 = (**(code **)(iVar7 + 0x14424))(local_fc,uVar20,&local_ec);
          iVar12 = local_ec;
          if (((iVar11 == 0) && (local_ec != 0)) &&
             ((iVar11 = string_equals(local_ec,iVar10), iVar11 != 0 ||
              (iVar12 = string_equals(iVar12,DAT_00014b18 + 0x14846), iVar12 != 0)))) {
            uVar6 = local_f8;
            local_dc = 0;
            local_d8 = (void *)0x0;
            local_d4 = (void *)0x0;
            if (*(code **)(iVar9 + 0x14432) != (code *)0x0) {
              iVar12 = (**(code **)(iVar9 + 0x14432))(local_ec,&local_d8,&local_d4);
              if ((((iVar12 == 0) && (local_d8 != (void *)0x0)) &&
                  (pvVar13 = (void *)(**(code **)(iVar9 + 0x14426))(uVar6,&local_dc),
                  pvVar13 == (void *)0x0)) && (uVar22 = 0, local_dc != 0)) {
                do {
                  local_d0 = pvVar13;
                  local_cc = pvVar13;
                  local_c8 = pvVar13;
                  iVar12 = (**(code **)(iVar21 + 0x14432))(uVar6,uVar22,&local_d0);
                  if (((iVar12 == 0) && (local_d0 != (void *)0x0)) &&
                     (((iVar12 = (**(code **)(iVar21 + 0x1443a))(local_d0,&local_cc,&local_c8),
                       iVar12 == 0 && ((local_cc != (void *)0x0 && (local_c8 == local_d4)))) &&
                      (iVar12 = memcmp(local_cc,local_d8,(size_t)local_c8), iVar12 == 0))))
                  goto LAB_000144da;
                  uVar22 = uVar22 + 1;
                } while (uVar22 < local_dc);
                pcVar19 = *(code **)(DAT_00014ac0 + 0x14502);
              }
              else {
                pcVar19 = *(code **)(iVar9 + 0x14432);
              }
              if ((((pcVar19 != (code *)0x0) &&
                   (iVar12 = (*pcVar19)(local_ec,&local_e8,&local_e4), iVar12 == 0)) &&
                  (local_e8 != 0)) &&
                 ((iVar12 = (**(code **)(iVar14 + 0x143dc))(0,local_e8,local_e4,&local_e0),
                  iVar12 == 0 && (local_e0 != 0)))) {
                iVar12 = (**(code **)(iVar14 + 0x14424))(local_f8);
                if (iVar12 == 0) {
                  local_114 = local_114 + 1;
                }
                (**(code **)(iVar5 + 0x143f0))(local_e0);
              }
            }
          }
LAB_000144da:
          uVar20 = uVar20 + 1;
        } while (uVar20 < local_f0);
        if (((local_114 != 0) &&
            (iVar9 = cfl_string(DAT_00014ac4 + 0x144fa,&local_f4), iVar7 = DAT_00014ac8, iVar9 == 0)
            ) && (local_f4 != 0)) {
          (**(code **)(DAT_00014ac8 + 0x1452e))(iVar8,local_f4,local_f8);
          (**(code **)(iVar7 + 0x1452a))(local_f4);
          (**(code **)(iVar7 + 0x1452a))(local_f8);
          goto LAB_00014248;
        }
      }
      (**(code **)(DAT_00014b1c + 0x1486c))(local_f8);
    }
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)(DAT_00014a8c + 0x1429c));
    iVar8 = DAT_00014a90;
    piVar1 = (int *)(DAT_00014a90 + 0x142da);
    *(undefined4 *)(DAT_00014a90 + 0x143b6) = 0;
    if (*piVar1 == param_1) {
      *(undefined4 *)(iVar8 + 0x1433e) = 4;
    }
    pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014a94 + 0x142be));
    cleanup_alt();
  }
LAB_00014248:
  if (local_2c != *piVar18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar23);
  }
  return;
}



/* Address 00014b7c | AirPlayReceiverSessionSendiAPMessage | bytes 84 */

undefined4
AirPlayReceiverSessionSendiAPMessage(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  pthread_mutex_t *__mutex;
  
  lazy_init();
  if (param_2 != 0 && param_1 != 0) {
    __mutex = (pthread_mutex_t *)(DAT_00014bd4 + 0x14bba);
    pthread_mutex_lock(__mutex);
    *(int *)((int)&DAT_00014d48 + DAT_00014bd8) = param_1;
    pthread_mutex_unlock(__mutex);
  }
  if (*(code **)(DAT_00014bd0 + 0x14cd6) == (code *)0x0) {
    return 0xffffffff;
  }
  uVar1 = (**(code **)(DAT_00014bd0 + 0x14cd6))(param_1,param_2,param_3,param_4);
  return uVar1;
}



/* Address 00014bdc | AirPlayReceiverSessionTearDown | bytes 332 */

void AirPlayReceiverSessionTearDown(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  int local_58;
  int local_54;
  int local_2c;
  
  piVar4 = *(int **)(DAT_00014d28 + 0x14bee + DAT_00014d2c);
  local_2c = *piVar4;
  lazy_init();
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00014d30 + 0x14c9e));
  if (param_2 == 0) {
    if (*(int *)((int)&DAT_00014e80 + DAT_00014d58 + 2) == param_1) {
      if (param_4 != (undefined1 *)0x0) {
        *param_4 = 1;
      }
      pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014d5c + 0x14db2));
      goto LAB_00014c90;
    }
    bVar1 = true;
    *(int *)((int)&DAT_00014e80 + DAT_00014d58 + 2) = param_1;
    bVar6 = true;
    bVar2 = false;
  }
  else {
    iVar3 = parse_setup_request(param_2,&local_58);
    if (iVar3 == 0) {
      bVar1 = true;
      bVar6 = false;
      bVar2 = false;
    }
    else {
      bVar6 = local_54 != 0;
      bVar1 = !bVar6;
      bVar2 = bVar6;
    }
  }
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00014d34 + 0x14c2c));
  iVar3 = *(int *)(DAT_00014d38 + 0x14c66);
  iVar5 = *(int *)((int)&DAT_00014d40 + DAT_00014d38 + 2);
  if (param_1 == iVar5) {
    *(undefined4 *)(AirPlayReceiverSessionScreen_SetTimeSynchronizer + DAT_00014d48 + 2) = 0;
  }
  if (param_2 == 0) {
    if (*(int *)((int)&DAT_00014d40 + DAT_00014d4c + 2) == param_1) {
      *(undefined4 *)((int)&DAT_00014d40 + DAT_00014d4c + 2) = 0;
    }
    if (*(int *)(DAT_00014d50 + 0x14e5a) == param_1) {
      *(undefined4 *)(DAT_00014d50 + 0x14e5a) = 0;
    }
    if (*(int *)(DAT_00014d54 + 0x14e6a) == param_1) {
      *(undefined4 *)(DAT_00014d54 + 0x14e6a) = 0;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014d3c + 0x14c5e));
  if ((bool)((iVar3 == param_1 || param_1 == iVar5) & bVar6)) {
    cleanup_alt();
  }
  if ((bVar2) && (param_4 != (undefined1 *)0x0)) {
    *param_4 = 0;
  }
  if (((bVar1) || (local_58 == 0)) && (*(code **)(DAT_00014d40 + 0x14db0) != (code *)0x0)) {
    (**(code **)(DAT_00014d40 + 0x14db0))(param_1,param_2,param_3,param_4);
  }
  pthread_mutex_unlock((pthread_mutex_t *)((int)&DAT_00014d28 + DAT_00014d44));
LAB_00014c90:
  if (local_2c != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 00014d60 | AirPlayReceiverSessionScreen_Setup | bytes 38 */

undefined4
AirPlayReceiverSessionScreen_Setup(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  lazy_init();
  if (*(code **)(DAT_00014d88 + 0x14ec2) == (code *)0x0) {
    return 0xffffffff;
  }
  uVar1 = (**(code **)(DAT_00014d88 + 0x14ec2))(param_1,param_2,param_3);
  return uVar1;
}



/* Address 00014d8c | PairingSessionDeriveKey | bytes 62 */

undefined4
PairingSessionDeriveKey
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00014dcc;
  lazy_init();
  if (*(code **)(&UNK_00014ef6 + iVar1) == (code *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (**(code **)(&UNK_00014ef6 + iVar1))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar2;
}



/* Address 00014dd0 | AirPlayReceiverSessionScreen_SetTimeSynchronizer | bytes 28 */

void AirPlayReceiverSessionScreen_SetTimeSynchronizer
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  code *pcVar1;
  
  lazy_init();
  pcVar1 = *(code **)(DAT_00014dec + 0x14e60);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1,param_2,extraout_r2,pcVar1,param_4);
  }
  return;
}



/* Address 00014df0 | AirPlayReceiverSessionScreen_StartSession | bytes 140 */

int AirPlayReceiverSessionScreen_StartSession
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  
  iVar1 = DAT_00014e7c;
  lazy_init();
  pcVar6 = *(code **)((int)&DAT_00014e84 + iVar1 + 2);
  if (pcVar6 == (code *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = (*pcVar6)(param_1,param_2,param_3,param_4,param_5,param_6);
    iVar2 = DAT_00014e80;
    if (iVar3 == 0) {
      piVar4 = (int *)__emutls_get_address(DAT_00014e80 + 0x14e6e);
      if (*piVar4 == 0) {
        pthread_mutex_lock((pthread_mutex_t *)(iVar2 + 0x14e32));
        iVar5 = *(int *)(iVar1 + 0x14f86);
        if ((iVar5 != 0) && (iVar5 != *(int *)(iVar1 + 0x14e7a))) {
          *(int *)(iVar1 + 0x14e7a) = iVar5;
          pthread_cond_broadcast((pthread_cond_t *)(iVar2 + 0x14e56));
        }
        if (*(int *)(dint_deinit + DAT_00014e84 + 4) != 0) {
          *(undefined4 *)(DAT_00014e84 + 0x14f70) = 1;
        }
        pthread_mutex_unlock((pthread_mutex_t *)(DAT_00014e88 + 0x14e78));
      }
    }
  }
  return iVar3;
}



/* Address 00014e8c | AirPlayReceiverSessionScreen_ProcessFrames | bytes 38 */

undefined4
AirPlayReceiverSessionScreen_ProcessFrames(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  lazy_init();
  if (*(code **)(DAT_00014eb4 + 0x14f2a) == (code *)0x0) {
    return 0xffffffff;
  }
  uVar1 = (**(code **)(DAT_00014eb4 + 0x14f2a))(param_1,param_2,param_3);
  return uVar1;
}



/* Address 00014eb8 | ServerSocketOpen | bytes 62 */

undefined4
ServerSocketOpen(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00014ef8;
  lazy_init();
  if (*(code **)(iVar1 + 0x15026) == (code *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x15026))(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar2;
}



/* Address 00014efc | dint_init | bytes 94 */

int dint_init(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  pthread_mutex_t *ppVar5;
  
  lazy_init();
  iVar4 = DAT_00014f5c;
  if (*(code **)(DAT_00014f5c + 0x15070) == (code *)0x0) {
    ppVar5 = (pthread_mutex_t *)(DAT_00014f64 + 0x14f50);
    pthread_mutex_lock(ppVar5);
    pthread_mutex_unlock(ppVar5);
    return -1;
  }
  iVar2 = (**(code **)(DAT_00014f5c + 0x15070))();
  iVar1 = DAT_00014f60;
  ppVar5 = (pthread_mutex_t *)(DAT_00014f60 + 0x14f1c);
  pthread_mutex_lock(ppVar5);
  iVar4 = *(int *)(iVar4 + 0x14f3c);
  pthread_mutex_unlock(ppVar5);
  if (iVar2 != 4) {
    return iVar2;
  }
  piVar3 = (int *)__emutls_get_address(iVar1 + 0x14f28);
  if (*piVar3 == 0 && iVar4 == 0) {
    iVar4 = 4;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}



/* Address 00014f68 | dint_deinit | bytes 66 */

undefined4 dint_deinit(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  code *pcVar5;
  pthread_mutex_t *__mutex;
  int iVar6;
  
  lazy_init();
  iVar2 = DAT_00014fb0;
  iVar1 = DAT_00014fac;
  __mutex = (pthread_mutex_t *)(DAT_00014fac + 0x14f7e);
  pthread_mutex_lock(__mutex);
  iVar6 = *(int *)((int)&DAT_00014fb0 + iVar2);
  pthread_mutex_unlock(__mutex);
  piVar3 = (int *)__emutls_get_address(iVar1 + 0x14f8a);
  if (*piVar3 != 0 || iVar6 != 0) {
    return 0;
  }
  pcVar5 = *(code **)(iVar2 + 0x150e8);
  if (pcVar5 == (code *)0x0) {
    return 0xffffffff;
  }
  uVar4 = (*pcVar5)();
  return uVar4;
}



/* Address 00014fb4 | dint_create_window | bytes 164 */

int dint_create_window(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                      undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  pthread_mutex_t *__mutex;
  int iVar5;
  
  lazy_init();
  iVar5 = param_2;
  if ((param_2 == 0x3b) &&
     ((param_3 != 0x780 || (iVar5 = 0x3e, param_4 != 600 && param_4 != 0x260)))) {
    piVar4 = (int *)__emutls_get_address(DAT_00015060 + 0x15076);
    if (*piVar4 == 0) {
      iVar5 = 0x3b;
    }
    else {
      iVar5 = 0x3e;
    }
  }
  iVar1 = DAT_00015058;
  if (*(code **)(DAT_00015058 + 0x1513a) == (code *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = (**(code **)(DAT_00015058 + 0x1513a))(param_1,iVar5,param_3,param_4,param_5,param_6);
    if ((iVar5 == 0x3e && param_2 == 0x3b) && (iVar2 == 0)) {
      __mutex = (pthread_mutex_t *)(DAT_0001505c + 0x15012);
      puVar3 = (undefined4 *)__emutls_get_address(DAT_0001505c + 0x1503e);
      *puVar3 = 1;
      pthread_mutex_lock(__mutex);
      *(undefined4 *)(iVar1 + 0x1500a) = 1;
      pthread_mutex_unlock(__mutex);
    }
  }
  return iVar2;
}



/* Address 00015064 | read_identity | bytes 298 */

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
  
  piVar10 = *(int **)(DAT_00015190 + 0x15072 + DAT_00015194);
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
          if (sVar4 < 0) goto LAB_000150fa;
          if (sVar4 == 0) {
            close(iVar2);
            if (uVar9 != 0) goto LAB_00015134;
            iVar2 = *param_3;
            goto LAB_0001515e;
          }
          uVar9 = uVar9 + sVar4;
        } while (uVar9 < 0x1000);
        if ((uVar9 != 0x1000) || (sVar4 = read(iVar2,&uStack_10bd,1), sVar4 == 0)) {
          close(iVar2);
LAB_00015134:
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
LAB_0001515e:
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
          goto LAB_00015114;
        }
      }
LAB_000150fa:
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
LAB_00015114:
  if (local_2c[0] != *piVar10) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



/* Address 00015198 | audi_device_binding_authorized | bytes 682 */

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
  
  iVar1 = DAT_00015454;
  piVar4 = *(int **)(DAT_00015444 + 0x151a2 + DAT_00015448);
  local_2178 = 0;
  local_2174 = 0;
  local_2c[0] = *piVar4;
  if (*(int *)(DAT_0001544c + 0x151b4) < 0) {
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
    local_2170[0] = *(int *)(DAT_00015450 + 0x15226);
    local_2170[1] = *(undefined4 *)(DAT_00015450 + 0x1522a);
    local_2170[2] = *(undefined4 *)(DAT_00015450 + 0x1522e);
    local_2170[3] = *(undefined4 *)(DAT_00015450 + 0x15232);
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
    iVar11 = read_identity(DAT_00015454 + 0x1524e,abStack_202c,&local_2178);
    if ((iVar11 == 0) &&
       (iVar11 = read_identity(iVar1 + 0x15262,abStack_102c,&local_2174), iVar11 == 0)) {
      data = (void *)(DAT_0001545c + 0x1530c);
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
      SHA256_Update(&SStack_2160,(void *)(iVar1 + 0x15272),0xc);
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
    *(int *)(DAT_00015458 + 0x152e0) = iVar1;
  }
  if (local_2c[0] != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Address 00015460 | emutls_init | bytes 36 */

void emutls_init(void)

{
  int iVar1;
  
  iVar1 = pthread_key_create((pthread_key_t *)(DAT_00015484 + 0x15474),
                             (__destr_function *)(DAT_00015488 + 0x15478));
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return;
}



/* Address 0001548c | emutls_destroy | bytes 76 */

void emutls_destroy(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (iVar3 != 0) {
    iVar1 = 0;
    piVar2 = param_1 + -1;
    do {
      iVar1 = iVar1 + 1;
      if (piVar2[2] != 0) {
        free(*(void **)(piVar2[2] + -4));
      }
      piVar2 = piVar2 + 1;
    } while (iVar1 != iVar3);
  }
  free(param_1);
  return;
}



/* Address 000154d8 | __emutls_get_address | bytes 444 */

void * __emutls_get_address(size_t *param_1)

{
  int iVar1;
  uint *__pointer;
  void *pvVar2;
  uint uVar3;
  pthread_key_t *ppVar4;
  uint uVar5;
  void *__s;
  uint uVar6;
  
  iVar1 = DAT_00015698;
  uVar3 = param_1[2];
  DataMemoryBarrier(0xf);
  if (uVar3 == 0) {
    pthread_once((pthread_once_t *)(DAT_00015698 + 0x15544),
                 (__init_routine *)(DAT_0001569c + 0x15548));
    pthread_mutex_lock((pthread_mutex_t *)(iVar1 + 0x15550));
    uVar3 = param_1[2];
    if (uVar3 == 0) {
      uVar3 = *(int *)(DAT_000156a8 + 0x15678) + 1;
      *(uint *)(DAT_000156a8 + 0x15678) = uVar3;
      DataMemoryBarrier(0xf);
      param_1[2] = uVar3;
    }
    pthread_mutex_unlock((pthread_mutex_t *)(DAT_000156a0 + 0x15578));
  }
  ppVar4 = (pthread_key_t *)(DAT_00015694 + 0x154fc);
  __pointer = pthread_getspecific(*ppVar4);
  if (__pointer == (uint *)0x0) {
    __pointer = calloc(uVar3 + 0x21,4);
    if (__pointer == (uint *)0x0) goto LAB_00015690;
    *__pointer = uVar3 + 0x20;
    pthread_setspecific(*ppVar4,__pointer);
  }
  else {
    uVar5 = *__pointer;
    if (uVar5 < uVar3) {
      uVar6 = uVar5 * 2;
      if (uVar6 < uVar3) {
        uVar6 = uVar3 + 0x20;
      }
      __pointer = realloc(__pointer,(uVar6 + 1) * 4);
      if (__pointer == (uint *)0x0) goto LAB_00015690;
      *__pointer = uVar6;
      memset(__pointer + uVar5 + 1,0,(uVar6 - uVar5) * 4);
      pthread_setspecific(*(pthread_key_t *)(DAT_000156a4 + 0x1560c),__pointer);
    }
  }
  __s = (void *)__pointer[uVar3];
  if (__s == (void *)0x0) {
    uVar5 = param_1[1];
    if (uVar5 < 5) {
      pvVar2 = malloc(*param_1 + 4);
      if (pvVar2 == (void *)0x0) {
LAB_00015690:
                    /* WARNING: Subroutine does not return */
        abort();
      }
      __s = (void *)((int)pvVar2 + 4);
      *(void **)pvVar2 = pvVar2;
    }
    else {
      pvVar2 = malloc(uVar5 + *param_1 + 3);
      if (pvVar2 == (void *)0x0) goto LAB_00015690;
      __s = (void *)((int)pvVar2 + uVar5 + 3 & -uVar5);
      *(void **)((int)__s + -4) = pvVar2;
    }
    if ((void *)param_1[3] == (void *)0x0) {
      memset(__s,0,*param_1);
    }
    else {
      memcpy(__s,(void *)param_1[3],*param_1);
    }
    __pointer[uVar3] = (uint)__s;
  }
  return __s;
}



/* Address 000156ac | __emutls_register_common | bytes 56 */

void __emutls_register_common(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  if (*param_1 < param_2) {
    *param_1 = param_2;
    param_1[3] = 0;
  }
  if (param_1[1] < param_3) {
    param_1[1] = param_3;
  }
  if (param_4 == 0) {
    return;
  }
  if (*param_1 == param_2) {
    param_1[3] = param_4;
  }
  return;
}



/* Address 000156e4 | restore_non_core_regs | bytes 136 */

void restore_non_core_regs(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      __gnu_Unwind_Restore_VFP(param_1 + 0x12);
      uVar1 = *param_1;
    }
    else {
      __gnu_Unwind_Restore_VFP_D();
      uVar1 = *param_1;
    }
  }
  if ((uVar1 & 4) == 0) {
    __gnu_Unwind_Restore_VFP_D_16_to_31(param_1 + 0x34);
    uVar1 = *param_1;
  }
  if ((uVar1 & 8) == 0) {
    __gnu_Unwind_Restore_WMMXD(param_1 + 0x6c);
    if ((*param_1 & 0x10) != 0) {
      return;
    }
  }
  else if ((uVar1 & 0x10) != 0) {
    return;
  }
  __gnu_Unwind_Restore_WMMXC(param_1 + 0x8c);
  return;
}



/* Address 0001576c | get_eit_entry | bytes 556 */

undefined4 get_eit_entry(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int local_2c [2];
  
  iVar5 = DAT_00015998 + 0x15780;
  uVar11 = param_2 - 2;
  if (*(int *)(iVar5 + DAT_0001599c) == 0) {
    iVar2 = *(int *)(iVar5 + DAT_000159b0);
    local_2c[0] = *(int *)(iVar5 + DAT_000159ac) - iVar2 >> 3;
  }
  else {
    iVar2 = __gnu_Unwind_Find_exidx(uVar11,local_2c);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      return 9;
    }
  }
  if (local_2c[0] == 0) {
LAB_00015834:
    *(undefined4 *)(param_1 + 0x10) = 0;
    return 9;
  }
  iVar10 = 0;
  iVar12 = local_2c[0] + -1;
  while( true ) {
    iVar1 = (iVar10 + iVar12) / 2;
    uVar6 = *(uint *)(iVar2 + iVar1 * 8);
    iVar8 = iVar2 + iVar1 * 8;
    if ((uVar6 & 0x40000000) == 0) {
      uVar3 = uVar6 & 0x7fffffff;
    }
    else {
      uVar3 = uVar6 | 0x80000000;
    }
    if (local_2c[0] + -1 == iVar1) break;
    iVar4 = iVar1 + 1;
    uVar7 = *(uint *)(iVar2 + iVar4 * 8);
    if ((uVar7 & 0x40000000) == 0) {
      uVar7 = uVar7 & 0x7fffffff;
    }
    else {
      uVar7 = uVar7 | 0x80000000;
    }
    if (uVar11 < iVar8 + uVar3) {
LAB_0001580c:
      if (iVar10 == iVar1) goto LAB_00015834;
      iVar12 = iVar1 + -1;
    }
    else {
      if (uVar11 <= iVar2 + iVar4 * 8 + -1 + uVar7) goto LAB_00015854;
      iVar10 = iVar4;
    }
  }
  if (uVar11 < iVar8 + uVar3) goto LAB_0001580c;
LAB_00015854:
  if ((uVar6 & 0x40000000) == 0) {
    uVar6 = uVar6 & 0x7fffffff;
  }
  else {
    uVar6 = uVar6 | 0x80000000;
  }
  uVar11 = *(uint *)(iVar8 + 4);
  *(uint *)(param_1 + 0x48) = iVar8 + uVar6;
  if (uVar11 == 1) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    return 5;
  }
  if ((int)uVar11 < 0) {
    puVar9 = (uint *)(iVar8 + 4);
    *(uint **)(param_1 + 0x4c) = puVar9;
    *(undefined4 *)(param_1 + 0x50) = 1;
  }
  else {
    if ((uVar11 & 0x40000000) == 0) {
      uVar11 = uVar11 & 0x7fffffff;
    }
    else {
      uVar11 = uVar11 | 0x80000000;
    }
    puVar9 = (uint *)(iVar8 + 4 + uVar11);
    *(uint **)(param_1 + 0x4c) = puVar9;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  uVar11 = *puVar9;
  if (-1 < (int)uVar11) {
    if ((uVar11 & 0x40000000) == 0) {
      uVar11 = uVar11 & 0x7fffffff;
    }
    else {
      uVar11 = uVar11 | 0x80000000;
    }
    *(uint *)(param_1 + 0x10) = (int)puVar9 + uVar11;
    return 0;
  }
  uVar11 = (uVar11 & 0xfffffff) >> 0x18;
  if (uVar11 == 1) {
    iVar5 = *(int *)(iVar5 + DAT_000159a8);
  }
  else if (uVar11 == 2) {
    iVar5 = *(int *)(iVar5 + DAT_000159a4);
  }
  else {
    if (uVar11 != 0) goto LAB_00015834;
    iVar5 = *(int *)(iVar5 + DAT_000159a0);
  }
  *(int *)(param_1 + 0x10) = iVar5;
  if (iVar5 == 0) {
    return 9;
  }
  return 0;
}



/* Address 000159b4 | _Unwind_DebugHook | bytes 4 */

void _Unwind_DebugHook(void)

{
  return;
}



/* Address 000159b8 | unwind_phase2_forced | bytes 356 */

int unwind_phase2_forced(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 *__src;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 local_48c;
  undefined4 uStack_488;
  undefined4 uStack_484;
  undefined4 uStack_480;
  undefined4 local_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 uStack_464;
  undefined4 local_460;
  undefined4 local_45c;
  undefined1 auStack_260 [56];
  undefined4 local_228;
  
  local_49c = *(undefined4 *)(param_2 + 4);
  uStack_498 = *(undefined4 *)(param_2 + 8);
  uStack_494 = *(undefined4 *)(param_2 + 0xc);
  uStack_490 = *(undefined4 *)(param_2 + 0x10);
  pcVar5 = *(code **)(param_1 + 0xc);
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  local_48c = *(undefined4 *)(param_2 + 0x14);
  uStack_488 = *(undefined4 *)(param_2 + 0x18);
  uStack_484 = *(undefined4 *)(param_2 + 0x1c);
  uStack_480 = *(undefined4 *)(param_2 + 0x20);
  local_47c = *(undefined4 *)(param_2 + 0x24);
  uStack_478 = *(undefined4 *)(param_2 + 0x28);
  uStack_474 = *(undefined4 *)(param_2 + 0x2c);
  uStack_470 = *(undefined4 *)(param_2 + 0x30);
  local_46c = *(undefined4 *)(param_2 + 0x34);
  local_468 = *(undefined4 *)(param_2 + 0x38);
  uStack_464 = *(undefined4 *)(param_2 + 0x3c);
  local_460 = *(undefined4 *)(param_2 + 0x40);
  local_4a0 = 0;
  iVar1 = get_eit_entry(param_1,local_460);
  if (param_3 == 0) {
    uVar4 = 9;
  }
  else {
    uVar4 = 10;
  }
  __src = &local_4a0;
  do {
    if (iVar1 != 0) {
      local_45c = local_468;
      iVar2 = (*pcVar5)(1,uVar4 | 0x10,param_1,param_1,__src,uVar6);
      if (iVar2 != 0) {
LAB_00015b00:
        iVar1 = 9;
      }
      return iVar1;
    }
    *(undefined4 *)(param_1 + 0x14) = local_460;
    memcpy(auStack_260,__src,0x240);
    iVar1 = (**(code **)(param_1 + 0x10))(uVar4,param_1,auStack_260);
    local_45c = local_228;
    iVar2 = (*pcVar5)(1,uVar4,param_1,param_1,__src,uVar6);
    if (iVar2 != 0) goto LAB_00015b00;
    memcpy(__src,auStack_260,0x240);
    if (iVar1 != 8) {
      if (iVar1 != 7) goto LAB_00015b00;
      _Unwind_DebugHook(0,local_460);
      uVar7 = restore_core_regs(&local_49c);
      iVar2 = (int)((ulonglong)uVar7 >> 0x20);
      iVar1 = (int)uVar7;
      pcVar5 = unwind_phase2;
      uVar6 = 0;
      break;
    }
    iVar1 = get_eit_entry(param_1,local_460);
    uVar4 = 9;
  } while( true );
  while( true ) {
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x40);
    iVar3 = (**(code **)(iVar1 + 0x10))
                      (1,iVar1,iVar2,*(code **)(iVar1 + 0x10),param_1,uVar6,__src,pcVar5);
    if (iVar3 != 8) break;
    iVar3 = get_eit_entry(iVar1,*(undefined4 *)(iVar2 + 0x40));
    if (iVar3 != 0) goto LAB_00015b68;
  }
  if (iVar3 == 7) {
    _Unwind_DebugHook(0,*(undefined4 *)(iVar2 + 0x40));
    iVar1 = restore_core_regs(iVar2 + 4);
    return *(int *)(iVar1 + 0x44);
  }
LAB_00015b68:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Address 00015b1c | unwind_phase2 | bytes 100 */

undefined4 unwind_phase2(int param_1,int param_2)

{
  int iVar1;
  
  do {
    iVar1 = get_eit_entry(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_00015b68;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 == 7) {
    _Unwind_DebugHook(0,*(undefined4 *)(param_2 + 0x40));
    iVar1 = restore_core_regs(param_2 + 4);
    return *(undefined4 *)(iVar1 + 0x44);
  }
LAB_00015b68:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Address 00015b80 | _Unwind_GetCFA | bytes 8 */

undefined4 _Unwind_GetCFA(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* Address 00015b88 | __gnu_Unwind_RaiseException | bytes 164 */

undefined4 __gnu_Unwind_RaiseException(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  int extraout_r3;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 local_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 local_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 local_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 local_218;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  local_254 = *(undefined4 *)(param_2 + 4);
  uStack_250 = *(undefined4 *)(param_2 + 8);
  uStack_24c = *(undefined4 *)(param_2 + 0xc);
  uStack_248 = *(undefined4 *)(param_2 + 0x10);
  local_244 = *(undefined4 *)(param_2 + 0x14);
  uStack_240 = *(undefined4 *)(param_2 + 0x18);
  uStack_23c = *(undefined4 *)(param_2 + 0x1c);
  uStack_238 = *(undefined4 *)(param_2 + 0x20);
  local_234 = *(undefined4 *)(param_2 + 0x24);
  uStack_230 = *(undefined4 *)(param_2 + 0x28);
  uStack_22c = *(undefined4 *)(param_2 + 0x2c);
  uStack_228 = *(undefined4 *)(param_2 + 0x30);
  local_224 = *(undefined4 *)(param_2 + 0x34);
  uStack_220 = *(undefined4 *)(param_2 + 0x38);
  uStack_21c = *(undefined4 *)(param_2 + 0x3c);
  local_218 = *(undefined4 *)(param_2 + 0x40);
  local_258 = 0xffffffff;
  do {
    iVar1 = get_eit_entry(param_1,local_218);
    if (iVar1 != 0) {
      return 9;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(0,param_1,&local_258);
  } while (iVar1 == 8);
  restore_non_core_regs(&local_258);
  if (iVar1 == 6) {
    uVar3 = unwind_phase2(param_1,param_2);
    iVar1 = (int)uVar3;
    uVar2 = *(undefined4 *)(extraout_r3 + 0x3c);
    *(int *)(iVar1 + 0xc) = (int)((ulonglong)uVar3 >> 0x20);
    *(undefined4 *)(iVar1 + 0x18) = extraout_r2;
    *(undefined4 *)(extraout_r3 + 0x40) = uVar2;
    uVar2 = unwind_phase2_forced(iVar1,extraout_r3,0);
    return uVar2;
  }
  return 9;
}



/* Address 00015c2c | __gnu_Unwind_ForcedUnwind | bytes 36 */

void __gnu_Unwind_ForcedUnwind(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_4 + 0x3c);
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_4 + 0x40) = uVar1;
  unwind_phase2_forced(param_1,param_4,0);
  return;
}



/* Address 00015c50 | __gnu_Unwind_Resume | bytes 116 */

void __gnu_Unwind_Resume(int param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x14);
  if (iVar1 != 0) {
    unwind_phase2_forced(param_1,param_2,1);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar1 = (**(code **)(param_1 + 0x10))(2,param_1,param_2);
  if (iVar1 == 7) {
    _Unwind_DebugHook(0,*(undefined4 *)(param_2 + 0x40));
    restore_core_regs(param_2 + 4);
  }
  else if (iVar1 != 8) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar2 = unwind_phase2(param_1,param_2);
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  if (*(int *)((int)uVar2 + 0xc) == 0) {
    __gnu_Unwind_RaiseException();
    return;
  }
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x3c);
  unwind_phase2_forced((int)uVar2,iVar1,0);
  return;
}



/* Address 00015cc4 | __gnu_Unwind_Resume_or_Rethrow | bytes 32 */

void __gnu_Unwind_Resume_or_Rethrow(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    __gnu_Unwind_RaiseException();
    return;
  }
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  unwind_phase2_forced(param_1,param_2,0);
  return;
}



/* Address 00015ce4 | _Unwind_Complete | bytes 4 */

void _Unwind_Complete(void)

{
  return;
}



/* Address 00015ce8 | _Unwind_DeleteException | bytes 32 */

void _Unwind_DeleteException(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 8);
  if (pcVar1 == (code *)0x0) {
    return;
  }
  (*pcVar1)(1,param_1,param_3,pcVar1,param_4);
  return;
}



/* Address 00015d08 | _Unwind_VRS_Get | bytes 68 */

undefined4 _Unwind_VRS_Get(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  
  if (param_2 != 0) {
    if (param_2 < 5) {
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
    return uVar1;
  }
  bVar2 = param_3 == 0xf;
  if (param_3 < 0x10) {
    bVar2 = param_4 == 0;
  }
  if (bVar2) {
    uVar1 = 0;
    *param_5 = *(undefined4 *)(param_1 + param_3 * 4 + 4);
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



/* Address 00015d4c | _Unwind_VRS_Set | bytes 68 */

undefined4 _Unwind_VRS_Set(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  
  if (param_2 != 0) {
    if (param_2 < 5) {
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
    return uVar1;
  }
  bVar2 = param_3 == 0xf;
  if (param_3 < 0x10) {
    bVar2 = param_4 == 0;
  }
  if (bVar2) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + param_3 * 4 + 4) = *param_5;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



/* Address 00015d90 | __gnu_Unwind_Backtrace | bytes 208 */

int __gnu_Unwind_Backtrace(code *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 *local_2b4;
  undefined1 auStack_2b0 [16];
  code *local_2a0;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 local_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 local_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 local_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 local_218;
  
  *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_3 + 0x3c);
  local_254 = *(undefined4 *)(param_3 + 4);
  uStack_250 = *(undefined4 *)(param_3 + 8);
  uStack_24c = *(undefined4 *)(param_3 + 0xc);
  uStack_248 = *(undefined4 *)(param_3 + 0x10);
  local_244 = *(undefined4 *)(param_3 + 0x14);
  uStack_240 = *(undefined4 *)(param_3 + 0x18);
  uStack_23c = *(undefined4 *)(param_3 + 0x1c);
  uStack_238 = *(undefined4 *)(param_3 + 0x20);
  local_234 = *(undefined4 *)(param_3 + 0x24);
  uStack_230 = *(undefined4 *)(param_3 + 0x28);
  uStack_22c = *(undefined4 *)(param_3 + 0x2c);
  uStack_228 = *(undefined4 *)(param_3 + 0x30);
  local_224 = *(undefined4 *)(param_3 + 0x34);
  uStack_220 = *(undefined4 *)(param_3 + 0x38);
  uStack_21c = *(undefined4 *)(param_3 + 0x3c);
  local_218 = *(undefined4 *)(param_3 + 0x40);
  local_258 = 0xffffffff;
  do {
    iVar1 = get_eit_entry(auStack_2b0,local_218);
    if (iVar1 != 0) {
LAB_00015e58:
      iVar1 = 9;
      break;
    }
    local_2b4 = auStack_2b0;
    _Unwind_VRS_Set(&local_258,0,0xc,0,&local_2b4);
    iVar1 = (*param_1)(&local_258,param_2);
    if (iVar1 != 0) goto LAB_00015e58;
    iVar1 = (*local_2a0)(8,auStack_2b0,&local_258);
  } while (iVar1 != 9 && iVar1 != 5);
  restore_non_core_regs(&local_258);
  return iVar1;
}



/* Address 00015e60 | __gnu_unwind_pr_common | bytes 1372 */

undefined4 __gnu_unwind_pr_common(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint *local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  
  uVar8 = param_1 & 3;
  local_30 = *(uint **)(param_2 + 0x4c) + 1;
  local_34 = **(uint **)(param_2 + 0x4c);
  iVar4 = DAT_000163bc + 0x15e8c;
  puVar5 = local_30;
  if (param_4 == 0) {
    local_34 = local_34 << 8;
    local_2b = 0;
    local_2c = 3;
  }
  else if (param_4 < 3) {
    uVar10 = local_34 >> 0x10;
    local_2b = (undefined1)(local_34 >> 0x10);
    local_34 = local_34 << 0x10;
    local_2c = 2;
    puVar5 = local_30 + (uVar10 & 0xff);
  }
  if (uVar8 == 2) {
    puVar5 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    bVar1 = false;
    while (uVar10 = *puVar5, uVar10 != 0) {
      if (param_4 == 2) {
        puVar7 = puVar5 + 2;
        uVar9 = puVar5[1];
      }
      else {
        puVar7 = puVar5 + 1;
        uVar9 = (uint)*(ushort *)((int)puVar5 + 2);
        uVar10 = (uint)(ushort)*puVar5;
      }
      uVar11 = (uVar9 & 0xfffffffe) + *(int *)(param_2 + 0x48);
      _Unwind_VRS_Get(param_3,0,0xf,0,&local_38);
      if (local_38 < uVar11) {
        bVar12 = false;
      }
      else if (local_38 < uVar11 + (uVar10 & 0xfffffffe)) {
        bVar12 = true;
      }
      else {
        bVar12 = false;
      }
      uVar10 = uVar10 & 1 | (uVar9 & 1) << 1;
      if (uVar10 == 1) {
        if (uVar8 == 0) {
          if (bVar12) {
            uVar10 = puVar7[1];
            if (uVar10 != 0xfffffffe) {
              local_54 = param_2 + 0x58;
              if (uVar10 == 0xffffffff) {
                _Unwind_VRS_Get(param_3,0,0xd,0,&local_38);
                *(uint *)(param_2 + 0x20) = local_38;
              }
              else {
                bVar12 = uVar10 != 0;
                if (bVar12) {
                  uVar10 = (int)puVar7 + uVar10;
                }
                if (bVar12) {
                  uVar2 = *(undefined4 *)(uVar10 + 4);
                }
                else {
                  uVar2 = 0;
                }
                iVar3 = __cxa_type_match(param_2,uVar2,*puVar7 >> 0x1f,&local_54);
                if (iVar3 == 0) goto LAB_000160cc;
                _Unwind_VRS_Get(param_3,0,0xd,0,&local_38);
                *(uint *)(param_2 + 0x20) = local_38;
                if (iVar3 == 2) {
                  *(int *)(param_2 + 0x2c) = local_54;
                  *(int **)(param_2 + 0x24) = (int *)(param_2 + 0x2c);
                  goto LAB_000162e8;
                }
              }
              *(int *)(param_2 + 0x24) = local_54;
LAB_000162e8:
              *(uint **)(param_2 + 0x28) = puVar7;
              return 6;
            }
            goto LAB_00015ed0;
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&local_38);
          if ((uVar10 == local_38) && (*(uint **)(param_2 + 0x28) == puVar7)) {
            uVar8 = *puVar7;
            if ((uVar8 & 0x40000000) == 0) {
              uVar8 = uVar8 & 0x7fffffff;
            }
            else {
              uVar8 = uVar8 | 0x80000000;
            }
            local_4c = (int)puVar7 + uVar8;
            _Unwind_VRS_Set(param_3,0,0xf,0,&local_4c);
            piVar6 = &local_48;
            local_48 = param_2;
LAB_000161e0:
            _Unwind_VRS_Set(param_3,0,0,0,piVar6);
            return 7;
          }
        }
LAB_000160cc:
        puVar5 = puVar7 + 2;
      }
      else if (uVar10 == 0) {
        if (uVar8 == 0) {
          bVar12 = false;
        }
        if (bVar12) {
          uVar8 = *puVar7;
          *(uint **)(param_2 + 0x38) = puVar7 + 1;
          if ((uVar8 & 0x40000000) == 0) {
            uVar8 = uVar8 & 0x7fffffff;
          }
          else {
            uVar8 = uVar8 | 0x80000000;
          }
          iVar4 = __cxa_begin_cleanup(param_2);
          if (iVar4 != 0) {
            local_50 = (int)puVar7 + uVar8;
            _Unwind_VRS_Set(param_3,0,0xf,0,&local_50);
            return 7;
          }
          goto LAB_00015ed0;
        }
        puVar5 = puVar7 + 1;
      }
      else {
        if (uVar10 != 2) goto LAB_00015ed0;
        uVar10 = *puVar7;
        uVar9 = uVar10 & 0x7fffffff;
        if (uVar8 == 0) {
          if (bVar12) {
            uVar11 = ((param_1 ^ 8) & 0xf) >> 3;
            if (uVar9 == 0) {
              uVar11 = 1;
            }
            if (uVar11 != 0) {
              if (uVar9 == 0) {
LAB_000162f4:
                _Unwind_VRS_Get(param_3,0,0xd,0,&local_38);
                *(uint **)(param_2 + 0x28) = puVar7;
                *(uint *)(param_2 + 0x20) = local_38;
                *(int *)(param_2 + 0x24) = local_54;
                return 6;
              }
              puVar5 = puVar7;
              uVar10 = 0;
              while( true ) {
                puVar5 = puVar5 + 1;
                uVar11 = uVar10 + 1;
                uVar2 = 0;
                if (*puVar5 != 0) {
                  uVar2 = *(undefined4 *)((int)puVar5 + *puVar5);
                }
                local_54 = param_2 + 0x58;
                iVar3 = __cxa_type_match(param_2,uVar2,0,&local_54);
                if (iVar3 != 0) break;
                uVar10 = uVar11;
                if (uVar11 == uVar9) goto LAB_000162f4;
              }
              if (uVar9 == uVar10) goto LAB_000162f4;
              goto LAB_00016034;
            }
          }
LAB_00016038:
          if ((int)uVar10 < 0) {
            puVar7 = puVar7 + 1;
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&local_38);
          if ((uVar10 != local_38) || (puVar7 != *(uint **)(param_2 + 0x28))) {
LAB_00016034:
            uVar10 = *puVar7;
            goto LAB_00016038;
          }
          *(uint *)(param_2 + 0x28) = uVar9;
          *(undefined4 *)(param_2 + 0x2c) = 0;
          *(undefined4 *)(param_2 + 0x30) = 4;
          *(uint **)(param_2 + 0x34) = puVar7 + 1;
          if ((int)*puVar7 < 0) {
            uVar8 = puVar7[uVar9 + 1];
            if ((uVar8 & 0x40000000) == 0) {
              uVar8 = uVar8 & 0x7fffffff;
            }
            else {
              uVar8 = uVar8 | 0x80000000;
            }
            local_44 = (int)puVar7 + uVar8 + (uVar9 + 1) * 4;
            _Unwind_VRS_Set(param_3,0,0xf,0,&local_44);
            piVar6 = &local_40;
            local_40 = param_2;
            goto LAB_000161e0;
          }
          bVar1 = true;
        }
        puVar5 = puVar7 + uVar9 + 1;
      }
    }
  }
  else {
    bVar1 = false;
  }
  if ((param_4 < 3) && (iVar3 = __gnu_unwind_execute(param_3,&local_34), iVar3 == 0)) {
    if (bVar1) {
      _Unwind_VRS_Get(param_3,0,0xf,0,&local_38);
      local_3c = local_38;
      _Unwind_VRS_Set(param_3,0,0xe,0,&local_3c);
      local_38 = *(uint *)(iVar4 + DAT_000163c0);
      _Unwind_VRS_Set(param_3,0,0xf,0,&local_38);
      uVar2 = 7;
    }
    else {
      uVar2 = 8;
    }
  }
  else {
LAB_00015ed0:
    uVar2 = 9;
  }
  return uVar2;
}



/* Address 000163c4 | __aeabi_unwind_cpp_pr2 | bytes 8 */

void __aeabi_unwind_cpp_pr2(void)

{
  __gnu_unwind_pr_common();
  return;
}



/* Address 000163cc | __aeabi_unwind_cpp_pr1 | bytes 8 */

void __aeabi_unwind_cpp_pr1(void)

{
  __gnu_unwind_pr_common();
  return;
}



/* Address 000163d4 | __aeabi_unwind_cpp_pr0 | bytes 8 */

void __aeabi_unwind_cpp_pr0(void)

{
  __gnu_unwind_pr_common();
  return;
}



/* Address 000163dc | _Unwind_VRS_Pop | bytes 904 */

undefined4 _Unwind_VRS_Pop(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  undefined4 auStack_220 [27];
  uint local_1b4;
  undefined4 local_1b0 [4];
  undefined1 auStack_1a0 [128];
  undefined4 auStack_120 [32];
  undefined4 auStack_a0 [34];
  
  switch(param_2) {
  case 0:
    if (param_4 != 0) {
      return 2;
    }
    puVar7 = (uint *)param_1[0xe];
    uVar6 = 0;
    do {
      uVar2 = uVar6 + 1;
      if ((param_3 & 0xffff & 1 << (uVar6 & 0xff)) != 0) {
        param_1[uVar6 + 1] = *puVar7;
        puVar7 = puVar7 + 1;
      }
      uVar6 = uVar2;
    } while (uVar2 != 0x10);
    if ((param_3 & 0x2000) == 0) {
      param_1[0xe] = (uint)puVar7;
      return 0;
    }
    return 0;
  case 1:
    if ((param_4 & 0xfffffffb) != 1) {
      return 2;
    }
    uVar6 = param_3 >> 0x10;
    param_3 = param_3 & 0xffff;
    uVar2 = param_3 + uVar6;
    if (param_4 == 1) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = 0x20;
    }
    if (uVar4 < uVar2) {
      return 2;
    }
    bVar9 = param_4 == 1;
    if (0xf < uVar6 && bVar9) {
      return 2;
    }
    uVar4 = param_3;
    if (0xf < uVar6) {
LAB_00016530:
      if (uVar4 != 0 && param_4 != 5) {
        return 2;
      }
    }
    else {
      if (0x10 < uVar2) {
        uVar4 = uVar2 - 0x10;
        goto LAB_00016530;
      }
      uVar4 = 0;
    }
    if ((uVar6 < 0x10) && (uVar2 = *param_1, (uVar2 & 1) != 0)) {
      *param_1 = uVar2 & 0xfffffffe;
      if (param_4 == 5) {
        *param_1 = uVar2 & 0xfffffffe | 2;
        __gnu_Unwind_Save_VFP_D(param_1 + 0x12);
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        __gnu_Unwind_Save_VFP(param_1 + 0x12);
      }
    }
    if ((uVar4 != 0) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      __gnu_Unwind_Save_VFP_D_16_to_31(param_1 + 0x34);
    }
    if (bVar9) {
      __gnu_Unwind_Save_VFP(auStack_a0);
      if (uVar4 == 0) goto LAB_0001659c;
    }
    else {
      if (uVar6 < 0x10) {
        __gnu_Unwind_Save_VFP_D(auStack_a0);
      }
      if (uVar4 == 0) goto LAB_0001659c;
      __gnu_Unwind_Save_VFP_D_16_to_31(auStack_1a0);
    }
    param_3 = 0x10 - uVar6;
LAB_0001659c:
    uVar2 = param_1[0xe];
    if (0 < (int)param_3) {
      iVar5 = param_3 * 2;
      puVar3 = auStack_a0 + uVar6 * 2;
      do {
        iVar5 = iVar5 + -1;
        *puVar3 = *(undefined4 *)((int)puVar3 + (uVar2 - (int)(auStack_a0 + uVar6 * 2)));
        puVar3 = puVar3 + 1;
      } while (iVar5 != 0);
      uVar2 = uVar2 + param_3 * 8;
    }
    if (uVar4 != 0) {
      uVar1 = uVar6;
      if (uVar6 < 0x10) {
        uVar1 = 0x10;
      }
      iVar5 = uVar4 * 2;
      puVar8 = (undefined4 *)(uVar2 - 4);
      puVar3 = auStack_220 + uVar1 * 2;
      do {
        iVar5 = iVar5 + -1;
        puVar8 = puVar8 + 1;
        *puVar3 = *puVar8;
        puVar3 = puVar3 + 1;
      } while (iVar5 != 0);
      uVar2 = uVar2 + uVar4 * 8;
    }
    if (bVar9) {
      param_1[0xe] = uVar2 + 4;
      __gnu_Unwind_Restore_VFP(auStack_a0);
    }
    else {
      param_1[0xe] = uVar2;
      if (uVar6 < 0x10) {
        __gnu_Unwind_Restore_VFP_D(auStack_a0);
      }
      if (uVar4 != 0) {
        __gnu_Unwind_Restore_VFP_D_16_to_31(auStack_1a0);
      }
    }
    return 0;
  case 2:
    return 1;
  case 3:
    if (param_4 == 3) {
      uVar6 = param_3 & 0xffff;
      if (uVar6 + (param_3 >> 0x10) < 0x11) {
        if ((*param_1 & 8) != 0) {
          *param_1 = *param_1 & 0xfffffff7;
          __gnu_Unwind_Save_WMMXD(param_1 + 0x6c);
        }
        iVar5 = uVar6 * 2;
        __gnu_Unwind_Save_WMMXD(auStack_120);
        uVar2 = param_1[0xe];
        if (uVar6 != 0) {
          puVar3 = auStack_120 + (param_3 >> 0x10) * 2;
          do {
            iVar5 = iVar5 + -1;
            *puVar3 = *(undefined4 *)
                       ((int)puVar3 + (uVar2 - (int)(auStack_120 + (param_3 >> 0x10) * 2)));
            puVar3 = puVar3 + 1;
          } while (iVar5 != 0);
          uVar2 = uVar2 + uVar6 * 8;
        }
        param_1[0xe] = uVar2;
        __gnu_Unwind_Restore_WMMXD(auStack_120);
        return 0;
      }
    }
    break;
  case 4:
    bVar9 = param_3 == 0x10;
    if (param_3 < 0x11) {
      bVar9 = param_4 == 0;
    }
    if (bVar9) {
      if ((*param_1 & 0x10) != 0) {
        *param_1 = *param_1 & 0xffffffef;
        local_1b4 = param_3;
        __gnu_Unwind_Save_WMMXC(param_1 + 0x8c);
        param_3 = local_1b4;
      }
      local_1b4 = param_3;
      __gnu_Unwind_Save_WMMXC(local_1b0);
      puVar3 = (undefined4 *)param_1[0xe];
      uVar6 = 0;
      do {
        if ((local_1b4 & 1 << (uVar6 & 0xff)) != 0) {
          local_1b0[uVar6] = *puVar3;
          puVar3 = puVar3 + 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 != 4);
      param_1[0xe] = (uint)puVar3;
      __gnu_Unwind_Restore_WMMXC(local_1b0);
      return 0;
    }
  }
  return 2;
}



/* Address 00016764 | restore_core_regs | bytes 20 */

undefined8 restore_core_regs(undefined8 *param_1)

{
  return *param_1;
}



/* Address 00016778 | __gnu_Unwind_Restore_VFP | bytes 8 */

undefined4 __gnu_Unwind_Restore_VFP(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Address 00016780 | __gnu_Unwind_Save_VFP | bytes 8 */

void __gnu_Unwind_Save_VFP(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



/* Address 00016788 | __gnu_Unwind_Restore_VFP_D | bytes 8 */

undefined4 __gnu_Unwind_Restore_VFP_D(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Address 00016790 | __gnu_Unwind_Save_VFP_D | bytes 8 */

void __gnu_Unwind_Save_VFP_D(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



/* Address 00016798 | __gnu_Unwind_Restore_VFP_D_16_to_31 | bytes 8 */

void __gnu_Unwind_Restore_VFP_D_16_to_31(void)

{
  return;
}



/* Address 000167a0 | __gnu_Unwind_Save_VFP_D_16_to_31 | bytes 8 */

void __gnu_Unwind_Save_VFP_D_16_to_31(undefined8 *param_1)

{
  undefined8 in_d16;
  undefined8 in_d17;
  undefined8 in_d18;
  undefined8 in_d19;
  undefined8 in_d20;
  undefined8 in_d21;
  undefined8 in_d22;
  undefined8 in_d23;
  undefined8 in_d24;
  undefined8 in_d25;
  undefined8 in_d26;
  undefined8 in_d27;
  undefined8 in_d28;
  undefined8 in_d29;
  undefined8 in_d30;
  undefined8 in_d31;
  
  *param_1 = in_d16;
  param_1[1] = in_d17;
  param_1[2] = in_d18;
  param_1[3] = in_d19;
  param_1[4] = in_d20;
  param_1[5] = in_d21;
  param_1[6] = in_d22;
  param_1[7] = in_d23;
  param_1[8] = in_d24;
  param_1[9] = in_d25;
  param_1[10] = in_d26;
  param_1[0xb] = in_d27;
  param_1[0xc] = in_d28;
  param_1[0xd] = in_d29;
  param_1[0xe] = in_d30;
  param_1[0xf] = in_d31;
  return;
}



/* Address 000167a8 | __gnu_Unwind_Restore_WMMXD | bytes 68 */

int __gnu_Unwind_Restore_WMMXD(int param_1)

{
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr4;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  undefined4 in_cr12;
  undefined4 in_cr13;
  undefined4 in_cr14;
  undefined4 in_cr15;
  
  coprocessor_loadlong(1,in_cr0,param_1);
  coprocessor_loadlong(1,in_cr1,param_1 + 8);
  coprocessor_loadlong(1,in_cr2,param_1 + 0x10);
  coprocessor_loadlong(1,in_cr3,param_1 + 0x18);
  coprocessor_loadlong(1,in_cr4,param_1 + 0x20);
  coprocessor_loadlong(1,in_cr5,param_1 + 0x28);
  coprocessor_loadlong(1,in_cr6,param_1 + 0x30);
  coprocessor_loadlong(1,in_cr7,param_1 + 0x38);
  coprocessor_loadlong(1,in_cr8,param_1 + 0x40);
  coprocessor_loadlong(1,in_cr9,param_1 + 0x48);
  coprocessor_loadlong(1,in_cr10,param_1 + 0x50);
  coprocessor_loadlong(1,in_cr11,param_1 + 0x58);
  coprocessor_loadlong(1,in_cr12,param_1 + 0x60);
  coprocessor_loadlong(1,in_cr13,param_1 + 0x68);
  coprocessor_loadlong(1,in_cr14,param_1 + 0x70);
  coprocessor_loadlong(1,in_cr15,param_1 + 0x78);
  return param_1 + 0x80;
}



/* Address 000167ec | __gnu_Unwind_Save_WMMXD | bytes 68 */

int __gnu_Unwind_Save_WMMXD(int param_1)

{
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr4;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  undefined4 in_cr12;
  undefined4 in_cr13;
  undefined4 in_cr14;
  undefined4 in_cr15;
  
  coprocessor_storelong(1,in_cr0,param_1);
  coprocessor_storelong(1,in_cr1,param_1 + 8);
  coprocessor_storelong(1,in_cr2,param_1 + 0x10);
  coprocessor_storelong(1,in_cr3,param_1 + 0x18);
  coprocessor_storelong(1,in_cr4,param_1 + 0x20);
  coprocessor_storelong(1,in_cr5,param_1 + 0x28);
  coprocessor_storelong(1,in_cr6,param_1 + 0x30);
  coprocessor_storelong(1,in_cr7,param_1 + 0x38);
  coprocessor_storelong(1,in_cr8,param_1 + 0x40);
  coprocessor_storelong(1,in_cr9,param_1 + 0x48);
  coprocessor_storelong(1,in_cr10,param_1 + 0x50);
  coprocessor_storelong(1,in_cr11,param_1 + 0x58);
  coprocessor_storelong(1,in_cr12,param_1 + 0x60);
  coprocessor_storelong(1,in_cr13,param_1 + 0x68);
  coprocessor_storelong(1,in_cr14,param_1 + 0x70);
  coprocessor_storelong(1,in_cr15,param_1 + 0x78);
  return param_1 + 0x80;
}



/* Address 00016830 | __gnu_Unwind_Restore_WMMXC | bytes 20 */

int __gnu_Unwind_Restore_WMMXC(int param_1)

{
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  
  coprocessor_load2(1,in_cr8,param_1);
  coprocessor_load2(1,in_cr9,param_1 + 4);
  coprocessor_load2(1,in_cr10,param_1 + 8);
  coprocessor_load2(1,in_cr11,param_1 + 0xc);
  return param_1 + 0x10;
}



/* Address 00016844 | __gnu_Unwind_Save_WMMXC | bytes 20 */

int __gnu_Unwind_Save_WMMXC(int param_1)

{
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  
  coprocessor_store2(1,in_cr8,param_1);
  coprocessor_store2(1,in_cr9,param_1 + 4);
  coprocessor_store2(1,in_cr10,param_1 + 8);
  coprocessor_store2(1,in_cr11,param_1 + 0xc);
  return param_1 + 0x10;
}



/* Address 00016858 | ___Unwind_RaiseException | bytes 36 */

void ___Unwind_RaiseException
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_RaiseException(param_1,&uStack_44,param_3,0,param_3);
  return;
}



/* Address 0001687c | _Unwind_Resume | bytes 36 */

void _Unwind_Resume(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_Resume(param_1,&uStack_44,param_3,0,param_3);
  return;
}



/* Address 000168a0 | ___Unwind_Resume_or_Rethrow | bytes 36 */

void ___Unwind_Resume_or_Rethrow
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_Resume_or_Rethrow(param_1,&uStack_44,param_3,0,param_3);
  return;
}



/* Address 000168c4 | ___Unwind_ForcedUnwind | bytes 36 */

void ___Unwind_ForcedUnwind(void)

{
  __gnu_Unwind_ForcedUnwind();
  return;
}



/* Address 000168e8 | ___Unwind_Backtrace | bytes 36 */

void ___Unwind_Backtrace(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_Backtrace(param_1,param_2,&uStack_44,0,param_3);
  return;
}



/* Address 0001690c | __gnu_unwind_execute | bytes 1800 */

/* WARNING: Type propagation algorithm not settling */

undefined4 __gnu_unwind_execute(undefined4 param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  int local_24;
  
  bVar7 = false;
LAB_00016924:
  do {
    if ((char)param_2[2] == '\0') {
      if (*(char *)((int)param_2 + 9) == '\0') goto LAB_0001693c;
      *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
      uVar6 = *(uint *)param_2[1];
      *(undefined1 *)(param_2 + 2) = 3;
      param_2[1] = (uint)((uint *)param_2[1] + 1);
    }
    else {
      uVar6 = *param_2;
      *(char *)(param_2 + 2) = (char)param_2[2] + -1;
    }
    uVar2 = uVar6 >> 0x18;
    uVar6 = uVar6 << 8;
    *param_2 = uVar6;
    if (uVar2 == 0xb0) {
LAB_0001693c:
      if (bVar7) {
        return 0;
      }
      _Unwind_VRS_Get(param_1,0,0xe,0,&local_24);
      _Unwind_VRS_Set(param_1,0,0xf,0,&local_24);
      return 0;
    }
    if ((uVar2 & 0x80) == 0) {
      _Unwind_VRS_Get(param_1,0,0xd,0,&local_24);
      iVar1 = (uVar2 & 0x3f) * 4 + 4;
      if ((uVar2 & 0x40) != 0) {
        iVar1 = -iVar1;
      }
      local_24 = local_24 + iVar1;
LAB_00016a28:
      _Unwind_VRS_Set(param_1,0,0xd,0,&local_24);
      goto LAB_00016924;
    }
    uVar5 = uVar2 & 0xf0;
    if (uVar5 == 0x80) {
      uVar2 = uVar2 << 8;
      if ((char)param_2[2] == '\0') {
        if (*(char *)((int)param_2 + 9) != '\0') {
          *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
          uVar6 = *(uint *)param_2[1];
          *(undefined1 *)(param_2 + 2) = 3;
          param_2[1] = (uint)((uint *)param_2[1] + 1);
          goto LAB_00016bf4;
        }
        uVar5 = 0xb0;
      }
      else {
        *(char *)(param_2 + 2) = (char)param_2[2] + -1;
LAB_00016bf4:
        uVar5 = uVar6 >> 0x18;
        *param_2 = uVar6 << 8;
      }
      if ((uVar5 | uVar2) == 0x8000) {
        return 9;
      }
      iVar1 = _Unwind_VRS_Pop(param_1,0,(uVar5 | uVar2 & 0xfff) << 4,0);
      if (iVar1 != 0) {
        return 9;
      }
      if ((uVar2 & 0x800) != 0) {
        bVar7 = true;
      }
      goto LAB_00016924;
    }
    if (uVar5 == 0x90) {
      if ((uVar2 & 0xd) == 0xd) {
        return 9;
      }
      _Unwind_VRS_Get(param_1,0,uVar2 & 0xf,0,&local_24);
      goto LAB_00016a28;
    }
    if (uVar5 == 0xa0) {
      uVar5 = 0xff0 >> (~uVar2 & 7) & 0xff0;
      if ((uVar2 & 8) != 0) {
        uVar5 = uVar5 | 0x4000;
      }
      uVar3 = 0;
LAB_00016ab4:
      iVar1 = _Unwind_VRS_Pop(param_1,uVar3,uVar5,uVar3);
    }
    else {
      if (uVar5 == 0xb0) {
        if (uVar2 == 0xb1) {
          if ((char)param_2[2] == '\0') {
            if (*(char *)((int)param_2 + 9) == '\0') {
              return 9;
            }
            *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
            uVar6 = *(uint *)param_2[1];
            *(undefined1 *)(param_2 + 2) = 3;
            param_2[1] = (uint)((uint *)param_2[1] + 1);
          }
          else {
            *(char *)(param_2 + 2) = (char)param_2[2] + -1;
          }
          uVar5 = uVar6 >> 0x18;
          *param_2 = uVar6 << 8;
          if (uVar5 == 0) {
            return 9;
          }
          uVar3 = 0;
          if ((uVar5 & 0xf0) != 0) {
            return 9;
          }
          goto LAB_00016ab4;
        }
        if (uVar2 != 0xb2) {
          if (uVar2 != 0xb3) {
            if ((uVar2 & 0xfc) == 0xb4) {
              iVar1 = _Unwind_VRS_Pop(param_1,2,(uVar2 & 3) + 1 | 0x40000,2);
            }
            else {
              iVar1 = _Unwind_VRS_Pop(param_1,1,(uVar2 & 7) + 1 | 0x80000,1);
            }
            goto joined_r0x00016ec0;
          }
          if ((char)param_2[2] == '\0') {
            if (*(char *)((int)param_2 + 9) != '\0') {
              *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
              uVar6 = *(uint *)param_2[1];
              *(undefined1 *)(param_2 + 2) = 3;
              param_2[1] = (uint)((uint *)param_2[1] + 1);
              goto LAB_00016f60;
            }
            uVar5 = 0xb0001;
          }
          else {
            *(char *)(param_2 + 2) = (char)param_2[2] + -1;
LAB_00016f60:
            *param_2 = uVar6 << 8;
            uVar5 = (uVar6 >> 0x18 & 0xf) + 1 | (uVar6 >> 0x18 & 0xf0) << 0xc;
          }
          uVar3 = 1;
          goto LAB_00016ab4;
        }
        _Unwind_VRS_Get(param_1,0,0xd,0,&local_24);
        if ((char)param_2[2] == '\0') {
          if (*(char *)((int)param_2 + 9) == '\0') {
            cVar4 = '\0';
            uVar2 = 0xb0;
            goto LAB_00016d40;
          }
          *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
          uVar6 = *(uint *)param_2[1];
          *(undefined1 *)(param_2 + 2) = 3;
          param_2[1] = (uint)((uint *)param_2[1] + 1);
        }
        else {
          uVar6 = *param_2;
          *(char *)(param_2 + 2) = (char)param_2[2] + -1;
        }
        uVar2 = uVar6 >> 0x18;
        *param_2 = uVar6 << 8;
        if ((uVar2 & 0x80) != 0) {
          cVar4 = (char)param_2[2];
LAB_00016d40:
          uVar6 = 2;
LAB_00016d48:
          local_24 = local_24 + ((uVar2 & 0x7f) << (uVar6 & 0xff));
          uVar6 = uVar6 + 7;
          if (cVar4 == '\0') break;
          uVar5 = *param_2;
          *(char *)(param_2 + 2) = cVar4 + -1;
          goto LAB_00016d8c;
        }
        uVar6 = 2;
LAB_00016de8:
        local_24 = local_24 + 0x204 + ((uVar2 & 0x7f) << (uVar6 & 0xff));
        _Unwind_VRS_Set(param_1,0,0xd,0,&local_24);
        goto LAB_00016924;
      }
      if (uVar5 == 0xc0) {
        if (uVar2 == 0xc6) {
          if ((char)param_2[2] == '\0') {
            if (*(char *)((int)param_2 + 9) != '\0') {
              *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
              uVar6 = *(uint *)param_2[1];
              *(undefined1 *)(param_2 + 2) = 3;
              param_2[1] = (uint)((uint *)param_2[1] + 1);
              goto LAB_00016f88;
            }
            uVar5 = 0xb0001;
          }
          else {
            *(char *)(param_2 + 2) = (char)param_2[2] + -1;
LAB_00016f88:
            *param_2 = uVar6 << 8;
            uVar5 = (uVar6 >> 0x18 & 0xf) + 1 | (uVar6 >> 0x18 & 0xf0) << 0xc;
          }
          uVar3 = 3;
          goto LAB_00016ab4;
        }
        if (uVar2 == 199) {
          if ((char)param_2[2] == '\0') {
            if (*(char *)((int)param_2 + 9) == '\0') {
              return 9;
            }
            *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
            uVar6 = *(uint *)param_2[1];
            *(undefined1 *)(param_2 + 2) = 3;
            param_2[1] = (uint)((uint *)param_2[1] + 1);
          }
          else {
            *(char *)(param_2 + 2) = (char)param_2[2] + -1;
          }
          *param_2 = uVar6 << 8;
          if (uVar6 >> 0x18 == 0) {
            return 9;
          }
          if ((uVar6 >> 0x18 & 0xf0) != 0) {
            return 9;
          }
          iVar1 = _Unwind_VRS_Pop(param_1,4);
        }
        else if ((uVar2 & 0xf8) == 0xc0) {
          iVar1 = _Unwind_VRS_Pop(param_1,3,(uVar2 & 0xf) + 1 | 0xa0000,3);
        }
        else {
          if (uVar2 == 200) {
            if ((char)param_2[2] == '\0') {
              if (*(char *)((int)param_2 + 9) == '\0') {
                uVar6 = 0xc0001;
                goto LAB_00016bd0;
              }
              *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
              uVar6 = *(uint *)param_2[1];
              *(undefined1 *)(param_2 + 2) = 3;
              param_2[1] = (uint)((uint *)param_2[1] + 1);
            }
            else {
              *(char *)(param_2 + 2) = (char)param_2[2] + -1;
            }
            *param_2 = uVar6 << 8;
            uVar6 = (uVar6 >> 0x18 & 0xf) + 1 | ((uVar6 >> 0x18 & 0xf0) + 0x10) * 0x1000;
          }
          else {
            if (uVar2 != 0xc9) {
              return 9;
            }
            if ((char)param_2[2] == '\0') {
              if (*(char *)((int)param_2 + 9) == '\0') {
                uVar6 = 0xb0001;
                goto LAB_00016bd0;
              }
              *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
              uVar6 = *(uint *)param_2[1];
              *(undefined1 *)(param_2 + 2) = 3;
              param_2[1] = (uint)((uint *)param_2[1] + 1);
            }
            else {
              *(char *)(param_2 + 2) = (char)param_2[2] + -1;
            }
            *param_2 = uVar6 << 8;
            uVar6 = (uVar6 >> 0x18 & 0xf) + 1 | (uVar6 >> 0x18 & 0xf0) << 0xc;
          }
LAB_00016bd0:
          iVar1 = _Unwind_VRS_Pop(param_1,1,uVar6,5);
        }
      }
      else {
        if ((uVar2 & 0xf8) != 0xd0) {
          return 9;
        }
        iVar1 = _Unwind_VRS_Pop(param_1,1,(uVar2 & 7) + 1 | 0x80000,5);
      }
    }
joined_r0x00016ec0:
    if (iVar1 != 0) {
      return 9;
    }
  } while( true );
  uVar2 = 0xb0;
  if (*(char *)((int)param_2 + 9) != '\0') {
    *(char *)((int)param_2 + 9) = *(char *)((int)param_2 + 9) + -1;
    uVar5 = *(uint *)param_2[1];
    *(undefined1 *)(param_2 + 2) = 3;
    param_2[1] = (uint)((uint *)param_2[1] + 1);
LAB_00016d8c:
    uVar2 = uVar5 >> 0x18;
    *param_2 = uVar5 << 8;
    if ((uVar2 & 0x80) != 0) {
      cVar4 = (char)param_2[2];
      goto LAB_00016d48;
    }
    goto LAB_00016de8;
  }
  goto LAB_00016d48;
}



/* Address 00017014 | __gnu_unwind_frame | bytes 64 */

void __gnu_unwind_frame(int param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_14;
  int iStack_10;
  undefined1 local_c;
  undefined1 local_b;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  iStack_10 = iVar1 + 8;
  local_c = 3;
  local_b = *(undefined1 *)(iVar1 + 7);
  iStack_14 = *(int *)(iVar1 + 4) << 8;
  __gnu_unwind_execute(param_2,&iStack_14);
  return;
}



/* Address 00017054 | _Unwind_GetRegionStart | bytes 48 */

undefined4 _Unwind_GetRegionStart(void)

{
  int local_c;
  
  _Unwind_VRS_Get();
  return *(undefined4 *)(local_c + 0x48);
}



/* Address 00017084 | _Unwind_GetLanguageSpecificData | bytes 60 */

int _Unwind_GetLanguageSpecificData(void)

{
  int local_c;
  
  _Unwind_VRS_Get();
  return *(int *)(local_c + 0x4c) + (uint)*(byte *)(*(int *)(local_c + 0x4c) + 7) * 4 + 8;
}



/* Address 000170c0 | _Unwind_GetDataRelBase | bytes 8 */

void _Unwind_GetDataRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Address 000170c8 | _Unwind_GetTextRelBase | bytes 8 */

void _Unwind_GetTextRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Address 000170d0 | _fini | bytes 8 */

void _fini(void)

{
  return;
}



/* Address 0001a000 | realloc | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a004 | __cxa_finalize | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a008 | pthread_mutex_lock | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a00c | strstr | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a010 | _ITM_deregisterTMCloneTable | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a014 | close | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a018 | strchr | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a01c | calloc | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a020 | strncmp | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a024 | __get_errno_ptr | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __get_errno_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a028 | free | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a02c | abort | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a030 | unlink | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a034 | pthread_getspecific | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a038 | memcpy | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a03c | __stack_chk_fail | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a040 | pthread_mutex_unlock | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a044 | lstat | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int lstat(char *__file,stat *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a048 | fstat | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fstat(int __fd,stat *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a04c | SHA256_Init | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Init(SHA256_CTX *c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a050 | memset | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a058 | __cxa_begin_cleanup | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a05c | pthread_key_create | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a060 | __gnu_Unwind_Find_exidx | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a064 | pthread_cond_wait | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a068 | __cxa_type_match | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a06c | read | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a070 | shutdown | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int shutdown(int __fd,int __how)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a074 | pthread_once | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_once(pthread_once_t *__once_control,__init_routine *__init_routine)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a078 | pthread_cond_broadcast | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_broadcast(pthread_cond_t *__cond)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a07c | pthread_setspecific | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a080 | __deregister_frame_info | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __deregister_frame_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a084 | snprintf | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a088 | __register_frame_info | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __register_frame_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a08c | getpid | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a090 | dlsym | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void dlsym(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a094 | dup | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a098 | write | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a09c | SHA256_Final | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Final(uchar *md,SHA256_CTX *c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0a0 | pthread_join | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0a4 | pthread_create | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0a8 | memcmp | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0ac | _Jv_RegisterClasses | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void _Jv_RegisterClasses(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0b0 | SHA256_Update | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SHA256_Update(SHA256_CTX *c,void *data,size_t len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0b4 | open | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0b8 | strlen | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0bc | _ITM_registerTMCloneTable | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0c0 | strtol | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0c4 | nanosleep | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int nanosleep(timespec *__requested_time,timespec *__remaining)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0c8 | rename | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rename(char *__old,char *__new)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0cc | __cxa_call_unexpected | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0d0 | malloc | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Address 0001a0d4 | strcmp | bytes 1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


