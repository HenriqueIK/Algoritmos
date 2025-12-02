#include <iostream>

#include <iomanip>

using namespace std;

int menor(int *vetor, int N)
{
	int menor = 999999; 
	
	int *vet2 = NULL;
	
	vet2 = vetor;
	
	for(int i = 0; i < N; i++)
	{
		if(vet2[i] < menor)
		{
			menor = vet2[i];
		}
	}
	
	return menor;
}

int main()
{
	int n; //tamanho do vetor
	
	int *vetor = NULL; //ponteiro apontando pro nada
	
    cin >> n;

    vetor = new int [n];

    for(int i = 0; i < n; i++)
	{ 
        cin >> vetor[i]; 
    }

    cout << menor(vetor, n) << endl;

    delete [] vetor; //liberando a memoria alocada
    
    return 0;
}