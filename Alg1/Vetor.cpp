#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std;

int main() 
{
    int N;
    
    double A[10];
    
    int X;
    
    int cont1,cont2;
    
    cont1=0;
    
    cont2=0;
    
    cin >> N;

    for(int i=1;i<=N;i++)
	{
    	cin>>A[N];
    }
    
    cin>>X;
    
    for(int i=1;i<=N;i++)
	{
        if(X==A[N])
		{
            cont1++;
        }
        
    	if(X!=A[N])
		{
		   	cont2++;
    	}
    }
    
    if(cont1==1)
	{
        cout<<"Valor pertence ao vetor"<<endl;
    }
    
    if(cont2<=N)
	{
        cout << "Valor nao pertence ao vetor" << endl;
    }
	
	//n�o consegui terminar
	
	return 0;
	
}