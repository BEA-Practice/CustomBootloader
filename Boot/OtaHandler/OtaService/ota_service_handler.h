/*
 * ota_service_handler.h
 *
 *  Created on: Apr 7, 2025
 *      Author: NDA9HC
 */

#ifndef OTAHANDLER_OTASERVICE_OTA_SERVICE_HANDLER_H_
#define OTAHANDLER_OTASERVICE_OTA_SERVICE_HANDLER_H_

#include <stdint.h>

uint32_t handle_ota_read_version(uint8_t* payload, uint16_t len);
uint32_t handle_ota_request_seed(uint8_t* payload, uint16_t len);
uint32_t handle_ota_transfer_key(uint8_t* payload, uint16_t len);
uint32_t handle_ota_erase_memory(uint8_t* payload, uint16_t len);
uint32_t handle_ota_request_download(uint8_t* payload, uint16_t len);
uint32_t handle_ota_transfer_data(uint8_t* payload, uint16_t len);
uint32_t handle_ota_transfer_exit(uint8_t* payload, uint16_t len);
uint32_t handle_ota_check_memory(uint8_t* payload, uint16_t len);
uint32_t handle_ota_ecu_reset(uint8_t* payload, uint16_t len);

#endif /* OTAHANDLER_OTASERVICE_OTA_SERVICE_HANDLER_H_ */
