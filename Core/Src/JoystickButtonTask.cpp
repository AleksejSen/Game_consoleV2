/*
 * JoystickButtonTask.cpp
 *
 *  Created on: Jun 28, 2021
 *      Author: alex
 */

#include <JoystickButtonTask.h>
#include <cstdio>
#include "printf.h"
#include "adc.h"
//#include "cmsis_os.h"




/*Queue Crateion TODO:Create Queue Class*/
const osMessageQueueAttr_t AdcQueue_attributes = {
  .name = "AdcQueue"
};

osMessageQueueId_t AdcQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &AdcQueue_attributes);
/*END Queue Crateion*/

JoystickButtonTask::JoystickButtonTask(/*const*/char *name, uint32_t stack_size, osPriority_t priority):
	FreeRtosTask(name, stack_size, priority) {
		CreateTask();
}

JoystickButtonTask::~JoystickButtonTask() {
	// TODO Auto-generated destructor stub
}


void JoystickButtonTask::CreateTask() {
	m_TaskHandle = osThreadNew((osThreadFunc_t) Run, NULL, &m_Task_attributes);
}

void JoystickButtonTask::Run() {
//	uint32_t adc_buff[2];
//	uint32_t adc_buff_y;
//	uint32_t adc_x;
//	uint32_t adc_y;
//	uint8_t conversion_done = 0;
//
//	HAL_ADC_Start_DMA(&hadc1, adc_buff, 2);

	extern osMessageQueueId_t adcQueue;

	uint32_t joystick_val[2];
	osStatus_t status;

	for (;;) {

	    status = osMessageQueueGet(adcQueue, &joystick_val, NULL, 0U);   // wait for message
	    if (status == osOK) {
	      printf("Y: %d  X: %d \r\n",joystick_val[0], joystick_val[1] );
	    }
		//printf("Joystick\r\n");
		osDelay(100);
	}

}
