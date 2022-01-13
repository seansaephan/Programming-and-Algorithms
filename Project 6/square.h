//square.h
//Saephan, Sean
//sksaephan
#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include<iostream>

class Square: public Shape
{
        public:                              //sets x and y variables to member variables and sets m_size to size 
               Square(int x, int y, int size): Shape(x,y), m_size(size){m_x=x;m_y=y;m_size=size;};
               virtual void draw(Grid &grid); //draw method for square
        private: 
               int m_size;//size member function
};
#endif
