#ifndef DEPTH_FIRST_SEARCH
#define DEPTH_FIRST_SEARCH

#include <iostream>
#include "position.h"
#include <stack>
#include <vector>


class DepthFirstSearch
{

    public:

        static const int INCREASING_SIZE;

        DepthFirstSearch();
        int init(int, int);
        void display_visited_positions();
        int explore(bool, int);

        int numSearchSpace();

        int nextPosition();
        Position nextPositionData();

    private:

        void defineStateOrder(int);
        void createPathToLocation();
        bool isNeighbour();
        int pathToLocation();

        std::stack<Position> searchSpace;
        std::vector<std::vector<int> > visitedPositions;
        Position neighbours[4];
        Position valid_neighbours[4];
        Position actualPosition;
        bool pathAvailable;

};


#endif
