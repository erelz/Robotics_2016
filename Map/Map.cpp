/*
 * Map.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#include "Map.h"
#include <iostream>

#define OCCUPIED_CHAR '*'
#define NON_OCCUPIED_CHAR ' '


Map::Map(float mapResolution, float robotSize) {

	mRobotSize = robotSize;
	mMapResolution = mapResolution;
	mRobotSizeInCells = robotSize / mapResolution;
	mInflationRadius = mRobotSize / 100 * mRobotSizeInCells;
	cout << "inflation radius " << mInflationRadius << endl;
}

void Map::loadMapFromFile(const char* filePath) {
	lodepng::decode(mImage, mMapWidth, mMapHeight, filePath);

	mFineMapWidth = mMapWidth / mRobotSizeInCells;
	mFineMapHeight = mMapHeight / mRobotSizeInCells;
	gridGraph.resize(mFineMapHeight);

	for (int i = 0; i < mFineMapHeight; i++) {
		gridGraph[i].resize(mFineMapWidth);
	}

	mMap.resize(mMapHeight);

	for (int i = 0; i < mMapHeight; i++) {
		mMap[i].resize(mMapWidth);
	}

	for (int i = 0; i < mMapHeight; i++) {
		for (int j = 0; j < mMapWidth; j++) {
			mMap[i][j] = checkIfCellIsOccupied(i, j);
		}
	}
}

bool Map::checkIfCellIsOccupied(int i, int j) {
	int c = (i * mMapWidth + j) * 4;
	int r = mImage[c];
	int g = mImage[c + 1];
	int b = mImage[c + 2];

	if (r == 0 && g == 0 && b == 0)
		return true;
	return false;
}

void Map::printMap() const {
	for (int i = 0; i < mMapHeight; i++) {
		for (int j = 0; j < mMapWidth; j++) {
			cout << (mInflateMap[i][j] ? OCCUPIED_CHAR : NON_OCCUPIED_CHAR);
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
}

void Map::inflateObstacles() {

	mInflateMap.resize(mMapHeight);
	for (int i = 0; i < mMapHeight; i++) {
		mInflateMap[i].resize(mMapWidth);
	}

	for (int i = 0; i < mMapHeight; i++) {
		for (int j = 0; j < mMapWidth; j++) {
			if (mMap[i][j]) {
				inflate(i, j);
			}
		}
	}
}

void Map::inflate(int i, int j) {

	for (int k = i - mInflationRadius; k < i + mInflationRadius; k++) {
		for (int m = j - mInflationRadius; m < j + mInflationRadius; m++) {
			if (m < 0 || k < 0 || k >= mMapHeight || m >= mMapWidth) {
				continue;
			} else {
				// Mark this cell as occupied in mInflateMap
				mInflateMap[k][m] = true;
				// Draw black color in corresponding image
				int c = (k * mMapWidth + m) * 4;
				mImage[c] = 0;
				mImage[c + 1] = 0;
				mImage[c + 2] = 0;

			}
		}
	}
}

void Map::buildFineGrid() {

	int fineGridCells = mMapHeight / mRobotSizeInCells;
	int fineGridWidth = mMapWidth / mRobotSizeInCells;
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
					if (mInflateMap[m][z] == true) {
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

	mCoarseMapHeight = mMapHeight / (mRobotSizeInCells * 2);
	mCoarseMapWidth = mMapWidth / (mRobotSizeInCells * 2);
	;
	mCoarseGrid.resize(mCoarseMapHeight);
	for (int i = 0; i < mCoarseMapHeight; i++) {
		mCoarseGrid[i].resize(mCoarseMapWidth);
	}

	int fleg = false;

	for (int i = 0; i < mCoarseMapHeight; i++) {
		for (int j = 0; j < mCoarseMapWidth; j++) {
			fleg = false;
			for (int m = i * (mRobotSizeInCells * 2);
					m < i * (mRobotSizeInCells * 2) + (mRobotSizeInCells * 2);
					m++) {
				for (int z = j * (mRobotSizeInCells * 2);
						z
								< j * (mRobotSizeInCells * 2)
										+ (mRobotSizeInCells * 2); z++) {
					if (mInflateMap[m][z] == true) {
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
