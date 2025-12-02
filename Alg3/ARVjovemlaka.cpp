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

void posicaoPreOrdem (treenodeptr * arvore, int & PRE, int cidade, int & x)
{
	if (arvore != NULL)
	{
		if(arvore->data == cidade)
        {
            x = PRE;
        }
		else
        {
            PRE++;

		    posicaoPreOrdem(arvore->esq, PRE, cidade, x);

		    posicaoPreOrdem(arvore->dir, PRE, cidade, x);
        }		
	}
}

void posicaoEmOrdem (treenodeptr * arvore, int &EM, int cidade, int &x)
{
	if (arvore != NULL)
	{
		posicaoEmOrdem(arvore->esq, EM, cidade, x);

		if(arvore->data == cidade)
        {
            x = EM;
        }
		else
        {
            EM++;
		    posicaoEmOrdem(arvore->dir, EM, cidade, x);
        }	
	}
}

void posicaoPosOrdem (treenodeptr * arvore, int &POS, int cidade, int &x)
{
	if (arvore != NULL)
	{
		posicaoPosOrdem(arvore->esq, POS, cidade, x);

		posicaoPosOrdem(arvore->dir, POS, cidade, x);

		if(arvore->data == cidade)
        {
            x = POS;
        }
		else
        {
            POS++;
        }	
	}
}

int melhorCaminho(treenodeptr * arvore, int cidade)
{
	int PRE = 0;

	int EM = 0;

	int POS = 0;

	int aux = 0; 

	posicaoPreOrdem(arvore, PRE, cidade, aux);
	PRE = aux;
	posicaoEmOrdem(arvore, EM, cidade, aux);
	EM = aux;
	posicaoPosOrdem(arvore, POS, cidade, aux);
	POS = aux;

	if(PRE < POS && PRE < EM)
    {
        aux = 1;
    }
	else if(EM < POS && EM < PRE)
    {
        aux = 2;
    }
	else if(POS < PRE && POS < EM)
    {
        aux = 3;
    }

	return aux;
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

    int cidade;

    int melhor_caminho;

    cin >> N;

    while(N != -1)
    {
        tInsere(arvore, N);

        cin >> N;
    }

    cin >> cidade;

    melhor_caminho = melhorCaminho(arvore, cidade);

    if(melhor_caminho == 1)
    {
        cout << "Pre" << endl;
    } 
    else if(melhor_caminho == 2)
    {
        cout << "Em" << endl;
    } 
    else if(melhor_caminho == 3)
    {
        cout << "Pos" << endl;
    }

    tDestruir(arvore);
    
    return 0;
}