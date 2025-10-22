/*
1. Desenvolva uma função recursiva para calcular o fatorial de um número inteiro.
*/

#include <iostream>
using namespace std;

long int fatorial(int n)
{
    if(n == 0 or n == 1) return 1;
    else
        return n*fatorial(n-1);
}

int main()
{
    long int fatorial(int);

    cout << fatorial(5);
}

/*
TESTE DE MESA
n = 5;

1
2 * fatorial(1) = 2
3 * fatorial(2) = 6
4 * fatorial(3) = 24
5 * fatorial(4) = 120
*/