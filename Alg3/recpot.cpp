#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

float raiz(float x, float x0, float e)
{
	if(abs(x0 * x0 - x) <= e)
	{
		return x0;
	}

	return raiz(x, (x0 * x0 + x) / (2 * x0)  , e);
}

int main()
{
	float x0;
	
	float x;

	float e;
	
	float r;
	
	cin >> x >> x0 >> e;

	r = raiz(x, x0, e);

	cout << fixed << setprecision(4);
	
	cout << r << endl;

	return 0;
}
