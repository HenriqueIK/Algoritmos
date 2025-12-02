#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int i;
	
	int N;
	
	int P;
	
	int fat=1;
	
	int fat2=1;
	
	cin>>N;
	
	cin>>P;
	
	if(N<0 && P<0 && N<=P)
	{
		cout<<"Erro de saída"<<endl;
	}
	
	int X=N-P;
	
	for(i=1;i<N;i++)
	{
		fat*=fat*i;
	}
	
	for(i=1;i<X;i++)
	{
		fat2*=fat2*i;
	}
	
	cout<<fat/fat2<<endl;
	
	return 0;
}