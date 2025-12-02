#include<iostream>
#include<iomanip>

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

int contarNos(treenodeptr * arvore)
{ 
    if (arvore == NULL) 
	{
        return 0;
    } 
	else 
	{
        return 1 + contarNos(arvore->esq) + contarNos(arvore->dir);
    }
}
int somaNos(treenodeptr * arvore) 
{
    if (arvore == NULL) 
	{
        return 0;
    }
	 else 
	{
        return arvore->data + somaNos(arvore->esq) + somaNos(arvore->dir);
    }
}

float media(treenodeptr * arvore)
{
    if (arvore == NULL) 
	{
        return 0.0;
    } 
	else 
	{
        int sum = somaNos(arvore);
        
        int count = contarNos(arvore);
        
        if (count == 0) 
		{
            return 0.0;
        } 
		else 
		{
            return (float)sum / count;
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

    cout << fixed << setprecision(2) << "Media: " << media(arvore) << endl;
    
    return 0;
}