/*
8. Construa um procedimento recursivo para verificar a existência de determinado valor y
em um vetor X de n (1  n  10) elementos inteiros. 
*/

#include <iostream>
using namespace std;


int main(){
    bool verifyIfNumExistsInVet(unsigned, int, int[]);

}

bool verifyIfNumExistsInVet(unsigned vet_size, int value, int vet[])
{
    if(vet_size<=0) return false;
    if(vet[vet_size-1] == value) return true;
    else{
        return verifyIfNumExistsInVet(vet_size-1, value, vet);
    }
}