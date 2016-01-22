
#ifndef LOCATION_H_
#define LOCATION_H_

#include <math.h>

class Location {
private :
	float _x;
	float _y;
	float _yaw;

	void construct(float x,float y, float yaw);

public:
	//**********************
	//		Ctor
	//**********************
	Location();
	Location(float x,float y, float yaw);

	float getX() const {
		return _x;
	}

	void setX(float x) {
		_x = x;
	}

	float getY() const {
		return _y;
	}

	void setY(float y) {
		_y = y;
	}

	float getYaw() const {
		return _yaw;
	}

	void setYaw(float yaw) {
		_yaw = yaw;
	}


};

#endif
