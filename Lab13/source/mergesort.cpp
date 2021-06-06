#include "Sort.h"
#include <stdexcept>

void merge(int input[], const int start, const int mid, const int end)
{
	int b1 = start, b2 = mid;
	int* output = new int[end-start];
	int idx = 0;
	// assume both sections are sorted
	while (b1 < mid and  b2 < end)
	{
		if (input[b1] <= input[b2])
			output[idx] = input[b1++];
		else output[idx] = input[b2++];
		idx++;
	}
	// fill in remaining
	if (b1 != mid)
		for (idx; idx < end - start; idx++)
			output[idx] = input[b1++];
	else if (b2 != end)
		for (idx; idx < end - start; idx++)
			output[idx] = input[b2++];
	// replace original with merged
	for (idx = start; idx < end; idx++)
		input[idx] = output[idx - start];
	delete[] output;
}

void mergeSort(int unsorted[], const int start, const int end)
{
	if (start + 1 >= end) return;

	int mid = (start + end) / 2;
	mergeSort(unsorted, start, mid);
	mergeSort(unsorted, mid, end);
	merge(unsorted, start, mid, end);
}


