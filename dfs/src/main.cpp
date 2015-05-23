#include "dfs.h"
#include <iostream>

using namespace std;

void display_map(int **map, int size)
{
    int row, column;

    for(row =0; row<size; row++)
    {
        for(column = 0; column < size; column++)
        {
            if(map[row][column] >= 0)
                cout<<" "<<map[row][column]<<"     ";
            else
                 cout<<map[row][column]<<"     ";
        }    

        cout<<endl;
    }

}    

int main()
{
    int MAP_SIZE = 10;

    int **map = new int*[MAP_SIZE];

    for(int i =0; i<MAP_SIZE;i++)
        map[i] = new int[MAP_SIZE];

    for(int i =0; i<MAP_SIZE; i++)
        for(int j =0; j<MAP_SIZE; j++)
            map[i][j] = 0;

    
    for(int j = 0; j<MAP_SIZE; j+=MAP_SIZE-1)
        for(int i = 0; i<MAP_SIZE; i++)
            map[i][j] = -1;

        for(int i = 0; i <MAP_SIZE; i += MAP_SIZE - 1)
            for(int j = 0; j<MAP_SIZE; j++)
                map[i][j] = -1;


    map[7][2] = -1;
    map[7][3] = -1;

//    display_map(map, MAP_SIZE);
    int x = 8;
    int y = 1;
    int cost = 1;

    DepthFirstSearch* dfs = new DepthFirstSearch();

    dfs->init(x, y);
    Position pos = dfs->nextPositionData();
    map[pos.x][pos.y] = (map[pos.x][pos.y] == -1?-1:1);
    cout<<"X: "<<pos.x<<"\n"<<"Y: "<<pos.y<<"\n\n";
    bool obstacle = (map[pos.x][pos.y] == -1?false:true);
    int stop = dfs->explore(obstacle, cost); 

    int b;
    while( stop != 1)
    {
        Position pos = dfs->nextPositionData();
        map[pos.x][pos.y] = (map[pos.x][pos.y] == -1?-1:1);
        cout<<"X: "<<pos.x<<"\n"<<"Y: "<<pos.y<<"\n\n";
        bool obstacle = (map[pos.x][pos.y] == -1?false:true);
    
        stop = dfs->explore(obstacle, cost);
        display_map(map, MAP_SIZE);

        cout<<"\n"<<endl;
        dfs->display_visited_positions();

        cout<<"\nNext direction: "<<dfs->nextPosition()<<endl;
        cout<<"Stop: "<<stop<<endl;
        cout<<"Num search spaces: "<<dfs->numSearchSpace()<<endl;
        cout<<"\n"<<endl;

        cin>>b;

    }    


    delete dfs;

    for(int i =0; i<MAP_SIZE; i++)
        delete map[i];

    delete map;

    return 0;
}    

