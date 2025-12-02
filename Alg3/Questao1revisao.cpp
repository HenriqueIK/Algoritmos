#include<iostream>

using namespace std;

void selectionsort(int array[], int n)
{
    // Questao 1) a)

	for (int i = 0; i < n - 1; i++) // 1 + 4(n-1) + 4 + 3(n-1)
	{
		int minIndex = i; // 2(n-1)
		
		for (int j = i + 1; j < n; j++) // [3+3(n/2) + 3 + 3(n/2)](n-1)
		{
			if (array[j] < array[i]) // [5(n/2)] (n - 1)
			{
				minIndex = j; // [2(n/2)](n-1)
			}
		}
		int temp = array[i]; // 3(n-1)
		
		array[i] = array[minIndex]; // 4(n-1)
		
		array[minIndex] = temp; // 3(n-1)
	}

    // Questao 1)b) 1 + 4(n-1) + 4 + 3(n-1) + 2(n-1) + [3+3(n/2) + 3 + 3(n/2)](n-1) + [5(n/2)] (n - 1) + [2(n/2)](n-1) + 3(n-1) + 4(n-1) + 3(n-1)

    // = 6,5 n^2 + 18,5 n - 20

    // Questao 1)c) O código possui 2 repeticoes de n aninhadas, uma complexidade quadratica, ou seja O(n^2)
}