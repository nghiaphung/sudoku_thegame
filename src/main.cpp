#include <iostream>

#include "sudoku.hpp"

int main (void)
{
    Sudoku game(GameBase::Easy);
    game.init_grid();
    return 0;
}