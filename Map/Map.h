/*
 * Map.h
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_
#include "../Objects/Node.h"
#include "lodepng.h"
#include <vector>
using namespace std;
typedef vector<vector<bool> > Grid;
class Map {
private:

	vector<unsigned char> mImage;
	vector<unsigned char> mGridImage;
	vector<vector<Node *> > gridGraph;
	vector<vector<Node *> > Path;

	Grid map;
	Grid inflateMap;

	//original Map size
	unsigned int mapWidth;
	unsigned int mapHeight;

	//grid Map size
	unsigned int fineMapWidth;
	unsigned int fineMapHeight;

	//coarse Map size
	unsigned int coarseMapWidth;
	unsigned int coarseMapHeight;

	//
	float mMapResolution;
	float mRobotSize;

	//size of the robot in pixels
	int mRobotSizeInCells;

	float mInflationRadius;

	Grid mFineGrid;
	Grid mCoarseGrid;

	bool checkIfCellIsOccupied(int i, int j);
	void inflate(int i, int j);

public:
	/**
	 * constructor
	 */
	Map(float mapResolution, float robotSize);
	/**
	 * load map from file
	 */
	void loadMapFromFile(const char* filePath);
	void printMap() const;
	void printGrid(const Grid &grid) const;
	void buildFineGrid();
	void buildCoarseGrid();
	void inflateObstacles();

	const Grid& getCoarseGrid() const {
		return mCoarseGrid;
	}

	const Grid& getFineGrid() const {
		return mFineGrid;
	}

	virtual ~Map();

};

#endif /* MAP_H_ */
