#include<iostream>

#include<iomanip>

using namespace std;

int main()
{
	int *vet = NULL; // ponteiro apontando pra nada

	int N;

	int i;
	
	int *vet2 = NULL; // ponteiro 2 para fazer a varredura
	
	int menor = 0; // Maior elemento

	cin >> N;

	vet = new int [N]; // transformando ponteiro em vetor

	for(i = 0; i < N; i++)
	{
		cin >> vet[i];
		
		if(vet[i] < 0)
		{
			menor -= vet[i];
		}
		else
		{
			menor += vet[i];
		}
	}
    
    vet2 = vet;
    
    for(i = 0; i < N; i++) // inserindo valores no vetor
	{
		if(vet[i] < menor)
		{
			menor = *vet2;
		}
		
		vet2++;
	}
	
	cout << menor << endl; 
	
	delete []vet; //liberando a memoria alocada
	
	return 0;
}