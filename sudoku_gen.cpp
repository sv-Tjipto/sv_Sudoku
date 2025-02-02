#include <iostream>
#include <vector>
#include <cstdlib> // Generating random numbers
#include <ctime> // Get current time

using std::cout;
using std::endl;
using std::vector;

const int GRID_SIZE = 9; // Define Sudoku grid (9x9)
const int BOX_SIZE = 3; // Define Sudoku Box (3x3)

/*

Prints the Grid of the Sudoku

*/
void printGrid(const vector<vector<int>>&grid){
    for (const auto& row : grid) {
        for (int num : row) {
            cout << num << " ";
        }
    }
    cout << endl;
}

