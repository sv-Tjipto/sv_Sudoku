#include "sudoku.h"
#include <iostream>

int main() {
    char choice;
    do {

        cout << "Program Started." << endl;

        Grid grid = generateFullGridSimple();

        // cout << "Generate Full Sudoku Grid: \n";
        // printGrid(grid);

        int holes = 40; // Difficulty
        removeNumbers(grid, holes);
        cout << "\nSudoku Puzzle:\n";
        printGrid(grid);
        cout << "PRESS ENTER TO SOLVE\n";
        cin.get();
        cout << "Full Sudoku Grid: \n";
        printGrid(grid);
        cout << "Do you want to continue? y/n \n";
        cin >> choice;
        cin.ignore(); // Ignore the newline character
        
    } while (choice == 'y' || choice == 'Y');

    cout << "Program Ended." << endl;
    return 0;

}