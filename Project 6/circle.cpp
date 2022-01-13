//circle.cpp
//Saephan, Sean
//sksaephan
#include<iostream>
#include "circle.h"

void Circle::draw(Grid &grid)//draws circle
{
       grid.set((m_x+1), m_y, 'o'); 
       grid.set((m_x+2), m_y, 'o'); 
       grid.set(m_x, (m_y+1), 'o'); 
       grid.set((m_x+3), (m_y+1), 'o'); 
       grid.set(m_x, (m_y+2), 'o'); 
       grid.set((m_x+3), (m_y+2), 'o'); 
       grid.set((m_x+1), (m_y+3), 'o'); 
       grid.set((m_x+2), (m_y+3), 'o'); 
}
