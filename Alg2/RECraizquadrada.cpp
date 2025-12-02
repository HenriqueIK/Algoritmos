#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

float raiz(float X, float X0, float e)
{
	if(abs(X0 * X0 - X) <= e)
	{
		return X0;
	}
	else
		return raiz(X, (X0 * X0 + X) / (2 * X0)  , e);
}
int main()
{
	float X0;
	
	float X;
	
	float e;
	
	float r;
	
	cin >> X >> X0 >> e;

	r = raiz(X, X0, e);

	cout << fixed << setprecision(4);
	
	cout << r << endl;

	return 0;
}
