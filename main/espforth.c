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

// TODO: bobtie remove before committing
// #define esp32

#ifdef esp32
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#define PLATFORM 'E'//SP32
#include "esp_log.h"
#  include "esp_mac.h"
#  include "freertos/FreeRTOS.h"
#  include "freertos/task.h"
#  include "esp_system.h"
#  include "driver/gpio.h"
#  include "driver/ledc.h"
// #  include "esp_spi_flash.h"
#  include "esp_err.h"
#  include "esp_vfs.h"
#  include "esp_vfs_dev.h"
#  include "esp_vfs_fat.h"
#  include "esp_system.h"
#  include "driver/uart.h"
#  include "driver/i2c.h"
#  include "driver/adc.h"
#  include "esp_adc/adc_oneshot.h"
#else
#define PLATFORM 'L'//INUX
#  include <termios.h>
#  include <unistd.h>
#endif

static const char* TAG = "espforth";

#define DEBUG_CORE_WORDS 0
#define FILE_BUFFER_SIZE 0x4000

typedef intptr_t cell_t;
typedef uintptr_t ucell_t;
#if __SIZEOF_POINTER__ == 8
typedef __int128_t dcell_t;
typedef __uint128_t udcell_t;
# define UPPER_MASK 0x5f5f5f5f5f5f5f5f
#elif __SIZEOF_POINTER__ == 4
typedef int64_t dcell_t;
typedef uint64_t udcell_t;
# define UPPER_MASK 0x5f5f5f5f
#else
# error "unsupported cell size"
#endif

#define CELL_BITS (sizeof(cell_t)*8)
#define PRIxCELL PRIxPTR
#define CELL_MASK (sizeof(cell_t)-1)

#define FALSE 0
#define TRUE -1
#define LOGICAL ? TRUE : FALSE
#define LOWER(x,y) ((ucell_t)(x)<(ucell_t)(y))
#define pop top = stack[(unsigned char)S--]
#define push stack[(unsigned char)++S] = top, top =
#define popR rack[(unsigned char)R--]
#define pushR rack[(unsigned char)++R]

static cell_t rack[256] = {0}, stack[256] = {0};
static unsigned char R=0, S=0;
static cell_t *Pointer;
static cell_t P, IP, WP, top, links;
static dcell_t d, n, m;
static cell_t data[16000] = {};
static uint8_t *cData = (uint8_t *) data;
static const int IMEDD=0x80;
static const int COMPO=0x40;

#ifdef esp32
mode_t umask(mode_t v) {
  return 0777;
}
#endif

// TODO: bobtie otherwise duplicated
// #ifdef esp32
// int ftruncate(int fd, off_t sz) {
//   errno = EINVAL;
//   return -1;
// }
// #endif

 // { WP=top; top=stack[(unsigned char)S--]; top = duplexread(cData+top, WP); S--;}

// X("ACCEPT", ACCEPT, top = duplexread(cData, top)) 

