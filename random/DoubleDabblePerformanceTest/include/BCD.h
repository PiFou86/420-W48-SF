#include <Arduino.h>

#define NB_BITS_32 32
#define NB_BITS_16 16
#define NB_BITS_8 8

uint32_t double_dabble32(uint32_t n);
uint16_t double_dabble16(uint16_t n);
uint8_t double_dabble8(uint8_t n);

String bcd2String(uint16_t n);
String bcd2String(uint32_t n);
String bcd2String(uint8_t n);


String int2String(uint32_t n);
