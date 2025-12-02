#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int Q1, Q2, D;
	
	double F;
	
	cout<<"Digite o valor de Q1"<<endl;
	
	cin>>Q1;
	
	cout<<"Digite o valor de Q2"<<endl;
	
	cin>>Q2;
	
	cout<<"Digite o valor de D"<<endl;
	
	cin>>D;
	
	cout<<fixed<<setprecision(2);
	
	F = 100*(Q1*Q2/D*D);
	
	cout<<"F = ";
	
	cout<<F<<endl;
	
	return 0;
}
