/*
2. Desenvolva uma função recursiva para calcular a soma dos números naturais de 1 a n. 
*/

#include <iostream>
using namespace std;

int calcularNumNat(int n){
    if(n == 1) return 1;
    else
        return n + calcularNumNat(n-1);
}

int main()
{
    int calcularNumInt(int);

    cout << calcularNumNat(10);
}