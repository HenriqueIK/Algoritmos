#include <iostream>

#include <iomanip>

using namespace std;

struct dado
{
    int k; // chave
    
    int status; // 0:vazio e 1:ocupado
} ;

int hash_aux(int k, int m)
{
    int h1 = k % m;
    
    if(h1 < 0)
    {
        h1 = h1 + m;
    }
    
    return h1;
}

int hash1(int k, int i, int m, int c1, int c2)
{
    int h2 = (hash_aux(k, m) + c1*i + c2*i*i) % m;
    
    return h2;
}

int hash_insert(dado t[], int m, int k, int c1, int c2)
{
    int i = 0;
    
    int j;
    
    do
    {
        j = hash1(k, i, m, c1, c2);
        
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

int hash_search(dado t[], int m, int k, int c1, int c2)
{
    int i = 0;
    
    int j;
    
    do
    {
        j = hash1(k, i, m, c1, c2);
        
        if (t[j].k == k)
		{
			return j;
		}
        i = i + 1;
    }while (t[j].status != 0 && i < m);
    
    return -1;
}

int main()
{
    dado t[100];
    
    int m;
    
    int k; // valor da chave
    
    int c1;
    
    int c2;
    
    int s; // resultado da funcao search

    cin >> m >> c1 >> c2;

   for(int i = 0; i < m; i++) // declarando os valores das structs
   {
        t[i].k = -1;
        
        t[i].status = 0;
    }
    
    cin >> k;
    
    while(k != 0)
    {
        hash_insert(t, m, k, c1, c2);
        
        cin >> k;
    }

    cin >> k; // procurando a chave
    
    s = hash_search(t, m, k, c1, c2);
    
    if(s != -1)
	{
        cout << "Chave " << k << " encontrada na posicao " << s << endl;
    }
    
    else
	{ 
        cout << "Chave " << k << " nao encontrada" << endl;
    }
    
    return 0;
}