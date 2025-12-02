#include <iostream>

#include<iomanip>

using namespace std;
 
int main() 
{
    int a,b;
    
    cin>>a>>b;
    
    cout<<fixed<<setprecision(2);
    
    switch(a)
	{
      case 1:
      cout<<"Total: R$ "<<b*4.0<<endl;
      break;
  
      case 2:
      cout<<"Total: R$ "<<b*4.5<<endl;
      break;
  
      case 3:
      cout<<"Total: R$ "<<b*5.0<<endl;
      break;
  
      case 4:
      cout<<"Total: R$ "<<b*2.0<<endl;
      break;
  
      case 5:
      cout<<"Total: R$ "<<b*1.5<<endl;
      break;
    }
    
    return 0;
}