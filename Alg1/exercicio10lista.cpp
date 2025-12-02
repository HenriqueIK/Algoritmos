#include<iostream>

#include<cmath>

#include<iomanip>

using namespace std;

int main(int argc, char** argv)
{
	int i;
	
	int N; //numero de funcionarios
	
	int F; //faltas
	
	double S; //salario
	
	cin>>N;
	
	for(i=0;i<N;i++)
	{
		cin>>S;
		
		cin>>F;
		
		if(S<=1000)
		{
			if(F<=5)
			{
				cout<<S+S*0.1<<endl;
			}
			
			if(F>5 && F<=12)
			{
				cout<<S+S*0.05<<endl;
			}
			
			if(F>12)
			{
				cout<<S<<endl;
			}
		}
		
		else if(S>1000 || S<=3000)
		{
			if(F<=5)
			{
				cout<<S+S*0.075<<endl;
			}
			
			if(F>5 && F<=12)
			{
				cout<<S+S*0.04<<endl;
			}
			
			if(F>12)
			{
				cout<<S<<endl;
			}
		}
		
		else if(S>3000)
		{
			if(F<=5)
			{
				cout<<S+S*0.03<<endl;
			}
			
			if(F>5)
			{
				cout<<S<<endl;
			}
		}
	}
	return 0;
}