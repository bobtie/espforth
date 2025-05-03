// # 0 "espforth.c"
// # 0 "<built-in>"
// # 0 "<command-line>"
// # 1 "/usr/include/stdc-predef.h" 1 3 4
// # 0 "<command-line>" 2
// # 1 "espforth.c"

// # 1 "/usr/include/assert.h" 1 3 4
// # 35 "/usr/include/assert.h" 3 4
// # 1 "/usr/include/features.h" 1 3 4
// # 394 "/usr/include/features.h" 3 4
// # 1 "/usr/include/features-time64.h" 1 3 4
// # 20 "/usr/include/features-time64.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 21 "/usr/include/features-time64.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
// # 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
// # 22 "/usr/include/features-time64.h" 2 3 4
// # 395 "/usr/include/features.h" 2 3 4
// # 502 "/usr/include/features.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
// # 576 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 577 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
// # 578 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
// # 503 "/usr/include/features.h" 2 3 4
// # 526 "/usr/include/features.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
// # 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
// # 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
// # 527 "/usr/include/features.h" 2 3 4
// # 36 "/usr/include/assert.h" 2 3 4
// # 66 "/usr/include/assert.h" 3 4

// # 69 "/usr/include/assert.h" 3 4
// extern void __assert_fail (const char *__assertion, const char *__file,
//       unsigned int __line, const char *__function)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

// extern void __assert_perror_fail (int __errnum, const char *__file,
//       unsigned int __line, const char *__function)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

// extern void __assert (const char *__assertion, const char *__file, int __line)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

// # 4 "espforth.c" 2
// # 1 "/usr/include/stdio.h" 1 3 4
// # 28 "/usr/include/stdio.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
// # 29 "/usr/include/stdio.h" 2 3 4

// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 1 3 4
// # 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3 4
// typedef long unsigned int size_t;
// # 35 "/usr/include/stdio.h" 2 3 4

// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h" 1 3 4
// # 40 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h" 3 4
// typedef __builtin_va_list __gnuc_va_list;
// # 38 "/usr/include/stdio.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
// # 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
// # 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
// # 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4

// typedef unsigned char __u_char;
// typedef unsigned short int __u_short;
// typedef unsigned int __u_int;
// typedef unsigned long int __u_long;

// typedef signed char __int8_t;
// typedef unsigned char __uint8_t;
// typedef signed short int __int16_t;
// typedef unsigned short int __uint16_t;
// typedef signed int __int32_t;
// typedef unsigned int __uint32_t;

// typedef signed long int __int64_t;
// typedef unsigned long int __uint64_t;

// typedef __int8_t __int_least8_t;
// typedef __uint8_t __uint_least8_t;
// typedef __int16_t __int_least16_t;
// typedef __uint16_t __uint_least16_t;
// typedef __int32_t __int_least32_t;
// typedef __uint32_t __uint_least32_t;
// typedef __int64_t __int_least64_t;
// typedef __uint64_t __uint_least64_t;

// typedef long int __quad_t;
// typedef unsigned long int __u_quad_t;

// typedef long int __intmax_t;
// typedef unsigned long int __uintmax_t;
// # 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
// # 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
// # 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4

// typedef unsigned long int __dev_t;
// typedef unsigned int __uid_t;
// typedef unsigned int __gid_t;
// typedef unsigned long int __ino_t;
// typedef unsigned long int __ino64_t;
// typedef unsigned int __mode_t;
// typedef unsigned long int __nlink_t;
// typedef long int __off_t;
// typedef long int __off64_t;
// typedef int __pid_t;
// typedef struct { int __val[2]; } __fsid_t;
// typedef long int __clock_t;
// typedef unsigned long int __rlim_t;
// typedef unsigned long int __rlim64_t;
// typedef unsigned int __id_t;
// typedef long int __time_t;
// typedef unsigned int __useconds_t;
// typedef long int __suseconds_t;
// typedef long int __suseconds64_t;

// typedef int __daddr_t;
// typedef int __key_t;

// typedef int __clockid_t;

// typedef void * __timer_t;

// typedef long int __blksize_t;

// typedef long int __blkcnt_t;
// typedef long int __blkcnt64_t;

// typedef unsigned long int __fsblkcnt_t;
// typedef unsigned long int __fsblkcnt64_t;

// typedef unsigned long int __fsfilcnt_t;
// typedef unsigned long int __fsfilcnt64_t;

// typedef long int __fsword_t;

// typedef long int __ssize_t;

// typedef long int __syscall_slong_t;

// typedef unsigned long int __syscall_ulong_t;

// typedef __off64_t __loff_t;
// typedef char *__caddr_t;

// typedef long int __intptr_t;

// typedef unsigned int __socklen_t;

// typedef int __sig_atomic_t;
// # 40 "/usr/include/stdio.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 1 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4
// # 13 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4
// typedef struct
// {
//   int __count;
//   union
//   {
//     unsigned int __wch;
//     char __wchb[4];
//   } __value;
// } __mbstate_t;
// # 6 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 2 3 4

// typedef struct _G_fpos_t
// {
//   __off_t __pos;
//   __mbstate_t __state;
// } __fpos_t;
// # 41 "/usr/include/stdio.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 1 3 4
// # 10 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
// typedef struct _G_fpos64_t
// {
//   __off64_t __pos;
//   __mbstate_t __state;
// } __fpos64_t;
// # 42 "/usr/include/stdio.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4

// struct _IO_FILE;
// typedef struct _IO_FILE __FILE;
// # 43 "/usr/include/stdio.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4

// struct _IO_FILE;

// typedef struct _IO_FILE FILE;
// # 44 "/usr/include/stdio.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 1 3 4
// # 35 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
// struct _IO_FILE;
// struct _IO_marker;
// struct _IO_codecvt;
// struct _IO_wide_data;

// typedef void _IO_lock_t;

// struct _IO_FILE
// {
//   int _flags;

//   char *_IO_read_ptr;
//   char *_IO_read_end;
//   char *_IO_read_base;
//   char *_IO_write_base;
//   char *_IO_write_ptr;
//   char *_IO_write_end;
//   char *_IO_buf_base;
//   char *_IO_buf_end;

//   char *_IO_save_base;
//   char *_IO_backup_base;
//   char *_IO_save_end;

//   struct _IO_marker *_markers;

//   struct _IO_FILE *_chain;

//   int _fileno;
//   int _flags2;
//   __off_t _old_offset;

//   unsigned short _cur_column;
//   signed char _vtable_offset;
//   char _shortbuf[1];

//   _IO_lock_t *_lock;

//   __off64_t _offset;

//   struct _IO_codecvt *_codecvt;
//   struct _IO_wide_data *_wide_data;
//   struct _IO_FILE *_freeres_list;
//   void *_freeres_buf;
//   size_t __pad5;
//   int _mode;

//   char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
// };
// # 45 "/usr/include/stdio.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h" 1 3 4
// # 27 "/usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h" 3 4
// typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
//                                           size_t __nbytes);

// typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
//                                            size_t __nbytes);

// typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);

// typedef int cookie_close_function_t (void *__cookie);

// typedef struct _IO_cookie_io_functions_t
// {
//   cookie_read_function_t *read;
//   cookie_write_function_t *write;
//   cookie_seek_function_t *seek;
//   cookie_close_function_t *close;
// } cookie_io_functions_t;
// # 48 "/usr/include/stdio.h" 2 3 4

// typedef __gnuc_va_list va_list;
// # 64 "/usr/include/stdio.h" 3 4
// typedef __off_t off_t;
// # 78 "/usr/include/stdio.h" 3 4
// typedef __ssize_t ssize_t;

// typedef __fpos_t fpos_t;
// # 129 "/usr/include/stdio.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
// # 130 "/usr/include/stdio.h" 2 3 4
// # 149 "/usr/include/stdio.h" 3 4
// extern FILE *stdin;
// extern FILE *stdout;
// extern FILE *stderr;

// extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

// extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));

// extern int renameat (int __oldfd, const char *__old, int __newfd,
//        const char *__new) __attribute__ ((__nothrow__ , __leaf__));
// # 184 "/usr/include/stdio.h" 3 4
// extern int fclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));
// # 194 "/usr/include/stdio.h" 3 4
// extern FILE *tmpfile (void)
//   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
// # 211 "/usr/include/stdio.h" 3 4
// extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
// # 228 "/usr/include/stdio.h" 3 4
// extern char *tempnam (const char *__dir, const char *__pfx)
//    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));

// extern int fflush (FILE *__stream);
// # 245 "/usr/include/stdio.h" 3 4
// extern int fflush_unlocked (FILE *__stream);
// # 264 "/usr/include/stdio.h" 3 4
// extern FILE *fopen (const char *__restrict __filename,
//       const char *__restrict __modes)
//   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;

// extern FILE *freopen (const char *__restrict __filename,
//         const char *__restrict __modes,
//         FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));
// # 299 "/usr/include/stdio.h" 3 4
// extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
//   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;

// extern FILE *fopencookie (void *__restrict __magic_cookie,
//      const char *__restrict __modes,
//      cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__ , __leaf__))
//   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;

// extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
//   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;

// extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
//   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
// # 334 "/usr/include/stdio.h" 3 4
// extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__))
//   __attribute__ ((__nonnull__ (1)));

// extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
//       int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
//          size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int fprintf (FILE *__restrict __stream,
//       const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));

// extern int printf (const char *__restrict __format, ...);

// extern int sprintf (char *__restrict __s,
//       const char *__restrict __format, ...) __attribute__ ((__nothrow__));

// extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
//        __gnuc_va_list __arg) __attribute__ ((__nonnull__ (1)));

// extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

// extern int vsprintf (char *__restrict __s, const char *__restrict __format,
//        __gnuc_va_list __arg) __attribute__ ((__nothrow__));

// extern int snprintf (char *__restrict __s, size_t __maxlen,
//        const char *__restrict __format, ...)
//      __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

// extern int vsnprintf (char *__restrict __s, size_t __maxlen,
//         const char *__restrict __format, __gnuc_va_list __arg)
//      __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

// extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
//         __gnuc_va_list __arg)
//      __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
// extern int __asprintf (char **__restrict __ptr,
//          const char *__restrict __fmt, ...)
//      __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
// extern int asprintf (char **__restrict __ptr,
//        const char *__restrict __fmt, ...)
//      __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;

// extern int vdprintf (int __fd, const char *__restrict __fmt,
//        __gnuc_va_list __arg)
//      __attribute__ ((__format__ (__printf__, 2, 0)));
// extern int dprintf (int __fd, const char *__restrict __fmt, ...)
//      __attribute__ ((__format__ (__printf__, 2, 3)));

// extern int fscanf (FILE *__restrict __stream,
//      const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));

// extern int scanf (const char *__restrict __format, ...) ;

// extern int sscanf (const char *__restrict __s,
//      const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));

// # 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
// # 119 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
// # 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
// # 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
// # 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
// # 438 "/usr/include/stdio.h" 2 3 4
// # 463 "/usr/include/stdio.h" 3 4
// extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

//                                 __attribute__ ((__nonnull__ (1)));
// extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
//                               ;
// extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

//                       ;
// # 490 "/usr/include/stdio.h" 3 4
// extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
//       __gnuc_va_list __arg)
//      __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));

// extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
//      __attribute__ ((__format__ (__scanf__, 1, 0))) ;

// extern int vsscanf (const char *__restrict __s,
//       const char *__restrict __format, __gnuc_va_list __arg)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
// # 540 "/usr/include/stdio.h" 3 4
// extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")

//      __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));
// extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

//      __attribute__ ((__format__ (__scanf__, 1, 0))) ;
// extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))

//      __attribute__ ((__format__ (__scanf__, 2, 0)));
// # 575 "/usr/include/stdio.h" 3 4
// extern int fgetc (FILE *__stream) __attribute__ ((__nonnull__ (1)));
// extern int getc (FILE *__stream) __attribute__ ((__nonnull__ (1)));

// extern int getchar (void);

// extern int getc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
// extern int getchar_unlocked (void);
// # 600 "/usr/include/stdio.h" 3 4
// extern int fgetc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
// # 611 "/usr/include/stdio.h" 3 4
// extern int fputc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
// extern int putc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));

// extern int putchar (int __c);
// # 627 "/usr/include/stdio.h" 3 4
// extern int fputc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));

// extern int putc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
// extern int putchar_unlocked (int __c);

// extern int getw (FILE *__stream) __attribute__ ((__nonnull__ (1)));

// extern int putw (int __w, FILE *__stream) __attribute__ ((__nonnull__ (2)));

// extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
//      __attribute__ ((__access__ (__write_only__, 1, 2))) __attribute__ ((__nonnull__ (3)));
// # 694 "/usr/include/stdio.h" 3 4
// extern __ssize_t __getdelim (char **__restrict __lineptr,
//                              size_t *__restrict __n, int __delimiter,
//                              FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));
// extern __ssize_t getdelim (char **__restrict __lineptr,
//                            size_t *__restrict __n, int __delimiter,
//                            FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));

// extern __ssize_t getline (char **__restrict __lineptr,
//                           size_t *__restrict __n,
//                           FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));

// extern int fputs (const char *__restrict __s, FILE *__restrict __stream)
//   __attribute__ ((__nonnull__ (2)));

// extern int puts (const char *__s);

// extern int ungetc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));

// extern size_t fread (void *__restrict __ptr, size_t __size,
//        size_t __n, FILE *__restrict __stream)
//   __attribute__ ((__nonnull__ (4)));

// extern size_t fwrite (const void *__restrict __ptr, size_t __size,
//         size_t __n, FILE *__restrict __s) __attribute__ ((__nonnull__ (4)));
// # 766 "/usr/include/stdio.h" 3 4
// extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
//          size_t __n, FILE *__restrict __stream)
//   __attribute__ ((__nonnull__ (4)));
// extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
//           size_t __n, FILE *__restrict __stream)
//   __attribute__ ((__nonnull__ (4)));

// extern int fseek (FILE *__stream, long int __off, int __whence)
//   __attribute__ ((__nonnull__ (1)));

// extern long int ftell (FILE *__stream) __attribute__ ((__nonnull__ (1)));

// extern void rewind (FILE *__stream) __attribute__ ((__nonnull__ (1)));
// # 803 "/usr/include/stdio.h" 3 4
// extern int fseeko (FILE *__stream, __off_t __off, int __whence)
//   __attribute__ ((__nonnull__ (1)));

// extern __off_t ftello (FILE *__stream) __attribute__ ((__nonnull__ (1)));
// # 829 "/usr/include/stdio.h" 3 4
// extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos)
//   __attribute__ ((__nonnull__ (1)));

// extern int fsetpos (FILE *__stream, const fpos_t *__pos) __attribute__ ((__nonnull__ (1)));
// # 860 "/usr/include/stdio.h" 3 4
// extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern void perror (const char *__s) __attribute__ ((__cold__));

// extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 897 "/usr/include/stdio.h" 3 4
// extern int pclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));

// extern FILE *popen (const char *__command, const char *__modes)
//   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;

// extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
//   __attribute__ ((__access__ (__write_only__, 1)));
// # 941 "/usr/include/stdio.h" 3 4
// extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 959 "/usr/include/stdio.h" 3 4
// extern int __uflow (FILE *);
// extern int __overflow (FILE *, int);
// # 983 "/usr/include/stdio.h" 3 4

// # 5 "espforth.c" 2
// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h" 1 3 4
// # 6 "espforth.c" 2
// # 1 "/usr/include/stdlib.h" 1 3 4
// # 26 "/usr/include/stdlib.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
// # 27 "/usr/include/stdlib.h" 2 3 4

// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 1 3 4
// # 329 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3 4
// typedef int wchar_t;
// # 33 "/usr/include/stdlib.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
// # 41 "/usr/include/stdlib.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
// # 42 "/usr/include/stdlib.h" 2 3 4
// # 59 "/usr/include/stdlib.h" 3 4
// typedef struct
//   {
//     int quot;
//     int rem;
//   } div_t;

// typedef struct
//   {
//     long int quot;
//     long int rem;
//   } ldiv_t;

// __extension__ typedef struct
//   {
//     long long int quot;
//     long long int rem;
//   } lldiv_t;
// # 98 "/usr/include/stdlib.h" 3 4
// extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern double atof (const char *__nptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

// extern int atoi (const char *__nptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

// extern long int atol (const char *__nptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

// __extension__ extern long long int atoll (const char *__nptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

