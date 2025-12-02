#include<iostream>

#include<iomanip>

using namespace std;

int main()
{
	int *v = NULL; // ponteiro para o vetor

	int N;

	int i;
	
	int *v2 = NULL; // ponteiro 2 para fazer a varredura
	
	int menor = 0; // Maior elemento

	cin >> N;

	v = new int [N]; // transformando ponteiro em vetor

	for(i = 0; i < N; i++)
	{
		cin >> v[i];
		
		if(v[i] < 0)
		{
			menor -= v[i];
		}
		else
		{
			menor += v[i];
		}
	}
    
    v2 = v;
    
    for(i = 0; i < N; i++) // inserindo valores no vetor
	{
		if(v[i] < menor)
		{
			menor = *v2;
		}
		
		v2++;
	}
	
	cout << menor << endl; 
	
	delete []v; //liberando a memória alocada
	
	return 0;
}