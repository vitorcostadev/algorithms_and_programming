/*
Crie uma função que realize a conversão de Polegadas (pol) para Centímetros (cm), onde pol é passado como
parâmetro e cm é retornado. Sabe-se que 1 polegada está para 2,54 centímetros. Crie também um programa para
testar tal função.
*/

#include <iostream>
#include <cctype>

using namespace std;

int main() 
{
    float polegasToCm(float); bool validarInteiro(string);

    string polegadas;
    do{
        cout << "Digite a quantidade de polegadas: "; 
        cin >> polegadas;

        if(not validarInteiro(polegadas))
        {
            cout << "Número incorreto, tente novamente."<<endl;
        }else if(atoi(polegadas.c_str()) <= 0) cout << "O valor das polegadas deve ser maior do que zero."<<endl;
    }while(not validarInteiro(polegadas) or atoi(polegadas.c_str()) <= 0);

    cout << "A conversão de "<<polegadas<<" para centímetros ficou em: "<<polegasToCm(atoi(polegadas.c_str()))<<" cm";
}

float polegasToCm(float pol)
{
    return pol * 2.54;
}

bool validarInteiro(string num)
{
    if(num.size() == 0) return false;

    bool result = true;

    for(unsigned i = 0; i<num.size(); i++)
    {
        if(not isdigit(num[0]) and num[0] != '-'){
            result = false;
            break;
        }else{
            for(unsigned x = 1; x<num.size(); x++){
                if(not isdigit(num[x])){
                    result = false;
                    break;
                }
            }
        }
    }
    return result;
}