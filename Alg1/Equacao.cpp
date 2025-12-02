#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	double x,s;
	
	cout<<"Digite o valor de x"<<endl;
	
	cin>>x;
	
	cout<<fixed<<setprecision(2);
	
	s = (x*x*x-x*x)*sqrt(x);
	
	cout<<"Valor da equacao"<<endl;
	
	cout<<s<<endl;
	
	return 0;
}
