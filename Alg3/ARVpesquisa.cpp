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

void tPesq(treenodeptr * arvore, int data)
{ 
    if(arvore == NULL)
    {
        cout << "Nao encontrado" << endl;
    } 
    else 
    {
        if(data > arvore->data)
        {
            tPesq(arvore->dir, data);
        } 
        else if(data < arvore->data)
        {
            tPesq(arvore->esq, data);
        } 
        else
        {
            cout << "Encontrado" << endl;
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

    treenodeptr * root = NULL;

    int N;

    int x;

    int num;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;

        tInsere(root, num);
    }

    cin >> x;

    tPesq(root, x);

    tDestruir(root);
    
    return 0;
}