#include<iostream>

#include<iomanip>

using namespace std;

struct dado
{
	int n1, n2, n3, n4;

	int nt;
	
	double m;
};

int main()
{
	dado *nota = NULL;
	
	int N;
	
	int i;

	nota = new dado[N];

	for(i = 0; i < N; i++)
	{
		cin >> nota[i].n1 >> nota[i].n2 >> nota[i].n3 >> nota[i].n4;

		nota[i].m = (double)(nota[i].n1 + nota[i].n2 + nota[i].n3 + nota[i].n4) / 4;
	}

	for(i = 0; i < N; i++)
	{
		nota[N].nt += nota[i].m;
	}

	nota[N].nt = nota[N].nt / N;

	cout << fixed << setprecision(2);

	cout << nota[N].nt;

	delete []nota;

	return 0;
}