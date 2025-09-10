/*
Criar uma função que determine se um caractere, recebido como parâmetro, é ou não uma letra do alfabeto. A
função deve retornar 1 caso positivo e 0 em caso contrário. Crie também um programa para testar tal função.
*/

#include <iostream>
#include <windows.h>

using namespace std;

bool checkIfCharIsAlfa(char letra)
{
    if(toupper(letra) >= 'A' and toupper(letra) <= 'Z'){
        return true;
    }
    return false;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    bool checkIfCharIsAlfa(char);

    char letra;

    do{
        cout << "Digite uma letra: ";
        cin >> letra;

        if(not checkIfCharIsAlfa(letra)){
            cout << "O caractere "<<letra<<" não faz parte do alfabeto."<<endl;
        }

    }while(not checkIfCharIsAlfa(letra) or not isalpha(letra));

    cout << "A letra digitada faz parte do alfabeto.";
}