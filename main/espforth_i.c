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

#include <ctype.h>

// #define esp32
// #define BB_LOG

#include <termios.h>
#include <unistd.h>

#ifdef BB_LOG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...)
#endif

// #define OLD_ACCEPT
// #define TRACE_EXECUTION
#define ABORT_IF_UNDERFLOW 0
// #define SIMPLE_DOTOK

static const char *TAG = "espforth";

typedef intptr_t cell_t;
typedef uintptr_t ucell_t;

typedef __int128_t dcell_t;
typedef __uint128_t udcell_t;

static cell_t rack[256] = {0}, stack[256] = {0};
static unsigned char R = 0, S = 0;

int Smm() {
     unsigned char x = S--;

     if (x == 0 && ABORT_IF_UNDERFLOW) {
          printf("stack underflow\n");
          abort();
     }

     return x;
}

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
static int DUMP = 0;

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

#ifdef OLD_ACCEPT
static void fun_ACCEPT(void) { top = duplexread(cData, top); }
#else
static void fun_ACCEPT(void) { WP=top; top=stack[(unsigned char)Smm()]; top = duplexread(cData+top, WP);}
#endif 
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
     top = stack[(unsigned char)Smm()];
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
     #ifdef DUMP_STACK
     printf("\nexit, top=%ld, S=%d, ",top,S);
     for(int s = S; s>=0; s--) {
          printf("s[%d]=%ld, ",s,stack[s]);
     }

     printf("\n");
     #endif
}
static void fun_EXECUTE(void)
{
     P = top;
     WP = P + sizeof(cell_t);
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
     next();
}
static void fun_BRANCH(void)
{
     IP = data[IP / sizeof(cell_t)];
     next();
}
static void fun_STORE(void)
{
     data[top / sizeof(cell_t)] = stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
}
static void fun_AT(void) { top = data[top / sizeof(cell_t)]; }
static void fun_CSTORE(void)
{
     cData[top] = (unsigned char)stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
}
static void fun_CAT(void) { top = (cell_t)cData[top]; }
static void fun_RPAT(void) { ; }
static void fun_RPSTO(void) { ; }
static void fun_RFROM(void) { stack[(unsigned char)++S] = top, top = rack[(unsigned char)R--]; }
static void fun_RAT(void) { stack[(unsigned char)++S] = top, top = rack[(unsigned char)R]; }
static void fun_TOR(void)
{
     rack[(unsigned char)++R] = top;
     top = stack[(unsigned char)Smm()];
}
static void fun_SPAT(void) { ; }
static void fun_SPSTO(void) { ; }
static void fun_DROP(void) { top = stack[(unsigned char)Smm()]; }
static void fun_DUP(void) { stack[(unsigned char)++S] = top; }
static void fun_SWAP(void)
{
     WP = top;
     top = stack[(unsigned char)S];
     stack[(unsigned char)S] = WP;
}
static void fun_OVER(void) { stack[(unsigned char)++S] = top, top = stack[(unsigned char)(S - 1)]; }
static void fun_ZLESS(void) { top = (top < 0) ? -1 : 0; }
static void fun_AND(void) { top &= stack[(unsigned char)Smm()]; }
static void fun_OR(void) { top |= stack[(unsigned char)Smm()]; }
static void fun_XOR(void) { top ^= stack[(unsigned char)Smm()]; }
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
static void fun_PLUS(void) { top += stack[(unsigned char)Smm()]; }
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
static void fun_SUB(void) { top = stack[(unsigned char)Smm()] - top; }
static void fun_ABS(void)
{
     if (top < 0)
          top = -top;
}
static void fun_EQUAL(void) { top = (stack[(unsigned char)Smm()] == top) ? -1 : 0; }
static void fun_ULESS(void)
{
     top = ((ucell_t)(stack[(unsigned char)S]) < (ucell_t)(top)) ? -1 : 0;
     Smm();
}
static void fun_LESS(void) { top = (stack[(unsigned char)Smm()] < top) ? -1 : 0; }
static void fun_UMMOD(void)
{
     d = (udcell_t)((ucell_t)top);
     m = (udcell_t)((ucell_t)stack[(unsigned char)S]);
     n = (udcell_t)((ucell_t)stack[(unsigned char)(S - 1)]);
     n += m << (sizeof(cell_t) * 8);
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
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
static void fun_MOD(void) { top = (top) ? stack[(unsigned char)Smm()] % top : stack[(unsigned char)Smm()]; }
static void fun_SLASH(void) { top = (top) ? stack[(unsigned char)Smm()] / top : (Smm(), 0); }
static void fun_UMSTA(void)
{
     d = (udcell_t)top;
     m = (udcell_t)stack[(unsigned char)S];
     m *= d;
     top = (ucell_t)(m >> (sizeof(cell_t) * 8));
     stack[(unsigned char)S] = (ucell_t)m;
}
static void fun_STAR(void) { top *= stack[(unsigned char)Smm()]; }
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
     top = stack[(unsigned char)Smm()];
     top = (cell_t)(n / d);
     stack[(unsigned char)S] = (cell_t)(n % d);
}
static void fun_STASL(void)
{
     d = (dcell_t)top;
     m = (dcell_t)stack[(unsigned char)S];
     n = (dcell_t)stack[(unsigned char)(S - 1)];
     n *= m;
     top = stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
     top = (cell_t)(n / d);
}
static void fun_PICK(void) { top = stack[(unsigned char)(S - top)]; }
static void fun_PSTORE(void)
{
     data[top / sizeof(cell_t)] += stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
}
static void fun_DSTORE(void)
{
     data[(top / sizeof(cell_t)) + 1] = stack[(unsigned char)Smm()];
     data[top / sizeof(cell_t)] = stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
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
          top = stack[(unsigned char)Smm()];
     else
          Smm();
}
static void fun_MIN(void)
{
     if (top < stack[(unsigned char)S])
          Smm();
     else
          top = stack[(unsigned char)Smm()];
}
static void fun_TONE(void)
{
     WP = top;
     top = stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
}
static void fun_sendPacket(void) { ; }
static void fun_POKE(void)
{
     Pointer = (cell_t *)top;
     *Pointer = stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
     setpin(WP, top);
     top = stack[(unsigned char)Smm()];
}
static void fun_DUTY(void)
{
     WP = top;
     top = stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
}
static void fun_FREQ(void)
{
     WP = top;
     top = stack[(unsigned char)Smm()];
     top = stack[(unsigned char)Smm()];
}
static void fun_MS(void)
{
     WP = top;
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
     cell_t len = top;
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
     cell_t len = top;
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
     cell_t len = top;
     top = stack[(unsigned char)Smm()];
     top = write(fd, &cData[top], len);
     top = top != len ?

                      (*__errno_location())

                      : 0;
}
static void fun_READ_FILE(void)
{
     cell_t fd = top;
     top = stack[(unsigned char)Smm()];
     cell_t len = top;
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
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
     top = stack[(unsigned char)Smm()];
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

static void fun_DUMP1(void) {
     cell_t nchar = top;
     top = stack[(unsigned char)Smm()];

     cell_t addr = top;
     top = stack[(unsigned char)Smm()];

     for (cell_t i = 0; i< nchar; i++) {
          printf("'%c' %x ", cData[addr+i],cData[addr+i]);
          if ((i+1) % 16 == 0) {
               printf("\n");
          }
     }
}

#ifdef C_DOTK
static void fun_DOTOK() {

     if (S > 0) {
          printf("top: %ld ", top);
     } else {
          printf("top: n.a. ");
     }

     for (int i=S; i >= 2; i--) {
          printf("%ld ",stack[i]);
     }
     

     printf(" [%d] ok> ",  S);

}
#endif

// ----





static void fun_DUMP(void) {
     cell_t nchar = top;
     top = stack[(unsigned char)Smm()];

     cell_t addr = top;
     top = stack[(unsigned char)Smm()];

    size_t i, j;

    for (i = 0; i < nchar; i += 16) {
        // Print offset
        printf("%08zx: ", addr+i);

        // Print hex values
        for (j = 0; j < 16; ++j) {
            if (i + j < nchar)
                printf("%02x ", cData[addr+i + j]);
            else
                printf("   "); // Padding for short lines
        }

        // Print separator
        printf(" ");

        // Print ASCII characters
        for (j = 0; j < 16; ++j) {
            if (i + j < nchar) {
                unsigned char c = cData[addr+i + j];
                printf("%c", isprint(c) ? c : '.');
            }
        }

        printf("\n");
    }
}


// ----


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
    fun_DUMP
    #ifdef C_DOTK
    , fun_DOTOK
    #endif

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
     as_DUMP
     #ifdef C_DOTK
     ,as_DOTOK
     #endif

};

