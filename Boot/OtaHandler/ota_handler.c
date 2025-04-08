/*
 * ota_handler.c
 *
 *  Created on: Apr 2, 2025
 *      Author: NDA9HC
 */


#include <Flash/nvm.h>
#include "ota_handler.h"

#include "Flash/nvm.h"
#include "Utils/LED/led_blink.h"

#include "main.h"

void ota_handler_init() {
	Led_blink_init(0b0010010101, 100);
}

void ota_handler_process() {
	uint32_t led_last_tick = 0;
	uint32_t ota_start_tick = HAL_GetTick();

	while(1) {
		if (HAL_GetTick() - led_last_tick >= 10)
		{
			led_last_tick = HAL_GetTick();
			Led_blink_proc_10ms();
		}

		if (HAL_GetTick() - ota_start_tick >= 5000) {
			nvm_set_boot_type(BOOT_TYPE_NORMAL_BOOT);
			nvm_sync();
			NVIC_SystemReset();
		}
	}
}

void handle_ota_jump(void);

__IO uint32_t* ota_jump_vect[] __attribute__((section(".ota_jump"))) = {
	(__IO  uint32_t*)&handle_ota_jump
};

void handle_ota_jump(void) {
	nvm_set_boot_type(BOOT_TYPE_OTA_SESSION);
	nvm_sync();
	NVIC_SystemReset();
}
