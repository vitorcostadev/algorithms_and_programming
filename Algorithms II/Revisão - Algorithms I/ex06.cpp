/*
6) Desenvolva um programa que leia n (1<=n<=10, faça validação) números
inteiros elementos (considere que os elementos podem estar repetidos) e
armazene-os em um vetor. Após, solicite um número qualquer e pesquise a
existência dele no vetor, escrevendo sua(s) posição(ões) no vetor.
Repita esta pesquisa para vários números.
*/

#include <iostream>
#include <windows.h>
#define TMAX 10 

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int vetor[TMAX], n=0, num=0, pos=0;
    bool isInVetor=false;

    do{
        cout<<"Digite o tamanho do vetor: ";
        cin >> n;

        if(n < 1) cout << "O vetor deve ser maior do que 1 e menor do que "<<TMAX;
    }while(n<1 or n>TMAX);

    for(int i = 0; i<n; i++){
    cout<<">> Digite o "<<i+1<<"° número: ";
    cin >> vetor[i];
    }

    do{
        cout<<"Digite um número para verificar sua existência no vetor (ou -1 para sair do loop): ";
        cin >> num;

        for(int x  = 0; x<n; x++){
            if(vetor[x] == num){
                isInVetor = true;
                pos = x;
                break;
            }
        }

        if(isInVetor){
            cout<<"O número "<<num<<" está presente no vetor, na posição "<<pos<<"!"<<endl;
            isInVetor=false; pos=0;
        }else if(num != -1){
            cout<<"O número não está presente no vetor."<<endl;
        }
    }while(num!=-1);
}