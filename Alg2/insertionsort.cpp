#include<iostream>

using namespace std;

void InsertionSort(int vetor[], int tamanho)
{
	int i, j; // contadores

	int x;

	for(j = 1; j < tamanho; j++)
	{
		x = vetor[j];

		i = j - 1;

		while((i >= 0) && (vetor[i] < x))
		{
			vetor[i + 1] = vetor[i];

			i = i - 1;
		}
		vetor[i + 1] = x;
	}
}

int main()
{
	int vetor[100]; //vetor de armazenamento

	int i = 0; //contador

    int a;
    
	int z; //auxiliar

	cin >> a;
	
	while(a != 0)
	{
	    vetor[i] = a;
	    
	    i++;
	    
	    cin >> a;
	}

    InsertionSort(vetor, i);
    	
	for(z = 0; z < i; z++)
	{
		cout<<vetor[z]<<" ";
	}

	return 0;
}