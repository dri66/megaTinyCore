#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void yield(void);

#define LOW           0x00
#define HIGH          0x01
#define CHANGE        0x04
#define FALLING       0x02
#define RISING        0x03
#define INPUT         0x00
#define OUTPUT        0x01
#define INPUT_PULLUP  0x02
#define LSBFIRST      0x00
#define MSBFIRST      0x01


#define PI            3.1415926535897932384626433832795
#define HALF_PI       1.5707963267948966192313216916398
#define TWO_PI        6.283185307179586476925286766559
#define DEG_TO_RAD    0.017453292519943295769236907684886
#define RAD_TO_DEG    57.295779513082320876798154814105
#define EULER         2.718281828459045235360287471352

#define SERIAL        0x00
#define DISPLAY       0x01

#define min(a,b) \
  ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b; })

#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

#ifndef constrain
#define constrain(x,low,high)   ({  \
  typeof (x)    _x = (x);           \
  typeof (low)  _l = (low);         \
  typeof (high) _h = (high);        \
  _x < _l ? _l : _x > _h ? _h :_x ;})
#endif

#ifndef radians
#define radians(deg) ((deg)*DEG_TO_RAD)
#endif

#ifndef degrees
#define degrees(rad) ((rad)*RAD_TO_DEG)
#endif

#ifndef sq
#define sq(x)        ({ typeof (x) _x = (x); _x * _x; })
#endif

#ifndef round
#define round(x)     ({ typeof (x) _x = (x);  _x >= 0 ? (long)x + 0.5 : (long)x - 0.5 ;})
#endif

typedef void (*voidFuncPtr)(void);

// interrupts() / noInterrupts() must be defined by the core

// a bunch of really silly hand-holding macros!
#define lowByte (w) ((uint8_t) ((w)    &  0xff))
#define highByte(w) ((uint8_t) ((w)    >>    8))
#define  bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define   bitSet(value, bit)  ((value) |= (1UL << (bit)))
#define bitClear(value, bit)  ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#ifndef bit
#define bit(b) (1UL << (b))
#endif

/* TODO: request for removal */
typedef bool      boolean;
typedef uint8_t   byte;
typedef uint16_t  word;

void init(void);
void initVariant(void);

int atexit(void (*func)()) __attribute__((weak));
int main() __attribute__((weak));

#ifdef EXTENDED_PIN_MODE
// Platforms who want to declare more than 256 pins need to define EXTENDED_PIN_MODE globally
typedef uint32_t pin_size_t;
#else
typedef uint8_t pin_size_t;
#endif

void    pinMode(         pin_size_t pinNumber, uint8_t mode);
void    digitalWrite(    pin_size_t pinNumber, uint8_t val);
int8_t  digitalRead(     pin_size_t pinNumber);
void    analogWrite(     pin_size_t pinNumber, int value);
int     analogRead(      pin_size_t pinNumber);
void    analogReference(         uint8_t mode);
bool    analogReadResolution(     uint8_t res);

unsigned long millis(void);
unsigned long micros(void);

void delay(unsigned long);
void delayMicroseconds(unsigned int us);
unsigned long     pulseIn(pin_size_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(pin_size_t pin, uint8_t state, unsigned long timeout);

void   shiftOut(pin_size_t dataPin, pin_size_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(pin_size_t dataPin, pin_size_t clockPin, uint8_t bitOrder);

void attachInterrupt(pin_size_t interruptNumber, voidFuncPtr callback, uint8_t mode);
void detachInterrupt(pin_size_t interruptNumber);

void setup(void);
void loop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus
  /* C++ prototypes */
  uint16_t makeWord(uint16_t w);
  uint16_t makeWord(byte h, byte l);

  #define word(...) makeWord(__VA_ARGS__)

  unsigned long     pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
  unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

  void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
  void noTone(uint8_t _pin);

  // WMath prototypes
  long random(long);
  long random(long, long);
  void randomSeed(unsigned long);
  long map(long, long, long, long, long);

#endif // __cplusplus
