#ifndef POSITION_H
#define POSITION_H

class Position
{
    public:

        static enum Directions
        {
            BACK = 0,
            LEFT,
            RIGHT,
            FRONT
        }possible_directions;

        Position(int, int, int, int);
        Position(){};

        int x;
        int y;
        int direction;
        int cost;

};


#endif
