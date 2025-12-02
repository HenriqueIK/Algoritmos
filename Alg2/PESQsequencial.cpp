#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int vet[100];

	int n;
	
	int aux; // variavel auxiliar

	int i = 0;
	
	int x; // numero a ser procurado

	bool encontrado = false; // variavel responsavel por dizer se o numero foi localizado

	cin>>vet[i];
	
	while(vet[i] != -1)
	{
		i++;
		
		cin >> vet[i];
	}
	
	cin >> x;

	n = i;
	
	for(i=0; i < n; i++)
	{
		if(vet[i] == x)
		{
			encontrado = true;
			
			aux = i;
		}
	}
	
	if(encontrado == false)
	{
		cout << x << " nao encontrado" << endl;
	}
	else
	{
		cout << x << " encontrado na posicao " << aux << endl;
	}
	
	return 0;
}