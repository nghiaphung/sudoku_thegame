#pragma once

#include <array>
#include <memory>
#include "game_base.hpp"

using namespace std;

class Sudoku: GameBase {
    public:
        typedef array<array<char, 9>, 9> grid_t;
        unique_ptr<grid_t> grid;
        Sudoku(Difficulty game_diffuculty);
        void init_grid(void);
        bool solve_grid(int pos, char value);
        bool check_grid(void);
};