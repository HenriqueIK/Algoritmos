#include <iostream>

using namespace std;

void quickSort(int vetor[], int tamanho, int i, int j)
{
	int trab, pivo;
	
	int e; //esquerda
	
	int d; //direita

	e = i;

	d = j;

	pivo = vetor[(int)((e + d) / 2.0)];

	do
	{
		while(vetor[d] > pivo)
		{
			d--;
		}
		
		while(vetor[e] < pivo)
		{
			e++;
		}
		
		if (e <= d)
		{
			trab = vetor[e];

			vetor[e] = vetor[d];

			vetor[d] = trab;

			e++;

			d--;
		}
	}
	while (e <= d);

	if (d - i >= 0)
	{
		quickSort(vetor, tamanho, i, d);
	}

	if (j - e >= 0)
	{
		quickSort(vetor, tamanho, e, j);
	}
}

int main()
{

	int vet[100];

	int tamanho = 0; // tamanho do vetor

	int i = 0; // variavel que representa o inicio do vetor na funcao quick sort

	int j; // variavel que representa o fim do vetor na funcao quick sort

	int z;

	cin >> z;

	while(z != -1) // inserindo valores ate o valor de -1
	{
		vet[tamanho] = z;

		tamanho++;

		cin >> z;
	}

	j = tamanho;

	quickSort(vet, tamanho, i, j);

	for(z = 0; z < tamanho; z++)
	{
		cout << vet[z] << " ";
	}

	return 0;
}