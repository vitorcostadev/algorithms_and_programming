/*
 Faça um programa que calcule o valor de "E" usando a série abaixo. O programa deve escrever os
termos na tela e ao final a soma calculada.

E = 1/(n-1)!
*/

#include <iostream>
#include <iomanip>

using namespace std;

void escreverTexto(int);
int fatorialNum(int);
void calcularE(int);

int main(){

    int num = 5;
    calcularE(num);
}

void escreverTexto(int n)
{
    if(n==0){
        cout<<"1 + "<<endl;
    }
    for(unsigned i = 0; i<n; i++){
        cout << "1/!("<<n-i<<"-1)";
        cout << (i != n-1 ? " + " : " ");

    }
} 
void calcularE(int n)
{
    float result=0.0;
    for(unsigned i = n; i<=n; i--){
        result += 1.0 / fatorialNum(i);
    }
    escreverTexto(n);
    cout << " = "<<fixed<<setprecision(2)<<result<<endl;
}
int fatorialNum(int num)
{
    int fatorial=1;

    if(num<=1) return fatorial;
    for(unsigned i = num; i>=1; i--){
        fatorial *= i;
    }

    return fatorial;
}