// extern double strtod (const char *__restrict __nptr,
//         char **__restrict __endptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern float strtof (const char *__restrict __nptr,
//        char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern long double strtold (const char *__restrict __nptr,
//        char **__restrict __endptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 177 "/usr/include/stdlib.h" 3 4
// extern long int strtol (const char *__restrict __nptr,
//    char **__restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern unsigned long int strtoul (const char *__restrict __nptr,
//       char **__restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// __extension__
// extern long long int strtoq (const char *__restrict __nptr,
//         char **__restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// __extension__
// extern unsigned long long int strtouq (const char *__restrict __nptr,
//            char **__restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// __extension__
// extern long long int strtoll (const char *__restrict __nptr,
//          char **__restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// __extension__
// extern unsigned long long int strtoull (const char *__restrict __nptr,
//      char **__restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 505 "/usr/include/stdlib.h" 3 4
// extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern long int a64l (const char *__s)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

// # 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
// # 27 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4

// typedef __u_char u_char;
// typedef __u_short u_short;
// typedef __u_int u_int;
// typedef __u_long u_long;
// typedef __quad_t quad_t;
// typedef __u_quad_t u_quad_t;
// typedef __fsid_t fsid_t;

// typedef __loff_t loff_t;

// typedef __ino_t ino_t;
// # 59 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
// typedef __dev_t dev_t;

// typedef __gid_t gid_t;

// typedef __mode_t mode_t;

// typedef __nlink_t nlink_t;

// typedef __uid_t uid_t;
// # 97 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
// typedef __pid_t pid_t;

// typedef __id_t id_t;
// # 114 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
// typedef __daddr_t daddr_t;
// typedef __caddr_t caddr_t;

// typedef __key_t key_t;

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 1 3 4

// typedef __clock_t clock_t;
// # 127 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 1 3 4

// typedef __clockid_t clockid_t;
// # 129 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 1 3 4
// # 10 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 3 4
// typedef __time_t time_t;
// # 130 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 1 3 4

// typedef __timer_t timer_t;
// # 131 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
// # 144 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 1 3 4
// # 145 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

// typedef unsigned long int ulong;
// typedef unsigned short int ushort;
// typedef unsigned int uint;

// # 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
// # 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
// typedef __int8_t int8_t;
// typedef __int16_t int16_t;
// typedef __int32_t int32_t;
// typedef __int64_t int64_t;
// # 156 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

// typedef __uint8_t u_int8_t;
// typedef __uint16_t u_int16_t;
// typedef __uint32_t u_int32_t;
// typedef __uint64_t u_int64_t;

// typedef int register_t __attribute__ ((__mode__ (__word__)));
// # 176 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
// # 1 "/usr/include/endian.h" 1 3 4
// # 24 "/usr/include/endian.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
// # 35 "/usr/include/x86_64-linux-gnu/bits/endian.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/endianness.h" 1 3 4
// # 36 "/usr/include/x86_64-linux-gnu/bits/endian.h" 2 3 4
// # 25 "/usr/include/endian.h" 2 3 4
// # 35 "/usr/include/endian.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
// # 33 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
// static __inline __uint16_t
// __bswap_16 (__uint16_t __bsx)
// {

//   return __builtin_bswap16 (__bsx);

// }

// static __inline __uint32_t
// __bswap_32 (__uint32_t __bsx)
// {

//   return __builtin_bswap32 (__bsx);

// }
// # 69 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
// __extension__ static __inline __uint64_t
// __bswap_64 (__uint64_t __bsx)
// {

//   return __builtin_bswap64 (__bsx);

// }
// # 36 "/usr/include/endian.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 1 3 4
// # 32 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 3 4
// static __inline __uint16_t
// __uint16_identity (__uint16_t __x)
// {
//   return __x;
// }

// static __inline __uint32_t
// __uint32_identity (__uint32_t __x)
// {
//   return __x;
// }

// static __inline __uint64_t
// __uint64_identity (__uint64_t __x)
// {
//   return __x;
// }
// # 37 "/usr/include/endian.h" 2 3 4
// # 177 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
// # 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
// # 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 1 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 1 3 4

// typedef struct
// {
//   unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
// } __sigset_t;
// # 5 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 2 3 4

// typedef __sigset_t sigset_t;
// # 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 1 3 4

// struct timeval
// {

//   __time_t tv_sec;
//   __suseconds_t tv_usec;

// };
// # 38 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
// # 11 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
// struct timespec
// {

//   __time_t tv_sec;

//   __syscall_slong_t tv_nsec;
// # 31 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
// };
// # 40 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

// typedef __suseconds_t suseconds_t;

// typedef long int __fd_mask;
// # 59 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
// typedef struct
//   {

//     __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];

//   } fd_set;

// typedef __fd_mask fd_mask;
// # 91 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

// # 102 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
// extern int select (int __nfds, fd_set *__restrict __readfds,
//      fd_set *__restrict __writefds,
//      fd_set *__restrict __exceptfds,
//      struct timeval *__restrict __timeout);
// # 127 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
// extern int pselect (int __nfds, fd_set *__restrict __readfds,
//       fd_set *__restrict __writefds,
//       fd_set *__restrict __exceptfds,
//       const struct timespec *__restrict __timeout,
//       const __sigset_t *__restrict __sigmask);
// # 153 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

// # 180 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

// typedef __blksize_t blksize_t;

// typedef __blkcnt_t blkcnt_t;

// typedef __fsblkcnt_t fsblkcnt_t;

// typedef __fsfilcnt_t fsfilcnt_t;
// # 227 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
// # 23 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 1 3 4
// # 44 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 1 3 4
// # 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 2 3 4
// # 45 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 1 3 4
// # 25 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 3 4
// typedef union
// {
//   __extension__ unsigned long long int __value64;
//   struct
//   {
//     unsigned int __low;
//     unsigned int __high;
//   } __value32;
// } __atomic_wide_counter;
// # 47 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

// typedef struct __pthread_internal_list
// {
//   struct __pthread_internal_list *__prev;
//   struct __pthread_internal_list *__next;
// } __pthread_list_t;

// typedef struct __pthread_internal_slist
// {
//   struct __pthread_internal_slist *__next;
// } __pthread_slist_t;
// # 76 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 1 3 4
// # 22 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
// struct __pthread_mutex_s
// {
//   int __lock;
//   unsigned int __count;
//   int __owner;

//   unsigned int __nusers;

//   int __kind;

//   short __spins;
//   short __elision;
//   __pthread_list_t __list;
// # 53 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
// };
// # 77 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4
// # 89 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 1 3 4
// # 23 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
// struct __pthread_rwlock_arch_t
// {
//   unsigned int __readers;
//   unsigned int __writers;
//   unsigned int __wrphase_futex;
//   unsigned int __writers_futex;
//   unsigned int __pad3;
//   unsigned int __pad4;

//   int __cur_writer;
//   int __shared;
//   signed char __rwelision;

//   unsigned char __pad1[7];

//   unsigned long int __pad2;

//   unsigned int __flags;
// # 55 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
// };
// # 90 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

// struct __pthread_cond_s
// {
//   __atomic_wide_counter __wseq;
//   __atomic_wide_counter __g1_start;
//   unsigned int __g_refs[2] ;
//   unsigned int __g_size[2];
//   unsigned int __g1_orig_size;
//   unsigned int __wrefs;
//   unsigned int __g_signals[2];
// };

// typedef unsigned int __tss_t;
// typedef unsigned long int __thrd_t;

// typedef struct
// {
//   int __data ;
// } __once_flag;
// # 24 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4

// typedef unsigned long int pthread_t;

// typedef union
// {
//   char __size[4];
//   int __align;
// } pthread_mutexattr_t;

// typedef union
// {
//   char __size[4];
//   int __align;
// } pthread_condattr_t;

// typedef unsigned int pthread_key_t;

// typedef int pthread_once_t;

// union pthread_attr_t
// {
//   char __size[56];
//   long int __align;
// };

// typedef union pthread_attr_t pthread_attr_t;

// typedef union
// {
//   struct __pthread_mutex_s __data;
//   char __size[40];
//   long int __align;
// } pthread_mutex_t;

// typedef union
// {
//   struct __pthread_cond_s __data;
//   char __size[48];
//   __extension__ long long int __align;
// } pthread_cond_t;

// typedef union
// {
//   struct __pthread_rwlock_arch_t __data;
//   char __size[56];
//   long int __align;
// } pthread_rwlock_t;

// typedef union
// {
//   char __size[8];
//   long int __align;
// } pthread_rwlockattr_t;

// typedef volatile int pthread_spinlock_t;

// typedef union
// {
//   char __size[32];
//   long int __align;
// } pthread_barrier_t;

// typedef union
// {
//   char __size[4];
//   int __align;
// } pthread_barrierattr_t;
// # 228 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

// # 515 "/usr/include/stdlib.h" 2 3 4

// extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));

// extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));

// extern char *initstate (unsigned int __seed, char *__statebuf,
//    size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// struct random_data
//   {
//     int32_t *fptr;
//     int32_t *rptr;
//     int32_t *state;
//     int rand_type;
//     int rand_deg;
//     int rand_sep;
//     int32_t *end_ptr;
//   };

// extern int random_r (struct random_data *__restrict __buf,
//        int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int srandom_r (unsigned int __seed, struct random_data *__buf)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
//    size_t __statelen,
//    struct random_data *__restrict __buf)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

// extern int setstate_r (char *__restrict __statebuf,
//          struct random_data *__restrict __buf)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

// extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));

// extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));

// extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
// extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
// extern long int nrand48 (unsigned short int __xsubi[3])
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
// extern long int jrand48 (unsigned short int __xsubi[3])
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
// extern unsigned short int *seed48 (unsigned short int __seed16v[3])
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// struct drand48_data
//   {
//     unsigned short int __x[3];
//     unsigned short int __old_x[3];
//     unsigned short int __c;
//     unsigned short int __init;
//     __extension__ unsigned long long int __a;

//   };

// extern int drand48_r (struct drand48_data *__restrict __buffer,
//         double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// extern int erand48_r (unsigned short int __xsubi[3],
//         struct drand48_data *__restrict __buffer,
//         double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int lrand48_r (struct drand48_data *__restrict __buffer,
//         long int *__restrict __result)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// extern int nrand48_r (unsigned short int __xsubi[3],
//         struct drand48_data *__restrict __buffer,
//         long int *__restrict __result)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int mrand48_r (struct drand48_data *__restrict __buffer,
//         long int *__restrict __result)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// extern int jrand48_r (unsigned short int __xsubi[3],
//         struct drand48_data *__restrict __buffer,
//         long int *__restrict __result)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int seed48_r (unsigned short int __seed16v[3],
//        struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int lcong48_r (unsigned short int __param[7],
//         struct drand48_data *__buffer)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern __uint32_t arc4random (void)
//      __attribute__ ((__nothrow__ , __leaf__)) ;

// extern void arc4random_buf (void *__buf, size_t __size)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
//      __attribute__ ((__nothrow__ , __leaf__)) ;

// extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
//      __attribute__ ((__alloc_size__ (1))) ;

// extern void *calloc (size_t __nmemb, size_t __size)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;

// extern void *realloc (void *__ptr, size_t __size)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));

// extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));

// extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
//      __attribute__ ((__alloc_size__ (2, 3)))
//     __attribute__ ((__malloc__ (__builtin_free, 1)));

// extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));

// # 1 "/usr/include/alloca.h" 1 3 4
// # 24 "/usr/include/alloca.h" 3 4
// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 1 3 4
// # 25 "/usr/include/alloca.h" 2 3 4

// extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));

// # 707 "/usr/include/stdlib.h" 2 3 4

// extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
//      __attribute__ ((__alloc_size__ (1))) ;

// extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// extern void *aligned_alloc (size_t __alignment, size_t __size)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
//      __attribute__ ((__alloc_size__ (2))) ;

// extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

// extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

// extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

// extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

// extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
// # 786 "/usr/include/stdlib.h" 3 4
// extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int setenv (const char *__name, const char *__value, int __replace)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
// # 814 "/usr/include/stdlib.h" 3 4
// extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 827 "/usr/include/stdlib.h" 3 4
// extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
// # 849 "/usr/include/stdlib.h" 3 4
// extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
// # 870 "/usr/include/stdlib.h" 3 4
// extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
// # 923 "/usr/include/stdlib.h" 3 4
// extern int system (const char *__command) ;
// # 940 "/usr/include/stdlib.h" 3 4
// extern char *realpath (const char *__restrict __name,
//          char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;

// typedef int (*__compar_fn_t) (const void *, const void *);
// # 960 "/usr/include/stdlib.h" 3 4
// extern void *bsearch (const void *__key, const void *__base,
//         size_t __nmemb, size_t __size, __compar_fn_t __compar)
//      __attribute__ ((__nonnull__ (1, 2, 5))) ;

// extern void qsort (void *__base, size_t __nmemb, size_t __size,
//      __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
// # 980 "/usr/include/stdlib.h" 3 4
// extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
// extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

// __extension__ extern long long int llabs (long long int __x)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

// extern div_t div (int __numer, int __denom)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
// extern ldiv_t ldiv (long int __numer, long int __denom)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

// __extension__ extern lldiv_t lldiv (long long int __numer,
//         long long int __denom)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
// # 1012 "/usr/include/stdlib.h" 3 4
// extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
//      int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;

// extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
//      int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;

// extern char *gcvt (double __value, int __ndigit, char *__buf)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;

// extern char *qecvt (long double __value, int __ndigit,
//       int *__restrict __decpt, int *__restrict __sign)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
// extern char *qfcvt (long double __value, int __ndigit,
//       int *__restrict __decpt, int *__restrict __sign)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
// extern char *qgcvt (long double __value, int __ndigit, char *__buf)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;

// extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
//      int *__restrict __sign, char *__restrict __buf,
//      size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
// extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
//      int *__restrict __sign, char *__restrict __buf,
//      size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

// extern int qecvt_r (long double __value, int __ndigit,
//       int *__restrict __decpt, int *__restrict __sign,
//       char *__restrict __buf, size_t __len)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
// extern int qfcvt_r (long double __value, int __ndigit,
//       int *__restrict __decpt, int *__restrict __sign,
//       char *__restrict __buf, size_t __len)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

// extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

// extern int mbtowc (wchar_t *__restrict __pwc,
//      const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

// extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));

// extern size_t mbstowcs (wchar_t *__restrict __pwcs,
//    const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
//     __attribute__ ((__access__ (__read_only__, 2)));

// extern size_t wcstombs (char *__restrict __s,
//    const wchar_t *__restrict __pwcs, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__))
//   __attribute__ ((__access__ (__write_only__, 1, 3)))
//   __attribute__ ((__access__ (__read_only__, 2)));

// extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
// # 1099 "/usr/include/stdlib.h" 3 4
// extern int getsubopt (char **__restrict __optionp,
//         char *const *__restrict __tokens,
//         char **__restrict __valuep)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
// # 1145 "/usr/include/stdlib.h" 3 4
// extern int getloadavg (double __loadavg[], int __nelem)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 1155 "/usr/include/stdlib.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
// # 1156 "/usr/include/stdlib.h" 2 3 4
// # 1167 "/usr/include/stdlib.h" 3 4

// # 7 "espforth.c" 2
// # 1 "/usr/include/string.h" 1 3 4
// # 26 "/usr/include/string.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
// # 27 "/usr/include/string.h" 2 3 4

// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 1 3 4
// # 34 "/usr/include/string.h" 2 3 4
// # 43 "/usr/include/string.h" 3 4
// extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
//        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern void *memmove (void *__dest, const void *__src, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
//         int __c, size_t __n)
//     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));

// extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int memcmp (const void *__s1, const void *__s2, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
// # 80 "/usr/include/string.h" 3 4
// extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
// # 107 "/usr/include/string.h" 3 4
// extern void *memchr (const void *__s, int __c, size_t __n)
//       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
// # 141 "/usr/include/string.h" 3 4
// extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern char *strncpy (char *__restrict __dest,
//         const char *__restrict __src, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern char *strcat (char *__restrict __dest, const char *__restrict __src)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern char *strncat (char *__restrict __dest, const char *__restrict __src,
//         size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int strcmp (const char *__s1, const char *__s2)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int strncmp (const char *__s1, const char *__s2, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int strcoll (const char *__s1, const char *__s2)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern size_t strxfrm (char *__restrict __dest,
//          const char *__restrict __src, size_t __n)
//     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));

// # 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
// # 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
// # 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
// struct __locale_struct
// {

//   struct __locale_data *__locales[13];

//   const unsigned short int *__ctype_b;
//   const int *__ctype_tolower;
//   const int *__ctype_toupper;

