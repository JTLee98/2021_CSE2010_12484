#include <iostream>
#include <cmath>
#include "Sort.h"

constexpr int TESTARR_SIZE = 20;
void printarr(int* arr, int count)
{
	for (int i = 0; i < count; i++)
		std::cout << arr[i] << ", ";
	std::cout << "}\n";
}

int main()
{
	int test_arr1[TESTARR_SIZE] = {};
	int test_arr2[TESTARR_SIZE] = {};
	int temp;
	std::cout << "test array:        {";
	for (int i = 0; i < TESTARR_SIZE; i++)
	{
		temp = rand() % 100 - 50;
		test_arr1[i] = temp;
		test_arr2[i] = temp;
		std::cout << temp << ", ";
	}
	std::cout << "}\n";

	mergeSort(test_arr1, 0, TESTARR_SIZE);
	quickSort(test_arr2, 0, TESTARR_SIZE);
	std::cout << "merge sort result: {";
	printarr(test_arr1, TESTARR_SIZE);
	std::cout << "quick sort result: {";
	printarr(test_arr2, TESTARR_SIZE);

}