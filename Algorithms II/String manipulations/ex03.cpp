/*
3. Faça um algoritmo que leia uma frase e determine qual a vogal mais usada. 
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

    unsigned qty_de_vogais=0;
    string palavra="";

    do{
        cout << "Digite uma palavra: ";
        getline(cin, palavra);
    }while(palavra.empty());

    for(
        unsigned i = 0;
        i<sizeof(vogais);
        i++
    ){
        for(unsigned j = 0; j<palavra.size(); j++){
            if(vogais[i] == tolower(palavra[j])){
                qty_de_vogais++;
            }
        }
    }

    cout << "A palavra "<<palavra<<" tem ao todo, "<<qty_de_vogais<<" vogais.";
}