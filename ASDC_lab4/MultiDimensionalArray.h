#pragma once
#include "Includes.h"
class MultiDimensionalArray
{
	vector<pair<int, int>> indicesRange;
	vector<int> dataStorage;
	int size;
	int dimension;
	int calculateSize(vector<pair<int, int>> ranges);
public:
	MultiDimensionalArray(vector<pair<int, int>>& ranges, int dimension);
	void getDefingVectors(int index, vector<int>& rowVector, vector<int>& colVector);
	int directAccess(vector<int> indices);
	int accessAyleaf(vector<int> indices);
	int getSize();
	int getDimension();
	~MultiDimensionalArray();
};

