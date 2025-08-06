/*
Desenvolva um programa que leia n (1<=n<=10, faça validação) números
reais e armazene-os em um vetor (considere que não haverá elemento
repetido). Após, percorra o vetor para descobrir qual é o menor valor.
Ao final escreva na tela o menor valor e em que posição ele está. Repita
o processo para determinar o maior valor.
*/

#include <iostream>
#include <windows.h>
#define TMAX 10 

using namespace std; 

int main(){
    SetConsoleOutputCP(CP_UTF8);
    float vetor[TMAX];
    int valor=0, posMin=0, posMax=0;

    do{
        cout << "Quantos valores você deseja introduzir no vetor (max. 10): ";
        cin >> valor;

        if (valor < 1 or valor > TMAX){
            cout << "O valor deve ser maior do que zero ou menor do que dez."<<endl;
        }
    }while(valor < 1 || valor > TMAX);

    for(int i = 0; i < valor; i++){
        cout << "["<<i+1<<"]: "<< "Digite o número real que deseja colocar no vetor: ";
        cin >> vetor[i];
    }

    for(int i = 0; i < valor; i++){
        if(vetor[i] < vetor[posMin]){
            posMin = i;
        }
    }
    for(int i = 0; i < valor; i++){
        if(vetor[i] > vetor[posMax]){
            posMax = i;
        }
    }

    cout << "Vetor inteiro: "<<endl;
    for(int i = 0; i<valor; i++) cout << "["<<vetor[i]<<"]"<<endl;
    cout<<"Maior valor: "<< vetor[posMax]<<endl;
    cout << "Menor valor: "<<vetor[posMin];

    return 0;

}