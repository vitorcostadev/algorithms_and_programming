/*
9. Faça uma função que faça a rotação de valor entre três números passados como parâmetros, por referência. Por
exemplo, se a função receber os valores 5 8 e 9, nesta ordem, os valores de saída nessas variáveis serão 8, 9 e 5,
respectivamente.
*/

#include <iostream>

using namespace std;

bool validarInteiro(string);
void rotacionarVal(int &, int &, int&);

int main()
{
    string numero="", numero2="", numero3="";
    int num=0, num2=0, num3=0;
    
    do{
        cout << "Digite um numero: ";
        cin>>numero;

        cout << "Digite o segundo numero: ";
        cin>>numero2;

        cout << "Digite o terceiro numero: ";
        cin>>numero3;

        if( not validarInteiro(numero) or
            not validarInteiro(numero2) or
            not validarInteiro(numero3)) cout<<"Invalid number"<<endl;
        else{
            num=atoi(numero.c_str());
            num2=atoi(numero2.c_str());
            num3=atoi(numero3.c_str());
        }
    }while(numero.empty() or 
    not validarInteiro(numero) or
    not validarInteiro(numero2) or
    not validarInteiro(numero3)
    );

    cout<<"Numeros originais: "<<num<<" "<<num2<<" "<<num3<<endl;
    rotacionarVal(num, num2, num3);
    cout<<"Numeros modificados: "<<num<<" "<<num2<<" "<<num3<<endl;
    
    

}

void rotacionarVal(int &a1, int &a2, int &a3){
    int nums[] = {a1, a2, a3};
    int maior = 0;

    for(unsigned i = 0; i<sizeof(nums)/sizeof(nums[0]); i++)
    {
        if(nums[i] > nums[maior]){
            maior = i;
        }
    }
   if(maior == 1) swap(nums[0], nums[1]);
    else if(maior == 2) swap(nums[0], nums[2]);

    a1 = nums[0];
    a2 = nums[1];
    a3 = nums[2];
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