#ifndef GRIDMAP_H
#define GRIDMAP_H
#include<vector>
using namespace std;
class Node
{
    public:
        int x;
        int y;
        bool visited;
        bool free;
        bool inpath;
        Node *parent;
        Node();
        Node(int,int,bool);
    void printnode();
    void getnode();

};

class GridMap
{
    public:
        int size;
        vector<int> obstacles;
        vector<vector<Node>> n;
        GridMap(int);
        void printmap();

};

#endif // GRIDMAP_H
