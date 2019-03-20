#include "grid_map.h"
#include<vector>
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
Node::Node(){
    x=0;
    y=0;
    free=true;
    visited=false;
    inpath=false;
    parent=nullptr;

}


Node::Node(int ix, int iy ,bool ifree){
    x=ix;
    y=iy;
    free=ifree;
    visited=false;
    inpath=false;
    parent=nullptr;

}

void Node::printnode()
{
    if(!free) cout<<'#'<<"   ";
    else if(inpath) cout<<"-"<<"   ";
    else cout<<x<<y<<"  ";
}

void Node::getnode()
{
    cout <<" Node Nr.:"<<x<<y<<endl;
    cout<<" This Node is Free:"<<free<<endl;
    cout<<" This Node is in path:"<<inpath<<endl;
    cout<<" This Node parent is:"<< parent->x << parent->y <<endl;
}

GridMap::GridMap(int s)
{
  size=s;
  string line;
  std::fstream myfile("map.txt", std::ios_base::in);
  if (myfile.is_open())
  {
    int a;
    while(myfile >> a){
    obstacles.push_back(a);
    }
        myfile.close();
    }
  else cout << "Unable to open file";

      for (int i=0;i<size;i++){
            n.push_back(vector<Node>());
        for (int j=0;j<size;j++){
                bool f=false;
                for(unsigned int k=0;k<obstacles.size();k++){
                    if((i==int(obstacles[k]/10))&&(j==(obstacles[k]%10))){f=true;}
                }
                Node x(i,j,!f);
            n[i].push_back(x);
        }
      }
}
void GridMap::printmap(){
    cout<<endl;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            n[i][j].printnode();
        }
        cout<<endl;
    }
}
