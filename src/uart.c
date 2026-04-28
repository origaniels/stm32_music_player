#include "uart.h"

void uart_init(struct uart *uart) {
  uint8_t af = 1;
  struct pin rx, tx;

  if (uart == USART1) SET_BIT(RCC->APBENR2, 14);
  if (uart == USART2) SET_BIT(RCC->APBENR1, 17);
  if (uart == USART3) SET_BIT(RCC->APBENR1, 18);

	if (uart == USART1) CLR_BIT(RCC->APBRSTR2, 14);
  if (uart == USART2) CLR_BIT(RCC->APBRSTR1, 17);
  if (uart == USART3) CLR_BIT(RCC->APBRSTR1, 18);

  if (uart == USART1) tx = (struct pin){BANKA, 2}, rx = (struct pin){BANKA, 3};
  if (uart == USART3) tx = (struct pin){BANKA, 2}, rx = (struct pin){BANKA, 3};

  if (uart == USART2) tx = (struct pin){BANKA, 2}, rx = (struct pin){BANKA, 3};
  gpio_set_mode(tx, GPIO_MODE_AF);
  gpio_set_af(tx, af);
  gpio_set_mode(rx, GPIO_MODE_AF);
  gpio_set_af(rx, af);
  uart->BRR = BRR_VALUE;
  uart->CR2 = 0;
	uart->CR3 = 0;
  uart->CR1 = 0;
  SET_BIT(uart->CR1, 2);
  SET_BIT(uart->CR1, 3);
  SET_BIT(uart->CR1, 0);
}

int uart_read_ready(struct uart *uart) {
  return uart->ISR & BIT(5);
}

uint8_t uart_read_byte(struct uart *uart) {
  return (uint8_t) (uart->RDR & 255);
}

void uart_write_byte(struct uart *uart, uint8_t byte) {
	uart->TDR = byte;
  while (!(uart->ISR & BIT(7))) {}
}

void uart_write_buf(struct uart *uart, char *buf, size_t len) {
  while (len-- > 0) uart_write_byte(uart, *(uint8_t *) buf++);
}
