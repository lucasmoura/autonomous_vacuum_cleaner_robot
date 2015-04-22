#ifndef ROBOT_H
#define ROBOT_H

#include "map.h"

typedef enum {FORWARD = 0, RIGHT, DOWNWARD, LEFT} Direction;

struct Robot
{
    int current_row;
    int current_column;
    int total_directions;
    Direction  movement_direction;
};

typedef struct Robot Robot;

extern Robot* create_robot();
extern void print_robot(Robot*);
extern int move(Robot*, Map*);

#endif
