
#include "ForwardBehaviour.h"
#include <math.h>

ForwardBehaviour::ForwardBehaviour(Robot* robot) : Behaviour(robot){
	// TODO Auto-generated constructor stub

}

bool ForwardBehaviour::startCond()
{
	bool val;
    if (_robot->isBlocked(&val))
    {
    	return false;
    }

    cout << "started Action_Drive" <<endl;
    return true;
}
bool ForwardBehaviour::stopCond()
{
   bool val;

   // Check if road is blocked or if we reached the current target location(the waypoint).
   if (_robot->isBlocked(&val) || _robot->isNearLocation(_robot->getTargetLocation()))
   {
	   return true;
   }

   return false;
}
void ForwardBehaviour::action()
{
    // set positive speed in target direction
    _robot->setSpeed(1.0f,0.0f); // simply drive straight.
}
