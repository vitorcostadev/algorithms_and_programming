/*
5. Dada uma cadeia de caracteres, verifique se é ou não um identificador (nome de variável) válido.
Um identificador válido é uma cadeia de caracteres cujo primeiro caracter deve ser uma letra e os
demais devem ser dígitos, letras ou o underscore ( _ ). Exemplos: casa_azul, conjunto1, umValor. 
*/

#include <iostream>

using namespace std;

int main(){

    string identificador="";
    bool isValid=true;

    do{
        cout<<"Digite o nome do identificador: ";
        getline(cin, identificador);
    }while(identificador.empty());

    for(unsigned i = 0; i<identificador.size(); i++)
    {
        if(not isalpha(identificador[0])){
            isValid=false;
            break;
        }else if(identificador[i] != '_' and not isalnum(identificador[i])){
            isValid=false;
            break;
        }
    }

    if(isValid) cout << "A palavra "<<identificador<<" eh um identificador de variavel valido.";
    else cout << "A palavra "<<identificador<<" nao eh um identificador valido.";
}