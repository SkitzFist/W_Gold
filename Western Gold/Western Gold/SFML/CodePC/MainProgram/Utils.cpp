#include "Utils.h"

Utils::Utils()
{
}

Utils::~Utils()
{
}

template<typename T>
T** Utils::allocateTwoDimensionalArray(int x, int y) {
	
	T** arr = new T*[x];
	for (size_t i; i < x; ++i) {
		arr[i] = new T[y];
	}
	return arr;
}

template<typename T>
void Utils::deallocateTwoDimensionalArray(T** arr) {
	delete[] * arr;
	delete[] arr;
}