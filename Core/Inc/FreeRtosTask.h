/*
 * FreeRtosTask.h
 *
 *  Created on: Jun 28, 2021
 *      Author: alex
 */

#ifndef INC_FREERTOSTASK_H_
#define INC_FREERTOSTASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"


class FreeRtosTask {
protected:
	osThreadId_t m_TaskHandle;
	const osThreadAttr_t m_Task_attributes;

public:

	FreeRtosTask(/*const*/ char *name, uint32_t stack_size, osPriority_t priority);
	virtual ~FreeRtosTask();

};

#endif /* INC_FREERTOSTASK_H_ */
