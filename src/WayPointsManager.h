
#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_

#include <vector>

#include "WayPoints/WayPoint.h"
#include "Commons/Location.h"
#include "Commons/GridPosition.h"
#include "Commons/MapObject.h"
#include "Commons/Utils.h"

using namespace std;

class WayPointsManager {
private :
	MapObject _originalMap;
	vector<GridPosition> _positions;
	vector<WayPoint> _wayPoints;

	unsigned _currentWayPoint;
public:

	//******************
	//	Ctor
	//******************
	WayPointsManager(vector<GridPosition> path, MapObject map);





	// Increasing the currentWayPoint and returning it until we get to the last waypoint

	WayPoint advanceWayPoint(){
		this->_currentWayPoint++;

		return getCurrnetWayPoint();
	}

	
	// * Returns the current way point


	WayPoint getCurrnetWayPoint(){
		return _wayPoints[_currentWayPoint];
	}

	/**
	 * Getting a specific way point
	 */
	WayPoint getWayPointNumber(unsigned number){
		return _wayPoints[number];
	}

	/**
	 * Returning number of way points available
	 */
	unsigned getNumberOfWayPoints(){
		return _wayPoints.size();
	}

	vector<GridPosition> getChosenPositions(){
		return _positions;
	}


	//********************
	//	Public methods
	//********************
	void savePointsOnMap(string name){
		Utils::writeMapToPng(name,_originalMap);
	}

private:
	//****************************
	//	Initialization methods
	//****************************

	
	// Getting the grid positions and choosing a selected amount of Way points

	// Every step is twice the robot's size
	void initializePositionsArray(vector<GridPosition> path){
		int robotsInPixel = ConfigurationsManager::getRobotSize() / _originalMap.getCell2Cm();

		int jumps = robotsInPixel * 2;

		for(unsigned i=0; i< path.size(); i += jumps){
			this->_positions.push_back(path[i]);
		}

		if ((path.size() % jumps) != 0){
			this->_positions.push_back(path[path.size() -1]);
		}

		_positions.erase(_positions.begin());

		Utils::insertPathToMap(_originalMap,_positions);
	}

	
	// Creating the waypoints from the grid positions
	 
	void initializeWayPointsWrray(){
		for (unsigned i = 0; i < _positions.size() ; i++){
			Location loc = _originalMap.locationFromPosition(_positions[i]);
			this->_wayPoints.push_back(WayPoint(loc,i));
		}
	}


};

#endif
