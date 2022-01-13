//circle.h
//Saephan, Sean
//sksaephan
#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
#include "shape.h"

class Circle:public Shape
{
        public:
               Circle(int x, int y): Shape(x,y){m_x=x;m_y=y;};//x and y set to protected variables
               virtual void draw(Grid &grid);//draw method for circle
};
#endif
