
#ifndef ACTIONDRIVE_H_
#define ACTIONDRIVE_H_

#include "Behaviour.h"

class ForwardBehaviour: public Behaviour {
public:
	ForwardBehaviour(Robot* robot);
	virtual ~ForwardBehaviour(){}
	bool startCond();
	bool stopCond();
	void action();
};

#endif /* ACTIONDRIVE_H_ */
