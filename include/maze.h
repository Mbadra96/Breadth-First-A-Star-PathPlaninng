#pragma once
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include"point.h"
using namespace cv;
class Maze{
  public:
    Mat maze;
    point start;
    point end;
    Maze();
    void showMaze();
    void SetPoints();
    void BFS();
    void ASearch();

};
