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
		
		adj[v].push_back (aux);
  }
}

void ordenacao_topologica(int f[], int nVertices)
{
	int aux[50];
	
	int i;
	
	int a;
	
	int b;
	
    for(i = 0; i < nVertices; i++)
	{
		aux[i] = i;
	}
	
	for(a = 0; a < nVertices; a++)
	{
		for(i = a + 1; i < nVertices; i++)
		{
			if(f[aux[a]] < f[aux[i]])
			{
				b = aux[a];
				
				aux[a] = aux[i];
				
				aux[i] = b;
			}
		}
	}
	
	for(i = 0; i < nVertices; i++)
	{
		cout << aux[i] << " ";
	}
	
	cout << endl;
}

void DFS_VISIT( int u, list<no>adj[], char color[], int pi[], int f[], int &time, int d[]) 
{ 
  list<no>::iterator w;
  
  color[u] ='G';
  
  time++;
  
  d[u] = time;
  
  for(w = adj[u].begin( ); w != adj[u].end();w++)
  {
    if (color[w->v ] == 'W')
    {
      pi[w->v] = u;
      
      DFS_VISIT(w->v, adj, color, pi, f, time, d);
    } 
  }
    color[u] = 'B';
    
    f[u] = time++;
}

void dfs(list<no>adj[], int nVertices)
{
  int f[10], pi[10], d[10];
  
  char color[10];
  
  int time;
  
  list<no>::iterator v;
  
  for(int u = 0; nVertices > u; u++)
  {
    color[u] = 'W';
    
    pi[10] = -1;
  }
   time = 0;
   
   for(int u = 0; nVertices > u; u++)
   {
    if (color[u] == 'W')
    	
    DFS_VISIT(u, adj, color, pi, f, time, d);
   }
   
   ordenacao_topologica( f,nVertices);
}

int main()
{
    int nVertices;
    
    int orientado;
    
    int u, v, p = 1; // origem, destino e peso
    
    list<no> adj[10];
    
    list<no>::iterator q;
    
    cin >> nVertices >> orientado;
    
    cin >> u >> v;
    
	while (u != -1 && v != -1)
    {
        cria_aresta(adj, u, v, p, orientado);
        
        cin >> u >> v;
    }
    
    dfs(adj, nVertices);
    
    return 0;
}