#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int v[10];
	
	int i,N,a,k;
	
	do
	{
		cin>>N;
	}while(N<0 || N>10);
	
	for(i=0;i<N;i++)
	{
		cin>>v[i];
	}
	
	for(k=N-1;k>0;k--)
	{
		for(i=0;i<k;i++)
		{
			if(v[i]>v[i+1])
			{
				a=v[i];
				
				v[i]=v[i+1];
				
				v[i+1]=a;
			}
		}
	}
	
	cout<<"Crescente = "<<endl;
	
	for(i=0;i<N;i++)
	{
		cout<<v[i]<<endl;
	}
	
	return 0;
}