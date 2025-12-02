#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int vet[20]; // vetor que armazena os numeros

	int n;

	int aux; // variavel auxiliar

	int i = 0;

	int x;

	bool acesso = false; // variavel responsavel por dizer se o numero foi localizado

	cin >> vet[i];

	while(vet[i] != -1)
	{
		i++;

		cin >> vet[i];
	}

	cin >> x;

	n = i;

	for(i = 0; i < n; i++)
	{
		if(vet[i] == x)
		{
			acesso = true;

			aux = i;
		}
	}

	if(acesso == false)
	{
		cout << "Nao possui acesso" << endl;
	}
	
	else
	{
		cout << "Possui acesso" << endl;
	}

	return 0;
}