//   const char *__names[13];
// };

// typedef struct __locale_struct *__locale_t;
// # 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

// typedef __locale_t locale_t;
// # 173 "/usr/include/string.h" 2 3 4

// extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

// extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
//     locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
//      __attribute__ ((__access__ (__write_only__, 1, 3)));

// extern char *strdup (const char *__s)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));

// extern char *strndup (const char *__string, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
// # 246 "/usr/include/string.h" 3 4
// extern char *strchr (const char *__s, int __c)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
// # 273 "/usr/include/string.h" 3 4
// extern char *strrchr (const char *__s, int __c)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
// # 286 "/usr/include/string.h" 3 4
// extern char *strchrnul (const char *__s, int __c)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

// extern size_t strcspn (const char *__s, const char *__reject)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern size_t strspn (const char *__s, const char *__accept)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
// # 323 "/usr/include/string.h" 3 4
// extern char *strpbrk (const char *__s, const char *__accept)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
// # 350 "/usr/include/string.h" 3 4
// extern char *strstr (const char *__haystack, const char *__needle)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern char *strtok (char *__restrict __s, const char *__restrict __delim)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern char *__strtok_r (char *__restrict __s,
//     const char *__restrict __delim,
//     char **__restrict __save_ptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

// extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
//          char **__restrict __save_ptr)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
// # 380 "/usr/include/string.h" 3 4
// extern char *strcasestr (const char *__haystack, const char *__needle)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern void *memmem (const void *__haystack, size_t __haystacklen,
//        const void *__needle, size_t __needlelen)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
//     __attribute__ ((__access__ (__read_only__, 1, 2)))
//     __attribute__ ((__access__ (__read_only__, 3, 4)));

// extern void *__mempcpy (void *__restrict __dest,
//    const void *__restrict __src, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// extern void *mempcpy (void *__restrict __dest,
//         const void *__restrict __src, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern size_t strlen (const char *__s)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

// extern size_t strnlen (const char *__string, size_t __maxlen)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

// extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
// # 432 "/usr/include/string.h" 3 4
// extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

//                         __attribute__ ((__nonnull__ (2)))
//     __attribute__ ((__access__ (__write_only__, 2, 3)));
// # 458 "/usr/include/string.h" 3 4
// extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));

// # 1 "/usr/include/strings.h" 1 3 4
// # 23 "/usr/include/strings.h" 3 4
// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 1 3 4
// # 24 "/usr/include/strings.h" 2 3 4

// extern int bcmp (const void *__s1, const void *__s2, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern void bcopy (const void *__src, void *__dest, size_t __n)
//   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 68 "/usr/include/strings.h" 3 4
// extern char *index (const char *__s, int __c)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
// # 96 "/usr/include/strings.h" 3 4
// extern char *rindex (const char *__s, int __c)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

// extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

// extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
// __extension__ extern int ffsll (long long int __ll)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

// extern int strcasecmp (const char *__s1, const char *__s2)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

// extern int strncasecmp_l (const char *__s1, const char *__s2,
//      size_t __n, locale_t __loc)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));

// # 463 "/usr/include/string.h" 2 3 4

// extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
//     __attribute__ ((__access__ (__write_only__, 1, 2)));

// extern char *strsep (char **__restrict __stringp,
//        const char *__restrict __delim)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
// # 489 "/usr/include/string.h" 3 4
// extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern char *__stpncpy (char *__restrict __dest,
//    const char *__restrict __src, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// extern char *stpncpy (char *__restrict __dest,
//         const char *__restrict __src, size_t __n)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern size_t strlcpy (char *__restrict __dest,
//          const char *__restrict __src, size_t __n)
//   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));

// extern size_t strlcat (char *__restrict __dest,
//          const char *__restrict __src, size_t __n)
//   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
// # 552 "/usr/include/string.h" 3 4

// # 8 "espforth.c" 2
// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stdint.h" 1 3 4
// # 9 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stdint.h" 3 4
// # 1 "/usr/include/stdint.h" 1 3 4
// # 26 "/usr/include/stdint.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
// # 27 "/usr/include/stdint.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
// # 29 "/usr/include/stdint.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 30 "/usr/include/stdint.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 1 3 4
// # 24 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 3 4
// typedef __uint8_t uint8_t;
// typedef __uint16_t uint16_t;
// typedef __uint32_t uint32_t;
// typedef __uint64_t uint64_t;
// # 38 "/usr/include/stdint.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/stdint-least.h" 1 3 4
// # 25 "/usr/include/x86_64-linux-gnu/bits/stdint-least.h" 3 4
// typedef __int_least8_t int_least8_t;
// typedef __int_least16_t int_least16_t;
// typedef __int_least32_t int_least32_t;
// typedef __int_least64_t int_least64_t;

// typedef __uint_least8_t uint_least8_t;
// typedef __uint_least16_t uint_least16_t;
// typedef __uint_least32_t uint_least32_t;
// typedef __uint_least64_t uint_least64_t;
// # 42 "/usr/include/stdint.h" 2 3 4

// typedef signed char int_fast8_t;

// typedef long int int_fast16_t;
// typedef long int int_fast32_t;
// typedef long int int_fast64_t;
// # 60 "/usr/include/stdint.h" 3 4
// typedef unsigned char uint_fast8_t;

// typedef unsigned long int uint_fast16_t;
// typedef unsigned long int uint_fast32_t;
// typedef unsigned long int uint_fast64_t;
// # 76 "/usr/include/stdint.h" 3 4
// typedef long int intptr_t;

// typedef unsigned long int uintptr_t;
// # 90 "/usr/include/stdint.h" 3 4
// typedef __intmax_t intmax_t;
// typedef __uintmax_t uintmax_t;
// # 10 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stdint.h" 2 3 4
// # 9 "espforth.c" 2
// # 1 "/usr/include/inttypes.h" 1 3 4
// # 34 "/usr/include/inttypes.h" 3 4
// typedef int __gwchar_t;
// # 327 "/usr/include/inttypes.h" 3 4

// typedef struct
//   {
//     long int quot;
//     long int rem;
//   } imaxdiv_t;
// # 351 "/usr/include/inttypes.h" 3 4
// extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

// extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
//       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

// extern intmax_t strtoimax (const char *__restrict __nptr,
//       char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));

// extern uintmax_t strtoumax (const char *__restrict __nptr,
//        char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));

// extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
//       __gwchar_t **__restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__));

// extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
//        __gwchar_t ** __restrict __endptr, int __base)
//      __attribute__ ((__nothrow__ , __leaf__));
// # 415 "/usr/include/inttypes.h" 3 4

// # 10 "espforth.c" 2

// # 1 "/usr/include/errno.h" 1 3 4
// # 28 "/usr/include/errno.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
// # 26 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
// # 1 "/usr/include/linux/errno.h" 1 3 4
// # 1 "/usr/include/x86_64-linux-gnu/asm/errno.h" 1 3 4
// # 1 "/usr/include/asm-generic/errno.h" 1 3 4

// # 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
// # 6 "/usr/include/asm-generic/errno.h" 2 3 4
// # 2 "/usr/include/x86_64-linux-gnu/asm/errno.h" 2 3 4
// # 2 "/usr/include/linux/errno.h" 2 3 4
// # 27 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4
// # 29 "/usr/include/errno.h" 2 3 4

// extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
// # 52 "/usr/include/errno.h" 3 4

// # 12 "espforth.c" 2
// # 1 "/usr/include/fcntl.h" 1 3 4
// # 28 "/usr/include/fcntl.h" 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/fcntl.h" 1 3 4
// # 35 "/usr/include/x86_64-linux-gnu/bits/fcntl.h" 3 4
// struct flock
//   {
//     short int l_type;
//     short int l_whence;

//     __off_t l_start;
//     __off_t l_len;

//     __pid_t l_pid;
//   };
// # 61 "/usr/include/x86_64-linux-gnu/bits/fcntl.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/fcntl-linux.h" 1 3 4
// # 382 "/usr/include/x86_64-linux-gnu/bits/fcntl-linux.h" 3 4

// # 456 "/usr/include/x86_64-linux-gnu/bits/fcntl-linux.h" 3 4

// # 62 "/usr/include/x86_64-linux-gnu/bits/fcntl.h" 2 3 4
// # 36 "/usr/include/fcntl.h" 2 3 4
// # 78 "/usr/include/fcntl.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/stat.h" 1 3 4
// # 25 "/usr/include/x86_64-linux-gnu/bits/stat.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/struct_stat.h" 1 3 4
// # 26 "/usr/include/x86_64-linux-gnu/bits/struct_stat.h" 3 4
// struct stat
//   {

//     __dev_t st_dev;

//     __ino_t st_ino;

//     __nlink_t st_nlink;
//     __mode_t st_mode;

//     __uid_t st_uid;
//     __gid_t st_gid;

//     int __pad0;

//     __dev_t st_rdev;

//     __off_t st_size;

//     __blksize_t st_blksize;

//     __blkcnt_t st_blocks;
// # 74 "/usr/include/x86_64-linux-gnu/bits/struct_stat.h" 3 4
//     struct timespec st_atim;
//     struct timespec st_mtim;
//     struct timespec st_ctim;
// # 89 "/usr/include/x86_64-linux-gnu/bits/struct_stat.h" 3 4
//     __syscall_slong_t __glibc_reserved[3];
// # 99 "/usr/include/x86_64-linux-gnu/bits/struct_stat.h" 3 4
//   };
// # 26 "/usr/include/x86_64-linux-gnu/bits/stat.h" 2 3 4
// # 79 "/usr/include/fcntl.h" 2 3 4
// # 177 "/usr/include/fcntl.h" 3 4
// extern int fcntl (int __fd, int __cmd, ...);
// # 209 "/usr/include/fcntl.h" 3 4
// extern int open (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
// # 233 "/usr/include/fcntl.h" 3 4
// extern int openat (int __fd, const char *__file, int __oflag, ...)
//      __attribute__ ((__nonnull__ (2)));
// # 255 "/usr/include/fcntl.h" 3 4
// extern int creat (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
// # 284 "/usr/include/fcntl.h" 3 4
// extern int lockf (int __fd, int __cmd, off_t __len);
// # 301 "/usr/include/fcntl.h" 3 4
// extern int posix_fadvise (int __fd, off_t __offset, off_t __len,
//      int __advise) __attribute__ ((__nothrow__ , __leaf__));
// # 323 "/usr/include/fcntl.h" 3 4
// extern int posix_fallocate (int __fd, off_t __offset, off_t __len);
// # 345 "/usr/include/fcntl.h" 3 4

// # 13 "espforth.c" 2

// # 1 "/usr/include/x86_64-linux-gnu/sys/stat.h" 1 3 4
// # 99 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/stat.h" 1 3 4
// # 102 "/usr/include/x86_64-linux-gnu/sys/stat.h" 2 3 4
// # 205 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4
// extern int stat (const char *__restrict __file,
//    struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
// # 264 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4
// extern int fstatat (int __fd, const char *__restrict __file,
//       struct stat *__restrict __buf, int __flag)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
// # 313 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4
// extern int lstat (const char *__restrict __file,
//     struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// # 352 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4
// extern int chmod (const char *__file, __mode_t __mode)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int lchmod (const char *__file, __mode_t __mode)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ , __leaf__));

// extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
//        int __flag)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;

// extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ , __leaf__));
// # 389 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4
// extern int mkdir (const char *__path, __mode_t __mode)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int mknodat (int __fd, const char *__path, __mode_t __mode,
//       __dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int mkfifo (const char *__path, __mode_t __mode)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int utimensat (int __fd, const char *__path,
//         const struct timespec __times[2],
//         int __flags)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
// # 452 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4
// extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ , __leaf__));
// # 468 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3 4

// # 15 "espforth.c" 2
// # 36 "espforth.c"
// # 1 "/usr/include/termios.h" 1 3 4
// # 35 "/usr/include/termios.h" 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/termios.h" 1 3 4
// # 23 "/usr/include/x86_64-linux-gnu/bits/termios.h" 3 4
// typedef unsigned char cc_t;
// typedef unsigned int speed_t;
// typedef unsigned int tcflag_t;

// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-struct.h" 1 3 4
// # 24 "/usr/include/x86_64-linux-gnu/bits/termios-struct.h" 3 4
// struct termios
//   {
//     tcflag_t c_iflag;
//     tcflag_t c_oflag;
//     tcflag_t c_cflag;
//     tcflag_t c_lflag;
//     cc_t c_line;
//     cc_t c_cc[32];
//     speed_t c_ispeed;
//     speed_t c_ospeed;

//   };
// # 28 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-c_cc.h" 1 3 4
// # 29 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-c_iflag.h" 1 3 4
// # 30 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-c_oflag.h" 1 3 4
// # 31 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4
// # 53 "/usr/include/x86_64-linux-gnu/bits/termios.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-baud.h" 1 3 4
// # 54 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-c_cflag.h" 1 3 4
// # 56 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-c_lflag.h" 1 3 4
// # 57 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4
// # 74 "/usr/include/x86_64-linux-gnu/bits/termios.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-tcflow.h" 1 3 4
// # 75 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/termios-misc.h" 1 3 4
// # 77 "/usr/include/x86_64-linux-gnu/bits/termios.h" 2 3 4
// # 40 "/usr/include/termios.h" 2 3 4
// # 48 "/usr/include/termios.h" 3 4
// extern speed_t cfgetospeed (const struct termios *__termios_p) __attribute__ ((__nothrow__ , __leaf__));

// extern speed_t cfgetispeed (const struct termios *__termios_p) __attribute__ ((__nothrow__ , __leaf__));

// extern int cfsetospeed (struct termios *__termios_p, speed_t __speed) __attribute__ ((__nothrow__ , __leaf__));

// extern int cfsetispeed (struct termios *__termios_p, speed_t __speed) __attribute__ ((__nothrow__ , __leaf__));

// extern int cfsetspeed (struct termios *__termios_p, speed_t __speed) __attribute__ ((__nothrow__ , __leaf__));

// extern int tcgetattr (int __fd, struct termios *__termios_p) __attribute__ ((__nothrow__ , __leaf__));

// extern int tcsetattr (int __fd, int __optional_actions,
//         const struct termios *__termios_p) __attribute__ ((__nothrow__ , __leaf__));

// extern void cfmakeraw (struct termios *__termios_p) __attribute__ ((__nothrow__ , __leaf__));

// extern int tcsendbreak (int __fd, int __duration) __attribute__ ((__nothrow__ , __leaf__));

// extern int tcdrain (int __fd);

// extern int tcflush (int __fd, int __queue_selector) __attribute__ ((__nothrow__ , __leaf__));

// extern int tcflow (int __fd, int __action) __attribute__ ((__nothrow__ , __leaf__));

// extern __pid_t tcgetsid (int __fd) __attribute__ ((__nothrow__ , __leaf__));

// # 1 "/usr/include/x86_64-linux-gnu/sys/ttydefaults.h" 1 3 4
// # 105 "/usr/include/termios.h" 2 3 4

// # 37 "espforth.c" 2
// # 1 "/usr/include/unistd.h" 1 3 4
// # 27 "/usr/include/unistd.h" 3 4

// # 202 "/usr/include/unistd.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/posix_opt.h" 1 3 4
// # 203 "/usr/include/unistd.h" 2 3 4

// # 1 "/usr/include/x86_64-linux-gnu/bits/environments.h" 1 3 4
// # 22 "/usr/include/x86_64-linux-gnu/bits/environments.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
// # 23 "/usr/include/x86_64-linux-gnu/bits/environments.h" 2 3 4
// # 207 "/usr/include/unistd.h" 2 3 4
// # 226 "/usr/include/unistd.h" 3 4
// # 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 1 3 4
// # 227 "/usr/include/unistd.h" 2 3 4
// # 255 "/usr/include/unistd.h" 3 4
// typedef __useconds_t useconds_t;
// # 274 "/usr/include/unistd.h" 3 4
// typedef __socklen_t socklen_t;
// # 287 "/usr/include/unistd.h" 3 4
// extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
// # 309 "/usr/include/unistd.h" 3 4
// extern int faccessat (int __fd, const char *__file, int __type, int __flag)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
// # 339 "/usr/include/unistd.h" 3 4
// extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
// # 358 "/usr/include/unistd.h" 3 4
// extern int close (int __fd);

// extern void closefrom (int __lowfd) __attribute__ ((__nothrow__ , __leaf__));

// extern ssize_t read (int __fd, void *__buf, size_t __nbytes)
//     __attribute__ ((__access__ (__write_only__, 2, 3)));

