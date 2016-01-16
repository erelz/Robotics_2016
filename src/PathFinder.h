
#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include <limits>
#include "Commons/MapObject.h"
#include "Commons/Utils.h"
#include "Commons/GridPosition.h"
#include "AStarAlgorithm/AStarSearcher.h"
#include "AStarAlgorithm/MapGraphObject.h"
#include "AStarAlgorithm/Matrix.h"

using namespace std;

#define MAX_U numeric_limits<unsigned int>::max()
#define MAX_I numeric_limits<int>::max()

class PathFinder {
private:
	MapObject _map;
	MapObject _mapWithRoughPath;

	vector<GridPosition> _roughlocationsVector;
	AStarSearcher _searcher;

	Matrix<GridPosition> _parentsMap = Matrix<GridPosition>(GridPosition(MAX_U,MAX_U));
	Matrix<int> _costsMap = Matrix<int>(MAX_I);

public:

	PathFinder(MapObject map);

	vector<GridPosition> getChosenPath(){
		return _roughlocationsVector;
	}

	void findPath(Location source, Location destination);


	void saveFullPathToPng(string fileName){
		Utils::writeMapToPng(fileName, _mapWithRoughPath);
	}

	
	// Printing the map
	 
	void printMapWithPath(){
		Utils::printMap(_mapWithRoughPath);
	}
private :


	// Finding the path

	vector<GridPosition> pathFromParentMap(GridPosition from, GridPosition to){
		vector<GridPosition> path;

		GridPosition current = to;

		path.insert(path.begin(),current);
		cout << LOG_DEBUG << " Pushed X=" << current.getX() << ", Y=" << current.getY() << endl;
		while(current != from){
			current = _parentsMap[current];

			path.insert(path.begin(),current);
			cout << LOG_DEBUG << " Pushed X=" << current.getX() << ", Y=" << current.getY() << endl;
		}

		return path;
	}
};

#endif
