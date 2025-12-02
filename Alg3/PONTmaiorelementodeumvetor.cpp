#include<iostream>

#include<iomanip>

using namespace std;

int main()
{
	int *v = NULL;

	int N;

	int i;
	
	int *v2 = NULL; // segundo ponteiro para varredura
	
	int menor = 0;

	cin >> N;

	v = new int [N];

	for(i = 0; i < N; i++)
	{
		cin >> v[i];
		
		if(v[i] > 0)
		{
			menor -= v[i];
		}
		else
		{
			menor += v[i];
		}
	}
    
    v2 = v;
    
    for(i = 0; i < N; i++)
	{
		if(v[i] > menor)
		{
			menor = *v2;
		}
		
		v2++;
	}
	
	cout << menor << endl; 
	
	delete []v;
	
	return 0;
}