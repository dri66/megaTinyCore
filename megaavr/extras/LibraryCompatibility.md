# Library Compatibility
Please include information that uniquely identifies the library, as popular libraries have dozens of forks all over the internet, and it is often difficult to identify which is the "right one". Bonus points if you include a version number too - but I've given up on that!

## DxCore vs megaTinyCore
This page is linked to from the DxCore documentation as well, for the simple reason that the similarity of the underlying hardware is such that something that works with one will work with the other unless it's using spexcific features that are onlyt present on one of the two, or if it is pooerly written and checks for specific parts, rather than peripeherals or things that are truefor a whole host of partt (ie, trsdting for #if defined(__ATtint3216__) || defined(__ATtiny1614__) - the two thingsthe author tested on, when the exact same code would work on any modern AVR if they had instead tested #if (__AVR_ARCH__>=102 && AVR_ARCH <= 104) - which poicks up all modern AVRs with 64k of flash (102), 128k of flash (104) or 32/48k or less (103, meaning fuilly memory-mapped flash)

<!-- markdownlint-disable-file MD034 -->
| Library      | Version | Library URL or reference                              | Status                               | Included w/ | Notes                                                     |
|--------------|---------|-------------------------------------------------------|--------------------------------------|-------------|-----------------------------------------------------------|
| tinyGPS++    |         | https://github.com/mikalhart/TinyGPSPlus              |                 Compiles and works   |             |                                                           |
| ~NeoGPS~     |         |                                                       |  Architecture warning, doesn't work  |             |                                                           |
| VL53L0X      |         | Pololu                                                |                 Compiles and works   |             |                                                           |
| VEML6070     |         | Adafruit                                              |                 Compiles and works   |             |                                                           |
| MLX90614     |         | https://github.com/adafruit/Adafruit-MLX90614-Library |                 Compiles and works   |             |                                                           |
| BMP180       |         | Adafruit                                              |                 Compiles and works   |             |                                                           |
| BME280       |         | Adafruit                                              |                 Compiles and works   |             |                                                           |
| OneWireNg    |         | https://github.com/pstolarz/OneWireNg                 |                 Compiles and works   |             |                                                           |
| ~OneWire~    | Original| ~https://github.com/PaulStoffregen/OneWire~           |                   Does not compile   |             | Not compatible with modern AVRs other than the ATmega4809 |
| OneWire      | Forked  | https://github.com/SpenceKonde/OneWire                | I added support for "megaavr", works |             | Tested PR submitted August 2020. No response from Paul.   |
| ~Neopixel~   |         | ~Adafruit~                                            |                   Does not compile   |        Core | Use included tinyNeoPixel - Same API, adapted for these   |
| LED Backpack |   1.1.8 | https://github.com/adafruit/Adafruit_LED_Backpack     |                 Compiles and works   |             |                                                           |
| Tiny4kOLED   |   1.5.4 | https://github.com/datacute/Tiny4kOLED                |                 Compiles and works   |             | SSD1306, not just for tinyAVR - anything with Wire.h!     |
| U8x8 and U8g2 |2.28.10 | https://github.com/olikraus/u8g2                      | U8x8 works. People disgree on U8g2   |             | See: [this issue, esp. ;the end of it w/example clode](https://github.com/SpenceKonde/megaTinyCore/discussions/454#discussioncomment-885742) |
| rc-switch    |         | https://github.com/sui77/rc-switch  (TX mode)         |                 Compiles and works   |             | A surprise. I don't expect RX will work                   |
| ~FAB-LED~    | Original| ~https://github.com/sonyhome/FAB_LED~                 |        Architecture is unsupported   |             | FAB-LED is a WS2812 w/out buffer library; impressive      |
| FAB-LED      | Forked  | https://github.com/SpenceKonde/FAB_LED                | I added support for "megaavr", works |             | No response to my PR to get my fix into his version :-/   |
| ~Servo~      |         | ~From library manager~ (the one included w/core works)|                      Compile error   |        Core | Use Servo_megaTinyCore if installed Servo via lib. mgr.   |
| TLC5947      |         | https://github.com/adafruit/Adafruit_TLC5947          |                 Compiles and works   |             | TLC5947 is a rather fancy LED driver.                     |
| MFRC522      | Frozen  | https://github.com/miguelbalboa/rfid                  |                 Compiles and works   |             | Long ago had issue relating to F(). This is the F()ing library that forced the return of the macro! |
| CAP1296      |         | https://github.com/mattThurstan/CAP1296               |                 Compiles and works   |             | Library needs cleanup - may not use correct ID by default, and prints stuff to Serial |
| MCP4725      |   2.0.0 | https://github.com/adafruit/Adafruit_MCP4725          |                 Compiles and works   |             | I2C 12-bit DAC                                            |
| MCP23017     |   2.0.0 | https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library |         Compiles and works   |             | Also supports the MCP23008, which has half as many pins   |
| VL53L0X      |         | Pololu                                                |                 Compiles and works   |             |                                                           |
| VL53L1X_ULD  |   1.2.2 | https://github.com/rneurink/VL53L1X_ULD               |                 Compiles and works   |   Lib. Mgr. |                                                           |
