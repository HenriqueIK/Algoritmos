#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int i,cont1,x;
	cont1=0;
	
	for(i=1;i<=5;i++)
	{
		cin>>x;
		
		if(x%2==0)
		{
			cont1++;
		}
	}
	
	cout<<cont1<<" valores pares"<<endl;
	
	return 0;
}
