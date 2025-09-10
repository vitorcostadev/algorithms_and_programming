/*
2. Faça um programa que recebe uma string A e inteiros positivos I e J e mostre o
segmento A[I..J]. 
*/

#include <iostream>

using namespace std;

int main()
{
    string frase = "", segmento="";
    int i = 0, j = 0;

    do{
        cout << "Digite uma frase: ";
        getline(cin, frase);
    }while(frase.empty());

    do{
        cout<<"Digite o valor de I ("<<i+1<<"-"<<frase.size()<<"): ";
        cin>>i;
    }while(i<1 or i>frase.size());

    do{
        cout<<"Digite o valor de J ("<<j+1<<"-"<<frase.size()<<"): ";
        cin>>j;
    }while(j<1 or j>frase.size());

    for(unsigned x = i; x<=j; x++){
        segmento += frase[x];
    }

    cout<<segmento;
} 