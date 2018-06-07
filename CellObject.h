#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CellObject
{
public:
	vector<int> cList;
	string pFlag;
	int value;
	CellObject(void);
	~CellObject(void);
	void InputValue(int inValue);
};
