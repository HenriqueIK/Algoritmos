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

	x = hash_aux(k, m);

	z = (x + i) % m;

	return z;
}

int hash_insert(dado t[], int m, int k)
{
	int j = 0;
	int i = 0;

	do
	{
		j = hash1(k, i, m);

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

int main()
{
	dado t[100]; //tabela hash

	int m; //tamanho da tabela
	
	int k; // valor da chave
	
	int i = 0;

	cin >> m;

	for(int i = 0; i < m; i++)
	{
		t[i].k = -1;

		t[i].status = 0;
	}

	cin >> k;

	while(k != 0)
	{
		hash_insert(t, m, k);
		cin >> k;
	}

	for(i = 0; i < m; i++)
	{
		cout << t[i].k << " ";
	}

	return 0;
}