#define PRIMITIVE_LIST \
  X("NOP", NOP, next()) \
  X("ACCEPT", ACCEPT, WP=top; top=stack[(unsigned char)S--]; top = duplexread(cData+top, WP)) \
  X("?KEY", QKEY, push qrx(); if (top >= 0) push -1; else top = 0) \
  X("EMIT", EMIT, char c=top; fputc(c, stdout); pop) \
  X("DOCON", DOCON, push data[WP/sizeof(cell_t)]) \
  X("DOLIT", DOLIT, push data[IP/sizeof(cell_t)]; \
    IP += sizeof(cell_t); next()) \
  X("DOLIST", DOLIST, rack[(unsigned char)++R] = IP; IP = WP; next()) \
  X("EXIT", EXIT, IP = (cell_t) rack[(unsigned char)R--]; next()) \
  X("EXECUTE", EXECUTE, P = top; WP = P + sizeof(cell_t); pop) \
  X("DONEXT", DONEXT, if(rack[(unsigned char)R]) \
    (rack[(unsigned char)R] -= 1, IP = data[IP/sizeof(cell_t)]); \
    else (IP += sizeof(cell_t), R--); next()) \
  X("QBRANCH", QBRANCH, if(top == 0) IP = data[IP/sizeof(cell_t)]; \
    else IP += sizeof(cell_t); pop; next()) \
  X("BRANCH", BRANCH, IP = data[IP/sizeof(cell_t)]; next()) \
  X("!", STORE, data[top/sizeof(cell_t)] = stack[(unsigned char)S--]; pop) \
  X("@", AT, top = data[top/sizeof(cell_t)]) \
  X("C!", CSTORE, cData[top] = (unsigned char) stack[(unsigned char)S--]; pop) \
  X("C@", CAT, top = (cell_t) cData[top]) \
  X("RPAT", RPAT, ) \
  X("RPSTO", RPSTO, ) \
  X("R>", RFROM, push rack[(unsigned char)R--]) \
  X("R@", RAT, push rack[(unsigned char)R]) \
  X(">R", TOR, rack[(unsigned char)++R] = top; pop) \
  X("SPAT", SPAT, ) \
  X("SPSTO", SPSTO, ) \
  X("DROP", DROP, pop) \
  X("DUP", DUP, stack[(unsigned char)++S] = top) \
  X("SWAP", SWAP, WP = top; top = stack[(unsigned char)S]; \
    stack[(unsigned char)S] = WP) \
  X("OVER", OVER, push stack[(unsigned char)(S-1)] ) \
  X("0<", ZLESS, top = (top < 0) LOGICAL) \
  X("AND", AND, top &= stack[(unsigned char)S--]) \
  X("OR", OR, top |= stack[(unsigned char)S--]) \
  X("XOR", XOR, top ^= stack[(unsigned char)S--]) \
  X("U+", UPLUS, stack[(unsigned char)S] += top; \
    top = LOWER(stack[(unsigned char)S], top)) \
  X("NEXT", NEXTT, next()) \
  X("?DUP", QDUP, if(top) stack[(unsigned char)++S] = top) \
  X("ROT", ROT, WP = stack[(unsigned char)(S-1)]; \
    stack[(unsigned char)(S-1)] = stack[(unsigned char)S]; \
    stack[(unsigned char)S] = top; top = WP) \
  X("2DROP", DDROP, fun_DROP(); fun_DROP()) \
  X("2DUP", DDUP, fun_OVER(); fun_OVER()) \
  X("+", PLUS, top += stack[(unsigned char)S--]) \
  X("INVERSE", INVERSE, top = -top-1) \
  X("NEGATE", NEGATE, top = 0 - top) \
  X("DNEGATE", DNEGATE, fun_INVERSE(); \
    fun_TOR(); fun_INVERSE(); push 1; fun_UPLUS(); \
    fun_RFROM(); fun_PLUS()) \
  X("-", SUB, top = stack[(unsigned char)S--] - top) \
  X("ABS", ABS, if(top < 0) top = -top) \
  X("=", EQUAL, top = (stack[(unsigned char)S--] == top) LOGICAL) \
  X("U<", ULESS, top = LOWER(stack[(unsigned char)S], top) LOGICAL; S--) \
  X("<", LESS, top = (stack[(unsigned char)S--] < top) LOGICAL) \
  X("UM/MOD", UMMOD, d = (udcell_t)((ucell_t)top); \
    m = (udcell_t)((ucell_t)stack[(unsigned char) S]); \
    n = (udcell_t)((ucell_t)stack[(unsigned char) (S - 1)]); \
    n += m << CELL_BITS; \
    pop; \
    if (d == 0) (top = 0, stack[S] = 0); \
    else (top = (ucell_t)(n / d), \
    stack[(unsigned char) S] = (ucell_t)(n%d))) \
  X("M/MOD", MSMOD, d = (dcell_t)((cell_t)top); \
    m = (dcell_t)((cell_t)stack[(unsigned char) S]); \
    n = (dcell_t)((cell_t)stack[(unsigned char) S - 1]); \
    n += m << CELL_BITS; \
    pop; \
    if (d == 0) (top = 0, stack[S] = 0); \
    else (top = (cell_t)(n / d), \
    stack[(unsigned char) S] = (cell_t)(n%d))) \
  X("/MOD", SLMOD, if (top != 0) \
    (WP = stack[(unsigned char) S] / top, \
    stack[(unsigned char) S] %= top, \
    top = WP)) \
  X("MOD", MOD, top = (top) ? stack[(unsigned char) S--] % top \
    : stack[(unsigned char) S--]) \
  X("/", SLASH, top = (top) ? stack[(unsigned char) S--] / top : (S--, 0)) \
  X("UM*", UMSTA, d = (udcell_t)top; \
    m = (udcell_t)stack[(unsigned char) S]; \
    m *= d; \
    top = (ucell_t)(m >> CELL_BITS); \
    stack[(unsigned char) S] = (ucell_t)m) \
  X("*", STAR, top *= stack[(unsigned char) S--]) \
  X("M*", MSTAR, d = (dcell_t)top; \
    m = (dcell_t)stack[(unsigned char) S]; \
    m *= d; \
    top = (cell_t)(m >> CELL_BITS); \
    stack[(unsigned char) S] = (cell_t)m) \
  X("*/MOD", SSMOD, d = (dcell_t)top; \
    m = (dcell_t)stack[(unsigned char) S]; \
    n = (dcell_t)stack[(unsigned char) (S - 1)]; \
    n *= m; \
    pop; \
    top = (cell_t)(n / d); \
    stack[(unsigned char) S] = (cell_t)(n%d)) \
  X("*/", STASL, d = (dcell_t)top; \
    m = (dcell_t)stack[(unsigned char) S]; \
    n = (dcell_t)stack[(unsigned char) (S - 1)]; \
    n *= m; \
    pop; pop; \
    top = (cell_t)(n / d)) \
  X("PICK", PICK, top = stack[(unsigned char)(S-top)]) \
  X("+!", PSTORE, data[top/sizeof(cell_t)] += stack[(unsigned char)S--]; pop) \
  X("2!", DSTORE, data[(top/sizeof(cell_t))+1] = stack[(unsigned char)S--]; \
    data[top/sizeof(cell_t)] = stack[(unsigned char)S--]; pop) \
  X("2@", DAT, push data[top/sizeof(cell_t)]; \
    top = data[(top/sizeof(cell_t))+1]) \
  X("COUNT", COUNT, stack[(unsigned char)++S] = top + 1; top = cData[top]) \
  X("DOVAR", DOVAR, push WP) \
  X("MAX", MAX, if (top < stack[(unsigned char)S]) pop; else S--) \
  X("MIN", MIN, if (top < stack[(unsigned char)S]) S--; else pop) \
  X("TONE-INIT", TONEINIT, WP=top; pop; ledcWriteTone(WP,top); pop) \
  X("TONE-FREQ", TONEFREQ, WP=top; pop; ledChangeTone(WP) ) \
  X("TONE-STATE", TONESTATE, WP=top; pop; ledToneState(WP) ) \
  X("I2C-M-INIT", I2CMINIT, top=i2c_master_init()) \
  X("I2C-M-WRITE", I2CMWRITE, WP=top; pop; top=i2c_write(WP,top)) \
  X("sendPacket", sendPacket, ) \
  X("POKE", POKE, Pointer = (cell_t*)top; \
    *Pointer = stack[(unsigned char)S--]; pop) \
  X("PEEK", PEEK, Pointer = (cell_t*)top; top = *Pointer) \
  X("ADC", ADC, /* top= (cell_t) analogRead(top); */ top = (cell_t) 0) \
  X("PINMODE", PINMODE, WP = top; pop; set_pin_direction(WP, top); pop) \
  X("PINSET", SETPIN, WP = top; pop; set_pin_level(WP, top); pop) \
  X("PINGET", GETPIN, top = get_pin_level(top)) \
  X("ADC-INIT", ADCINIT, adc_init(top); pop) \
  X("ADC-READ", ADCREAD, top = adc_read(top)) \
  X("DUTY", DUTY, WP = top; pop; /* ledcAnalogWrite(WP,top,255); */ pop) \
  X("FREQ", FREQ, WP = top; pop; /* ledcSetup(WP,top,13); */ pop) \
  X("MS", MS, WP = top; pop; mspause(WP)) \
  X("TERMINATE", TERMINATE, exit(top)) \
  /* File words */ \
  X("r/o", R_O, push O_RDONLY) \
  X("r/w", R_W, push O_RDWR) \
  X("w/o", W_O, push O_WRONLY) \
  X("bin", BIN, ) \
  X("close-file", CLOSE_FILE, top = close(top); top = top ? errno : 0) \
  X("open-file", OPEN_FILE, cell_t mode = top; pop; cell_t len = top; pop; \
    memcpy(filename, &cData[top], len); filename[len] = 0; \
    mode_t mask = umask(0); umask(mask); \
    top = open(filename, mode, mask); push top < 0 ? errno : 0) \
  X("create-file", CREATE_FILE, cell_t mode = top; pop; cell_t len = top; pop; \
    memcpy(filename, &cData[top], len); filename[len] = 0; \
    top = open(filename, mode | O_CREAT | O_TRUNC); push top < 0 ? errno : 0) \
  X("delete-file", DELETE_FILE, cell_t len = top; pop; \
    memcpy(filename, &cData[top], len); filename[len] = 0; \
    top = unlink(filename); top = top ? errno : 0) \
  X("write-file", WRITE_FILE, cell_t fd = top; pop; cell_t len = top; pop; \
    top = write(fd, &cData[top], len); top = top != len ? errno : 0) \
  X("read-file", READ_FILE, cell_t fd = top; pop; cell_t len = top; pop; \
    top = read(fd, &cData[top], len); push top != len ? errno : 0) \
  X("file-position", FILE_POSITION, \
    top = (cell_t) lseek(top, 0, SEEK_CUR); push top < 0 ? errno : 0) \
  X("reposition-file", REPOSITION_FILE, cell_t fd = top; pop; \
    top = (cell_t) lseek(fd, top, SEEK_SET); top = top < 0 ? errno : 0) \
  X("resize-file", RESIZE_FILE, cell_t fd = top; pop; \
    top = ftruncate(fd, top); top = top < 0 ? errno : 0) \
  X("file-size", FILE_SIZE, struct stat st; WP = fstat(top, &st); \
    top = (cell_t) st.st_size; push WP < 0 ? errno : 0) \

