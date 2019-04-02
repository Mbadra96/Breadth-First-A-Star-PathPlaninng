#include "maze.h"
#include "point.h"

using namespace std;

int main()
{
    Maze m;
    m.SetPoints();
    m.ASearch();
    //Mat src = imread("../mazes/ll.png",1);
    //Mat gray;
    //Mat bin;
    //cvtColor(src,gray,CV_BGR2GRAY);
    //threshold(gray,bin,200,255,THRESH_BINARY);
    //bitwise_not(bin,bin);
    //imshow("He",bin);
    //waitKey(0);
    //imwrite("output.png",bin);
    return 0;
}
