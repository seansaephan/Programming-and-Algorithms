//point.cpp
//Saephan, Sean
//sksaephan
#include<iostream>
#include "point.h"

void Point::draw(Grid &grid)//draws and sets point
{
        grid.set(m_x, m_y, m_c);
}
