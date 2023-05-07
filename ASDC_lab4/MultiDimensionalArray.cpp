#include "MultiDimensionalArray.h"

MultiDimensionalArray::MultiDimensionalArray(vector<pair<int, int>>& ranges, int dimension)
	:
	size(calculateSize(ranges)),
	indicesRange(ranges),
	dimension(dimension)
{}

int MultiDimensionalArray::directAccess(vector<int> indices)
{
	int index = indices[dimension - 1] - indicesRange[dimension - 1].first;
	int product = 1;
	for (int i = dimension - 2; i >= 0; i--) {
		index += (indices[i] - indicesRange[i].first) * product;
		product *= (indicesRange[i + 1].second - indicesRange[i + 1].first + 1);
	}
	return dataStorage[index];
}

int MultiDimensionalArray::accessAyleaf(vector<int> indices)
{
	int index = indices[0] - indicesRange[0].first;
	for (int i = 1; i < dimension; i++) {
		int product = 1;
		for (int j = 0; j < i; j++) {
			product *= (indicesRange[j + 1].second - indicesRange[j + 1].first + 1);
		}
		index += (indices[i] - indicesRange[i].first) * product;
	}
	return dataStorage[index];
}

MultiDimensionalArray::~MultiDimensionalArray() {
	// dtor
}

int MultiDimensionalArray::calculateSize(vector<pair<int, int>> ranges)
{
	int size = 1;
	for (auto& x : ranges) {
		size *= (x.second - x.first + 1);
	}
	dataStorage.resize(size);
	for (int i = 0; i < size; i++) {
		dataStorage[i] = i;
	}
	return size;
}

int MultiDimensionalArray::getSize() {
	return size;
}

int MultiDimensionalArray::getDimension()
{
	return dimension;
}

void MultiDimensionalArray::getDefingVectors(int index, vector<int>& rowVector, vector<int>& colVector) {
	int product = 1;
	for (int i = dimension - 1; i >= 0; i--) {
		rowVector[i] = (index / product) % (indicesRange[i].second - indicesRange[i].first + 1) + indicesRange[i].first;
		product *= (indicesRange[i].second - indicesRange[i].first + 1);
	}
	product = 1;
	for (int i = 0; i < dimension; i++) {
		colVector[i] = (index / product) % (indicesRange[i].second - indicesRange[i].first + 1) + indicesRange[i].first;
		product *= (indicesRange[i].second - indicesRange[i].first + 1);
	}
}
