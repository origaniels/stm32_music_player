#pragma once
#include <inttypes.h>

struct rcc {
  volatile uint32_t CR;
  volatile uint32_t ICSCR;
  volatile uint32_t CFGR;
  volatile uint32_t RESERVED1[2];
  volatile uint32_t CRRCR;
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  volatile uint32_t IOPRSTR;
  volatile uint32_t AHBRSTR;
  volatile uint32_t APBRSTR1;
  volatile uint32_t APBRSTR2;
  volatile uint32_t IOPENR;
  volatile uint32_t AHBENR;
  volatile uint32_t APBENR1;
  volatile uint32_t APBENR2;
  volatile uint32_t IOPSMENR;
  volatile uint32_t AHBSMENR;
  volatile uint32_t APBSMENR1;
  volatile uint32_t APBSMENR2;
  volatile uint32_t CCIPR;
  volatile uint32_t CCIPR2;
  volatile uint32_t CSR1;
  volatile uint32_t CSR2;
};
#define RCC ((struct rcc *)0x40021000)
