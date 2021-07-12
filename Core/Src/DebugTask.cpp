/*
 * DebugTask.cpp
 *
 *  Created on: Jun 28, 2021
 *      Author: alex
 */

#include <DebugTask.h>
#include <cstdio>
#include "printf.h"

DebugTask::~DebugTask() {
	// TODO Auto-generated destructor stub
}

DebugTask::DebugTask(/*const*/char *name, uint32_t stack_size,
		osPriority_t priority) :
		FreeRtosTask(name, stack_size, priority) {
	CreateTask();
}

void DebugTask::CreateTask() {
	m_TaskHandle = osThreadNew((osThreadFunc_t) Run, NULL, &m_Task_attributes);
}

void DebugTask::Run() {

	for (;;) {
		//printf("dbg\r\n");
		osDelay(400);
	}

}
