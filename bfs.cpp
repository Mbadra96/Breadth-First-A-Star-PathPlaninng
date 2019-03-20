#include "bfs.h"
#include <iostream>
#include<string>
using namespace std;
bool doesexist(int x,int y,int s)
{
    if(x>=s || y>=s){return false;}
    if(x<0 || y<0){return false;}
    return true;
}
BFS::BFS(GridMap *x,int sx,int sy,int gx,int gy)
{
    m=x;
    s_x=sx;
    g_x=gx;
    s_y=sy;
    g_y=gy;
}

void BFS::solve()
{
    que.push(m->n[int(s_x)][int(s_y)]);
    m->n[int(s_x)][int(s_y)].visited=true;
    m->n[int(s_x)][int(s_y)].inpath=true;
    while((que.front().x!=g_x) || (que.front().y !=g_y))
        {
           int cord_x=que.front().x;
           int cord_y=que.front().y;
            //cout<<cord_x<<cord_y<<"  ";
            que.pop();
            int dx[]={1,1,0,-1,-1,-1,0,1};
            int dy[]={0,1,1,1,0,-1,-1,-1};
            for(int i=0;i<8;i++)
                {
                    if(doesexist(cord_x+dx[i],cord_y+dy[i],m->size))
                {
                    if(bool(m->n[cord_x+dx[i]][cord_y+dy[i]].free) && !bool(m->n[cord_x+dx[i]][cord_y+dy[i]].visited))
                        {
                            m->n[cord_x+dx[i]][cord_y+dy[i]].visited=true;
                            m->n[cord_x+dx[i]][cord_y+dy[i]].parent=&(m->n[cord_x][cord_y]);
                            que.push(m->n[cord_x+dx[i]][cord_y+dy[i]]);
                        }
                }
    }
}
cout<< "The path is: ";
int cord_x=que.front().x;
int cord_y=que.front().y;
que.front().inpath=true;
cout<<cord_x<<cord_y<< "   ";
while(cord_x!=0 || cord_y!=0){
        m->n[cord_x][cord_y].parent->inpath=true;
        int tmpx=m->n[cord_x][cord_y].parent->x;
        int tmpy=m->n[cord_x][cord_y].parent->y;
    cout<<tmpx<<tmpy<< "   ";
    cord_x=tmpx;
    cord_y=tmpy;
}
}
