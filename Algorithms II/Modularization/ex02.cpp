/*
Elabore uma função que realize a conversão de Fahrenheit (F) para graus Celsius (C), onde F é passado como
parâmetro e C é retornado. Sabe-se que os pontos de fusão e ebulição nas escalas Celsius e Fahrenheit são: 0ºC
e 100ºC, e 32ºF e 212ºF, respectivamente. Crie também um programa para testar tal função.

Formula: (F-32)*5/9
*/

#include <iostream>
#include <cctype> // atof()
#include <windows.h> // apenas para corrigir os caracteres no terminal
#include <cmath> // round()
using namespace std;

float fahrenheitToCelsius(float fah)
{
    return (fah-32)*5/9;
}

bool validarFloat(string num)
{
    if(num.size() == 0) return false;
    else if(num == "-0" or num == "-0.0") return false;

    bool result = true;
    for(unsigned i = 0; i<num.size(); i++)
    {
        if(not isdigit(num[0]) and num[0] != '-'){
            result = false; 
            break;
        }else{
            unsigned short ponto = 0;
            for(unsigned x = 1; x<num.size(); x++){
                if(not isdigit(num[x])){
                    if(num[x] == '.' and ponto == 0) ponto++;
                    else{
                        result = false;
                        break;
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    bool validarFloat(string); float fahrenheitToCelsius(float);

    string fah;
    do{
        cout << "Digite a temperatura em Fahrenheit (F°): ";
        cin>>fah;

        if(not validarFloat(fah))
        {
            cout << "Número inválido, tente novamente."<<endl;
        }else if(atof(fah.c_str()) < 32) cout << "O valor de graus em F° deve ser acima de 32°F incluindo o 32."<<endl;

    }while(not validarFloat(fah) or atof(fah.c_str()) < 32);

    cout << "A temperatura em celsius é: "<<round(fahrenheitToCelsius(atof(fah.c_str())))<<" °C.";
}