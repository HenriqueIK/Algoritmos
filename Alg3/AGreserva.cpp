#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Ponto
{
    int x, y;
};

Ponto p0;

Ponto nextToTop(stack<Ponto> &S)
{
    Ponto p = S.top();
    S.pop();
    Ponto res = S.top();
    S.push(p);
    return res;
}

void troca(Ponto &p1, Ponto &p2)
{
    Ponto temp = p1;
    p1 = p2;
    p2 = temp;
}

double calcularD(Ponto p1, Ponto p2)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int orientar(Ponto p, Ponto q, Ponto r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
    {
        return 0; // colinear
    }
    if(val > 0)
    {
        return 1; // girar para sentido horario
    }
    else
    {
        return 2; // girar para sentido anti-horario
    }
}

int comp(const void *vp1, const void *vp2)
{
    Ponto *p1 = (Ponto *)vp1;
    Ponto *p2 = (Ponto *)vp2;

    int o = orientar(p0, *p1, *p2);

    if (o == 0)
    {
        return (calcularD(p0, *p2) >= calcularD(p0, *p1)) ? -1 : 1;
    }
    if(o == 2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

double grahan_scan(vector<Ponto>& pontos, int n)
{
    int ymin = pontos[0].y, min = 0;

    for (int i = 1; i < n; i++)
    {
        int y = pontos[i].y;

        if ((y < ymin) || (ymin == y && pontos[i].x < pontos[min].x))
        {
            ymin = pontos[i].y, min = i;
        }
    }

    troca(pontos[0], pontos[min]);

    p0 = pontos[0];

    qsort(&pontos[1], n - 1, sizeof(Ponto), comp);

    int m = 1;

    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientar(p0, pontos[i], pontos[i + 1]) == 0)

            i++;

        pontos[m] = pontos[i];
        m++;
    }

    if (m < 3)
    {
        return 0.0;
    }

    stack<Ponto> S;
    S.push(pontos[0]);
    S.push(pontos[1]);
    S.push(pontos[2]);

    for (int i = 3; i < m; i++)
    {
        while (S.size() > 1 && orientar(nextToTop(S), S.top(), pontos[i]) != 2)
            S.pop();
        S.push(pontos[i]);
    }

    Ponto prev = S.top();
    S.pop();
    while (!S.empty())
    {
        Ponto curr = S.top();
        S.pop();
        prev = curr;
    }

    double material = calcularD(pontos[n - 1], pontos[0]);
    
    for (int i = 1; i < n; i++)
    {
        material += calcularD(pontos[i - 1], pontos[i]);
    }

    return material;
}

int main()
{
    int numReservas;

    double materialTotal = 0.0;

    cout << "Digite o numero de reservas florestais: ";

    cin >> numReservas;

    for (int i = 0; i < numReservas; i++) 
    {
        int numTrees;

        cout << "Reserva #" << i + 1 << endl;

        cout << "Digite o numero de arvores: ";

        cin >> numTrees;

        vector<Ponto> pontos(numTrees);

        for (int j = 0; j < numTrees; j++) 
        {
            cout << "Digite as coordenadas da arvore #" << j + 1 << " (x y): ";

            cin >> pontos[j].x >> pontos[j].y;
        }

        double Materialminimo = grahan_scan(pontos, numTrees);

        materialTotal += Materialminimo;
    }
        cout << "Quantidade minima de material necessaria para cercar a reserva: " << materialTotal << endl;

    return 0;
}