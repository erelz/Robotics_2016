

#ifndef ACTIONSELECTWAYPOINT_H_
#define ACTIONSELECTWAYPOINT_H_

#include "Behaviour.h"
#include "WayPointsManager.h"

class WaypointSelectionBehaviour: public Behaviour {
private:
	bool isWaypointSet;
	WayPointsManager* wpManager;
public:
	WaypointSelectionBehaviour(Robot* robot);
	virtual ~WaypointSelectionBehaviour(){};
	bool startCond();
	bool stopCond();
	void action();

	void setWaypointManager(WayPointsManager* wp);
};

#endif /* ACTIONSELECTWAYPOINT_H_ */
