#pragma once

#include <array>
#include <memory>
#include "game_base.hpp"

using namespace std;

class Sudoku: GameBase {
    public:
        Sudoku(Difficulty game_diffuculty);
        void init_grid(void);
        bool solve_grid(void);

    private:
        char grid[9][9];
        array<char, 9> number_arr {1, 2, 3, 4, 5, 6, 7, 8, 9};

        bool is_safe(char pos, char value);
        bool fill_grid(void);
        void print_grid(void);
        void fill_diagonal_box(char index);
};