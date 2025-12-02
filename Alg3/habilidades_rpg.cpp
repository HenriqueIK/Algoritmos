#include<iostream>

#include<locale.h> 

#include<string>

#include<list>

#include<cstdlib>

using namespace std;

string atributos_base[3] = {"Mental", "F�sico", "Espiritual"};

typedef struct habilidade
{
	int codigo;
	
	string descricao;
	
	int atributo_base;
	
	int modificador;
	
} Habilidade;

typedef struct desafio
{
	int dificuldade;
	
	int atributo_base;
	
} Desafio;

Desafio gerar_desafio()
{
	Desafio d;
	
	d.dificuldade = rand() % 30;
	
	d.atributo_base = rand() % 3;
	
	return d;
}

int rolar_d20()
{
	return rand() % 20;
}

int main()
{
    int ch;

    string desc;

    int a;

    int m;

    Habilidade habilidadeAtual;

    int poderFinal;

    int valor_aleatorio;

    list<Habilidade> listaHabilidades;

    list<Habilidade> :: iterator p;

	setlocale(LC_ALL,"");
	
	cout << "Bem vindo ao sistema de habilidades.";
	
	int op=4;
	
	do
	{	
		cout<<"\n\t\tMenu\n\t1> Cadastrar nova habilidade\n\t2> Testar habilidades\n\n\t3> Sair\n";
	
		do
		{	
			cout << "Entre com a op��o desejada: ";
			
			cin >> op;
			
			if(op != 1 && op != 2 && op != 3)
			{
				cout << "Op��o inv�lida!" << endl;
			}
				
		} while(op != 1 && op != 2 && op != 3);
		
		if(op == 1)
		{
			cout << "\n\tCadastro de habilidade" << endl;
			
			cout << "Informe o c�digo da habilidade: ";
			
			cin >> ch;

            cout << "Informe a descricao da habilidade: ";

            cin >> desc;

            cout << "Informe o atributo base (0 para mental, 1 para f�sico, 2 para espiritual): ";

            cin >> a;

            cout << "Informe o modificador: ";

            cin >> m;
			
			Habilidade novaHabilidade = {ch, desc, a, m};

            listaHabilidades.push_front(novaHabilidade);
		}

		else if(op ==2)
		{
			cout << "\n\tTeste de habilidade" << endl;
			
			Desafio d = gerar_desafio();
			
			cout << "Desafio enfrentado: " << atributos_base[d.atributo_base] << endl;
			
			cout << d.dificuldade << endl;
					
			int habilidade;

            while(true)
            {
                cout << "Escolha a sua habilidade: ";
					
			    cin >> habilidade;
			
                p = listaHabilidades.begin();

                for(p = listaHabilidades.begin(); p != listaHabilidades.end(); p++)
                {
                    if(p -> codigo == habilidade)
                        {
                            habilidadeAtual = *p;

                            break;
                        }
                }
                if(habilidadeAtual.atributo_base != d.atributo_base) 
                {
                    cout << "Essa habilidade nao pode ser usada para esse desafio" << endl;
                }
                else
                {
                    valor_aleatorio = rolar_d20();
			
			        cout << "Valor do dado D20: " << valor_aleatorio << endl;

                    poderFinal = habilidadeAtual.modificador + valor_aleatorio;

                    if(poderFinal > d.dificuldade)
                    {
                        cout <<  "Voc� superou esse desafio!" << endl;
                    }
                    else
                    {
                        cout << "Voc� fracassou nesse desafio..." << endl;
                    }
                    break;
                }
            }
		}
	}while(op != 3);
	
	cout << "Obrigado por utilizar o sistema de habilidades!" << endl;

    while(!listaHabilidades.empty())
    {
        listaHabilidades.pop_front();
    }
	
	return 0;
}