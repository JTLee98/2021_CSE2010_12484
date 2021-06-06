#include "Sort.h"
inline void swap(int list[], const int id1, const int id2)
{
	int temp = list[id1];
	list[id1] = list[id2];
	list[id2] = temp;
}

int partition(int input[], const int start, const int end)
{
	int pivot = input[start];
	int low = start + 1;
	int high = end - 1;
	while (low < high)
	{
		if (input[low] <= pivot)
		{
			low++;
			continue;
		}
		if (input[high] >= pivot)
		{
			high--;
			continue;
		}
		swap(input, low++, high--);
	}
	if (low == high and input[low] < pivot)
		swap(input, low, start);
	else if (low > high and input[high] < pivot) 
		swap(input, high, start);
	return high;
}

void quickSort(int unsorted[], const int start, const int end)
{
	if (start + 1 >= end) return;
	if (start + 2 == end)
	{
		if (unsorted[start] > unsorted[start + 1])
			swap(unsorted, start, start + 1);
		return;
	}
	int p = partition(unsorted, start, end);
	quickSort(unsorted, start, p);
	quickSort(unsorted, p, end);
}


