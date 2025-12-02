#include<iostream>

#include<iomanip>

using namespace std;

int main()
{
	int *v = NULL; // ponteiro para o vetor

	int *v2 = NULL; // segundo ponteiro para varrer

	int N; // tamanho do vetor

	int i;

	int s;

	double m;

	cin >> N;
	
	v = new int [N];

	for(i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	v2 = v;

	for(i = 0; i < N; i++)
	{
		s += *v2;

		v2++;
	}

	m = (double)s / N;

	cout << fixed << setprecision(2);

	cout << m;

	delete []v; // liberando memoria alocada

	return 0;
}