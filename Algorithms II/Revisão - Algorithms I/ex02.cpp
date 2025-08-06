#include <iostream>
#define TMAX 15

using namespace std;

int main(){

    int vetor[TMAX] = {1,1};

    for(
        int i = 2;
        i < TMAX;
        i++
    ){
        vetor[i] = vetor[i-2] + vetor[i-1];
    }

    for(
        int i = 0;
        i < TMAX;
        i++
    ){
        cout << "["<<vetor[i]<<"]";
    }
}