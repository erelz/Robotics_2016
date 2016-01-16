
#ifndef ACTIONOBSTACLE_H_
#define ACTIONOBSTACLE_H_

#include "Behaviour.h"
#include <ctime>

#define DRIVE_AWAY_TIME_SECONDS 2

class ObstacleBehaviour: public Behaviour {
private:
	bool obstacle_from_right;
	clock_t drive_away_start_time;
	bool drive_away;
public:
	ObstacleBehaviour(Robot* robot);
	virtual ~ObstacleBehaviour(){}
	bool startCond();
	bool stopCond();
	void action();
};

#endif /* ACTIONOBSTACLE_H_ */