// extern ssize_t write (int __fd, const void *__buf, size_t __n)
//     __attribute__ ((__access__ (__read_only__, 2, 3)));
// # 389 "/usr/include/unistd.h" 3 4
// extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
//         __off_t __offset)
//     __attribute__ ((__access__ (__write_only__, 2, 3)));

// extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
//          __off_t __offset)
//     __attribute__ ((__access__ (__read_only__, 2, 3)));
// # 437 "/usr/include/unistd.h" 3 4
// extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
// # 452 "/usr/include/unistd.h" 3 4
// extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
// # 464 "/usr/include/unistd.h" 3 4
// extern unsigned int sleep (unsigned int __seconds);

// extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
//      __attribute__ ((__nothrow__ , __leaf__));

// extern int usleep (__useconds_t __useconds);
// # 489 "/usr/include/unistd.h" 3 4
// extern int pause (void);

// extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// extern int fchownat (int __fd, const char *__file, __uid_t __owner,
//        __gid_t __group, int __flag)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;

// extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
// # 531 "/usr/include/unistd.h" 3 4
// extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
// # 545 "/usr/include/unistd.h" 3 4
// extern char *getwd (char *__buf)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__))
//     __attribute__ ((__access__ (__write_only__, 1)));

// extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
// # 564 "/usr/include/unistd.h" 3 4
// extern char **__environ;

// extern int execve (const char *__path, char *const __argv[],
//      char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int execv (const char *__path, char *const __argv[])
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int execle (const char *__path, const char *__arg, ...)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int execl (const char *__path, const char *__arg, ...)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int execvp (const char *__file, char *const __argv[])
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

// extern int execlp (const char *__file, const char *__arg, ...)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// # 619 "/usr/include/unistd.h" 3 4
// extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern void _exit (int __status) __attribute__ ((__noreturn__));

// # 1 "/usr/include/x86_64-linux-gnu/bits/confname.h" 1 3 4
// # 24 "/usr/include/x86_64-linux-gnu/bits/confname.h" 3 4
// enum
//   {
//     _PC_LINK_MAX,

//     _PC_MAX_CANON,

//     _PC_MAX_INPUT,

//     _PC_NAME_MAX,

//     _PC_PATH_MAX,

//     _PC_PIPE_BUF,

//     _PC_CHOWN_RESTRICTED,

//     _PC_NO_TRUNC,

//     _PC_VDISABLE,

//     _PC_SYNC_IO,

//     _PC_ASYNC_IO,

//     _PC_PRIO_IO,

//     _PC_SOCK_MAXBUF,

//     _PC_FILESIZEBITS,

//     _PC_REC_INCR_XFER_SIZE,

//     _PC_REC_MAX_XFER_SIZE,

//     _PC_REC_MIN_XFER_SIZE,

//     _PC_REC_XFER_ALIGN,

//     _PC_ALLOC_SIZE_MIN,

//     _PC_SYMLINK_MAX,

//     _PC_2_SYMLINKS

//   };

// enum
//   {
//     _SC_ARG_MAX,

//     _SC_CHILD_MAX,

//     _SC_CLK_TCK,

//     _SC_NGROUPS_MAX,

//     _SC_OPEN_MAX,

//     _SC_STREAM_MAX,

//     _SC_TZNAME_MAX,

//     _SC_JOB_CONTROL,

//     _SC_SAVED_IDS,

//     _SC_REALTIME_SIGNALS,

//     _SC_PRIORITY_SCHEDULING,

//     _SC_TIMERS,

//     _SC_ASYNCHRONOUS_IO,

//     _SC_PRIORITIZED_IO,

//     _SC_SYNCHRONIZED_IO,

//     _SC_FSYNC,

//     _SC_MAPPED_FILES,

//     _SC_MEMLOCK,

//     _SC_MEMLOCK_RANGE,

//     _SC_MEMORY_PROTECTION,

//     _SC_MESSAGE_PASSING,

//     _SC_SEMAPHORES,

//     _SC_SHARED_MEMORY_OBJECTS,

//     _SC_AIO_LISTIO_MAX,

//     _SC_AIO_MAX,

//     _SC_AIO_PRIO_DELTA_MAX,

//     _SC_DELAYTIMER_MAX,

//     _SC_MQ_OPEN_MAX,

//     _SC_MQ_PRIO_MAX,

//     _SC_VERSION,

//     _SC_PAGESIZE,

//     _SC_RTSIG_MAX,

//     _SC_SEM_NSEMS_MAX,

//     _SC_SEM_VALUE_MAX,

//     _SC_SIGQUEUE_MAX,

//     _SC_TIMER_MAX,

//     _SC_BC_BASE_MAX,

//     _SC_BC_DIM_MAX,

//     _SC_BC_SCALE_MAX,

//     _SC_BC_STRING_MAX,

//     _SC_COLL_WEIGHTS_MAX,

//     _SC_EQUIV_CLASS_MAX,

//     _SC_EXPR_NEST_MAX,

//     _SC_LINE_MAX,

//     _SC_RE_DUP_MAX,

//     _SC_CHARCLASS_NAME_MAX,

//     _SC_2_VERSION,

//     _SC_2_C_BIND,

//     _SC_2_C_DEV,

//     _SC_2_FORT_DEV,

//     _SC_2_FORT_RUN,

//     _SC_2_SW_DEV,

//     _SC_2_LOCALEDEF,

//     _SC_PII,

//     _SC_PII_XTI,

//     _SC_PII_SOCKET,

//     _SC_PII_INTERNET,

//     _SC_PII_OSI,

//     _SC_POLL,

//     _SC_SELECT,

//     _SC_UIO_MAXIOV,

//     _SC_IOV_MAX = _SC_UIO_MAXIOV,

//     _SC_PII_INTERNET_STREAM,

//     _SC_PII_INTERNET_DGRAM,

//     _SC_PII_OSI_COTS,

//     _SC_PII_OSI_CLTS,

//     _SC_PII_OSI_M,

//     _SC_T_IOV_MAX,

//     _SC_THREADS,

//     _SC_THREAD_SAFE_FUNCTIONS,

//     _SC_GETGR_R_SIZE_MAX,

//     _SC_GETPW_R_SIZE_MAX,

//     _SC_LOGIN_NAME_MAX,

//     _SC_TTY_NAME_MAX,

//     _SC_THREAD_DESTRUCTOR_ITERATIONS,

//     _SC_THREAD_KEYS_MAX,

//     _SC_THREAD_STACK_MIN,

//     _SC_THREAD_THREADS_MAX,

//     _SC_THREAD_ATTR_STACKADDR,

//     _SC_THREAD_ATTR_STACKSIZE,

//     _SC_THREAD_PRIORITY_SCHEDULING,

//     _SC_THREAD_PRIO_INHERIT,

//     _SC_THREAD_PRIO_PROTECT,

//     _SC_THREAD_PROCESS_SHARED,

//     _SC_NPROCESSORS_CONF,

//     _SC_NPROCESSORS_ONLN,

//     _SC_PHYS_PAGES,

//     _SC_AVPHYS_PAGES,

//     _SC_ATEXIT_MAX,

//     _SC_PASS_MAX,

//     _SC_XOPEN_VERSION,

//     _SC_XOPEN_XCU_VERSION,

//     _SC_XOPEN_UNIX,

//     _SC_XOPEN_CRYPT,

//     _SC_XOPEN_ENH_I18N,

//     _SC_XOPEN_SHM,

//     _SC_2_CHAR_TERM,

//     _SC_2_C_VERSION,

//     _SC_2_UPE,

//     _SC_XOPEN_XPG2,

//     _SC_XOPEN_XPG3,

//     _SC_XOPEN_XPG4,

//     _SC_CHAR_BIT,

//     _SC_CHAR_MAX,

//     _SC_CHAR_MIN,

//     _SC_INT_MAX,

//     _SC_INT_MIN,

//     _SC_LONG_BIT,

//     _SC_WORD_BIT,

//     _SC_MB_LEN_MAX,

//     _SC_NZERO,

//     _SC_SSIZE_MAX,

//     _SC_SCHAR_MAX,

//     _SC_SCHAR_MIN,

//     _SC_SHRT_MAX,

//     _SC_SHRT_MIN,

//     _SC_UCHAR_MAX,

//     _SC_UINT_MAX,

//     _SC_ULONG_MAX,

//     _SC_USHRT_MAX,

//     _SC_NL_ARGMAX,

//     _SC_NL_LANGMAX,

//     _SC_NL_MSGMAX,

//     _SC_NL_NMAX,

//     _SC_NL_SETMAX,

//     _SC_NL_TEXTMAX,

//     _SC_XBS5_ILP32_OFF32,

//     _SC_XBS5_ILP32_OFFBIG,

//     _SC_XBS5_LP64_OFF64,

//     _SC_XBS5_LPBIG_OFFBIG,

//     _SC_XOPEN_LEGACY,

//     _SC_XOPEN_REALTIME,

//     _SC_XOPEN_REALTIME_THREADS,

//     _SC_ADVISORY_INFO,

//     _SC_BARRIERS,

//     _SC_BASE,

//     _SC_C_LANG_SUPPORT,

//     _SC_C_LANG_SUPPORT_R,

//     _SC_CLOCK_SELECTION,

//     _SC_CPUTIME,

//     _SC_THREAD_CPUTIME,

//     _SC_DEVICE_IO,

//     _SC_DEVICE_SPECIFIC,

//     _SC_DEVICE_SPECIFIC_R,

//     _SC_FD_MGMT,

//     _SC_FIFO,

//     _SC_PIPE,

//     _SC_FILE_ATTRIBUTES,

//     _SC_FILE_LOCKING,

//     _SC_FILE_SYSTEM,

//     _SC_MONOTONIC_CLOCK,

//     _SC_MULTI_PROCESS,

//     _SC_SINGLE_PROCESS,

//     _SC_NETWORKING,

//     _SC_READER_WRITER_LOCKS,

//     _SC_SPIN_LOCKS,

//     _SC_REGEXP,

//     _SC_REGEX_VERSION,

//     _SC_SHELL,

//     _SC_SIGNALS,

//     _SC_SPAWN,

//     _SC_SPORADIC_SERVER,

//     _SC_THREAD_SPORADIC_SERVER,

//     _SC_SYSTEM_DATABASE,

//     _SC_SYSTEM_DATABASE_R,

//     _SC_TIMEOUTS,

//     _SC_TYPED_MEMORY_OBJECTS,

//     _SC_USER_GROUPS,

//     _SC_USER_GROUPS_R,

//     _SC_2_PBS,

//     _SC_2_PBS_ACCOUNTING,

//     _SC_2_PBS_LOCATE,

//     _SC_2_PBS_MESSAGE,

//     _SC_2_PBS_TRACK,

//     _SC_SYMLOOP_MAX,

//     _SC_STREAMS,

//     _SC_2_PBS_CHECKPOINT,

//     _SC_V6_ILP32_OFF32,

//     _SC_V6_ILP32_OFFBIG,

//     _SC_V6_LP64_OFF64,

//     _SC_V6_LPBIG_OFFBIG,

//     _SC_HOST_NAME_MAX,

//     _SC_TRACE,

//     _SC_TRACE_EVENT_FILTER,

//     _SC_TRACE_INHERIT,

//     _SC_TRACE_LOG,

//     _SC_LEVEL1_ICACHE_SIZE,

//     _SC_LEVEL1_ICACHE_ASSOC,

//     _SC_LEVEL1_ICACHE_LINESIZE,

//     _SC_LEVEL1_DCACHE_SIZE,

//     _SC_LEVEL1_DCACHE_ASSOC,

//     _SC_LEVEL1_DCACHE_LINESIZE,

//     _SC_LEVEL2_CACHE_SIZE,

//     _SC_LEVEL2_CACHE_ASSOC,

//     _SC_LEVEL2_CACHE_LINESIZE,

//     _SC_LEVEL3_CACHE_SIZE,

//     _SC_LEVEL3_CACHE_ASSOC,

//     _SC_LEVEL3_CACHE_LINESIZE,

//     _SC_LEVEL4_CACHE_SIZE,

//     _SC_LEVEL4_CACHE_ASSOC,

//     _SC_LEVEL4_CACHE_LINESIZE,

//     _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

//     _SC_RAW_SOCKETS,

//     _SC_V7_ILP32_OFF32,

//     _SC_V7_ILP32_OFFBIG,

//     _SC_V7_LP64_OFF64,

//     _SC_V7_LPBIG_OFFBIG,

//     _SC_SS_REPL_MAX,

//     _SC_TRACE_EVENT_NAME_MAX,

//     _SC_TRACE_NAME_MAX,

//     _SC_TRACE_SYS_MAX,

//     _SC_TRACE_USER_EVENT_MAX,

//     _SC_XOPEN_STREAMS,

//     _SC_THREAD_ROBUST_PRIO_INHERIT,

//     _SC_THREAD_ROBUST_PRIO_PROTECT,

//     _SC_MINSIGSTKSZ,

//     _SC_SIGSTKSZ

//   };

// enum
//   {
//     _CS_PATH,

//     _CS_V6_WIDTH_RESTRICTED_ENVS,

//     _CS_GNU_LIBC_VERSION,

//     _CS_GNU_LIBPTHREAD_VERSION,

//     _CS_V5_WIDTH_RESTRICTED_ENVS,

//     _CS_V7_WIDTH_RESTRICTED_ENVS,

//     _CS_LFS_CFLAGS = 1000,

//     _CS_LFS_LDFLAGS,

//     _CS_LFS_LIBS,

//     _CS_LFS_LINTFLAGS,

//     _CS_LFS64_CFLAGS,

//     _CS_LFS64_LDFLAGS,

//     _CS_LFS64_LIBS,

//     _CS_LFS64_LINTFLAGS,

//     _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

//     _CS_XBS5_ILP32_OFF32_LDFLAGS,

//     _CS_XBS5_ILP32_OFF32_LIBS,

//     _CS_XBS5_ILP32_OFF32_LINTFLAGS,

//     _CS_XBS5_ILP32_OFFBIG_CFLAGS,

//     _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

//     _CS_XBS5_ILP32_OFFBIG_LIBS,

//     _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

//     _CS_XBS5_LP64_OFF64_CFLAGS,

//     _CS_XBS5_LP64_OFF64_LDFLAGS,

//     _CS_XBS5_LP64_OFF64_LIBS,

//     _CS_XBS5_LP64_OFF64_LINTFLAGS,

//     _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

//     _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

//     _CS_XBS5_LPBIG_OFFBIG_LIBS,

//     _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,

//     _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

//     _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

//     _CS_POSIX_V6_ILP32_OFF32_LIBS,

//     _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

//     _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

//     _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

//     _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

//     _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

//     _CS_POSIX_V6_LP64_OFF64_CFLAGS,

//     _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

//     _CS_POSIX_V6_LP64_OFF64_LIBS,

//     _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

//     _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

//     _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

//     _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

//     _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,

//     _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

//     _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

//     _CS_POSIX_V7_ILP32_OFF32_LIBS,

//     _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

//     _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

//     _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

//     _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

//     _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

//     _CS_POSIX_V7_LP64_OFF64_CFLAGS,

//     _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

//     _CS_POSIX_V7_LP64_OFF64_LIBS,

//     _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

//     _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

//     _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

//     _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

//     _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,

//     _CS_V6_ENV,

//     _CS_V7_ENV

//   };
// # 631 "/usr/include/unistd.h" 2 3 4

// extern long int pathconf (const char *__path, int __name)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));

// extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));

// extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
//     __attribute__ ((__access__ (__write_only__, 2, 3)));

// extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));

// extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));

// extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
// # 682 "/usr/include/unistd.h" 3 4
// extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));

// extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));

// extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));

// extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__))
//     __attribute__ ((__access__ (__write_only__, 2, 1)));
// # 722 "/usr/include/unistd.h" 3 4
// extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
// # 778 "/usr/include/unistd.h" 3 4
// extern __pid_t fork (void) __attribute__ ((__nothrow__));

// extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
// # 799 "/usr/include/unistd.h" 3 4
// extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));

// extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
//      __attribute__ ((__access__ (__write_only__, 2, 3)));

// extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));

// extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));

// extern int link (const char *__from, const char *__to)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;

// extern int linkat (int __fromfd, const char *__from, int __tofd,
//      const char *__to, int __flags)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;

// extern int symlink (const char *__from, const char *__to)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;

// extern ssize_t readlink (const char *__restrict __path,
//     char *__restrict __buf, size_t __len)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
//      __attribute__ ((__access__ (__write_only__, 2, 3)));

