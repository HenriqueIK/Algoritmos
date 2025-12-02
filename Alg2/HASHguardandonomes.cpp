#include <iostream>

#include<iomanip>

#include<cstring>

using namespace std;

struct dado
{
	char info[50];
	
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

int hash_insert(dado t[], int m, int k, char info[])
{
	int i = 0;
	
	int j;
	
	do
	{
		j = dhash(k, m, i);
		if (t[j].status != 1)
		{
			strcpy(t[j].info, info);
			
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

int hash_search(dado t[], int m, int k, char info[])
{
	int i = 0;
	
	int j;
	
	do
	{
		j = dhash(k, m, i);
		
		if(strcmp(t[j].info, info) == 0)
		{
			return j;
		}
		
		i += 1;
	}while(t[j].status != 0 && i < m);

	return -1;
}

int hash_remove(dado t[], int m, int k, char info[])
{
	int j;
	
	j = hash_search(t, m, k, info);
	
	if(j != -1)
	{
		strcpy(t[j].info, "vazio");
		
		t[j].status = 2;
		
		t[j].k = -1;
		
		return 0;
	}
	else
	{
		return -1; // caso k nao seja encontrado
	}
}

int calcula_chave(char nome[])
{
	int tam; // nome
	
	int i;
	
	int k = 0; // chave
	
	tam = strlen(nome);
	
	for(i = 0; i < tam; i++)
	{
		k += (int)nome[i];
	}
	
	return k;
}

int main()
{
	dado t[100];
	
	char nome[50];
	
	int m; // tamanho da tabela
	
	int i; // contador
	
	int op; // opcao
	
	int r; // resultado
	
	int s; // resultado da pesquisa

	cin >> m >> op;

	for(i = 0; i < m; i++)
	{
		t[i].k = -1; // colocando todos os vetores de t[i].k = -1
		
		t[i].status = 0; // colocando todos os vetores de t[j].status = 0
		
		strcpy(t[i].info, "vazio");
	}
	
	while(op != 5)
	{
		if(op == 1) // inserindo
		{
			cin.ignore();
			
			cin.getline(nome, 50);
							
			r = calcula_chave(nome);

			hash_insert(t, m, r, nome);

			cin >> op;
		}
		else if(op == 2) // pesquisando
		{
			cin.ignore();
			
			cin.getline(nome, 50);
			
			r = calcula_chave(nome);
			
			s= hash_search(t, m, r, nome);
			
			if(s == -1)
			{
				cout << nome << " nao encontrado" << endl;
			}
			else
			{
		     	cout << nome << " encontrado na posicao " << s << endl;
            }
            
			cin >> op;
		}
		else if(op == 3) // removendo
		{
			cin.ignore();
			
			cin.getline(nome, 50);

			r = calcula_chave(nome);

			hash_remove(t, m, r, nome);

			cin >> op;
		}
		else if(op == 4) // listando
		{
			for(int i = 0; i < m; i++)
			{
				cout << t[i].info << endl;
			}

			cout << endl;

			cin >> op;
		}
	}
	return 0;
}