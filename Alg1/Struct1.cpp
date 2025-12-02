#include<iostream>

#include<iomanip>

#include<cmath>

#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	struct ficha
	{
		int idade;
		
		char nome[51];
		
		char raca[31];
	};
	
	ficha dados[101];
	
	int i,N;
	
	do
	{
		cin>>N;
		
	}while(N<0 || N>100);
	
	for(i=0;i<N;i++	)
	{
		cout<<"Digite o nome: "<<endl;
		
		cin.ignore();
		cin.getline(dados[i].nome, 51);
		
		cout<<"Digite a raça"<<endl;
		
		cin.getline(dados[i].raca, 31);
		
		cout<<"Digite a idade: "<<endl;
		
		cin>>dados[i].idade;
	}
	
	for(i=0;i<N;i++)
	{
		cout<<"Nome: "<<dados[i].nome<<endl;
		
		cout<<"Raça: "<<dados[i].raca<<endl;
		
		cout<<"Idade: "<<dados[i].idade<<endl;
	}
	
	return 0;
}