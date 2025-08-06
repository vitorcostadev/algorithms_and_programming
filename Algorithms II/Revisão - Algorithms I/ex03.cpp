#include <iostream>
#include <windows.h>
#define TMAX 10

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int vetor[TMAX], value=0;

    for(
        int i = 0;
        i < TMAX;
        i++
    ){
        do{
            cout <<"["<<i+1<<"]: "<< "Digite um número positivo: ";
            cin >> value;

            if (value < 0){
                cout << "O número deve ser positivo!"<<endl;
            }else{
                vetor[i] = value;
            }
        }while(value<0);
    }

    for(
        int i = 0;
        i < TMAX;
        i++
    ){
        if(vetor[i] % 2 == 0){
            cout<<"O número "<<vetor[i]<<" é positivo e está na posição "<<i<<"."<<endl;
        }
    }
}