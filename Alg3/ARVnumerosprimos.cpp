#include<iostream>

using namespace std;

typedef struct treenodeptr 
{
    int data;
    treenodeptr * dir;
    treenodeptr * esq;

} treenodeptr;

void tInsere(treenodeptr *& arvore, int data)
{
    if (arvore == NULL)
    {
        arvore = new treenodeptr;
        arvore->data = data;
        arvore->dir = NULL;
        arvore->esq = NULL;
    }
    else 
    {
        if (data > arvore->data)
        {
            tInsere(arvore->dir, data);
        } 
        else if (data < arvore->data)
        {
            tInsere(arvore->esq, data);
        }
    }
}

void primoPosOrdem (treenodeptr * arvore, int &j)
{  
    int aux = 0;

	if (arvore != NULL)
	{
		primoPosOrdem(arvore->esq,j);

		primoPosOrdem(arvore->dir,j);

		for(int i = 1; i <= arvore->data; i++)
		{
			if(arvore->data % i == 0)
            {
                aux++;
            }
		}
		if(aux == 2)
        {
            j++;
        }
	}
}

int contaPrimos(treenodeptr * arvore) 
{
    int j = 0;
    
    primoPosOrdem(arvore, j);

    return j;
}


void tDestruir(treenodeptr *& arvore)
{
    if(arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }
    
    arvore = NULL;
}

int main()
{
    treenodeptr * arvore = NULL;
    
    int N;

    cin >> N;

    while(N != -1)
    {
        tInsere(arvore, N);

        cin >> N;
    }

    contaPrimos(arvore);

    cout << contaPrimos(arvore) << " numeros primos" << endl;

    tDestruir(arvore);
    
    return 0;
}