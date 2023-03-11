#pragma once

#include <array>
#include <memory>
#include "game_base.hpp"

using namespace std;

class Sudoku: GameBase {
    public:
        // typedef array<array<char, 9>, 9> grid_t;
        // grid_t grid{0};
        char grid[9][9];

        Sudoku(Difficulty game_diffuculty);
        void init_grid(void);
        bool solve_grid(void);
        bool check_grid(void);

    private:
        array<char, 9> number_arr {1, 2, 3, 4, 5, 6, 7, 8, 9};
        bool is_safe(char pos, char value);
        bool is_grid_filled_full(void);
        bool fill_grid(void);
        void print_grid(void);
        void fill_diagonal_box(char index);
};