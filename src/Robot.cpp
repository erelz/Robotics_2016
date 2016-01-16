
#include "Robot.h"

Robot::Robot(char* ip, int port, RobotLocation initial_location) {
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	decision_made = false;
	decided_direction_is_left = false;

	_pp->SetMotorEnable(true);

	for(int i=0;i<15;i++)
		Read();

	_pp->SetOdometry(initial_location.getX(),initial_location.getY(), initial_location.getYaw());
}

Robot::~Robot() {
	delete _pc;
	delete _pp;
	delete _lp;
}

bool Robot::isBlocked(bool* is_blocked_from_right) {

	// Checking if the robot is blocked from the right
	if (!right_flank_clear())
	{

		if (!decision_made)
		{
			decided_direction_is_left = true;

			decision_made = true;
		}
	}
	// Checking if there is an obstacle from the left or forward
	else if (!left_flank_clear() || (*_lp)[forward] < 0.3f)
	{
		if (!decision_made)
		{
			decided_direction_is_left = false;
			decision_made = true;
		}
	}
	// If the robot is not blocked changing the decision to false
	else
	{
		decision_made = false;
	}

	*is_blocked_from_right = decided_direction_is_left;
	return decision_made;
}

bool Robot::right_flank_clear()
{
	for(int i = forward + 50; i < 566; i+= 5)
	{
		// Checking if there is an obstacle in front of the robot
		if ((*_lp)[i] < 0.85 - i * 0.001)
	    {
	    	return false;
	    }
	}
	return true;
}

bool Robot::left_flank_clear()
{
	for(int i = 100; i < forward - 50; i+= 5)
	{
		// Checking if there is an obstacle in front of the robot
	    if ((*_lp)[i] < 0.25 + i * 0.001)
	    {
	    	return false;
	    }
	}
	return true;
}

bool Robot::isNearLocation(Location loc)
{
    float distance = getCurrentLocation().Distance(loc);

	if (distance < 0.3f)
	{
		return true;
	}

	return false;
}


void Robot::setTargetLocation(Location target)
{
	this->target_location = target;
}

Location Robot::getTargetLocation()
{
	return this->target_location;
}

Location Robot::getCurrentLocation()
{
	Location curr_loc((float)_pp->GetXPos(),(float)_pp->GetYPos());
	return curr_loc;
}
float Robot::getYaw()
{
	return _pp->GetYaw();
}
