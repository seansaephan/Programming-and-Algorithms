//triangle.h
//Saephan, Sean
//sksaephan
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
#include "shape.h"

class Triangle: public Shape
{
        public:
               Triangle(int x, int y) : Shape(x,y){m_x=x; m_y=y;} //sets x and y to member functions
               virtual void draw(Grid &grid);//draw method for triangle
};
#endif
