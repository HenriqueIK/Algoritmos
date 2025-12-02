#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int N,i,j=0,k=0;
	
	double VET[10];
	
	double POS[10];
	
	double NEG[10];
	
	do
	{
		cin>>N;
	}
	while(N<1 || N>10);

	for(i=0;i<N;i++)
	{
		cin>>VET[i];
	}
	
	for(i=0;i<N;i++)
	{
		if(VET[i]>=0)
		{
			POS[j]=VET[i];
			
			j++;
		}
		if(VET[i]<0)
		{
			NEG[k]=VET[i];
			
			k++;
		}
	}
	
	for(i=0;i<j;i++)
	{
		cout<<"Positivos = "<<POS[i]<<endl;
	}
	
	for(i=0;i<k;i++)
	{
		cout<<"Negativos = "<<NEG[i]<<endl;
	}
	
	return 0;
}