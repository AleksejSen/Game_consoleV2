/*
 * Queue.h
 *
 *  Created on: Jun 29, 2021
 *      Author: alex
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_

#include "task.h"
#include "cmsis_os2.h"


class Queue {
public:
	//const osMessageQueueAttr_t m_Queue_attributes;
	const int m_QueueSize = 20;

	typedef struct {                                // object data type
	  uint8_t Buf[32];
	  uint8_t Idx;
	} MSGQUEUE_OBJ_t;


	osMessageQueueId_t m_QueueHandle;

	 ~Queue();
	Queue(uint32_t qeue_size, uint32_t msg_size, const char *name);

	//osMessageQueueId_t QueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &AdcQueue_attributes);
};

#endif /* INC_QUEUE_H_ */
