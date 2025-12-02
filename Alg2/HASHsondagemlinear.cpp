#include<iostream>

using namespace std;

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

int main()
{
	int k; // valor da chave

	int i = 0; // numero da tentativa

	int m; // tamanho da tabela

	int h;
	
	cin >> k >> m;
	
	for(i = 0; i < m; i++)
	{
		h = hash1(k, i, m);
		
		cout << h << endl;
	}

	return 0;
}