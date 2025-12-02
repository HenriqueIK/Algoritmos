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

int maior(treenodeptr * arvore)
{ 
    if(arvore == NULL)
    {
        return -1;
    } 
    else 
    {
        if(arvore->dir == NULL)
        {
            return arvore->data;
        } 
        else 
        {
            return maior(arvore->dir);
        }
    }
}

int menor(treenodeptr * arvore)
{ 
    if(arvore == NULL)
    {
        return -1;
    } 
    else 
    {
        if(arvore->esq == NULL)
        {
            return arvore->data;
        } 
        else 
        {
            return menor(arvore->esq);
        }
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

    cin >> N;

    while(N != -1)
    {
        tInsere(arvore, N);

        cin >> N;
    }

    cout << menor(arvore) << " e " << maior(arvore) << endl;

    tDestruir(arvore);
    
    return 0;
}