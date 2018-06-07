#include "SudokuPuzzle.h"
#include "CellGroup.h"
#include "CellObject.h"
#include <Windows.h>
#include <algorithm>

CellObject::CellObject(void)
{
}
CellObject::~CellObject(void)
{

}

void CellObject::InputValue(int inValue)
{
	//Change value
	value = 0;
	value = inValue;
	//determine if value has been predefined in puzzle
	if (inValue == 0)
	{
		pFlag = "undefined";
	}
	else
	{
		pFlag = "defined";
	}
}


CellGroup::CellGroup(void)
{
}
CellGroup::~CellGroup(void)
{

}

SudokuPuzzle::SudokuPuzzle(void) 
{
}

SudokuPuzzle::~SudokuPuzzle(void)
{
}

int SudokuPuzzle::FindBlock(int x, int y) const
{
	//Used to find the approprtiate block for the inputted coordinates
	int blockNum;
	switch (y)
	{
	case 0:
	case 1:
	case 2:
		switch (x)
		{
		case 0:
		case 1:
		case 2:
			blockNum = 0;
			break;

		case 3:
		case 4:
		case 5:
			blockNum = 1;
			break;

		case 6:
		case 7:
		case 8:
			blockNum = 2;
			break;
		}
		break;

	case 3:
	case 4:
	case 5:
		switch (x)
		{
		case 0:
		case 1:
		case 2:
			blockNum = 3;
			break;

		case 3:
		case 4:
		case 5:
			blockNum = 4;
			break;

		case 6:
		case 7:
		case 8:
			blockNum = 5;
			break;
		}
		break;

	case 6:
	case 7:
	case 8:
		switch (x)
		{
		case 0:
		case 1:
		case 2:
			blockNum = 6;
			break;

		case 3:
		case 4:
		case 5:
			blockNum = 7;
			break;

		case 6:
		case 7:
		case 8:
			blockNum = 8;
			break;
		}
		break;
	}
	return blockNum;
}

