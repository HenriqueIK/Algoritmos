#include<iostream>

#include<list>

using namespace std;

typedef struct treenodeptr 
{
    int data;
    treenodeptr * dir;
    treenodeptr * esq;

} treenodeptr;

void tInsere(treenodeptr *& arvore, int data) //passagem por referencia, pois a arvore pode ser alterada
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

void emNivel(treenodeptr * arvore)
{
    treenodeptr * n;

    list<treenodeptr *> q;

    if(arvore != NULL)
    {
        q.push_back(arvore);

        while(q.empty() == false)
        {
            n = *q.begin();

            q.pop_front();

            if(n->esq != NULL)
            {
                q.push_back(n->esq);
            }
            if(n->dir != NULL)
            {
                q.push_back(n->dir);
            }
            cout << n->data << " ";
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

    emNivel(arvore);

    tDestruir(arvore);
    
    return 0;
}