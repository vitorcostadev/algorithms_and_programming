/*
6. Elabore um procedimento que receba um número inteiro e escreva o mês correspondente ao número. Por
exemplo, 2 corresponde a “fevereiro”. Não aceitar valores inválidos. Faça um programa que leia um valor e
chame o procedimento criado.
*/

#include <iostream>
#include <cctype>

using namespace std;

//functions
bool validarInteiro(string);
void numeroToMonth(int, string[], unsigned);

//main
int main()
{
    string numero="";
    int mes=0;
    string months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    do{
        do{
            cout<<"Digite o numero de um mes: ";
            cin>>numero;
            if (not validarInteiro(numero)) cout << "Invalid number."<<endl;
        }while(numero.empty() or not validarInteiro(numero));
        
        mes = atoi(numero.c_str());
        if(mes < 1 or mes > 12){
            cout << "Os meses ficam apenas no intervalo de 1 e 12."<<endl;
            continue;
        }
        numeroToMonth(mes, months, sizeof(months));
    }while(mes < 1 or mes > 12);
}
//func codes
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
void numeroToMonth(int mes, string months[], unsigned size)
{
    for(unsigned i = 0; i<size; i++){
        if((mes-1) == i){
            cout<<"The corresponded month of the number "<<mes<<" is "<<months[i]<<endl;
            break;
        }
    }
}