#ifndef PATH_NODE_H
#define PATH_NODE_H

class PathNode
{
    public:

        int x;
        int y;
        int direction;
        int cost;
        PathNode *parent;

        PathNode(int, int, int, int);
};        

#endif