const char * code_name(int code) {
     switch(code) {
     case as_UNKNOWN: return "UNKNOWN";
     case as_NOP: return "NOP";
     case as_ACCEPT: return "ACCEPT";
     case as_QKEY: return "QKEY";
     case as_EMIT: return "EMIT";
     case as_DOCON: return "DOCON";
     case as_DOLIT: return "DOLIT";
     case as_DOLIST: return "DOLIST";
     case as_EXIT: return "EXIT";
     case as_EXECUTE: return "EXECUTE";
     case as_DONEXT: return "DONEXT";
     case as_QBRANCH: return "QBRANCH";
     case as_BRANCH: return "BRANCH";
     case as_STORE: return "STORE";
     case as_AT: return "AT";
     case as_CSTORE: return "CSTORE";
     case as_CAT: return "CAT";
     case as_RPAT: return "RPAT";
     case as_RPSTO: return "RPSTO";
     case as_RFROM: return "RFROM";
     case as_RAT: return "RAT";
     case as_TOR: return "TOR";
     case as_SPAT: return "SPAT";
     case as_SPSTO: return "SPSTO";
     case as_DROP: return "DROP";
     case as_DUP: return "DUP";
     case as_SWAP: return "SWAP";
     case as_OVER: return "OVER";
     case as_ZLESS: return "ZLESS";
     case as_AND: return "AND";
     case as_OR: return "OR";
     case as_XOR: return "XOR";
     case as_UPLUS: return "UPLUS";
     case as_NEXTT: return "NEXTT";
     case as_QDUP: return "QDUP";
     case as_ROT: return "ROT";
     case as_DDROP: return "DDROP";
     case as_DDUP: return "DDUP";
     case as_PLUS: return "PLUS";
     case as_INVERSE: return "INVERSE";
     case as_NEGATE: return "NEGATE";
     case as_DNEGATE: return "DNEGATE";
     case as_SUB: return "SUB";
     case as_ABS: return "ABS";
     case as_EQUAL: return "EQUAL";
     case as_ULESS: return "ULESS";
     case as_LESS: return "LESS";
     case as_UMMOD: return "UMMOD";
     case as_MSMOD: return "MSMOD";
     case as_SLMOD: return "SLMOD";
     case as_MOD: return "MOD";
     case as_SLASH: return "SLASH";
     case as_UMSTA: return "UMSTA";
     case as_STAR: return "STAR";
     case as_MSTAR: return "MSTAR";
     case as_SSMOD: return "SSMOD";
     case as_STASL: return "STASL";
     case as_PICK: return "PICK";
     case as_PSTORE: return "PSTORE";
     case as_DSTORE: return "DSTORE";
     case as_DAT: return "DAT";
     case as_COUNT: return "COUNT";
     case as_DOVAR: return "DOVAR";
     case as_MAX: return "MAX";
     case as_MIN: return "MIN";
     case as_TONE: return "TONE";
     case as_sendPacket: return "sendPacket";
     case as_POKE: return "POKE";
     case as_PEEK: return "PEEK";
     case as_ADC: return "ADC";
     case as_PIN: return "PIN";
     case as_DUTY: return "DUTY";
     case as_FREQ: return "FREQ";
     case as_MS: return "MS";
     case as_TERMINATE: return "TERMINATE";
     case as_R_O: return "R_O";
     case as_R_W: return "R_W";
     case as_W_O: return "W_O";
     case as_BIN: return "BIN";
     case as_CLOSE_FILE: return "CLOSE_FILE";
     case as_OPEN_FILE: return "OPEN_FILE";
     case as_CREATE_FILE: return "CREATE_FILE";
     case as_DELETE_FILE: return "DELETE_FILE";
     case as_WRITE_FILE: return "WRITE_FILE";
     case as_READ_FILE: return "READ_FILE";
     case as_FILE_POSITION: return "FILE_POSITION";
     case as_REPOSITION_FILE: return "REPOSITION_FILE";
     case as_RESIZE_FILE: return "RESIZE_FILE";
     case as_FILE_SIZE: return "FILE_SIZE";
     #ifdef C_DOTOK
     case as_DOTOK: return "DOTOK";
     #endif

     }

     return "<<code not mapped>>";
}


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

