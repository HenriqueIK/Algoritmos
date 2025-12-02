#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int hash_aux(int k, int m)
{
	int h;

	h = (k % m);

	if(h < 0)
	{
		return h + m;
	}

	return h;
}

int main()
{
	int j; //valor da chave

	int i; //tamanho da tabela

	int h;
	
	do
	{
		cin >> j >> i;
		
		if(j==0 && i==0)
		{
			break;
		}
		
		h = hash_aux(j, i);
		
		cout << h << endl;
	}
	while(j != 0 && i != 0);
	
	return 0;
}