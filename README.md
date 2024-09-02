# mmlib

Martins Micro Library in standard C, for micro processors

## standard c libraries

mmlib uses c standard libraries, example: use `stdbool.h` and therefore `true` and `false` for instance.

## implemented and tested features

## documentation

see [readme](docs/readme.md)

## ideas, whishlist

- data management
  - array list
  - fifo, queue
  - linked list
- string functions
  - uint8/16/32 to string
  - int8/16/32 to string
  - float to string, precision pro and post point :-)
- communication, high level, hal is still needed, but should work with this api
  - spi
  - uart
  - i2c/twi
- memory management in fixed memory space
  - new
  - free, delete
- macros
  - number of elements additional to sizeof, using sizeof
  - bitvalue, bitmask
- typedefs
  - uint32_16_t
  - uint32_8_t

## workflow

1. start by writing the documentation of a given feature like the linked list
2. write tests
3. implement the actual feature
4. verify the code by running the tests
