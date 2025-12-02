#include<iostream>

#include<list>

using namespace std;

struct treenode
{
    int info;
    
    treenode *esq;
    
    treenode *dir;
};

typedef treenode *treenodeptr;

void insert(treenodeptr &arvore, int x)
{
    if (arvore == NULL)
    {
        arvore = new treenode;
        
        arvore->info = x;
        
        arvore->esq = NULL;
        
        arvore->dir = NULL;
    }
    
    else if (x < arvore->info)
	{
		insert(arvore->esq, x);
	}
	
    else
	{
		insert(arvore->dir, x);
	}
}

bool indenticas(treenodeptr arvore1, treenodeptr arvore2)
{
    if (arvore1 == NULL && arvore2 == NULL)
    {
        return true;
    }
    
    if (arvore1 == NULL || arvore2 == NULL)
    {
        return false;
    }
    
    return (arvore1->info == arvore2->info && indenticas(arvore1->esq, arvore2->esq) && indenticas(arvore1->dir, arvore2->dir));
}

bool irmaos(treenodeptr arvore, int a, int b)
{
    if (arvore == NULL)
    {
        return false;
    }
    
    if ((arvore->esq != NULL && arvore->esq->info == a && arvore->dir != NULL && arvore->dir->info == b) || (arvore->esq != NULL && arvore->esq->info == b && arvore->dir != NULL && arvore->dir->info == a) || 
	irmaos(arvore->esq, a, b) || irmaos(arvore->dir, a, b))
    {
        return true;
    }
    
    return false;
}

int main()
{
    treenodeptr arvore = NULL;
    
    treenodeptr p;
    
    int x;

    cin >> x;

    while (x != -1)
    {
        insert(arvore, x);
        
        cin >> x;
    }

    return 0;
}