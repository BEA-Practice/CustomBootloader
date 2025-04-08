/*
 * led_blink.h
 *
 *  Created on: Apr 1, 2025
 *      Author: NDA9HC
 */

#ifndef UTILS_LED_LED_BLINK_H_
#define UTILS_LED_LED_BLINK_H_

#include <stdint.h>

void Led_blink_proc_10ms(void);
void Led_blink_init(uint32_t pattern, uint32_t interval);

#endif /* UTILS_LED_LED_BLINK_H_ */
