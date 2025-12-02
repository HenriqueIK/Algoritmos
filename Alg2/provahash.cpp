#include<iostream>

#include<iomanip>

using namespace std;

struct dado
{
	int k; //chave

	int status; //0 para vazio e 1 para ocupado
};

int hash_aux(int k, int m)
{
	int h;
	
	h = (k % m);
	
	return h;	
}

int hash1(int k, int i, int m, int c1, int c2)
{
	int h1;
	
	int h2;
	
	h1 = hash_aux(k, m); //chamando a hash_aux
	
	h2 = (h1 + (c1 * i) + (c2 * i * i)) % m;
	
	return h2;
}

int hash_search(dado t[], int m, int k, int c1, int c2)
{
	int i = 0;
	
	int j = 0;
	
	do
	{
		j = hash1(k, i, m, c1, c2); //chamando a hash1
		
		if(t[j].k == k)
		{
			return j;
		}
		
		i = i + 1;
		
	}while(t[j].status != 0 && i < m);
	
	return -1;
}

int main()
{
	int m; // tamanho da tabela
	
	int c1, c2;
	
	int k; // valor da chave
	
	int x;
	
	int i;
	
	cin >> m >> c1 >> c2;
	
	for(i = 0; i < m; i++)
	{
		t[i].k = -1;

		t[i].status = 0;
	}
	
	do
	{
		cin >> k;
		
	}while(k != 0);
	
	cin >> k;
	
	x = hash_search(t, m, k, c1, c2);
	
	if(x != -1)
	{
		cout << "Chave " << k << " encontrada na posicao " << x;
	}
	
	else
	{
		cout << "Chave " << k << " nao encontrada";
	}
	
	return 0;
}