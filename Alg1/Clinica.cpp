#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	double Idade, Altura, Peso, IMC;
	
	char nome[20];
	
	cout<<"Idade"<<endl;
	
	cin>>Idade;
	
	cout<<"Nome"<<endl;
	
	cin.ignore();
	
	cin.getline(nome, 20);
	
	cout<<"Altura(m)"<<endl;
	
	cin>>Altura;
	
	cout<<"Peso(kg)"<<endl;
	
	cin>>Peso;
	
	IMC=Peso/pow(Altura, 2)
	
	;cout<<"Nome: "<<nome<<endl;
	
	cout<<"Idade: "<<Idade<<endl;
	
	cout<<fixed<<setprecision(2);
	
	cout<<"IMC : "<<IMC<<" kg/m^2"<<endl;
	
	if 	(IMC<=15)
		cout<<"Extremamente abaixo do peso";
	else if (IMC<=16)
	{
		cout<<"Gravemente abaixo do peso";
	}
	
	else if (IMC<=18.5)
	{
		cout<<"Abaixo do peso ideal";
	}	
	
	else if (IMC<=25)
	{
		cout<<"Peso ideal";
	}
	
	else if (IMC<=30)
	{
		cout<<"Sobrepeso";
	}
	
	else if (IMC<=35)
	{
		cout<<"Obesidade de grau I";
	}
	
	else if (IMC<=40)
	{
		cout<<"Obesidade de grau II (grave)";
	}
	
	else if (IMC>40)
	{
		cout<<"Obesidade de grau III (m�rbida)";
	}
	
	return 0;
}
