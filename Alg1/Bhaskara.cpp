#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	
	double A, B, C;
	
	double X1, X2, D;
	
	cout<<"A"<<endl;
	
	cin>>A;
	
	cout<<"B"<<endl;
	
	cin>>B;
	
	cout<<"C"<<endl;
	
	cin>>C;
	
	D = pow(B, 2) - 4*A*C;
	
	X1 = (((-B) + sqrt(D))/(2*A));
	
	X2 = (((-B) - sqrt(D))/(2*A));
	
	if(A>0 && D>0)
	{
		cout<<fixed<<setprecision(5);
		cout<<"X1 ="<<X1<<endl;
		cout<<"X2 ="<<X2<<endl;
	}
	else
	{
		cout<<"Impossivel"<<endl;
	}
	
	return 0;
}
