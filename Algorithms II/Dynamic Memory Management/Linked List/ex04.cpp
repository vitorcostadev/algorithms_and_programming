/*
4. Escreva um procedimento que elimine a primeira ocorrência de um determinado valor de uma lista de
valores inteiros. 
*/

#include <iostream>
using namespace std;

typedef struct Nodo{
    int valor;
    struct Nodo *prox;
} List;

void inserirNoFinal(List *&lista, int valor){
    List *listaux = new List();
    listaux->valor = valor;
    listaux->prox = NULL;

    if(lista == NULL){
        lista = listaux;
        return;
    }else{
        List *p = lista;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = listaux;
    }
}

void imprimirLista(List *&lista){
    List *aux = lista;
    while(aux!=NULL){
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void deletarList(List *&lista){
    List *aux;
    while(aux != NULL){
        aux = lista;
        lista = lista->prox;
        delete aux;
    }
}

void removerValor(List *&lista, int valor){
    List *aux = lista;
    List *pant=NULL;

    while(aux!=NULL and aux->valor != valor){
        pant = aux;
        aux = aux->prox;
    }
    
    if(aux != NULL){
        if(aux == lista){
            lista = lista->prox;
            delete aux; return;
        }else{
            pant->prox = aux->prox;
            delete aux;
        }
    } else return;
}
int main(){
    int valor=0;
    List *x = NULL;

    do{
        cout << "Digite valores para inserir na lista: ";
        cin >> valor;

        if(valor > -1){
            inserirNoFinal(x, valor);
        }
    }while(valor > -1);
    cout << "Valores inseridos...: "<<endl;
    imprimirLista(x);
    do{
        cout << "Digite um valor para remover da lista: ";
        cin >> valor;
        if(valor > -1){
            removerValor(x, valor);
            cout << "O valor "<<valor<<" foi removido da lista, eis a nova: "<<endl;
            imprimirLista(x);
        }
    }while(valor > -1);
    deletarList(x);
    return 0;
}