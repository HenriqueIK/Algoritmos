#include<iostream>

#include<iomanip>

#include<cmath>

#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	struct ficha
	{
		int integrantes;
		
		char banda[61];
		
		char pr[2];
	};
	
	ficha dados[101];
	
	int i,N;
	
	int cont1,cont2;
	
	char op[2];
	
	do
	{
		cin>>N;
		
	}while(N<0 || N>100);
	
	for(i=0;i<N;i++)
	{
		cout<<"Digite o nome da banda: "<<endl;
		
		cin.ignore();
		cin.getline(dados[i].banda, 61);
		
		cout<<"Digite o número de integrantes: "<<endl;
		
		cin>>dados[i].integrantes;
	}
	
	cout<<"Digite o estilo musical, P para pop e R para rock: "<<endl;
	do
	{
		cin.getline(dados[i].pr, 2);
	}
	
	switch(pr)
	{
		case 'P':
		{
			cont1++;
			
			break;
		}
		
		case 'R':
		{
			cont2++;
			
			break;
		}
	}
	
	cout<<"Digite 1 para mostrar o nome de todas as bandas cadastradas"<<endl;
	
	cout<<"Digite 2 para mostrar o nome das bandas do estilo rock (R)"<<endl;
	
	cout<<"Digite 3 para mostrar o nome das bandas do estilo pop (P)"<<endl;
	
	cout<<"Digite 4 para encerrar o programa"<<endl;
	
	cin.getline(op, 2);
	
	case '1':
	{
		cout<<
	}
	
	return 0;
}