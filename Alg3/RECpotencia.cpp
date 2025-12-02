#include<iostream>

#include<cmath>

using namespace std;

float pot(int a, int n)
{
    if(n == 1)
    {
        return 1;
    }

	return a*pow(a, n - 1);
}

int main()
{
    int a,n;

    float p;

    cin >> a >> n;

    p = pot(a, n);

    cout << p << endl;

    return 0;
}