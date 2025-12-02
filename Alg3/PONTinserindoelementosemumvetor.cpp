#include<iostream>

using namespace std;

int main()
{
	int *vet = NULL;

	int N;

	int i;

	cin >> N;

	vet = new int [N];

	for(i = 0; i < N; i++)
	{
		cin >> vet[i];
	}

	for(i = 0; i < N; i++)
	{
		cout << vet[i] << " ";
	}

	delete []vet;

	return 0;
}