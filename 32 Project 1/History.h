#ifndef HISTORY_INCLUDED
#define HISTORY_INCLUDED

#include "globals.h"
class Arena;
class Zombie;

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    Arena*  h_history;
    int     h_grid[MAXROWS][MAXCOLS];
    int     h_rows;
    int     h_cols;
    Zombie* h_zombies[MAXZOMBIES];
    int     h_nZombies;
    int     rows() const;
    int     cols() const;
    bool isPosInBounds(int r, int c) const;
   
    
};

#endif // HISTORY_INCLUDED
