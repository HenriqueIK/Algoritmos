#include<iostream>

#include<list>

#include<climits>

using namespace std;

struct no
{
	int v; // vertice de destino
	
	int peso; // peso da aresta
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
	if(u != -1 && v != -1 && p != -1)
	{
		no aux; // variavel auxiliar de struct

		aux.v = v; // destino da aresta auxiliar
		
		aux.peso = p; // peso da aresta auxiliar

		adj[u].push_back(aux); // insere a aresta no grafo

		if(orientado == 0)
		{
			aux.v = u;
			
			adj[v].push_back(aux);
		}
	}
}

void shortest_path_dijkstra(list<no> adj[], int nVertices, int start, int end)
{
	int u, v; // variaveis para identificar vertices
	
	bool intree[100]; // v se o vertice estiver na arvore
	
	int distance[100]; // tamanho da aresta
	
	int parent[100]; // pai do vertice
	
	list<no>::iterator p; // ponteiro para varrer a lista de adjacencias
	
	int destino; // vertice de destino da aresta
	
	int weight; // peso da aresta
	
	int distancia; // variavel para encontrar a menor distancia
	
	int pesototal; // custo da arvore geradora minima
	
	for (u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		
		distance[u] = INT_MAX;
		
		parent[u] = -1;
	}

	distance[start] = 0;
	
	v = start;
	
	while (intree[v] == false)
	{
		intree[v] = true;
		
		for (p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			
			weight = p->peso;

			if (distance[destino] > distance[v] + weight)
			{
				distance[destino] = distance[v] + weight;
				
				parent[destino] = v;
			}
		}
		
		v = 0;
		
		distancia = INT_MAX;
		
		for (u = 0; u < nVertices; u++)
		{	
			if (intree[u] == false && distancia > distance[u])
			{
				distancia = distance[u];
				v = u;
			}
		}	
	}
	
	pesototal = 0;
	
	list<int>pilha;//ponteiro para a pilha
	
    int a = end;//Variavel auxiliar

    pilha.push_front(a);
    
    a = parent[a];
    
    while (a != -1)
    {
        pilha.push_front(a);
        
        a = parent[a];
    } 
	
    cout << " Menor caminho: "  ; 
    
    while(!pilha.empty())
	{
		a = *pilha.begin();
		
		cout << a << " ";
		
		pilha.pop_front(); 
	}
	
	cout << endl;
	
    cout << " Custo: " << distance[end] << endl;
}

int main()
{
	list<no> adj[100]; // lista
	
	int u; // origem
	
	int v; // destino
	
	int peso; // peso da aresta
	
	int orientado; // 1: orientado, 0: n�o orientado
	
	int nVertices; // # vertices do grafo
	
	int start; // inicio da arvore
	
	int end; // final da arvore
	
	cin >> nVertices >> orientado >> start >> end; 
	
	while (u != -1 && v != -1 && peso != -1)
	{
		cin >> u >> v >> peso;
		
		cria_aresta(adj, u, v, peso, orientado);
	}
	
    shortest_path_dijkstra(adj,nVertices,start,end);
 
	return 0;
}