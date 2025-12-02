#include<iostream>

#include<list>

#include<string>

using namespace std;

struct cliente
{
    string nome; // nome do cliente
    
    float d; // divida do cliente
};

int main()
{
    int nc; // # de cliente
    
    cin >> nc; // digitando o # de clientes
    
    cin.ignore();

    list<cliente> c; // criando lista

    for (int i = 0; i < nc; i++)
	{
        string nome; // nome do cliente
        
        float d; // divida do cliente
        
        getline(cin, nome); // lendo o nome
        
        cin >> d; // digitando a divida
        
        cin.ignore();

        cliente newcliente;
        
        newcliente.nome = nome;
        
        newcliente.d = d;
        
        c.push_back(newcliente);
    }
    
    string pago; // variavel para definir se a divida foi paga
    
    getline(cin, pago);

    // procurar e remover o cliente que pagou todas as dividas
    
    for (list<cliente>::iterator it = c.begin(); it != c.end(); )
	{
        if (it->nome == pago) 
		{
            it = c.erase(it);
        } 
		else 
		{
            it++;
        }
    }
    
    for (list<cliente>::iterator it = c.begin(); it != c.end(); it++)
	{
        cout << it->nome << " " << it->d << endl;
    }

    return 0;
}