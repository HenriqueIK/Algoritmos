#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int x,y,z;
	
	cin>>x>>y>>z;
	
	if(x>y && y>z)
	{
		cout<<z<<endl;
		
		cout<<y<<endl;
		
		cout<<x<<endl;
	}
	
	if(x>z && z>y)
	{
		cout<<y<<endl;
		
		cout<<z<<endl;
		
		cout<<x<<endl;
	}
	
	if(y>x && x>z)
	{
		cout<<z<<endl;
		
		cout<<x<<endl;
		
		cout<<y<<endl;
	}
	
	if(y>z && z>x)
	{
		cout<<x<<endl;
		
		cout<<z<<endl;
		
		cout<<y<<endl;
	}
	
	if(z>x && x>y)
	{
		cout<<y<<endl;
		
		cout<<x<<endl;
		
		cout<<z<<endl;
	}
	
	if(z>y && y>x)
	{
		cout<<x<<endl;
		
		cout<<y<<endl;
		
		cout<<z<<endl;
	}
	
	return 0;
}