/*
 * led_blink.c
 *
 *  Created on: Apr 1, 2025
 *      Author: NDA9HC
 */


#include "led_blink.h"
#include "main.h"

static uint32_t led_blink_pattern_s;
static uint32_t led_blink_interval_s;

void Led_blink_proc_10ms(void) {
	static uint32_t last_tick = 0;
	static uint32_t iterater = 0;

	uint32_t cur_tick = HAL_GetTick();
	if (cur_tick - last_tick >= led_blink_interval_s) {
		last_tick = cur_tick;
		iterater >>= 1;
		GPIO_PinState cmd = (GPIO_PinState)(iterater & 0x1);
		HAL_GPIO_WritePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin, cmd);

		if (iterater == 0) {
			iterater = led_blink_pattern_s;
		}
	}
}

void Led_blink_init(uint32_t pattern, uint32_t interval) {
	led_blink_pattern_s = pattern;
	led_blink_interval_s = interval;
}

