#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "CellObject.h"
using namespace std;

class CellGroup
{
public:
	CellObject *pointerArray[9];
	CellGroup(void);
	~CellGroup(void);
};