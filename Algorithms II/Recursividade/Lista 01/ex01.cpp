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