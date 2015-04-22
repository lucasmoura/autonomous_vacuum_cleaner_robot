#include "robot.h"

Robot* create_robot(int current_row, int current_column)
{
    Robot* robot = (Robot*) malloc(sizeof(Robot));
    
    robot->current_row = current_row;
    robot->current_column = current_column;
    robot->total_directions = 4;

    robot->movement_direction = FORWARD;

    return robot;
}

void print_robot(Robot* robot)
{
    printf("\n..............\n");
    printf("Current position: %d %d\n", robot->current_row, robot->current_column);
    printf("Direction: %d\n", robot->movement_direction);
    printf("................\n");
}    

int check_for_end_of_trail(Robot* robot, Map* map)
{
    int above = get_map_value(map, robot->current_row+1, robot->current_column);
    int below = get_map_value(map, robot->current_row-1, robot->current_column);
    int right = get_map_value(map, robot->current_row, robot->current_column+1);
    int left = get_map_value(map, robot->current_row, robot->current_column-1);

    if(above && below && right && left)
        return 0;
    else
        return 1;
}    


void get_next_position(Robot* robot, int* position)
{
    position[0] = 0;
    position[1] = 0;

    switch(robot->movement_direction)
    {
        case FORWARD:
            position[0] = robot->current_row-1;
            position[1] = robot->current_column;
            break;

        case RIGHT:
            position[0] = robot->current_row;
            position[1] = robot->current_column + 1;
            break;

        case DOWNWARD:
            position[0] = robot->current_row+1;
            position[1] = robot->current_column;
            break;

        case LEFT:
            position[0] = robot->current_row;
            position[1] = robot->current_column -1;
            break;
    }

}

int is_a_valid_position(int* position, Map* map)
{
    int map_value = get_map_value(map, position[0], position[1]);

    return (map_value != 0)?1:0;
}

Direction get_next_direction(Robot* robot, int valid_position)
{
    Direction direction = robot->movement_direction;
    int total_direction = robot->total_directions;

    int new_direction = valid_position *((direction+1)%total_direction) + (1-valid_position)*direction;

    return new_direction;

}

int move(Robot* robot, Map* map)
{
    int next_position[2];
    int valid_position;

    mark_as_visited(map, robot->current_row, robot->current_column);

    get_next_position(robot, next_position);

    valid_position = is_a_valid_position(next_position, map);

    robot->current_row = valid_position*robot->current_row + (1 - valid_position)*next_position[0];
    robot->current_column = valid_position*robot->current_column + (1 - valid_position)*next_position[1];

    robot->movement_direction = get_next_direction(robot, valid_position);

    return check_for_end_of_trail(robot, map);
}
    
