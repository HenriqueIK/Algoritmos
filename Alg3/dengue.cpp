#include <iostream>

#include <climits>

#include <algorithm>

using namespace std;

int main()
{
	int custo[100][100];

	int n;

	int casa;

	do
	{
		cin >> n;
		
	}while(n >= 8 && n <= 2);

	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			cin >> custo[i][j];

			custo[j][i] = custo[i][j];
		}
	}

	do
	{
		cin >> casa;
		
	}while(casa <= 0 && casa >= n - 1);

	int v[100];

	int x;

	int menor_custo;

	int custo_caminho;

	x = 0;

	for(int i = 0; i < n; i++)
	{
		if(i != casa)
		{
			v[x] = i;
			
			x++;
		}
	}
	
	menor_custo = INT_MAX;

	do
	{
		custo_caminho = custo[casa][v[0]];

		for(int i = 0; i < n - 2; i++)
		{
			custo_caminho += custo[v[i]][v[i + 1]];
		}
		
		custo_caminho += custo[v[n - 2]][casa];
		
		menor_custo = min(menor_custo, custo_caminho);
		
	}while(next_permutation(v, v + (n - 1)));

	cout << menor_custo << endl;

	return 0;
}