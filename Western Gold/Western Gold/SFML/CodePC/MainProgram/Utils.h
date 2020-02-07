#pragma once
	template<typename T>
	T** allocateTwoDimensionalArray(int x, int y) {
		T** arr = new T * [x];
		for (size_t i = 0; i < x; ++i) {
			arr[i] = new T[y];
		}
		return arr;
	}

	template<typename T>
	void deallocateTwoDimensionalArray(T** arr, int x) {
		for (int i = 0; i < x; ++i) {
			delete[] arr[i];
		}
		delete[] arr;
	}
