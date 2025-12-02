#include<iostream>

using namespace std;

int soma(int n)
{
    if(n == 0)
    {
        return 0;
    }
    
    else
    {
        return n + soma(n -1);
    }
}

int main()
{
    int n;
    
    int s;
    
    int x;
    
    cin >> n;
    
    x = soma(n);
    
    cout << "soma = " << x;
    
    return 0;
}