#include<iostream>

#include<iomanip>

#include<cmath>

#include<cstring>

using namespace std;

int main(){
//	
	int i, cont=0, cpfp;
	
	char rep, op;
	
	struct cadastro
	{
		char nome[81];
		
		int cpf;
		
		int idade;
	};
	cadastro dados[201];
	
	do{
	cout << "Digite o seu nome: " << endl;
	
	cin.getline(dados[cont].nome, 81);
	
	cout << "Digite seu CPF:" << endl;
	
	cin >> dados[cont].cpf;
	
	cout << "Digite sua idade( de 10 anos ate 80):" << endl;
	do{
		cin >> dados[cont].idade;
		if(dados[cont].idade < 10 || dados[cont].idade > 80){
			cout << "Idade incorreta, digite novamente..." << endl;
		}
	}while(dados[cont].idade < 10 || dados[cont].idade > 80);
	
	cout << "Digite 'C' para continuar ou 'S' para sair: " << endl;
	cin >> rep;
	cont++;
	}while(rep=='C' && cont<200);
	
	cout << "Para mostrar os dados de um participante especifico usando o cpf, digite 1" << endl;
	cout << "Para mostrar os dados de todos os participantes digite 2" << endl;
	cout << "Para finalizar o programa digite 3" << endl;
	
	do{
	cin >> op;
	
	switch(op){
		case 1:
			cout << "Digite o CPF do participante:" << endl;
			cin >> cpfp;
			for(i=0; i<cont; i++){
				if(cpfp == dados[i].cpf)
					cout << "Nome: " << "\t" << dados[i].nome << endl;
                    cout << "CPF: " << "\t" << dados[i].cpf << endl;
                    cout << "Idade: " << "\t" << dados[i].idade << endl;
			}
			break;
		case 2:
	 	for(i=0; i<cont; i++){
			 cout << "Nome: " << "\t" << dados[i].nome << endl;
			 cout << "CPF: " << "\t" << dados[i].cpf << endl;
			 cout << "Idade: " << "\t" << dados[i].idade << endl;
		 }
		   break;
		 case 3:
		 	break;
	}
	
	
	}while(op!=3);
	
	return 0;
}