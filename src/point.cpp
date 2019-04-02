#include"point.h"
point::point(){
this->x=0;
this->y=0;
this->parentx=0;
this->parenty=0;
}

point::point(int x ,int y ,int parentx ,int parenty){
this->x=x;
this->y=y;
this->parentx=parentx;
this->parenty=parenty;
}
void point::printPoint(){

  std::cout<<this->x<<" "<<this->y<<std::endl;
}

bool point::point::equalPoints(point p){
  if(x==p.x && y==p.y) return true;
  return false;

}

point point::point::addPoints(point p){
  point tmp;
  tmp.x=x+p.x;
  tmp.y=y+p.y;
  return tmp;

}
void point::addparent(point p){
  parentx=p.x;
  parenty=p.y;
}
