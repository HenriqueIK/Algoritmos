#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	double X, Y, Z, D, L, E; 
	
	cout<<"Dolar"<<endl;
	
	cin>>X;
	
	cout<<"Libra"<<endl;
	
	cin>>Y;
	
	cout<<"Euro"<<endl;
	
	cin>>Z;
	
	cout<<fixed<<setprecision(2);
	
	D = X/4.04;
	
	L = Y/5.32;
	
	E = Z/4.60;
	
	cout<<"Dolar: "<<D<<endl;
	
	cout<<"Libra: "<<L<<endl;
	
	cout<<"Euro: "<<E<<endl;
	
	return 0;
}
