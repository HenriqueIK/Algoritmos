#include <iostream>

#include <list>

using namespace std;

int contar(list<int> lista)
{
	list<int>::iterator p; // ponteiro para ler a lista
	
	int cont = 0;
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		cont ++;
	}
	
	return cont;
}

int main()
{
	list<int> fila;
	
	int x;
	
	int r;
	
	cin >> x;
	
	while(x != 0) // lendo os valores de x ate zero
	{
		fila.push_back(x);
		
		cin >> x;
	}
	
	r = contar(fila);
	
	cout << r << endl;
	
	while(!fila.empty()) // liberando espaco alocado na memoria
	{
		fila.pop_front();
	}
	
	return 0;
}