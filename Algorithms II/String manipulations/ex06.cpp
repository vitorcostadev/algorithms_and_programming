/*
6. Dadas duas palavras verificar se uma é permutação circular de outra. Para se obter uma
permutação circular dessa palavra transfere-se o primeiro caracter do início para o fim da mesma.
Para se obter todas as outras permutações circulares, repete-se esse mesmo processo para cada
permutação circular obtida até que o último caracter da palavra inicial torne-se o primeiro. Assim,
por exemplo a palavra AROMA tem as seguintes permutações circulares: ROMAA, OMAAR,
MAARO, AAROM, AROMA. 
*/

#include <iostream>

using namespace std;

int main(){
    string palavra="", permuted="";
    bool isPermut=true;

    do{
        cout << "Digite uma palavra: ";
        getline(cin, palavra);
    }while(palavra.empty());

    for(int i = 0; i<palavra.size(); i++){
        permuted=palavra;
        for(int j = i; j<palavra.size(); j++){
            swap(permuted[i], permuted[j]);
            cout << permuted << endl;
        }
    }
}