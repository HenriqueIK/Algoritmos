#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int A, B, C;
	
	double V1, V2, V3;
	
	cout<<"Modelo 1"<<endl;
	
	cin>>A;
	
	cout<<"Modelo 2"<<endl;
	
	cin>>B;
	
	cout<<"Modelo 3"<<endl;
	
	cin>>C;
	
	V1=10.0*A-(4/3)*A;
	
	V2=10.0*B-(4/3)*B;
	
	V3=10.0*C-(4/3)*C;
	
	if(V1>V2 && V1>V3)
	{
		cout<<"Moto 1"<<endl;
	}
	else if(V2>V3 && V2>V1)
	{
		cout<<"Moto 2"<<endl;
	}
	else if(V3>V2 && V3>V1)
	{
		cout<<"Moto 3"<<endl;
	}
	
	return 0;
}
