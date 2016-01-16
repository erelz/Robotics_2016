
#include <Behaviours/WaypointSelectionBehaviour.h>

WaypointSelectionBehaviour::WaypointSelectionBehaviour(Robot* robot) : Behaviour(robot){
	// TODO Auto-generated constructor stub
	isWaypointSet = false;
}

bool WaypointSelectionBehaviour::startCond()
{
	// check if the robot is near our current waypoint.
    if (_robot->isNearLocation(wpManager->getCurrnetWayPoint().getRealLocation()))
    {
    	isWaypointSet = false; // do it before we select a waypoint. so action will be called.
    	cout << "Started Action_SelectWaypoint" << endl;
    	return true;
    }

    // the robot is not close to the current waypoint. cant switch waypoints.
    return false;
}
bool WaypointSelectionBehaviour::stopCond()
{
	// if the waypoint was not set, stay in the behaviour.
	// basicly im just making sure the action func ran atleast once.
   return isWaypointSet;
}
void WaypointSelectionBehaviour::action()
{
	// if you reached your current waypoint, set a new one!
	if (_robot->isNearLocation(wpManager->getCurrnetWayPoint().getRealLocation()))
	{
		wpManager->advanceWayPoint();
	}

	Location waypoint_loc =  wpManager->getCurrnetWayPoint().getRealLocation();

	// Give the robot his current target. (might be the same way point if he didn't reach it or a new one).
	_robot->setTargetLocation(waypoint_loc);

	isWaypointSet = true;
}

void WaypointSelectionBehaviour::setWaypointManager(WayPointsManager* wp)
{
	this->wpManager = wp;
}

