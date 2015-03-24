
// zombies.cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "Game.h"
using namespace std;

int main()
{
    // Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Create a gamed
    // Use this instead to create a mini-game:   Game g(3, 5, 2);
    // (x, y, z): x = x-axis size, y = y-axis size, z = number of zombies
    Game g(10, 10, 10);
    
    // Play the game
    g.play();
}
