/*
4. Faça um programa recebe uma string A e duas letras L1 e L2, e troque todas as
ocorrências da letra L1 pela letra L2. Ao final mostre a string A atualizada
*/

#include <iostream>

using namespace std;

int main()
{
    string frase="", frase_modificada="";
    char a,b;

    do{
        cout<<"Digite uma frase: ";
        getline(cin, frase);
    }while(frase.empty());
    do{
        cout<<"Digite uma letra: ";
        cin>>a;
    }while(a < 'a' or a > 'z');
    do{
        cout<<"Digite outra letra: ";
        cin>>b;
    }while(b < 'a' or b > 'z');

    frase_modificada=frase;
    for(unsigned i = 0; i<frase.size(); i++){
        if(tolower(frase[i]) == tolower(a)){
            frase_modificada[i] = b;
        }
    }

    cout<<"Frase original: "<<frase<<endl;
    cout<<"Frase com trocas da letra "<<a<<" pela letra "<<b<<": "<<frase_modificada<<endl;
}