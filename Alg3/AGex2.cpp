#include <iostream>

#include <cmath>

#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};

typedef ponto vetor; 

struct reta
{
	ponto A;
	ponto B;
};

typedef reta segmento;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

int lado(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float vet;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	vet = vetorial(AB, AC);

	if(vet > 0)
    {
        return 1;
    }
	else if(vet < 0)
    {
        return -1;
    }
		
	else
    {
        return 0;
    }
}

int main()
{
	ponto a, b;
	a.x = 1;
	a.y = 2;
	b.x = 3;
	b.y = 4;

	ponto p;

	cin >> p.x;

	cin >> p.y;

	cout << endl;

	int resp = lado(a, b, p); // Posicao de C em relacao ao segmento AB / 1 -> esquerda / -1 -> direita / 0 -> colinear

	cout << endl;

	if(resp == 1)
	{
		cout << "esquerda" << endl;
	}

	else if(resp == -1)
	{
		cout << "direita" << endl;
	}

	else if(resp == 0)
	{
		cout << "colinear" << endl;
	}

	return 0;
}