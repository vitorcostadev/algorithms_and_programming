/*
2. Faça um programa que leia x pares de valores (n, r) e escreva, para cada par de valor, a combinação
de n elementos agrupados r a r. Defina uma função para calcular a combinação de n elementos
agrupados r a r utilizando a fórmula abaixo: 

C(n,r) = n! / r!(n-r)!
*/

#include <iostream>

using namespace std;

int fatorialNum(int);
bool validarInteiro(string);
int calcCombAgru(int, int);

int main()
{
    string nx,rx;
    int n,r;

    do{
        do{
            cout << "Digite um valor para N e R (ex: 4 2): ";
            cin>>nx>>rx;

            if(not validarInteiro(nx) or not validarInteiro(rx)){
                cout<<"Invalid number"<<endl;
            }else{
                n=atoi(nx.c_str());
                r=atoi(rx.c_str());
            }
        }while(nx.empty() or rx.empty() or not validarInteiro(nx) or not validarInteiro(rx));

        if(n<1 or r < 1){
            cout<<"Apenas numeros positivos e maiores do que zero."<<endl;
        }

    }while(n < 1 or r < 1);

    cout<<"C(n,r): "<<calcCombAgru(n,r)<<endl;
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
int calcCombAgru(int n, int r)
{
    if(r>n){
        return 0;
    }
    int fatN = fatorialNum(n);
    int fatR = fatorialNum(r);

    int nrSub = fatR * fatorialNum(n - r);

    return fatN / nrSub;

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