#include "SudokuPuzzle.h"

int main(int argc, char **) {
	SudokuPuzzle puzzle;
	puzzle.Solve("sudoku_puzzle.txt"); 

	system("pause");

	return 0;
}
