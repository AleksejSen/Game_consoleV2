/*
 * JoystickButtonTask.h
 *
 *  Created on: Jun 28, 2021
 *      Author: alex
 */

#ifndef INC_JOYSTICKBUTTONTASK_H_
#define INC_JOYSTICKBUTTONTASK_H_

#include <FreeRtosTask.h>

class JoystickButtonTask: private FreeRtosTask {
private:

public:
	JoystickButtonTask(/*const*/char *name, uint32_t stack_size, osPriority_t priority);
	virtual ~JoystickButtonTask();
	void CreateTask();
	static void Run();

};

#endif /* INC_JOYSTICKBUTTONTASK_H_ */
