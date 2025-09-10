/*
1. Faça um programa que leia um número inteiro n maior ou igual a zero e calcule o fatorial de n
(usualmente escrito como n!). O fatorial é calculado como o produto n * (n -1) * (n - 2) * ... * 2 * 1. Isto
nada mais é do que uma série de multiplicações repetidas, onde o multiplicador é reduzido de 1 antes
de cada multiplicação. Defina uma função para calcular o fatorial. 
*/

#include <iostream>
#include <cctype>

using namespace std;

int fatorialNum(int);
bool validarInteiro(string);

int main()
{
    string num="";
    int numero;

    do{
        do{
            cout << "Digite um numero para verificar a fatorial dele: ";
            cin>>num;

            if(not validarInteiro(num)){
                cout<<"Invalid number"<<endl;
            }else{
                numero=atoi(num.c_str());
            }
        }while(num.empty() or not validarInteiro(num));

        if(numero<1){
            cout<<"Apenas numeros positivos e maiores do que zero."<<endl;
        }

    }while(numero < 1);

    cout<<"A fatorial do numero "<<numero<<" eh "<<fatorialNum(numero)<<endl;
}
int fatorialNum(int num)
{
    int fatorial=1;

    if(num<=1) return fatorial;
    for(unsigned i = num; i>=1; i--){
        fatorial *= i;
    }

    return fatorial;
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