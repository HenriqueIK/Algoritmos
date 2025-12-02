#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

struct dado
{
	int k; //chave

	int status; //0: vazio, 1: ocupado
};

int hash_aux(int k, int m)
{
	int h;

	h = (k % m);

	if(h < 0)
	{
		return h + m;
	}

	return h;
}

int hash1(int k, int i, int m)
{
	int x;

	int z;

	x = hash_aux(k, m); //chamando a função hash_aux

	z = (x + i) % m;

	return z;
}

int hash_insert(dado t[], int m, int k)
{
	int j = 0;
	int i = 0;

	do
	{
		j = hash1(k, i, m); //chamando a função hash1

		if (t[j].status != 1)
		{
			t[j].k = k;

			t[j].status = 1;

			return j;
		}
		else
			i = i + 1;

	}
	while(i != m);

	return -1;
}

int hash_search(dado t[], int m, int k)
{
	int i = 0;

	int j;

	do
	{
		j = hash1(k, i, m); //chamando a função hash1

		if(t[j].k == k)
		{
			return j;
		}
		i = i + 1;

	}
	while(t[j].status != 0 && i < m);

	return -1;
}

int hash_remove(dado t[], int m, int k)
{
	int j; //chamando a função hash_search

	j = hash_search(t, m, k);

	if(j != -1)
	{
		t[j].status = 2;

		t[j].k = -1;

		return 0;
	}

	else
	{
		return -1;
	}
}

int main()
{
	dado t[100]; // tabela hash

	int m; // tamanho da tabela

	int k; // valor da chave

	int aux; // analisar as chaves

	int t_rash;

	int x;

	int i = 0;

	cin >> m;

	for(int i = 0; i < m; i++)
	{
		t[i].k = -1;

		t[i].status = 0;
	}

	cin >> aux;

	while(aux != 0)
	{
		t_rash = hash_insert(t, m, aux);

		cin >> aux;
	}

	int k2;
	
	cin >> k2;

	x = hash_remove(t, m, k2);

	for(i = 0; i < m; i ++)
	{
		cout << t[i].k << " ";
	}

	return 0;
}