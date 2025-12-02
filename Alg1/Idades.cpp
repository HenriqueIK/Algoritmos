#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	char nome1[20];
	
	char nome2[20];
	
	int idade1;
	
	int idade2;
	
	cout<<"Digite seu nome"<<endl;
	
	cin.getline(nome1, 20);
	
	cout<<"Digite sua idade"<<endl;
	
	cin>>idade1;
	
	cout<<"Digite seu nome2"<<endl;
	
	cin.ignore();
	cin.getline(nome2, 20);
	
	cout<<"Digite sua idade2"<<endl;
	
	cin>>idade2;
	
	if (idade1>idade2)
		cout<<nome1;
    else if (idade2>idade1)
	{
		cout<<nome2;
	}
	
	else if (idade1=idade2)
	{
		cout<<"Idades iguais";
	}
	
	return 0;
}