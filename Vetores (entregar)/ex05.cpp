/*
Faça um algoritmo que leia n (n ≤ 100) pares de valores, sendo o primeiro valor o número de inscrição
do atleta e o segundo a altura (em cm) do atleta, e armazene-os em vetores. Apresente ao final o número
de inscrição e a altura do atleta mais alto, o número de inscrição e a altura do atleta mais baixo e a
altura média do grupo de atletas. 
*/

#include <iostream>
#include <windows.h>
#define NMAX 100

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    float alturas[NMAX];
    int inscricoes[NMAX];
    int n = 0;

    float alturaMaisAlta;
    float alturaMaisBaixa;
    float mediaDasAlturas = 0.0;

    do{
    cout << "Quantos atletas você deseja inscrever? ";
    cin >> n;
    }while(n < 1 || n > NMAX);

    for(
        int i = 0;
        i < n;
        i++
    ){
        cin.ignore();
        cout << "["<<i+1<<"] - "<<"Digite o número da inscrição do atleta: ";
        cin >> inscricoes[i];

        cout << "Digite a altura do atleta: ";
        cin >> alturas[i];
        cin.clear();
    }
    
    alturaMaisAlta = alturas[0];
    int altaIndice = 0;
    int baixaIndice = 0;
    alturaMaisBaixa = alturas[0];
    for(
        int i = 0;
        i < n;
        i++
    ){
        float altura = alturas[i];
        mediaDasAlturas+=altura;

        if (altura > alturaMaisAlta){
            alturaMaisAlta = altura;
            altaIndice = i;
        }else if(alturaMaisBaixa > altura){
            alturaMaisBaixa = altura;
            baixaIndice = i;
        }
    }

    cout << "A maior altura registrada foi do atleta: "<<endl;
    cout << "\nAtleta N° da inscrição: "<<inscricoes[altaIndice]<<endl;
    cout << "Altura do atleta: "<<alturas[altaIndice]<<"cm"<<endl;

    cout << "\nA menor altura registrada foi do atleta: "<<endl;
    cout << "\nAtleta N° da inscrição: "<<inscricoes[baixaIndice]<<endl;
    cout << "Altura do atleta: "<<alturas[baixaIndice]<<"cm";



}