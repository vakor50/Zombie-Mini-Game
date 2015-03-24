#include "History.h"
#include "Arena.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
    h_rows = nRows;
    h_cols = nCols;
    h_nZombies = 0;
    h_history = new Arena(nRows, nCols);
}

bool History::record(int r, int c)
{
    if (! isPosInBounds(r, c))
        return false;
    h_history->addZombie(r, c);
    return true;
}

bool History::isPosInBounds(int r, int c) const
{
    return (r >= 1  &&  r <= h_rows  &&  c >= 1  &&  c <= h_cols);
}

void History::display() const
{
    char displayGrid[MAXROWS][MAXCOLS];
    int r, c;
    
    // Fill displayGrid with dots (empty) and stars (brains)
    for (r = 1; r <= h_rows; r++)
    {
        for (c = 1; c <= h_cols; c++)
        {
            int numAtPos = h_history->numberOfZombiesAt(r, c);
            //cout << numAtPos << ": " << r << ", " << c << endl;
            if (numAtPos == 0)
                displayGrid[r-1][c-1] = '.';
            else if (numAtPos > 26)
                displayGrid[r-1][c-1] = 'Z';
            else
                displayGrid[r-1][c-1] = numAtPos + 64;
        }
    }
    
    // Draw the grid
    clearScreen();
    for (r = 1; r <= h_rows; r++)
    {
        for (c = 1; c <= h_cols; c++)
            cout << displayGrid[r-1][c-1];
        cout << endl;
    }
    cout << endl;
}