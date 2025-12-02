#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int X, Y;
	
	cout<<"X"<<endl;
	
	cin>>X;
	
	cout<<"Y"<<endl;
	
	cin>>Y;
	
	if (X%Y==0)
		cout<<"Sim"<<endl;
	else
	{
		cout<<"Nao"<<endl;
	}
	return 0;
}
