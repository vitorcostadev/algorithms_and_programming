/*
Faça um programa que receba uma frase e imprima esta frase de maneira invertida,
trocando também as letras A por *. 
*/

#include <iostream>

using namespace std;

int main()
{
    string frase = "", frase_invertida="", frase_sem_a="";

    do{
        cout<<"Digite uma frase: ";
        getline(cin, frase);
    }while(frase.empty());

    frase_invertida=frase;
    for(unsigned i = 0; i<frase.size(); i++){
        int j = frase.size() - 1 - i;
        frase_invertida[i] = frase[j];
    }

    frase_sem_a = frase_invertida;
    for(unsigned i = 0; i<frase_invertida.size(); i++){
        if(toupper(frase_invertida[i]) == 'A'){
            frase_sem_a[i] = '*';
        }
    }

    cout<<"[i] : Frase digitada: "<<frase<<endl;
    cout<<"[ii]: Frase invertida: "<<frase_invertida<<endl;
    cout<<"[iii] : Frase invertida sem a letra A: "<<frase_sem_a<<endl;
}