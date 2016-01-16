
#ifndef COMPLEXLOCATION_H_
#define COMPLEXLOCATION_H_

#include "Location.h"


// Represents an actual location in a 2D world with a yaw

class RobotLocation: public Location {
private :
	float _yaw;

	void construct(float yaw);

public:

	RobotLocation();
	RobotLocation(float yaw);
	RobotLocation(float x, float y);
	RobotLocation(float x, float y, float yaw);



	Location getLocation(){
		Location loc(getX(),getY());

		return loc;
	}




	float getYaw() const {
		return _yaw;
	}

	void setYaw(float yaw) {
		_yaw = yaw;
	}

};

#endif
