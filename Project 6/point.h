//point.h
//Saephan, Sean
//sksaephan
#ifndef POINT_H
#define POINT_H
#include<iostream>
#include "shape.h"
class Point:public Shape
{
        public:
               Point(int x, int y, char c):Shape(x,y), m_c(c){m_x=x;m_y=y;m_c=c;};//sets x and y and c to protected variables
               void draw(Grid &grid);
        protected:
               char m_c;
};
#endif