static int ABORQP=0, DOTQP=0, STRQP = 0, COLD = 0;
static char filename[4096];
#define X(sname, name, code) static int name = 0;
  PRIMITIVE_LIST
#undef X

static void HEADER(int flags, const char *name) {
  assert(IP % sizeof(cell_t) == 0);
  P=IP/sizeof(cell_t);
  int i;
  int len = strlen(name) & 0x1f;
  data[P++] = links;
  IP=P*sizeof(cell_t);
#if DEBUG_CORE_WORDS
  printf("\n");
  printf("[%" PRIxCELL "]", links);
  for (i=links/sizeof(cell_t);i<P;i++) {
    printf(" ");
    printf("%08" PRIxCELL, data[i]);
  }
#endif
  links=IP;
  cData[IP++]=len | flags;
  for (i=0;i<len;i++) {
    cData[IP++] = name[i];
  }
  while (IP&CELL_MASK) {
    cData[IP++]=0;
  }
#if DEBUG_CORE_WORDS
  printf("\n");
  printf("%s", name);
  printf(" (at: ");
  printf("%08" PRIxCELL, IP);
  printf(") ");
#endif
}

static void Comma(cell_t n) {
  assert(IP % sizeof(cell_t) == 0);
  P=IP/sizeof(cell_t);
  data[P++] = n;
  IP=P*sizeof(cell_t);
}

#define STR_LIKE(op) \
  str = va_arg(argList, const char*); \
  int len = strlen(str); \
  data[P++] = op; \
  IP=P*sizeof(cell_t); \
  cData[IP++]=len; \
  for (i=0;i<len;i++) cData[IP++]=str[i]; \
  while (IP & CELL_MASK) cData[IP++]=0; \
  P=IP/sizeof(cell_t);

#define MACRO_LIST \
  X(BEGIN, pushR=P) \
  X(AGAIN, data[P++]=BRANCH; data[P++]=popR*sizeof(cell_t)) \
  X(UNTIL, data[P++]=QBRANCH; data[P++]=popR*sizeof(cell_t)) \
  X(WHILE, data[P++]=QBRANCH; data[P++]=0; k=popR; pushR=(P-1); pushR=k) \
  X(REPEAT, data[P++]=BRANCH; data[P++]=popR*sizeof(cell_t); \
    data[popR]=P*sizeof(cell_t)) \
  X(IF, data[P++]=QBRANCH; pushR=P; data[P++]=0) \
  X(ELSE, data[P++]=BRANCH; data[P++]=0; \
    data[popR]=P*sizeof(cell_t); pushR=P-1) \
  X(THEN, data[popR]=P*sizeof(cell_t)) \
  X(FOR, data[P++]=TOR; pushR=P) \
  X(NEXT, data[P++]=DONEXT; data[P++]=popR*sizeof(cell_t)) \
  X(AFT, data[P++]=BRANCH; data[P++]=0; k=popR; pushR=P; pushR=P-1) \
  X(DOTQ, STR_LIKE(DOTQP)) \
  X(STRQ, STR_LIKE(STRQP)) \
  X(ABORTQ, STR_LIKE(ABORQP))

enum {
  UNUSED_MACRO=0x80000000,
#define X(name, code) name,
MACRO_LIST
#undef X
};

#if DEBUG_CORE_WORDS
static void CheckSum() {
  printf("\n");
  unsigned char sum = 0;
  for (cell_t i = 0; i < IP;) {
    printf("%04" PRIxCELL " ", i);
    for (int j = 0; j < 32; ++j) {
      sum += cData[i];
      printf("%02x",cData[i++]);
    }
    printf(" %02x\n",sum);
  }
  printf("\n");
}
#endif

static void next(void) {
  P = data[IP/sizeof(cell_t)];
  IP += sizeof(cell_t);
  WP = P+sizeof(cell_t);
}

static int qrx(void) {
  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);
  struct timeval tm;
  tm.tv_sec = 0;
  tm.tv_usec = 0;
  int ret = select(1, &readfds, NULL, NULL, &tm);
  if (ret > 0) {
    return fgetc(stdin);
  }
  return -1;
}

static int duplexread(unsigned char* dst, int sz) {
  int len = 0;
  while (sz > 0) {
    int ch = fgetc(stdin);
    if (ch == 127 || ch == 8) {
      if (len > 0) {
        fputc(8, stdout);
        fputc(' ', stdout);
        fputc(8, stdout);
        --len;
      }
      continue;
    }
    if (ch == '\n') {
      fputc('\r', stdout);
    }
    fputc(ch, stdout);
    if (ch == '\n' || ch < 0) {
      break;
    }
    dst[len++] = ch;
  }
  // printf("duplexread, len=%d\n", len);
  return len;
}

static void set_pin_direction(int p, int m) {
  /* m = 1 for input, m = 2 for output*/
#ifdef esp32
   gpio_reset_pin(p);
   gpio_set_direction(p, m);
#endif
}

static void set_pin_level(int p, int level) {
  #ifdef esp32
     gpio_set_level(p, top);
  #endif
}

static cell_t get_pin_level(int p) {
  #ifdef esp32
     return gpio_get_level(p);
  #endif
}

#ifdef esp32
static adc_oneshot_unit_handle_t adc1_handle;
#endif

