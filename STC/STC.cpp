/*
 * STC.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: colman
 */

#include "STC.h"

STC::STC(Map &map, Location initialRobotPos) :
		mMap(map), mInitialRobotPos(initialRobotPos) {
	// create node graph
	buildGraph();
	//printGraph();
	DFS(initialRobotPos.getX(), (int)initialRobotPos.getY());
	//printDFS();
}

void STC::buildGraph() {
	Grid coarseGrid = mMap.getCoarseGrid();
	mGraphHeight = coarseGrid.size();
	mGraphWidth = coarseGrid[0].size();

	mGraph.resize(mGraphHeight);
	for (int i = 0; i < mGraphHeight; i++)
		mGraph[i].resize(mGraphWidth);

	// fill the not occupied with node
	for (int i = 0; i < mGraphHeight; i++) {
		for (int j = 0; j < mGraphWidth; j++) {

			if (!coarseGrid[i][j]) {
				Node* node = new Node(i, j);
				mGraph[i][j] = node;
			} else {
				mGraph[i][j] = NULL;
			}
		}
	}
}

Node* STC::DFS(int x, int y) {

	if (x < 0 || x > mGraphWidth || y < 0 || y > mGraphHeight) {
		return NULL;
	}

	if (mGraph[x][y] == NULL) {
		return NULL;
	}

	Node* node = mGraph[x][y];
	if (node->visited) {
		return NULL;
	}

	node->visited = true;

	// right
	Node* rightNode = DFS(node->row + 1, node->col);
	if (rightNode != NULL) {
		node->neighborsInTree.push_back(rightNode);
	}

	// left
	Node* leftNode = DFS(node->row - 1, node->col);
	if (leftNode != NULL) {
		node->neighborsInTree.push_back(leftNode);
	}

	// down
	Node* downNode = DFS(node->row, node->col + 1);
	if (downNode != NULL) {
		node->neighborsInTree.push_back(downNode);
	}

	// up
	Node* upNode = DFS(node->row, node->col - 1);
	if (upNode != NULL) {
		node->neighborsInTree.push_back(upNode);
	}

	return node;
}




void STC::printDFS() {

	for (int i = 0; i < mGraphWidth; i++) {
		for (int j = 0; j < mGraphHeight; j++) {
			if (mGraph[i][j] != NULL) {
				for (int k = 0; k < 4; k++) {
					if (mGraph[i][j]->neighborsInTree[k] != NULL) {

						cout << "(" << mGraph[i][j]->row << ","
								<< mGraph[i][j]->col << ")";
						cout << " -> ";
						cout << "("
								<< mGraph[i][j]->neighborsInTree[k]->row
								<< ","
								<< mGraph[i][j]->neighborsInTree[k]->col
								<< ")" << endl;
					}
				}

			}
		}
	}
}

STC::~STC() {
	// TODO Auto-generated destructor stub
}

void STC::DFS(Node *node) {
	// 1. Go over all the neighbors of the node in the graph
	// 2. For each neighbor, if not visited:
	// 	  2a. Add tree edge between node and neighbor
	//    2b. Recursively call DFS with neighbor
}
