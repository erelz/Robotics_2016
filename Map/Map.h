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
	vector<vector<Node *> > gridGraph;
	vector<vector<Node *> > Path;

	Grid mMap;
	Grid mInflateMap;

	unsigned int mMapWidth;
	unsigned int mMapHeight;

	float mMapResolution;
	float mRobotSize;
	int mRobotSizeInCells;
	float mInflationRadius;

	unsigned int mFineMapWidth;
	unsigned int mFineMapHeight;
	Grid mFineGrid;

	unsigned int mCoarseMapWidth;
	unsigned int mCoarseMapHeight;
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


	const Grid& getMap() const {
		return mMap;
	}

	const Grid& getCoarseGrid() const {
		return mCoarseGrid;
	}

	const Grid& getFineGrid() const {
		return mFineGrid;
	}

	virtual ~Map();

	unsigned int getMapHeight() const {
		return mMapHeight;
	}

	unsigned int getMapWidth() const {
		return mMapWidth;
	}
};

#endif /* MAP_H_ */
