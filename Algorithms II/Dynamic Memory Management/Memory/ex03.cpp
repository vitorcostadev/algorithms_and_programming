#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream of;
    string linha, path = "Algorithms II/Dynamic Memory Management/Memory/";
    unsigned i = 0;
    of.open(path+"ex03.txt");

    if(not of.fail()){
        cout << "Arquivo aberto com sucesso." << endl;
        while(getline(of, linha)){
            cout << linha << endl;
            if(i % 20 == 0){
                cout << "Aperte <ENTER> para continuar."; cin.get();
            }
            i++;
        }
    }else cout << "Houve um problema ao abrir o arquivo."<<endl;
}