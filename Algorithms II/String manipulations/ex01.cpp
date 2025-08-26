/*
1. Considere que uma frase tem no máximo 80 caracteres, cada palavra é separada por um espaço
em branco e finalizada com ponto final. Faça um algoritmo que leia várias frases e, para cada
uma imprima as palavras contidas nela e seu número de caracteres. Por exemplo, a partir da
frase “Vamos resolver exercícios.”, o resultado será:
“Vamos resolver exercícios.”
Vamos 5 resolver 8 exercícios 10 
*/

#include <iostream>
#include <string>
#define CMAX 80 

using namespace std; 

int main(){
    string frase = "";
    do{
        cout << "Digite uma frase: ";
        getline(cin, frase);
        cin.clear();

        if(frase.empty()) cout << "A frase não pode ficar vazia."<<endl;
        else if(frase.size() > CMAX) cout << "A frase não pode conter mais de 80 caracteres."<<endl;

    }while(frase.empty() or frase.size() > CMAX);

    int aux = 0, _start=0;
    for(int i = 0; i <= frase.size(); i++){ 
    if(isalpha(frase[i])){
        aux++;
    } else {
        if(aux > 0) {
            for(int x = _start; x < aux + _start; x++){
                cout << frase[x];
            }
            cout << " " << aux << " ";
            aux = 0;
        }
        _start = i + 1;
    }
}
}