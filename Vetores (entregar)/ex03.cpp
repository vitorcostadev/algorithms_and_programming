/*
Faça um algoritmo que leia dois vetores V e W com n (n ≤ 15) números reais. Determine os vetores
resultantes da soma de V e W, da subtração de V e W, da multiplicação de V e W, da divisão de V e W,
elemento a elemento. Determine também o produto escalar de V e W, definido como: Σ (Vi * Wi) = V1 *
W1 + V2 * W2 + ...+ Vn* Wn. Caso o produto escalar seja igual a zero, os vetores são classificados como
ORTOGONAIS.
*/

#include <iostream>
#include <windows.h>
#include <cmath>
#define NMAX 15

using namespace std; 

int main(){
    SetConsoleOutputCP(CP_UTF8);
    float V[NMAX];
    float W[NMAX];
    int n = 0;

    do{
        cout << "Quantos números deseja adicionar? ";
        cin >> n;
    }while(n < 1 || n > NMAX);

    cout << "Digite a posição do vetor correspondente\n\n";
    for(
        int i = 0;
        i < n; 
        i++
    ){
        cout << "V["<<i+1<<"]: ";
        cin >> V[i];
        cout << "W["<<i+1<<"]: ";
        cin >> W[i];
    }

    // Soma de V + W

    float somaVW[NMAX];

    for(
        int i = 0;
        i < n;
        i++
    ){
        somaVW[i] = W[i] + V[i];
    }
    cout<<"[SOMA]"<<endl;
    for(int i = 0; i<n; i++){cout<<somaVW[i]<<" ";}
    cout << endl;
    // Subtração V - W

    float subVW[NMAX];

    for(
        int i = 0;
        i < n;
        i++
    ){
        subVW[i] = W[i] - V[i];
    }
    cout<<"[SUBTRAÇÃO]"<<endl;
    for(int i = 0; i<n; i++){cout<<subVW[i]<<" ";}
    cout << endl;
    // Produto V * W

    float produtoVW[NMAX];

    for(
        int i = 0;
        i < n;
        i++
    ){
        produtoVW[i] = W[i] * V[i];
    }
    cout<<"[PRODUTO]"<<endl;
    for(int i = 0; i<n; i++){cout<<produtoVW[i]<<" ";}
    cout << endl;
    // Divisão V / W

    float divVW[NMAX];

    for(
        int i = 0;
        i < n;
        i++
    ){
        divVW[i] = round(W[i] / V[i]);
    }
    cout<<"[DIVISÃO]"<<endl;
    for(int i = 0; i<n; i++){cout<<divVW[i]<<" ";}
    cout << endl;
    // Produto Escalar

    float prodEscalar = 0.0;

    for(
        int i = 0;
        i < n;
        i++
    ){
        prodEscalar+=V[i] * W[i];
    }
    cout<<"[PRODUTO ESCALAR]"<<endl;
    cout << prodEscalar<<endl;
    cout << (prodEscalar == 0 ? "ORTOGONAL: SIM" : "ORTOGONAL: NÂO") << endl;
    cout << endl;

    return 0;
}