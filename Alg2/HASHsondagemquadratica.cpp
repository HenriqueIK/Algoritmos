#include <iostream>

using namespace std;

int hash_aux(int k, int m)
{
	int r;

	r = k % m;

	if(r < 0)
	{
		r += m;
	}
	
	return r;
}

int hash1(int k, int i, int m, int c1, int c2)
{
	int aux;
	
	aux = (hash_aux(k, m) + c1 * i + c2 * i * i) % m;
	
	return aux;
}

int main()
{
	int k; // valor da chave
	
	int m; // tamanho da tabela
	
	int c1, c2; // variaveis auxiliares
	
	cin >> k >> m >> c1 >> c2;
	
	for(int i = 0; i < m; i++)
	{
		if(i - 1 == m)
			cout << hash1(k, i, m, c1, c2) << endl;
		else
			cout << hash1(k, i, m, c1, c2) << " ";
	}
	
	return 0;
}