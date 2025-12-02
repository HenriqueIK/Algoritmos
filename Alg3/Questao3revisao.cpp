#include<iostream>

#include<string>

#define ITENS 14

#define CAP 2000

using namespace std;

int solucao[ITENS] [CAP];

int peso[ITENS]{600,550,525,530,510,413,210,210,190,180,55,30,25,23};

int valor[ITENS] = {3,3,3,2,2,2,2,1,1,1,1,1,0,0};

int mochila(int item, int capacidade)
{
	if(item >= ITENS)
	{
		return 0;
	}
	
	if(solucao[item] [capacidade] != -1)
	{
		return solucao[item] [capacidade];
	}

	// escolher o item atual

	int ansi = 0;

	if(capacidade >= peso[item])
	{
		ans1 = mochila(item+1, capacidade - peso[item]) + valor[item];
	}

	// não escolhi

	int ans2 = mochila(item+1, capacidade);

	int ans = max(ansi, ans2);

	solucao[item] [capacidade] = ans;
	
	return ans;
}

void lista escolhidos()
{
	string restaurante[ITENS] = 
	{
	   	"Poison Frit",
	   	"Sal&Pimenta",
	   	"Umami",
	   	"Saboroso",
	   	"Tiramisu",
	   	"Golden Food",
	   	"Salivante",
	   	"Rei do peixe",
	   	"Buteco do Joao",
	   	"Maria's",
	   	"Mar&Terra Gastrobar",
	   	"Boia",
  	   	"Prato&Marmita",
	   	"PF do Zezinho"
	};
	
	int gasto = O;
	
	int x = CAP;
	
	int j=0;
	
	while(j<ITENS)
	{
		if(solucao[j][x] == solucao[j+1][x-peso[j]]+valor[3])
		{
		cout<< restaurante[j] << endl;
		
		gasto += peso[j];
		
		x=x- peso[j];
		}
		j+n+;
	}
	
	cout<<"Gasto total: R$ "<<gasto<<",00"<<endl;
}

int main()
{
	for(int i=0; i<ITENS; i++)
	{
		for(int j=0; j<=CAP; j++)
		{
			solucao[i][3] = -1;
		}
	}
	
	cout << mochila(0, CAP) << endl;
			
	lista escolhidos();
	
	return 0;
}

// Questao 3)a) Umami, Sal&Pimenta, Poison Frit, Salivante, Boia, Mar&Terra, Gastrobrar e PF do Zezinho, total 1993,
// 13 estrelas ao todo e 7 restaurantes

// Questao 3)b) Um algoritmo de complexidade O(n)

// Questao 3)c) Umami, Sal&Pimenta, Poison Frit, Salivante, Boia, Mar&Terra, Gastrobrar e PF do Zezinho