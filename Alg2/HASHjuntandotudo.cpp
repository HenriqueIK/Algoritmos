#include <iostream>

#include <iomanip>

using namespace std;

struct dado
{
	int k; // chave
	
	int status; // 0: vazio, 1: ocupado e 2: removido
};

int h1(int k, int m)
{
	int g = k % m;
	
	if(g < 0)
	{
		g += m;
	}
	
	return g;
}

int h2(int k, int m)
{
	int b = 1 + (k % (m - 1));
	
	if(b < 0)
	{
		b += m;
	}
	
	return b;
}

int dhash(int k, int m, int i)
{
	int dh = (h1(k, m) + i * h2(k, m)) % m;
	
	return dh;
}

int hash_insert(dado t[], int m, int k)
{
	int i = 0;
	
	int j;
	
	do
	{
		j = dhash(k, m, i);
		
		if (t[j].status != 1)
		{
			t[j].k = k;
			
			t[j].status = 1;
			
			return j;
		}
		else
		{
			i = i + 1;
		}
	}while (i != m);
	
	return -1;
}

int hash_search(dado t[], int m, int k)
{
	int i = 0;
	
	int j;
	
	do // buscando pelo vetor
	{
		j = dhash(k, m, i);
		
		if(t[j].k == k)
		{
			return j;
		}
		
		i += 1;
		
	}while(t[j].status != 0 && i < m);

	return -1;
}

int hash_remove(dado t[], int m, int k)
{
	int j;
	
	j = hash_search(t,m, k);
	
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
	dado t[100];
	
	int m;
	
	int r; // resultado
	
	int i = 0;
	
	int aux; // variavel para ler as chaves
	
	int op;
	
	int p; // numero buscado

	cin >> m >> op;

	for(i = 0; i < m; i++)
	{
		t[i].k = -1;
		
		t[i].status = 0;
	}

	while(op != 5)
	{
		if(op == 1)
		{
			cin >> aux; // lendo as chaves

			hash_insert(t, m, aux);

			cin >> op;
		}
		else if(op == 2) // pesquisando
		{
			cin >> p;
			
			cout << hash_search(t, m, p) << endl;

			cin >> op;
		}
		else if(op == 3) // removendo
		{
			cin >> aux;

			hash_remove(t, m, aux);

			cin >> op;
		}
		else if(op == 4) // listando
		{
			for(int i = 0; i < m; i++)
			{
				cout << t[i].k << " ";
			}

			cout << endl;

			cin >> op;
		}
	}

	return 0;
}