#include <inttypes.h>
#include "register.h"
#include "rcc.h"

#define TIM1_BASE_ADDR 0x40012C00

struct adv_control_timer *tim1 = (struct adv_control_timer *)TIM1_BASE_ADDR;

struct adv_control_timer {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t BDTR;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
  volatile uint32_t CCMR3;
  volatile uint32_t CCR5;
  volatile uint32_t CCR6;
  volatile uint32_t AF1;
  volatile uint32_t AF2;
  volatile uint32_t TISEL;
};

void setup_timer1_pwm() {
  SET_BIT(RCC->APBENR2, 11);
  tim1->PSC = 5000;
  tim1->ARR = 10;
  tim1->CCR1 = 1;
  CLR_BIT(tim1->CCMR1, 16);
  SET_BIT(tim1->CCMR1, 6);
  SET_BIT(tim1->CCMR1, 5);
  CLR_BIT(tim1->CCMR1, 4);
  SET_BIT(tim1->CR1, 7);
  SET_BIT(tim1->CR1, 0);

  SET_BIT(tim1->CCER, 0);
  SET_BIT(tim1->BDTR, 15);// MOE

  SET_BIT(tim1->EGR, 0);
}

