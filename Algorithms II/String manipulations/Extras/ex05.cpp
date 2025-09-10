/*
Escreva um programa que recebe do usuário uma string S, um caractere C e uma
posição I, e mostra o índice da primeira ocorrência do caracter C procurado a partir
da posição I. 
*/

#include <iostream>

using namespace std;

int main()
{
    string frase="";
    char C;
    int pos;
    unsigned indice;

    do{
        cout<<"Digite uma frase: ";
        getline(cin, frase);
    }while(frase.empty());

    do{
        cout<<"Digite uma letra: ";
        cin>>C;

    }while(C < 'a' or C > 'z');

    do{
        cout<<"Digite uma posiçao para iniciar a procura ("<<1<<"-"<<frase.size()<<"): ";
        cin>>pos;
    }while(pos<1 or pos > frase.size());

    for(unsigned i = pos-1; i<frase.size(); i++){
        if(tolower(frase[i]) == tolower(C)){
            indice = i;
            break;
        }
    }

    cout << "A primeira ocorrencia da letra "<<C<<" comecando do indice "<<pos<<" eh na posiçao: "<<indice<<endl;
}