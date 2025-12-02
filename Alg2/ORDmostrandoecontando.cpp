#include<iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanho, int &qt, int n[])
{
	int i;

	int j;

	int trab;

	bool troca;

	int limite;

	int troc = 0;

	troca = true;

	limite = tamanho - 1;

	while (troca)
	{
		troca = false;
		for (i = 0; i < limite; i++)
			if(vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];

				vetor[i] = vetor[i + 1];

				vetor[i + 1] = trab;

				j = i;

				troca = true;

				n[troc] = trab;

				troc++;

			}
		limite = j;
	}

	qt = troc;
}

int main()
{
	int vetor[100];

	int tamanho;

	int qt = 0;

	int n[100];

	int i;

	int j;

	cin >> tamanho; //lendo i

	for(i = 0; i < tamanho; i++)
	{
		cin >> vetor[i];
	}

	bubbleSort(vetor, tamanho, qt, n); // chamando funcao

	for(i = 0; i < tamanho - 1; i++)
	{
		cout << "New trab:" << n[i] << endl;
	}

	cout << "Contador:" << qt << endl;

	return 0;
}
