#include <iostream>
#include <fstream>

using namespace std; 

int main(){
    ifstream of;
    unsigned direita_key=0, esquerda_key=0;
    string path = "Algorithms II/Dynamic Memory Management/Memory/", arq, linha;

    do{
        cout << "...: Digite o nome do arquivo: ";
        cin >> arq;

        if(arq.empty()) cout << "O arquivo nao pode ficar vazio."<<endl;
    }while(arq.empty());

    of.open(path+arq);
    if(not of.fail()){
        cout << "Abrindo "<<arq << endl;
        while(getline(of, linha)){
            if(not linha.empty()){
                for(unsigned x = 0; x<linha.size(); ++x){
                    if(linha.at(x) != ' ' and not isalpha(linha.at(x))){
                        if(linha.at(x) == '}')direita_key++;
                        if(linha.at(x) == '{') esquerda_key++;
                    }
                }
            }
        }
        of.close();
    }

    cout << "A quantidade de chaves esquerdas encontradas foram: " << esquerda_key<<endl;
    cout << "A quantidade de chaves direitas encontradas foram: " << direita_key<<endl;
    if(direita_key==esquerda_key) cout << "E como ja da pra ver, ela sao iguais!";
}