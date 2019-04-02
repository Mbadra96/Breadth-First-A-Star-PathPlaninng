#pragma once
#include <iostream>
class point{
  public:
    int x;
    int y;
    int parentx;
    int parenty;
    point(int,int,int,int);
    point();
    void printPoint();
    bool equalPoints(point);
    point addPoints(point);
    void addparent(point);

};
