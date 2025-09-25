/*
3. Escreva uma função recursiva para calcular a soma dos múltiplos de 5 entre 0 e 1000.
*/

#include <iostream>
using namespace std;

int main()
{
    unsigned calcularMultiplo(unsigned);

    cout << calcularMultiplo(100);
    return 0;
}

unsigned calcularMultiplo(unsigned n)
{
    if(n == 0 or n % 5 != 0) return 0; // caso base
    else
        return n + calcularMultiplo(n-5); // caso recursivo
}