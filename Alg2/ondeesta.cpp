#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int n;

	int vet[100];

	int aux;

	int i;

	int x;

	int encontrado = 0; // variavel responsavel por dizer se o numero foi localizado

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> vet[i];
	}

	cin >> x;

	for (i = 0; i < n; i++)
	{
		if(vet[i] == x)
		{
			aux = i;

			encontrado = 1;
		}
	}
	
	if(encontrado == 1)
	{
		cout << "Corredor " << aux << endl;
	}

	else
	{
		cout << "Nao localizado" << endl;
	}
	
	return 0;
}
