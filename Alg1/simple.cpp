#include <iostream>

using namespace std;

int main()
{
    int x,y,z,aux;
    
    int v[3];
    
    cin>>x>>y>>z;
    
    v[0]=x;
    
    v[1]=y;
    
    v[2]=z;
    
    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			{
				if(v[i]<v[j])
					{
						aux = v[j];
						
						v[j] = v[i];
						
						v[i] = aux;
                    }
            }
			 
    }
    
    cout<<v[0]<<endl<<v[1]<<endl<<v[2]<<endl<<endl;
    
    cout<<x<<endl<<y<<endl<<z<<endl;
    
    return 0;
}