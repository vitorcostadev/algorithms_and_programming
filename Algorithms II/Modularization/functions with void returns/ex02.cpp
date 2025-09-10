/*
Escreva um procedimento que receba um número inteiro e o imprima na forma extensa (p.ex. para 1 a saída
desejada é “Um”). O código deve gerar o extenso dos números de 0 até 10, inclusive. Caso um número não
compatível seja recebido, deve-se mostrar uma mensagem de erro. Crie também um programa que leia um valor
inteiro e chame o procedimento criado para mostrar o número extenso.
*/

#include <iostream>
#include <cctype>

using namespace std;

bool validarInteiro(string);
void imprimirPorExt(int);

int main()
{
    string numero="";
    int num;
    do{
        do{
            cout << "Digite um numero: ";
            cin>>numero;

            if(not validarInteiro) cout<<"Invalid number"<<endl;
            else{
                num=atoi(numero.c_str());
            }
        }while(numero.empty() or not validarInteiro(numero));

        if(num < 0 or num > 10) cout << "Apenas numeros no intervalo de 0-10!"<<endl;
    }while(num < 0 or num > 10);

    imprimirPorExt(num);
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
void imprimirPorExt(int numero)
{
    string numerosExt[] = {
        "Zero",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eighty",
        "Nine",
        "Ten"
    };

    for(unsigned i = 0; i<sizeof(numerosExt); i++)
    {
        if(numero == i){
            cout<<"O numero "<<numero<<" escrito por extenso ficaria: "<<numerosExt[i]<<endl;
        }
    }
}