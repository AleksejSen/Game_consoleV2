/*
 * DebugTask.h
 *
 *  Created on: Jun 28, 2021
 *      Author: alex
 */

#ifndef INC_DEBUGTASK_H_
#define INC_DEBUGTASK_H_

#include <FreeRtosTask.h>

class DebugTask: protected virtual FreeRtosTask {
public:
	//static void Run() override;
	 DebugTask(/*const*/char *name, uint32_t stack_size, osPriority_t priority);
	 ~DebugTask();
	 void CreateTask();
	 static void Run();


};

#endif /* INC_DEBUGTASK_H_ */
