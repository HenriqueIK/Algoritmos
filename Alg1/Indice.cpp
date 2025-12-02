#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	char nome[20];
	
	double idade;
	
	double ind;
	
	cout<<"Digite seu nome"<<endl;
	
	cin.getline(nome, 20);
	
	cout<<"Digite sua idade"<<endl;
	
	cin>>idade;

	ind = idade*1/42-(idade-3);
	
	cout<<idade<<endl;
	
	cout<<nome<<endl;
	
	cout<<"Ind = ";
	
	cout<<fixed<<setprecision(4);
	
	cout<<ind<<endl;
	
	return 0;
}
