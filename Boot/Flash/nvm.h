/*
 * nvm.h
 *
 *  Created on: Apr 2, 2025
 *      Author: NDA9HC
 */

#ifndef NVM_H_
#define NVM_H_

#include <stdint.h>

typedef enum boot_type_t {
	BOOT_TYPE_OTA_SESSION = 0u,
	BOOT_TYPE_NORMAL_BOOT = 1u
} boot_type_t;

typedef struct nvm_value_t {
	uint32_t app_crc;
	uint32_t hard_fault_cnt;
	boot_type_t boot_type;
} nvm_value_t;

void nvm_init();
void nvm_sync();

boot_type_t nvm_get_boot_type();
void nvm_set_boot_type(boot_type_t type);

uint32_t nvm_get_app_crc();
void nvm_set_app_crc(uint32_t crc);

uint32_t nvm_get_hard_fault_cnt();
void nvm_set_hard_fault_cnt(uint32_t cnt);

void nvm_write_bytes(uint32_t addr, void* data, uint16_t len);
void nvm_erase(uint32_t addr);

#endif /* NVM_H_ */
