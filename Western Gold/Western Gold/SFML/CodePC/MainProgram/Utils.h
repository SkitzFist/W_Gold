#pragma once
class Utils
{
public:
	Utils();
	~Utils();

	template<typename T>
	T** allocateTwoDimensionalArray(int x, int y);

	template<typename T>
	void deallocateTwoDimensionalArray(T** arr);
private:
};
