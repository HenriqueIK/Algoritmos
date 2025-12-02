#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int X, Y;
	
	double Z, Z1;
	
	cout<<"X"<<endl;
	
	cin>>X;
	
	cout<<"Y"<<endl;
	
	cin>>Y;
	
	if (X<Y);
	{
		Z1=X+2*Y/3+X;
		
		Z=pow(Z1/3);
	}
	else if (X=Y);
	{
		Z=X*X*X-X*Y+sqrt(Y);
	}
	else if (X>Y);
	{
		Z=-X+sqrt(X*X-4*Y)/2*Y
	}
	
	cout<<Z<<endl;
	
	return 0;
}