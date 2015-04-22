#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "robot.h"

int move_robot(Map*, Robot*);
 
int main()
{

    int num_rows = 5;
    int num_columns = 5;
    
    int initial_row = 5;
    int initial_column = 1;

    int result = 1;

    Map* map = create_map(num_rows, num_columns);
    Robot* robot = create_robot(initial_row, initial_column);

    init_map(map);

    display_map(map);
    printf("\n\n");
    print_robot(robot);

    while(result)
    {
        result = move_robot(map, robot);
    }   


    free(robot);
    free_map(map);
    free(map);

    return 0;
}

int move_robot(Map* map, Robot* robot)
{
    int result = move(robot, map);
    printf("\n\n");
    display_map(map);
    print_robot(robot);

    return result;
}
