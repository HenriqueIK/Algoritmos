#include<iostream>

#include<iomanip>

using namespace std;

int main()
{
	int *vet = NULL; // ponteiro para o vetor

	int N;

	int *vet2 = NULL; // segundo ponteiro para leitura

	int i;
	
	int cont = 0;
	
	cin >> N;

	vet = new int [N];

	for(i = 0; i < N; i++)
	{
		cin >> vet[i];
	}

	vet2 = vet;

	for(i = 0; i < N; i++)
	{
		if((*vet2 > 0) && (*vet2 % 2 == 0))
		{
			cont++;
		}
		
		vet2++;
	}

	cout << cont;
	
	delete []vet; //liberando a memoria alocada

	return 0;
}