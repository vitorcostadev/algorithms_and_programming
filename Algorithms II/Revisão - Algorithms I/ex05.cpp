/*
5) Desenvolva um programa que leia n (1<=n<=10, faça validação) números
reais e armazene-os em um vetor. Após, ordene o vetor. Ao final escreva
o vetor na tela.
*/

#include <iostream>
#include <windows.h>
#define TMAX 10 

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    float vetor[TMAX] = {0};
    int n=0;

    do{
        cout << "Digite o tamanho do vetor: ";
        cin >> n;

        if(n < 1) cout << "O tamanho do vetor deve ser maior do que zero ou menor do que dez!"<<endl;
    }while(n < 1 or n>TMAX);

    for(int i = 0; i<n; i++){
        cout<<">> Digite o "<<i+1<<"° número: ";
        cin >> vetor[i];
    }

    for(int i = 0; i < n - 1; i++){          
        for(int j = 0; j < n - 1 - i; j++){  
            if(vetor[j] > vetor[j + 1]){
                float z = vetor[j];         
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = z;
        }
    }
}

    for(int i = 0; i<n; i++){
        cout<<"["<<vetor[i]<<"] ";
    }
}