/*
8. Escreva uma função que verifique se duas listas encadeadas em memória são iguais. 
*/

#include <iostream>
using namespace std;

typedef struct Nodo{
    int valor;
    struct Nodo *prox;
} Lista;

bool VerificarIgualdade(Lista *&ptr, Lista *&ptr_);
void deletarLista(Lista*&list);

int main(){
    Lista *lista1 = NULL;
    Lista *lista2 = NULL;

    Lista *novo1 = new Lista();
    novo1->valor = 11;
    novo1->prox = lista1;
    lista1 = novo1;

    Lista *novo2 = new Lista();
    novo2->valor = 20;
    novo2->prox = lista1;
    lista1 = novo2;

    Lista *novo3 = new Lista();
    novo3->valor = 10;
    novo3->prox = lista2;
    lista2 = novo3;

    Lista *novo4 = new Lista();
    novo4->valor = 20;
    novo4->prox = lista2;
    lista2 = novo4;

    if(VerificarIgualdade(lista1, lista2)){
        cout << "As listas sao iguais." << endl;
    } else {
        cout << "As listas sao diferentes." << endl;
    }

    deletarLista(lista1);
    deletarLista(lista2);

    return 0;
}
bool VerificarIgualdade(Lista *&ptr, Lista *&ptr_)
{
    Lista *paux = ptr, *paux_ = ptr_;
    bool isEqual = true;
    while(paux != NULL and paux_ != NULL)
    {
        if(paux->valor != paux_->valor){
            isEqual = false; break;
        }
        paux = paux->prox;
        paux_ = paux_->prox;
    }
    if(isEqual) return true;
    return false;

}
void deletarLista(Lista*&list){
    Lista*paux;
    while(paux != NULL){
        paux = list;
        list = list->prox;
        delete paux;

    }
}