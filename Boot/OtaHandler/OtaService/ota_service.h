/*
 * ota_service.h
 *
 *  Created on: Apr 7, 2025
 *      Author: NDA9HC
 */

#ifndef OTAHANDLER_OTASERVICE_OTA_SERVICE_H_
#define OTAHANDLER_OTASERVICE_OTA_SERVICE_H_

#include "ota_service_handler.h"

typedef uint32_t (*phandler)(uint8_t*, uint16_t);
typedef struct {
	uint32_t id;
	phandler handler;
} service;

service ota_handlers[] = {
		{0x22, &handle_ota_read_version},
		{0x2711, &handle_ota_request_seed},
		{0x2712, &handle_ota_transfer_key},
		{0x3101FF00, &handle_ota_erase_memory},
		{0x34, &handle_ota_request_download},
		{0x36, &handle_ota_transfer_data},
		{0x37, &handle_ota_transfer_exit},
		{0x31010202, &handle_ota_check_memory},
		{0x1101, &handle_ota_ecu_reset}
};



#endif /* OTAHANDLER_OTASERVICE_OTA_SERVICE_H_ */
