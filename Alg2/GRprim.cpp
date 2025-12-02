#include<iostream>

#include<list>

#include<limits.h>

using namespace std;

struct no
{
    int v; // vertice de destino
    
    int peso; // peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){

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

struct galho
{
	bool intree; // definindo se o vertice esta na arvore
	
	int distance; // distancia entre o pai e o vertice
	
	int parent; // pai do vertice
};

void prim(list<no>adj[], int nVertices, int start)
{
	galho arvore[10]; // cria o vetor arvore
	
	int custo = 0; // custo total da arvore
	
	int destino, weight, v, dist; // variaveis auxiliares 
	
	for(int u = 0;u < nVertices;u++)
	{
		arvore[u].intree = false;
		
		arvore[u].distance = INT_MAX;
		
		arvore[u].parent = -1;
	}  	
	
	arvore[start].distance = 0;
	
	v = start;
	
	
	while(arvore[v].intree == false) // coloca todos os vertices na arvore com o menor custo possivel
	{
		arvore[v].intree = true;
		
		for(list<no>::iterator p = adj[v].begin(); p != adj[v].end(); p++) // encontra o menor caminho possivel do vertice para o seu destino
		{
			destino = p->v;
			
			weight = p->peso;
			
			if(arvore[destino].distance > weight && arvore[destino].intree == false)
			{
				arvore[destino].distance = weight;
				
				arvore[destino].parent = v;
			}
		}
		
		v = 0;
		
		dist = INT_MAX;
		
		for(int u = 0;u < nVertices; u++) // encontra proximo vertice a ser inserido na arvore
		{
			if(arvore[u].intree == false && dist > arvore[u].distance)
			{
				dist = arvore[u].distance;
				
				v = u;
			}
		}
		
	}
	 
	for(int u = 0;u < nVertices;u++) // calculando o custo da arvore
	{
		custo += arvore[u].distance;
	}
	
	cout << "Arvore Geradora Minima:" << endl;
	
	for(int u = 1;u < nVertices;u++)
	{
		cout << arvore[u].parent << " " << u << endl;
	}
		
	cout << "Custo: " << custo << endl;
}

int main()
{
	list<no>adj[10];
	
    int u; // origem da aresta
    
    int v; // destino da aresta
    
    int p; // peso da aresta
    
    int nVertice; // numero de vertices
    
    int origem; // origem do grafo
    
    int orientado; // 1: orientado e 0: nao orientado
    
    cin >> nVertice >> orientado >> origem;
	
	cin >> u >> v >> p;
	
    while(u != -1 || v != -1 || p != -1){

        cria_aresta(adj,u,v,p,orientado);
        
        cin >> u >> v >> p;
    }
    
    prim(adj,nVertice,origem); // chamando a funcao prim e criando a arvore
    
    for(int i=0;i<nVertice;i++)
	{
		while(!adj[i].empty())
		{
			adj[i].pop_back();
		}
	}
	
	return 0;
}