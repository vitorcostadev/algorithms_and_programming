/*
1. Escreva um programa que numere as linhas de um arquivo texto. O arquivo de entrada deve ser
informado pelo usuário. O programa deve mostrar cada linha do arquivo de entrada precedida do seu
número e um espaço. 
*/

#include <iostream>
#include <fstream>

using namespace std; 

int main()
{
    string path = "Algorithms II/Dynamic Memory Management/Memory/";
    ifstream read_;
    ofstream write_;
    string nomedoArq, linha;
    int i=0;

    do{
        cout << ">>> Digite o nome do arquivo: ";
        getline(cin, nomedoArq);
        if(nomedoArq.empty()) cout << "O nome do arquivo nao pode ficar vazio." <<endl;
    }while(nomedoArq.empty());

    read_.open(path + nomedoArq);
    write_.open(path + "saida_ex01.txt");

    if(not read_.fail()){
        while(getline(read_, linha)){
            cout << ++i << " " << linha << endl;
            write_ << i << " " << linha << endl;
        }
        read_.close();
        write_.close();
    }else{
        cout << "Erro ao abrir o arquivo." << endl;
    }
    return 0;
}