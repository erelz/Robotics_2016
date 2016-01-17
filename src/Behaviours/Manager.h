

#ifndef MANAGER_H_
#define MANAGER_H_
#include "Plans/PlanDrive.h"
#include "../Robot.h"
class Manager {
	Behaviour* _curr;
	Robot* _robot;
public:
	Manager(Robot* robot, Plan* pln);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
