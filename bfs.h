#ifndef BFS_H
#define BFS_H
#include "grid_map.h"
#include<queue>
#include<vector>
using namespace std;

class BFS
{

    public:
        GridMap *m;int s_x;int s_y;int g_x;int g_y;
        BFS(GridMap*,int,int,int,int);
        queue <Node> que;
        void solve();
};

#endif // BFS_H
