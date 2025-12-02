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

treenodeptr* tMenor(treenodeptr *& arvore)
{
    treenodeptr* aux = arvore;

    if (aux->esq == NULL) 
    {
        arvore = aux->dir;

        return aux;
    } 
    else 
    {
        return tMenor(aux->esq);
    }
}

int tRemove(treenodeptr *& arvore, int X)
{
    
    treenodeptr * aux;

    if(arvore == NULL)
    {
        return 1;
    }
    if(X == arvore->data)
    {
        aux = arvore;
        if(arvore->esq == NULL)
        { 
            arvore = arvore->dir;
        }
        else if(arvore->dir == NULL)
        { 
            arvore = arvore->esq;
        }
        else
        { 
            aux = tMenor(arvore->dir);

            arvore->data = aux->data;
        }

        delete aux;

        return 0;
    }
    else if(X < arvore->data)
    {
        return tRemove(arvore->esq, X);
    }
    else
    {
        return tRemove(arvore->dir, X);
    }
}

void emOrdem (treenodeptr * arvore)
{  
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);

		cout << arvore->data << " ";

		emOrdem(arvore->dir);
	}

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

    int X;

    int remocao;

    cin >> N;

    while(N != 0)
    {
        tInsere(arvore, N);

        cin >> N;
    }

    cin >> X;

    remocao = tRemove(arvore, X);

    while(remocao == 0)
    {
        remocao = tRemove(arvore, X);
    }

    emOrdem(arvore);

    cout << endl;
    
    tDestruir(arvore);
    
    return 0;
}