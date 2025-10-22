/*
9. Escreva uma função recursiva para verificar se dois vetores X e Y de n (1  n  10)
elementos inteiros são iguais, ou seja, xi = yi,  1  i  n. 
*/

#include <iostream>
using namespace std;

int main(){
    bool verifyIfTwoVetIsEqual(unsigned vets_size, int vetX[], int vetY[]);

    int vetX[3] = {1,1,1};
    int vetY[3] = {1,1,2};

    cout << verifyIfTwoVetIsEqual(3,vetX,vetY);
}

bool verifyIfTwoVetIsEqual(unsigned vets_size, int vetX[], int vetY[])
{
    if(vets_size<=0) return true;
    if(vetX[vets_size -1] != vetY[vets_size-1]) return false;
    else{
        return verifyIfTwoVetIsEqual(vets_size-1, vetX, vetY);
    }
}