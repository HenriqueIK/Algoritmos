#include <iostream>

#include <list>

using namespace std;

int soma(list<int> lista)
{
	list<int>::iterator p;
	
	int soma = 0;
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		soma += *p;
	}
	
	return soma;
}

int main()
{
	list<int> fila;
	
	int x;
	
	int r;
	
	cin >> x;
	
	while(x != 0)
	{
		fila.push_back(x);
		
		cin >> x;
	}
	
	r = soma(fila);
	
	cout << r << endl;
	
	while(!fila.empty()) // liberando espaco alocado na memoria
	{
		fila.pop_front();
	}
	
	return 0;
}