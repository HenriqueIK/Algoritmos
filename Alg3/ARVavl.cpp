#include<iostream>

using namespace std;

struct treenode
{
	int numero;
	treenode *esq;
	treenode *dir;
	int altura;
};
typedef treenode *treenodeptr;

void tInsere(treenodeptr & arvore, int num)
{
    if (arvore == NULL)
    {
        arvore = new treenode;
        arvore->numero = num;
        arvore->dir = NULL;
        arvore->esq = NULL;
        arvore -> altura = 1;
    }
    else if(arvore -> numero > num)
	{
		tInsere(arvore -> esq, num);
    }
	else
	{
		tInsere(arvore -> dir, num);
    }
}

int altura(treenodeptr N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N->altura;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

treenodeptr novoNo(int num)
{
    treenodeptr no = new treenode();
    no->numero = num;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;
    return(no);
}

treenodeptr rotacaoDireita(treenodeptr y)
{
    treenodeptr x = y->esq;
    treenodeptr T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir))+1;
    x->altura = max(altura(x->esq), altura(x->dir))+1;

    return x;
}

treenodeptr rotacaoEsquerda(treenodeptr x)
{
    treenodeptr y = x->dir;
    treenodeptr T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir))+1;
    y->altura = max(altura(y->esq), altura(y->dir))+1;

    return y;
}

int getBalance(treenodeptr N)
{
    if (N == NULL)
    {
        return 0;
    }
    return altura(N->esq) - altura(N->dir);
}

treenodeptr tInsereAVL(treenodeptr no, int num)
{
    if (no == NULL)
    {
        return(novoNo(num));
    }
    if (num < no->numero)
    {
        no->esq  = tInsereAVL(no->esq, num);
    }
    else if (num > no->numero)
    {
        no->dir = tInsereAVL(no->dir, num);
    }   
    else
    {
        return no;
    }

    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    int balance = getBalance(no);


    if (balance > 1 && num < no->esq->numero)
    {
        return rotacaoDireita(no);
    }
    if (balance < -1 && num > no->dir->numero)
    {
        return rotacaoEsquerda(no);
    }
    if (balance > 1 && num > no->esq->numero)
    {
        no->esq =  rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }
    if (balance < -1 && num < no->dir->numero)
    {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}


int tPesq(treenodeptr &arvore, int num, int &cont) // funcao que pesquisa um numero na arvore binaria e retorna o numero de chamadas recursivas
{
	if(arvore == NULL)
    {
		return cont;
	}
    else if(arvore -> numero > num)
    { 
		cont++;
		return tPesq(arvore -> esq, num, cont);
    }
	else if(arvore -> numero < num)
    {
		cont++;
		return tPesq(arvore -> dir, num, cont);
    }
	else
    {
		return cont;
	}
}

int main()
{
    treenodeptr arvore = NULL;
    
    treenodeptr arvoreAVL = NULL;

	int num;

	int x;

	int cont = 1;

	cin >> num;

	while(num != 0)
    {
		tInsere(arvore, num);
		arvoreAVL = tInsereAVL(arvoreAVL, num);
		cin >> num;
	}

	cin >> x;

	cout << "Arvore normal: " << tPesq(arvore, x, cont) << endl;

	cont = 1;

	cout << "AVL: " << tPesq(arvoreAVL, x, cont) << endl;
    
    return 0;
}