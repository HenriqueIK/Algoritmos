#include<iostream>

#include<list>

using namespace std;

bool encontrar(list<int> lista, int x)
{
	list<int>::iterator p;
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(*p == x)
		{
			return true;
		}
	}
	
	return false;
}

int main()
{
	list<int> fila; // ponteiro para a fila
	
	int x;
	
	int N;
	
	bool r;
	
	cin >> N;
	
	while(N != 0)
	{
		fila.push_back(N);
		
		cin >> N;
	}
	
	cin >> x;
	
	r = encontrar(fila, x);
	
	if(r)
	{
		cout << "Encontrado" << endl;
	}
	
	else
	{
		cout << "Nao encontrado" << endl;
	}
	
	while(!fila.empty())
	{
		fila.pop_front();
	}
	
	return 0;
}