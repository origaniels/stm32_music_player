#include "rcc.h"
#include "gpio.h"
#include "clock.h"
#include "uart.h"


int main() {
  systick_init();

  bool out = true;

  struct pin pin = (struct pin){BANKA, 5};
  gpio_set_mode(pin, GPIO_MODE_OUTPUT);
  for (;;) {
    gpio_write(pin, out);
    out = !out;
    uart_write_buf(USART2, "Hello\n\r", 7);

    delay(1000);
  }
  return 0;
}


__attribute__((naked, noreturn)) void _reset() {
  extern long _sbss, _ebss, _sdata, _edata, _sidata;
  for (long *dst = &_sbss; dst < &_ebss; dst++)
      *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;)
      *dst++ = *src++;

  main();
  for (;;) (void) 0;
}

extern void _estack();

__attribute__((section(".vectors"))) void (*const tab[16 + 91])(void) = {
  [0] = _estack,
  [1] = _reset,
  [15] = Systick_handler
};
