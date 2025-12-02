#include<iostream>

using namespace std;

struct dado
{
	int k; // chave
	
	int status; // 0:vazio, 1:ocupado
};

int hash_aux(int k, int m)
{
    if(k%m < 0)
	{
        return (k % m) + m;
    }
    
    else
	{
        return k % m;
    }
}

int hash1(int k, int i, int m, int c1, int c2)
{
	if((hash_aux(k, m) + ((c1 * i + c2 * i * i) % m)) < 0)
	{
		return (hash_aux(k, m) + ((c1 * i + c2 * i * i) % m)) + m;
	}
    else
	{
		return (hash_aux(k, m) + ((c1 * i + c2 * i * i) % m));
	}
}

int hash_insert(dado T[], int m, int k, int c1, int c2)
{
    int i = 0;
    
    int j;
    
    do
	{
        j = hash1(k, i, m, c1, c2);
        
        if(T[j].status != 1)
		{
            T[j].k = k;
            
            T[j].status = 1;
            
            return j;
        }
        else
        {
            i = i+1;
        }
    }while(i != m);
    
    return -1;
}

int hash_search(dado T[], int m, int k, int c1, int c2)
{
    int i = 0;
    
    int j;
    
    do
    {
        j = hash1(k,i,m,c1,c2);
        
        if(T[j].k == k)
        {
            return j;
        }
        
        i = i + 1;
        
    }while(T[j].status != 0 && i < m);
    
    return -1;
}

int main()
{
    int m; // tamanho da tabela
    
    int c1,c2; // valores das chaves a serem inseridas
    
    int k;
    
    int r; // variavel para chamar a funcao
    
    int j; // contador
    
    int x; // valor da chave a ser procurada
    
    dado T[11];
	
    cin >> m >> c1 >> c2;
    
	for(j = 0; j < m; j++)
	{
		T[j].k = -1;
		
		T[j].status = 0;
	}
	
	cin >> k;
	
    while(k != 0)
	{
       hash_insert(T, m, k, c1, c2);
       
	   cin >> k;
    }
    
    cin >> x;
    
    r = hash_search(T,m,x,c1,c2);
    
    if(r != -1)
    {
        cout << "Chave " << x << " encontrada na posicao " << r << endl;
    }
    else if(r == -1)
    {
        cout << "Chave " << x << " nao encontrada" << endl;
    }
    
    return 0;
}