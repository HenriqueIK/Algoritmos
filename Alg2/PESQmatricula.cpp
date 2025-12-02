#include <iostream>

#include <iomanip>

#include <cstring>

using namespace std;

int main()
{
	int N;
	
	int i;

	char proc[50];

	struct cadastro
	{
		char nome[50]; // nome do aluno

		char c[20]; // curso do aluno

		int cod; // numero de matricula do aluno
	};

	cadastro dados[10000];

	int achou = 0; // variavel de busca

	do
	{
		cin >> N;

	}
	while (N < 1 || N > 10000);

	for(i = 0; i < N; i++)
	{
		cin.ignore();
		
		cin.getline(dados[i].nome, 50);
		
		cin.getline(dados[i].c, 20);
		
		cin >> dados[i].cod;
		
		cout << endl;
	}
	
	cin.ignore();

	cin.getline(proc, 50); // procurando aluno

	for(i = 0; i < N; i++)
	{
		if(strcmp(proc, dados[i].nome) == 0)
		{
			cout << endl;
			
			cout << dados[i].nome << endl;
			
			cout << dados[i].c << endl;
			
			cout << dados[i].cod << endl;
			
			achou++;
		}
	}
	
	if(achou == 0)
	{
		cout << "Aluno nao localizado" << endl;
	}
	
	return 0;
}