#include "sudoku.h"
#include <iostream>
#include <vector>
#include <cstdlib> // Generating random numbers
#include <ctime> // Get current time



using std::vector;


// const int GRID_SIZE = 9; // Define Sudoku grid (9x9)
const int BOX_SIZE = 3; // Define Sudoku Box (3x3)

using Grid = vector<vector<int>>; // Alias for 2D vector

/*

Prints the Grid of the Sudoku

*/
void printGrid(const Grid& grid){
    // for (const auto& row : grid) {
    //     for (int num : row) {
    //         cout << num << " ";
    //     }
    // }
    // cout << endl;
    cout << "-------------------------" << endl;
    for (int row = 0; row < GRID_SIZE; ++row) {
        cout << "| ";
        for (int col = 0; col < GRID_SIZE; ++col) {
            cout << grid[row][col] << " ";
            if ((col + 1) % 3 == 0) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((row + 1) % 3 == 0) {
            cout << "-------------------------" << endl;
        }
    }
}

bool isSafe(const Grid& grid, int row, int col, int num) {
    // Checks the the X & Y grid of num for matching
    for (int x = 0; x < GRID_SIZE; ++x) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    // Checks the 3x3 box if any matching num
    int startRow  = row - row % 3, startCol = col - col % 3;
    for (int i = 0;i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(Grid& grid, int row, int col) {
    if (row == GRID_SIZE - 1 && col == GRID_SIZE) {
        return true;
    }
    if (col == GRID_SIZE) {
        row++;
        col = 0;
    }
    // If there is a number in current slot, skip next
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }
    for (int num = 1; num <= GRID_SIZE; ++num) {
        if (isSafe (grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

Grid generateFullGridSimple(){
    vector<vector<int>> grid(GRID_SIZE,vector<int>(GRID_SIZE, 0));

    srand(time(0));
    for (int i = 0; i < GRID_SIZE; ++i) {
        int num = rand() % GRID_SIZE + 1;
        if  (isSafe(grid, 0, i, num)) {
            grid[0][i] = num;
        }
    }

    solveSudoku(grid, 0, 0);
    return grid;
}

void removeNumbers(Grid& grid, int holes) {
    while (holes > 0) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            --holes;
        }
    }
}