// --------------------------------------
static void adc_init(int channel) {

    #ifdef esp32
    adc_oneshot_unit_init_cfg_t init_config = {
        .unit_id = ADC_UNIT_1,
    };
    adc_oneshot_new_unit(&init_config, &adc1_handle);

    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_11, // for 0 - 3.6V range
    };
    adc_oneshot_config_channel(adc1_handle, channel, &config);
    #endif
  }

int adc_read(int channel) {
        int raw = 0;
        #ifdef esp32
        adc_oneshot_read(adc1_handle, channel, &raw);
        #endif
        return raw;
}


// --------------------------------------

static void mspause(cell_t ms) {
#ifdef esp32
  vTaskDelay(ms / portTICK_PERIOD_MS);
#else
  usleep(ms * 1000);
#endif
}



#define PWM_GPIO        18      // GPIO pin for PWM
#define PWM_FREQ_HZ     440    // Frequency in Hertz
#define PWM_DUTY_RES    LEDC_TIMER_8_BIT // 8-bit resolution (0-255)
#define PWM_DUTY        128     // 50% duty cycle (128 out of 255)
#define PWM_TIMER       LEDC_TIMER_0
#define PWM_MODE        LEDC_HIGH_SPEED_MODE
#define PWM_CHANNEL     LEDC_CHANNEL_0

void ledToneState(int s)
{
  #ifdef esp32
    if (s == 0) {
      ledc_timer_pause(PWM_MODE, PWM_TIMER);
    } else {
      ledc_timer_resume(PWM_MODE, PWM_TIMER);
    }
  #endif
}

void ledChangeTone(int freq)
{
  #ifdef esp32
    ledc_set_freq(PWM_MODE, PWM_TIMER, freq);
    #endif
}

void ledcWriteTone(int pin, int freq)
{

    // printf("ledcWriteTone, freq: %d, pin: %d\n", freq, pin);
    // Configure the PWM timer
    #ifdef esp32
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = PWM_MODE,
        .timer_num        = PWM_TIMER,
        .duty_resolution  = PWM_DUTY_RES,
        .freq_hz          = freq,
        .clk_cfg          = LEDC_AUTO_CLK
    };

    ledc_timer_config(&ledc_timer);

    ledc_timer_pause(PWM_MODE, PWM_TIMER);

    // Configure the PWM channel
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = PWM_MODE,
        .channel        = PWM_CHANNEL,
        .timer_sel      = PWM_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = pin,
        .duty           = PWM_DUTY,
        .hpoint         = 0
    };

    ledc_channel_config(&ledc_channel);
    #endif

}

// ---- i2c control

#define I2C_MASTER_NUM I2C_NUM_0       // or I2C_NUM_1
#define I2C_MASTER_SDA_IO 21           // Set to your actual SDA pin
#define I2C_MASTER_SCL_IO 22           // Set to your actual SCL pin
#define I2C_MASTER_FREQ_HZ 100000      // Standard I2C speed
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0

#ifndef esp32
  typedef int esp_err_t;
#endif

esp_err_t i2c_master_init(void) {
    #ifdef esp32
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };
    esp_err_t err = i2c_param_config(I2C_MASTER_NUM, &conf);
    if (err != ESP_OK) return err;
    return i2c_driver_install(I2C_MASTER_NUM, conf.mode,
                              I2C_MASTER_RX_BUF_DISABLE,
                              I2C_MASTER_TX_BUF_DISABLE, 0);
    #else
      return 0;
    #endif
}

// 8-bit I2C address = (7-bit address << 1)
// Example: TM1650 digit0 addr = 0x34 → write addr = 0x68
esp_err_t i2c_write(uint8_t addr_8bit, uint8_t data) {
    esp_err_t err = 0;
    #ifdef esp32
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, addr_8bit, true);     // Send slave address
    i2c_master_write_byte(cmd, data, true);          // Send data
    i2c_master_stop(cmd);
    err = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, pdMS_TO_TICKS(1000));
    i2c_cmd_link_delete(cmd);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "I2C write failed: %s", esp_err_to_name(err));
    }
    #endif
    return err;
}

#define X(sname, name, code) static void fun_ ## name(void) { code; }
  PRIMITIVE_LIST
#undef X

static void (*primitives[])(void) = {
#define X(sname, name, code) fun_ ## name,
  PRIMITIVE_LIST
#undef X
};

enum {
  as_UNKNOWN = -1,
#define X(sname, name, code) as_ ## name,
  PRIMITIVE_LIST
#undef X
};

int CODE(const char *name, ... ) {
  HEADER(0, name);
  int addr=IP;
  cell_t s;
#if DEBUG_CORE_WORDS
    printf(" CODE:");
#endif
  va_list argList;
  va_start(argList, name);
  do {
    s = va_arg(argList, cell_t);
    cData[IP++] = s;
#if DEBUG_CORE_WORDS
    printf(" ");
    printf("%" PRIxCELL, s);
#endif
  } while(s != as_NEXTT);
  while (IP & CELL_MASK) {
    cData[IP++]=0;
  }
  va_end(argList);
  return addr;
}

int COLON_WITH_FLAGS(int flags, const char *name, ...) {
  HEADER(flags, name);
  int addr=IP;
  P=IP/sizeof(cell_t);
  data[P++] = as_DOLIST;
  va_list argList;
  va_start(argList, name);
#if DEBUG_CORE_WORDS
  printf("\n");
  printf("%x", addr);
  printf(" ");
  printf("6");
#endif
  int prev_word=0, word=0, i, k;
  const char *str;
  do {
    prev_word = word;
    word = va_arg(argList, int);
    switch (word) {
#define X(name, code) case name: { code; } break;
      MACRO_LIST
#undef X
      default:
        data[P++] = word;
#if DEBUG_CORE_WORDS
        printf(" ");
        printf("%" PRIxCELL, data[P-1]);
#endif
       break;
    }
  } while (word != EXIT || R > 0 || prev_word == DOLIT);
  IP=P*sizeof(cell_t);
  va_end(argList);
  return addr;
}

#define COLON(...) COLON_WITH_FLAGS(0, __VA_ARGS__)
#define COLON_IMMEDIATE(...) COLON_WITH_FLAGS(IMEDD, __VA_ARGS__)

static int CONSTANT(const char *name, cell_t n) {
  int ret = CODE(name, as_DOCON, as_NEXTT);
  Comma(n);
  return ret;
}

static int VARIABLE(const char *name) {
  int ret = CODE(name, as_DOVAR, as_NEXTT);
  Comma(0);
  return ret;
}

