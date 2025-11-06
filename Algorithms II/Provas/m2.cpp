#include <iostream>
#define TMAX 5
using namespace std;


typedef struct{
    int pilha[TMAX];
    unsigned size=0;
} Pilha;

bool ehValido(Pilha p);
void empilha(int, Pilha &);
void desempilha(Pilha &);

int main(){

    Pilha p;
    int n=0;
    do{
        cout << "Digite um valor para empilhar: ";
        cin>>n;

        empilha(n,p);
        for(unsigned i = 0; i<p.size; i++) cout << p.pilha[i] <<endl;
        if(p.size >= TMAX) desempilha(p);

    }while(n!=1);
}


bool ehValido(Pilha p){
    if(p.size >= TMAX) return true;
    return false;
}

void empilha(int value, Pilha &p){
    if(not ehValido(p)){
        p.pilha[p.size] = value;
        p.size++;
    }
}

void desempilha(Pilha &p){
    if(p.size > 0){
        p.size--;
    }
}

