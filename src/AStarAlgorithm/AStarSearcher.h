
#ifndef ASTARSEARCHER_H_
#define ASTARSEARCHER_H_

#include <tr1/unordered_map>
#include <vector>
#include <queue>

#include "../Commons/GridPosition.h"
#include "MapGraphObject.h"
#include "HelperTemplates.h"
#include "Matrix.h"

using namespace std;
using namespace tr1;


class AStarSearcher {
public:
	AStarSearcher();

	//***********
	//	Search methods
	//***********
	void aStarSearch(MapGraphObject mapGraph,
			GridPosition start, GridPosition target,
			Matrix<GridPosition>& parentsMap,
			Matrix<int>& costMap);
private:
	//***********
	//	Algotihm's logic methods
	//***********
	inline int heuristic(GridPosition from, GridPosition to) {
		int fromX = from.getX();
		int fromY = from.getY();
		int toX = to.getX();
		int toY = to.getY();
	  return abs(fromX - toX) + abs(fromY- toY);
	}
};

#endif /* ASTARSEARCHER_H_ */
