#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	float salario,resto,resultado;
	
	cin>>salario;
	
	cout<<fixed<<setprecision(2)<<endl;
	
	if(salario<=2000)
	{
		cout<<"Isento"<<endl;
	}
	
	else if(salario<=3000)
	{
		resto=salario-2000;
		
		resultado=resto*0.08;
		
		cout<<"R$ "<<resultado<<endl;
	}
	
	else if(salario<4500)
	{
		resto=salario-3000;
		
		resultado=(resto*0.18)+(1000*0.08);
		
		cout<<"R$ "<<resultado<<endl;
	}
	
	else
	{
		resto=salario-4500;
		
		resultado=(resto*0.28)+(1500*0.18)+(1000*0.08);
		
		cout<<"R$ "<<resultado<<endl;
	}
	
	return 0;
}