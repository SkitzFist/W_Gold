#pragma once
#include <random>

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


	int randomInt(int min, int max) {
		int rv = NULL;

		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_int_distribution<int> dist(min, max);
		rv = dist(generator);
		return rv;
}
	
	float randomFloat(float min, float max) {
		float rv = NULL;
		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_real_distribution<float> dist(min, max);
		rv = dist(generator);
		return rv;
	}
