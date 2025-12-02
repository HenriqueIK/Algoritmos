#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	double sf, v, s;
	
	char nome[20];
	
	cout<<"Digite seu nome"<<endl;
	
	cin.getline(nome, 20);
	
	cout<<"Digite seu salario fixo"<<endl;
	
	cin>>sf;
	
	cout<<"Digite o valor total das vendas"<<endl;
	
	cin>>v;
	
	cout<<fixed<<setprecision(2);
	
	s=(v*0,15)+sf;
	
	cout<<"TOTAL = R$"<<s<<endl;
	
	return 0;
}
