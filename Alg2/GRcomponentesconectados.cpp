#include <iostream>

#include <list>

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

bool bfs(list<no>adj[], int nVertices, int s)
{
    char state[20];
    
    int v, pai[20];
    
    int u;
    
    list<no>::iterator p;
    
    list<int>q;

    for(u = 0; u <= nVertices - 1;  u++)
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
        
        for(p = adj[u].begin(); p != adj[u].end(); p++)
        {
            v = p-> v;
            
            if(state[v] == 'u')
            {
                state[v] = 'd';
                
                pai[v] = u;
                
                q.push_back(v);
            }
        }
        state[u] = 'p'; // processed
    }
    
    for(u = 0; u <= nVertices - 1;  u++)
	{
		if(state[u] == 'u')
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
    list<no>adj[10]; // lista de adjacencia
    
    int u, v; // origem e destino
    
    int p = 0; // peso da aresta
    
    bool conexo; // true: ha conexao entre os vertices, false: não ha
    
    no aux; // struct aux para inserir as arestas
    
    list <no>:: iterator q; // iterator para mostrar a lista de adjacencias
    
    int i; // contador
    
    int nVertices; // # de vertices do grafo
    
    int orientado = 0; // 1: orientado, 0: nao orientado
    
    int s;
    
    cin >> nVertices >> s;
    
    cin >> u >> v;
    
    while(u != -1 || v != -1)
    {
        cria_aresta(adj,u,v,p,orientado);
        
        cin >> u >> v;
    }

    conexo = bfs(adj, nVertices,s);
    
    if(conexo == true)
	{
		cout << "Conexo" << endl;
	}
	else
	{
		cout << "Nao conexo" << endl;
	}

    return 0;
}