void SudokuPuzzle::Solve(char filenameIn[]) const
{
	//creating cell objects
	CellObject a1, a2, a3, a4, a5, a6, a7, a8, a9,
		b1, b2, b3, b4, b5, b6, b7, b8, b9,
		c1, c2, c3, c4, c5, c6, c7, c8, c9,
		d1, d2, d3, d4, d5, d6, d7, d8, d9,
		e1, e2, e3, e4, e5, e6, e7, e8, e9,
		f1, f2, f3, f4, f5, f6, f7, f8, f9,
		g1, g2, g3, g4, g5, g6, g7, g8, g9,
		h1, h2, h3, h4, h5, h6, h7, h8, h9,
		i1, i2, i3, i4, i5, i6, i7, i8, i9;
	//An array of pointers to the cell objects
	CellObject *puzzleArray[9][9] = {
		{ &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9 } ,
		{ &b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9 } ,
		{ &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9 } ,
		{ &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9 } ,
		{ &e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9 } ,
		{ &f1, &f2, &f3, &f4, &f5, &f6, &f7, &f8, &f9 } ,
		{ &g1, &g2, &g3, &g4, &g5, &g6, &g7, &g8, &g9 } ,
		{ &h1, &h2, &h3, &h4, &h5, &h6, &h7, &h8, &h9 } ,
		{ &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9 }

	};
	//creating row objects
	CellGroup rowA, rowB, rowC, rowD, rowE, rowF,
		rowG, rowH, rowI;
	//creating an array of pointers to the row objects
	CellGroup *rowArray[9] = { &rowA, &rowB, &rowC, &rowD, &rowE, &rowF,
		&rowG, &rowH, &rowI };
	//assigning the appropriate cell objects to the row objects
	for (int x = 0; x < 9; x++)
	{
		for (int j = 0; j < 9; j++)
		{
			rowArray[x]->pointerArray[j] = puzzleArray[x][j];
		}
	}
	//creating column objects
	CellGroup column1, column2, column3, column4, column5, 
		column6, column7, column8, column9;
	//creating an array of pointers to the column objects
	CellGroup *columnArray[9] = { &column1, &column2, &column3,
		&column4, &column5, &column6, &column7, &column8, &column9 };
	//assigning the appropriate cell objects to the column objects
	for (int x = 0; x < 9; x++)
	{
		for (int j = 0; j < 9; j++)
		{
			columnArray[x]->pointerArray[j] = puzzleArray[j][x];
		}
	}
	//creating the block objects
	CellGroup abc123, abc456, abc789, def123, def456, def789,
		ghi123, ghi456, ghi789;
	//creating an array of block objects
	CellGroup *blockArray[9] = { &abc123, &abc456, &abc789, 
		&def123, &def456, &def789, &ghi123, &ghi456, &ghi789 };
	//assigning the appropriate cell objects to the block objects
	int p = 0;
	//abc123
	for (int x = 0; x < 3; x++)
	{
		for (int j = 0; j < 3; j++)
		{
			blockArray[0]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//abc456
	for (int x = 0; x < 3; x++)
	{
		for (int j = 3; j < 6; j++)
		{
			blockArray[1]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//abc789
	for (int x = 0; x < 3; x++)
	{
		for (int j = 6; j < 9; j++)
		{
			blockArray[2]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//def123
	for (int x = 3; x < 6; x++)
	{
		for (int j = 0; j < 3; j++)
		{
			blockArray[3]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//def456
	for (int x = 3; x < 6; x++)
	{
		for (int j = 3; j < 6; j++)
		{
			blockArray[4]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//def789
	for (int x = 3; x < 6; x++)
	{
		for (int j = 6; j < 9; j++)
		{
			blockArray[5]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//ghi123
	for (int x = 6; x < 9; x++)
	{
		for (int j = 0; j < 3; j++)
		{
			blockArray[6]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//ghi456
	for (int x = 6; x < 9; x++)
	{
		for (int j = 3; j < 6; j++)
		{
			blockArray[7]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//ghi789
	for (int x = 6; x < 9; x++)
	{
		for (int j = 6; j < 9; j++)
		{
			blockArray[8]->pointerArray[p] = puzzleArray[x][j];
			p++;
		}
	}
	p = 0;
	//reading the data file
	//Create an input file stream
	string filename(filenameIn);
	ifstream in(filename, ios::in);
	int number; //Variable to hold each number as it is read
	for (int x = 0; x < 9; x++)
	{
		for (int j = 0; j < 9; j++)
		{
			in >> number;
			rowArray[x]->pointerArray[j]->InputValue(number);
		}
	}
	//starting the "timer"
	LARGE_INTEGER start, end, frequency;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);

	// Solve the puzzle
	// Creates a candidate list
	for (int y = 0; y < 9; ++y)
	{
		for (int x = 0; x < 9; ++x)
		{
			if (puzzleArray[y][x]->pFlag == "undefined")
			{
				for (int z = 1; z < 10; ++z)
				{
					for (int v = 0; v < 9; ++v)
					{
						/*checks to see if the possible candidate 
						number "z" appears as a defined value 
						in the triple context*/
						if (z == rowArray[y]->pointerArray[v]->value)
						{
							break;
						}
						else if (z == columnArray[x]->pointerArray[v]->value)
						{
							break;
						}
						else if (z == blockArray[FindBlock(x, y)]->pointerArray[v]->value)
						{
							break;
						}
						/*if all values in the triple context 
						have been checked and the number does 
						not appear then it is assigned*/
						else if (v == 8)
						{
							puzzleArray[y][x]->cList.push_back(z);
							break;
						}
					}
				}
			}
		}
	}

	//variables to hold instrumentation data
	int numOfSolvedCells = 0;
	int numOfPasses = 0;
	size_t numOfValsConsidered = 0;;
	int solved = 1;
	//as long as a cell has been assigned in the last pass this loop will repeat
	while (solved != 0)
	{
		solved = 0;
		for (int y = 0; y < 9; ++y)
		{
			for (int x = 0; x < 9; ++x)
			{
				if (puzzleArray[y][x]->cList.size() == 1)
				{
					puzzleArray[y][x]->value = puzzleArray[y][x]->cList[0];
					++numOfSolvedCells;
					puzzleArray[y][x]->pFlag == "defined";
					++solved;
					for (int j = 0; j < 9; ++j)
					{
						//Searches the triple context and removes the assigned value from their candidate lists
						numOfValsConsidered = numOfValsConsidered + rowArray[y]->pointerArray[j]->cList.size();
						rowArray[y]->pointerArray[j]->cList.erase(std::remove(rowArray[y]->pointerArray[j]->cList.begin(), 
							rowArray[y]->pointerArray[j]->cList.end(), puzzleArray[y][x]->value),
							rowArray[y]->pointerArray[j]->cList.end());
						numOfValsConsidered = numOfValsConsidered + columnArray[x]->pointerArray[j]->cList.size();
						columnArray[x]->pointerArray[j]->cList.erase(std::remove(columnArray[x]->pointerArray[j]->cList.begin(),
							columnArray[x]->pointerArray[j]->cList.end(), puzzleArray[y][x]->value),
							columnArray[x]->pointerArray[j]->cList.end());
						numOfValsConsidered = numOfValsConsidered + blockArray[FindBlock(x, y)]->pointerArray[j]->cList.size();
						blockArray[FindBlock(x, y)]->pointerArray[j]->cList.erase(std::remove(blockArray[FindBlock(x, y)]->pointerArray[j]->cList.begin(),
							blockArray[FindBlock(x, y)]->pointerArray[j]->cList.end(), puzzleArray[y][x]->value),
							blockArray[FindBlock(x, y)]->pointerArray[j]->cList.end());
					}
				}
			}
		}
		++numOfPasses;
	}

	QueryPerformanceCounter(&end);
	float time = (end.QuadPart - start.QuadPart) / (static_cast<float> (frequency.QuadPart));

	//creates an output array of the finished objects
	CellObject outputArray[9][9] = {
		{ a1, a2, a3, a4, a5, a6, a7, a8, a9 } ,
		{ b1, b2, b3, b4, b5, b6, b7, b8, b9 } ,
		{ c1, c2, c3, c4, c5, c6, c7, c8, c9 } ,
		{ d1, d2, d3, d4, d5, d6, d7, d8, d9 } ,
		{ e1, e2, e3, e4, e5, e6, e7, e8, e9 } ,
		{ f1, f2, f3, f4, f5, f6, f7, f8, f9 } ,
		{ g1, g2, g3, g4, g5, g6, g7, g8, g9 } ,
		{ h1, h2, h3, h4, h5, h6, h7, h8, h9 } ,
		{ i1, i2, i3, i4, i5, i6, i7, i8, i9 }
	};

	Output(outputArray, numOfSolvedCells, numOfPasses, numOfValsConsidered, time);
}

void SudokuPuzzle::Output(CellObject inPuzzleArray[9][9], int numOfSolvedCells, int numOfPasses, int numOfValsConsidered, float time) const
{
	ofstream fout("sudoku_solution.txt"); 
	//iterates through the grid writing the values to the text file
	if(fout.is_open())
	{
		for(int y = 0; y < 9; ++y)
		{
			for(int x = 0; x < 9; ++x)
			{
				fout << inPuzzleArray[y][x].value << " ";
			}
			fout << endl;
		}
		//outputs the instrumentation data to the console
		cout << "----Software Performance---- ";
		cout << endl;
		cout << "Number of solved Cells = " << numOfSolvedCells;
		cout << endl;
		cout << "Number of passes through the grid = " << numOfPasses;
		cout << endl;
		cout << "Number of candidate values considered = " << numOfValsConsidered;
		cout << endl;
		cout << "Time taken for solution to be produced = " << time;
		cout << endl;
		cout << "-----------------------------";
		cout << endl;
		fout.close();
	}
}
