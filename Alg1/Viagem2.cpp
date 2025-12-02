#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int X, Y, C;
	
	double P, R$;
	
	cout<<"Notas"<<endl;
	
	cin>>X;
	
	cout<<"Reais"<<endl;
	
	cin>>Y;
	
	cout<<"Chocolates"<<endl;
	
	cin>>C;
	
	cout<<"Preco"<<endl;
	
	cin>>P;
	
	cout<<fixed<<setprecision(2);
	
	R$=X*Y-C*P;
	
	cout<<"R$ "<<R$<<endl;
	
	return 0;
}