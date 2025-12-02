#include <iostream>

#include <list>

using namespace std;

int main()
{
	list<int> L1; // lista 1
	
	list<int> L2; // lista 2
	
	list<int> L3; // lista 3
	
	list<int>::iterator p1; // ponteiro para a lista 1
	
	list<int>::iterator p2; // ponteiro para a lista 2
	
	list<int>::iterator p3; // ponteiro para a lista 3
	
	int x;
	
	cin >> x; // colocando dados na lista 1
	
	while(x != 0)
	{
		L1.push_back(x);
		
		cin >> x;
	}
	
	cin >> x; // colocando dados na lista 2
	
	while(x != 0)
	{
		L2.push_back(x);
		
		cin >> x;
	}
	
	p1 = L1.begin(); // apontando o ponteiro 1 para o comeco da lista 1
	
	p2 = L2.begin(); // apontando o ponteiro 2 para o comeco da lista 2
	
	// unindo as listas
	do
	{
		if(*p1 == *p2)
		{
			L3.push_back(*p1);
			
			p1++;
			
			p2++;
		}
		else if(*p1 < *p2 || p2==L2.end())
		{
			L3.push_back(*p1);
			
			p1++;
		}
		else if(*p1 > *p2 || p1==L1.end())
		{
			L3.push_back(*p2);
			
			p2++;
		}
	}
	
	while(p1 != L1.end() || p2 != L2.end());
	{
		for(p3 = L3.begin(); p3 != L3.end(); p3++)
		{
			cout << *p3 << " ";
		}
	}
	
	while(!L1.empty())
	{
		L1.pop_front();
	}
	while(!L2.empty())
	{
		L2.pop_front();
	}
	while(!L3.empty())
	{
		L3.pop_front();
	}
	//liberando a memoria alocada

	return 0;
}