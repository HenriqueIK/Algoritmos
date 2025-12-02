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
    
    adj[u].push_back(aux); // insere a aresta no grafo
    
    if(orientado == 0)
    {
        aux.v = u;
        
        adj[v].push_back(aux);
    }
}

int main()
{
    list<no> adj[10]; // lista de adjac�ncias
    
	int u, v; // origem e destino
	
	int p; // peso de uma aresta
	
	no aux; // struct auxiliar para inserir as arestas
	
	list <no>:: iterator q; // iterator para mostrar a lista de adjac�ncias
	
	int i; // contador
	
	int nVertices; // # de vertices do grafo
	
	int orientado; // 1: orientado, 0: nao orientado
	
	cin >> nVertices >> orientado;
	
	cin >> u >> v >> p;
	
	while(u != -1 && v != -1 && p != -1)
	{
	    cria_aresta(adj,u,v,p,orientado);
	    
	    cin >> u >> v >> p;
	}
	
	for(i = 0; i < nVertices; i++)
	{
		for(q = adj[i].begin(); q != adj[i].end(); q++)
		{
			cout << i << " " << q->v << " " << q->peso << endl;
		}
	}
	
    return 0;
}