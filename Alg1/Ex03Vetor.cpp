#include<iostream>

#include<iomanip>

#include<cmath>

#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int i,N;
	
	char nome[10][31];
	
	double a[10];
	
	double e[10];
	
	double t[10];
	
	double p[10];
	
	int maior=0;
	
	cout<<"Número de equipes (1-10)"<<endl;
	
	do
	{
		cin>>N;
		
		if(N>10 || N<0)
		{
			cout<<"Número inválido, Digite novamente"<<endl;
			
			cout<<"Número de equipes (1-10)"<<endl;
		}
		
	}while(N<0 || N>10);
	
	for(i=0;i<N;i++)
	{
		cout<<"Equipe: ";
		
		cin>>nome[i];
		
		cout<<"Tentativas certas: ";
		
		cin>>a[i];
		
		cout<<"Tentativas erradas: ";
		
		cin>>e[i];
		
		cout<<"Tempo gasto (min): ";
		
		cin>>t[i];
		
		p[i]=(5*a[i]+2*e[i]+1)/t[i];
		
		cout<<endl;
	}
	
	cout<<"Listagem final: "<<endl;
	
	cout<<fixed<<setprecision(1)<<endl;
	
	for(i=0;i<N;i++)
	{
		cout<<nome[i]<<" - "<<p[i]<<" ptos."<<endl;
	}
	
	for(i=0;i<N;i++)
	{
		if(maior<p[i])
		{
			maior=p[i];
		}
	}
	
	cout<<endl;
	
	cout<<"Maior pontuação: "<<maior<<" ptos."<<endl;
	
	for(i=0;i<N;i++)
	{
		if(maior==p[i])
		{
			cout<<"Equipe(s) vencedora(s): "<<nome[i]<<endl;
		}
	}
	
	return 0;
}