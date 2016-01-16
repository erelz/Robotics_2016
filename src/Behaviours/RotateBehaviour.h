#ifndef ACTIONROTATE_H_
#define ACTIONROTATE_H_

#include "Behaviour.h"

class RotateBehaviour: public Behaviour {
public:
	RotateBehaviour(Robot* robot);
	virtual ~RotateBehaviour(){};
	bool startCond();
	bool stopCond();
	void action();
};

#endif /* ACTIONROTATE_H_ */
