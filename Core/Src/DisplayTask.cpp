/*
 * DisplayTask.cpp
 *
 *  Created on: Jul 8, 2021
 *      Author: alex
 */

#include <DisplayTask.h>
#include <cstdio>
#include "printf.h"

extern "C" {
#include "ST7735.h"
#include "fonts.h"
#include "GFX_FUNCTIONS.h"
#include "bitmaps.h"
}

DisplayTask::~DisplayTask() {
	// TODO Auto-generated destructor stub
}

DisplayTask::DisplayTask(/*const*/char *name, uint32_t stack_size,
		osPriority_t priority) :
		FreeRtosTask(name, stack_size, priority) {
	CreateTask();
}

void DisplayTask::CreateTask() {
	m_TaskHandle = osThreadNew((osThreadFunc_t) Run, NULL, &m_Task_attributes);
}

void DisplayTask::Run() {

	//extern osMessageQueueId_t msgQueue;

	extern osMessageQueueId_t adcQueue;

	ST7735_Init(0);
	fillScreen(BLACK);
	ST7735_SetRotation(1);

	//ST7735_WriteString(30, 30, "Game Console V2", Font_7x10, RED, BLACK);
	//ST7735_WriteString(50, 50, "STM32F4", Font_7x10, RED, BLACK);
	//ST7735_WriteString(10, 70, "by Aleksejs Sencenko", Font_7x10, RED, BLACK);

	uint32_t joystick_val[2];
	osStatus_t status;
	uint16_t x, y;

	for (;;) {
		//printf("Display\r\n");

		status = osMessageQueueGet(adcQueue, &joystick_val, NULL, 0U); // wait for message
		if (status == osOK) {
			//printf("Y: %d  X: %d \r\n",joystick_val[0], joystick_val[1] );

			if (joystick_val[1] < 1700) {
				ST7735_WriteString(150, 5, "<", Font_7x10, RED, BLACK);
				if (x < 0) {
					x = 0;
				} else {
					--x;
				}

			} else if (joystick_val[1] > 2300) {
				ST7735_WriteString(150, 5, ">", Font_7x10, RED, BLACK);
				if (x > 140) {
					x = 140;
				} else {
					++x;
				}

			} else {
				ST7735_WriteString(150, 5, " ", Font_7x10, RED, BLACK);
			}

			if (joystick_val[0] < 1700) {
				ST7735_WriteString(142, 5, "^", Font_7x10, RED, BLACK);
				if (y < 0) {
					y = 0;
				} else {
					--y;
				}

			} else if (joystick_val[0] > 2300) {
				ST7735_WriteString(142, 5, "v", Font_7x10, RED, BLACK);
				if (y > 100) {
					y = 100;
				} else {
					++y;
				}
			} else {
				ST7735_WriteString(142, 5, " ", Font_7x10, RED, BLACK);
			}

		}

		osDelay(5);
	}

}
