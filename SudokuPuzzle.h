#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "CellObject.h"
using namespace std;

class SudokuPuzzle
{
public:
	SudokuPuzzle(void);
	~SudokuPuzzle(void);

	void Solve(char filenameIn[]) const;
	int FindBlock(int x, int y) const;

private:
	void Output(CellObject inPuzzleArray[9][9], int numOfSolvedCells, int numOfPasses, int numOfValsConsidered, float time) const;
};

