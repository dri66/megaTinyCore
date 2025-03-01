# EEPROM Library V2.0 for Arduino
Written by: _Christopher Andrews_.

## What is the EEPROM library

The EEPROM library provides an easy to use interface to interact with the internal non-volatile storage found in AVR based Arduino boards. This library will work on many AVR devices like ATtiny and ATmega chips.

## How to use it
The EEPROM library is included in your IDE download. To add its functionality to your sketch you'll need to reference the library header file. You do this by adding an include directive to the top of your sketch.

```Arduino
#include <EEPROM.h>

void setup(){

}

void loop(){

}

```

The library provides a global variable named `EEPROM`, you use this variable to access the library functions. The methods provided in the EEPROM class are listed below.

## Warning about invalid addresses
It is possible to specify addresses beyond the end of the EEPROM or (through a negative number) ones before it's beginning. On parts with 256b of EEPROM, this just wraps around to the other end, like classic AVRs did. On parts with less, it will still wrap around, but addresses between the end of the EEPROM and 255 (after which it wraps around) read as 0x00 and cannot be written. On Dx-series parts, many of which have 512b of EEPROM, there is no wraparound, and if you go far enough out and try to write, you'll overwrite other stuff. Don't do that.

## EEPROM Sizes

| AVR Device | EEPROM size |
|---------------------|--------|
| tinyAVR 0/1/2-series 2k flash | 64b |
| tinyAVR 0/1/2-series 4-8k flash | 128b |
| tinyAVR 0/1/2-series 16-32k flash | 256b |
| megaAVR 0-series (all flash sizes) | 256b |
| DA, DB, EA-series (all flash sizes) | 512b |
| DD-series (all flash sizes) | 256b |

You can view all the examples [here](examples/).

## Library functions

### `EEPROM.read( address )` [[_example_]](examples/eeprom_read/eeprom_read.ino)

This function allows you to read a single byte of data from the eeprom.
Its only parameter is an `int` which should be set to the address you wish to read.

The function returns an `unsigned char` containing the value read.

### `EEPROM.write( address, value )` [[_example_]](examples/eeprom_write/eeprom_write.ino)

The `write()` method allows you to write a single byte of data to the EEPROM.
Two parameters are needed. The first is an `int` containing the address that is to be written, and the second is a the data to be written (`unsigned char`).

This function does not return any value.

### `EEPROM.update( address, value )` [[_example_]](examples/eeprom_update/eeprom_update.ino)

This function is similar to `EEPROM.write()` however this method will only write data if the cell contents pointed to by `address` is different to `value`. This method can help prevent unnecessary wear on the EEPROM cells.

This function does not return any value.

### `EEPROM.get( address, object )` [[_example_]](examples/eeprom_get/eeprom_get.ino)

This function will retrieve any object from the EEPROM.
Two parameters are needed to call this function. The first is an `int` containing the address that is to be written, and the second is the object you would like to read.

This function returns a reference to the `object` passed in. It does not need to be used and is only returned for conveience.

### `EEPROM.put( address, object )` [[_example_]](examples/eeprom_put/eeprom_put.ino)

This function will write any object to the EEPROM.
Two parameters are needed to call this function. The first is an `int` containing the address that is to be written, and the second is the object you would like to write.

This function uses the _update_ method to write its data, and therefore only rewrites changed cells.

This function returns a reference to the `object` passed in. It does not need to be used and is only returned for conveience.

### **Subscript operator** `EEPROM[address]` [[_example_]](examples/eeprom_crc/eeprom_crc.ino)

This operator allows using the identifier `EEPROM` like an array.
EEPROM cells can be read _and_ written directly using this method.

This operator returns a reference to the EEPROM cell.

```c++
unsigned char val;

//Read first EEPROM cell.
val = EEPROM[ 0 ];

//Write first EEPROM cell.
EEPROM[ 0 ] = val;

//Compare contents
if( val == EEPROM[ 0 ] ){
  //Do something...
}
```

### `EEPROM.length()`

This function returns an `unsigned int` containing the number of cells in the EEPROM.

---

## Advanced features

This library uses a component based approach to provide its functionality. This means you can also use these components to design a customized approach. Two background classes are available for use: `EERef` & `EEPtr`.

### `EERef` class

This object references an EEPROM cell.
Its purpose is to mimic a typical byte of RAM, however its storage is the EEPROM.
This class has an overhead of two bytes, similar to storing a pointer to an EEPROM cell.

```C++
EERef ref = EEPROM[ 10 ]; //Create a reference to 11th cell.

ref = 4; //write to EEPROM cell.

unsigned char val = ref; //Read referenced cell.
```

### `EEPtr` class

This object is a bidirectional pointer to EEPROM cells represented by `EERef` objects.
Just like a normal pointer type, this type can be dereferenced and repositioned using
increment/decrement operators.

```C++
EEPtr ptr = 10; //Create a pointer to 11th cell.

*ptr = 4; //dereference and write to EEPROM cell.

unsigned char val = *ptr; //dereference and read.

ptr++; //Move to next EEPROM cell.
```

### `EEPROM.begin()`

This function returns an `EEPtr` pointing to the first cell in the EEPROM.
This is useful for STL objects, custom iteration and C++11 style ranged for loops.

### `EEPROM.end()`

This function returns an `EEPtr` pointing at the location after the last EEPROM cell.
Used with `begin()` to provide custom iteration.

**Note:** The `EEPtr` returned is invalid as it is out of range. See the warning about invalid addresses above.

## EEPROM corruption due to low supply voltage
If the power supply voltage is insufficient (as in, below operating specifications) while writing to the EEPROM, corruption can result; this includes the case where power is cut entirely while writing to the EEPROM. This phenomenon is described in the "Preventing Flash/EEPROM corruption" section of the datasheet. Enabling the Brown-Out Detect functionality ("burn bootloader" required after changing those settings to apply them) will prevent this by holding the part in reset when below a minimum supply voltage. If BOD is for some reason unacceptable as a solution (for example due to power consumption and battery life concerns), the ADC could be used to read the supply voltage to ensure that it is within a normal operating range prior to writing to the EEPROM. The minimum threshold voltage option is sufficient for preventing EEPROM corruption.
