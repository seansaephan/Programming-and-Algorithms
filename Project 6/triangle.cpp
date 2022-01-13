//triangle.cpp
//Saephan, Sean
//sksaephan
#include<iostream>
#include "triangle.h"

void Triangle::draw(Grid &grid) //draw method for triangle
{
        int x=0;
        grid.set(m_x+2, m_y, '+');
        grid.set(m_x+1, m_y+1, '+');
        grid.set(m_x+3, m_y+1, '+');
        while(x<5)
        {
                grid.set(m_x+(x++), m_y+2, '+');
        }
}
