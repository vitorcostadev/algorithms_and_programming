#include <iostream>
#define TMAX 10

using namespace std;

int main(){

    int vetor[TMAX], valor=5;

    for(
        int i = 0;
        i < TMAX;
        i ++
    ){
        vetor[i] = valor;
        valor+=5;
    }

    for(
        int i = 0;
        i < TMAX;
        i++
    ){
        cout << "[" << vetor[i] << "]";
    }
}