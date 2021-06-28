/*
 * FreeRtosTaskHandler.h
 *
 *  Created on: Jun 28, 2021
 *      Author: alex
 */

#ifndef INC_FREERTOSTASKHANDLER_H_
#define INC_FREERTOSTASKHANDLER_H_

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

class FreeRtosTaskHandler {
public:
	FreeRtosTaskHandler();
	virtual ~FreeRtosTaskHandler();
};

#endif /* INC_FREERTOSTASKHANDLER_H_ */
