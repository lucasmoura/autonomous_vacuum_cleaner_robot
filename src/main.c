#include <stdio.h>
#include <stdlib.h>
#include "map.h"


int main()
{

    int num_rows = 5;
    int num_columns = 5;

    Map* map = create_map(num_rows, num_columns);
    init_map(map);
    display_map(map);
    free_map(map);

    free(map);

    return 0;
}

