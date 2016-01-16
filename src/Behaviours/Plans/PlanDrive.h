
#ifndef PLANDRIVE_H_
#define PLANDRIVE_H_

#include "Plan.h"
#include "../RotateBehaviour.h"
#include "../ForwardBehaviour.h"
#include "../ObstacleBehaviour.h"
#include "../WaypointSelectionBehaviour.h"
#include "WayPointsManager.h"

class PlanDrive: public Plan {
	Behaviour* _beh[4];

public:
	PlanDrive(Robot* robot);
	PlanDrive(Robot* robot, WayPointsManager* wpManager);
	Behaviour* getStartPoint();
	virtual ~PlanDrive();
};

#endif /* PLANDRIVE_H_ */
