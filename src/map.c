#include "map.h"


void create_map_with_sentinel(Map* map)
{
    int i;
    map->map = (int**) malloc((map->num_rows+2) * sizeof(int*));

    for(i =0; i< map->num_rows+2; i++)
        map->map[i] = (int*) malloc((map->num_columns+2)*sizeof(int));
    
}

Map* create_map(int num_rows, int num_columns)
{
    Map* room_map = (Map*) malloc (sizeof(Map));

    room_map->num_rows = num_rows;
    room_map->num_columns = num_columns;

    create_map_with_sentinel(room_map);

    return room_map;
}

void init_sentinel(Map* map)
{
    int row, column;

    for(row = 0; row<map->num_rows+2; row+=map->num_rows+1)
        for(column = 0; column<map->num_columns+2; column++)
            map->map[row][column] = -1;

    for(column = 0; column <map->num_columns+2; column += map->num_columns+1)
        for(row = 0; row< map->num_rows+2; row++)
            map->map[row][column] = -1;

}

void init_map(Map* map)
{
    int row, column;
    init_sentinel(map);

    for(row = 1; row <map->num_rows+1; row++)
        for(column = 1; column < map->num_columns+1; column++)
            map->map[row][column] = 0;
}

void display_map(Map* map)
{
    int row, column;

    for(row =0; row<map->num_rows+2; row++)
    {
        for(column = 0; column < map->num_columns+2; column++)
        {
            if(map->map[row][column] >= 0)
                printf(" %d     ", map->map[row][column]);
            else
                 printf("%d     ", map->map[row][column]);
        }    

        printf("\n");
    }

}    

void free_map(Map* map)
{
    int i;

    for(i = 0; i < map->num_rows; i++)
            free(map->map[i]);

    free(map->map);
}

