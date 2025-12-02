#include <iostream>

using namespace std;

int main()
{	
	int m[100][100];
	
	int caminho[100][100];
	
	char s1[100];
	
	int t1;
	
	char s2[100];
	
	int t2;
	
	do
	{
		cin >> t1;
		
	}while(t1 <= 1 && t1 >= 100);
	
	for(int i = 0;i < t1;i++)
	{
		cin >> s1[i];
	}
	
	do
	{
		cin >> t2;
		
	}while(t2 <= 1 && t2 >= 100);
	
	for(int i = 0;i < t2;i++)
	{
		cin >> s2[i];
	}
	
	for(int i = 0;i < t1;i++)
	{
		m[i][t2] = 0;
	}
	
	for(int i = 0; i < t2;i++)
	{
		m[t1][i] = 0;
	}
	
	for(int i = t1-1;i >= 0; i--)
	{
		for(int j = t2-1;j >= 0; j--) 
		{
			if(s1[i] == s2[j])
			{
				m[i][j] = m[i+1][j+1] + 1;
				
				caminho[i][j] = 0;
			}
			else
			{
				if(m[i+1][j] > m[i][j+1])
				{
					m[i][j] = m[i+1][j];
					
					caminho[i][j] = 2;
				}
				else
				{
					m[i][j] = m[i][j+1];
					
					caminho[i][j] = 1;
				}
			}
		}
	}
	
	int tam = m[0][0];
	
	int i = 0,j = 0;
	
	while(tam > 0)
	{
		if(caminho[i][j] == 0)
		{
			cout << s1[j] << " ";
			
			tam--;
			
			i++;
			
			j++;
		}
		else if(caminho[i][j] == 1)
		{
			j++;
		}
		else
		{
			i++;
		}  
	}
	cout << endl;
	
	return 0;
}