/*
 * printf.c
 *
 *  Created on: May 13, 2021
 *      Author: alex
 */

#include "printf.h"
#include "usart.h"

#ifdef __cplusplus
extern "C" {
#endif

int __io_putchar(int ch) {
	uint8_t c[1];
	c[0] = ch & 0x00FF;
	HAL_UART_Transmit(&huart2, &*c, 1, 10);
	return ch;
}

int _write(int file, char *ptr, int len) {
	int DataIdx;
	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		__io_putchar(*ptr++);
	}
	return len;
}

#ifdef __cplusplus
}
#endif
