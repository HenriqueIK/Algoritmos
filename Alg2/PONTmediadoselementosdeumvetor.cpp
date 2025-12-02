#include<iostream>

#include<iomanip>

using namespace std;

int main()
{
	int *vet = NULL; // ponteiro para o vetor

	int N;

	int *vet2 = NULL; // segundo ponteiro para leitura

	int i; // contador

	int s = 0;

	double med;

	cin >> N;

	vet = new int [N];

	for(i = 0; i < N; i++)
	{
		cin >> vet[i];
	}

	vet2 = vet;

	for(i = 0; i < N; i++)
	{
		s += *vet2;

		vet2++;
	}

	med = (double)s / N;

	cout << fixed << setprecision(2);

	cout << med;

	delete []vet; //liberando a memoria alocada

	return 0;
}