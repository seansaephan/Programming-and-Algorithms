//shape.h
//Saephan, Sean
//sksaephan
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "grid.h"

class Shape
{
        public:
                Shape(int x, int y){m_x = x; m_y = y;} //set protected functions to x and y
                virtual void draw(Grid &grid) = 0; //draw function from project pdf
        protected:
                int m_x;// member functions of oth x and y
                int m_y;
                
};
#endif