// extern int symlinkat (const char *__from, int __tofd,
//         const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;

// extern ssize_t readlinkat (int __fd, const char *__restrict __path,
//       char *__restrict __buf, size_t __len)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)))
//      __attribute__ ((__access__ (__write_only__, 3, 4)));

// extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int unlinkat (int __fd, const char *__name, int __flag)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

// extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));

// extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));

// extern char *getlogin (void);

// extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)))
//     __attribute__ ((__access__ (__write_only__, 1, 2)));

// extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// # 1 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 1 3 4
// # 27 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 1 3 4
// # 28 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 3 4

// extern char *optarg;
// # 50 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 3 4
// extern int optind;

// extern int opterr;

// extern int optopt;
// # 91 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 3 4
// extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
//        __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

// # 28 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 2 3 4

// # 49 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 3 4

// # 904 "/usr/include/unistd.h" 2 3 4

// extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
//     __attribute__ ((__access__ (__write_only__, 1, 2)));

// extern int sethostname (const char *__name, size_t __len)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));

// extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int getdomainname (char *__name, size_t __len)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
//      __attribute__ ((__access__ (__write_only__, 1, 2)));
// extern int setdomainname (const char *__name, size_t __len)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));

// extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));

// extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// extern int profil (unsigned short int *__sample_buffer, size_t __size,
//      size_t __offset, unsigned int __scale)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));

// extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
// extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
// extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));

// extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));

// extern int fsync (int __fd);
// # 1002 "/usr/include/unistd.h" 3 4
// extern long int gethostid (void);

// extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));

// extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

// extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
// # 1026 "/usr/include/unistd.h" 3 4
// extern int truncate (const char *__file, __off_t __length)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
// # 1049 "/usr/include/unistd.h" 3 4
// extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
// # 1070 "/usr/include/unistd.h" 3 4
// extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;

// extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
// # 1091 "/usr/include/unistd.h" 3 4
// extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
// # 1150 "/usr/include/unistd.h" 3 4
// extern int fdatasync (int __fildes);
// # 1162 "/usr/include/unistd.h" 3 4
// extern char *crypt (const char *__key, const char *__salt)
//      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
// # 1201 "/usr/include/unistd.h" 3 4
// int getentropy (void *__buffer, size_t __length)
//     __attribute__ ((__access__ (__write_only__, 1, 2)));
// # 1221 "/usr/include/unistd.h" 3 4
// # 1 "/usr/include/x86_64-linux-gnu/bits/unistd_ext.h" 1 3 4
// # 1222 "/usr/include/unistd.h" 2 3 4

// # 38 "espforth.c" 2

// AIBOT ESP32 Forth, based on Version 6.3 by CH Ting

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>

// #define esp32

#ifdef esp32
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"
#include "esp_mac.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
// #  include "esp_spi_flash.h"
#include "esp_err.h"
#include "esp_vfs.h"
#include "esp_vfs_dev.h"
#include "esp_vfs_fat.h"
#include "esp_system.h"
#include "driver/uart.h"
#else
#include <termios.h>
#include <unistd.h>
#endif

#define log(...) fprintf(stderr, __VA_ARGS__)
// #define log(...)

static const char *TAG = "espforth";

typedef intptr_t cell_t;
typedef uintptr_t ucell_t;

typedef __int128_t dcell_t;
typedef __uint128_t udcell_t;

static cell_t rack[256] = {0}, stack[256] = {0};
static unsigned char R = 0, S = 0;
static cell_t *Pointer;
static cell_t P, IP, WP, top, links;
static dcell_t d, n, m;
static cell_t data[16000] = {};
static uint8_t *cData = (uint8_t *)data;
static const int IMEDD = 0x80;
static const int COMPO = 0x40;

static int ABORQP = 0, DOTQP = 0, STRQP = 0, COLD = 0;
static char filename[4096];

static int NOP = 0;
static int ACCEPT = 0;
static int QKEY = 0;
static int EMIT = 0;
static int DOCON = 0;
static int DOLIT = 0;
static int DOLIST = 0;
static int EXIT = 0;
static int EXECUTE = 0;
static int DONEXT = 0;
static int QBRANCH = 0;
static int BRANCH = 0;
static int STORE = 0;
static int AT = 0;
static int CSTORE = 0;
static int CAT = 0;
static int RPAT = 0;
static int RPSTO = 0;
static int RFROM = 0;
static int RAT = 0;
static int TOR = 0;
static int SPAT = 0;
static int SPSTO = 0;
static int DROP = 0;
static int DUP = 0;
static int SWAP = 0;
static int OVER = 0;
static int ZLESS = 0;
static int AND = 0;
static int OR = 0;
static int XOR = 0;
static int UPLUS = 0;
static int NEXTT = 0;
static int QDUP = 0;
static int ROT = 0;
static int DDROP = 0;
static int DDUP = 0;
static int PLUS = 0;
static int INVERSE = 0;
static int NEGATE = 0;
static int DNEGATE = 0;
static int SUB = 0;
static int ABS = 0;
static int EQUAL = 0;
static int ULESS = 0;
static int LESS = 0;
static int UMMOD = 0;
static int MSMOD = 0;
static int SLMOD = 0;
static int MOD = 0;
static int SLASH = 0;
static int UMSTA = 0;
static int STAR = 0;
static int MSTAR = 0;
static int SSMOD = 0;
static int STASL = 0;
static int PICK = 0;
static int PSTORE = 0;
static int DSTORE = 0;
static int DAT = 0;
static int COUNT = 0;
static int DOVAR = 0;
static int MAX = 0;
static int MIN = 0;
static int TONE = 0;
static int sendPacket = 0;
static int POKE = 0;
static int PEEK = 0;
static int ADC = 0;
static int PIN = 0;
static int DUTY = 0;
static int FREQ = 0;
static int MS = 0;
static int TERMINATE = 0;
static int R_O = 0;
static int R_W = 0;
static int W_O = 0;
static int BIN = 0;
static int CLOSE_FILE = 0;
static int OPEN_FILE = 0;
static int CREATE_FILE = 0;
static int DELETE_FILE = 0;
static int WRITE_FILE = 0;
static int READ_FILE = 0;
static int FILE_POSITION = 0;
static int REPOSITION_FILE = 0;
static int RESIZE_FILE = 0;
static int FILE_SIZE = 0;

static void HEADER(int flags, const char *name)
{
     log("HEADER, flags: %d, name: %s\n",flags,name);
     ((void)sizeof((

                       IP % sizeof(cell_t) == 0

                       )
                       ? 1
                       : 0),
      __extension__({ if (

 IP % sizeof(cell_t) == 0

 ) ; else __assert_fail (

 "IP % sizeof(cell_t) == 0"

 , "espforth.c", 257, __extension__ __PRETTY_FUNCTION__); }))

         ;
     P = IP / sizeof(cell_t);
     int i;
     int len = strlen(name) & 0x1f;
     data[P++] = links;
     IP = P * sizeof(cell_t);

     links = IP;
     cData[IP++] = len | flags;
     for (i = 0; i < len; i++)
     {
          cData[IP++] = name[i];
     }
     while (IP & (sizeof(cell_t) - 1))
     {
          cData[IP++] = 0;
     }
}

static void Comma(cell_t n)
{

     ((void)sizeof((

                       IP % sizeof(cell_t) == 0

                       )
                       ? 1
                       : 0),
      __extension__({ if (

 IP % sizeof(cell_t) == 0

 ) ; else __assert_fail (

 "IP % sizeof(cell_t) == 0"

 , "espforth.c", 289, __extension__ __PRETTY_FUNCTION__); }))

         ;
     P = IP / sizeof(cell_t);
     data[P++] = n;
     IP = P * sizeof(cell_t);
}

enum
{
     UNUSED_MACRO = 0x80000000,

     BEGIN,
     AGAIN,
     UNTIL,
     WHILE,
     REPEAT,
     IF,
     ELSE,
     THEN,
     FOR,
     NEXT,
     AFT,
     DOTQ,
     STRQ,
     ABORTQ,

};

static void next(void)
{
     P = data[IP / sizeof(cell_t)];
     IP += sizeof(cell_t);
     WP = P + sizeof(cell_t);
}

static int qrx(void)
{
     fd_set readfds;

     do
     {
          unsigned int __i;
          fd_set *__arr = (

              &readfds

          );
          for (__i = 0; __i < sizeof(fd_set) / sizeof(__fd_mask); ++__i)
               ((__arr)->__fds_bits)[__i] = 0;
     } while (0)

         ;

     ((void)(((

                  &readfds

                  )
                  ->__fds_bits)[((0) / (8 * (int)sizeof(__fd_mask)))] |= ((__fd_mask)(1UL << ((0) % (8 * (int)sizeof(__fd_mask)))))))

         ;
     struct timeval tm;
     tm.tv_sec = 0;
     tm.tv_usec = 0;
     int ret = select(1, &readfds,

                      ((void *)0)

                          ,

                      ((void *)0)

                          ,
                      &tm);
     if (ret > 0)
     {
          return fgetc(

              stdin

          );
     }
     return -1;
}

static int duplexread(unsigned char *dst, int sz)
{
     int len = 0;
     while (sz > 0)
     {
          int ch = fgetc(

              stdin

          );
          if (ch == 127 || ch == 8)
          {
               if (len > 0)
               {
                    fputc(8,

                          stdout

                    );
                    fputc(' ',

                          stdout

                    );
                    fputc(8,

                          stdout

                    );
                    --len;
               }
               continue;
          }
          if (ch == '\n')
          {
               fputc('\r',

                     stdout

               );
          }
          fputc(ch,

                stdout

          );
          if (ch == '\n' || ch < 0)
          {
               break;
          }
          dst[len++] = ch;
     }
     return len;
}

static void setpin(int p, int level)
{
     printf("setting pin #%d to level: %d\n",p,level);
}

static void mspause(cell_t ms)
{

     usleep(ms * 1000);
}

