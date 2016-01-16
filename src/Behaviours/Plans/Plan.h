
#ifndef PLAN_H_
#define PLAN_H_
#include "../Behaviour.h"

class Plan {

protected:
	Behaviour* _start;
public:
	Plan(Robot* robot);
	virtual Behaviour* getStartPoint(){return _start;}
	virtual ~Plan();
};

#endif /* PLAN_H_ */
