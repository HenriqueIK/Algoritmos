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

int contaFolhas(treenodeptr * arvore) 
{
    if (arvore == NULL) 
    {
        return 0;
    } 
    else 
    {
        if (arvore->esq == NULL && arvore->dir == NULL) 
        {
            return 1;
        }
        else
        {
            return contaFolhas(arvore->esq) + contaFolhas(arvore->dir);
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

    cout << contaFolhas(arvore) << endl;

    tDestruir(arvore);
    
    return 0;
}