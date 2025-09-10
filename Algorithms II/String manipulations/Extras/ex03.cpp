/*
3. Faça um programa que recebe do usuário uma string A e monte uma nova string B
cujo conteúdo é a string A sem suas vogais. Mostre B ao final. 
*/

#include <iostream>

using namespace std;

int main()
{
    char vogais[] = {
        'a',
        'e',
        'i',
        'o',
        'u'
    };

    string frase="", frase_sem_vogais="";

    do{
        cout<<"Digite uma frase: "<<endl;
        getline(cin, frase);
        
    }while(frase.empty());

    frase_sem_vogais=frase;
    for(unsigned i = 0; i<frase.size(); i++){
        for(unsigned j = 0; j<sizeof(vogais); j++){
            if(tolower(frase[i]) == vogais[j]){
                frase_sem_vogais[i] = '\0';
            }
        }
    }

    cout<<"Frase original: "<<frase<<endl;
    cout<<"Frase sem as vogais: "<<frase_sem_vogais<<endl;
}