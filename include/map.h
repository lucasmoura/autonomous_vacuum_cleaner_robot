#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

struct Map
{
    int num_rows;
    int num_columns;

    int **map;

};

typedef struct Map Map;

extern Map* create_map(int, int);
extern void display_map(Map*);
extern void init_map(Map*);
extern void free_map(Map*);

#endif
