/*
 * nvm.c
 *
 *  Created on: Apr 2, 2025
 *      Author: NDA9HC
 */


#include "memlay.h"
#include "nvm.h"
#include "main.h"

nvm_value_t nvm_value;

void nvm_init() {
	nvm_value = *(nvm_value_t*)BOOT_NVM_START_ADDR;
}

void nvm_sync() {
	nvm_erase(BOOT_NVM_START_ADDR); // 1 page 18
	nvm_write_bytes(BOOT_NVM_START_ADDR, &nvm_value, sizeof(nvm_value));
}

static inline void nvm_wait_fs_ready() {
	while(FLASH->SR & FLASH_SR_BSY);
}

void nvm_write_bytes(uint32_t addr, void* data, uint16_t len) {
	uint16_t r_len = len/2 + len%2;
	HAL_FLASH_Unlock();
	FLASH->CR |= FLASH_CR_PG;
	for (int i = 0; i < r_len; i++) {
		nvm_wait_fs_ready();
		*(__IO uint16_t*)(addr + i*2) = *(uint16_t*)(data + i*2);
	}

	nvm_wait_fs_ready();
	FLASH->CR &= ~FLASH_CR_PG;
	HAL_FLASH_Lock();
}

void nvm_erase(uint32_t addr) {
	HAL_FLASH_Unlock();
	nvm_wait_fs_ready();
	FLASH->CR |= FLASH_CR_PER;
	FLASH->AR = addr;
	FLASH->CR |= FLASH_CR_STRT;
	nvm_wait_fs_ready();
	FLASH->CR &= ~FLASH_CR_PER;
	HAL_FLASH_Lock();
}

boot_type_t nvm_get_boot_type() {
	return nvm_value.boot_type;
}

void nvm_set_boot_type(boot_type_t type) {
	nvm_value.boot_type = type;
}

uint32_t nvm_get_app_crc() {
	return nvm_value.app_crc;
}

void nvm_set_app_crc(uint32_t crc) {
	nvm_value.app_crc = crc;
}

uint32_t nvm_get_hard_fault_cnt() {
	return nvm_value.hard_fault_cnt;
}

void nvm_set_hard_fault_cnt(uint32_t cnt) {
	nvm_value.hard_fault_cnt = cnt;
}
