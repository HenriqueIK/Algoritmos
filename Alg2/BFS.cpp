#include<iostream>

#include<list>

using namespace std;

struct no
{
	int v; // vertice adjacente
	
	int peso; // peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux;
	
	aux.v = v;
	
	aux.peso = p;
	
	adj[u].push_back(aux);
	
	if(orientado == 0)
	{
		aux.v = u;
		
		adj[v].push_back(aux);
	}
}

void bfs(list<no>adj[], int nVertices, int s)
{
	char state[20];
	
	int v, pai[20];
	
	int u;
	
	list<no>::iterator p;
	
	list<int>q;

	for( u = 0; u < nVertices;  u++)
	{
		state[u] = 'u'; // undiscovered
		
		pai[u] = -1; // sem pais
	}
	
	state[s] = 'd'; // discovered
	
	pai[s] = -1;
	
	q.push_back(s);
	
	while(!q.empty())
	{
		u = *q.begin();
		
		q.pop_front();
		
		cout << u << endl;
		
		for(p = adj[u].begin(); p != adj[u].end(); p++)
		{
		    v = p-> v;
		    
			cout << u << " " << v << endl;
			
			if(state[v] == 'u')
			{
				state[v] = 'd';
				
				pai[v] = u;
				
				q.push_back(v);
			}
		}
		state[u] = 'p'; // processed
	}
}

int main()
{
	list<no>adj[10]; // lista de adjacencia
	
	int u, v; // origem e destino
	
	int p; // peso da aresta
	
	no aux; // struct aux para inserir as arestas
	
	list<no>::iterator q; // iterator para mostrar a lista de adjacencias
	
	int i; // contador
	
	int nVertices; // # de vertices do grafo
	
	int orientado = 0; // 1: orientado, 0: nao orientado
	
	int s;
	
	cin >> nVertices >> orientado;
	
	cin >> u >> v >> p;
	
	while(u != -1 && v != -1 && p != -1)
	{
	    cria_aresta(adj,u,v,p,orientado);
	    
	    cin >> u >> v >> p;
	}
	
	bfs(adj, nVertices,s);
	
	return 0;
}