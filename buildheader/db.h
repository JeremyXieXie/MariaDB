#ifndef _DB_H
#define _DB_H
/* This code generated by make_db_h.   Copyright (c) 2007 Tokutek */
#include <sys/types.h>
#if defined(__cplusplus)
extern "C" {
#endif
#ifndef _TOKUDB_WRAP_H
#define DB_VERSION_STRING "Tokutek: TokuDB"
#else
#define DB_VERSION_STRING "Tokutek: TokuDB (wrapped bdb)"
#endif
typedef struct __toku_db_btree_stat DB_BTREE_STAT;
typedef struct __toku_db_env DB_ENV;
typedef struct __toku_db_key_range DB_KEY_RANGE;
typedef struct __toku_db_lsn DB_LSN;
typedef struct __toku_db DB;
typedef struct __toku_db_txn DB_TXN;
typedef struct __toku_db_txn_active DB_TXN_ACTIVE;
typedef struct __toku_db_txn_stat DB_TXN_STAT;
typedef struct __toku_dbc DBC;
typedef struct __toku_dbt DBT;
typedef enum {
 DB_BTREE=1
} DBTYPE;
typedef enum { /* This appears to be a mysql-specific addition to the api. */ 
 DB_NOTICE_LOGFILE_CHANGED=0
} db_notices;
#define DB_VERB_DEADLOCK 2
#define DB_VERB_RECOVERY 4
#define DB_VERB_REPLICATION 8
#define DB_VERB_WAITSFOR 16
#define DB_DBT_MALLOC 4
#define DB_DBT_REALLOC 16
#define DB_DBT_USERMEM 32
#define DB_DBT_DUPOK 64
#define DB_ARCH_ABS 1
#define DB_ARCH_LOG 4
#define DB_CREATE 1
#define DB_PRIVATE 262144
#define DB_RDONLY 16
#define DB_RECOVER 32
#define DB_THREAD 64
#define DB_TXN_NOSYNC 256
#define DB_LOCK_DEFAULT 1
#define DB_LOCK_OLDEST 6
#define DB_LOCK_RANDOM 7
#define DB_DUP 2
#define DB_NOOVERWRITE 23
#define DB_INIT_LOCK 4096
#define DB_INIT_LOG 8192
#define DB_INIT_MPOOL 16384
#define DB_INIT_TXN 32768
/* in wrap mode, top-level function txn_begin is renamed, but the field isn't renamed, so we have to hack it here.*/
#ifdef _TOKUDB_WRAP_H
#undef txn_begin
#endif
struct __toku_db_btree_stat {
  char __toku_dummy0[12];
  u_int32_t bt_nkeys; /* 32-bit offset=12 size=4, 64=bit offset=12 size=4 */
  u_int32_t bt_ndata; /* 32-bit offset=16 size=4, 64=bit offset=16 size=4 */
  char __toku_dummy1[60];  /* Padding at the end */ 
};
struct __toku_db_env {
  struct __toku_db_env_internal *i;
  void* __toku_dummy0[45];
  char __toku_dummy1[64];
  int  (*close) (DB_ENV *, u_int32_t); /* 32-bit offset=248 size=4, 64=bit offset=432 size=8 */
  void* __toku_dummy2[2];
  void (*err) (const DB_ENV *, int, const char *, ...); /* 32-bit offset=260 size=4, 64=bit offset=456 size=8 */
  void* __toku_dummy3[1];
  int  (*open) (DB_ENV *, const char *, u_int32_t, int); /* 32-bit offset=268 size=4, 64=bit offset=472 size=8 */
  void* __toku_dummy4[1];
  int  (*set_data_dir) (DB_ENV *, const char *); /* 32-bit offset=276 size=4, 64=bit offset=488 size=8 */
  void* __toku_dummy5[3];
  void (*set_errcall) (DB_ENV *, void (*)(const char *, char *)); /* 32-bit offset=292 size=4, 64=bit offset=520 size=8 */
  void* __toku_dummy6[1];
  void (*set_errpfx) (DB_ENV *, const char *); /* 32-bit offset=300 size=4, 64=bit offset=536 size=8 */
  void* __toku_dummy7[1];
  int  (*set_flags) (DB_ENV *, u_int32_t, int); /* 32-bit offset=308 size=4, 64=bit offset=552 size=8 */
  void (*set_noticecall) (DB_ENV *, void (*)(DB_ENV *, db_notices)); /* 32-bit offset=312 size=4, 64=bit offset=560 size=8 */
  void* __toku_dummy8[4];
  int  (*set_tmp_dir) (DB_ENV *, const char *); /* 32-bit offset=332 size=4, 64=bit offset=600 size=8 */
  int  (*set_verbose) (DB_ENV *, u_int32_t, int); /* 32-bit offset=336 size=4, 64=bit offset=608 size=8 */
  void* __toku_dummy9[1];
  int  (*set_lg_bsize) (DB_ENV *, u_int32_t); /* 32-bit offset=344 size=4, 64=bit offset=624 size=8 */
  int  (*set_lg_dir) (DB_ENV *, const char *); /* 32-bit offset=348 size=4, 64=bit offset=632 size=8 */
  int  (*set_lg_max) (DB_ENV *, u_int32_t); /* 32-bit offset=352 size=4, 64=bit offset=640 size=8 */
  void* __toku_dummy10[1];
  int  (*log_archive) (DB_ENV *, char **[], u_int32_t); /* 32-bit offset=360 size=4, 64=bit offset=656 size=8 */
  void* __toku_dummy11[2];
  int  (*log_flush) (DB_ENV *, const DB_LSN *); /* 32-bit offset=372 size=4, 64=bit offset=680 size=8 */
  void* __toku_dummy12[4];
  int  (*set_lk_detect) (DB_ENV *, u_int32_t); /* 32-bit offset=392 size=4, 64=bit offset=720 size=8 */
  int  (*set_lk_max) (DB_ENV *, u_int32_t); /* 32-bit offset=396 size=4, 64=bit offset=728 size=8 */
  void* __toku_dummy13[15];
  int  (*set_cachesize) (DB_ENV *, u_int32_t, u_int32_t, int); /* 32-bit offset=460 size=4, 64=bit offset=856 size=8 */
  void* __toku_dummy14[21];
  int  (*txn_begin) (DB_ENV *, DB_TXN *, DB_TXN **, u_int32_t); /* 32-bit offset=548 size=4, 64=bit offset=1032 size=8 */
  int  (*txn_checkpoint) (DB_ENV *, u_int32_t, u_int32_t, u_int32_t); /* 32-bit offset=552 size=4, 64=bit offset=1040 size=8 */
  void* __toku_dummy15[2];
  int  (*txn_stat) (DB_ENV *, DB_TXN_STAT **, u_int32_t); /* 32-bit offset=564 size=4, 64=bit offset=1064 size=8 */
  void* __toku_dummy16[2]; /* Padding at the end */ 
  char __toku_dummy17[8];  /* Padding at the end */ 
};
struct __toku_db_key_range {
  double less; /* 32-bit offset=0 size=8, 64=bit offset=0 size=8 */
  double equal; /* 32-bit offset=8 size=8, 64=bit offset=8 size=8 */
  double greater; /* 32-bit offset=16 size=8, 64=bit offset=16 size=8 */
  void* __toku_dummy0[128]; /* Padding at the end */ 
  char __toku_dummy1[48];  /* Padding at the end */ 
};
struct __toku_db_lsn {
  char __toku_dummy0[8];  /* Padding at the end */ 
};
struct __toku_db {
  struct __toku_db_internal *i;
  void* __toku_dummy0[3];
  void *app_private; /* 32-bit offset=16 size=4, 64=bit offset=32 size=8 */
  void* __toku_dummy1[39];
  char __toku_dummy2[96];
  int (*close) (DB*, u_int32_t); /* 32-bit offset=272 size=4, 64=bit offset=448 size=8 */
  int (*cursor) (DB *, DB_TXN *, DBC **, u_int32_t); /* 32-bit offset=276 size=4, 64=bit offset=456 size=8 */
  int (*del) (DB *, DB_TXN *, DBT *, u_int32_t); /* 32-bit offset=280 size=4, 64=bit offset=464 size=8 */
  void* __toku_dummy3[3];
  int (*get) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t); /* 32-bit offset=296 size=4, 64=bit offset=496 size=8 */
  void* __toku_dummy4[4];
  int (*key_range) (DB *, DB_TXN *, DBT *, DB_KEY_RANGE *, u_int32_t); /* 32-bit offset=316 size=4, 64=bit offset=536 size=8 */
  int (*open) (DB *, DB_TXN *, const char *, const char *, DBTYPE, u_int32_t, int); /* 32-bit offset=320 size=4, 64=bit offset=544 size=8 */
  int (*put) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t); /* 32-bit offset=324 size=4, 64=bit offset=552 size=8 */
  int (*remove) (DB *, const char *, const char *, u_int32_t); /* 32-bit offset=328 size=4, 64=bit offset=560 size=8 */
  int (*rename) (DB *, const char *, const char *, const char *, u_int32_t); /* 32-bit offset=332 size=4, 64=bit offset=568 size=8 */
  void* __toku_dummy5[11];
  int (*set_flags) (DB *, u_int32_t); /* 32-bit offset=380 size=4, 64=bit offset=664 size=8 */
  void* __toku_dummy6[3];
  int (*stat) (DB *, void *, u_int32_t); /* 32-bit offset=396 size=4, 64=bit offset=696 size=8 */
  void* __toku_dummy7[3];
  int (*set_bt_compare) (DB *, int (*)(DB *, const DBT *, const DBT *)); /* 32-bit offset=412 size=4, 64=bit offset=728 size=8 */
  void* __toku_dummy8[15]; /* Padding at the end */ 
  char __toku_dummy9[8];  /* Padding at the end */ 
};
struct __toku_db_txn_active {
  u_int32_t txnid; /* 32-bit offset=0 size=4, 64=bit offset=0 size=4 */
  char __toku_dummy0[4];
  DB_LSN lsn; /* 32-bit offset=8 size=8, 64=bit offset=8 size=8 */
};
struct __toku_db_txn {
  struct __toku_db_txn_internal *i;
  void* __toku_dummy0[13];
  char __toku_dummy1[24];
  int (*commit) (DB_TXN*, u_int32_t); /* 32-bit offset=80 size=4, 64=bit offset=136 size=8 */
  void* __toku_dummy2[1];
  u_int32_t (*id) (DB_TXN *); /* 32-bit offset=88 size=4, 64=bit offset=152 size=8 */
  void* __toku_dummy3[3]; /* Padding at the end */ 
};
struct __toku_db_txn_stat {
  void* __toku_dummy0[1];
  char __toku_dummy1[28];
  u_int32_t st_nactive; /* 32-bit offset=32 size=4, 64=bit offset=36 size=4 */
  char __toku_dummy2[8];
  DB_TXN_ACTIVE *st_txnarray; /* 32-bit offset=44 size=4, 64=bit offset=48 size=8 */
  void* __toku_dummy3[1]; /* Padding at the end */ 
  char __toku_dummy4[8];  /* Padding at the end */ 
};
struct __toku_dbc {
  struct __toku_dbc_internal *i;
  void* __toku_dummy0[24];
  char __toku_dummy1[104];
  int (*c_close) (DBC *); /* 32-bit offset=204 size=4, 64=bit offset=304 size=8 */
  void* __toku_dummy2[1];
  int (*c_del) (DBC *, u_int32_t); /* 32-bit offset=212 size=4, 64=bit offset=320 size=8 */
  void* __toku_dummy3[1];
  int (*c_get) (DBC *, DBT *, DBT *, u_int32_t); /* 32-bit offset=220 size=4, 64=bit offset=336 size=8 */
  void* __toku_dummy4[11]; /* Padding at the end */ 
};
struct __toku_dbt {
  void*data; /* 32-bit offset=0 size=4, 64=bit offset=0 size=8 */
  u_int32_t size; /* 32-bit offset=4 size=4, 64=bit offset=8 size=4 */
  u_int32_t ulen; /* 32-bit offset=8 size=4, 64=bit offset=12 size=4 */
  char __toku_dummy0[8];
  void*app_private; /* 32-bit offset=20 size=4, 64=bit offset=24 size=8 */
  u_int32_t flags; /* 32-bit offset=24 size=4, 64=bit offset=32 size=4 */
  /* 4 more bytes of alignment in the 64-bit case. */
};
#ifdef _TOKUDB_WRAP_H
#define txn_begin txn_begin_tokudb
#endif
#if defined(__cplusplus)
}
#endif
#endif
