#include<iostream>

#include<iomanip>

#include<cstring>

using namespace std;

struct ficha
{
	char nome[50];

	int idade;
};

int matricula(int mat[], int pesqmat, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(mat[i] == pesqmat)
		{
			return i;
		}
	}
}

int main()
{
	int n;

	int pesqmat;

	int r;

	int mat[10];

	int i;

	ficha dados[100];

	cin >> n;

	for(i = 0; i < n; i++)
	{
		cin >> mat[i];

		cin.ignore();

		cin.getline(dados[i].nome, 50);

		cin >> dados[i].idade;
	}

	cin >> pesqmat;

	r = matricula(mat, pesqmat, n);
	
	cout << dados[r].nome << endl;

	cout << mat[r] << endl;

	cout << dados[r].idade << endl;

	return 0;
}
