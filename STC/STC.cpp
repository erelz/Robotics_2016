/*
 * STC.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: colman
 */


#include "STC.h"

STC::STC(Map &map, Location initialRobotPos) :
		mMap(map), mInitialRobotPos(initialRobotPos) {
	cout << "run STC" << endl;
	// create node graph
	buildGraph();
	printGraph();

	cout << "run DFS" << endl;
	mDFSStartNode = DFS(initialRobotPos.getX() / 30,
			initialRobotPos.getY() / 30);

	buildSpanningTree(mDFSStartNode);
}

void STC::buildGraph() {
	Grid coarseGrid = mMap.getCoarseGrid();
	mGraphWidth = coarseGrid.size();
	mGraphHeight = coarseGrid[0].size();

	mGraph.resize(mGraphWidth);
	for (int i = 0; i < mGraphWidth; i++)
		mGraph[i].resize(mGraphHeight);

	// fill the not occupied with node
	for (int i = 0; i < mGraphWidth; i++) {
		for (int j = 0; j < mGraphHeight; j++) {

			if (!coarseGrid[i][j]) {
				cout << "(" << i << ", " << j << ")" << endl;
				Node* node = new Node(i, j);
				mGraph[i][j] = node;
			} else {
				mGraph[i][j] = NULL;
			}
		}
	}
}

void STC::printGraph() {
	int gridRows = mGraph.size();
	int gridCols = mGraph[0].size();

	for (int i = 0; i < gridRows; i++) {
		for (int j = 0; j < gridCols; j++) {
			if (mGraph[i][j]) {
				cout << setw(2) << i << ":" << setw(2) << j << " ";
			} else {
				cout << "  :   ";
			}
		}
		cout << endl;
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

	cout << "visited: (" << node->row << ", " << node->col << ")" << endl;
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

void STC::buildSpanningTree(Node* node) {

	cout << "(" << node->row << ", " << node->col << ")" << endl;
	mPath.push_back(new Location((float) node->row, (float) node->col));
	if (node->neighborsInTree.size() != 0) {
		for (int i = 0; i < node->neighborsInTree.size(); i++) {
			buildSpanningTree(node->neighborsInTree[i]);
		}
	}
}

void STC::saveSpanningTreeToFile(const char* filePath) {
	Grid mapGrid = mMap.getMap();
	vector<unsigned char> image;

	int mapHeight = mapGrid.size();
	int mapWidth = mapGrid[0].size();

	image.resize(mapHeight * mapWidth * 4);

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			int c = (i * mapWidth + j) * 4;
			if (mapGrid[i][j]) {
				image[c] = 0;
				image[c + 1] = 0;
				image[c + 2] = 0;
				image[c + 3] = 255;
			} else {
				image[c] = 255;
				image[c + 1] = 255;
				image[c + 2] = 255;
				image[c + 3] = 255;
			}

		}
	}

	drawSpanningTree(image, mDFSStartNode ,mapWidth);
	lodepng::encode(filePath, image, mapWidth, mapHeight);
}

void STC::drawSpanningTree(vector<unsigned char> &image, Node* node, int mapWidth) {

	for (int i = 0; i < node->neighborsInTree.size(); i++) {
		drawLine(image, node, node->neighborsInTree[i], mapWidth);
		drawSpanningTree(image, node->neighborsInTree[i], mapWidth);
	}
}s

void STC::drawLine(vector<unsigned char> &image, Node* nodeA , Node* nodeB, int mapWidth) {

	int nodeAx = nodeA->row * 25;
	int nodeAY = nodeA->col * 25;
	int nodeBx = nodeB->row * 25;
	int nodeBy = nodeB->col * 25;

	if (nodeAx == nodeBx) {
		// horizontal line
		int start =
				(nodeAY < nodeBy) ?
						nodeAY : nodeBy;
		int length = abs(nodeAY - nodeBy);
		for (int i = start; i <= start + length; i++) {
			int c = (nodeAx* mapWidth + i) * 4;
			image[c] = 0;
			image[c + 1] = 0;
			image[c + 2] = 255;
			image[c + 3] = 255;
		}
	} else {
		// vertical line
		int start =
				(nodeAx < nodeBx) ?
						nodeAx : nodeBx;
		int length = abs(nodeAx - nodeBx);
		for (int i = start; i <= start + length; i++) {
			int c = (i * mapWidth + nodeAY) * 4;
			image[c] = 0;
			image[c + 1] = 0;
			image[c + 2] = 255;
			image[c + 3] = 255;
		}
	}
}

STC::~STC() {
	// TODO Auto-generated destructor stub
}