static void fun_NOP(void) { next(); }
static void fun_ACCEPT(void) { top = duplexread(cData, top); }
static void fun_QKEY(void)
{
     stack[(unsigned char)++S] = top, top = qrx();
     if (top >= 0)
          stack[(unsigned char)++S] = top, top = -1;
     else
          top = 0;
}
static void fun_EMIT(void)
{
     char c = top;
     fputc(c,

           stdout

     );
     top = stack[(unsigned char)S--];
}
static void fun_DOCON(void) { stack[(unsigned char)++S] = top, top = data[WP / sizeof(cell_t)]; }
static void fun_DOLIT(void)
{
     stack[(unsigned char)++S] = top, top = data[IP / sizeof(cell_t)];
     IP += sizeof(cell_t);
     next();
}
static void fun_DOLIST(void)
{
     rack[(unsigned char)++R] = IP;
     IP = WP;
     next();
}
static void fun_EXIT(void)
{
     IP = (cell_t)rack[(unsigned char)R--];
     next();
}
static void fun_EXECUTE(void)
{
     P = top;
     WP = P + sizeof(cell_t);
     top = stack[(unsigned char)S--];
}
static void fun_DONEXT(void)
{
     if (rack[(unsigned char)R])
          (rack[(unsigned char)R] -= 1, IP = data[IP / sizeof(cell_t)]);
     else
          (IP += sizeof(cell_t), R--);
     next();
}
static void fun_QBRANCH(void)
{
     if (top == 0)
          IP = data[IP / sizeof(cell_t)];
     else
          IP += sizeof(cell_t);
     top = stack[(unsigned char)S--];
     next();
}
static void fun_BRANCH(void)
{
     IP = data[IP / sizeof(cell_t)];
     next();
}
static void fun_STORE(void)
{
     data[top / sizeof(cell_t)] = stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_AT(void) { top = data[top / sizeof(cell_t)]; }
static void fun_CSTORE(void)
{
     cData[top] = (unsigned char)stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_CAT(void) { top = (cell_t)cData[top]; }
static void fun_RPAT(void) { ; }
static void fun_RPSTO(void) { ; }
static void fun_RFROM(void) { stack[(unsigned char)++S] = top, top = rack[(unsigned char)R--]; }
static void fun_RAT(void) { stack[(unsigned char)++S] = top, top = rack[(unsigned char)R]; }
static void fun_TOR(void)
{
     rack[(unsigned char)++R] = top;
     top = stack[(unsigned char)S--];
}
static void fun_SPAT(void) { ; }
static void fun_SPSTO(void) { ; }
static void fun_DROP(void) { top = stack[(unsigned char)S--]; }
static void fun_DUP(void) { stack[(unsigned char)++S] = top; }
static void fun_SWAP(void)
{
     WP = top;
     top = stack[(unsigned char)S];
     stack[(unsigned char)S] = WP;
}
static void fun_OVER(void) { stack[(unsigned char)++S] = top, top = stack[(unsigned char)(S - 1)]; }
static void fun_ZLESS(void) { top = (top < 0) ? -1 : 0; }
static void fun_AND(void) { top &= stack[(unsigned char)S--]; }
static void fun_OR(void) { top |= stack[(unsigned char)S--]; }
static void fun_XOR(void) { top ^= stack[(unsigned char)S--]; }
static void fun_UPLUS(void)
{
     stack[(unsigned char)S] += top;
     top = ((ucell_t)(stack[(unsigned char)S]) < (ucell_t)(top));
}
static void fun_NEXTT(void) { next(); }
static void fun_QDUP(void)
{
     if (top)
          stack[(unsigned char)++S] = top;
}
static void fun_ROT(void)
{
     WP = stack[(unsigned char)(S - 1)];
     stack[(unsigned char)(S - 1)] = stack[(unsigned char)S];
     stack[(unsigned char)S] = top;
     top = WP;
}
static void fun_DDROP(void)
{
     fun_DROP();
     fun_DROP();
}
static void fun_DDUP(void)
{
     fun_OVER();
     fun_OVER();
}
static void fun_PLUS(void) { top += stack[(unsigned char)S--]; }
static void fun_INVERSE(void) { top = -top - 1; }
static void fun_NEGATE(void) { top = 0 - top; }
static void fun_DNEGATE(void)
{
     fun_INVERSE();
     fun_TOR();
     fun_INVERSE();
     stack[(unsigned char)++S] = top, top = 1;
     fun_UPLUS();
     fun_RFROM();
     fun_PLUS();
}
static void fun_SUB(void) { top = stack[(unsigned char)S--] - top; }
static void fun_ABS(void)
{
     if (top < 0)
          top = -top;
}
static void fun_EQUAL(void) { top = (stack[(unsigned char)S--] == top) ? -1 : 0; }
static void fun_ULESS(void)
{
     top = ((ucell_t)(stack[(unsigned char)S]) < (ucell_t)(top)) ? -1 : 0;
     S--;
}
static void fun_LESS(void) { top = (stack[(unsigned char)S--] < top) ? -1 : 0; }
static void fun_UMMOD(void)
{
     d = (udcell_t)((ucell_t)top);
     m = (udcell_t)((ucell_t)stack[(unsigned char)S]);
     n = (udcell_t)((ucell_t)stack[(unsigned char)(S - 1)]);
     n += m << (sizeof(cell_t) * 8);
     top = stack[(unsigned char)S--];
     if (d == 0)
          (top = 0, stack[S] = 0);
     else
          (top = (ucell_t)(n / d), stack[(unsigned char)S] = (ucell_t)(n % d));
}
static void fun_MSMOD(void)
{
     d = (dcell_t)((cell_t)top);
     m = (dcell_t)((cell_t)stack[(unsigned char)S]);
     n = (dcell_t)((cell_t)stack[(unsigned char)S - 1]);
     n += m << (sizeof(cell_t) * 8);
     top = stack[(unsigned char)S--];
     if (d == 0)
          (top = 0, stack[S] = 0);
     else
          (top = (cell_t)(n / d), stack[(unsigned char)S] = (cell_t)(n % d));
}
static void fun_SLMOD(void)
{
     if (top != 0)
          (WP = stack[(unsigned char)S] / top, stack[(unsigned char)S] %= top, top = WP);
}
static void fun_MOD(void) { top = (top) ? stack[(unsigned char)S--] % top : stack[(unsigned char)S--]; }
static void fun_SLASH(void) { top = (top) ? stack[(unsigned char)S--] / top : (S--, 0); }
static void fun_UMSTA(void)
{
     d = (udcell_t)top;
     m = (udcell_t)stack[(unsigned char)S];
     m *= d;
     top = (ucell_t)(m >> (sizeof(cell_t) * 8));
     stack[(unsigned char)S] = (ucell_t)m;
}
static void fun_STAR(void) { top *= stack[(unsigned char)S--]; }
static void fun_MSTAR(void)
{
     d = (dcell_t)top;
     m = (dcell_t)stack[(unsigned char)S];
     m *= d;
     top = (cell_t)(m >> (sizeof(cell_t) * 8));
     stack[(unsigned char)S] = (cell_t)m;
}
static void fun_SSMOD(void)
{
     d = (dcell_t)top;
     m = (dcell_t)stack[(unsigned char)S];
     n = (dcell_t)stack[(unsigned char)(S - 1)];
     n *= m;
     top = stack[(unsigned char)S--];
     top = (cell_t)(n / d);
     stack[(unsigned char)S] = (cell_t)(n % d);
}
static void fun_STASL(void)
{
     d = (dcell_t)top;
     m = (dcell_t)stack[(unsigned char)S];
     n = (dcell_t)stack[(unsigned char)(S - 1)];
     n *= m;
     top = stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
     top = (cell_t)(n / d);
}
static void fun_PICK(void) { top = stack[(unsigned char)(S - top)]; }
static void fun_PSTORE(void)
{
     data[top / sizeof(cell_t)] += stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_DSTORE(void)
{
     data[(top / sizeof(cell_t)) + 1] = stack[(unsigned char)S--];
     data[top / sizeof(cell_t)] = stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_DAT(void)
{
     stack[(unsigned char)++S] = top, top = data[top / sizeof(cell_t)];
     top = data[(top / sizeof(cell_t)) + 1];
}
static void fun_COUNT(void)
{
     stack[(unsigned char)++S] = top + 1;
     top = cData[top];
}
static void fun_DOVAR(void) { stack[(unsigned char)++S] = top, top = WP; }
static void fun_MAX(void)
{
     if (top < stack[(unsigned char)S])
          top = stack[(unsigned char)S--];
     else
          S--;
}
static void fun_MIN(void)
{
     if (top < stack[(unsigned char)S])
          S--;
     else
          top = stack[(unsigned char)S--];
}
static void fun_TONE(void)
{
     WP = top;
     top = stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_sendPacket(void) { ; }
static void fun_POKE(void)
{
     Pointer = (cell_t *)top;
     *Pointer = stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_PEEK(void)
{
     Pointer = (cell_t *)top;
     top = *Pointer;
}
static void fun_ADC(void) { top = (cell_t)0; }
static void fun_PIN(void)
{
     WP = top;
     top = stack[(unsigned char)S--];
     setpin(WP, top);
     top = stack[(unsigned char)S--];
}
static void fun_DUTY(void)
{
     WP = top;
     top = stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_FREQ(void)
{
     WP = top;
     top = stack[(unsigned char)S--];
     top = stack[(unsigned char)S--];
}
static void fun_MS(void)
{
     WP = top;
     top = stack[(unsigned char)S--];
     mspause(WP);
}
static void fun_TERMINATE(void) { exit(top); }
static void fun_R_O(void) { stack[(unsigned char)++S] = top, top =

                                                                 00

                            ; }
static void fun_R_W(void) { stack[(unsigned char)++S] = top, top =

                                                                 02

                            ; }
static void fun_W_O(void) { stack[(unsigned char)++S] = top, top =

                                                                 01

                            ; }
static void fun_BIN(void) { ; }
static void fun_CLOSE_FILE(void)
{
     top = close(top);
     top = top ?

               (*__errno_location())

               : 0;
}
static void fun_OPEN_FILE(void)
{
     cell_t mode = top;
     top = stack[(unsigned char)S--];
     cell_t len = top;
     top = stack[(unsigned char)S--];
     memcpy(filename, &cData[top], len);
     filename[len] = 0;
     mode_t mask = umask(0);
     umask(mask);
     top = open(filename, mode, mask);
     stack[(unsigned char)++S] = top, top = top < 0 ?

                                                    (*__errno_location())

                                                    : 0;
}
static void fun_CREATE_FILE(void)
{
     cell_t mode = top;
     top = stack[(unsigned char)S--];
     cell_t len = top;
     top = stack[(unsigned char)S--];
     memcpy(filename, &cData[top], len);
     filename[len] = 0;
     top = open(filename, mode |

                              0100

                              |

                              01000

     );
     stack[(unsigned char)++S] = top, top = top < 0 ?

                                                    (*__errno_location())

                                                    : 0;
}
static void fun_DELETE_FILE(void)
{
     cell_t len = top;
     top = stack[(unsigned char)S--];
     memcpy(filename, &cData[top], len);
     filename[len] = 0;
     top = unlink(filename);
     top = top ?

               (*__errno_location())

               : 0;
}
static void fun_WRITE_FILE(void)
{
     cell_t fd = top;
     top = stack[(unsigned char)S--];
     cell_t len = top;
     top = stack[(unsigned char)S--];
     top = write(fd, &cData[top], len);
     top = top != len ?

                      (*__errno_location())

                      : 0;
}
static void fun_READ_FILE(void)
{
     cell_t fd = top;
     top = stack[(unsigned char)S--];
     cell_t len = top;
     top = stack[(unsigned char)S--];
     log("fun_READ_FILE, fd=%ld, address=%ld, len=%ld\n",fd,top,len);
     top = read(fd, &cData[top], len);
     log("fun_READ_FILE, read=%ld\n",top);
     stack[(unsigned char)++S] = top, top = top != len ?

                                                       (*__errno_location())

                                                       : 0;
}
static void fun_FILE_POSITION(void)
{
     top = (cell_t)lseek(top, 0,

                         1

     );
     stack[(unsigned char)++S] = top, top = top < 0 ?

                                                    (*__errno_location())

                                                    : 0;
}
static void fun_REPOSITION_FILE(void)
{
     cell_t fd = top;
     top = stack[(unsigned char)S--];
     top = (cell_t)lseek(fd, top,

                         0

     );
     top = top < 0 ?

                   (*__errno_location())

                   : 0;
}
static void fun_RESIZE_FILE(void)
{
     cell_t fd = top;
     top = stack[(unsigned char)S--];
     top = ftruncate(fd, top);
     top = top < 0 ?

                   (*__errno_location())

                   : 0;
}
static void fun_FILE_SIZE(void)
{
     struct stat st;
     WP = fstat(top, &st);
     top = (cell_t)st.st_size;
     stack[(unsigned char)++S] = top, top = WP < 0 ?

                                                   (*__errno_location())

                                                   : 0;
}

static void (*primitives[])(void) = {

    fun_NOP,
    fun_ACCEPT,
    fun_QKEY,
    fun_EMIT,
    fun_DOCON,
    fun_DOLIT,
    fun_DOLIST,
    fun_EXIT,
    fun_EXECUTE,
    fun_DONEXT,
    fun_QBRANCH,
    fun_BRANCH,
    fun_STORE,
    fun_AT,
    fun_CSTORE,
    fun_CAT,
    fun_RPAT,
    fun_RPSTO,
    fun_RFROM,
    fun_RAT,
    fun_TOR,
    fun_SPAT,
    fun_SPSTO,
    fun_DROP,
    fun_DUP,
    fun_SWAP,
    fun_OVER,
    fun_ZLESS,
    fun_AND,
    fun_OR,
    fun_XOR,
    fun_UPLUS,
    fun_NEXTT,
    fun_QDUP,
    fun_ROT,
    fun_DDROP,
    fun_DDUP,
    fun_PLUS,
    fun_INVERSE,
    fun_NEGATE,
    fun_DNEGATE,
    fun_SUB,
    fun_ABS,
    fun_EQUAL,
    fun_ULESS,
    fun_LESS,
    fun_UMMOD,
    fun_MSMOD,
    fun_SLMOD,
    fun_MOD,
    fun_SLASH,
    fun_UMSTA,
    fun_STAR,
    fun_MSTAR,
    fun_SSMOD,
    fun_STASL,
    fun_PICK,
    fun_PSTORE,
    fun_DSTORE,
    fun_DAT,
    fun_COUNT,
    fun_DOVAR,
    fun_MAX,
    fun_MIN,
    fun_TONE,
    fun_sendPacket,
    fun_POKE,
    fun_PEEK,
    fun_ADC,
    fun_PIN,
    fun_DUTY,
    fun_FREQ,
    fun_MS,
    fun_TERMINATE,
    fun_R_O,
    fun_R_W,
    fun_W_O,
    fun_BIN,
    fun_CLOSE_FILE,
    fun_OPEN_FILE,
    fun_CREATE_FILE,
    fun_DELETE_FILE,
    fun_WRITE_FILE,
    fun_READ_FILE,
    fun_FILE_POSITION,
    fun_REPOSITION_FILE,
    fun_RESIZE_FILE,
    fun_FILE_SIZE,

};

enum
{
     as_UNKNOWN = -1,

     as_NOP,
     as_ACCEPT,
     as_QKEY,
     as_EMIT,
     as_DOCON,
     as_DOLIT,
     as_DOLIST,
     as_EXIT,
     as_EXECUTE,
     as_DONEXT,
     as_QBRANCH,
     as_BRANCH,
     as_STORE,
     as_AT,
     as_CSTORE,
     as_CAT,
     as_RPAT,
     as_RPSTO,
     as_RFROM,
     as_RAT,
     as_TOR,
     as_SPAT,
     as_SPSTO,
     as_DROP,
     as_DUP,
     as_SWAP,
     as_OVER,
     as_ZLESS,
     as_AND,
     as_OR,
     as_XOR,
     as_UPLUS,
     as_NEXTT,
     as_QDUP,
     as_ROT,
     as_DDROP,
     as_DDUP,
     as_PLUS,
     as_INVERSE,
     as_NEGATE,
     as_DNEGATE,
     as_SUB,
     as_ABS,
     as_EQUAL,
     as_ULESS,
     as_LESS,
     as_UMMOD,
     as_MSMOD,
     as_SLMOD,
     as_MOD,
     as_SLASH,
     as_UMSTA,
     as_STAR,
     as_MSTAR,
     as_SSMOD,
     as_STASL,
     as_PICK,
     as_PSTORE,
     as_DSTORE,
     as_DAT,
     as_COUNT,
     as_DOVAR,
     as_MAX,
     as_MIN,
     as_TONE,
     as_sendPacket,
     as_POKE,
     as_PEEK,
     as_ADC,
     as_PIN,
     as_DUTY,
     as_FREQ,
     as_MS,
     as_TERMINATE,
     as_R_O,
     as_R_W,
     as_W_O,
     as_BIN,
     as_CLOSE_FILE,
     as_OPEN_FILE,
     as_CREATE_FILE,
     as_DELETE_FILE,
     as_WRITE_FILE,
     as_READ_FILE,
     as_FILE_POSITION,
     as_REPOSITION_FILE,
     as_RESIZE_FILE,
     as_FILE_SIZE,

};

int CODE(const char *name, ...)
{
     log("CODE name: %s\n",name);

     HEADER(0, name);

     int addr = IP;
     cell_t s;

     va_list argList;

     __builtin_va_start(

         argList

         ,

         name

     )

         ;
     do
     {
          s =

              __builtin_va_arg(

                  argList

                  ,

                  cell_t

              )

              ;
          cData[IP++] = s;

     } while (s != as_NEXTT);
     while (IP & (sizeof(cell_t) - 1))
     {
          cData[IP++] = 0;
     }

     __builtin_va_end(

         argList

     )

         ;
     return addr;
}

int COLON_WITH_FLAGS(int flags, const char *name, ...)
{
     log("COLON_WITH_FLAGS, flags: %d, name: %s\n",flags,name);
     HEADER(flags, name);

     int addr = IP;
     P = IP / sizeof(cell_t);
     data[P++] = as_DOLIST;
     va_list argList;

     __builtin_va_start(

         argList

         ,

         name

     )

         ;

     int prev_word = 0, word = 0, i, k;
     const char *str;
     do
     {
          prev_word = word;
          word =

              __builtin_va_arg(

                  argList

                  ,

                  int

              )

              ;
          switch (word)
          {

          case BEGIN:
          {
               rack[(unsigned char)++R] = P;
          }
          break;
          case AGAIN:
          {
               data[P++] = BRANCH;
               data[P++] = rack[(unsigned char)R--] * sizeof(cell_t);
          }
          break;
          case UNTIL:
          {
               data[P++] = QBRANCH;
               data[P++] = rack[(unsigned char)R--] * sizeof(cell_t);
          }
          break;
          case WHILE:
          {
               data[P++] = QBRANCH;
               data[P++] = 0;
               k = rack[(unsigned char)R--];
               rack[(unsigned char)++R] = (P - 1);
               rack[(unsigned char)++R] = k;
          }
          break;
          case REPEAT:
          {
               data[P++] = BRANCH;
               data[P++] = rack[(unsigned char)R--] * sizeof(cell_t);
               data[rack[(unsigned char)R--]] = P * sizeof(cell_t);
          }
          break;
          case IF:
          {
               data[P++] = QBRANCH;
               rack[(unsigned char)++R] = P;
               data[P++] = 0;
          }
          break;
          case ELSE:
          {
               data[P++] = BRANCH;
               data[P++] = 0;
               data[rack[(unsigned char)R--]] = P * sizeof(cell_t);
               rack[(unsigned char)++R] = P - 1;
          }
          break;
          case THEN:
          {
               data[rack[(unsigned char)R--]] = P * sizeof(cell_t);
          }
          break;
          case FOR:
          {
               data[P++] = TOR;
               rack[(unsigned char)++R] = P;
          }
          break;
          case NEXT:
          {
               data[P++] = DONEXT;
               data[P++] = rack[(unsigned char)R--] * sizeof(cell_t);
          }
          break;
          case AFT:
          {
               data[P++] = BRANCH;
               data[P++] = 0;
               k = rack[(unsigned char)R--];
               rack[(unsigned char)++R] = P;
               rack[(unsigned char)++R] = P - 1;
          }
          break;
          case DOTQ:
          {
               str =

                   __builtin_va_arg(

                       argList

                       ,

                       const char *

                   )

                   ;
               int len = strlen(str);
               data[P++] = DOTQP;
               IP = P * sizeof(cell_t);
               cData[IP++] = len;
               for (i = 0; i < len; i++)
                    cData[IP++] = str[i];
               while (IP & (sizeof(cell_t) - 1))
                    cData[IP++] = 0;
               P = IP / sizeof(cell_t);
               ;
          }
          break;
          case STRQ:
          {
               str =

                   __builtin_va_arg(

                       argList

                       ,

                       const char *

                   )

                   ;
               int len = strlen(str);
               data[P++] = STRQP;
               IP = P * sizeof(cell_t);
               cData[IP++] = len;
               for (i = 0; i < len; i++)
                    cData[IP++] = str[i];
               while (IP & (sizeof(cell_t) - 1))
                    cData[IP++] = 0;
               P = IP / sizeof(cell_t);
               ;
          }
          break;
          case ABORTQ:
          {
               str =

                   __builtin_va_arg(

                       argList

                       ,

                       const char *

                   )

                   ;
               int len = strlen(str);
               data[P++] = ABORQP;
               IP = P * sizeof(cell_t);
               cData[IP++] = len;
               for (i = 0; i < len; i++)
                    cData[IP++] = str[i];
               while (IP & (sizeof(cell_t) - 1))
                    cData[IP++] = 0;
               P = IP / sizeof(cell_t);
               ;
          }
          break;

          default:
               data[P++] = word;

               break;
          }
     } while (word != EXIT || R > 0 || prev_word == DOLIT);
     IP = P * sizeof(cell_t);

     __builtin_va_end(

         argList

     )

         ;
     return addr;
}

static int CONSTANT(const char *name, cell_t n)
{
     log("CONSTANT name: %s, value:%ld\n",name,n);

     int ret = CODE(name, as_DOCON, as_NEXTT);
     Comma(n);
     return ret;
}

static int VARIABLE(const char *name)
{
     log("VARIABLE name: %s\n",name);
     int ret = CODE(name, as_DOVAR, as_NEXTT);
     Comma(0);
     return ret;
}

static void SET_VAR(cell_t addr, cell_t value)
{
     data[addr / sizeof(cell_t) + 1] = value;
}

static void run()
{
     P = COLD;
     WP = P + sizeof(cell_t);
     for (;;)
     {
          // int lastP = P;
          unsigned char bytecode = cData[P++];
          // printf("executing at: %ul, bytecode: %d\n",lastP,bytecode);
          primitives[bytecode]();
     }
}

static struct termios terminalOld;
static void RestoreTerminal(void)
{
     tcsetattr(

         0

         ,

         2

         ,
         &terminalOld);
}
static void Init(void)
{
     setvbuf(

         stdin

         ,

         ((void *)0)

             ,

         2

         ,
         0);
     setvbuf(

         stdout

         ,

         ((void *)0)

             ,

         2

         ,
         0);

     tcgetattr(

         0

         ,
         &terminalOld);
     atexit(RestoreTerminal);
     struct termios t = terminalOld;
     t.c_lflag &= ~

                  0000010

         ;
     t.c_lflag &= ~

                  0000002

         ;
     tcsetattr(

         0

         ,

         2

         ,
         &t);
}

void pwd() {
     char cwd[512];
 
     if (getcwd(cwd, sizeof(cwd)) != NULL) {
         printf("Current working directory: %s\n", cwd);
     } else {
         perror("getcwd() error");
     }
 
 }

 void dump_data(int n) {
     FILE *f = fopen("/tmp/memory.bin","w");

     size_t written = fwrite(data, sizeof(data[0]), n, f);

     if (written != n) {
          perror("Failed to write entire buffer");
      }

     fclose(f);

 }

int main(int argc, const char * argv[])
{
     printf("lnxespforth, ver. 1.1\n");
     const char * fname = "boot.fs";

     if (argc == 2) {
          fname = argv[1];
     }

     // pwd();

     Init();
     S = 0;
     R = 0;
     top = 0;
     links = 0;
     IP = 0x100;

     int TTIB = VARIABLE("'TIB");
     IP += 0x100;
     int NFIB = VARIABLE("#FIB");
     SET_VAR(NFIB, 0x4000);
     int FIB = VARIABLE("FIB");
     IP += 0x4000;
     int CONTEXT = VARIABLE("CONTEXT");
     int CP = VARIABLE("CP");
     int LAST = VARIABLE("LAST");
     int TEVAL = VARIABLE("'EVAL");
     int TABORT = VARIABLE("'ABORT");
     int HLD = VARIABLE("HLD");
     int SPAN = VARIABLE("SPAN");
     int INN = VARIABLE(">IN");
     int NTIB = VARIABLE("#TIB");
     int TEMP = VARIABLE("tmp");
     int BASE = VARIABLE("BASE");

     NOP = CODE("NOP", as_NOP, as_NEXTT);
     ACCEPT = CODE("ACCEPT", as_ACCEPT, as_NEXTT);
     QKEY = CODE("?KEY", as_QKEY, as_NEXTT);
     EMIT = CODE("EMIT", as_EMIT, as_NEXTT);
     DOCON = CODE("DOCON", as_DOCON, as_NEXTT);
     DOLIT = CODE("DOLIT", as_DOLIT, as_NEXTT);
     DOLIST = CODE("DOLIST", as_DOLIST, as_NEXTT);
     EXIT = CODE("EXIT", as_EXIT, as_NEXTT);
     EXECUTE = CODE("EXECUTE", as_EXECUTE, as_NEXTT);
     DONEXT = CODE("DONEXT", as_DONEXT, as_NEXTT);
     QBRANCH = CODE("QBRANCH", as_QBRANCH, as_NEXTT);
     BRANCH = CODE("BRANCH", as_BRANCH, as_NEXTT);
     STORE = CODE("!", as_STORE, as_NEXTT);
     AT = CODE("@", as_AT, as_NEXTT);
     CSTORE = CODE("C!", as_CSTORE, as_NEXTT);
     CAT = CODE("C@", as_CAT, as_NEXTT);
     RPAT = CODE("RPAT", as_RPAT, as_NEXTT);
     RPSTO = CODE("RPSTO", as_RPSTO, as_NEXTT);
     RFROM = CODE("R>", as_RFROM, as_NEXTT);
     RAT = CODE("R@", as_RAT, as_NEXTT);
     TOR = CODE(">R", as_TOR, as_NEXTT);
     SPAT = CODE("SPAT", as_SPAT, as_NEXTT);
     SPSTO = CODE("SPSTO", as_SPSTO, as_NEXTT);
     DROP = CODE("DROP", as_DROP, as_NEXTT);
     DUP = CODE("DUP", as_DUP, as_NEXTT);
     SWAP = CODE("SWAP", as_SWAP, as_NEXTT);
     OVER = CODE("OVER", as_OVER, as_NEXTT);
     ZLESS = CODE("0<", as_ZLESS, as_NEXTT);
     AND = CODE("AND", as_AND, as_NEXTT);
     OR = CODE("OR", as_OR, as_NEXTT);
     XOR = CODE("XOR", as_XOR, as_NEXTT);
     UPLUS = CODE("U+", as_UPLUS, as_NEXTT);
     NEXTT = CODE("NEXT", as_NEXTT, as_NEXTT);
     QDUP = CODE("?DUP", as_QDUP, as_NEXTT);
     ROT = CODE("ROT", as_ROT, as_NEXTT);
     DDROP = CODE("2DROP", as_DDROP, as_NEXTT);
     DDUP = CODE("2DUP", as_DDUP, as_NEXTT);
     PLUS = CODE("+", as_PLUS, as_NEXTT);
     INVERSE = CODE("INVERSE", as_INVERSE, as_NEXTT);
     NEGATE = CODE("NEGATE", as_NEGATE, as_NEXTT);
     DNEGATE = CODE("DNEGATE", as_DNEGATE, as_NEXTT);
     SUB = CODE("-", as_SUB, as_NEXTT);
     ABS = CODE("ABS", as_ABS, as_NEXTT);
     EQUAL = CODE("=", as_EQUAL, as_NEXTT);
     ULESS = CODE("U<", as_ULESS, as_NEXTT);
     LESS = CODE("<", as_LESS, as_NEXTT);
     UMMOD = CODE("UM/MOD", as_UMMOD, as_NEXTT);
     MSMOD = CODE("M/MOD", as_MSMOD, as_NEXTT);
     SLMOD = CODE("/MOD", as_SLMOD, as_NEXTT);
     MOD = CODE("MOD", as_MOD, as_NEXTT);
     SLASH = CODE("/", as_SLASH, as_NEXTT);
     UMSTA = CODE("UM*", as_UMSTA, as_NEXTT);
     STAR = CODE("*", as_STAR, as_NEXTT);
     MSTAR = CODE("M*", as_MSTAR, as_NEXTT);
     SSMOD = CODE("*/MOD", as_SSMOD, as_NEXTT);
     STASL = CODE("*/", as_STASL, as_NEXTT);
     PICK = CODE("PICK", as_PICK, as_NEXTT);
     PSTORE = CODE("+!", as_PSTORE, as_NEXTT);
     DSTORE = CODE("2!", as_DSTORE, as_NEXTT);
     DAT = CODE("2@", as_DAT, as_NEXTT);
     COUNT = CODE("COUNT", as_COUNT, as_NEXTT);
     DOVAR = CODE("DOVAR", as_DOVAR, as_NEXTT);
     MAX = CODE("MAX", as_MAX, as_NEXTT);
     MIN = CODE("MIN", as_MIN, as_NEXTT);
     TONE = CODE("TONE", as_TONE, as_NEXTT);
     sendPacket = CODE("sendPacket", as_sendPacket, as_NEXTT);
     POKE = CODE("POKE", as_POKE, as_NEXTT);
     PEEK = CODE("PEEK", as_PEEK, as_NEXTT);
     ADC = CODE("ADC", as_ADC, as_NEXTT);
     PIN = CODE("PIN", as_PIN, as_NEXTT);
     DUTY = CODE("DUTY", as_DUTY, as_NEXTT);
     FREQ = CODE("FREQ", as_FREQ, as_NEXTT);
     MS = CODE("MS", as_MS, as_NEXTT);
     TERMINATE = CODE("TERMINATE", as_TERMINATE, as_NEXTT);
     R_O = CODE("r/o", as_R_O, as_NEXTT);
     R_W = CODE("r/w", as_R_W, as_NEXTT);
     W_O = CODE("w/o", as_W_O, as_NEXTT);
     BIN = CODE("bin", as_BIN, as_NEXTT);
     CLOSE_FILE = CODE("close-file", as_CLOSE_FILE, as_NEXTT);
     OPEN_FILE = CODE("open-file", as_OPEN_FILE, as_NEXTT);
     CREATE_FILE = CODE("create-file", as_CREATE_FILE, as_NEXTT);
     DELETE_FILE = CODE("delete-file", as_DELETE_FILE, as_NEXTT);
     WRITE_FILE = CODE("write-file", as_WRITE_FILE, as_NEXTT);
     READ_FILE = CODE("read-file", as_READ_FILE, as_NEXTT);
     FILE_POSITION = CODE("file-position", as_FILE_POSITION, as_NEXTT);
     REPOSITION_FILE = CODE("reposition-file", as_REPOSITION_FILE, as_NEXTT);
     RESIZE_FILE = CODE("resize-file", as_RESIZE_FILE, as_NEXTT);
     FILE_SIZE = CODE("file-size", as_FILE_SIZE, as_NEXTT);

     int BLANK = CONSTANT("BL", ' ');
     CONSTANT("CELL", sizeof(cell_t));
     int CELLP = CODE("CELL+",
                      as_DOCON, as_PLUS, as_NEXTT);
     Comma(sizeof(cell_t));
     int CELLM = CODE("CELL-",
                      as_DOCON, as_SUB, as_NEXTT);
     Comma(sizeof(cell_t));
     int CELLS = CODE("CELLS",
                      as_DOCON, as_STAR, as_NEXTT);
     Comma(sizeof(cell_t));
     int CELLD = CODE("CELL/",
                      as_DOCON, as_SLASH, as_NEXTT);
     Comma(sizeof(cell_t));
     int ONEP = CODE("1+", as_DOCON, as_PLUS, as_NEXTT);
     Comma(1);
     int ONEM = CODE("1-", as_DOCON, as_SUB, as_NEXTT);
     Comma(1);
     CODE("2+", as_DOCON, as_PLUS, as_NEXTT);
     Comma(2);
     CODE("2-", as_DOCON, as_SUB, as_NEXTT);
     Comma(2);
     CODE("2*", as_DOCON, as_STAR, as_NEXTT);
     Comma(2);
     CODE("2/", as_DOCON, as_SLASH, as_NEXTT);
     Comma(2);

     COLON_WITH_FLAGS(0, "BYE", DOLIT, 0, TERMINATE, EXIT);
     COLON_WITH_FLAGS(0, "KEY", BEGIN, QKEY, UNTIL, EXIT);
     int WITHI = COLON_WITH_FLAGS(0, "WITHIN", OVER, SUB, TOR, SUB, RFROM, ULESS, EXIT);
     int TCHAR = COLON_WITH_FLAGS(0, ">CHAR", DOLIT, 0x7F, AND, DUP, DOLIT, 127, BLANK, WITHI, IF, DROP, DOLIT, '_', THEN, EXIT);
     int ALIGN = COLON_WITH_FLAGS(0, "ALIGNED", DOLIT, (sizeof(cell_t) - 1), PLUS, DOLIT, (sizeof(cell_t) - 1), INVERSE, AND, EXIT);
     int HERE = COLON_WITH_FLAGS(0, "HERE", CP, AT, EXIT);
     int PAD = COLON_WITH_FLAGS(0, "PAD", HERE, DOLIT, 80, PLUS, EXIT);
     int TIB = COLON_WITH_FLAGS(0, "TIB", TTIB, AT, EXIT);
     int ATEXE = COLON_WITH_FLAGS(0, "@EXECUTE", AT, QDUP, IF, EXECUTE, THEN, EXIT);
     int CMOVEE = COLON_WITH_FLAGS(0, "CMOVE", FOR, AFT, OVER, CAT, OVER, CSTORE, TOR, ONEP, RFROM, ONEP, THEN, NEXT, DDROP, EXIT)

         ;
     COLON_WITH_FLAGS(0, "MOVE", CELLD, FOR, AFT, OVER, AT, OVER, STORE, TOR, CELLP, RFROM, CELLP, THEN, NEXT, DDROP, EXIT);
     COLON_WITH_FLAGS(0, "FILL", SWAP, FOR, SWAP, AFT, DDUP, CSTORE, ONEP, THEN, NEXT, DDROP, EXIT);
     int DIGIT = COLON_WITH_FLAGS(0, "DIGIT", DOLIT, 9, OVER, LESS, DOLIT, 7, AND, PLUS, DOLIT, '0', PLUS, EXIT);
     int EXTRC = COLON_WITH_FLAGS(0, "EXTRACT", DOLIT, 0, SWAP, UMMOD, SWAP, DIGIT, EXIT);
     int BDIGS = COLON_WITH_FLAGS(0, "<#", PAD, HLD, STORE, EXIT);
     int HOLD = COLON_WITH_FLAGS(0, "HOLD", HLD, AT, ONEM, DUP, HLD, STORE, CSTORE, EXIT);
     int DIG = COLON_WITH_FLAGS(0, "#", BASE, AT, EXTRC, HOLD, EXIT);
     int DIGS = COLON_WITH_FLAGS(0, "#S", BEGIN, DIG, DUP, WHILE, REPEAT, EXIT);
     int SIGN = COLON_WITH_FLAGS(0, "SIGN", ZLESS, IF, DOLIT, '-', HOLD, THEN, EXIT);
     int EDIGS = COLON_WITH_FLAGS(0, "#>", DROP, HLD, AT, PAD, OVER, SUB, EXIT);
     int STRR = COLON_WITH_FLAGS(0, "str", DUP, TOR, ABS, BDIGS, DIGS, RFROM, SIGN, EDIGS, EXIT);
     int HEX = COLON_WITH_FLAGS(0, "HEX", DOLIT, 16, BASE, STORE, EXIT);
     COLON_WITH_FLAGS(0, "DECIMAL", DOLIT, 10, BASE, STORE, EXIT);
     int UMASK = CONSTANT("UMASK", 0x5f5f5f5f5f5f5f5f);
     int UPPER = COLON_WITH_FLAGS(0, "wupper", UMASK, AND, EXIT);
     int TOUPP = COLON_WITH_FLAGS(0, ">upper", DUP, DOLIT, 'a', DOLIT, '{', WITHI, IF, DOLIT, 0x5F, AND, THEN, EXIT);
     int DIGTQ = COLON_WITH_FLAGS(0, "DIGIT?", TOR, TOUPP, DOLIT, '0', SUB, DOLIT, 9, OVER, LESS, IF, DOLIT, 7, SUB, DUP, DOLIT, 10, LESS, OR, THEN, DUP, RFROM, ULESS, EXIT)

         ;
     int NUMBQ = COLON_WITH_FLAGS(0, "NUMBER?", BASE, AT, TOR, DOLIT, 0, OVER, COUNT, OVER, CAT, DOLIT, '$', EQUAL, IF, HEX, SWAP, ONEP, SWAP, ONEM, THEN, OVER, CAT, DOLIT, '-', EQUAL, TOR, SWAP, RAT, SUB, SWAP, RAT, PLUS, QDUP, IF, ONEM, FOR, DUP, TOR, CAT, BASE, AT, DIGTQ, WHILE, SWAP, BASE, AT, STAR, PLUS, RFROM, ONEP, NEXT, DROP, RAT, IF, NEGATE, THEN, SWAP, ELSE, RFROM, RFROM, DDROP, DDROP, DOLIT, 0, THEN, DUP, THEN, RFROM, DDROP, RFROM, BASE, STORE, EXIT)

         ;
     int SPACE = COLON_WITH_FLAGS(0, "SPACE", BLANK, EMIT, EXIT);
     int CHARS = COLON_WITH_FLAGS(0, "CHARS", SWAP, DOLIT, 0, MAX, FOR, AFT, DUP, EMIT, THEN, NEXT, DROP, EXIT);
     int SPACS = COLON_WITH_FLAGS(0, "SPACES", BLANK, CHARS, EXIT);
     int TYPES = COLON_WITH_FLAGS(0, "TYPE", FOR, AFT, DUP, CAT, TCHAR, EMIT, ONEP, THEN, NEXT, DROP, EXIT);
     int CR = COLON_WITH_FLAGS(0, "CR", DOLIT, '\n', DOLIT, '\r', EMIT, EMIT, EXIT);
     int DOSTR = COLON_WITH_FLAGS(0, "do$", RFROM, RAT, RFROM, COUNT, PLUS, ALIGN, TOR, SWAP, TOR, EXIT);
     STRQP = COLON_WITH_FLAGS(0, "$\"|", DOSTR, EXIT);
     DOTQP = COLON_WITH_FLAGS(0, ".\"|", DOSTR, COUNT, TYPES, EXIT);
     COLON_WITH_FLAGS(0, ".R", TOR, STRR, RFROM, OVER, SUB, SPACS, TYPES, EXIT);
     int UDOTR = COLON_WITH_FLAGS(0, "U.R", TOR, BDIGS, DIGS, EDIGS, RFROM, OVER, SUB, SPACS, TYPES, EXIT);
     int UDOT = COLON_WITH_FLAGS(0, "U.", BDIGS, DIGS, EDIGS, SPACE, TYPES, EXIT);
     int DOT = COLON_WITH_FLAGS(0, ".", BASE, AT, DOLIT, 10, XOR, IF, UDOT, EXIT, THEN, STRR, SPACE, TYPES, EXIT);
     COLON_WITH_FLAGS(0, "?", AT, DOT, EXIT);
     int PARS = COLON_WITH_FLAGS(0, "(parse)", TEMP, CSTORE, OVER, TOR, DUP, IF, ONEM, TEMP, CAT, BLANK, EQUAL, IF, FOR, BLANK, OVER, CAT, SUB, ZLESS, INVERSE, WHILE, ONEP, NEXT, RFROM, DROP, DOLIT, 0, DUP, EXIT, THEN, RFROM, THEN, OVER, SWAP, FOR, TEMP, CAT, OVER, CAT, SUB, TEMP, CAT, BLANK, EQUAL, IF, ZLESS, THEN, WHILE, ONEP, NEXT, DUP, TOR, ELSE, RFROM, DROP, DUP, ONEP, TOR, THEN, OVER, SUB, RFROM, RFROM, SUB, EXIT, THEN, OVER, RFROM, SUB, EXIT)

         ;

     int PACKS = COLON_WITH_FLAGS(0, "PACK$", DUP, TOR, DDUP, PLUS, DOLIT, (sizeof(cell_t) - 1), INVERSE, AND, DOLIT, 0, SWAP, STORE, DDUP, CSTORE, ONEP, SWAP, CMOVEE, RFROM, EXIT);
     int PARSE = COLON_WITH_FLAGS(0, "PARSE", TOR, TIB, INN, AT, PLUS, NTIB, AT, INN, AT, SUB, RFROM, PARS, INN, PSTORE, EXIT);
     int TOKEN = COLON_WITH_FLAGS(0, "TOKEN", BLANK, PARSE, DOLIT, 0x1F, MIN, HERE, CELLP, PACKS, EXIT);
     int WORDD = COLON_WITH_FLAGS(0, "WORD", PARSE, HERE, CELLP, PACKS, EXIT);

     int NAMET = COLON_WITH_FLAGS(0, "NAME>", COUNT, DOLIT, 0x1F, AND, PLUS, ALIGN, EXIT);

     int SAMEQ = COLON_WITH_FLAGS(0, "SAME?", DOLIT, 0x1F, AND, CELLD, FOR, AFT, OVER, RAT, CELLS, PLUS, AT, UPPER, OVER, RAT, CELLS, PLUS, AT, UPPER, SUB, QDUP, IF, RFROM, DROP, EXIT, THEN, THEN, NEXT, DOLIT, 0, EXIT)

         ;

     int FIND = COLON_WITH_FLAGS(0, "find", SWAP, DUP, AT, TEMP, STORE, DUP, AT, TOR, CELLP, SWAP, BEGIN, AT, DUP, IF, DUP, AT, DOLIT, 0xC0, INVERSE, AND, UPPER, RAT, UPPER, XOR, IF, CELLP, DOLIT, -1, ELSE, CELLP, TEMP, AT, SAMEQ, THEN, ELSE, RFROM, DROP, SWAP, CELLM, SWAP, EXIT, THEN, WHILE, CELLM, CELLM, REPEAT, RFROM, DROP, SWAP, DROP, CELLM, DUP, NAMET, SWAP, EXIT)

         ;
     int NAMEQ = COLON_WITH_FLAGS(0, "NAME?", CONTEXT, FIND, EXIT);
     COLON_WITH_FLAGS(0, "EXPECT", ACCEPT, SPAN, STORE, DROP, EXIT);
     int QUERY = COLON_WITH_FLAGS(0, "QUERY", TIB, DOLIT, 0x100, ACCEPT, NTIB, STORE, DROP, DOLIT, 0, INN, STORE, EXIT);
     int ABORT = COLON_WITH_FLAGS(0, "ABORT", NOP, TABORT, ATEXE, EXIT);
     ABORQP = COLON_WITH_FLAGS(0, "abort\"", IF, DOSTR, COUNT, TYPES, ABORT, THEN, DOSTR, DROP, EXIT);
     int ERRORR = COLON_WITH_FLAGS(0, "ERROR", SPACE, COUNT, TYPES, DOLIT, '?', EMIT, CR, ABORT, EXIT);
     int INTER = COLON_WITH_FLAGS(0, "$INTERPRET", NAMEQ, QDUP, IF, CAT, DOLIT, COMPO, AND, ABORTQ, " compile only", EXECUTE, EXIT, THEN, NUMBQ, IF, EXIT, THEN, ERRORR, EXIT)

         ;
     int LBRAC = COLON_WITH_FLAGS(IMEDD, "[", DOLIT, INTER, TEVAL, STORE, EXIT);
     int DOTOK = COLON_WITH_FLAGS(0, ".OK", CR, DOLIT, INTER, TEVAL, AT, EQUAL, IF, TOR, TOR, TOR, DUP, DOT, RFROM, DUP, DOT, RFROM, DUP, DOT, RFROM, DUP, DOT, DOTQ, " ok> ", THEN, EXIT)

         ;
     int EVAL = COLON_WITH_FLAGS(0, "EVAL", LBRAC, BEGIN, TOKEN, DUP, AT, WHILE, TEVAL, ATEXE, REPEAT, DROP, NOP, EXIT);
     int QUIT = COLON_WITH_FLAGS(0, "QUIT", LBRAC, BEGIN, DOTOK, QUERY, EVAL, AGAIN, EXIT);
     int LOAD = COLON_WITH_FLAGS(0, "LOAD", TTIB, AT, TOR, NTIB, STORE, TTIB, STORE, DOLIT, 0, INN, STORE, EVAL, RFROM, TTIB, STORE, EXIT);
     int COMMA = COLON_WITH_FLAGS(0, ",", HERE, DUP, CELLP, CP, STORE, STORE, EXIT);
     int LITER = COLON_WITH_FLAGS(IMEDD, "LITERAL", DOLIT, DOLIT, COMMA, COMMA, EXIT);
     COLON_WITH_FLAGS(0, "ALLOT", ALIGN, CP, PSTORE, EXIT);
     int STRCQ = COLON_WITH_FLAGS(0, "$,\"", DOLIT, '"', WORDD, COUNT, PLUS, ALIGN, CP, STORE, EXIT);
     int UNIQU = COLON_WITH_FLAGS(0, "?UNIQUE", DUP, NAMEQ, QDUP, IF, COUNT, DOLIT, 0x1F, AND, SPACE, TYPES, DOTQ, " reDef", THEN, DROP, EXIT)

         ;
     int SNAME = COLON_WITH_FLAGS(0, "$,n", DUP, AT, IF, UNIQU, DUP, NAMET, CP, STORE, DUP, LAST, STORE, CELLM, CONTEXT, AT, SWAP, STORE, EXIT, THEN, ERRORR, EXIT)

         ;
     int TICK = COLON_WITH_FLAGS(0, "'", TOKEN, NAMEQ, IF, EXIT, THEN, ERRORR, EXIT);
     COLON_WITH_FLAGS(IMEDD, "[COMPILE]", TICK, COMMA, EXIT);
     int COMPI = COLON_WITH_FLAGS(0, "COMPILE", RFROM, DUP, AT, COMMA, CELLP, TOR, EXIT);
     int SCOMP = COLON_WITH_FLAGS(0, "$COMPILE", NAMEQ, QDUP, IF, AT, DOLIT, IMEDD, AND, IF, EXECUTE, ELSE, COMMA, THEN, EXIT, THEN, NUMBQ, IF, LITER, EXIT, THEN, ERRORR, EXIT)

         ;
     int OVERT = COLON_WITH_FLAGS(0, "OVERT", LAST, AT, CONTEXT, STORE, EXIT);
     int RBRAC = COLON_WITH_FLAGS(0, "]", DOLIT, SCOMP, TEVAL, STORE, EXIT);
     COLON_WITH_FLAGS(0, ":", TOKEN, SNAME, RBRAC, DOLIT, as_DOLIST, COMMA, EXIT);
     COLON_WITH_FLAGS(IMEDD, ";", DOLIT, EXIT, COMMA, LBRAC, OVERT, EXIT);
     int DMP = COLON_WITH_FLAGS(0, "dm+", OVER, DOLIT, 6, UDOTR, FOR, AFT, DUP, AT, DOLIT, 9, UDOTR, CELLP, THEN, NEXT, EXIT)

         ;
     COLON_WITH_FLAGS(0, "DUMP", BASE, AT, TOR, HEX, DOLIT, 0x1F, PLUS, DOLIT, 0x20, SLASH, FOR, AFT, CR, DOLIT, 8, DDUP, DMP, TOR, SPACE, CELLS, TYPES, RFROM, THEN, NEXT, DROP, RFROM, BASE, STORE, EXIT)

         ;
     COLON_WITH_FLAGS(0, ">NAME", CONTEXT, BEGIN, AT, DUP, WHILE, DDUP, NAMET, XOR, IF, ONEM, ELSE, SWAP, DROP, EXIT, THEN, REPEAT, SWAP, DROP, EXIT);
     int DOTID = COLON_WITH_FLAGS(0, ".ID", COUNT, DOLIT, 0x1F, AND, TYPES, SPACE, EXIT);
     COLON_WITH_FLAGS(0, "WORDS", CR, CONTEXT, DOLIT, 0, TEMP, STORE, BEGIN, AT, QDUP, WHILE, DUP, SPACE, DOTID, CELLM, TEMP, AT, DOLIT, 8, LESS, IF, DOLIT, 1, TEMP, PSTORE, ELSE, CR, DOLIT, 0, TEMP, STORE, THEN, REPEAT, EXIT)

         ;
     COLON_WITH_FLAGS(0, "FORGET", TOKEN, NAMEQ, QDUP, IF, CELLM, DUP, CP, STORE, AT, DUP, CONTEXT, STORE, LAST, STORE, DROP, EXIT, THEN, ERRORR, EXIT)

         ;
     int BOOT = COLON_WITH_FLAGS(0, "BOOT", STRQ, fname, COUNT, R_O, OPEN_FILE, IF, DROP, ELSE, FIB, SWAP, DOLIT, NFIB, AT, SWAP, READ_FILE, IF, DROP, ELSE, FIB, SWAP, LOAD, THEN, THEN, EXIT)

         ;
     COLD = COLON_WITH_FLAGS(0, "COLD", BOOT, DOTQ, "AIBOT ESP32 Forth", CR, BEGIN, QUIT, AGAIN, EXIT);
     int LINE = COLON_WITH_FLAGS(0, "LINE", DOLIT, 0x7, FOR, DUP, PEEK, DOLIT, 0x9, UDOTR, CELLP, NEXT, EXIT);
     int PP = COLON_WITH_FLAGS(0, "PP", FOR, AFT, CR, DUP, DOLIT, 0x9, UDOTR, SPACE, LINE, THEN, NEXT, EXIT);
     COLON_WITH_FLAGS(0, "P0", DOLIT, 0x3FF44004, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P0S", DOLIT, 0x3FF44008, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P0C", DOLIT, 0x3FF4400C, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P1", DOLIT, 0x3FF44010, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P1S", DOLIT, 0x3FF44014, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P1C", DOLIT, 0x3FF44018, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P0EN", DOLIT, 0x3FF44020, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P0ENS", DOLIT, 0x3FF44024, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P0ENC", DOLIT, 0x3FF44028, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P1EN", DOLIT, 0x3FF4402C, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P1ENS", DOLIT, 0x3FF44030, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P1ENC", DOLIT, 0x3FF44034, POKE, EXIT);
     COLON_WITH_FLAGS(0, "P0IN", DOLIT, 0x3FF4403C, PEEK, DOT, EXIT);
     COLON_WITH_FLAGS(0, "P1IN", DOLIT, 0x3FF44040, PEEK, DOT, EXIT);
     COLON_WITH_FLAGS(0, "PPP", DOLIT, 0x3FF44000, DOLIT, 3, PP, DROP, EXIT);
     int EMITT = COLON_WITH_FLAGS(0, "EMITT", DOLIT, 0x3, FOR, DOLIT, 0, DOLIT, 0x100, MSMOD, SWAP, TCHAR, EMIT, NEXT, DROP, EXIT);
     int TYPEE = COLON_WITH_FLAGS(0, "TYPEE", SPACE, DOLIT, 0x7, FOR, DUP, PEEK, EMITT, CELLP, NEXT, DROP, EXIT);
     COLON_WITH_FLAGS(0, "PPPP", FOR, AFT, CR, DUP, DUP, DOLIT, 0x9, UDOTR, SPACE, LINE, SWAP, TYPEE, THEN, NEXT, EXIT);
     COLON_WITH_FLAGS(0, "KKK", DOLIT, 0x3FF59000, DOLIT, 0x10, PP, DROP, EXIT);
     int THENN = COLON_WITH_FLAGS(IMEDD, "THEN", HERE, SWAP, STORE, EXIT);
     COLON_WITH_FLAGS(IMEDD, "FOR", COMPI, TOR, HERE, EXIT);
     COLON_WITH_FLAGS(IMEDD, "BEGIN", HERE, EXIT);
     COLON_WITH_FLAGS(IMEDD, "NEXT", COMPI, DONEXT, COMMA, EXIT);
     COLON_WITH_FLAGS(IMEDD, "UNTIL", COMPI, QBRANCH, COMMA, EXIT);
     int AGAINN = COLON_WITH_FLAGS(IMEDD, "AGAIN", COMPI, BRANCH, COMMA, EXIT);
     int IFF = COLON_WITH_FLAGS(IMEDD, "IF", COMPI, QBRANCH, HERE, DOLIT, 0, COMMA, EXIT);
     int AHEAD = COLON_WITH_FLAGS(IMEDD, "AHEAD", COMPI, BRANCH, HERE, DOLIT, 0, COMMA, EXIT);
     COLON_WITH_FLAGS(IMEDD, "REPEAT", AGAINN, THENN, EXIT);
     COLON_WITH_FLAGS(IMEDD, "AFT", DROP, AHEAD, HERE, SWAP, EXIT);
     COLON_WITH_FLAGS(IMEDD, "ELSE", AHEAD, SWAP, THENN, EXIT);
     COLON_WITH_FLAGS(IMEDD, "WHILE", IFF, SWAP, EXIT);
     COLON_WITH_FLAGS(IMEDD, "ABORT\"", DOLIT, ABORQP, HERE, STORE, STRCQ, EXIT);
     COLON_WITH_FLAGS(IMEDD, "$\"", DOLIT, STRQP, HERE, STORE, STRCQ, EXIT);
     COLON_WITH_FLAGS(IMEDD, ".\"", DOLIT, DOTQP, HERE, STORE, STRCQ, EXIT);
     int CODE = COLON_WITH_FLAGS(0, "CODE", TOKEN, SNAME, OVERT, HERE, ALIGN, CP, STORE, EXIT);
     int CREATE = COLON_WITH_FLAGS(0, "CREATE", CODE, DOLIT, as_DOVAR + (as_NEXTT << 8), COMMA, EXIT);
     COLON_WITH_FLAGS(0, "VARIABLE", CREATE, DOLIT, 0, COMMA, EXIT);
     COLON_WITH_FLAGS(0, "CONSTANT", CODE, DOLIT, as_DOCON + (as_NEXTT << 8), COMMA, COMMA, EXIT);
     COLON_WITH_FLAGS(IMEDD, ".(", DOLIT, ')', PARSE, TYPES, EXIT);
     COLON_WITH_FLAGS(IMEDD, "\\", DOLIT, '\n', WORDD, DROP, EXIT);
     COLON_WITH_FLAGS(IMEDD, "(", DOLIT, ')', PARSE, DDROP, EXIT);
     COLON_WITH_FLAGS(IMEDD, "COMPILE-ONLY", DOLIT, COMPO, LAST, AT, PSTORE, EXIT);
     COLON_WITH_FLAGS(0, "IMMEDIATE", DOLIT, IMEDD, LAST, AT, PSTORE, EXIT);

     SET_VAR(CP, IP);
     SET_VAR(BASE, 10);
     SET_VAR(TEVAL, INTER);
     SET_VAR(TABORT, EVAL);
     SET_VAR(CONTEXT, links);
     SET_VAR(LAST, links);

     // log("ready to run\n");

     // dump_data(IP/sizeof(cell_t));

     run();
}
