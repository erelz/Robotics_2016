
#include "WayPointsManager.h"

WayPointsManager::WayPointsManager(vector<GridPosition> path, MapObject map) {
	this->_originalMap = map;

	// Choosing the grid position way points
	this->initializePositionsArray(path);

	// Making locations vector
	initializeWayPointsWrray();

	this->_currentWayPoint = 0;
}

