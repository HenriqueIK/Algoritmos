#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	double Q1;
	
	double Q2;
	
	double d;
	
	double F;
	
	cin>>Q1;
	
	cin>>Q2;
	
	cin>>d;
	
	F=(9*pow(10,9))*((sqrt(Q1*Q1)*sqrt(Q2*Q2))/(d*d));
	
	cout<<F<<endl;
	
	return 0;
}