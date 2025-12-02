#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	double x,y;
	
	cin>>x>>y;
	
	if(x>0 && y>0)
	{
		cout<<"Q1"<<endl;
	}
	
	if(x<0 && y>0)
	{
		cout<<"Q2"<<endl;
	}
	
	if(x<0 && y<0)
	{
		cout<<"Q3"<<endl;
	}
	
	if(x>0 && y<0)
	{
		cout<<"Q4"<<endl;
	}
	
	if(y==0 && x!=0)
	{
		cout<<"Eixo X"<<endl;
	}
	
	if(x==0 && y!=0)
	{
		cout<<"Eixo Y"<<endl;
	}
	
	if(x==0 && y==0)
	{
		cout<<"Origem"<<endl;
	}
	
	return 0;
}