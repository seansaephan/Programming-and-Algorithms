// grid.h
// Saephan, Sean
// sksaephan

#ifndef GRID_H
#define GRID_H

static const int COLS = 60;
static const int ROWS = 24;

class Grid
{
    public:
    	Grid(); //constructor
	    void set(int x, int y, char c);//set function for grid
	    void print();//print function for borders
    private:
    	char m_grid[COLS][ROWS];
};

#endif
