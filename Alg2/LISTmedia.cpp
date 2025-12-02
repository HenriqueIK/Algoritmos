#include <iostream>

#include <iomanip>
 
#include <list>

using namespace std;

float calcMedia(list<int> lista)
{
	list<int>::iterator p;
	
	int x = 0;
	
	int cont = 0;
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		x += *p;
		
		cont ++;
	}
	
	return (float)x/cont;
}

int main()
{
	list<int> lista;
	
	int x;
	
	float med;
	
	cin >> x;
	
	while(x != 0)
	{
		lista.push_back(x);
		
		cin >> x;
	}
	
	med = calcMedia(lista);
	
	cout << fixed << setprecision(2);

	cout << med;
	
	while(!lista.empty()) // liberando espaco alocado na memoria
	{
		lista.pop_front();
	}
	
	return 0;
}