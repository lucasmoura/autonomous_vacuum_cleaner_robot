#include "dfs.h"
#include <iostream>

const int DepthFirstSearch::INCREASING_SIZE = 50;

DepthFirstSearch::DepthFirstSearch()
{

}

void 
DepthFirstSearch::display_visited_positions()
{
    int row, column;

    for(row =0; row<10; row++)
    {
        for(column = 0; column < 10; column++)
        {
            if(visitedPositions[row][column] >= 0)
                std::cout<<" "<<visitedPositions[row][column]<<"     ";
            else
                 std::cout<<visitedPositions[row][column]<<"     ";
        }    

        std::cout<<std::endl;
    }

}   

int
DepthFirstSearch::init(int x, int y)
{
    int cost = 0;
    Position pos = Position(x, y, Position::FRONT, cost);
    searchSpace.push(pos);
    
    visitedPositions.resize(INCREASING_SIZE);

    for(int i =0; i<INCREASING_SIZE; i++)
        visitedPositions[i].resize(INCREASING_SIZE);

    visitedPositions[x][y] = 1;

    valid_neighbours[0] = Position(1, 0, Position::BACK, cost);
    valid_neighbours[1] = Position(0, -1, Position::LEFT, cost);
    valid_neighbours[2] = Position(0, 1, Position::RIGHT, cost);
    valid_neighbours[3] = Position(-1, 0, Position::FRONT, cost);

    return 0;
}


void
DepthFirstSearch::defineStateOrder(int direction)
{
    switch(direction)
    {
        case Position::FRONT:
            neighbours[0] = valid_neighbours[0];
            neighbours[1] = valid_neighbours[1];
            neighbours[2] = valid_neighbours[2];
            neighbours[3] = valid_neighbours[3];
            break;

         case Position::RIGHT:
            neighbours[0] = valid_neighbours[3];
            neighbours[1] = valid_neighbours[1];
            neighbours[2] = valid_neighbours[0];
            neighbours[3] = valid_neighbours[2];
            break;

         case Position::LEFT:
            neighbours[0] = valid_neighbours[2];
            neighbours[1] = valid_neighbours[0];
            neighbours[2] = valid_neighbours[3];
            neighbours[3] = valid_neighbours[1];
            break;

         case Position::BACK:
            neighbours[0] = valid_neighbours[3];
            neighbours[1] = valid_neighbours[2];
            neighbours[2] = valid_neighbours[1];
            neighbours[3] = valid_neighbours[0];
            break;

         default:
            break;
    }     
           
}

int
DepthFirstSearch::explore(bool isObstacleAhead, int distance)
{
    if(searchSpace.empty())
        return 1;

    Position pos = searchSpace.top();
    searchSpace.pop();
    actualPosition = pos;

    int x = pos.x;
    int y = pos.y;
    int direction = pos.direction;
    int cost = pos.cost;
    visitedPositions[x][y] = 1;

    defineStateOrder(direction);

    if(!isObstacleAhead)
    {
       visitedPositions[x][y] = -1;
       return -1;
    }

    for(int i =0; i<4; i++)
    {
        int tempx = x;
        int tempy = y;

        tempx += neighbours[i].x;
        tempy += neighbours[i].y;
        direction = neighbours[i].direction;
       
        if(tempx<0 || tempy<0)
            continue;

        if(visitedPositions[tempx][tempy] == 1)
            continue;
    
        //std::cout<<tempx<<" "<<tempy<<std::endl;
        Position p = Position(tempx, tempy, direction, cost+distance);
        searchSpace.push(p);
    }    
    
    return 0;

}

bool
DepthFirstSearch::isNeighbour()
{
    Position pos = nextPositionData();
    
    for(int i =0;i<4; i++)
    {
        int tempx = valid_neighbours[i].x + pos.x;
        int tempy = valid_neighbours[i].y + pos.y;

        if(actualPosition.x == tempx && actualPosition.y == tempy)
            return true;
    }

    return false;
}    

void
DepthFirstSearch::createPathToLocation()
{
    
}

int
DepthFirstSearch::pathToLocation()
{
    return 0;
}

int
DepthFirstSearch::nextPosition()
{
    if(!searchSpace.empty())
    {
        if(pathAvailable)
            return pathToLocation();

        if(isNeighbour())
            return searchSpace.top().direction;
        else
        {
            createPathToLocation();
            return pathToLocation();
        }
            
    }
    else
        return -1;
}    

Position
DepthFirstSearch::nextPositionData()
{
    if(!searchSpace.empty())
        return searchSpace.top();
    else
        return Position(0, 0,Position::FRONT, 0);
}    

int
DepthFirstSearch::numSearchSpace()
{
    return searchSpace.size();
}

