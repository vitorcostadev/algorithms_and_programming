/*
4. Faça um algoritmo que leia um vetor V com n (n ≤ 15) número inteiros. Determine o menor e o maior
elemento do vetor. 
*/

#include <iostream>
#include <windows.h>
#define NMAX 15

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int V[NMAX];
    int n = 0;

    do{
        cout << "Digite quantos valores você deseja inserir no vetor: ";
        cin >> n;
    }while(n < 1 || n > NMAX);

    for(
        int i = 0;
        i < n;
        i ++ 
    ){
        cout << "V["<<i+1<<"]: ";
        cin >> V[i];
    }

    int maiorNumero = V[0];
    int menorNumero = V[0];
    
    for(
        int i = 0;
        i < n;
        i++
    ){
        int num = V[i];

        if (num > maiorNumero){
            maiorNumero = num;

        }if(menorNumero > num){
           menorNumero = num; 
        }
          
    }

    cout << "O menor número digitado foi: "<<menorNumero<<endl;
    cout << "O maior número digitado foi: "<<maiorNumero<<endl;
}