/*
 * DisplayTask.h
 *
 *  Created on: Jul 8, 2021
 *      Author: alex
 */

#ifndef INC_DISPLAYTASK_H_
#define INC_DISPLAYTASK_H_

#include <FreeRtosTask.h>

class DisplayTask: private virtual FreeRtosTask {
public:
	DisplayTask(/*const*/char *name, uint32_t stack_size, osPriority_t priority);
	virtual ~DisplayTask();
	void CreateTask();
	static void Run();
};

#endif /* INC_DISPLAYTASK_H_ */
