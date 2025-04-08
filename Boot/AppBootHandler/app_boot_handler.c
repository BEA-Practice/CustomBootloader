/*
 * app_boot_handler.c
 *
 *  Created on: Apr 2, 2025
 *      Author: NDA9HC
 */


#include "app_boot_handler.h"
#include "Flash/memlay.h"

#include "main.h"

void app_boot_handler_init() {

}

static int validate_crc() {
	return 1;
}

void app_boot_handler_process() {
	if (!validate_crc()) return;

	uint32_t app_sp = *((volatile uint32_t*)APP_VTOR_OFFSET);
	uint32_t app_reset_addr = *((volatile uint32_t*)(APP_VTOR_OFFSET + 4));

	if (app_reset_addr & 0x1) {
		HAL_DeInit();

		typedef void (*pFunction)(void);
		__set_MSP(app_sp);
		SCB->VTOR = APP_VTOR_OFFSET;
		pFunction app_entry = (pFunction)(app_reset_addr);
		app_entry();
	} else {

	}
}
