#include <iostream>

#include <iomanip>

using namespace std;

int h1(int k, int m)
{
	return k % m;
}

int h2(int k, int m)
{
	return  1 + (k % (m - 1));
}

int dhash(int k, int m, int i)
{
	int h;

	h = (h1(k, m) + (i * h2(k, m))) % m;

	if(h < 0)
	{
		h = h + m;
	}

	return h;
}

int main()
{
	int k;

	int m;

	int hash;

	cin >> k >>  m;

	for(int i = 0; i < m; i++)
	{
		hash = dhash(k, m, i);
		
		cout << hash << " ";
	}
	
	return 0;
}