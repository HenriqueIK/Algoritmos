#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	double tempo, vm, L;
	
	cout<<"Digite o tempo decorrido (em horas)"<<endl;
	
	cin>>tempo;
	
	cout<<"Digite a velocidade media (em km/h)"<<endl;
	
	cin>>vm;
	
	cout<<fixed<<setprecision(3);
	
	L = vm*tempo/12;
	
	cout<<L<<" litro(s)"<<endl;
	
	return 0;
}
