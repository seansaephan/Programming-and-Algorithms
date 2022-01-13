// grid.cpp
// Saephan, Sean
// sksaephan
#include<iostream>
#include "grid.h"
using namespace std;

Grid::Grid()
{
        for(int x=0;x<60;x++)
        {
                for(int y=0;y<24;y++)
                {
                        m_grid[x][y] = ' '; //initalizes the empty grid to spaces
                }
        }
}

void Grid::set(int x, int y, char c)
{
        if((x < 0 || x > 59) || (y < 0 || y > 23)) //if the values are outside the grid
        {
                return; //do nothing
        }
        else
        {
                m_grid[x][y] = c; ///if the x y values are inside the grid
        }
}

void Grid::print()
{
        for(int x=0;x<24;x++)
        {
                for(int y=0;y<60;y++)
                {
                        cout << m_grid[y][x]; //prints out by row
                }
                cout << endl;
        }
}
