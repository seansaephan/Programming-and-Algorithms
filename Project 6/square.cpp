//square.cpp 
//Saephan, Sean
//sksaephan
#include<iostream>
#include"square.h"

void Square::draw(Grid &grid)
{
        for(int x=0;x<m_size;x++) //for loop to draw square
        {
                for(int y=0;y<m_size;y++)
                {
                        if(x == 0 || y == 0 || x == (m_size-1) || y == (m_size-1))//to determine rectangle origin
                        {
                            grid.set(m_x+y, m_y+x, '*');
                        }
                        
                }
        }
}
