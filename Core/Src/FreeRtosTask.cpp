/*
 * FreeRtosTask.cpp
 *
 *  Created on: Jun 28, 2021
 *      Author: alex
 */

#include "FreeRtosTask.h"


FreeRtosTask::~FreeRtosTask() {
	// TODO Auto-generated destructor stub
}

FreeRtosTask::FreeRtosTask(/*const*/char *name, uint32_t stack_size, osPriority_t priority) :
m_Task_attributes{name,0,0,0,0, stack_size, priority}
{

}