static void SET_VAR(cell_t addr, cell_t value) {
  data[addr/sizeof(cell_t) + 1] = value;
}

static void run() {
  P = COLD;
  WP = P + sizeof(cell_t);
  for(;;) {
    unsigned char bytecode = cData[P++];
    #ifdef TRACE_EXECUTION
    printf("executing at %u: %s\n",lastP,opname[bytecode]);
    #endif
    primitives[bytecode]();
  }
}

#ifdef esp32
#define BOOT_PATH "/spiflash/boot.fs"
static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;
static void Init(void) {


  ESP_LOGI(TAG, "Init() begin ...");

  const char *base_path = "/spiflash";

  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  ESP_ERROR_CHECK( uart_driver_install( (uart_port_t)CONFIG_ESP_CONSOLE_UART_NUM,
          256, 0, 0, NULL, 0) );
  esp_vfs_dev_uart_use_driver(CONFIG_ESP_CONSOLE_UART_NUM);
  esp_vfs_dev_uart_set_rx_line_endings(ESP_LINE_ENDINGS_CR);
  esp_vfs_dev_uart_set_tx_line_endings(ESP_LINE_ENDINGS_CRLF);

  const esp_vfs_fat_mount_config_t mount_config = {
      .max_files = 4,
      .format_if_mount_failed = true,
      .allocation_unit_size = CONFIG_WL_SECTOR_SIZE
  };

  esp_err_t err = esp_vfs_fat_spiflash_mount(
    base_path, "storage", &mount_config, &s_wl_handle);
  if (err != ESP_OK) {
    fprintf(stderr, "Failed to mount FATFS (%s)", esp_err_to_name(err));
    return;
  }
}

#else
#define BOOT_PATH "boot.fs"
static struct termios terminalOld;
static void RestoreTerminal(void) {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminalOld);
}
static void Init(void) {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  tcgetattr(STDIN_FILENO, &terminalOld);
  atexit(RestoreTerminal);
  struct termios t = terminalOld;
  t.c_lflag &= ~ECHO;
  t.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
}
#endif

