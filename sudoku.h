#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using Grid = vector< vector<int> >;

const int GRID_SIZE = 9;

// Function Declarations
void printGrid(const Grid& rid);
bool isSafe(const Grid& grid, int row, int col, int num);
bool solveSudoku(Grid& grid, int row, int col);
Grid generateFullGridSimple();
void removeNumbers(Grid& grid, int holes);

#endif 
