#include<iostream>

#include<iomanip>

#include<cstring>

using namespace std;

struct ficha
{
	int matricula;
	
	int idade;
	
	char nome[50];
};

int main()
{
	int n;
	
	char pesqnome[50];
	
	int r;
	
	int t;

	ficha dados[100];

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> dados[i].matricula;
		
		cin.ignore();
		
		cin.getline(dados[i].nome, 50);
		
		cin >> dados[i].idade;

	}

	cin.ignore();
	
	cin.getline(pesqnome, 50);
	
	t = strlen(pesqnome);

	for(int i = 0; i < t; i++)
	{
		if(strcmp(dados[i].nome, pesqnome) == 0)
		{
			r = i;
		}
	}

	cout << dados[r].nome << endl;
	
	cout << dados[r].matricula << endl;
	
	cout << dados[r].idade << endl;
	
	return 0;
}
