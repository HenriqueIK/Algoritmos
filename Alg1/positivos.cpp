#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	int i,cont1;
	
	float x,m;
	
	cont1=0;
	
	for(i=1;i<=6;i++)
	{
		cin>>x;
		
		if(x>0)
		{
			cont1++;
		}
		
		m=m+x;
		
	}
	
	cout<<cont1<<" valores positivos"<<endl;
	
	cout<<fixed<<setprecision(1);
	
	cout<<m/cont1<<endl;
	
	return 0;
}