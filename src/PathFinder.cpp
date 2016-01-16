
#include "PathFinder.h"

PathFinder::PathFinder(MapObject map) {
	this->_map = map;

	this->_costsMap.defineDimensions(map.getWidth(),map.getHeight());
	this->_parentsMap.defineDimensions(map.getWidth(),map.getHeight());
}

void PathFinder::findPath(Location source, Location destination){
	// Finding matching cells in the map
	GridPosition sourceCell = GridPosition(source.getX(),source.getY());
	GridPosition destinationCell = GridPosition(destination.getX(),destination.getY());

	// a graph object
	MapGraphObject graphObject(_map);

	// DEBUG
	this->_mapWithRoughPath = MapObject(_map);
	_mapWithRoughPath.setCellAtPosition(sourceCell,Source);
	_mapWithRoughPath.setCellAtPosition(destinationCell,Target);
	Utils::writeMapToPng("locations.png", _mapWithRoughPath);

	// A star search
	_searcher.aStarSearch(graphObject,sourceCell,destinationCell,_parentsMap, _costsMap);

	// Getting path from the parent map
	_roughlocationsVector= pathFromParentMap(sourceCell,destinationCell);

	// Copying the original map and assigning the path
	this->_mapWithRoughPath = MapObject(_map);
	Utils::insertPathToMap(_mapWithRoughPath,_roughlocationsVector);
	_mapWithRoughPath.setCellAtPosition(sourceCell,Source);
	_mapWithRoughPath.setCellAtPosition(destinationCell,Target);
}
