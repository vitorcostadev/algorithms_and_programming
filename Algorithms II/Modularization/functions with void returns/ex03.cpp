/*
8. Crie um procedimento que gere um cabeçalho para um relatório. Esse procedimento deve receber um nome como
parâmetro. O cabeçalho tem a seguinte forma:
============================================
UNIVALI – POLITECNICA – Ciência da Computação
Disciplina Algoritmo e Programação 2per
Nome: Fulano de Tal
============================================
*/

#include <iostream>
using namespace std;

void gerarCabec(string);

int main()
{
    string fulano="";

    do{
        cout<<"Digite um nome: ";
        getline(cin, fulano);

    }while(fulano.empty());
    gerarCabec(fulano);
}

void gerarCabec(string fulano)
{
    cout<<"============================================"<<endl;
    cout<<"UNIVALI – POLITECNICA – Ciência da Computação"<<endl;
    cout<<"Disciplina Algoritmo e Programação 2per"<<endl;
    cout<<"Nome: "<<fulano<<endl;
    cout<<"============================================"<<endl;

}