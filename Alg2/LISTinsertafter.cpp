#include<iostream>

#include<list>

using namespace std;

int main() 
{
    list<int> lista;

    int n; // numero para colocar na lista
    
    int x;
    
    int y;
    
    cin >> n;

    while(n != -1) 
	{
        lista.push_front(n); //formato pilha
        
        cin >> n;
    }
    
    cin >> x >> y;
    
    list<int>::iterator p = lista.begin(); // ponteiro para a lista
    
    while(p != lista.end()) 
	{
        if (*p == x)
		{
            p++;
            
            lista.insert(p, y);
            
            break;
        }
        
		p++;
    }
    
    for(list<int>::iterator p = lista.begin(); p != lista.end(); p++) 
	{
        cout << *p << " ";
    }
    
    return 0;
}