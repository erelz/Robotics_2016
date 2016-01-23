/*
 * Waypoint.h
 */

#ifndef WAYPOINT_H_
#define WAYPOINT_H_

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "Types.h"

using namespace std;

class Waypoint {
public:
	vector<Location> mPath;
	vector<Location> Waypoints;
	Waypoint(vector<Location> &mPath);

	vector<Location> MakeWaypoints();

	virtual ~Waypoint();
};

#endif /* WAYPOINT_H_ */
