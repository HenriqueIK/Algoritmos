#include<iostream>

#include<iomanip>

#include<cstring>

using namespace std;

struct ficha
{
	int matricula;
	
	char nome[50];
};

int idad(int idade[], int pesqidade, int n)
{
	int cont = 0;

	for(int i = 0; i < n; i++)
	{
		if(idade[i] <= pesqidade)
		{
			cont++;
		}
	}

	return cont;
}

int main()
{
	int n;
	
	int pesqidade;
	
	int r;
	
	int idade[3];

	ficha dados[100];

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> dados[i].matricula;
		
		cin.ignore();
		
		cin.getline(dados[i].nome, 50);
		
		cin >> idade[i];

	}

	cin >> pesqidade;

	r = idad(idade, pesqidade, n);
	
	cout << r << "pessoas que tem essa idade: " << pesqidade << " ou menos" << endl;
	
	return 0;
}
