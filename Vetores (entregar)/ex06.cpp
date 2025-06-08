/*
Desenvolva um algoritmo que leia n (1 ≤ n ≤ 10) números inteiros e armazene-os no vetor X. Realize
um processo que troque a disposição dos elementos do vetor X de forma que o primeiro elemento seja
trocado com o último, o segundo seja trocado com o penúltimo e assim sucessivamente. Mostre os
elementos do vetor X após este processo. Não utilizar vetor auxiliar.
*/

#include <iostream>
#define NMAX 10

using namespace std;

int main(){
    int X[NMAX];
    int n = 0;

    do{
        cout << "Quantos valores você deseja utilizar? ";
        cin >> n;
    }while(n < 1 || n > NMAX);

    for(
        int i = 0;
        i < n;
        i++
    ){
        cout << "V["<<i+1<<"]: ";
        cin >> X[i];
    }

    int maxValue = n;
    int minValue = 0

    for(
        int i = 0;
        i < n;
        i ++
    ){
        if(maxValue != X[i]){
            // jaja termino
        }
    }

}