#ifdef esp32
void app_main(void) {
#else
int main(void) {
#endif
  Init();
  S = 0;
  R = 0;
  top = 0;
  links = 0;
  IP = 0x100;

  int TTIB=VARIABLE("'TIB"); IP += 0x100;
  int NFIB=VARIABLE("#FIB"); SET_VAR(NFIB, FILE_BUFFER_SIZE);
  int FIB=VARIABLE("FIB"); IP += FILE_BUFFER_SIZE;
  int CONTEXT=VARIABLE("CONTEXT");
  int CP=VARIABLE("CP");
  int LAST=VARIABLE("LAST");
  int TEVAL=VARIABLE("'EVAL");
  int TABORT=VARIABLE("'ABORT");
  int HLD=VARIABLE("HLD");
  int SPAN=VARIABLE("SPAN");
  int INN=VARIABLE(">IN");
  int NTIB=VARIABLE("#TIB");
  int TEMP=VARIABLE("tmp");
  int BASE=VARIABLE("BASE");

#define X(sname, name, code) name = CODE(sname, as_ ## name, as_NEXTT);
  PRIMITIVE_LIST
#undef X

  int BLANK=CONSTANT("BL", ' ');
  CONSTANT("CELL", sizeof(cell_t));
  int CELLP=CODE("CELL+",
    as_DOCON, as_PLUS, as_NEXTT); Comma(sizeof(cell_t));
  int CELLM=CODE("CELL-",
    as_DOCON, as_SUB, as_NEXTT); Comma(sizeof(cell_t));
  int CELLS=CODE("CELLS",
    as_DOCON, as_STAR, as_NEXTT); Comma(sizeof(cell_t));
  int CELLD=CODE("CELL/",
    as_DOCON, as_SLASH, as_NEXTT); Comma(sizeof(cell_t));
  int ONEP=CODE("1+", as_DOCON, as_PLUS, as_NEXTT); Comma(1);
  int ONEM=CODE("1-", as_DOCON, as_SUB, as_NEXTT); Comma(1);
  CODE("2+", as_DOCON, as_PLUS, as_NEXTT); Comma(2);
  CODE("2-", as_DOCON, as_SUB, as_NEXTT); Comma(2);
  CODE("2*", as_DOCON, as_STAR, as_NEXTT); Comma(2);
  CODE("2/", as_DOCON, as_SLASH, as_NEXTT); Comma(2);

  COLON("BYE", DOLIT,0,TERMINATE,EXIT);
  COLON("KEY", BEGIN,QKEY,UNTIL,EXIT);
  int WITHI=COLON("WITHIN", OVER,SUB,TOR,SUB,RFROM,ULESS,EXIT);
  int TCHAR=COLON(">CHAR", DOLIT,0x7F,AND,DUP,DOLIT,127,BLANK,WITHI,
    IF, DROP,DOLIT,'_', THEN, EXIT);
  int ALIGN=COLON("ALIGNED", DOLIT,CELL_MASK,PLUS, DOLIT,CELL_MASK,INVERSE,AND,EXIT);
  int HERE=COLON("HERE", CP,AT,EXIT);
  int PAD=COLON("PAD", HERE,DOLIT,80,PLUS,EXIT);
  int TIB=COLON("TIB", TTIB,AT,EXIT);
  int ATEXE=COLON("@EXECUTE", AT,QDUP,IF,EXECUTE,THEN,EXIT);
  int CMOVEE=COLON("CMOVE",
    FOR,AFT,OVER,CAT,OVER,CSTORE,TOR,ONEP,RFROM,ONEP,
    THEN,NEXT,DDROP,EXIT);
  COLON("MOVE", CELLD,FOR,AFT,OVER,AT,OVER,STORE,TOR,CELLP,RFROM,CELLP,
    THEN,NEXT,DDROP,EXIT);
  COLON("FILL", SWAP,FOR,SWAP,AFT,DDUP,CSTORE,ONEP,THEN,NEXT,
    DDROP,EXIT);
  int DIGIT=COLON("DIGIT", DOLIT,9,OVER,LESS,DOLIT,7,AND,PLUS,
                           DOLIT,'0',PLUS,EXIT);
  int EXTRC=COLON("EXTRACT", DOLIT,0,SWAP,UMMOD,SWAP,DIGIT,EXIT);
  int BDIGS=COLON("<#", PAD,HLD,STORE,EXIT);
  int HOLD=COLON("HOLD", HLD,AT,ONEM,DUP,HLD,STORE,CSTORE,EXIT);
  int DIG=COLON("#", BASE,AT,EXTRC,HOLD,EXIT);
  int DIGS=COLON("#S", BEGIN,DIG,DUP,WHILE,REPEAT,EXIT);
  int SIGN=COLON("SIGN", ZLESS,IF,DOLIT,'-',HOLD,THEN,EXIT);
  int EDIGS=COLON("#>", DROP,HLD,AT,PAD,OVER,SUB,EXIT);
  int STRR=COLON("str", DUP,TOR,ABS,BDIGS,DIGS,RFROM,SIGN,EDIGS,EXIT);
  int HEX=COLON("HEX", DOLIT,16,BASE,STORE,EXIT);
  COLON("DECIMAL", DOLIT,10,BASE,STORE,EXIT);
  int UMASK = CONSTANT("UMASK", UPPER_MASK);
  int UPPER=COLON("wupper", UMASK,AND,EXIT);
  int TOUPP=COLON(">upper", DUP,DOLIT,'a',DOLIT,'{',WITHI,IF,
                            DOLIT,0x5F,AND,THEN,EXIT);
  int DIGTQ=COLON("DIGIT?", TOR,TOUPP,DOLIT,'0',SUB,DOLIT,9,OVER,LESS,
                            IF,DOLIT,7,SUB,DUP,DOLIT,10,LESS,OR,THEN,
                            DUP,RFROM,ULESS,EXIT);
  int NUMBQ=COLON("NUMBER?", BASE,AT,TOR,DOLIT,0,OVER,COUNT,OVER,CAT,
                            DOLIT,'$',EQUAL,IF,HEX,SWAP,ONEP,SWAP,ONEM,THEN,
                            OVER,CAT,DOLIT,'-',EQUAL,TOR,SWAP,RAT,SUB,
                            SWAP,RAT,PLUS,QDUP,IF,ONEM,
                            FOR,DUP,TOR,CAT,BASE,AT,DIGTQ,
                            WHILE,SWAP,BASE,AT,STAR,PLUS,RFROM,ONEP,NEXT,
                            DROP,RAT,IF,NEGATE,THEN,SWAP,
                            ELSE,RFROM,RFROM,DDROP,DDROP,DOLIT,0,THEN,
                            DUP,THEN,RFROM,DDROP,RFROM,BASE,STORE,EXIT);
  int SPACE=COLON("SPACE", BLANK,EMIT,EXIT);
  int CHARS=COLON("CHARS", SWAP,DOLIT,0,MAX,FOR,AFT,DUP,EMIT,THEN,NEXT,
                           DROP,EXIT);
  int SPACS=COLON("SPACES", BLANK,CHARS,EXIT);
  int TYPES=COLON("TYPE",
    FOR,AFT,DUP,CAT,TCHAR,EMIT,ONEP,THEN,NEXT,DROP,EXIT);
  int CR=COLON("CR", DOLIT,'\n',DOLIT,'\r',EMIT,EMIT,EXIT);
  int DOSTR=COLON("do$",
    RFROM,RAT,RFROM,COUNT,PLUS,ALIGN,TOR,SWAP,TOR,EXIT);
  STRQP=COLON("$\"|", DOSTR,EXIT);
  DOTQP=COLON(".\"|", DOSTR,COUNT,TYPES,EXIT);
  COLON(".R", TOR,STRR,RFROM,OVER,SUB,SPACS,TYPES,EXIT);
  int UDOTR=COLON("U.R",
    TOR,BDIGS,DIGS,EDIGS,RFROM,OVER,SUB,SPACS,TYPES,EXIT);
  int UDOT=COLON("U.", BDIGS,DIGS,EDIGS,SPACE,TYPES,EXIT);
  int DOT=COLON(".", BASE,AT,DOLIT,10,XOR,IF,UDOT,EXIT,THEN,
                     STRR,SPACE,TYPES,EXIT);
  COLON("?", AT,DOT,EXIT);
  int PARS=COLON("(parse)", TEMP,CSTORE,OVER,TOR,DUP,IF,
                              ONEM,TEMP,CAT,BLANK,EQUAL,IF,
                                FOR,BLANK,OVER,CAT,SUB,ZLESS,INVERSE,
                                  WHILE,ONEP,
                                NEXT,
                                RFROM,DROP,DOLIT,0,DUP,EXIT,
                              THEN,RFROM,
                            THEN,OVER,SWAP,
                            FOR,TEMP,CAT,OVER,CAT,SUB,TEMP,CAT,BLANK,EQUAL,
                              IF,ZLESS,THEN,
                              WHILE,ONEP,
                            NEXT,DUP,TOR,
                            ELSE,RFROM,DROP,DUP,ONEP,TOR,
                            THEN,OVER,SUB,RFROM,RFROM,SUB,EXIT,
                            THEN,OVER,RFROM,SUB,EXIT);
  // : PACK$
  //     dup >r 2dup + CELL_MASK and 0 swap ! 2dup c! 1+ swap cmove r>
  // ;
  int PACKS=COLON("PACK$", DUP,TOR,DDUP,PLUS,DOLIT,CELL_MASK,INVERSE,AND,
    DOLIT,0,SWAP,STORE,DDUP,CSTORE,ONEP,SWAP,CMOVEE,RFROM,EXIT);
  int PARSE=COLON("PARSE", TOR,TIB,INN,AT,PLUS,NTIB,AT,INN,AT,SUB,RFROM,
    PARS,INN,PSTORE,EXIT);
  int TOKEN=COLON("TOKEN",
    BLANK,PARSE,DOLIT,0x1F,MIN,HERE,CELLP,PACKS,EXIT);
  int WORDD=COLON("WORD", PARSE,HERE,CELLP,PACKS,EXIT);
  // : NAMET
  //     count $1f and + align
  // ;
  int NAMET=COLON("NAME>", COUNT,DOLIT,0x1F,AND,PLUS,ALIGN,EXIT);
  // : SAME?
  //     $1f and cell/
  //     for aft
  //         over r@ cells + @ wupper over r@ cells + @ wupper - ?dup
  //         if
  //             r> drop exit
  //         then
  //     then next
  //     0
  // ;
  int SAMEQ=COLON("SAME?", DOLIT,0x1F,AND,CELLD,FOR,AFT,
                             OVER,RAT,CELLS,PLUS,AT,UPPER,OVER,RAT,
                             CELLS,PLUS,AT,UPPER,SUB,QDUP,IF,
                               RFROM,DROP,EXIT,THEN,
                           THEN,NEXT,DOLIT,0,EXIT);
  // : FIND
  //     swap dup @ temp ! dup @ >r cell+ swap
  //     begin
  //         @ dup
  //         if
  //             dup @ ~$C0 and wupper r@ wupper xor
  //             if
  //                 cell+ -1
  //             else
  //                 cell+ temp @ same?
  //             then
  //         else
  //             r> drop swap cell- swap exit
  //         then
  //     while
  //          cell- cell-
  //     repeat
  //     r> drop swap drop cell- dup namet swap
  // ;
  int FIND=COLON("find", SWAP,DUP,AT,TEMP,STORE,DUP,AT,TOR,CELLP,SWAP,
                         BEGIN,AT,DUP,IF,
                           DUP,AT,DOLIT,0xC0,INVERSE,AND,UPPER,RAT,UPPER,XOR,
                           IF,CELLP,DOLIT,-1,ELSE,CELLP,TEMP,AT,SAMEQ,THEN,
                         ELSE,RFROM,DROP,SWAP,CELLM,SWAP,EXIT,THEN,
                         WHILE,CELLM,CELLM,REPEAT,
                         RFROM,DROP,SWAP,DROP,CELLM,DUP,NAMET,SWAP,EXIT);
  int NAMEQ=COLON("NAME?", CONTEXT,FIND,EXIT);
  COLON("EXPECT", ACCEPT,SPAN,STORE,EXIT);
  int QUERY=COLON("QUERY", TIB,DOLIT,0x100,ACCEPT,NTIB,STORE,
    DOLIT,0,INN,STORE,EXIT);
  int ABORT=COLON("ABORT", NOP,TABORT,ATEXE,EXIT);
  ABORQP=COLON("abort\"", IF,DOSTR,COUNT,TYPES,ABORT,THEN,
    DOSTR,DROP,EXIT);
  int ERRORR=COLON("ERROR", SPACE,COUNT,TYPES,DOLIT,'?',EMIT,CR,ABORT,EXIT);
  int INTER=COLON("$INTERPRET", NAMEQ,QDUP,IF,CAT,DOLIT,COMPO,AND,
                  ABORTQ," compile only",EXECUTE,EXIT,THEN,NUMBQ,IF,
                  EXIT,THEN,ERRORR,EXIT);
  int LBRAC=COLON_IMMEDIATE("[", DOLIT,INTER,TEVAL,STORE,EXIT);
  int DOTOK=COLON(".OK", CR,DOLIT,INTER,TEVAL,AT,EQUAL,IF,
                    TOR,TOR,TOR,DUP,DOT,RFROM,DUP,DOT,RFROM,DUP,DOT,
                    RFROM,DUP,DOT,DOTQ," ok> ",THEN,EXIT);
  int EVAL=COLON("EVAL", LBRAC,BEGIN,TOKEN,DUP,AT,WHILE,TEVAL,ATEXE,
                 REPEAT,DROP,NOP,EXIT);
  int QUIT=COLON("QUIT", LBRAC,BEGIN,DOTOK,QUERY,EVAL,AGAIN,EXIT);
  int LOAD=COLON("LOAD", TTIB,AT,TOR,NTIB,STORE,TTIB,STORE,
    DOLIT,0,INN,STORE,EVAL,RFROM,TTIB,STORE,EXIT);
  int COMMA=COLON(",", HERE,DUP,CELLP,CP,STORE,STORE,EXIT);
  int LITER=COLON_IMMEDIATE("LITERAL", DOLIT,DOLIT,COMMA,COMMA,EXIT);
  COLON("ALLOT", ALIGN,CP,PSTORE,EXIT);
  int STRCQ=COLON("$,\"", DOLIT,'"',WORDD,COUNT,PLUS,ALIGN,CP,STORE,EXIT);
  int UNIQU=COLON("?UNIQUE", DUP,NAMEQ,QDUP,IF,
                   COUNT,DOLIT,0x1F,AND,SPACE,TYPES,DOTQ," reDef",
                  THEN,DROP,EXIT);
  int SNAME=COLON("$,n", DUP,AT,IF,UNIQU,DUP,NAMET,CP,STORE,DUP,
                  LAST,STORE,CELLM,CONTEXT,AT,SWAP,STORE,EXIT,THEN,
                  ERRORR,EXIT);
  int TICK=COLON("'", TOKEN,NAMEQ,IF,EXIT,THEN,ERRORR,EXIT);
  COLON_IMMEDIATE("[COMPILE]", TICK,COMMA,EXIT);
  int COMPI=COLON("COMPILE", RFROM,DUP,AT,COMMA,CELLP,TOR,EXIT);
  int SCOMP=COLON("$COMPILE", NAMEQ,QDUP,IF,AT,DOLIT,IMEDD,AND,IF,EXECUTE,
                  ELSE,COMMA,THEN,EXIT,THEN,NUMBQ,IF,LITER,EXIT,THEN,
                  ERRORR,EXIT);
  int OVERT=COLON("OVERT", LAST,AT,CONTEXT,STORE,EXIT);
  int RBRAC=COLON("]", DOLIT,SCOMP,TEVAL,STORE,EXIT);
  COLON(":", TOKEN,SNAME,RBRAC,DOLIT,as_DOLIST,COMMA,EXIT);
  COLON_IMMEDIATE(";", DOLIT,EXIT,COMMA,LBRAC,OVERT,EXIT);
  int DMP=COLON("dm+",
     OVER,DOLIT,6,UDOTR,FOR,AFT,DUP,AT,DOLIT,9,UDOTR,CELLP,
    THEN,NEXT,EXIT);
  COLON("DUMP", BASE,AT,TOR,HEX,DOLIT,0x1F,PLUS,DOLIT,0x20,SLASH,
    FOR,AFT,CR,DOLIT,8,DDUP,DMP,TOR,SPACE,CELLS,TYPES,RFROM,THEN,NEXT,
    DROP,RFROM,BASE,STORE,EXIT);
  COLON(">NAME", CONTEXT,BEGIN,AT,DUP,WHILE,DDUP,NAMET,XOR,
    IF,ONEM,ELSE,SWAP,DROP,EXIT,THEN,REPEAT,SWAP,DROP,EXIT);
  int DOTID=COLON(".ID", COUNT,DOLIT,0x1F,AND,TYPES,SPACE,EXIT);
  COLON("WORDS", CR,CONTEXT,DOLIT,0,TEMP,STORE,BEGIN,AT,QDUP,
    WHILE,DUP,SPACE,DOTID,CELLM,TEMP,AT,DOLIT,8,LESS,
    IF,DOLIT,1,TEMP,PSTORE,ELSE,CR,DOLIT,0,TEMP,STORE,THEN,
    REPEAT,EXIT);
  COLON("FORGET", TOKEN,NAMEQ,QDUP,IF,
    CELLM,DUP,CP,STORE,AT,DUP,CONTEXT,STORE,LAST,STORE,DROP,EXIT,THEN,
    ERRORR,EXIT);
  int BOOT=COLON("BOOT", STRQ,BOOT_PATH,COUNT,R_O,OPEN_FILE,IF,DROP,DOTQ, "file not found:", DOTQ, BOOT_PATH, CR,ELSE,
    FIB,SWAP,DOLIT,NFIB,AT,SWAP,READ_FILE,
    IF,DROP,ELSE,FIB,SWAP,LOAD,THEN,THEN,EXIT);
  COLD=COLON("COLD",
    BOOT,DOTQ,"AIBOT ESP32 Forth",CR,BEGIN,QUIT,AGAIN,EXIT);

  // --- My wokrds
  COLON("PLATFORM",
    DOLIT,PLATFORM,EXIT);

  // ---- ESP32 WORDS
  
  int LINE=COLON("LINE",
    DOLIT,0x7,FOR,DUP,PEEK,DOLIT,0x9,UDOTR,CELLP,NEXT,EXIT);
  int PP=COLON("PP",
    FOR,AFT,CR,DUP,DOLIT,0x9,UDOTR,SPACE,LINE,THEN,NEXT,EXIT);
  COLON("P0", DOLIT,0x3FF44004,POKE,EXIT);
  COLON("P0S", DOLIT,0x3FF44008,POKE,EXIT);
  COLON("P0C", DOLIT,0x3FF4400C,POKE,EXIT);
  COLON("P1", DOLIT,0x3FF44010,POKE,EXIT);
  COLON("P1S", DOLIT,0x3FF44014,POKE,EXIT);
  COLON("P1C", DOLIT,0x3FF44018,POKE,EXIT);
  COLON("P0EN", DOLIT,0x3FF44020,POKE,EXIT);
  COLON("P0ENS", DOLIT,0x3FF44024,POKE,EXIT);
  COLON("P0ENC", DOLIT,0x3FF44028,POKE,EXIT);
  COLON("P1EN", DOLIT,0x3FF4402C,POKE,EXIT);
  COLON("P1ENS", DOLIT,0x3FF44030,POKE,EXIT);
  COLON("P1ENC", DOLIT,0x3FF44034,POKE,EXIT);
  COLON("P0IN", DOLIT,0x3FF4403C,PEEK,DOT,EXIT);
  COLON("P1IN", DOLIT,0x3FF44040,PEEK,DOT,EXIT);
  COLON("PPP", DOLIT,0x3FF44000,DOLIT,3,PP,DROP,EXIT);
  int EMITT=COLON("EMITT", DOLIT,0x3,FOR,DOLIT,0,DOLIT,0x100,MSMOD,SWAP,
    TCHAR,EMIT,NEXT,DROP,EXIT);
  int TYPEE=COLON("TYPEE", SPACE,DOLIT,0x7,FOR,DUP,PEEK,EMITT,CELLP,NEXT,
    DROP,EXIT);
  COLON("PPPP", FOR,AFT,CR,DUP,DUP,DOLIT,0x9,UDOTR,SPACE,LINE,
    SWAP,TYPEE,THEN,NEXT,EXIT);
  COLON("KKK", DOLIT,0x3FF59000,DOLIT,0x10,PP,DROP,EXIT);

  // ---- 

  int THENN=COLON_IMMEDIATE("THEN", HERE,SWAP,STORE,EXIT);
  COLON_IMMEDIATE("FOR", COMPI,TOR,HERE,EXIT);
  COLON_IMMEDIATE("BEGIN", HERE,EXIT);
  COLON_IMMEDIATE("NEXT", COMPI,DONEXT,COMMA,EXIT);
  COLON_IMMEDIATE("UNTIL", COMPI,QBRANCH,COMMA,EXIT);
  int AGAINN = COLON_IMMEDIATE("AGAIN", COMPI,BRANCH,COMMA,EXIT);
  int IFF = COLON_IMMEDIATE("IF", COMPI,QBRANCH,HERE,DOLIT,0,COMMA,EXIT);
  int AHEAD = COLON_IMMEDIATE("AHEAD",
    COMPI,BRANCH,HERE,DOLIT,0,COMMA,EXIT);
  COLON_IMMEDIATE("REPEAT", AGAINN,THENN,EXIT);
  COLON_IMMEDIATE("AFT", DROP,AHEAD,HERE,SWAP,EXIT);
  COLON_IMMEDIATE("ELSE", AHEAD,SWAP,THENN,EXIT);
  COLON_IMMEDIATE("WHILE", IFF,SWAP,EXIT);
  COLON_IMMEDIATE("ABORT\"", DOLIT,ABORQP,HERE,STORE,STRCQ,EXIT);
  COLON_IMMEDIATE("$\"", DOLIT,STRQP,HERE,STORE,STRCQ,EXIT);
  COLON_IMMEDIATE(".\"", DOLIT,DOTQP,HERE,STORE,STRCQ,EXIT);
  int CODE=COLON("CODE", TOKEN,SNAME,OVERT,HERE,ALIGN,CP,STORE,EXIT);
  int CREATE=COLON("CREATE",
    CODE,DOLIT,as_DOVAR + (as_NEXTT << 8),COMMA,EXIT);
  COLON("VARIABLE", CREATE,DOLIT,0,COMMA,EXIT);
  COLON("CONSTANT", CODE,DOLIT,as_DOCON + (as_NEXTT << 8),
    COMMA,COMMA,EXIT);
  COLON_IMMEDIATE(".(", DOLIT,')',PARSE,TYPES,EXIT);
  COLON_IMMEDIATE("\\", DOLIT,'\n',WORDD,DROP,EXIT);
  COLON_IMMEDIATE("(", DOLIT,')',PARSE,DDROP,EXIT);
  COLON_IMMEDIATE("COMPILE-ONLY", DOLIT,COMPO,LAST,AT,PSTORE,EXIT);
  COLON("IMMEDIATE", DOLIT,IMEDD,LAST,AT,PSTORE,EXIT);

  SET_VAR(CP, IP);
  SET_VAR(BASE, 10);
  SET_VAR(TEVAL, INTER);
  SET_VAR(TABORT, EVAL);
  SET_VAR(CONTEXT, links);
  SET_VAR(LAST, links);

#if DEBUG_CORE_WORDS
  CheckSum();
#endif

// setpin(13, 0);  // Indicate successful boot.
  run();

}

