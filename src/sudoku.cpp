#include <iostream>
#include <stdlib.h> //rand()
#include <algorithm> // std::shuffle
#include <random>
#include <string>
#include <chrono> // std::chrono::system_clock

#include "sudoku.hpp"

using namespace std;

bool find_unasigned_location(char grid[9][9], char &row, char &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

Sudoku::Sudoku(Difficulty game_diffuculty)
{
    GameBase::difficulty = game_diffuculty;
    for (auto i = 0; i < 9; i++)
    {
        for (auto j = 0; j < 9; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Sudoku::init_grid(void)
{
    fill_grid();
}

bool Sudoku::solve_grid(void)
{
    char row, col;

    if (!find_unasigned_location(this->grid, row, col))
    {
        //no unassinged location found -> all filled
        return true;
    }

    for (auto i = 0; i < 9; i++)
    {
        if (is_safe(row*9+col, number_arr[i]))
        {
            grid[row][col] = number_arr[i];

            if (solve_grid())
            {
                //all location filled
                return true;
            }

            // failure, unmake and try again
            grid[row][col] = 0;
        }
    }

    return false; //this triggers backtracking
}

/*
 * Box is a 3x3 region in Sudoku grid
 * The algorith is we will fill in 3 diagonal box, which don't have any common row or column
 * --> we don't need to check value in those box is safe or not
 * Doing this helps solve_grid() reduce steps because we have already filled 1/3 of the grid
*/ 
void Sudoku::fill_diagonal_box(char index)
{
    //check for valid argument
    if (index > 3)
        return;

    char start = index * 3;

    // Shuffle number_arr to randomly create a "Box" -> the grid will be different each time it is created
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (number_arr.begin(), number_arr.end(), std::default_random_engine(seed));

    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            grid[start+i][start+j] = number_arr[i*3+j];
        }
    }
}

bool Sudoku::fill_grid(void)
{
    // First: fill 3 diagonal box
    // | x | . | . |
    // | . | x | . |
    // | . | . | x |
    fill_diagonal_box(0);
    fill_diagonal_box(1);
    fill_diagonal_box(2);

    // Second: fill all the remaining
    solve_grid();

    print_grid();
    return true;
}

bool Sudoku::is_safe(char pos, char value)
{
    char col = pos % 9;
    char row = pos / 9;
    char box_start_row = row - row % 3; //horizontal starting position of 3x3 box
    char box_start_col = col - col % 3; //vertical starting position of 3x3 box

    if ((pos > 81) || (value > 9) || (value < 1))
        return false;

    // check if value is used in the row
    for (char i = 0; i < 9; i++)
    {
        if (value == grid[row][i])
            return false;
    }

    // check if value is used in the column
    for (char i = 0; i < 9; i++)
    {
        if (value == grid[i][col])
            return false;
    }

    // check if value is used in the box
    for (char i = 0; i < 3; i++)
    {
        for (char j = 0; j < 3; j++)
        {
            if (value == grid[box_start_row+i][box_start_col+j])
            {
                return false;
            }  
        }
    }

    return true;
}

void Sudoku::print_grid(void)
{
    cout << endl;
    for (auto i = 0; i < 9; i++)
    {
        for (auto j = 0; j < 9; j++)
        {
            cout << to_string(grid[i][j]);
        }
        cout << endl;
    }   
}