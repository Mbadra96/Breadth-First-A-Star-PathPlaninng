#include <iostream>
#include "grid_map.h"
#include "bfs.h"
using namespace std;

int main()
{
    GridMap m(10);
    m.printmap();
    BFS b(&m,0,0,0,9);
    b.solve();
    m.printmap();

}
