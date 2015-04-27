#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "robot.h"
#include "arduino-serial-lib.h"
#include <string.h>

int move_robot(Map*, Robot*);
 
int main()
{

    char* serialport = "/dev/ttyACM0";
    int baud = 9600;
    int fd;
    int buf_max = 10;
    int count = 10;
    int timeout = 10000;
    char *buff = (char*) malloc(sizeof(char)*buf_max);
    char until = '.';

    fd = serialport_init(serialport, baud); 

    printf("FD: %d\n", fd);


    while(count)
    {
        serialport_read_until(fd, buff, until, buf_max, timeout);   
        printf("Buffer: %s\n", buff);

        memset(buff, '\0', buf_max );
        usleep(10000);
        count--;
    }

    serialport_close(fd);

    /*int num_rows = 5;
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
    free(map);*/

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
