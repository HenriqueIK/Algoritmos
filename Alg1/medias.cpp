#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()
{
	float a,b,c,d,e,m;
	
	cin>>a>>b>>c>>d;
	
	m=(a*2.0+b*3.0+c*4.0+d*1.0)/(10.0);
	
	cout<<fixed<<setprecision(1);
	
	cout<<"Media: "<<m<<endl;
	
	if(m>=7.0)
	{
		cout<<"Aluno aprovado."<<endl;
	}
	
	if(m<5.0)
	{
		cout<<"Aluno reprovado."<<endl;
	}
	
	if(m>=5.0 && m<7.0)
	{
		cout<<"Aluno em exame."<<endl;
		
		cin>>e;
		
		cout<<"Nota do exame: "<<e<<endl;
		if((e+m)/2.0 >= 5.0)
		{
			cout<<"Aluno aprovado."<<endl;
		}
		
		else
		{
			cout<<"Aluno reprovado."<<endl;
		}
		
		cout<<"Media final: "<<(m+e)/(2.0)<<endl;
		
	}
	
	return 0;
}