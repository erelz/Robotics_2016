
#ifndef MAPOBJECT_H_
#define MAPOBJECT_H_

using namespace std;

#include <iostream>
#include <vector>
#include <cmath>

#include "../Globals.h"
#include "GridPosition.h"
#include "Location.h"

/**
 * Represents a single map as a matrix of GridCells
 * Adding utilities to convert the actual locations to cells
 */
class MapObject {
private :
	vector<vector<GridCell> > _cellMatrix;
	unsigned _width;
	unsigned _height;
	float _cell2Cm;
public:

	MapObject();
	MapObject(vector<vector<GridCell> >, unsigned width, unsigned height, float cell2cm);
	~MapObject();

	/**
	 * Redefining the size of the matrix
	 */
	void defineDimensions(unsigned width, unsigned height);

	/**
	 *	Filling the matrix with clear cells
	 */
	void clearMatrix();

	bool isPositionValid(unsigned x, unsigned y){
		return ((x > 0) && (x < _width)) &&
				((y > 0) && (y < _height));
	}

	bool isPositionValid(GridPosition pos){
		return (isPositionValid(pos.getX(), pos.getY()));
	}

	unsigned getHeight() const {
		return _height;
	}

	unsigned getWidth() const {
		return _width;
	}

	float getCell2Cm() const {
		return _cell2Cm;
	}

	void setCell2Cm(float cell2Cm) {
		_cell2Cm = cell2Cm;
	}

	/**
	 * Getting the cell at the given position from the matrix.
	 *
	 * (If an invalid position was given , no value is returned)
	 */
	GridCell getCellAtPosition(unsigned x,  unsigned y){

		if (ensureCellPositionValid(x,y)){
			return _cellMatrix[y][x];
		} else {
			cout << LOG_ERROR << "Invalid position given to 'getCellAtPosition' , no value returned." << endl;
		}
	}

	/**
	* Getting the cell at the given position from the matrix.
	*
	* (If an invalid position was given , no value is returned)
	*/
	GridCell getCellAtPosition(GridPosition pos){
		return getCellAtPosition(pos.getX(), pos.getY());
	}

	void setCellAtPosition(unsigned x,  unsigned y, GridCell value){

		if (ensureCellPositionValid(x,y)){
			_cellMatrix[y][x] = value;
		} else {
			cout << LOG_ERROR << "Invalid position given to 'setCellAtPosition' , no value returned." << endl;
		}
	}

	void setCellAtPosition(GridPosition pos,GridCell value){
		setCellAtPosition(pos.getX(),pos.getY(),value);
	}

	/**
	 * Return the cell that contains the actual location
	 */
	GridCell getCellAtRealLocation(float x,  float y){
		GridPosition position = positionFromLocation(x,y);
		return getCellAtPosition(position.getX(),position.getY());
	}

	/**
	 * Getting the position from the location coordinates
	 */
	GridPosition positionFromLocation(float x, float y){
		unsigned xPos = positionFromActualLocation(x);
		unsigned yPos = positionFromActualLocation(y);
		return GridPosition(xPos,yPos);
	}

	/**
	 * Getting the position from the given location object
	 */
	GridPosition positionFromLocation(Location location){
		return positionFromLocation(location.getX(),location.getY());
	}

	/**
	 * Return an approximate location of the grid position
	 */
	Location locationFromPosition(GridPosition position){
         Location loc(locationFromActualPosition(position.getX())
        		 , locationFromActualPosition(position.getY()));
         return loc;
	}

private :
	//************
	//	Calculation methods
	//************

	/**
	 * Gets an "actual location" representer
	 * Each whole number here belongs to the previous cell before him
	 */
	unsigned positionFromActualLocation(float location){
		unsigned cell;
		if (location == 0){

			cell = 0;
		} else {
			// Round up the division and subtract 1
			cell = ceil(location / this->_cell2Cm) - 1;
		}

		return cell;
	}


	//	Returns an actual world location that is in the middle of the grid location

	float locationFromActualPosition(unsigned position){
		float aproximateLocation = (position * _cell2Cm) + (((float)_cell2Cm) / 2);
		return aproximateLocation;
	}

	//*************
	//	Validation methods
	//*************
	/**
	 * Ensures that the position is valid for the given matrix
	 */
	bool ensureCellPositionValid(unsigned x,  unsigned y){
		if ((x >= this->getWidth()) || (y >= this->getHeight())){
			this->throwOutOfBoundsException(x,y);
			return false;
		} else {
			return true;
		}
	}

	/**
	 * Printing an error and throwing an exception
	 */
	void throwOutOfBoundsException(unsigned x,  unsigned y){
		cout << "ERROR : " << "Map object was given out of boundaries values. "
				<< "The boundaries are X=" << x << " and Y=" << y
				<< " But given location was X=" << _width << " and Y=" << _height << endl;
		throw ("Out of map matrix bounds !");
	}


};

#endif
