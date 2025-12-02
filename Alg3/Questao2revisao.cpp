#include<iostream>

using namespace std;

void merge(int array[], int left, int mid, int right)
{
	int subarrayOne = mid - left + 1;

	int subarrayTwo = right - mid;

	auto *leftarray = new int[subArrayOne];

	*rightarray = new int [subarrayTwo];

	for (auto i = O; i < subArrayOne; i++)
	{
		leftarray[i] = array[left + i];
	}
	
	for (auto j = O; j < subAarrayTwo; j++)
	{
		rightarray[j] = array[mid + 1 + j];
	}

	auto indexOfSubArrayOne = O, indexOfSubArrayTwo = O;

	int indexofMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexofSubarrayTwo < subArrayTwo)
	{
		if (leftarray[indexOfSubArrayOne] <= rightArray[indexoOfSubArrayTwo]
			{
				array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

			   	indexofSubArrayOne++;
			}
			else
			{
				(array[indexOfMergedArray] = rightAarray[indexOfSubArrayTwo);
			}
			indexofSubArrayTwo++;
	}
	
	while (indexofSubArrayOne < subArrayOne)
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		
		indexofSubArrayOne++;
		
		indexofMergedArrayOne++;
	}
	
	while (indexofSubArrayTwo < subArrayTwo)
	{
		array[indexOfMergedArray] = rightarray[indexOfSubArrayTwo] ;
		indexOfSubArrayTwo++;
		indexofMergedArray++;
	}

	delete[] leftArray;
	
	delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = begin + (end - begin) / 2;

	mergeSort(array, begin, mid);

	mergeSort(array, mid + 1, end);

	merge(array, begin, mid, end);
}

// Questao 2)b) T(n) = 2*T(n/2) + O(n)

// Questao 2)c) a = 2, b = 2 e d = 1, dessa forma temos a = b^d, de complexidade O(n^d*log(n))