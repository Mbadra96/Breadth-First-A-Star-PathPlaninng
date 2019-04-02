#include "maze.h"
#include <vector>
#include <queue>
#include <unistd.h>
using namespace std;
int r=2;
void printqueue(queue<point> q){

  while (!q.empty())
 {
   std::cout << q.front().x << ":"<<q.front().y<<"--";
   q.pop();
 }
 std::cout << std::endl;
}
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
int flag=0;
bool validpoint(int x,int y,int width,int height){
  if(x<0 || x > width){
    return false;
  }
  else if(y<0 || y > height){
    return false;
  }
  return true;

}
bool freepoint(int x,int y,Mat maze){
  Vec3b color = maze.at<Vec3b>(y,x);
  int blue = color.val[0];
  int green = color.val[1];
  int red = color.val[2];
  if(blue==255 && green==255 && red==255){
    return true;
  }
  else if(blue==0 && green==255 && red==0){
    return true;
  }
  else if(blue==255 && green==0 && red==0){
    return true;
  }
  return false;
}
void visitpoint(int x,int y,Mat *maze){
  Vec3b color;
  color.val[0]=239;
  color.val[1]=226;
  color.val[2]=159;
  maze->at<Vec3b>(y,x)=color;
}
void inpathpoint(int x,int y,Mat *maze){
  Vec3b color;
  color.val[0]=20;
  color.val[1]=20;
  color.val[2]=20;
  maze->at<Vec3b>(y,x)=color;
}
Maze::Maze(){
  maze = imread( "../mazes/maze.png", 1 );
  if ( !maze.data )
  {
      throw "No image data \n";

  }

}
void Maze::showMaze(){

  namedWindow("Maze", WINDOW_AUTOSIZE );
  imshow("Maze", maze);
  waitKey(0);

}
void Maze::SetPoints(){
  namedWindow("My Window", 1);

//set the callback function for any mouse event
  setMouseCallback("My Window",CallBackFunc, this);

  imshow("My Window", maze);
  waitKey(0);
}
void CallBackFunc(int event, int px, int py, int flags, void* param)
{
    Maze* mat=(Maze*)param;
     if  ( event == EVENT_LBUTTONDOWN )
     {
        if (flag==0){
          mat->start.x=px;
          mat->start.y=py;
          rectangle(mat->maze, Point(px-r,py-r), Point(px+r,py+r), cv::Scalar(0, 255, 0),-1,8,0);
          imshow("My Window", mat->maze);
          std::cout<<"start point: "<<mat->start.x<<" "<<mat->start.y<<std::endl;

          flag++;
        }
        else if(flag==1){
          mat->end.x=px;
          mat->end.y=py;
          std::cout<<"end point: "<<mat->end.x<<" "<<mat->end.y<<std::endl;
            rectangle(mat->maze, Point(px-r,py-r), Point(px+r,py+r), cv::Scalar(255, 0, 0),-1,8,0);
            imshow("My Window", mat->maze);
          flag++;
        }
     }

}
void Maze::BFS(){
  cout<<"Starting BFS"<<endl;
  int dx[]={0,1,1,1,0,-1,-1,-1};
  int dy[]={1,1,0,-1,-1,-1,0,1};
  queue<point> que;
  point p[maze.size().width][maze.size().height];
  for (int i=0;i<maze.size().width;i++){
    for(int j=0;j<maze.size().height;j++){
      p[i][j].x=i;
      p[i][j].y=j;
    }
  }
  que.push(p[start.x][start.y]);
  int width=maze.size().width;
  int height=maze.size().height;
   while(que.front().x!=end.x || que.front().y!=end.y)
    {
     int cord_x=que.front().x;
     int cord_y=que.front().y;
     que.pop();
     for (int i=0;i<8;i++){
         if(validpoint(cord_x+dx[i],cord_y+dy[i],width,height)){
           if(freepoint(cord_x+dx[i],cord_y+dy[i],maze)){
             p[cord_x+dx[i]][cord_y+dy[i]].parentx=cord_x;
             p[cord_x+dx[i]][cord_y+dy[i]].parenty=cord_y;
             que.push(p[cord_x+dx[i]][cord_y+dy[i]]);
             visitpoint(cord_x+dx[i],cord_y+dy[i],&maze);
             imshow("My Window",maze);
             waitKey(1);

           }
         }
     }

   }


    point po=p[end.x][end.y];
    rectangle(maze, Point(start.x-r,start.y-r), Point(start.x+r,start.y+r), cv::Scalar(0, 255, 0),-1,8,0);
    rectangle(maze, Point(end.x-r,end.y-r), Point(end.x+r,end.y+r), cv::Scalar(255, 0, 0),-1,8,0);
    while(po.parentx !=start.x || po.parenty !=start.y){
      inpathpoint(po.x,po.y,&maze);
      po=p[po.parentx][po.parenty];
      imshow("My Window",maze);
      waitKey(1);

    }

    waitKey(0);
}
void Maze::ASearch(){
  cout<<"Starting ASearch"<<endl;
  int dx[]={0,1,1,1,0,-1,-1,-1};
  int dy[]={1,1,0,-1,-1,-1,0,1};
  point p[maze.size().width][maze.size().height];
  for (int i=0;i<maze.size().width;i++){
    for(int j=0;j<maze.size().height;j++){
      p[i][j].x=i;
      p[i][j].y=j;
    }
  }
  std::vector<point> openlist;
  std::vector<point> closedlist;
  closedlist.push_back(p[start.x][start.y]);
  int width=maze.size().width;
  int height=maze.size().height;
  while(closedlist[closedlist.size()-1].x!=end.x || closedlist[closedlist.size()-1].y!=end.y){

  int cord_x=closedlist[closedlist.size()-1].x;
  int cord_y=closedlist[closedlist.size()-1].y;
    for(int i=0;i<8;i++){
      if(validpoint(cord_x+dx[i],cord_y+dy[i],width,height)){
        if(freepoint(cord_x+dx[i],cord_y+dy[i],maze)){

          p[cord_x+dx[i]][cord_y+dy[i]].parentx=cord_x;
          p[cord_x+dx[i]][cord_y+dy[i]].parenty=cord_y;
          openlist.push_back(p[cord_x+dx[i]][cord_y+dy[i]]);
          visitpoint(cord_x+dx[i],cord_y+dy[i],&maze);

          imshow("My Window",maze);
          waitKey(1);
        }
      }
}
point tmp;
tmp.x=openlist[0].x;
tmp.y=openlist[0].y;
int sum=(end.x-tmp.x)+(end.y-tmp.y);
int index=0;
for(int i=1;i<openlist.size();i++){
    tmp.x=openlist[i].x;
    tmp.y=openlist[i].y;
    if(sum > (end.x-tmp.x)+(end.y-tmp.y)){
      sum=(end.x-tmp.x)+(end.y-tmp.y);
      index=i;
    }
}
closedlist.push_back(openlist[index]);
openlist.erase(openlist.begin()+index);
}


    point po=p[end.x][end.y];
    rectangle(maze, Point(start.x-r,start.y-r), Point(start.x+r,start.y+r), cv::Scalar(0, 255, 0),-1,8,0);
    rectangle(maze, Point(end.x-r,end.y-r), Point(end.x+r,end.y+r), cv::Scalar(255, 0, 0),-1,8,0);
    while(po.parentx !=start.x || po.parenty !=start.y){
      inpathpoint(po.x,po.y,&maze);
      po=p[po.parentx][po.parenty];
      imshow("My Window",maze);
      waitKey(1);

    }

    waitKey(0);

}
