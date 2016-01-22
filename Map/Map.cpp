/*
 * Map.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#include "Map.h"
#include <iostream>

Map::Map(float mapResolution, float robotSize) :
		mMapResolution(mapResolution), mRobotSize(robotSize) {

	mRobotSizeInCells = robotSize / mapResolution;
	mInflationRadius = mRobotSize / 100 * mRobotSizeInCells;
	cout << "inflation radius " << mInflationRadius << endl;
}

void Map::loadMapFromFile(const char* filePath) {
	lodepng::decode(mImage, mapWidth, mapHeight, filePath);

	fineMapWidth = mapWidth / mRobotSizeInCells;
	fineMapHeight = mapHeight / mRobotSizeInCells;
	gridGraph.resize(fineMapHeight);

	for (int k = 0; k < fineMapHeight; k++) {
		gridGraph[k].resize(fineMapWidth);
	}
	cout << "map size: " << mapWidth << "," << mapHeight << endl;

	map.resize(mapHeight);

	for (int i = 0; i < mapHeight; i++) {
		map[i].resize(mapWidth);
	}

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			map[i][j] = checkIfCellIsOccupied(i, j);
		}
	}
}

bool Map::checkIfCellIsOccupied(int i, int j) {
	int c = (i * mapWidth + j) * 4;
	int r = mImage[c];
	int g = mImage[c + 1];
	int b = mImage[c + 2];

	if (r == 0 && g == 0 && b == 0)
		return true;
	return false;
}

void Map::printMap() const {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			cout << (inflateMap[i][j] ? "*" : " ");
		}
		cout << endl;
	}
}

void Map::printGrid(const Grid &grid) const {
	int rows = grid.size();
	int cols = grid[0].size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << (grid[i][j] ? "*" : " ");
		}
		cout << endl;
	}

	rows = mCoarseGrid.size();
	cols = mCoarseGrid[0].size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << (mCoarseGrid[i][j] ? "*" : " ");
		}
		cout << endl;
	}
}

void Map::inflateObstacles() {

	inflateMap.resize(mapHeight);
	for (int i = 0; i < mapHeight; i++) {
		inflateMap[i].resize(mapWidth);
	}

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]) {
				inflate(i, j);
			}
		}
	}
}

void Map::inflate(int i, int j) {

	for (int k = i - mInflationRadius; k < i + mInflationRadius; k++) {
		for (int m = j - mInflationRadius; m < j + mInflationRadius; m++) {
			if (m < 0 || k < 0 || k >= mapHeight || m >= mapWidth) {
				continue;
			} else {
				// Mark this cell as occupied in inflateMap
				inflateMap[k][m] = true;
				// Draw black color in corresponding image
				int c = (k * mapWidth + m) * 4;
				mImage[c] = 0;
				mImage[c + 1] = 0;
				mImage[c + 2] = 0;

			}
		}
	}
}

void Map::buildFineGrid() {

	int fineGridCells = mapHeight / mRobotSizeInCells;
	int fineGridWidth = mapWidth / mRobotSizeInCells;
	mFineGrid.resize(fineGridCells);
	for (int i = 0; i < fineGridCells; i++) {
		mFineGrid[i].resize(fineGridWidth);
	}

	int flag = false;

	for (int i = 0; i < fineGridCells; i++) {
		for (int j = 0; j < fineGridWidth; j++) {
			flag = false;
			for (int m = i * mRobotSizeInCells;
					m < i * mRobotSizeInCells + mRobotSizeInCells; m++) {
				for (int z = j * mRobotSizeInCells;
						z < j * mRobotSizeInCells + mRobotSizeInCells; z++) {
					if (inflateMap[m][z] == true) {
						flag = true;
						break;
					}
				}
			}
			mFineGrid[i][j] = flag;
		}
	}

}

void Map::buildCoarseGrid() {

	int fineGridCells = mapHeight / (mRobotSizeInCells * 2);
	coarseMapHeight = fineGridCells;
	int fineGridWidth = mapWidth / (mRobotSizeInCells * 2);
	coarseMapWidth = fineGridWidth;
	mCoarseGrid.resize(fineGridCells);
	for (int i = 0; i < fineGridCells; i++) {
		mCoarseGrid[i].resize(fineGridWidth);
	}

	int fleg = false;

	for (int i = 0; i < fineGridCells; i++) {
		for (int j = 0; j < fineGridWidth; j++) {
			fleg = false;
			for (int m = i * (mRobotSizeInCells * 2);
					m < i * (mRobotSizeInCells * 2) + (mRobotSizeInCells * 2);
					m++) {
				for (int z = j * (mRobotSizeInCells * 2);
						z < j * (mRobotSizeInCells * 2) + (mRobotSizeInCells * 2);
						z++) {
					if (inflateMap[m][z] == true) {
						fleg = true;
						break;
					}
				}
			}
			mCoarseGrid[i][j] = fleg;
		}
	}
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}