static int call_levels = 0;

static void run()
{
     P = COLD;
     WP = P + sizeof(cell_t);
     for (;;)
     {
          int lastP = P;
          unsigned char bytecode = cData[P++];
          #ifdef TRACE_EXECUTION
          printf("\n%3d: executing at: %u, bytecode: %d, name: %s\n",call_levels,lastP,bytecode, code_name(bytecode));

          if (bytecode == as_DOLIST) {
               call_levels++;
               printf("word: ");
          // int len = 0x1f & cData[P-9];
          for (int i=8; i >= 0; i--) {
               printf("%c",cData[P-i]);
          }
          printf("\n");

          } else if (bytecode == as_EXIT)
          {
               call_levels--;
          }
          
          #endif
          primitives[bytecode]();
          #ifdef TRACE_EXECUTION
          #ifdef C_DOTOK
          fun_DOTOK();
          #endif
          #endif

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
     DUMP = CODE("DUMP",as_DUMP, as_NEXTT);
     #ifdef C_DOTOK
     int DOTOK =  CODE("OK", as_DOTOK, as_NEXTT);
     #endif

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

     COLON_WITH_FLAGS(0, "EXPECT", ACCEPT, SPAN, STORE, EXIT);
     int QUERY = COLON_WITH_FLAGS(0, "QUERY", TIB, DOLIT, 0x100, ACCEPT, NTIB, STORE, DOLIT, 0, INN, STORE, EXIT);
     int ABORT = COLON_WITH_FLAGS(0, "ABORT", NOP, TABORT, ATEXE, EXIT);
     ABORQP = COLON_WITH_FLAGS(0, "abort\"", IF, DOSTR, COUNT, TYPES, ABORT, THEN, DOSTR, DROP, EXIT);
     int ERRORR = COLON_WITH_FLAGS(0, "ERROR", SPACE, COUNT, TYPES, DOLIT, '?', EMIT, CR, ABORT, EXIT);
     int INTER = COLON_WITH_FLAGS(0, "$INTERPRET", NAMEQ, QDUP, IF, CAT, DOLIT, COMPO, AND, ABORTQ, " compile only", EXECUTE, EXIT, THEN, NUMBQ, IF, EXIT, THEN, ERRORR, EXIT)

         ;
     int LBRAC = COLON_WITH_FLAGS(IMEDD, "[", DOLIT, INTER, TEVAL, STORE, EXIT);
     
     #ifndef C_DOTOK
     #ifndef SIMPLE_DOTOK
     #if ABORT_IF_UNDERFLOW == 1
     #error "cannot implement this with underflow detection"
     #endif
     // the word leverages the circularity of the espforth's data stack. it would do stack underflow is the stack contains less than 4 elemens
     int DOTOK = COLON_WITH_FLAGS(0, ".OK", CR, DOLIT, INTER, TEVAL, AT, EQUAL, IF, TOR, TOR, TOR, DUP, DOT, RFROM, DUP, DOT, RFROM, DUP, DOT, RFROM, DUP, DOT, DOTQ, " ok> ", THEN, EXIT);     
     #else
     int DOTOK = COLON_WITH_FLAGS(0, ".OK", CR, DOTQ, "ok> ", EXIT);
     #endif
     #endif

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
     // COLON_WITH_FLAGS(0, "DUMP", BASE, AT, TOR, HEX, DOLIT, 0x1F, PLUS, DOLIT, 0x20, SLASH, FOR, AFT, CR, DOLIT, 8, DDUP, DMP, TOR, SPACE, CELLS, TYPES, RFROM, THEN, NEXT, DROP, RFROM, BASE, STORE, EXIT)

     //    ;
     COLON_WITH_FLAGS(0, ">NAME", CONTEXT, BEGIN, AT, DUP, WHILE, DDUP, NAMET, XOR, IF, ONEM, ELSE, SWAP, DROP, EXIT, THEN, REPEAT, SWAP, DROP, EXIT);
     int DOTID = COLON_WITH_FLAGS(0, ".ID", COUNT, DOLIT, 0x1F, AND, TYPES, SPACE, EXIT);
     COLON_WITH_FLAGS(0, "WORDS", CR, CONTEXT, DOLIT, 0, TEMP, STORE, BEGIN, AT, QDUP, WHILE, DUP, SPACE, DOTID, CELLM, TEMP, AT, DOLIT, 8, LESS, IF, DOLIT, 1, TEMP, PSTORE, ELSE, CR, DOLIT, 0, TEMP, STORE, THEN, REPEAT, EXIT)

         ;
     COLON_WITH_FLAGS(0, "FORGET", TOKEN, NAMEQ, QDUP, IF, CELLM, DUP, CP, STORE, AT, DUP, CONTEXT, STORE, LAST, STORE, DROP, EXIT, THEN, ERRORR, EXIT)

         ;

     int INCLUDE = COLON_WITH_FLAGS(0, "INCLUDE", R_O, OPEN_FILE, IF, DROP, DOTQ, "file not found", CR, ELSE, DOTQ, "loading...", CR, FIB, SWAP, DOLIT, NFIB, AT, SWAP, READ_FILE, IF, DOTQ, "cannot read file:", DOT, CR, ELSE, FIB, SWAP, LOAD, DOTQ, "loaded.", CR, THEN, THEN, EXIT);
     int BOOT = COLON_WITH_FLAGS(0, "BOOT", STRQ, fname, COUNT, INCLUDE, EXIT)

         ;
     
     COLD = COLON_WITH_FLAGS(0, "COLD", BOOT, DOTQ, "AIBOT ESP32 Forth", CR, BEGIN, QUIT, AGAIN, EXIT);

     // COLD = COLON_WITH_FLAGS(0, "COLD", BEGIN, QUIT, AGAIN, EXIT);
     
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

     // printf("SPAT=%d\n",SPAT); exit(1);

     run();
}
