#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	
	char nome[20];
	
	int N;
	
	double R;
	
	cout<<"Nome"<<endl;
	
	cin.getline(nome, 20);
	
	cout<<"Numero de morangos"<<endl;
	
	cin>>N;
	
	cout<<fixed<<setprecision(2);
	
	R = N*2.908;
	
	cout<<nome<<endl;
	
	cout<<"R$: "<<R;
	
	return 0;
}
